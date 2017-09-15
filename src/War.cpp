#include "War.h"

War::War ( double prestige, double bitcoin, double violence, int second, unsigned short war_num, Map*& _map )
{
    this->occupied_city = 1;
    this->lucky = ( ( sqrt ( ( 10 - war_num ) * 0.03 ) + prestige * 0.05 + violence + 0.05 + second * 0.08 ) / ( prestige + bitcoin + violence + second ) ) ;
    this->life = ( prestige / 2 ) * 300 + ( this->lucky / 3 ) * 100;
    this->recover_life = 30;
    this->magic = ( violence / 2 ) * 150 + ( this->lucky / 8 ) * 100;
    this->recover_magic = 10;
    this->coin = ( bitcoin / 3 ) * 100 + ( this->lucky / 13 ) * 100;
    this->recover_coin = 25;
    this->point_selecter = 0;
    this->soldier_selecter = 0;
    this->_id = 0;
    this->_map = _map;
}

War::~War()
{
}



void War::_ShowStatus()
{
    cout << endl << endl << "[*]当前状态:" << endl;
    cout << "[*]生命源: " << this->life << endl;
    cout << "[*]魔法源: " << this->magic << endl;
    cout << "[*]金钱: " << this->coin << endl;
    cout << "[*]幸运值: " << this->lucky * 100 << "%" << endl;
}

void War::_ShowMap ( bool show_detail )
{
    this->_map->ShowMap ( show_detail );
}

bool War::_SelectPoint ( unsigned int _x, unsigned int _y )
{
    if ( _x > this->_map->rwidth || _y > this->_map->rheight )
        return false;
    this->point_selecter = this->_map->GetPoint ( _x, _y );
    return true;
}

void War::_ShowPointStatus()
{
    cout << endl << "[*]当前地点(" << this->point_selecter->GetX() << " ," << this->point_selecter->GetY() << ")状态：" << endl;
    cout << "归属势力: " << this->point_selecter->SGetPower() << endl;
    cout << "生命值: " << this->point_selecter->GetLife() << endl;
    cout << "攻击力: " << this->point_selecter->GetAttack() << endl;
    cout << "防御力: " << this->point_selecter->GetDefense() << endl;
    cout << "士兵总数: " << this->point_selecter->GetNumber() << endl;
}

bool War::_SelectSoldier ( unsigned int id )
{
    if ( id >= this->_id ) return false;
    this->soldier_selecter = &this->created_soldier[id];
    return true;
}

void War::_ShowSoldierStatus ( unsigned int id )
{
    cout << endl << "战士ID: " << this->created_soldier[id].GetID() << endl;
    cout << "种族: " << this->created_soldier[id].SGetSpecies() << endl;
    cout << "兵种: " << this->created_soldier[id].SGetName() << endl;
    cout << "生命值: " << this->created_soldier[id].GetLife() << endl;
    cout << "攻击力: " << this->created_soldier[id].GetAttack() << endl;
    cout << "防御力: " << this->created_soldier[id].GetDefence() << endl;
    cout << "位置: " << this->created_soldier[id].GetX() << ", " << this->created_soldier[id].GetY() << endl;
}

void War::_ShowSoldierStatus()
{
    cout << endl << "战士ID: " << this->soldier_selecter->GetID() << endl;
    cout << "种族: " << this->soldier_selecter->SGetSpecies() << endl;
    cout << "兵种: " << this->soldier_selecter->SGetName() << endl;
    cout << "生命值: " << this->soldier_selecter->GetLife() << endl;
    cout << "攻击力: " << this->soldier_selecter->GetAttack() << endl;
    cout << "防御力: " << this->soldier_selecter->GetDefence() << endl;
    cout << "位置: " << this->soldier_selecter->GetX() << ", " << this->soldier_selecter->GetY() << endl;
}

void War::_UpdateLife ( int _life )
{
    this->life += _life;
}

void War::_UpdateMagic ( int _magic )
{
    this->magic += _magic;
}

void War::_UpdateCoin ( int _coin )
{
    this->coin += _coin;
}


