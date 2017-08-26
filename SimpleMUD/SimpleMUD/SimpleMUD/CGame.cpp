#include "CGame.h"
#include <assert.h>

CGame::CGame( HANDLE hConsole) {
	hConsoleHandle = hConsole;

	pSkills = NULL;
	pGoods = NULL;
	pNpcs = NULL;
	pSpots = NULL;
	pQuests = NULL;
	pScripts = NULL;

	nCurLineIndex = 0;
	nScriptLineNumber = 0;

	oGameEnv.bFighting = false;
}

CGame::~CGame() {
	if (pScripts) {
		delete[] pScripts;
		pScripts = NULL;
	}

	if (pQuests) {
		delete[] pQuests;
		pQuests = NULL;
	}

	if (pSpots) {
		delete[] pSpots;
		pSpots = NULL;
	}

	if (pNpcs) {
		delete[] pNpcs;
		pNpcs = NULL;
	}

	if (pSkills) {
		delete[] pSkills;
		pSkills = NULL;
	}

	if (pGoods) {
		delete[] pGoods;
		pGoods = NULL;
	}
}

bool CGame::ReadWholeTextFile(char * stFileName, char * stBuffer) {
	//Ҫ��׼ȷ�ļ����ļ����ȣ�Ҫ��ios::binary��
	ifstream hTextFile(stFileName, ios::binary);

	if (!hTextFile) {
		cerr << "open whole text file failed !" << endl;
		return false;
	}

	//�õ��ļ�����
	int nFileLength;
	hTextFile.seekg(0, ios::end);
	nFileLength = static_cast<int>(hTextFile.tellg());

	//��ָ�뷵���ļ���ͷ
	hTextFile.seekg(0);

	//��ȡ�����ļ���buffer��
	try {
		hTextFile.read(stBuffer, nFileLength);
	} catch (...) {
		cout << "read whole text file error !" << endl;
		return false;
	}

	stBuffer[nFileLength] = '\0';
	return true;
}

void CGame::ShowBuffer(char * stBuffer) {
#ifdef _WIN32_
	SetConsoleTextAttribute( hConsoleHandle, ITEM_NAME_COLOR|0);
	cout << stBuffer << endl << endl;
#else
	printf(ITEM_NAME_STRING, stBuffer);
	cout << endl << endl;
#endif
}

void CGame::PrintNpcs(short nSpotIndex) {
	short i;
	for (i = 0; i < pSpots[nSpotIndex].nNpcNum; ++i) {
		cout << i + 1 << ".";
		ShowNpcName(pSpots[nSpotIndex].nNpcs[i]);
		cout << endl;
	}
	cout << i + 1 << "." << "ȡ��" << endl << endl;
}

//��ʾ��ɫ���ϵ���Ʒ
void CGame::PrintGoodsOfNpc(short nNpcIndex) {
	short i;
	for (i = 0; i < pNpcs[nNpcIndex].nGoodsNum; ++i) {
		cout << i + 1 << ".";
		ShowGoodsName(pNpcs[nNpcIndex].MyGoods[i]);

		cout << "\t\t";
		if (oGameEnv.eState == buy_goods)
			cout << pGoods[pNpcs[nNpcIndex].MyGoods[i]].nCost << "��";
		else if (oGameEnv.eState == sell_goods)
			cout << pGoods[pNpcs[nNpcIndex].MyGoods[i]].nCost / 2 << "��";

		cout << endl;
	}
	cout << i + 1 << ".ȡ��" << endl << endl;
}

short CGame::GetUserInput() {
	char str[1];
	str[0] = getchar();
	return atoi(str);
}

short CGame::GetUserInput(short nMin, short nMax) {
	short n = GetUserInput();

	while (n < nMin || n > nMax)
		n = GetUserInput();

	return n;
}

/* ��ȡ������� */
bool CGame::LoadPlayerData(bool bNewGame) {
	//װ��npc�ͳ�������
	if (!LoadNpcsData(oResFiles.stRoleFile, '#')) {
		SystemWarning("װ��NPC����ʧ�ܣ�");
		return false;
	}
	if (!LoadSpotsData(oResFiles.stSpotFile, '#')) {
		SystemWarning("װ�س�����Ϣʧ�ܣ�");
		return false;
	}

	//���������Ϸ
	if (bNewGame) {
		//һ��ʼ�������Ǽ���
		oGameEnv.nCurrentMap = 0;

		/*
		 //��ȡ������ݺ�������������־λ
		 for (int i = 0; i< nQuestsNum; ++i )
		 {
		 pQuests[i].nFlagValue = 0;
		 }
		 */
	}

	//����Ƕ�ȡ�浵
	else {
		//�򿪴浵�ļ�
		ifstream hSaveFile("save.dat");
		if (!hSaveFile) {
			cerr << "open save file failed !" << endl;
			return false;
		}

		//��ȡ�������
		hSaveFile.read(reinterpret_cast<char *>(&pNpcs[0]), sizeof(CRole));
		hSaveFile.read(reinterpret_cast<char *>(&oGameEnv.nCurrentMap),
				sizeof(short));

		//��ȡ�����־
		for (int i = 0; i < nQuestsNum; ++i)
			hSaveFile.read(reinterpret_cast<char *>(&pQuests[i].nFlagValue),
					sizeof(short));
		for (int i = 0; i < VAR_NUM; ++i)
			hSaveFile.read(reinterpret_cast<char *>(&nVars[i]), sizeof(short));

		//��ȡ����������npc����Ʒ
		/*
		 for( i= 0; i < nSpotsNum; ++i )
		 {
		 hSaveFile.read( reinterpret_cast<char *>(&pSpots[i].nNpcNum), sizeof(short));
		 for(j = 0; j < pSpots[i].nNpcNum; ++j )
		 hSaveFile.read( reinterpret_cast<char *>(&pSpots[i].nNpcs[j]), sizeof(short) );

		 hSaveFile.read( reinterpret_cast<char *>(&pSpots[i].nGoodsNum), sizeof(short));
		 for(j = 0; j < pSpots[i].nGoodsNum; ++j )
		 hSaveFile.read( reinterpret_cast<char *>(&pSpots[i].nGoods[j]), sizeof(short) );
		 }
		 */
	}
	UpdateNick(0);
	return true;
}

/* �洢������� */
bool CGame::SavePlayerData() {
	//�򿪴浵�ļ�
	ofstream hSaveFile("save.dat");
	if (!hSaveFile) {
		cerr << "open save file failed !" << endl;
		return false;
	}

	//д�������������
	hSaveFile.write(reinterpret_cast<char *>(&pNpcs[0]), sizeof(CRole));
	hSaveFile.write(reinterpret_cast<char *>(&oGameEnv.nCurrentMap),
			sizeof(short));

	//short i, j;

	//д�������־
	for (int i = 0; i < nQuestsNum; ++i)
		hSaveFile.write(reinterpret_cast<char *>(&pQuests[i].nFlagValue),
				sizeof(short));
	for (int i = 0; i < VAR_NUM; ++i)
		hSaveFile.write(reinterpret_cast<char *>(&nVars[i]), sizeof(short));

	//д���������npc�� free item�����
	/*
	 for( i= 0; i < nSpotsNum; ++i )
	 {
	 hSaveFile.write( reinterpret_cast<char *>(&pSpots[i].nNpcNum), sizeof(short) );
	 for(j = 0; j < pSpots[i].nNpcNum; ++j )
	 hSaveFile.write( reinterpret_cast<char *>(&pSpots[i].nNpcs[j]), sizeof(short) );

	 hSaveFile.write( reinterpret_cast<char *>(&pSpots[i].nGoodsNum), sizeof(short));
	 for(j = 0; j < pSpots[i].nGoodsNum; ++j )
	 hSaveFile.write( reinterpret_cast<char *>(&pSpots[i].nGoods[j]), sizeof(short) );
	 }
	 */

	return true;
}

