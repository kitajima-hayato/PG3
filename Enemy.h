#pragma once
class Enemy
{

public:

	// 接近
	void Access();
	// 射撃
	void Fire();
	// 離脱
	void Elimination();
	// アップデート
	void Update();
private:
	// メンバ関数のポインタのテーブル
	static void (Enemy::* BehaviorTable[])();
	int phase_;
};

