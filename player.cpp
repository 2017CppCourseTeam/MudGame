#include "player.h"

Player::Player ( )
{
	this->prestige = 50.0;
	this->bitcoin = 10.0;
	this->violence = 50.0;
	this->second = 10;
	srand ( unsigned ( time ( NULL ) ) );
}

void Player::TrainCoder ( )
{
	this->bitcoin -= 0.2;
	if ( rand ( ) / double ( RAND_MAX ) <= 0.8 )
	{
		this->violence += 5;
		this->second += 1;
		cout << "恭喜你，训练成功" << endl;
		return;
	}
	else
	{
		cout << "很遗憾，训练失败" << endl;
		return;
	}
}

void Player::DigMine ( )
{
	if ( ( rand ( ) / double ( RAND_MAX ) ) <= 0.5 )
	{
		this->bitcoin += 10;
		this->second += 1;
		cout << "恭喜你，本次挖出10个比特币！" << endl;
		return;
	}
	else
	{
		this->bitcoin += 0.01;
		this->second += 1;
		cout << "恭喜你，本次挖出0.1个比特币！" << endl;
		return;
	}
}

void Player::WashBrain ( )
{
	cout << "test";
	return;
}

void Player::StartWar ( )
{ }