/* ������Ϸ����������������ı��ļ��е����ݶ��Ѿ�������ܱ����� */
void CGame::RunGame() {
	short nInput;

	if (!LoadResFileName("res_index.txt", '#'))
		return;

	if (!LoadSkillsData(oResFiles.stSkillFile, '#'))
		return;
	if (!LoadGoodsData(oResFiles.stGoodsFile, '#'))
		return;
	if (!LoadQuestData(oResFiles.stQuestFile, '#'))
		return;
	if (!LoadScripts(oResFiles.stScriptFile, '#'))
		return;
	if (!ReadWholeTextFile(oResFiles.stMapFile, stMapBuffer))
		return;
	if (!ReadWholeTextFile(oResFiles.stLogoFile, stLogoBuffer))
		return;
	LoadNickData(oResFiles.stNickFile, '#');

	oGameEnv.eState = system_menu;

	iRunning = true;

	while (iRunning) {
		short i;

		switch (oGameEnv.eState) {

		//��ʾ��Ϸ�ı����ϵͳ�˵�
		case system_menu:

			system(CLEAR);
			ShowBuffer(stLogoBuffer);
			//RunScripts( 0 );
			//cout << endl;
			SystemOut("1. �µ���;	2.��ս����	3.�⽣����");

			nInput = GetUserInput(1, 3);

			//������½���Ϸ
			if (nInput == 1) {
				SystemHint("��ȡ�������...");
				if (!LoadPlayerData(true)) {
					iRunning = false;
				}

				cout << "������";
				ShowNpcDetail(0);
				SystemPause();
				oGameEnv.eState = player_adven;
			}

			//����Ƕ�ȡ�浵
			else if (nInput == 2) {
				SystemHint("��ȡ�������...");
				if (!LoadPlayerData(false)) {
					iRunning = false;
				}
				oGameEnv.eState = player_adven;
			}

			//���Ҫ�뿪��Ϸ
			else if (nInput == 3)
				return;

			break;

			//���ð��״̬
		case player_adven:
			system(CLEAR);	//����
			ShowSpotDetail(oGameEnv.nCurrentMap);
			ShowNpcState(0);
			SystemOut("1.��̸	2.�۲�	3.����	4.ʰȡ	5.��·	6.״̬	7.ϵͳ	8.��ͼ");

			nInput = GetUserInput(1, 8);

			//���˽�̸
			if (nInput == 1) {
				if (pSpots[oGameEnv.nCurrentMap].nNpcNum == 0)
					SystemWarning("����û���˿��Խ�̸��");
				else
					oGameEnv.eState = talk_with_npc;
			}

			//�۲����
			else if (nInput == 2) {
				if (pSpots[oGameEnv.nCurrentMap].nNpcNum == 0)
					SystemWarning("����û���˿��Թ۲죡");
				else
					oGameEnv.eState = watch_npc;
			}

			//��������
			else if (nInput == 3) {
				if (pSpots[oGameEnv.nCurrentMap].nNpcNum == 0)
					SystemWarning("����û���˿��Թ�����");
				else
					oGameEnv.eState = attack_npc;
			}

			//����
			else if (nInput == 4) {
				if (pSpots[oGameEnv.nCurrentMap].nGoodsNum == 0)
					SystemWarning("����û�пɼ�Ķ�����");
				else
					oGameEnv.eState = list_free_item;
			}

			//��·
			else if (nInput == 5) {
				if (pSpots[oGameEnv.nCurrentMap].nLeaveScript >= 0) {
					RunScripts(pSpots[oGameEnv.nCurrentMap].nLeaveScript);
					oGameEnv.eState = player_adven;
				} else
					oGameEnv.eState = show_exits;
			}

			//��Ҳ쿴״̬
			else if (nInput == 6)
				oGameEnv.eState = player_state;

			//ϵͳ�˵�
			else if (nInput == 7) {
				oGameEnv.eState = playing_sys_menu;
			}

			//�鿴��ͼ
			else if (nInput == 8) {
				ShowBuffer(stMapBuffer);
				SystemPause();
				oGameEnv.eState = player_adven;
			}

			break;

			//��Ҳ쿴״̬
		case player_state:
			SystemHint("Ҫ�쿴ʲô��");
			SystemOut("1.����	2.��Ʒ	3.װ��	4.����	5.����	6.ȡ��");

			nInput = GetUserInput(1, 6);

			//���Ҫ�쿴����
			if (nInput == 1) {
				ShowNpcDetailX(0);
				SystemPause();
				oGameEnv.eState = player_state;
			}

			//�鿴���ϵ���Ʒ
			else if (nInput == 2) {
				if (pNpcs[0].nGoodsNum)
					oGameEnv.eState = list_goods;
				else {
					SystemWarning("������û���κ���Ʒ.");
					oGameEnv.eState = player_state;
				}
			}

			//�鿴װ��
			else if (nInput == 3)
				oGameEnv.eState = check_equipment;

			//�鿴ӵ�еļ���
			else if (nInput == 4) {
				if (pNpcs[0].nSkillNum)
					oGameEnv.eState = list_skills;
				else {
					SystemWarning("�㻹ûѧ���κμ��ܡ�");
					oGameEnv.eState = player_state;
				}
			}

			//�鿴����
			else if (nInput == 5)
				oGameEnv.eState = list_quest;

			//ȡ��
			else
				oGameEnv.eState = player_adven;

			break;

			//ѡ���ƶ���Ŀ�ĵ�
		case show_exits:
			SystemHint("Ҫȥ���");

			//��ʾ����ȥ�ĵط�
			for (i = 0; i < pSpots[oGameEnv.nCurrentMap].nExitNum; ++i) {
				cout << (i + 1) << ".";
				ShowSpotName(pSpots[oGameEnv.nCurrentMap].nExits[i]);
				cout << endl;
			}
			cout << i + 1 << ".ȡ��" << endl << endl;

			nInput = GetUserInput(1, i + 1);

			//ȡ��
			if (nInput == i + 1)
				oGameEnv.eState = player_adven;

			//ת����Ŀ�ĵ�
			else {
				oGameEnv.nCurrentMap =
						pSpots[oGameEnv.nCurrentMap].nExits[nInput - 1];
				RunScripts(pSpots[oGameEnv.nCurrentMap].nEnterScript);
				oGameEnv.eState = player_adven;
			}

			break;

			//���˽�̸
		case talk_with_npc:
			SystemHint("Ҫ��˭��̸��");
			PrintNpcs(oGameEnv.nCurrentMap);

			nInput = GetUserInput(1, pSpots[oGameEnv.nCurrentMap].nNpcNum + 1);

			//ȡ��
			if (nInput == pSpots[oGameEnv.nCurrentMap].nNpcNum + 1)
				oGameEnv.eState = player_adven;

			//��ѡ�е�����Ի�
			else {
				oGameEnv.nCurrentNpc = pSpots[oGameEnv.nCurrentMap].nNpcs[nInput
						- 1];
				RunScripts(pNpcs[oGameEnv.nCurrentNpc].nTalkScript);
				if (oGameEnv.eState == talk_with_npc)
					oGameEnv.eState = player_adven;
			}

			break;

			//�۲����
		case watch_npc:
			SystemHint("Ҫ�۲�˭��");
			PrintNpcs(oGameEnv.nCurrentMap);

			nInput = GetUserInput(1, pSpots[oGameEnv.nCurrentMap].nNpcNum + 1);

			//ȡ��
			if (nInput == pSpots[oGameEnv.nCurrentMap].nNpcNum + 1)
				oGameEnv.eState = player_adven;

			//��ʾ�����˵�����
			else {
				ShowNpcDetail(pSpots[oGameEnv.nCurrentMap].nNpcs[nInput - 1]);
				SystemPause();
				oGameEnv.eState = player_adven;
			}

			break;

			//��������
		case attack_npc:
			SystemHint("Ҫ����˭��");
			PrintNpcs(oGameEnv.nCurrentMap);

			nInput = GetUserInput(1, pSpots[oGameEnv.nCurrentMap].nNpcNum + 1);

			//ȡ��
			if (nInput == pSpots[oGameEnv.nCurrentMap].nNpcNum + 1)
				oGameEnv.eState = player_adven;

			//��ս
			else {
				cout << "����";
				ShowNpcName(pSpots[oGameEnv.nCurrentMap].nNpcs[nInput - 1]);
				SystemWarning("����һ����");

				InitFight(pSpots[oGameEnv.nCurrentMap].nNpcs[nInput - 1]);
			}

			break;

			//ս������
		case fighting:

			short nActRole;
			short nSelectedSkill;
			nActRole = DecideWhoAct();

			//���������ж�
			if (nActRole == 0) {
				oGameEnv.eState = player_act;
			}

			//�����npc�ж�
			else {
				nSelectedSkill = UseWhichSkill(nActRole);
				Act(nActRole, nSelectedSkill, 0);
			}

			break;

			//�����ս���е��ж�
		case player_act:

			SystemHint("�ֵ����ж��ˣ�");
			ShowNpcState(0);
			SystemOut("1.����	2.����	3.��Ʒ	4.����	");

			nInput = GetUserInput(1, 4);

			//ѡ�񹥻�
			if (nInput == 1)
				Act(0, -1, oGameEnv.nCurrentEnemy);

			//ʹ�ü���
			else if (nInput == 2) {
				if (pNpcs[0].nSkillNum == 0) {
					SystemWarning("�㻹ûѧ���κμ��ܡ�");
				} else
					oGameEnv.eState = list_skills;
			}

			//ʹ����Ʒ
			else if (nInput == 3) {
				if (pNpcs[0].nGoodsNum == 0) {
					SystemWarning("������û���κ���Ʒ��");
				} else
					oGameEnv.eState = list_goods;
			}

			//����
			else if (nInput == 4)
				EscapeOut(0, oGameEnv.nCurrentEnemy);

			//����
			else
				SystemWarning("û����ѡ�����������ѡ��");

			break;

			//��Ϸ�����е���ϵͳ�˵�
		case playing_sys_menu:

			SystemHint("Ҫ��ʲô��");
			SystemOut("1.�洢����\n2.��ȡ����\n3.���ر���\n4.������Ϸ");

			nInput = GetUserInput(1, 4);

			//����Ǵ洢����
			if (nInput == 1) {
				if (!SavePlayerData()) {
					SystemWarning("���ȴ洢ʧ�ܡ�");
					iRunning = false;
				} else {
					SystemHint("���ȴ洢��ϡ�");
					SystemPause();
				}
				oGameEnv.eState = playing_sys_menu;
			}

			//��ȡ����
			else if (nInput == 2) {
				if (!LoadPlayerData(false)) {
					SystemHint("���ȶ�ȡʧ�ܣ�");
					iRunning = false;
				} else {
					SystemHint("���ȶ�ȡ�ɹ���");
					SystemPause();
				}
				oGameEnv.eState = player_adven;
			}

			//���ر���
			else if (nInput == 3)
				oGameEnv.eState = system_menu;

			//ȡ��
			else
				oGameEnv.eState = player_adven;

			break;

			//�鿴����
		case list_quest:

			SystemHint("Ҫ�鿴��������");
			SystemOut("1.δ�������		2.���������	3.����");
			nInput = GetUserInput(1, 3);

			if (nInput == 1) {
				ShowQuests(false);
			}

			else if (nInput == 2) {
				ShowQuests(true);
			}

			else if (nInput == 3)
				oGameEnv.eState = player_adven;

			break;

			//�鿴ӵ����Ʒ
		case list_goods:

			SystemHint("Ҫʹ��ʲô��Ʒ��");
			PrintGoodsOfNpc(0);

			nInput = GetUserInput(1, pNpcs[0].nGoodsNum + 1);

			//ȡ��
			if (nInput == pNpcs[0].nGoodsNum + 1) {
				if (oGameEnv.bFighting)
					oGameEnv.eState = player_act;
				else
					oGameEnv.eState = player_adven;
			}

			//׼��ʹ��ѡ�е���Ʒ
			else {
				oGameEnv.nCurrentGoods = nInput - 1;
				oGameEnv.eState = use_goods;
			}

			break;

			//ʹ����Ʒ
		case use_goods:
			ShowGoodsDetail(pNpcs[0].MyGoods[oGameEnv.nCurrentGoods]);
			SystemOut("1.ʹ��	2.����	3.����");

			nInput = GetUserInput(1, 3);

			//ʹ����Ʒ
			if (nInput == 1) {
				UseGoods(0, oGameEnv.nCurrentGoods);

				if (oGameEnv.bFighting)
					oGameEnv.eState = fighting;
				else
					oGameEnv.eState = list_goods;
			}

			else if (nInput == 2) {
				ShowNpcName(0);
				cout << "�ӵ���";
				ShowGoodsName(pNpcs[0].MyGoods[oGameEnv.nCurrentGoods]);
				cout << "��" << endl;
				SystemPause();

				AddGoodsToSpot(oGameEnv.nCurrentMap,
						pNpcs[0].MyGoods[oGameEnv.nCurrentGoods]);
				RemoveGoods(0, oGameEnv.nCurrentGoods, false);
				oGameEnv.eState = list_goods;
			}

			//ȡ��
			else
				oGameEnv.eState = list_goods;

			break;

			//�鿴ӵ�еļ���
		case list_skills:

			SystemHint("Ҫʹ��ʲô���ܣ�");
			for (i = 0; i < pNpcs[0].nSkillNum; ++i) {
				cout << i + 1 << ".";
				ShowSkillName(pNpcs[0].MySkills[i].nSkillIndex);
				cout << "\t" << pNpcs[0].MySkills[i].nSkillLevel << "��" << endl;
			}
			cout << i + 1 << ".ȡ��" << endl << endl;

			nInput = GetUserInput(1, i + 1);

			//ȡ��
			if (nInput == i + 1) {
				if (oGameEnv.bFighting)
					oGameEnv.eState = player_act;
				else
					oGameEnv.eState = player_adven;
			}

			//׼��ʹ�ü���
			else {
				oGameEnv.nCurrentSkill = nInput - 1;
				oGameEnv.eState = use_skill;
			}

			break;

			//ʹ�ü���
		case use_skill:

			//������������
			short nMpCost;
			nMpCost = SkillMpCost(0, oGameEnv.nCurrentSkill);

			//��ʾ
			ShowSkillDetail(
					pNpcs[0].MySkills[oGameEnv.nCurrentSkill].nSkillIndex);
			cout << "��ǰ����"
					<< pNpcs[0].MySkills[oGameEnv.nCurrentSkill].nSkillLevel
					<< '\t';
			cout << "�ķ�������" << nMpCost << '\t';
			cout << "�����˺���" << SkillDamage(0, oGameEnv.nCurrentSkill) << endl;
			SystemOut("1.ʹ��	2.����");

			nInput = GetUserInput(1, 2);

			//ʹ�ü���
			if (nInput == 1) {
				if (oGameEnv.bFighting) {
					if (pNpcs[0].nMP >= nMpCost) {
						Act(0, oGameEnv.nCurrentSkill, oGameEnv.nCurrentEnemy);
					} else {
						SystemWarning("�������㡣");
						oGameEnv.eState = player_act;
					}
				}

				else {
					SystemWarning("ֻ����ս��ʱʹ�ã�");
					oGameEnv.eState = list_skills;
				}
			}

			//ȡ��
			else if (nInput == 2) {
				oGameEnv.eState = list_skills;
			}

			break;

			//�г����Լ�Ķ���
		case list_free_item:
			SystemHint("Ҫ����ʲô��");
			for (i = 0; i < pSpots[oGameEnv.nCurrentMap].nGoodsNum; ++i) {
				cout << i + 1 << ".";
				ShowGoodsName(pSpots[oGameEnv.nCurrentMap].nGoods[i]);
				cout << "\t";
			}
			cout << i + 1 << ".ȡ��" << endl << endl;

			nInput = GetUserInput(1, i + 1);

			if (nInput == i + 1)
				oGameEnv.eState = player_adven;
			else {
				oGameEnv.nCurrentGoods = nInput - 1;
				oGameEnv.eState = pick_item;
			}
			break;

		case pick_item:
			ShowGoodsDetail(
					pSpots[oGameEnv.nCurrentMap].nGoods[oGameEnv.nCurrentGoods]);
			SystemOut("1.��ȡ	2.ȡ��");

			nInput = GetUserInput(1, 2);

			if (nInput == 1) {
				PickGoods(0, oGameEnv.nCurrentGoods);
				if (pSpots[oGameEnv.nCurrentMap].nGoodsNum == 0)
					oGameEnv.eState = player_adven;
				else
					oGameEnv.eState = list_free_item;
			} else
				oGameEnv.eState = list_free_item;

			break;

		case check_equipment:
			ShowNpcName(0);
			cout << "��װ�������" << endl;

#ifdef _WIN32_
			SetConsoleTextAttribute( hConsoleHandle, ITEM_NAME_COLOR|0 );
#endif
			cout << "1.ͷ����";
			ShowEquipment(0, 0);
			cout << endl;
			cout << "2.���ţ�";
			ShowEquipment(0, 1);
			cout << endl;
			cout << "3.�ֳ֣�";
			ShowEquipment(0, 2);
			cout << endl;
			cout << "4.��̤��";
			ShowEquipment(0, 3);
			cout << endl;
			cout << "5.ȡ��";
			cout << endl << endl;

			nInput = GetUserInput(1, 5);

			if (nInput == 5)
				oGameEnv.eState = player_adven;
			else if (pNpcs[0].MyEquipment[nInput - 1] == -1)
				SystemWarning("��ûʲô�ÿ��ġ�");
			else {
				oGameEnv.nCurrentEquipment = nInput - 1;
				oGameEnv.eState = unequip_;
			}
			break;

		case unequip_:
			ShowGoodsDetail(pNpcs[0].MyEquipment[oGameEnv.nCurrentEquipment]);
			SystemOut("1.ж��	2.����");

			nInput = GetUserInput(1, 2);
			if (nInput == 1) {
				UnEquip(0, oGameEnv.nCurrentEquipment);
				oGameEnv.eState = check_equipment;
			} else
				oGameEnv.eState = player_adven;

			break;

		case trading:
			ShowNpcName(oGameEnv.nCurrentNpc);
			cout << "����ӭ���٣�������ʲô��Ҫ�İɣ�" << endl;
			SystemOut("1.����	2.����	3.ȡ��");

			nInput = GetUserInput(1, 3);
			if (nInput == 1)
				oGameEnv.eState = buy_goods;
			else if (nInput == 2)
				oGameEnv.eState = sell_goods;
			else
				oGameEnv.eState = player_adven;
			break;

		case buy_goods:
			SystemHint("Ҫ��Щʲô��");
			PrintGoodsOfNpc(oGameEnv.nCurrentNpc);

			nInput = GetUserInput(1, pNpcs[oGameEnv.nCurrentNpc].nGoodsNum + 1);

			if (nInput == pNpcs[oGameEnv.nCurrentNpc].nGoodsNum + 1)
				oGameEnv.eState = player_adven;
			else {
				BuyGoods(0, pNpcs[oGameEnv.nCurrentNpc].MyGoods[nInput - 1]);
				oGameEnv.eState = buy_goods;
			}
			break;

		case sell_goods:
			SystemHint("Ҫ��ʲô��");
			PrintGoodsOfNpc(0);

			nInput = GetUserInput(1, pNpcs[0].nGoodsNum + 1);

			if (nInput == pNpcs[0].nGoodsNum + 1)
				oGameEnv.eState = player_adven;
			else {
				SellGoods(0, nInput - 1);
				oGameEnv.eState = sell_goods;
			}
			break;

		default:
			oGameEnv.eState = player_adven;
		}
	}
}

