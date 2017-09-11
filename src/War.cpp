#include "War.h"

War::War ( double prestige, double bitcoin, double violence, int second, unsigned short war_num, Map*& _map )
{
    this->life =  prestige * 30 ;
    this->magic = violence * 20 ;
    this->coin = bitcoin * 10 ;
    this->lucky = sqrt((10-war_num)*0.03) + prestige * 0.05 + violence + 0.05 ;
    this->poing_selecter = 0;
    this->soldier_selecter = 0;
    this->_id = 0;
    this->_map = _map;

}

War::~War()
{
}

void War::_Show_Status()
{
    cout << endl << endl << "[*]��ǰ״̬:" << endl;
    cout << endl << "[*]����Դ: " << this->life << endl;
    cout << endl << "[*]ħ��Դ: " << this->magic << endl;
    cout << endl << "[*]��Ǯ: " << this->coin << endl;
    cout << endl << "[*]����ֵ: " << this->lucky << endl;
}

void War::_Show_Map ( bool show_detail )
{
    this->_map->Show_Map ( show_detail );
}

bool War::_Select_Point ( unsigned int _x, unsigned int _y )
{
    if ( _x > this->_map->rwidth || _y > this->_map->rheight )
        return false;
    this->poing_selecter = this->_map->Get_Point ( _x, _y );
    return true;
}

void War::_Show_Point_Status()
{
    cout << endl << "[*]��ǰ�ص�(" << this->poing_selecter->GetX() << this->poing_selecter->GetY() << ")״̬��" << endl;
    cout << "��������: " << this->poing_selecter->SGetPower() << endl;
    cout << "����ֵ: " << this->poing_selecter->GetLife() << endl;
    cout << "������: " << this->poing_selecter->GetAttack() << endl;
    cout << "������: " << this->poing_selecter->GetDefense() << endl;
    cout << "ʿ������: " << this->poing_selecter->GetNumber() << endl;
}

bool War::_Select_Soldier ( unsigned int id )
{
    if ( id >= this->_id ) return false;
    this->soldier_selecter = &this->created_soldier[id];
    return true;
}

void War::_Show_Soldier_Status ( unsigned int id )
{
    cout << endl << "սʿID: " << this->created_soldier[id].GetID() << endl;
    cout << "����: " << this->created_soldier[id].SGetSpecies() << endl;
    cout << "����: " << this->created_soldier[id].SGetName() << endl;
    cout << "����ֵ: " << this->created_soldier[id].GetLife() << endl;
    cout << "������: " << this->created_soldier[id].GetAttack() << endl;
    cout << "������: " << this->created_soldier[id].GetDefence() << endl;
    cout << "λ��: " << this->created_soldier[id].GetX() << ", " << this->created_soldier[id].GetY() << endl;
}

void War::_Show_Soldier_Status()
{
    cout << endl << "սʿID: " << this->soldier_selecter->GetID() << endl;
    cout << "����: " << this->soldier_selecter->SGetSpecies() << endl;
    cout << "����: " << this->soldier_selecter->SGetName() << endl;
    cout << "����ֵ: " << this->soldier_selecter->GetLife() << endl;
    cout << "������: " << this->soldier_selecter->GetAttack() << endl;
    cout << "������: " << this->soldier_selecter->GetDefence() << endl;
    cout << "λ��: " << this->soldier_selecter->GetX() << ", " << this->soldier_selecter->GetY() << endl;
}


void War::_Create_Soldier ( enum AllSoldiers soldier, unsigned int x, unsigned int y )
{
    switch ( soldier )
    {
        case _Worker:
        {
            this->created_soldier.push_back ( Worker ( this->_id, x, y ) );
            break;
        }
        case _Archer:
        {
            this->created_soldier.push_back ( Archer ( this->_id, x, y ) );
            break;
        }
        case _SwordsMan:
        {
            this->created_soldier.push_back ( SwordsMan ( this->_id, x, y ) );
            break;
        }
        case _Priest:
        {
            this->created_soldier.push_back ( Priest ( this->_id, x, y ) );
            break;
        }
        case _SiegCar:
        {
            this->created_soldier.push_back ( SiegCar ( this->_id, x, y ) );
            break;
        }
        case _Dragon:
        {
            this->created_soldier.push_back ( Dragon ( this->_id, x, y ) );
            break;
        }
        case _Wolf:
        {
            this->created_soldier.push_back ( Wolf ( this->_id, x, y ) );
            break;
        }
        case _Slime:
        {
            this->created_soldier.push_back ( Slime ( this->_id, x, y  ) );
            break;
        }
        case _Goblin:
        {
            this->created_soldier.push_back ( Goblin ( this->_id, x, y ) );
            break;
        }
        case _IceGiant:
        {
            this->created_soldier.push_back ( IceGiant ( this->_id, x, y ) );
            break;
        }
        case _FlameBirds:
        {
            this->created_soldier.push_back ( FlameBirds ( this->_id, x, y ) );
            break;
        }
        case _Naga:
        {
            this->created_soldier.push_back ( Naga ( this->_id, x, y ) );
            break;
        }
        case _Phoenix:
        {
            this->created_soldier.push_back ( Phoenix ( this->_id, x, y ) );
            break;
        }
    }
    cout << endl << "[*]�����ɹ�" << endl;
    this->_AddSoldierToMap ( '*', x, y, this->created_soldier[this->created_soldier.size() - 1] );
    this->_Show_Soldier_Status ( this->_id++ );
}

void War::_AddSoldierToMap ( const char& _c, unsigned int _x, unsigned int _y, Soldier& _soldier )
{
    this->_map->AddSoldierToMap ( _c, _x, _y );
    this->_map->AddSoldierToPoint ( _x, _y, _soldier );
}


void War::_Delete_Soldier ( unsigned int _id )
{
    this->created_soldier.erase ( vector<Soldier>::iterator ( this->created_soldier.begin() + _id ) );
    cout << endl << "[*]IDΪ: " << _id << "��սʿ������ԭIDΪ: " << _id + 1 << "��սʿȡ����ID" << endl;
    for ( vector<int>::size_type i = _id; i != this->created_soldier.size(); i++ )
    {
        this->created_soldier[i].UpdateID ( created_soldier[i].GetID() - 1 );
    }
}

bool War::_IsSelectSoldier()
{
    if ( this->soldier_selecter != 0 )
        return true;
    else
        return false;
}

unsigned int War::_GetPlayerBaseX()
{
    return this->_map->player_base_x;
}

unsigned int War::_GetPlayerBaseY()
{
    return this->_map->player_base_y;
}

unsigned int War::_GetAIBaseX()
{
    return this->_map->ai_base_x;
}

unsigned int War::_GetAIBaseY()
{
    return this->_map->ai_base_y;
}
