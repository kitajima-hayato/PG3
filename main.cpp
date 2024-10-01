#include<stdio.h>
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
//
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


int main(){
	int hours=8;
	// 各賃金体系での給与を表示
	int regular = regularWage(hours);
	int recursive = recursiveWage(hours);

	printf("一般的な賃金形態 : %d\n", regular);
	printf("再帰的な賃金形態 : %d\n", recursive);
	// 再帰的な賃金体系が得になる時間を計算して表示
	int surpassHours = hoursToSurpassRegularWage();
	return 0;
}