/* ���볡������ */
bool CGame::LoadSpotsData(const char * pstFileName, const char cHeadFlag) {
	short i;

	if (pSpots) {
		delete[] pSpots;
		pSpots = NULL;
	}

	CTextParser SpotsFile(pstFileName, cHeadFlag);	//open spots file
	nSpotsNum = SpotsFile.GetRecordNum();			//get spots number
	pSpots = new CSpot[nSpotsNum]; //malloc memory space to hold spots data

	//read data one by one
	for (short nSpotsIndex = 0; nSpotsIndex < nSpotsNum; ++nSpotsIndex) {
		SpotsFile.FindRecordHead();
		SpotsFile.GotoNextLine();
		SpotsFile.ReadString(pSpots[nSpotsIndex].stName);
		SpotsFile.GotoNextLine();
		SpotsFile.ReadString(pSpots[nSpotsIndex].stScene);

		//exits data
		SpotsFile.GotoNextLine();
		SpotsFile.ReadInteger(&pSpots[nSpotsIndex].nExitNum);
		SpotsFile.GotoNextLine();
		for (i = 0; i < pSpots[nSpotsIndex].nExitNum; ++i)
			SpotsFile.ReadInteger(&pSpots[nSpotsIndex].nExits[i]);

		//goods data
		SpotsFile.GotoNextLine();
		SpotsFile.ReadInteger(&pSpots[nSpotsIndex].nGoodsNum);
		SpotsFile.GotoNextLine();
		for (i = 0; i < pSpots[nSpotsIndex].nGoodsNum; ++i)
			SpotsFile.ReadInteger(&pSpots[nSpotsIndex].nGoods[i]);

		//npcs data
		SpotsFile.GotoNextLine();
		SpotsFile.ReadInteger(&pSpots[nSpotsIndex].nNpcNum);
		SpotsFile.GotoNextLine();
		for (i = 0; i < pSpots[nSpotsIndex].nNpcNum; ++i)
			SpotsFile.ReadInteger(&pSpots[nSpotsIndex].nNpcs[i]);

		//enter script and leave script
		SpotsFile.GotoNextLine();
		SpotsFile.ReadInteger(&pSpots[nSpotsIndex].nEnterScript);
		SpotsFile.ReadInteger(&pSpots[nSpotsIndex].nLeaveScript);
	}
	return true;
}

//��ʾ��������
void CGame::ShowSpotName(short nSpotIndex) {
#ifdef _WIN32_
	SetConsoleTextAttribute( hConsoleHandle, SPOT_NAME_COLOR|0 );
	cout << pSpots[nSpotIndex].stName;
#else
	printf(SPOT_NAME_STRING, pSpots[nSpotIndex].stName);
#endif
}

/* ���ڳ�������ϸ��Ϣ */
void CGame::ShowSpotDetail(short nSpotIndex) {
	short i;

	//show specified spot description
	ShowSpotName(nSpotIndex);
	cout << endl;
#ifdef _WIN32_
	SetConsoleTextAttribute( hConsoleHandle, DESCRIPTION_COLOR|0 );
	cout << pSpots[ nSpotIndex].stScene << endl;
#else
	printf(DESCRIPTION_STRING, pSpots[nSpotIndex].stScene);
	cout << endl;
#endif

	//show those npcs in the spot
	if (pSpots[nSpotIndex].nNpcNum) {
		cout << "����������У�";
		for (i = 0; i < pSpots[nSpotIndex].nNpcNum; ++i) {
			ShowNpcName(pSpots[nSpotIndex].nNpcs[i]);
			cout << "\t";
		}
		cout << endl;
	}

	// show the goods of the spot
	if (pSpots[nSpotIndex].nGoodsNum) {
		cout << "������Щ���Լ�ȡ�Ķ�����";
		for (i = 0; i < pSpots[nSpotIndex].nGoodsNum; ++i) {
			ShowGoodsName(pSpots[nSpotIndex].nGoods[i]);
			cout << "\t";
		}
		cout << endl;
	}

	//show the exits of the spot
	if (pSpots[nSpotIndex].nExitNum) {
		cout << "�������ͨ����";
		for (i = 0; i < pSpots[nSpotIndex].nExitNum; ++i) {
			ShowSpotName(pSpots[nSpotIndex].nExits[i]);
			cout << " ";
		}
		cout << endl;
	}

	//RunScripts( pSpots[nSpotIndex].nEnterScript );
}

/* show skill name */
void CGame::ShowSkillName(short nSkillIndex) {
#ifdef _WIN32_
	SetConsoleTextAttribute( hConsoleHandle, SKILL_NAME_COLOR|0 );
	cout << pSkills[nSkillIndex].stName;
#else
	printf(SKILL_NAME_STRING, pSkills[nSkillIndex].stName);
#endif
}

/* ��ʾ������ϸ��Ϣ */
void CGame::ShowSkillDetail(short nSkillIndex) {
	ShowSkillName(nSkillIndex);
	cout << endl;
#ifdef _WIN32_
	SetConsoleTextAttribute( hConsoleHandle, DESCRIPTION_COLOR|0);
	cout << pSkills[nSkillIndex].stDesc << endl;
#else
	printf(DESCRIPTION_STRING, pSkills[nSkillIndex].stDesc);
	cout << endl;
#endif
	cout << "ÿ��һ����������" << pSkills[nSkillIndex].nPower << "��" << endl;
}

/* ��ʾװ������ */
void CGame::ShowEquipment(short nRoleIndex, short nLocation) {
	if (pNpcs[nRoleIndex].MyEquipment[nLocation] != -1)
		ShowGoodsName(pNpcs[nRoleIndex].MyEquipment[nLocation]);
	else
		cout << "��";
}

/* ��ʾ��Ʒ���� */
void CGame::ShowGoodsName(short nGoodsIndex) {
#ifdef _WIN32_
	SetConsoleTextAttribute( hConsoleHandle, ITEM_NAME_COLOR|0 );
	cout << pGoods[nGoodsIndex].stName;
#else
	printf(ITEM_NAME_STRING, pGoods[nGoodsIndex].stName);
#endif
}

/* ��ʾ��Ʒ����ϸ��Ϣ */
void CGame::ShowGoodsDetail(short nGoodsIndex) {
	if (nGoodsIndex >= nGoodsNum) {
		SystemWarning("��Ʒ����������Χ����Ϸ���˳���");
		iRunning = false;
		return;
	}

	//��Ʒ����
	ShowGoodsName(nGoodsIndex);
	cout << endl;
#ifdef _WIN32_
	SetConsoleTextAttribute( hConsoleHandle, DESCRIPTION_COLOR|0 );
	cout << pGoods[ nGoodsIndex ].stDesc << endl;
#else
	printf(DESCRIPTION_STRING, pGoods[nGoodsIndex].stDesc);
	cout << endl;
#endif

	//��Ʒ��Ч��
	switch (pGoods[nGoodsIndex].nProperty) {
	case 0:
		cout << "���Է��ã�";
		break;
	case 1:
		cout << "����װ����";
		break;
	case 2:
		cout << "������ϰ��";
		break;
	default:
		cout << "������Ʒ!";
	}

	if (pGoods[nGoodsIndex].nAddHP)
		cout << "���� + " << pGoods[nGoodsIndex].nAddHP << "��\t";
	if (pGoods[nGoodsIndex].nAddMaxHP)
		cout << "�������� + " << pGoods[nGoodsIndex].nAddMaxHP << "��\t";
	if (pGoods[nGoodsIndex].nAddMP)
		cout << "���� + " << pGoods[nGoodsIndex].nAddMP << "��\t";
	if (pGoods[nGoodsIndex].nAddMaxMP)
		cout << "�������� + " << pGoods[nGoodsIndex].nAddMaxMP << "��\t";
	if (pGoods[nGoodsIndex].nAddAttack)
		cout << "���� + " << pGoods[nGoodsIndex].nAddAttack << "��\t";
	if (pGoods[nGoodsIndex].nAddDefence)
		cout << "���� + " << pGoods[nGoodsIndex].nAddDefence << "��\t";
	if (pGoods[nGoodsIndex].nAddSpeed)
		cout << "�ٶ� + " << pGoods[nGoodsIndex].nAddSpeed << "��\t";
	if (pGoods[nGoodsIndex].nSkillIndex != -1) {
		cout << "�������书��";
		ShowSkillName(pGoods[nGoodsIndex].nSkillIndex);
		cout << "��";
	}

	cout << endl;
}

//��ʾ����
void CGame::ShowQuests(bool bCompleted) {
	short i, n = 0;

	if (bCompleted) {
		cout << "����ɵ�����" << endl;

		for (i = 0; i < nQuestsNum; ++i) {
			if (pQuests[i].nFlagValue == 2) {
				n++;
#ifdef _WIN32_
				SetConsoleTextAttribute( hConsoleHandle, QUEST_COLOR|0 );
				cout <<"[" << n << "] ";
				cout << pQuests[i].stQuestDesc << endl;
#else
				cout << "[" << n << "]";
				printf(QUEST_STRING, pQuests[i].stQuestDesc);
				cout << endl;
#endif
			}
		}
	}

	else {
		cout << "δ��ɵ�����" << endl;

		for (i = 0; i < nQuestsNum; ++i) {
			if (pQuests[i].nFlagValue == 1) {
				n++;
#ifdef _WIN32_
				SetConsoleTextAttribute( hConsoleHandle, QUEST_COLOR|0 );
				cout <<"[" << n << "] ";
				cout << pQuests[i].stQuestDesc << endl;
#else
				cout << "[" << n << "] ";
				printf(QUEST_STRING, pQuests[i].stQuestDesc);
				cout << endl;
#endif
			}
		}
	}

	if (!n)
		cout << "�ޡ�" << endl;

	SystemPause();
}

