#include<stdio.h>
template <typename Type>

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


int calc(int a, int b) {
	return a + b;
}
float calc(float d, float e) {
	return d + e + 10;
}

int main(){
	printf("%d\n", min<int>(1, 5));
	printf("%f\n", min<float>(2.2f, 5.5f));
	printf("%lf\n", min<double>(1.2222f, 2.1111f));
	printf("%c\n", min<char>('p','a'));

	return 0;
}