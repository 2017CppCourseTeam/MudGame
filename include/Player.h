#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "War.h"

class Player
{
    public:
        Player();
        ~Player();

        void Show_Status(); // 打印玩家状态

        void Train_Coder(); // 训练码农
        void Dig_Mine(); // 挖矿
        void Wash_Brain(); // 洗脑

        void Random_Event(); // 随机事件
        void Mine_Crash(); // 矿难
        void Brain_Unwashed(); // 洗脑失败
        void AI_Rebel(); // AI反叛

        double Get_Prestige(); // 得到威望
        double Get_Bitcoin(); // 得到比特币
        double Get_Violence(); // 得到暴力值
        int Get_Second(); // 得到时间
        unsigned short Get_War_Num(); // 得到战争进度
        string Get_name(); // 得到该玩家姓名
        void Set_name ( string name ); // 设置该玩家姓名
        bool Check_Win(); // 检查玩家是否胜利

        enum IDENTITY GetIdentity();
        void SetIdentity ( enum IDENTITY identity );

        /**
        * 以下函数用于战争
        * 将War类中所有接口转入该类中
        **/
        void First();
        bool Is_First(); // 判断玩家是否先手
        void Restart_War(); //　重置战争进度
        void Start_War ( Map*& _map ); // 开始战争
        void End_War ( Map*& _map ); // 结束战争

        void Show_War_Status(); // 打印当前战争状态
        void Show_Map ( bool show_detail ); // 打印当前地图
        bool Select_Point ( unsigned int _x, unsigned int _y ); // 在地图上选择一个点（_x, _y）
        void Show_Ponit_Status(); // 打印该点状态
        bool Select_Soldier ( unsigned int id ); // 在地图上选择一个士兵（根据id使选择器指向该id的士兵）
        void Show_Soldier_Status ( unsigned int id ); // 打印该士兵的状态（根据id）
        void Show_Soldier_Status ( );  // 打印该士兵的状态（根据选择器） 重载
        bool IsSelectSoldier(); // 判断选择器是否选择了一个士兵

        unsigned int GetPlayerBaseX(); // 得到玩家基地的绝对X坐标
        unsigned int GetPlayerBaseY(); // 得到玩家基地的绝对Y坐标
        unsigned int GetAIBaseX(); // 得到AI基地的绝对X坐标
        unsigned int GetAIBaseY(); // 得到AI基地的绝对Y坐标

        bool CheckWin(); // 检查是否胜利

        enum AllSoldiers GetCurrentSoldierName();

        enum LocalPower GetCityPower(); // 得到当前士兵选择器所指向的士兵所在的城市归属（枚举类型）

        void BuildCity(); // 在当前士兵选择器所选择的士兵的地点处建立一个城市

        bool MoveUp(); // 士兵选择器所指向的士兵上移
        bool MoveDown(); // 士兵选择器所指向的士兵下移
        bool MoveLeft(); // 士兵选择器所指向的士兵左移
        bool MoveRight(); // 士兵选择器所指向的士兵右移
        void Recover(); // 每回合自动回复

        bool Create_Soldier ( enum AllSoldiers soldier, enum LocalPower power, unsigned int x, unsigned int y ); // 在地图上x，y绝对坐标处生成一个士兵
        void Delete_Soldier ( unsigned int _id ); // 删除该id的士兵
        Soldier* GetSoldierFromPoint ( unsigned int _x, unsigned int _y, unsigned int _id );
        bool IsCounterAttack();
        void AttackBase ( unsigned int _x, unsigned int _y );
        void AttackSoldier ( unsigned int _x, unsigned int _y );
        void AttackCity ( unsigned int _x, unsigned int _y );

        /** This for AI **/
        void AI_Init ( double prestige, double bitcoin, double violence, int second, unsigned short war_num, bool first ); // 初始化AI的接口
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
