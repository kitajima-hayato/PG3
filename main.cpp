#include <iostream>
#include <type_traits>

// テンプレート関数: 最小値を返す
template <typename T>
T Min(T a, T b) {
    return (a < b) ? a : b;
}

// char型の特殊化
template <>
char Min<char>(char a, char b) {
    std::cout << "数字以外は代入できません" << std::endl;
    return '\0';
}

int main() {
    // int型
    int a = 5, b = 10;
    std::cout << "Min(" << a << ", " << b << ") = " << Min(a, b) << std::endl;

    // float型
    float c = 3.5f, d = 2.1f;
    std::cout << "Min(" << c << ", " << d << ") = " << Min(c, d) << std::endl;

    // double型
    double e = 7.8, f = 7.8;
    std::cout << "Min(" << e << ", " << f << ") = " << Min(e, f) << std::endl;

    // char型
    char g = 'A', h = 'B';
    Min(g, h);

    return 0;
}
