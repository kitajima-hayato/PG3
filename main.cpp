#include <stdio.h>
#include <cstdlib>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <thread>
#include <functional>
#include "Enemy.h"
template <typename Type>
//overload
Type min(Type a, Type b) {
	if (a < b) {
		return static_cast<Type>(a);
	}
	else {
		return static_cast<Type>(b);
	}
};



int main() {
	Enemy* enemy = new Enemy();
	enemy->Update();

	delete enemy;
	return 0;
}