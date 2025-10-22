#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
    try {
        double a, b;
        cout << "Ingrese dos numeros (numerador denominador): ";
        if (!(cin >> a >> b)) {
            throw invalid_argument("Se esperaba un numero");
        }
        if (b == 0.0) {
            throw domain_error("No se puede dividir entre cero");
        }
        cout << "Resultado: " << (a / b) << std::endl;
    } catch (const invalid_argument &e) {
        cerr << "Error de tipo: " << e.what() << std::endl;
        return 1;
    } catch (const domain_error &e) {
        cerr << "Error aritmetico: " << e.what() << std::endl;
        return 2;
    }
    
    return 0;
}

/*
Output esperado:
Ingrese dos numeros (numerador denominador): 1 2
Resultado: 0.5


Ingrese dos numeros (numerador denominador): 1 a
Error de tipo: Se esperaba un numero


Ingrese dos numeros (numerador denominador): 1 0
Error aritmetico: No se puede dividir entre cero
*/