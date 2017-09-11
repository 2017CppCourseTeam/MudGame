#ifndef WAR_H_INCLUDED
#define WAR_H_INCLUDED

#include "Map.h"

class War
{
        // 该类不提供对外接口，全部接口转入Player类中
    private:
        War ( double prestige, double bitcoin, double violence, int second, unsigned short war_num, Map*& _map );
        ~War();
        void _Show_Status();
        void _Show_Map ( bool show_detail = false );
        bool _Select_Point ( unsigned int _x, unsigned int _y );
        void _Show_Point_Status();
        bool _Select_Soldier ( unsigned int id );
        void _Show_Soldier_Status ( unsigned int id );
        bool _Create_Soldier ( enum AllSoldiers soldier, enum LocalPower power, unsigned int x, unsigned int y, double* _life, double* _magic, unsigned int* _coin );
        void _Delete_Soldier ( unsigned int _id );
        bool _IsSelectSoldier();
        unsigned int _GetPlayerBaseX();
        unsigned int _GetPlayerBaseY();
        unsigned int _GetAIBaseX();
        unsigned int _GetAIBaseY();
        void _AddSoldierToMap ( const char& _c, unsigned int _x, unsigned int _y, Soldier& _soldier );
        void _Show_Soldier_Status();
        enum AllSoldiers _GetCurrentSoldierName();
        enum LocalPower _GetCityPower();
        void _BuildCity();

        double life;
        double magic;
        unsigned int coin;
        double lucky;
        unsigned int _id;

        vector<Soldier> created_soldier;

        Map* _map;
        Point* point_selecter;
        Soldier* soldier_selecter;

        friend class Player;
<<<<<<< HEAD
        friend class Commander;
        friend class AI;
=======
>>>>>>> acbadf8fde47ffe048f458d2c5a504baec69387f

};

#endif // WAR_H
