#include<stdio.h>
#include<cstdlib>
#include<cstdlib>
#include<iostream>
#include<ctime>
#include <thread>
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
template<>
char min<char>(char a, char b) {
	return printf("数字以外は代入できません");
}
// 一般的な賃金体系での給与計算（時給1,072円）
int regularWage(int hours) {
	const int hourlyRate = 1072;

	return hourlyRate * hours;
}
// 再帰的な賃金体系での給与計算
int recursiveWage(int hours) {
	int wage = 0;
	int hourlyRate = 0; // 最初の1時間は100円

	for (int i = 1; i <= hours; ++i) {
		if (i == 1) {
			hourlyRate = 100;
		}
		wage += hourlyRate;
		hourlyRate = hourlyRate * 2 - 50; // 次の時間の時給は「前の時給 * 2 - 50円」
	}

	return wage;
}
// 再帰的な賃金体系が得になる時間を計算する関数
int hoursToSurpassRegularWage() {
	int hours = 0;
	while (recursiveWage(hours) <= regularWage(hours)) {
		++hours;
	}
	return hours;
}

typedef bool(*calc)(int);


bool Check(int randomnumber) {
	printf("出目は奇数でしょうか偶数でしょうか\n偶数ならば０、奇数ならば１を入力してください\n");
	int ans;
	std::cin >> ans;
	if (randomnumber % 2 == ans) {
		std::this_thread::sleep_for(std::chrono::seconds(3));
		printf("正解！\n");
		return true;
	}if (randomnumber % 1 == ans) {
		std::this_thread::sleep_for(std::chrono::seconds(3));
		printf("正解！\n");
		return true;
	}
	else {
		std::this_thread::sleep_for(std::chrono::seconds(3));
		printf("不正解\n");
		printf("もう一度！\n");
		return false;
	}
}

void game(calc Check, bool loop) {
	while (!loop) {
		int randomNumber = rand() % 6 + 1;
		bool result = Check(randomNumber);
		if (result) {
			printf("もう一度やりますか?( Yes : 1 / No : 0)\n");
			int RePlay;
			std::cin >> RePlay;
			if (!RePlay) {
				loop = true;
			}
		}
	}
}

int main() {
	srand(time(0));

	bool loop = false;
	calc p;
	p = &Check;

	game(p, loop);


	return 0;
}