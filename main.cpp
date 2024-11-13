#include <iostream>
using namespace std;

template <typename T>
class MinClass {
public:
    T Min(T a, T b) {
        return (a < b) ? a : b;
    }
};


// 2つの型引数を持つクラステンプレートの定義
template <typename T1, typename T2>
class MinClass2 {
public:
    // 2つの引数の小さい方の値を返すメンバ関数
    auto Min(T1 a, T2 b) -> decltype((a < b) ? a : b) {
        return (a < b) ? a : b;
    }
};

int main() {
    // int
    MinClass<int> intIntMin;
    cout << "int, intの最小値: " << intIntMin.Min(4, 33) << endl;

    // float
    MinClass<float> floatFloatMin;
    cout << "float, floatの最小値: " << floatFloatMin.Min(3.3f, 33.4f) << endl;

    // double, doubleの組み合わせ
    MinClass<double> doubleDoubleMin;
    cout << "double, doubleの最小値: " << doubleDoubleMin.Min(4.33, 33.4) << endl;

    // int, float
    MinClass2<int, float> intFloatMin;
    cout << "int, floatの最小値: " << intFloatMin.Min(3, 33.4f) << endl;

    // int, double
    MinClass2<int, double> intDoubleMin;
    cout << "int, doubleの最小値: " << intDoubleMin.Min(3, 33.4) << endl;

    // float, double
    MinClass2<float, double> floatDoubleMin;
    cout << "float, doubleの最小値: " << floatDoubleMin.Min(4.4f, 33.4) << endl;

    return 0;
}