/* load Npcs data */
bool CGame::LoadNpcsData(char * pstFileName, char cHeadFlag) {
	short i;

	if (pNpcs) {
		delete[] pNpcs;
		pNpcs = NULL;
	}

	CTextParser NpcsFile(pstFileName, cHeadFlag);	//open npcs file
	nNpcsNum = NpcsFile.GetRecordNum();				//get npcs number
	pNpcs = new CRole[nNpcsNum];	//malloc memory space to hold npcs data

	//read data one by one
	for (short nNpcsIndex = 0; nNpcsIndex < nNpcsNum; ++nNpcsIndex) {
		NpcsFile.FindRecordHead();

		//role description
		NpcsFile.GotoNextLine();
		NpcsFile.ReadString(pNpcs[nNpcsIndex].stName);
		NpcsFile.GotoNextLine();
		NpcsFile.ReadString(pNpcs[nNpcsIndex].stDescription);

		NpcsFile.GotoNextLine();
		NpcsFile.ReadInteger(&(pNpcs[nNpcsIndex].nExps[0]));	//Exp for sword
		NpcsFile.ReadInteger(&(pNpcs[nNpcsIndex].nExps[1]));	//Exp for blade
		NpcsFile.ReadInteger(&(pNpcs[nNpcsIndex].nExps[2]));	//Exp for long
		NpcsFile.ReadInteger(&(pNpcs[nNpcsIndex].nExps[3]));	//Exp for hand
		UpdateNick(nNpcsIndex); //create nick

		NpcsFile.GotoNextLine();
		NpcsFile.ReadInteger(&(pNpcs[nNpcsIndex].nHP));	//hp
		NpcsFile.ReadInteger(&(pNpcs[nNpcsIndex].nMaxHP));	//maxHP
		NpcsFile.ReadInteger(&(pNpcs[nNpcsIndex].nMP));	//mp
		NpcsFile.ReadInteger(&(pNpcs[nNpcsIndex].nMaxMP));	//maxMp

		NpcsFile.GotoNextLine();
		NpcsFile.ReadInteger(&(pNpcs[nNpcsIndex].nAttack));	//attack
		NpcsFile.ReadInteger(&(pNpcs[nNpcsIndex].nDefend));	//defend
		NpcsFile.ReadInteger(&(pNpcs[nNpcsIndex].nSpeed));	//speed

		//read skill data
		NpcsFile.GotoNextLine();
		NpcsFile.ReadInteger(&(pNpcs[nNpcsIndex].nSkillNum));	//skill number
		NpcsFile.GotoNextLine();
		for (i = 0; i < pNpcs[nNpcsIndex].nSkillNum; i++) {
			NpcsFile.ReadInteger(&(pNpcs[nNpcsIndex].MySkills[i].nSkillIndex));
			NpcsFile.ReadInteger(&(pNpcs[nNpcsIndex].MySkills[i].nSkillLevel));
			NpcsFile.ReadInteger(&(pNpcs[nNpcsIndex].MySkills[i].nTimes));
		}

		//read goods data
		NpcsFile.GotoNextLine();
		NpcsFile.ReadInteger(&(pNpcs[nNpcsIndex].nGoodsNum));	//goods number
		NpcsFile.GotoNextLine();
		for (i = 0; i < pNpcs[nNpcsIndex].nGoodsNum; i++) {
			NpcsFile.ReadInteger(&(pNpcs[nNpcsIndex].MyGoods[i]));
		}

		//equipment
		NpcsFile.GotoNextLine();
		for (i = 0; i < 4; ++i)
			NpcsFile.ReadInteger(&(pNpcs[nNpcsIndex].MyEquipment[i]));

		//money
		NpcsFile.GotoNextLine();
		NpcsFile.ReadInteger(&(pNpcs[nNpcsIndex].nMoney));

		// related script data
		NpcsFile.GotoNextLine();
		NpcsFile.ReadInteger(&(pNpcs[nNpcsIndex].nTalkScript)); //talk script index
		NpcsFile.ReadInteger(&(pNpcs[nNpcsIndex].nFailScript));	//fail script index
	}
	return true;
}

/* ��ͣ��Ϸ�����û����� */
void CGame::SystemPause() {
	system("pause>nul");
	//cout << endl;
}

/* ϵͳ��Ϣ��� */
void CGame::SystemOut(const char * stOutString) {
#ifdef _WIN32_
	SetConsoleTextAttribute( hConsoleHandle, SYSTEM_COLOR|0);
	cout << stOutString << endl << endl;
#else
	printf(SYSTEM_STRING, stOutString);
	cout << endl << endl;
#endif
}

/* ��ʾ��Ϣ��� */
void CGame::SystemHint(const char * stHintString) {
	cout << endl;
#ifdef _WIN32_
	SetConsoleTextAttribute( hConsoleHandle, SYSTEM_HINT_COLOR|0);
	cout << stHintString << endl << endl;
#else
	printf(SYSTEM_HINT_STRING, stHintString);
	cout << endl << endl;
#endif
}

/* ������Ϣ���������ͣ */
void CGame::SystemWarning(const char * stWarningString) {
#ifdef _WIN32_
	SetConsoleTextAttribute( hConsoleHandle, WARNING_COLOR|0);
	cout << stWarningString << endl;
#else
	printf(WARNING_STRING, stWarningString);
	cout << endl;
#endif
	SystemPause();
}

//��ʾ��ɫ����
void CGame::ShowNpcName(short nNpcIndex) {
#ifdef _WIN32_
	SetConsoleTextAttribute( hConsoleHandle, NPC_NAME_COLOR|0);
	cout << pNpcs[nNpcIndex].stName;
#else
	printf(NPC_NAME_STRING, pNpcs[nNpcIndex].stName);
#endif
}

//��ʾ��ɫ�º�
void CGame::ShowNickName(short nNpcIndex) {
#ifdef _WIN32_
	SetConsoleTextAttribute( hConsoleHandle, NPC_NAME_COLOR|0);
	cout << pNpcs[nNpcIndex].stNick;
#else
	printf(NICK_NAME_STRING, pNpcs[nNpcIndex].stNick);
#endif
}

void CGame::UpdateNick(short nRoleIdx) {
	short nMaxIdx = -1;
	short nMaxExp = -1;
	for (short i = 0; i < SKILL_KIND; ++i) {
		if (pNpcs[nRoleIdx].nExps[i] > nMaxExp) {
			nMaxExp = pNpcs[nRoleIdx].nExps[i];
			nMaxIdx = i;
		}
	}
	strcpy_s(pNpcs[nRoleIdx].stNick, stSkillNicks[nMaxIdx]);
	for (short i = SKILL_LVL - 1; i >= 0; --i) {
		if (nMaxExp >= nNickExp[i]) {
			strcat_s(pNpcs[nRoleIdx].stNick, stLvlNicks[i]);
			break;
		}
	}
}

void CGame::ShowNpcState(short nNpcIndex) {
	ShowNpcName(nNpcIndex);
	cout << " [";
	ShowNickName(nNpcIndex);
	cout << "] " << endl;
	cout << "( ������" << pNpcs[nNpcIndex].nHP << "/" << pNpcs[nNpcIndex].nMaxHP
			<< "�� ������" << pNpcs[nNpcIndex].nMP << "/" << pNpcs[nNpcIndex].nMaxMP
			<< "�� " << pNpcs[nNpcIndex].nMoney << "�� )" << endl;
}

//��ʾ��ɫ����
void CGame::ShowNpcDetail(short nNpcIndex) {
	ShowNpcName(nNpcIndex);
	cout << " [";
	ShowNickName(nNpcIndex);
	cout << "] " << endl;

#ifdef _WIN32_
	SetConsoleTextAttribute( hConsoleHandle, DESCRIPTION_COLOR | 0);
	cout << pNpcs[nNpcIndex].stDescription << endl;
#else
	printf(DESCRIPTION_STRING, pNpcs[nNpcIndex].stDescription);
	cout << endl;
#endif
	cout << "ͷ��: ";
	ShowEquipment(nNpcIndex, 0);
	cout << endl;
	cout << "����: ";
	ShowEquipment(nNpcIndex, 1);
	cout << endl;
	cout << "�ֳ�: ";
	ShowEquipment(nNpcIndex, 2);
	cout << endl;
	cout << "��̤: ";
	ShowEquipment(nNpcIndex, 3);
	cout << endl;

}

/* ��ʾ��ɫ����ϸ��Ϣ */
void CGame::ShowNpcDetailX(short nNpcIndex) {
	ShowNpcDetail(nNpcIndex);

#ifdef _WIN32_
	SetConsoleTextAttribute( hConsoleHandle, ITEM_NAME_COLOR| 0);
#endif

	cout << "����: " << pNpcs[nNpcIndex].nMoney << endl;
	cout << endl;

#ifdef _WIN32_
	SetConsoleTextAttribute( hConsoleHandle, DESCRIPTION_COLOR|0);
#endif

	for (short i = 0; i < SKILL_KIND; ++i) {
		cout << stSkillNicks[i] << "��Ϊ  ��" << pNpcs[nNpcIndex].nExps[i] << endl;
	}

	cout << "����    ��" << pNpcs[nNpcIndex].nHP << "\t/ "
			<< pNpcs[nNpcIndex].nMaxHP << endl;
	cout << "����    ��" << pNpcs[nNpcIndex].nMP << "\t/ "
			<< pNpcs[nNpcIndex].nMaxMP << endl;

	cout << "����    ��" << pNpcs[nNpcIndex].nAttack << "\t +"
			<< GetAddedAttack(nNpcIndex) << endl;
	cout << "����    ��" << pNpcs[nNpcIndex].nDefend << "\t +"
			<< GetAddedDefend(nNpcIndex) << endl;
	cout << "��    ��" << pNpcs[nNpcIndex].nSpeed << "\t +"
			<< GetAddedSpeed(nNpcIndex) << endl << endl;
}

//��ȡ��Դ�ļ���
bool CGame::LoadResFileName(const char* pstFileName, const char cHeadFlag) {
	CTextParser ResNameFile(pstFileName, cHeadFlag);
	ResNameFile.FindRecordHead();

	ResNameFile.GotoNextLine();
	ResNameFile.ReadString(oResFiles.stSkillFile);
	ResNameFile.GotoNextLine();
	ResNameFile.ReadString(oResFiles.stGoodsFile);
	ResNameFile.GotoNextLine();
	ResNameFile.ReadString(oResFiles.stRoleFile);
	ResNameFile.GotoNextLine();
	ResNameFile.ReadString(oResFiles.stSpotFile);
	ResNameFile.GotoNextLine();
	ResNameFile.ReadString(oResFiles.stQuestFile);
	ResNameFile.GotoNextLine();
	ResNameFile.ReadString(oResFiles.stScriptFile);
	ResNameFile.GotoNextLine();
	ResNameFile.ReadString(oResFiles.stMapFile);
	ResNameFile.GotoNextLine();
	ResNameFile.ReadString(oResFiles.stLogoFile);
	ResNameFile.GotoNextLine();
	ResNameFile.ReadString(oResFiles.stNickFile);

	return true;
}

void CGame::LoadNickData(const char * pstFileName, const char cHeadFlag) {
	CTextParser NickFile(pstFileName, cHeadFlag);
	NickFile.FindRecordHead();
	NickFile.GotoNextLine();
	short i;
	for (i = 0; i < SKILL_KIND; ++i)
		NickFile.ReadString(stSkillNicks[i]);

	NickFile.GotoNextLine();
	for (i = 0; i < SKILL_LVL; ++i)
		NickFile.ReadString(stLvlNicks[i]);

	NickFile.GotoNextLine();
	for (i = 0; i < SKILL_LVL; ++i)
		NickFile.ReadInteger(&nNickExp[i]);
}

