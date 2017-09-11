#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

#define AI_PRESTIGE_1 100.0
#define AI_PRESTIGE_2 200.0
#define AI_PRESTIGE_3 300.0
#define AI_PRESTIGE_4 400.0
#define AI_PRESTIGE_5 500.0

#define AI_BITCOIN_1 100.0
#define AI_BITCOIN_2 200.0
#define AI_BITCOIN_3 300.0
#define AI_BITCOIN_4 400.0
#define AI_BITCOIN_5 500.0

#define AI_VIOLENCE_1 100.0
#define AI_VIOLENCE_2 200.0
#define AI_VIOLENCE_3 300.0
#define AI_VIOLENCE_4 400.0
#define AI_VIOLENCE_5 500.0

#define AI_SECOND_1 10
#define AI_SECOND_2 20
#define AI_SECOND_3 30
#define AI_SECOND_4 40
#define AI_SECOND_5 50

#define WORKER_COST_LIFE 30
#define WORKER_COST_MAGIC 0
#define WORKER_COST_COIN 20

#define ARCHER_COST_LIFE 50
#define ARCHER_COST_MAGIC 0
#define ARCHER_COST_COIN 70

#define SWORDSMAN_COST_LIFE 100
#define SWORDSMAN_COST_MAGIC 0
#define SWORDSMAN_COST_COIN 150

#define PRIEST_COST_LIFE 70
#define PRIEST_COST_MAGIC 0
#define PRIEST_COST_COIN 200

#define SIEGCAR_COST_LIFE 200
#define SIEGCAR_COST_MAGIC 0
#define SIEGCAR_COST_COIN 350

#define DRAGON_COST_LIFE 370
#define DRAGON_COST_MAGIC 260
#define DRAGON_COST_COIN 540

#define WOLF_COST_LIFE 130
#define WOLF_COST_MAGIC 0
#define WOLF_COST_COIN 90

#define SLIME_COST_LIFE 190
#define SLIME_COST_MAGIC 50
#define SLIME_COST_COIN 120

#define GOBLIN_COST_LIFE 210
#define GOBLIN_COST_MAGIC 70
#define GOBLIN_COST_COIN 40

#define ICEGIANT_COST_LIFE 410
#define ICEGIANT_COST_MAGIC 280
#define ICEGIANT_COST_COIN 460

#define FLAMEBIRDS_COST_LIFE 420
#define FLAMEBIRDS_COST_MAGIC 280
#define FLAMEBIRDS_COST_COIN 340

#define NAGA_COST_LIFE 320
#define NAGA_COST_MAGIC 250
#define NAGA_COST_COIN 210

#define PHOENIX_COST_LIFE 720
#define PHOENIX_COST_MAGIC 500
#define PHOENIX_COST_COIN 640

#include <ctime>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <conio.h>
#include <cstdio>
#include <windows.h>
#include <sstream>
#include <math.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

enum STATUS {_main = 0, practice, war, quit, start_war, win, lose};
enum IDENTITY {_player_, _ai_};
enum Species {humanity, mechanical, beast, wizard, warcraft};
enum AllSoldiers {_Worker, _Archer, _SwordsMan, _Priest, _SiegCar, _Dragon, _Wolf, _Slime, _Goblin, _IceGiant, _FlameBirds, _Naga, _Phoenix};
enum LocalPower {_empty, _player, _ai, player_city, ai_city, empty_city};

#endif // GLOBAL_H_INCLUDED
