#include <iostream>
using namespace std;

class Vector2D {
private:
    double x;
    double y;

public:
    Vector2D(double x_0, double y_0) : x(x_0), y(y_0) {}

    // operador +
    Vector2D operator+(const Vector2D& v) const {
        return Vector2D(x + v.x, y + v.y);
    }

    // operador ==
    bool operator==(const Vector2D& v) const {
        return x == v.x && y == v.y;
    }

    void mostrar() const {
        cout << "(" << x << ", " << y << ")\n";
    }
};

int main() {
    Vector2D v1(3.5, 2.0);
    Vector2D v2(1.5, 4.0);

    cout << "Vector 1: ";
    v1.mostrar();
    cout << "Vector 2: ";
    v2.mostrar();

    Vector2D v3 = v1 + v2;

    cout << "Vector 1 + Vector 2: ";
    v3.mostrar();

    if (v1 == v2)
        cout << "Los vectores son iguales\n";
    else
        cout << "Los vectores son diferentes\n";

    return 0;
}