/* load skills data */
bool CGame::LoadSkillsData(const char * pstFileName, const char cHeadFlag) {
	if (pSkills) {
		delete[] pSkills;
		pSkills = NULL;
	}

	CTextParser SkillsFile(pstFileName, cHeadFlag);
	nSkillsNum = SkillsFile.GetRecordNum();
	pSkills = new CSkill[nSkillsNum];
	if (!pSkills) {
		SystemWarning("Ϊ���ܷ����ڴ�ʧ�ܣ���Ϸ���˳���");
		return false;
	}

	for (short nSkillIndex = 0; nSkillIndex < nSkillsNum; ++nSkillIndex) {
		SkillsFile.FindRecordHead();
		SkillsFile.GotoNextLine();
		SkillsFile.ReadString(pSkills[nSkillIndex].stName);
		SkillsFile.GotoNextLine();
		SkillsFile.ReadString(pSkills[nSkillIndex].stDesc);

		SkillsFile.GotoNextLine();
		SkillsFile.ReadInteger(&(pSkills[nSkillIndex].nPower));
		SkillsFile.GotoNextLine();
		SkillsFile.ReadInteger(&(pSkills[nSkillIndex].nLvlUp));
		SkillsFile.GotoNextLine();
		SkillsFile.ReadInteger(&(pSkills[nSkillIndex].nMpCost));
		SkillsFile.GotoNextLine();
		SkillsFile.ReadInteger(&(pSkills[nSkillIndex].nSklCls));
		SkillsFile.GotoNextLine();
		SkillsFile.ReadInteger(&(pSkills[nSkillIndex].nPreExp));
		SkillsFile.GotoNextLine();
		SkillsFile.ReadInteger(&(pSkills[nSkillIndex].nAddExp));

		SkillsFile.GotoNextLine();
		SkillsFile.ReadInteger(&(pSkills[nSkillIndex].nAddHp));
		SkillsFile.GotoNextLine();
		SkillsFile.ReadInteger(&(pSkills[nSkillIndex].nAddMp));
		SkillsFile.GotoNextLine();
		SkillsFile.ReadInteger(&(pSkills[nSkillIndex].nAddAttack));
		SkillsFile.GotoNextLine();
		SkillsFile.ReadInteger(&(pSkills[nSkillIndex].nAddDef));
		SkillsFile.GotoNextLine();
		SkillsFile.ReadInteger(&(pSkills[nSkillIndex].nAddSpeed));

	}

	return true;
}

/* load goods data */
bool CGame::LoadGoodsData(char * pstFileName, char cHeadFlag) {
	if (pGoods) {
		delete[] pGoods;
		pGoods = NULL;
	}

	CTextParser GoodsFile(pstFileName, cHeadFlag);
	nGoodsNum = GoodsFile.GetRecordNum();
	pGoods = new CGoods[nGoodsNum];
	assert(pGoods);

	for (short nGoodsIndex = 0; nGoodsIndex < nGoodsNum; nGoodsIndex++) {
		GoodsFile.FindRecordHead();
		GoodsFile.GotoNextLine();
		GoodsFile.ReadString(pGoods[nGoodsIndex].stName);			//name
		GoodsFile.GotoNextLine();
		GoodsFile.ReadString(pGoods[nGoodsIndex].stDesc);		//description

		GoodsFile.GotoNextLine();
		GoodsFile.ReadInteger(&pGoods[nGoodsIndex].nProperty);//eat,equip or learn?

		GoodsFile.GotoNextLine();
		GoodsFile.ReadInteger(&pGoods[nGoodsIndex].nAddAttack);	//add attack
		GoodsFile.ReadInteger(&pGoods[nGoodsIndex].nAddDefence);//add defence
		GoodsFile.ReadInteger(&pGoods[nGoodsIndex].nAddSpeed);	//add speed

		GoodsFile.GotoNextLine();
		GoodsFile.ReadInteger(&pGoods[nGoodsIndex].nAddHP);		//add hp
		GoodsFile.ReadInteger(&pGoods[nGoodsIndex].nAddMaxHP);	//add max hp
		GoodsFile.ReadInteger(&pGoods[nGoodsIndex].nAddMP);		//add mp
		GoodsFile.ReadInteger(&pGoods[nGoodsIndex].nAddMaxMP);	//add max mp

		GoodsFile.GotoNextLine();
		GoodsFile.ReadInteger(&pGoods[nGoodsIndex].nSkillIndex);//which skill to learn

		GoodsFile.GotoNextLine();
		GoodsFile.ReadInteger(&pGoods[nGoodsIndex].nLocation);//location:head,foot...

		GoodsFile.GotoNextLine();
		GoodsFile.ReadInteger(&pGoods[nGoodsIndex].nCost);		//value
	}
	return true;
}

/* װ���������� */
bool CGame::LoadQuestData(char * pstFileName, char cHeadFlag) {
	if (pQuests) {
		delete[] pQuests;
		pQuests = NULL;
	}

	CTextParser QuestsFile(pstFileName, cHeadFlag);
	nQuestsNum = QuestsFile.GetRecordNum();
	pQuests = new CQuest[nQuestsNum];
	if (!pQuests) {
		return false;
	}

	for (short nQuestIndex = 0; nQuestIndex < nQuestsNum; ++nQuestIndex) {
		QuestsFile.FindRecordHead();
		QuestsFile.GotoNextLine();
		QuestsFile.ReadString(pQuests[nQuestIndex].stQuestDesc);
		QuestsFile.GotoNextLine();
		QuestsFile.ReadInteger(&pQuests[nQuestIndex].nRoleIndex);
		QuestsFile.GotoNextLine();
		QuestsFile.ReadInteger(&pQuests[nQuestIndex].nMapIndex);
		pQuests[nQuestIndex].nFlagValue = 0;
	}
	return true;
}

/* load scripts */
bool CGame::LoadScripts(char * pstFileName, char cHeadFlag) {
	if (pScripts) {
		delete[] pScripts;
		pScripts = NULL;
	}

	CTextParser ScriptsFile(pstFileName, cHeadFlag);	//open file
	nScriptsNumber = ScriptsFile.GetRecordNum();

	char stTemp[512];
	short nScriptsIndex = -1;
	short nValidLineIndex = -1;
	short nLineNumber = 0;
	short nValidLineNum = 0;

	//calculate line number
	while (ScriptsFile.GetWholeLine(stTemp)) {
		nLineNumber++;

		if (stTemp[0] != cHeadFlag)
			nValidLineNum++;
	}

	nScriptLineNumber = nValidLineNum;

	//malloc memory space to hold scripts
	pScripts = new CScriptLine[nValidLineNum];
	if (!pScripts) {
		cerr << "memory not enough!" << endl;
		return false;
	}

	// read scripts into memory
	ScriptsFile.GotoFileHead();
	short i;
	for (i = 0; i < nLineNumber; ++i) {
		ScriptsFile.GetWholeLine(stTemp);
		if (stTemp[0] == cHeadFlag) {
			nScriptsIndex++;
		} else {
			nValidLineIndex++;
			if (nValidLineIndex < nValidLineNum) {
				pScripts[nValidLineIndex].nScriptIndex = nScriptsIndex;
				strcpy_s(pScripts[nValidLineIndex].stScriptLine, stTemp);
			}

		}
	}
	return true;
}

/* given a id, find the first scripts who have the same id */
bool CGame::FindScripts(short nScriptsID) {
	if (!pScripts || nScriptsID >= nScriptsNumber || nScriptsID < 0) {
		return false;
	}

	nCurLineIndex = 0;

	while (pScripts[nCurLineIndex].nScriptIndex < nScriptsID) {
		nCurLineIndex++;
	}

	return true;
}

/* run scripts */
void CGame::RunScripts(short nScriptID) {
	if (!FindScripts(nScriptID))
		return;

	iRunningScripts = true;
	while (iRunningScripts) {
		//execute scripte line
		ExecuteScriptLine(pScripts[nCurLineIndex].stScriptLine);
		nCurLineIndex++;
	}
}

/* ִ��һ���ű���� */
void CGame::ExecuteScriptLine(char * stScriptLine) {
	nIndexInCurLine = 0;

	// ��ȡ����
	char stCommand[32];
	ReadSubString(stScriptLine, stCommand);

	char stStringBuffer[256];
	char stNumberBuffer[4];

	// ����
	if (!strcmp(stCommand, "RETURN")) {
		iRunningScripts = false;
	}

	//��Ļ���
	else if (!strcmp(stCommand, "PRINT")) {
		ReadSubString(stScriptLine, stStringBuffer);
		SystemOut(stStringBuffer);
		SystemPause();
	}

	//��ͣ
	else if (!strcmp(stCommand, "PAUSE"))
		SystemPause();

	else if (!strcmp(stCommand, "CLEAR"))
		system(CLEAR);

	//����
	else if (!strcmp(stCommand, "TALK")) {
		//��ȡNPC������
		ReadSubString(stScriptLine, stNumberBuffer);
		short nNpcIndex = atoi(stNumberBuffer);

		//��ȡ��������
		ReadSubString(stScriptLine, stStringBuffer);

		//���
		ShowNpcName(nNpcIndex);
		cout << ": ";
#ifdef _WIN32_
		short nRandomColor = 1 + rand()%15;
		SetConsoleTextAttribute( hConsoleHandle, nRandomColor|0);
		cout << stStringBuffer<<endl << endl;
#else
		printf(SYSTEM_HINT_STRING, stStringBuffer);
		cout << endl;
#endif
		SystemPause();
	}

	//����ĳ������ֵ��������ڲ���ֵ��ű���ת��ָ���ط�
	else if (!strcmp(stCommand, "QUEST_JUMP")) {
		//��ȡ��������
		ReadSubString(stScriptLine, stNumberBuffer);
		short nQuestIndex = atoi(stNumberBuffer);

		//��ȡ����ֵ
		ReadSubString(stScriptLine, stNumberBuffer);
		short nTestValue = atoi(stNumberBuffer);

		//������Գ�������ת
		if (pQuests[nQuestIndex].nFlagValue == nTestValue) {
			//��ȡ��ת�Ľű�����
			ReadSubString(stScriptLine, stNumberBuffer);
			short nScriptIndex = atoi(stNumberBuffer);

			//��ת
			FindScripts(nScriptIndex);
			nCurLineIndex--;
		}
	}

	//���������־
	else if (!strcmp(stCommand, "SET_FLAG")) {
		//��ȡ��������
		ReadSubString(stScriptLine, stNumberBuffer);
		short nQuestIndex = atoi(stNumberBuffer);

		//��ȡ�趨ֵ
		ReadSubString(stScriptLine, stNumberBuffer);
		short nSetValue = atoi(stNumberBuffer);

		pQuests[nQuestIndex].nFlagValue = nSetValue;
	}

	//�����ɫ����ӵ��ָ��������ĳ����
	else if (!strcmp(stCommand, "HAVE_JUMP")) {
		ReadSubString(stScriptLine, stNumberBuffer);
		short nRoleIdx = atoi(stNumberBuffer);
		ReadSubString(stScriptLine, stNumberBuffer);
		short nGoodsIdx = atoi(stNumberBuffer);
		ReadSubString(stScriptLine, stNumberBuffer);
		short nNumber = atoi(stNumberBuffer);
		if (NumOfGoods(nRoleIdx, nGoodsIdx) >= nNumber) {
			ReadSubString(stScriptLine, stNumberBuffer);
			short nScriptIndex = atoi(stNumberBuffer);
			FindScripts(nScriptIndex);
			nCurLineIndex--;
		}
	}

	//����������ڵ�������ת
	else if (!strcmp(stCommand, "MORE_JUMP")) {
		ReadSubString(stScriptLine, stNumberBuffer);
		short nVarIndex = atoi(stNumberBuffer);
		ReadSubString(stScriptLine, stNumberBuffer);
		short nTestValue = atoi(stNumberBuffer);
		if (nVars[nVarIndex] >= nTestValue) {
			ReadSubString(stScriptLine, stNumberBuffer);
			short nScriptIndex = atoi(stNumberBuffer);
			FindScripts(nScriptIndex);
			nCurLineIndex--;
		}
	}

	//���������������ת
	else if (!strcmp(stCommand, "EQ_JUMP")) {
		ReadSubString(stScriptLine, stNumberBuffer);
		short nVarIndex = atoi(stNumberBuffer);
		ReadSubString(stScriptLine, stNumberBuffer);
		short nTestValue = atoi(stNumberBuffer);
		if (nVars[nVarIndex] == nTestValue) {
			ReadSubString(stScriptLine, stNumberBuffer);
			short nScriptIndex = atoi(stNumberBuffer);
			FindScripts(nScriptIndex);
			nCurLineIndex--;
		}
	}

	//�趨����
	else if (!strcmp(stCommand, "SET_VAR")) {
		ReadSubString(stScriptLine, stNumberBuffer);
		short nVarIndex = atoi(stNumberBuffer);
		ReadSubString(stScriptLine, stNumberBuffer);
		short nValue = atoi(stNumberBuffer);
		nVars[nVarIndex] = nValue;
	}

	//���ӱ���
	else if (!strcmp(stCommand, "ADD_VAR")) {
		ReadSubString(stScriptLine, stNumberBuffer);
		short nVarIndex = atoi(stNumberBuffer);
		nVars[nVarIndex] = nVars[nVarIndex] + 1;
	}

	// YES/NO
	else if (!strcmp(stCommand, "YES_NO")) {
		SystemOut("1.��  2.��");
		short nSel = GetUserInput(1, 2);
		nVars[0] = nSel;
	}

	//����ð��
	else if (!strcmp(stCommand, "CONTINUE"))
		oGameEnv.eState = player_adven;

	else if (!strcmp(stCommand, "TRADE")) {
		oGameEnv.eState = trading;
	}

	//ս��
	else if (!strcmp(stCommand, "FIGHT")) {
		//��ȡNPC����
		ReadSubString(stScriptLine, stNumberBuffer);
		short nNpcIndex = atoi(stNumberBuffer);

		//��ʼ��ս��
		InitFight(nNpcIndex);
	}

	else if (!strcmp(stCommand, "ADD_GOODS")) {
		ReadSubString(stScriptLine, stNumberBuffer);
		short nRoleIdx = atoi(stNumberBuffer);
		ReadSubString(stScriptLine, stNumberBuffer);
		short nGoodsIndex = atoi(stNumberBuffer);
		AddGoods(nRoleIdx, nGoodsIndex, true);
	}

	else if (!strcmp(stCommand, "DEL_GOODS")) {
		ReadSubString(stScriptLine, stNumberBuffer);
		short nRoleIdx = atoi(stNumberBuffer);
		ReadSubString(stScriptLine, stNumberBuffer);
		short nGoodsIdx = atoi(stNumberBuffer);
		RemoveGoods(nRoleIdx, HaveGoods(nRoleIdx, nGoodsIdx), true);
	}

	else if (!strcmp(stCommand, "ADD_MONEY")) {
		ReadSubString(stScriptLine, stNumberBuffer);
		short nRoleIdx = atoi(stNumberBuffer);
		ReadSubString(stScriptLine, stNumberBuffer);
		short nMoney = atoi(stNumberBuffer);
		AddMoney(nRoleIdx, nMoney);
	}

	else if (!strcmp(stCommand, "DEL_MONEY")) {
		ReadSubString(stScriptLine, stNumberBuffer);
		short nRoleIdx = atoi(stNumberBuffer);
		ReadSubString(stScriptLine, stNumberBuffer);
		short nMoney = atoi(stNumberBuffer);
		if (DelMoney(nRoleIdx, nMoney))
			nVars[1] = 0;  //success
		else
			nVars[1] = 1;  //fail
	}

	//��ָ����ͼ���npc
	else if (!strcmp(stCommand, "ADD_NPC")) {
		//��ȡ��ͼ����
		ReadSubString(stScriptLine, stNumberBuffer);
		short nSpotIndex = atoi(stNumberBuffer);

		//��ȡnpc����
		ReadSubString(stScriptLine, stNumberBuffer);
		short nNpcIndex = atoi(stNumberBuffer);

		//���
		if (!AddNpc(nSpotIndex, nNpcIndex)) {
			SystemWarning("���NPCʧ�ܣ���Ϸ���˳���");
			iRunning = false;
		}
	}

	//�Ƴ�ָ����ͼ��npc
	else if (!strcmp(stCommand, "REMOVE_NPC")) {
		//��ȡ��ͼ����
		ReadSubString(stScriptLine, stNumberBuffer);
		short nSpotIndex = atoi(stNumberBuffer);

		//��ȡnpc����
		ReadSubString(stScriptLine, stNumberBuffer);
		short nNpcIndex = atoi(stNumberBuffer);

		//���
		if (!RemoveNpc(nSpotIndex, nNpcIndex)) {
			SystemWarning("ɾ��NPC������Ϸ���˳���");
			iRunning = false;
		}
	}

	else if (!strcmp(stCommand, "RANDOM_DROP")) {
		// read goods index
		ReadSubString(stScriptLine, stNumberBuffer);
		short nGoodsIndex = atoi(stNumberBuffer);

		// read probability
		ReadSubString(stScriptLine, stNumberBuffer);
		short nProb = atoi(stNumberBuffer);

		RandomDrop(oGameEnv.nCurrentNpc, nGoodsIndex, nProb);
	}

	else if (!strcmp(stCommand, "REFRESH")) {
		ReadSubString(stScriptLine, stNumberBuffer);
		short nRoleIdx = atoi(stNumberBuffer);
		Refresh(nRoleIdx);
	}
}

