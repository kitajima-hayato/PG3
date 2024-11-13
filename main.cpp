#ifndef M_PI
#define M_PI 3.14
#endif

#include <iostream>
#include <cmath>

class IShape {
public:
    virtual void Size() = 0;
    virtual void Draw() = 0;
};

class Circle : public IShape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    void Size() override {
        std::cout << "円の面積: " << M_PI * radius * radius << std::endl;
    }
    void Draw() override {
        std::cout << "半径: " << radius << " の円を描画します。" << std::endl;
    }
};

class Rectangle : public IShape {
private:
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    void Size() override {
        std::cout << "矩形の面積: " << length * width << std::endl;
    }
    void Draw() override {
        std::cout << "長さ: " << length << "、幅: " << width << " の矩形を描画します。" << std::endl;
    }
};

int main() {
    Circle c(5);
    c.Size();
    c.Draw();

    Rectangle r(4, 6);
    r.Size();
    r.Draw();

    return 0;
}
