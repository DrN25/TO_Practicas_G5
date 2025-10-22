#include <iostream>
using namespace std;

int main() {
    double num1, num2, resultado;

    cout << "Ingrese el numerador: ";
    cin >> num1;
    cout << "Ingrese el denominador: ";
    cin >> num2;

    try {
        if (num2 == 0) {
            throw runtime_error("Error: No se puede dividir entre cero.");
        }
        resultado = num1 / num2;
        cout << "Resultado: " << resultado << endl;
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
    finally: {
        cout << "Operacion finalizada." << endl;
    }

    return 0;
}