void CGame::RandomDrop(short nRoleIdx, short nGoodsIdx, short nProb) {
	short nRan = rand() % 100;
	if (nRan <= nProb) {
		AddGoodsToSpot(oGameEnv.nCurrentMap, nGoodsIdx);
		ShowNpcName(nRoleIdx);
		cout << "������";
		ShowGoodsName(nGoodsIdx);
		cout << endl;
		SystemPause();
	}
}

/* read a sub string from a string */
void CGame::ReadSubString(char * stString, char * stSubString) {
	short nIndex = 0;

	//ignore space before valid char
	while (stString[nIndexInCurLine] == ' ' || stString[nIndexInCurLine] == '\t') {
		nIndexInCurLine++;
	}

	//read sub string
	while (nIndexInCurLine < (short) strlen(stString)) {
		if (stString[nIndexInCurLine] == ' '
				|| stString[nIndexInCurLine] == '\t'
				|| stString[nIndexInCurLine] == '\r')
			break;
		else {
			stSubString[nIndex] = stString[nIndexInCurLine];
			nIndex++;
		}
		nIndexInCurLine++;
	}

	stSubString[nIndex] = '\0';

}

//��ʼ��ս��
void CGame::InitFight(short nNpcIndex) {
	oGameEnv.nCurrentEnemy = nNpcIndex;
	oGameEnv.nCurrentNpc = nNpcIndex;

	oActSlot[0].nRoleID = 0;
	oActSlot[0].nVirtualSpeed = pNpcs[0].nSpeed + GetAddedSpeed(0);
	oActSlot[1].nRoleID = oGameEnv.nCurrentEnemy;
	oActSlot[1].nVirtualSpeed = pNpcs[oGameEnv.nCurrentEnemy].nSpeed
			+ GetAddedSpeed(oGameEnv.nCurrentEnemy);

	oGameEnv.bFighting = true;
	oGameEnv.eState = fighting;
}

//ս������
void CGame::EndFight(short nNpcIndex) {
	//��ʾ��Ϣ
	if (nNpcIndex == 0)
		cout << "��սʤ��";
	else
		cout << "�������";
	ShowNpcName(oGameEnv.nCurrentEnemy);
	cout << "��" << endl;
	SystemPause();

	//�ƺ�
	oGameEnv.bFighting = false;
	if (nNpcIndex == 0) {
		/*
		 short exp = Experience(nNpcIndex, oGameEnv.nCurrentEnemy );
		 ShowNpcName(nNpcIndex);
		 cout <<"�õ�" << exp << "�㾭�顣" <<endl;
		 pNpcs[nNpcIndex].nExp += exp;
		 UpdateLevel( nNpcIndex );
		 SystemPause();
		 */
		RunScripts(pNpcs[oGameEnv.nCurrentEnemy].nFailScript);	//���е���ʧ�ܵĽű�
		Refresh(oGameEnv.nCurrentEnemy);

		if (oGameEnv.bFighting)
			oGameEnv.eState = fighting;
		else
			oGameEnv.eState = player_adven;
	} else {
		RunScripts(pNpcs[0].nFailScript);
		oGameEnv.eState = system_menu;
	}
}

short CGame::DecideWhoAct() {
	if (oActSlot[0].nVirtualSpeed >= oActSlot[1].nVirtualSpeed) {
		oActSlot[1].nVirtualSpeed += (pNpcs[oGameEnv.nCurrentEnemy].nSpeed
				+ GetAddedSpeed(oGameEnv.nCurrentEnemy));
		return oActSlot[0].nRoleID;
	} else {
		oActSlot[0].nVirtualSpeed += pNpcs[0].nSpeed + GetAddedSpeed(0);
		return oActSlot[1].nRoleID;
	}
}

//ѡ����ʲô����
short CGame::UseWhichSkill(short nRoleIndex) {
	short nSelectedSkill = -1;
	short nSkillPower = 0;
	short i;

	for (i = 0; i < pNpcs[nRoleIndex].nSkillNum; ++i) {
		short nPower = SkillDamage(nRoleIndex, i);
		if (nSkillPower < nPower
				&& pNpcs[nRoleIndex].nMP >= SkillMpCost(nRoleIndex, i)) {
			nSkillPower = nPower;
			nSelectedSkill = i;
		}
	}

	return nSelectedSkill;
}

//����
void CGame::EscapeOut(short nRoleIndex, short nEnemyIndex) {
	short r = rand() % 100;
	if (pNpcs[nRoleIndex].nSpeed + GetAddedSpeed(nRoleIndex)
			< pNpcs[nEnemyIndex].nSpeed + GetAddedSpeed(nEnemyIndex)) {
		if (r < 50) {
			ShowNpcName(nRoleIndex);
			cout << "������ս����" << endl;
			oGameEnv.eState = player_adven;
			oGameEnv.bFighting = false;
		} else {
			ShowNpcName(nRoleIndex);
			cout << "����ʧ�ܣ�" << endl;
			oGameEnv.eState = fighting;
		}
	} else {
		if (r < 90) {
			ShowNpcName(nRoleIndex);
			cout << "������ս����" << endl;
			oGameEnv.eState = player_adven;
			oGameEnv.bFighting = false;
		} else {
			ShowNpcName(nRoleIndex);
			cout << "����ʧ�ܣ�" << endl;
			oGameEnv.eState = fighting;
		}
	}
	SystemPause();
}

//ָ���Ľ�ɫʩչָ���ļ���
void CGame::Act(short nRoleIndex, short nSkillIndex, short nEnemyIndex) {
	short nDamage;
#ifdef _WIN32_
	SetConsoleTextAttribute( hConsoleHandle, SYSTEM_COLOR|0 );
#endif

	//��ͨ����
	if (nSkillIndex == -1) {
		nDamage = Damage(nRoleIndex, nEnemyIndex);
		ShowNpcName(nRoleIndex);
		cout << "����";
		ShowNpcName(nEnemyIndex);
		cout << "�� " << endl;
	}

	//ʹ�ü��ܹ���
	else {
		pNpcs[nRoleIndex].nMP -= SkillMpCost(nRoleIndex, nSkillIndex);
		nDamage = Damage(nRoleIndex, nEnemyIndex)
				+ SkillDamage(nRoleIndex, nSkillIndex);
		ShowNpcName(nRoleIndex);
		cout << "ʹ��";
		ShowSkillName(pNpcs[nRoleIndex].MySkills[nSkillIndex].nSkillIndex);
		cout << "����";
		ShowNpcName(nEnemyIndex);
		cout << "�� " << endl;
		if (nRoleIndex == 0)
			UpdateSkillLevel(nRoleIndex, nSkillIndex);
	}

	ShowNpcName(nEnemyIndex);
	cout << "�ܵ�" << nDamage << "���˺���";

	//����֮��
	pNpcs[nEnemyIndex].nHP -= nDamage;
	pNpcs[nEnemyIndex].nHP =
			pNpcs[nEnemyIndex].nHP > 0 ? pNpcs[nEnemyIndex].nHP : 0;

	SystemPause();
	if (pNpcs[nEnemyIndex].nHP == 0)
		EndFight(nRoleIndex);
	else {
		oGameEnv.eState = fighting;
	}
}

//��ָ���ĵ�ͼ���npc
bool CGame::AddNpc(short nSpotIndex, short nNpcIndex) {
	assert(
			nSpotIndex >= 0 && nSpotIndex < nSpotsNum && nNpcIndex >= 0
					&& nNpcIndex < nNpcsNum);

	if (pSpots[nSpotIndex].nNpcNum == 9) {
		cout << "�õ�ͼ��npc���������npc����" << endl;
		return false;
	}

	pSpots[nSpotIndex].nNpcs[pSpots[nSpotIndex].nNpcNum] = nNpcIndex;
	pSpots[nSpotIndex].nNpcNum += 1;
	return true;
}

