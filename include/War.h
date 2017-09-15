#ifndef WAR_H_INCLUDED
#define WAR_H_INCLUDED

#include "Map.h"

class War
{
        // 该类不提供对外接口，全部接口转入Player类中
    private:
        War ( double prestige, double bitcoin, double violence, int second, unsigned short war_num, Map*& _map );
        ~War();
        void _ShowStatus();
        void _ShowMap ( bool show_detail = false );
        bool _SelectPoint ( unsigned int _x, unsigned int _y );
        void _ShowPointStatus();
        bool _SelectSoldier ( unsigned int id );
        void _ShowSoldierStatus ( unsigned int id );
        bool _CreateSoldier ( enum AllSoldiers soldier, enum LocalPower power, unsigned int x, unsigned int y, double* _life, double* _magic, unsigned int* _coin );
        void _DeleteSoldier ( unsigned int _id );
        bool _IsSelectSoldier();
        unsigned int _GetPlayerBaseX();
        unsigned int _GetPlayerBaseY();
        unsigned int _GetAIBaseX();
        unsigned int _GetAIBaseY();
        double _GetLife();
        double _GetMagic();
        unsigned int _GetCoin();
        double _GetLucky();
        void _AddSoldierToMap ( const char& _c, unsigned int _x, unsigned int _y, Soldier& _soldier );
        void _ShowSoldierStatus();
        Soldier* _GetSoldierFromPoint ( unsigned int _x, unsigned int _y, unsigned int _id );
        enum AllSoldiers _GetCurrentSoldierName();
        enum LocalPower _GetCityPower();
        void _BuildCity();
        void _UpdateLife ( int _life );
        void _UpdateMagic ( int _magic );
        void _UpdateCoin ( int _coin );

        double life;
        double recover_life;
        double magic;
        double recover_magic;
        unsigned int coin;
        unsigned int recover_coin;
        double lucky;
        unsigned int _id;
        unsigned int occupied_city;

        vector<Soldier> created_soldier;

        Map* _map;
        Point* point_selecter;
        Soldier* soldier_selecter;

        friend class Player;
        friend class Commander;

};

#endif // WAR_H
