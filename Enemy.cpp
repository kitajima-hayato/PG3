#include "Enemy.h"

#include <iostream>

void Enemy::Access()
{
	std::cout << "Access" << std::endl;
	phase_ = 1;
}

void Enemy::Fire()
{
	std::cout << "Fire!" << std::endl;
	phase_ = 2;
}

void Enemy::Elimination()
{
	std::cout << "Elimination" << std::endl;
}

void Enemy::Update()
{
	// メンバ関数ポインタに入ってる関数を呼び出す
	(this->*BehaviorTable[phase_])();
	Fire();
	Elimination();
}

// メンバ関数のポインタのテーブル
void (Enemy::* Enemy::BehaviorTable[])() = {
	&Enemy::Access,		// 0
	&Enemy::Fire,		// 1
	&Enemy::Elimination	// 2
};