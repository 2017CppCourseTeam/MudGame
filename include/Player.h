#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "War.h"

class Player
{
    public:
        Player();
        ~Player();

        void ShowStatus(); // ��ӡ���״̬

        void TrainCoder(); // ѵ����ũ
        void DigMine(); // �ڿ�
        void WashBrain(); // ϴ��

        void RandomEvent(); // ����¼�
        void MineCrash(); // ����
        void BrainUnwashed(); // ϴ��ʧ��
        void AIRebel(); // AI����

        double GetPrestige(); // �õ�����
        double GetBitcoin(); // �õ����ر�
        double GetViolence(); // �õ�����ֵ
        int GetSecond(); // �õ�ʱ��
        unsigned short GetWarNum(); // �õ�ս������
        void SetWarNum ( unsigned int num ); // ����ս������
        string GetName(); // �õ����������
        void SetName ( string name ); // ���ø��������
        bool CheckWinOfWar(); // �������Ƿ�ʤ��

        enum IDENTITY GetIdentity(); // �õ�Playerʵ�������
        void SetIdentity ( enum IDENTITY identity ); // ����Playerʵ�������

        /**
        * ���º�������ս��
        **/
        void First();
        bool IsFirst(); // �ж�����Ƿ�����
        void RestartWar(); //������ս������
        void StartWar ( Map*& _map ); // ��ʼս��
        void EndWar ( Map*& _map ); // ����ս��

        void ShowWarStatus(); // ��ӡ��ǰս��״̬
        void ShowMap ( bool show_detail ); // ��ӡ��ǰ��ͼ
        bool SelectPoint ( unsigned int _x, unsigned int _y ); // �ڵ�ͼ��ѡ��һ���㣨_x, _y��
        void ShowPonitStatus(); // ��ӡ�õ�״̬
        bool SelectSoldier ( unsigned int id ); // �ڵ�ͼ��ѡ��һ��ʿ��������idʹѡ����ָ���id��ʿ����
        void ShowSoldierStatus ( unsigned int id ); // ��ӡ��ʿ����״̬������id��
        void ShowSoldierStatus ( );  // ��ӡ��ʿ����״̬������ѡ������ ����
        bool IsSelectSoldier(); // �ж�ѡ�����Ƿ�ѡ����һ��ʿ��

        unsigned int GetPlayerBaseX(); // �õ���һ��صľ���X����
        unsigned int GetPlayerBaseY(); // �õ���һ��صľ���Y����
        unsigned int GetAIBaseX(); // �õ�AI���صľ���X����
        unsigned int GetAIBaseY(); // �õ�AI���صľ���Y����
        // �����Ӯ
        bool CheckWin();
        bool CheckLose();

        enum AllSoldiers GetCurrentSoldierName();

        enum LocalPower GetCityPower(); // �õ���ǰʿ��ѡ������ָ���ʿ�����ڵĳ��й�����ö�����ͣ�

        void BuildCity(); // �ڵ�ǰʿ��ѡ������ѡ���ʿ���ĵص㴦����һ������

        bool MoveUp( ); // ʿ��ѡ������ָ���ʿ������
        bool MoveDown( ); // ʿ��ѡ������ָ���ʿ������
        bool MoveLeft( ); // ʿ��ѡ������ָ���ʿ������
        bool MoveRight( ); // ʿ��ѡ������ָ���ʿ������
        void Recover( ); // ÿ�غ��Զ��ظ�

        bool CreateSoldier ( enum AllSoldiers soldier, enum LocalPower power, unsigned int x, unsigned int y ); // �ڵ�ͼ��x��y�������괦����һ��ʿ��
        void DeleteSoldier ( unsigned int _id ); // ɾ����id��ʿ��
        Soldier* GetSoldierFromPoint ( unsigned int _x, unsigned int _y, unsigned int _id );
        bool IsCounterAttack();
        void AttackBase ( unsigned int _x, unsigned int _y );
        void AttackSoldier ( unsigned int _x, unsigned int _y, enum Direct _direct, bool _cattack = true );
        void AttackCity ( unsigned int _x, unsigned int _y );

        /** This for AI **/
        void AIInit ( double prestige, double bitcoin, double violence, int second, unsigned short war_num, bool first ); // ��ʼ��AI�Ľӿ�
        void Action();
        int GetActNum();
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
        int round_num;
        int act[10];
        int coldness;
        /** This for AI **/

        HANDLE handle;
        War* war;
        friend class User;

};

#endif // PLAYER1_H_INCLUDED