bool War::_CreateSoldier ( enum AllSoldiers soldier, enum LocalPower power, unsigned int x, unsigned int y, double* _life, double* _magic, unsigned int* _coin )
{
    bool _result = false;
    switch ( soldier )
    {
        case _Worker:
        {
            if ( *_life >= WORKER_COST_LIFE && *_magic >= WORKER_COST_MAGIC && *_coin >= WORKER_COST_COIN )
            {
                this->created_soldier.push_back ( Worker (
                                                      this->_id,
                                                      x,
                                                      y,
                                                      power,
                                                      WORKER_COST_LIFE,
                                                      WORKER_COST_MAGIC,
                                                      WORKER_COST_COIN ) );
                *_life -= WORKER_COST_LIFE;
                *_magic -= WORKER_COST_MAGIC;
                *_coin -= WORKER_COST_COIN;
                _result = true;
            }
            break;
        }
        case _Archer:
        {
            if ( *_life >= ARCHER_COST_LIFE && *_magic >= ARCHER_COST_MAGIC && *_coin >= ARCHER_COST_COIN )
            {
                this->created_soldier.push_back ( Archer (
                                                      this->_id,
                                                      x,
                                                      y,
                                                      power,
                                                      ARCHER_COST_LIFE,
                                                      ARCHER_COST_MAGIC,
                                                      ARCHER_COST_COIN ) );
                *_life -= ARCHER_COST_LIFE;
                *_magic -= ARCHER_COST_MAGIC;
                *_coin -= ARCHER_COST_COIN;
                _result = true;
            }
            break;
        }
        case _SwordsMan:
        {
            if ( *_life >= SWORDSMAN_COST_LIFE && *_magic >= SWORDSMAN_COST_MAGIC && *_coin >= SWORDSMAN_COST_COIN )
            {
                this->created_soldier.push_back ( SwordsMan (
                                                      this->_id,
                                                      x,
                                                      y,
                                                      power,
                                                      SWORDSMAN_COST_LIFE,
                                                      SWORDSMAN_COST_MAGIC,
                                                      SWORDSMAN_COST_COIN ) );
                *_life -= SWORDSMAN_COST_LIFE;
                *_magic -= SWORDSMAN_COST_MAGIC;
                *_coin -= SWORDSMAN_COST_COIN;
                _result = true;
            }
            break;
        }
        case _Priest:
        {
            if ( *_life >= PRIEST_COST_LIFE && *_magic >= PRIEST_COST_MAGIC && *_coin >= PRIEST_COST_COIN )
            {
                this->created_soldier.push_back ( Priest (
                                                      this->_id,
                                                      x,
                                                      y,
                                                      power,
                                                      PRIEST_COST_LIFE,
                                                      PRIEST_COST_MAGIC,
                                                      PRIEST_COST_COIN ) );
                *_life -= PRIEST_COST_LIFE;
                *_magic -= PRIEST_COST_MAGIC;
                *_coin -= PRIEST_COST_COIN;
                _result = true;
                break;
            }
        }
        case _SiegCar:
        {
            if ( *_life >= SIEGCAR_COST_LIFE && *_magic >= SIEGCAR_COST_MAGIC && *_coin >= SIEGCAR_COST_COIN )
            {
                this->created_soldier.push_back ( SiegCar (
                                                      this->_id,
                                                      x,
                                                      y,
                                                      power,
                                                      SIEGCAR_COST_LIFE,
                                                      SIEGCAR_COST_MAGIC,
                                                      SIEGCAR_COST_COIN ) );
                *_life -= SIEGCAR_COST_LIFE;
                *_magic -= SIEGCAR_COST_MAGIC;
                *_coin -= SIEGCAR_COST_COIN;
                _result = true;
            }
            break;
        }
        case _Dragon:
        {
            if ( *_life >= DRAGON_COST_LIFE && *_magic >= DRAGON_COST_MAGIC && *_coin >= DRAGON_COST_COIN )
            {
                this->created_soldier.push_back ( Dragon (
                                                      this->_id,
                                                      x,
                                                      y,
                                                      power,
                                                      DRAGON_COST_LIFE,
                                                      DRAGON_COST_MAGIC,
                                                      DRAGON_COST_COIN ) );
                *_life -= DRAGON_COST_LIFE;
                *_magic -= DRAGON_COST_MAGIC;
                *_coin -= DRAGON_COST_COIN;
                _result = true;
            }
            break;
        }
        case _Wolf:
        {
            if ( *_life >= WOLF_COST_LIFE && *_magic >= WOLF_COST_MAGIC && *_coin >= WOLF_COST_COIN )
            {
                this->created_soldier.push_back ( Wolf (
                                                      this->_id,
                                                      x,
                                                      y,
                                                      power,
                                                      WOLF_COST_LIFE,
                                                      WOLF_COST_MAGIC,
                                                      WOLF_COST_COIN ) );
                *_life -= WOLF_COST_LIFE;
                *_magic -= WOLF_COST_MAGIC;
                *_coin -= WOLF_COST_COIN;
                _result = true;
            }
            break;
        }
        case _Slime:
        {
            if ( *_life >= SLIME_COST_LIFE && *_magic >= SLIME_COST_MAGIC && *_coin >= SLIME_COST_COIN )
            {
                this->created_soldier.push_back ( Slime (
                                                      this->_id,
                                                      x,
                                                      y,
                                                      power,
                                                      SLIME_COST_LIFE,
                                                      SLIME_COST_MAGIC,
                                                      SLIME_COST_COIN ) );
                *_life -= SLIME_COST_LIFE;
                *_magic -= SLIME_COST_MAGIC;
                *_coin -= SLIME_COST_COIN;
                _result = true;
                break;
            }
        }
        case _Goblin:
        {
            if ( *_life >= GOBLIN_COST_LIFE && *_magic >= GOBLIN_COST_MAGIC && *_coin >= GOBLIN_COST_COIN )
            {
                this->created_soldier.push_back ( Goblin (
                                                      this->_id,
                                                      x,
                                                      y,
                                                      power,
                                                      GOBLIN_COST_LIFE,
                                                      GOBLIN_COST_MAGIC,
                                                      GOBLIN_COST_COIN ) );
                *_life -= GOBLIN_COST_LIFE;
                *_magic -= GOBLIN_COST_MAGIC;
                *_coin -= GOBLIN_COST_COIN;
                _result = true;
                break;
            }
            case _IceGiant:
            {
                if ( *_life >= ICEGIANT_COST_LIFE && *_magic >= ICEGIANT_COST_MAGIC && *_coin >= ICEGIANT_COST_COIN )
                {
                    this->created_soldier.push_back ( IceGiant (
                                                          this->_id,
                                                          x,
                                                          y,
                                                          power,
                                                          ICEGIANT_COST_LIFE,
                                                          ICEGIANT_COST_MAGIC,
                                                          ICEGIANT_COST_COIN ) );
                    *_life -= ICEGIANT_COST_LIFE;
                    *_magic -= ICEGIANT_COST_MAGIC;
                    *_coin -= ICEGIANT_COST_COIN;
                    _result = true;
                }
                break;
            }
            case _FlameBirds:
            {
                if ( *_life >= FLAMEBIRDS_COST_LIFE && *_magic >= FLAMEBIRDS_COST_MAGIC && *_coin >= FLAMEBIRDS_COST_COIN )
                {
                    this->created_soldier.push_back ( FlameBirds (
                                                          this->_id,
                                                          x,
                                                          y,
                                                          power,
                                                          FLAMEBIRDS_COST_LIFE,
                                                          FLAMEBIRDS_COST_MAGIC,
                                                          FLAMEBIRDS_COST_COIN ) );
                    *_life -= FLAMEBIRDS_COST_LIFE;
                    *_magic -= FLAMEBIRDS_COST_MAGIC;
                    *_coin -= FLAMEBIRDS_COST_COIN;
                    _result = true;
                }
                break;
            }
            case _Naga:
            {
                if ( *_life >= NAGA_COST_LIFE && *_magic >= NAGA_COST_MAGIC && *_coin >= NAGA_COST_COIN )
                {
                    this->created_soldier.push_back ( Naga (
                                                          this->_id,
                                                          x,
                                                          y,
                                                          power,
                                                          NAGA_COST_LIFE,
                                                          NAGA_COST_MAGIC,
                                                          NAGA_COST_COIN ) );
                    *_life -= NAGA_COST_LIFE;
                    *_magic -= NAGA_COST_MAGIC;
                    *_coin -= NAGA_COST_COIN;
                    _result = true;
                }
                break;
            }
            case _Phoenix:
            {
                if ( *_life >= PHOENIX_COST_LIFE && *_magic >= PHOENIX_COST_MAGIC && *_coin >= PHOENIX_COST_COIN )
                {
                    this->created_soldier.push_back ( Phoenix (
                                                          this->_id,
                                                          x,
                                                          y,
                                                          power,
                                                          PHOENIX_COST_LIFE,
                                                          PHOENIX_COST_MAGIC,
                                                          PHOENIX_COST_COIN ) );
                    *_life -= PHOENIX_COST_LIFE;
                    *_magic -= PHOENIX_COST_MAGIC;
                    *_coin -= PHOENIX_COST_COIN;
                    _result = true;
                }
                break;
            }
        }
    }
    if ( _result )
    {
        if ( power == player_city )
            this->_AddSoldierToMap ( '*', x, y, this->created_soldier[this->created_soldier.size() - 1] );
        else
            this->_AddSoldierToMap ( 'X', x, y, this->created_soldier[this->created_soldier.size() - 1] );
    }
    return _result;
}