//��ָ���ĵ�ͼ�Ƴ�npc
bool CGame::RemoveNpc(short nSpotIndex, short nNpcIndex) {
	assert(
			nSpotIndex >= 0 && nSpotIndex < nSpotsNum && nNpcIndex >= 0
					&& nNpcIndex < nNpcsNum);

	if (pSpots[nSpotIndex].nNpcNum == 0)
		return false;

	//�ҵ����npc�Ǹõ�ͼ�еĵڼ���
	short nNpcLocation;
	for (nNpcLocation = 0; nNpcLocation < pSpots[nSpotIndex].nNpcNum;
			++nNpcLocation) {
		if (pSpots[nSpotIndex].nNpcs[nNpcLocation] == nNpcIndex)
			break;
	}
	if (nNpcLocation == pSpots[nSpotIndex].nNpcNum)
		return false;

	//������npc�������һ���������npc֮���npcǰ��
	if (nNpcLocation < pSpots[nSpotIndex].nNpcNum - 1) {
		short i;
		for (i = nNpcLocation; i < pSpots[nSpotIndex].nNpcNum - 1; ++i) {
			pSpots[nSpotIndex].nNpcs[i] = pSpots[nSpotIndex].nNpcs[i + 1];
		}
	}
	pSpots[nSpotIndex].nNpcNum--;

	return true;
}

void CGame::AddMoney(short nRoleIdx, short nMoney) {
	pNpcs[nRoleIdx].nMoney += nMoney;
	ShowNpcName(nRoleIdx);
	cout << "�õ���Ǯ" << nMoney << "�ġ�" << endl;
	SystemPause();
}

bool CGame::DelMoney(short nRoleIdx, short nMoney) {
	if (pNpcs[nRoleIdx].nMoney >= nMoney) {
		pNpcs[nRoleIdx].nMoney -= nMoney;
		ShowNpcName(nRoleIdx);
		cout << "ʧȥ��Ǯ" << nMoney << "�ġ�" << endl;
		SystemPause();
		return true;
	} else {
		return false;
	}
}

//������Ʒ, visible��ʾ�Ƿ���ʾ��Ϣ
bool CGame::AddGoods(short nRoleIndex, short nGoodsIndex, bool bVisible) {
	assert(nGoodsIndex >= 0 && nGoodsIndex <= nGoodsNum);

	if (bVisible) {
		ShowNpcName(nRoleIndex);
		cout << "�õ�";
		ShowGoodsName(nGoodsIndex);
		cout << "��" << endl;
		SystemPause();
	}

	if (pNpcs[nRoleIndex].nGoodsNum == MAX_GOODS_NUM) {
		ShowNpcName(nRoleIndex);
		cout << "������������";
		ShowGoodsName(nGoodsIndex);
		cout << "�����˵��ϡ�" << endl;
		SystemPause();

		AddGoodsToSpot(oGameEnv.nCurrentMap, nGoodsIndex);
		return false;
	} else {
		pNpcs[nRoleIndex].nGoodsNum++;
		pNpcs[nRoleIndex].MyGoods[pNpcs[nRoleIndex].nGoodsNum - 1] =
				nGoodsIndex;
		return true;
	}
}

//�ӽ�ɫ�����Ƴ���Ʒ, nGoodsLocation��ָ����Ʒ����������е�λ��
bool CGame::RemoveGoods(short nRoleIndex, short nGoodsLocation, bool bVisible) {
	if (nGoodsLocation < 0 || nGoodsLocation >= pNpcs[nRoleIndex].nGoodsNum)
		return false;

	if (bVisible) {
		ShowNpcName(nRoleIndex);
		cout << "ʧȥ";
		ShowGoodsName(pNpcs[nRoleIndex].MyGoods[nGoodsLocation]);
		cout << "��" << endl;
		SystemPause();
	}

	short i;
	for (i = nGoodsLocation; i < pNpcs[nRoleIndex].nGoodsNum - 1; ++i)
		pNpcs[nRoleIndex].MyGoods[i] = pNpcs[nRoleIndex].MyGoods[i + 1];
	pNpcs[nRoleIndex].nGoodsNum--;

	return true;
}

//���ĳ����Ʒ��������ϵ�λ�ã����û�з���-1��
short CGame::HaveGoods(short nRoleIndex, short nGoodsIndex) {
	short nLoc;
	for (nLoc = 0; nLoc < pNpcs[nRoleIndex].nGoodsNum; ++nLoc) {
		if (pNpcs[nRoleIndex].MyGoods[nLoc] == nGoodsIndex)
			break;
	}

	if (nLoc == pNpcs[nRoleIndex].nGoodsNum)
		return -1;
	else
		return nLoc;
}

short CGame::NumOfGoods(short nRoleIdx, short nGoodsIdx) {
	short nNumber = 0;
	for (short i = 0; i < pNpcs[nRoleIdx].nGoodsNum; ++i) {
		if (pNpcs[nRoleIdx].MyGoods[i] == nGoodsIdx)
			nNumber++;
	}
	return nNumber;
}

//�������Ƿ���ĳ�ּ���
bool CGame::HaveSkill(short nRoleIndex, short nSkillIndex) {
	short nLoc;
	for (nLoc = 0; nLoc < pNpcs[nRoleIndex].nSkillNum; ++nLoc) {
		if (pNpcs[nRoleIndex].MySkills[nLoc].nSkillIndex == nSkillIndex)
			return true;
	}

	return false;
}

//���Ӽ���
bool CGame::AddSkill(short nRoleIndex, short nSkillIndex) {
	if (nSkillIndex < 0 || nSkillIndex >= nSkillsNum)
		return false;

	if (pNpcs[nRoleIndex].nSkillNum == MAX_SKILL_NUM) {
		ShowNpcName(nRoleIndex);
		SystemWarning("�������ﵽ���ޣ�����ѧϰ�µļ��ܣ�");
		cout << endl;
		return false;
	}
	if (HaveSkill(nRoleIndex, nSkillIndex)) {
		ShowNpcName(nRoleIndex);
		SystemWarning("�������ּ��ܣ�");
		cout << endl;
		return false;
	}

	short nSkillClass = pSkills[nSkillIndex].nSklCls;

	if (pNpcs[nRoleIndex].nExps[nSkillClass] < pSkills[nSkillIndex].nPreExp) {
		ShowNpcName(nRoleIndex);
		SystemWarning("����Ϊ���������������书��");
		cout << endl;
		return false;
	}

	pNpcs[nRoleIndex].MySkills[pNpcs[nRoleIndex].nSkillNum].nSkillIndex =
			nSkillIndex;
	pNpcs[nRoleIndex].MySkills[pNpcs[nRoleIndex].nSkillNum].nSkillLevel = 1;
	pNpcs[nRoleIndex].MySkills[pNpcs[nRoleIndex].nSkillNum].nTimes = 0;
	pNpcs[nRoleIndex].nSkillNum++;
	ShowNpcName(nRoleIndex);
	cout << "ϰ��";
	ShowSkillName(nSkillIndex);
	cout << "��" << endl;
	SystemPause();
	return true;
}

//����Ʒ��ѧϰ���ܣ����ü����Ʒ�ǲ��ǿ�����ϰ�������usegoods�����м�顣
void CGame::LearnSkill(short nRoleIndex, short nGoodsIndex) {
	AddSkill(nRoleIndex, pGoods[nGoodsIndex].nSkillIndex);
}

void CGame::SellGoods(short nRoleIndex, short nGoodsLocation) {
	ShowNpcName(nRoleIndex);
	cout << "������";
	ShowGoodsName(pNpcs[nRoleIndex].MyGoods[nGoodsLocation]);
	cout << "��" << endl;
	SystemPause();

	pNpcs[nRoleIndex].nMoney +=
			pGoods[pNpcs[nRoleIndex].MyGoods[nGoodsLocation]].nCost / 2;
	RemoveGoods(nRoleIndex, nGoodsLocation, false);

}

void CGame::BuyGoods(short nRoleIndex, short nGoodsIndex) {
	if (pNpcs[nRoleIndex].nMoney > pGoods[nGoodsIndex].nCost) {
		ShowNpcName(nRoleIndex);
		cout << "������";
		ShowGoodsName(nGoodsIndex);
		cout << "��" << endl;

		AddGoods(nRoleIndex, nGoodsIndex, false);
		pNpcs[nRoleIndex].nMoney -= pGoods[nGoodsIndex].nCost;
	} else {
		ShowNpcName(oGameEnv.nCurrentNpc);
		cout << ": ���Ǯ������" << endl;
	}

	SystemPause();
}

//������Ʒ�����ü����Ʒ�Ƿ���Է��ã�����use goods�����м��
void CGame::Eat(short nRoleIndex, short nGoodsIndex) {
	ShowNpcName(nRoleIndex);
	cout << "������";
	ShowGoodsName(nGoodsIndex);
	cout << "��" << endl;
	SystemPause();

	if (pGoods[nGoodsIndex].nAddMaxHP) {
		cout << "�������ޣ�" << pNpcs[nRoleIndex].nMaxHP << "\t---->\t";
		pNpcs[nRoleIndex].nMaxHP += pGoods[nGoodsIndex].nAddMaxHP;
		cout << pNpcs[nRoleIndex].nMaxHP << endl;
	}

	if (pGoods[nGoodsIndex].nAddHP) {
		cout << "��ǰ������" << pNpcs[nRoleIndex].nHP << "\t---->\t";
		pNpcs[nRoleIndex].nHP += pGoods[nGoodsIndex].nAddHP;
		if (pNpcs[nRoleIndex].nHP > pNpcs[nRoleIndex].nMaxHP)
			pNpcs[nRoleIndex].nHP = pNpcs[nRoleIndex].nMaxHP;
		cout << pNpcs[nRoleIndex].nHP << endl;
	}

	if (pGoods[nGoodsIndex].nAddMaxMP) {
		cout << "�������ޣ�" << pNpcs[nRoleIndex].nMaxMP << "\t---->\t";
		pNpcs[nRoleIndex].nMaxMP += pGoods[nGoodsIndex].nAddMaxMP;
		cout << pNpcs[nRoleIndex].nMaxMP << endl;
	}

	if (pGoods[nGoodsIndex].nAddMP) {
		cout << "��ǰ������" << pNpcs[nRoleIndex].nMP << "\t---->\t";
		pNpcs[nRoleIndex].nMP += pGoods[nGoodsIndex].nAddMP;
		if (pNpcs[nRoleIndex].nMP > pNpcs[nRoleIndex].nMaxMP)
			pNpcs[nRoleIndex].nMP = pNpcs[nRoleIndex].nMaxMP;
		cout << pNpcs[nRoleIndex].nMP << endl;
	}

	SystemPause();
}

//װ��
void CGame::Equip(short nRoleIndex, short nGoodsLocation) {
	short oldAttack, oldDefend, oldSpeed;
	oldAttack = GetAddedAttack(nRoleIndex);
	oldDefend = GetAddedDefend(nRoleIndex);
	oldSpeed = GetAddedSpeed(nRoleIndex);

	short nIndex = pNpcs[nRoleIndex].MyGoods[nGoodsLocation];
	UnEquip(nRoleIndex, pGoods[nIndex].nLocation);

	ShowNpcName(nRoleIndex);
	cout << "װ����";
	ShowGoodsName(pNpcs[nRoleIndex].MyGoods[nGoodsLocation]);
	cout << "��" << endl;
	SystemPause();

	pNpcs[nRoleIndex].MyEquipment[pGoods[nIndex].nLocation] = nIndex;
	RemoveGoods(nRoleIndex, nGoodsLocation, false);

	cout << "������" << pNpcs[nRoleIndex].nAttack << " + " << oldAttack
			<< "\t---->\t" << pNpcs[nRoleIndex].nAttack << " + "
			<< GetAddedAttack(nRoleIndex) << "\t("
			<< GetAddedAttack(nRoleIndex) - oldAttack << ")" << endl;

	cout << "���壺" << pNpcs[nRoleIndex].nDefend << " + " << oldDefend
			<< "\t---->\t" << pNpcs[nRoleIndex].nDefend << " + "
			<< GetAddedDefend(nRoleIndex) << "\t("
			<< GetAddedDefend(nRoleIndex) - oldDefend << ")" << endl;

	cout << "���ݣ�" << pNpcs[nRoleIndex].nSpeed << " + " << oldSpeed
			<< "\t---->\t" << pNpcs[nRoleIndex].nSpeed << " + "
			<< GetAddedSpeed(nRoleIndex) << "\t("
			<< GetAddedSpeed(nRoleIndex) - oldSpeed << ")" << endl;

	SystemPause();
}

