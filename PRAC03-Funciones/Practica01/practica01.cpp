#include <iostream>
using namespace std;

// Funciones inline

inline double areaRectangulo(double b, double h) {
    return b*h;
}

inline double areaCirculo(double r) {
    return 3.14*r*r;
}

inline double areaCuadrado(double l) {
    return l*l;
}

int main() {
    int opcion;
    double a, b;

    cout << "Seleccione la figura:\n";
    cout << "1. Cuadrado\n2. Rectangulo\n3. Circulo\n";
    cin >> opcion;

    if (opcion == 1) {
        cout << "Ingrese lado: ";
        cin >> a;
        cout << "Area del cuadrado: " << areaCuadrado(a) << endl;
    } else if (opcion == 2) {
        cout << "Ingrese base y altura: ";
        cin >> a >> b;
        cout << "Area del rectangulo: " << areaRectangulo(a, b) << endl;
    } else if (opcion == 3) {
        cout << "Ingrese radio: ";
        cin >> a;
        cout << "Area del circulo: " << areaCirculo(a) << endl;
    } else {
        cout << "La opcion no es valida\n";
    }

    return 0;
}