void War::_AddSoldierToMap ( const char& _c, unsigned int _x, unsigned int _y, Soldier& _soldier )
{
    this->_map->DrawToMap ( _c, _x, _y, false );
    this->_map->AddSoldierToPoint ( _x, _y, _soldier );
}

void War::_DeleteSoldier ( unsigned int _id )
{
    this->created_soldier.erase ( vector<Soldier>::iterator ( this->created_soldier.begin() + _id ) );
    cout << endl << "[*]ID为: " << _id << "的战士死亡，原ID为: " << _id + 1 << "的战士取代该ID" << endl;
    for ( vector<int>::size_type i = _id; i != this->created_soldier.size(); i++ )
    {
        this->created_soldier[i].UpdateID ( created_soldier[i].GetID() - 1 );
    }
    this->_id--;
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
    return ( ( this->_map->player_base_x - 1 ) / 3 );
}
unsigned int War::_GetPlayerBaseY()
{
    return ( ( this->_map->player_base_y - 1 ) / 2 );
}
unsigned int War::_GetAIBaseX()
{
    return ( ( this->_map->ai_base_x - 1 ) / 3 );
}
unsigned int War::_GetAIBaseY()
{
    return ( ( this->_map->ai_base_y - 1 ) / 2 );
}
enum AllSoldiers War::_GetCurrentSoldierName()
{
    return this->soldier_selecter->GetSoldierName();
}