//�Ƴ�װ��
void CGame::UnEquip(short nRoleIndex, short nLocation) {
	short nGoosIndex = pNpcs[nRoleIndex].MyEquipment[nLocation];
	if (nGoosIndex == -1)
		return;

	ShowNpcName(nRoleIndex);
	cout << "ж����";
	ShowGoodsName(nGoosIndex);
	cout << "��" << endl;
	SystemPause();

	AddGoods(nRoleIndex, nGoosIndex, false);
	pNpcs[nRoleIndex].MyEquipment[nLocation] = -1;
}

//ʹ����Ʒ
void CGame::UseGoods(short nRoleIndex, short nGoodsLocation) {
	switch (pGoods[pNpcs[nRoleIndex].MyGoods[nGoodsLocation]].nProperty) {
	case 0:	//����
		Eat(nRoleIndex, pNpcs[nRoleIndex].MyGoods[nGoodsLocation]);
		RemoveGoods(nRoleIndex, nGoodsLocation, false);
		break;
	case 1: //װ��
		Equip(nRoleIndex, nGoodsLocation);
		break;
	case 2:  //ѧϰ
		LearnSkill(nRoleIndex, pNpcs[nRoleIndex].MyGoods[nGoodsLocation]);
		break;
	default:	//������Ʒ
		SystemWarning("��֪����ôʹ�����ֶ�����");
		cout << endl;
	}
}

//������Ʒ������nGoodsLocation��ָ�����Ʒ�ڳ�����Ʒ�е�λ��
void CGame::PickGoods(short nRoleIndex, short nGoodsLocation) {
	ShowNpcName(nRoleIndex);
	if (pNpcs[nRoleIndex].nGoodsNum == MAX_GOODS_NUM)
		cout << "�������������Ų����κζ����ˡ�" << endl;
	else {
		cout << "����";
		ShowGoodsName(pSpots[oGameEnv.nCurrentMap].nGoods[nGoodsLocation]);
		cout << "��" << endl;
		AddGoods(nRoleIndex,
				pSpots[oGameEnv.nCurrentMap].nGoods[nGoodsLocation], false);
		RmGoodsFromSpot(oGameEnv.nCurrentMap, nGoodsLocation);
	}

	SystemPause();
}

//�ӳ�����ȥ��ĳ����Ʒ
void CGame::RmGoodsFromSpot(short nSpotIndex, short nGoodsLocation) {
	short i;
	for (i = nGoodsLocation; i < pSpots[nSpotIndex].nGoodsNum - 1; ++i)
		pSpots[nSpotIndex].nGoods[i] = pSpots[nSpotIndex].nGoods[i + 1];
	pSpots[nSpotIndex].nGoodsNum--;
}

//������Ʒ��������
void CGame::AddGoodsToSpot(short nSpotIndex, short nGoodsIndex) {
	if (pSpots[nSpotIndex].nGoodsNum == MAX_GOODS_NUM) {
		short i;
		for (i = 0; i < pSpots[nSpotIndex].nGoodsNum - 1; ++i)
			pSpots[nSpotIndex].nGoods[i] = pSpots[nSpotIndex].nGoods[i + 1];
		pSpots[nSpotIndex].nGoods[i] = nGoodsIndex;
	} else {
		pSpots[nSpotIndex].nGoods[pSpots[nSpotIndex].nGoodsNum] = nGoodsIndex;
		pSpots[nSpotIndex].nGoodsNum++;
	}
}

//����սʤ���˺�õ��ľ���
short CGame::Experience(short nRoleIndex, short nEnemyIndex) {
	return 0;
}

//���½�ɫ�ȼ�
void CGame::UpdateLevel(short nRoleIndex) {
	//������黹������100%������
	/*
	 if ( pNpcs[nRoleIndex].nExp < 100 )	return;

	 #ifdef _WIN32_
	 SetConsoleTextAttribute( hConsoleHandle, ITEM_NAME_COLOR|0 );
	 #endif
	 cout << pNpcs[nRoleIndex].stName << "����������" << endl;
	 SystemPause();

	 cout << "����   "<<pNpcs[nRoleIndex].nLevel << "\t---->\t";
	 pNpcs[nRoleIndex].nLevel ++;
	 cout << pNpcs[nRoleIndex].nLevel << endl;

	 cout <<"�������ޣ�"<<pNpcs[nRoleIndex].nMaxHP << "\t---->\t";
	 pNpcs[nRoleIndex].nMaxHP = pNpcs[nRoleIndex].nMaxHP +
	 pNpcs[nRoleIndex].nLevel + rand()%6;
	 cout << pNpcs[nRoleIndex].nMaxHP << endl;

	 cout <<"�������ޣ�"<<pNpcs[nRoleIndex].nMaxMP << "\t---->\t";
	 pNpcs[nRoleIndex].nMaxMP = pNpcs[nRoleIndex].nMaxMP +
	 pNpcs[nRoleIndex].nLevel + rand()%6;
	 cout << pNpcs[nRoleIndex].nMaxMP << endl;

	 cout <<"����    ��"<<pNpcs[nRoleIndex].nAttack << "\t---->\t";
	 pNpcs[nRoleIndex].nAttack = pNpcs[nRoleIndex].nAttack +
	 pNpcs[nRoleIndex].nLevel/5 + rand()%2;
	 cout << pNpcs[nRoleIndex].nAttack << endl;

	 cout <<"����    ��"<<pNpcs[nRoleIndex].nDefend << "\t---->\t";
	 pNpcs[nRoleIndex].nDefend = pNpcs[nRoleIndex].nDefend +
	 (short)((float)pNpcs[nRoleIndex].nMaxHP * 12 / 100 );
	 cout << pNpcs[nRoleIndex].nDefend << endl;

	 cout <<"����    ��"<<pNpcs[nRoleIndex].nSpeed << "\t---->\t";
	 pNpcs[nRoleIndex].nSpeed = pNpcs[nRoleIndex].nSpeed +
	 pNpcs[nRoleIndex].nLevel/5 + rand()%2;
	 cout << pNpcs[nRoleIndex].nSpeed << endl;

	 Refresh( nRoleIndex );
	 pNpcs[nRoleIndex].nExp =
	 (short)((float)(pNpcs[nRoleIndex].nExp - 100) / pNpcs[nRoleIndex].nLevel);

	 SystemPause();
	 */
}

//�����˺�
short CGame::Damage(short nRoleIndex, short nEnemyIndex) {
	short nAtk = pNpcs[nRoleIndex].nAttack + GetAddedAttack(nRoleIndex);
	short nDef = pNpcs[nEnemyIndex].nDefend + GetAddedDefend(nEnemyIndex);

	if (nAtk > nDef)
		return (nAtk - nDef + rand() % 3);
	else
		return rand() % 3;
	//return (int)(nAtk * (float)(100-nDef) / 100) + rand()%3;
}

//���㼼���˺�
short CGame::SkillDamage(short nRoleIndex, short nSkillIndex) {
	return (pSkills[pNpcs[nRoleIndex].MySkills[nSkillIndex].nSkillIndex].nPower
			* pNpcs[nRoleIndex].MySkills[nSkillIndex].nSkillLevel);
}

//�������ĵ�����
short CGame::SkillMpCost(short nRoleIndex, short nSkillIndex) {
	return pSkills[pNpcs[nRoleIndex].MySkills[nSkillIndex].nSkillIndex].nMpCost
			* pNpcs[nRoleIndex].MySkills[nSkillIndex].nSkillLevel;
}

//��������
void CGame::SkillLevelUp(short nRoleIndex, short nSkillIndex) {
	pNpcs[nRoleIndex].MySkills[nSkillIndex].nSkillLevel++;
	pNpcs[nRoleIndex].MySkills[nSkillIndex].nTimes = 0;
	short nHpAdded =
			pNpcs[nRoleIndex].MySkills[nSkillIndex].nSkillLevel
					* pSkills[pNpcs[nRoleIndex].MySkills[nSkillIndex].nSkillIndex].nAddHp;
	pNpcs[nRoleIndex].nMaxHP += nHpAdded;
	short nMpAdded =
			pNpcs[nRoleIndex].MySkills[nSkillIndex].nSkillLevel
					* pSkills[pNpcs[nRoleIndex].MySkills[nSkillIndex].nSkillIndex].nAddMp;
	pNpcs[nRoleIndex].nMaxMP += nMpAdded;
	short nAtkAdded =
			pNpcs[nRoleIndex].MySkills[nSkillIndex].nSkillLevel
					* pSkills[pNpcs[nRoleIndex].MySkills[nSkillIndex].nSkillIndex].nAddAttack;
	pNpcs[nRoleIndex].nAttack += nAtkAdded;
	short nDefAdded =
			pNpcs[nRoleIndex].MySkills[nSkillIndex].nSkillLevel
					* pSkills[pNpcs[nRoleIndex].MySkills[nSkillIndex].nSkillIndex].nAddDef;
	pNpcs[nRoleIndex].nDefend += nDefAdded;
	short nSpeedAdded =
			pNpcs[nRoleIndex].MySkills[nSkillIndex].nSkillLevel
					* pSkills[pNpcs[nRoleIndex].MySkills[nSkillIndex].nSkillIndex].nAddSpeed;
	pNpcs[nRoleIndex].nSpeed += nSpeedAdded;

	cout << endl;
	ShowNpcName(nRoleIndex);
	cout << "��";
	ShowSkillName(pNpcs[nRoleIndex].MySkills[nSkillIndex].nSkillIndex);
	cout << "������" << pNpcs[nRoleIndex].MySkills[nSkillIndex].nSkillLevel << "�أ�"
			<< endl;
	cout << "������������" << nHpAdded << "��" << endl;
	cout << "������������" << nMpAdded << "��" << endl;
	cout << "��������" << nAtkAdded << "��" << endl;
	cout << "��������" << nDefAdded << "��" << endl;
	cout << "������" << nSpeedAdded << "��" << endl;

	SystemPause();
}

//���¼��ܵȼ�
void CGame::UpdateSkillLevel(short nRoleIndex, short nSkillIndex) {
	short global_skill_index =
			pNpcs[nRoleIndex].MySkills[nSkillIndex].nSkillIndex;
	short local_skill_level =
			pNpcs[nRoleIndex].MySkills[nSkillIndex].nSkillLevel;

	short nExpAdded = local_skill_level * pSkills[global_skill_index].nAddExp;
	pNpcs[nRoleIndex].nExps[pSkills[global_skill_index].nSklCls] += nExpAdded;
	cout << stSkillNicks[pSkills[nSkillIndex].nSklCls] << "��Ϊ����" << nExpAdded
			<< endl;
	UpdateNick(nRoleIndex);

	if (local_skill_level == MAX_SKILL_LEVEL)
		return;

	pNpcs[nRoleIndex].MySkills[nSkillIndex].nTimes++;
	if (pNpcs[nRoleIndex].MySkills[nSkillIndex].nTimes
			== local_skill_level * pSkills[global_skill_index].nLvlUp) {
		SkillLevelUp(nRoleIndex, nSkillIndex);
	}
}

void CGame::Refresh(short nRoleIndex) {
	pNpcs[nRoleIndex].nHP = pNpcs[nRoleIndex].nMaxHP;
	pNpcs[nRoleIndex].nMP = pNpcs[nRoleIndex].nMaxMP;
}

short CGame::GetAddedAttack(short nRoleIndex) {
	short nAdd = 0;
	short i;
	for (i = 0; i < 4; ++i) {
		if (pNpcs[nRoleIndex].MyEquipment[i] != -1)
			nAdd += pGoods[pNpcs[nRoleIndex].MyEquipment[i]].nAddAttack;
	}

	return nAdd;
}

short CGame::GetAddedDefend(short nRoleIndex) {
	short nAdd = 0;
	short i;
	for (i = 0; i < 4; ++i) {
		if (pNpcs[nRoleIndex].MyEquipment[i] != -1)
			nAdd += pGoods[pNpcs[nRoleIndex].MyEquipment[i]].nAddDefence;
	}

	return nAdd;
}

short CGame::GetAddedSpeed(short nRoleIndex) {
	short nAdd = 0;
	short i;
	for (i = 0; i < 4; ++i) {
		if (pNpcs[nRoleIndex].MyEquipment[i] != -1)
			nAdd += pGoods[pNpcs[nRoleIndex].MyEquipment[i]].nAddSpeed;
	}

	return nAdd;
}
