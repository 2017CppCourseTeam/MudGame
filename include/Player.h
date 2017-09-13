#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "War.h"

class Player
{
    public:
        Player();
        ~Player();

        void Show_Status(); // ��ӡ���״̬

        void Train_Coder(); // ѵ����ũ
        void Dig_Mine(); // �ڿ�
        void Wash_Brain(); // ϴ��

        void Random_Event(); // ����¼�
        void Mine_Crash(); // ����
        void Brain_Unwashed(); // ϴ��ʧ��
        void AI_Rebel(); // AI����

        double Get_Prestige(); // �õ�����
        double Get_Bitcoin(); // �õ����ر�
        double Get_Violence(); // �õ�����ֵ
        int Get_Second(); // �õ�ʱ��
        unsigned short Get_War_Num(); // �õ�ս������
        string Get_name(); // �õ����������
        void Set_name ( string name ); // ���ø��������
        bool Check_Win(); // �������Ƿ�ʤ��

        enum IDENTITY GetIdentity();
        void SetIdentity ( enum IDENTITY identity );

        /**
        * ���º�������ս��
        * ��War�������нӿ�ת�������
        **/
        void First();
        bool Is_First(); // �ж�����Ƿ�����
        void Restart_War(); //������ս������
        void Start_War ( Map*& _map ); // ��ʼս��
        void End_War ( Map*& _map ); // ����ս��

        void Show_War_Status(); // ��ӡ��ǰս��״̬
        void Show_Map ( bool show_detail ); // ��ӡ��ǰ��ͼ
        bool Select_Point ( unsigned int _x, unsigned int _y ); // �ڵ�ͼ��ѡ��һ���㣨_x, _y��
        void Show_Ponit_Status(); // ��ӡ�õ�״̬
        bool Select_Soldier ( unsigned int id ); // �ڵ�ͼ��ѡ��һ��ʿ��������idʹѡ����ָ���id��ʿ����
        void Show_Soldier_Status ( unsigned int id ); // ��ӡ��ʿ����״̬������id��
        void Show_Soldier_Status ( );  // ��ӡ��ʿ����״̬������ѡ������ ����
        bool IsSelectSoldier(); // �ж�ѡ�����Ƿ�ѡ����һ��ʿ��

        unsigned int GetPlayerBaseX(); // �õ���һ��صľ���X����
        unsigned int GetPlayerBaseY(); // �õ���һ��صľ���Y����
        unsigned int GetAIBaseX(); // �õ�AI���صľ���X����
        unsigned int GetAIBaseY(); // �õ�AI���صľ���Y����

        bool CheckWin(); // ����Ƿ�ʤ��

        enum AllSoldiers GetCurrentSoldierName();

        enum LocalPower GetCityPower(); // �õ���ǰʿ��ѡ������ָ���ʿ�����ڵĳ��й�����ö�����ͣ�

        void BuildCity(); // �ڵ�ǰʿ��ѡ������ѡ���ʿ���ĵص㴦����һ������

        bool MoveUp(); // ʿ��ѡ������ָ���ʿ������
        bool MoveDown(); // ʿ��ѡ������ָ���ʿ������
        bool MoveLeft(); // ʿ��ѡ������ָ���ʿ������
        bool MoveRight(); // ʿ��ѡ������ָ���ʿ������
        void Recover(); // ÿ�غ��Զ��ظ�

        bool Create_Soldier ( enum AllSoldiers soldier, enum LocalPower power, unsigned int x, unsigned int y ); // �ڵ�ͼ��x��y�������괦����һ��ʿ��
        void Delete_Soldier ( unsigned int _id ); // ɾ����id��ʿ��
        Soldier* GetSoldierFromPoint ( unsigned int _x, unsigned int _y, unsigned int _id );
        bool IsCounterAttack();
        void AttackBase ( unsigned int _x, unsigned int _y );
        void AttackSoldier ( unsigned int _x, unsigned int _y );
        void AttackCity ( unsigned int _x, unsigned int _y );

        /** This for AI **/
        void AI_Init ( double prestige, double bitcoin, double violence, int second, unsigned short war_num, bool first ); // ��ʼ��AI�Ľӿ�
        void Action();
        int getAct_num();
        /** This for AI **/
    private:
        enum Is_Win _Result();

        double prestige;
        double bitcoin;
        double violence;
        int second;
        unsigned short war_num;
        bool war_first;
        string name;

        enum IDENTITY identity;
        //enum Species allow_species[];

        /** This for AI **/
        int act_num;
        int act[10];
        int coldness;
        /** This for AI **/

        HANDLE handle;
        War* war;
        friend class User;

};

#endif // PLAYER1_H_INCLUDED