Soldier* War::_GetSoldierFromPoint ( unsigned int _x, unsigned int _y, unsigned int _id )
{
    return this->_map->points[_x][_y]._GetSoldier ( _id );
}

double War::_GetLife()
{
    return this->life;
}

double War::_GetMagic()
{
    return this->magic;
}

unsigned int War::_GetCoin()
{
    return this->coin;
}

double War::_GetLucky()
{
    return this->lucky;
}


enum LocalPower War::_GetCityPower()
{
    return this->_map->points[this->soldier_selecter->GetX()][this->soldier_selecter->GetY()].GetPower();
}
void War::_BuildCity()
{
    if ( this->_map->points[this->soldier_selecter->GetX()][this->soldier_selecter->GetY()].GetPower() == empty_city )
    {
        this->_map->points[this->soldier_selecter->GetX()][this->soldier_selecter->GetY()].UpdatePower ( this->soldier_selecter->GetPower() );
        if ( this->soldier_selecter->GetPower() == player_city )
            this->_map->DrawToMap ( '*', this->soldier_selecter->GetX(), this->soldier_selecter->GetY(), true );
        else
            this->_map->DrawToMap ( 'X', this->soldier_selecter->GetX(), this->soldier_selecter->GetY(), true );
        this->occupied_city++;
    }
}
