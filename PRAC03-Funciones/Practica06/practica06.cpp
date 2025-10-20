#include <iostream>
#include <iomanip> // Necesario para setw y setfill

using namespace std;

// Clase que representa una Fecha
class Fecha {
private:
    int dia;
    int mes;
    int anio;

    // Función auxiliar para validar la lógica del día/mes (Reto Adicional)
    bool validarFecha(int d, int m) {
        if (m < 1 || m > 12) return false;
        if (d < 1 || d > 31) return false;
        // Meses de 30 días
        if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) return false;
        // Febrero (simplificado sin contar bisiestos)
        if (m == 2 && d > 29) return false;
        return true;
    }

public:
    // Constructor con validación
    Fecha(int d, int m, int a) {
        if (validarFecha(d, m)) {
            dia = d;
            mes = m;
        } else {
            // Si la fecha es inválida, se usa una fecha por defecto y se avisa.
            dia = 1;
            mes = 1;
            cout << "[AVISO: Fecha " << d << "/" << m << "/" << a << " no es valida. Usando 01/01/" << a << "]" << endl;
        }
        anio = a;
    }

    // Sobrecarga del operador << (ostream) como una función friend.
    // Esto permite que la función acceda a los miembros privados y funcione con cout.
    friend ostream& operator<<(ostream& os, const Fecha& f);
};

// Implementación de la sobrecarga del operador <<
ostream& operator<<(ostream& os, const Fecha& f) {
    // Usamos 'setw(2)' para asegurar un ancho de 2 caracteres
    // y 'setfill('0')' para rellenar con un cero a la izquierda si es necesario 
    os << setfill('0') << setw(2) << f.dia << "/"
       << setfill('0') << setw(2) << f.mes << "/"
       << f.anio;
    return os; // Devuelve la referencia al ostream para encadenar salidas
}

int main() {
    cout << " Practica 6: Sobrecarga de Operador << " << endl;

    Fecha f1(5, 7, 2025);
    Fecha f2(30, 11, 2024);

    // 2. Creación de objetos con datos no válidos para probar la validación
    Fecha f3(32, 10, 2023); // Día inválido
    Fecha f4(31, 4, 2026);  // Mes 4 (Abril) solo tiene 30 días

    cout << "\n Resultados de Salida " << endl;
    cout << "Fecha 1 (Correcta): " << f1 << endl;
    cout << "Fecha 2 (Correcta): " << f2 << endl;
    cout << "Fecha 3 (Dia Invalido): " << f3 << endl;
    cout << "Fecha 4 (Logica Invalida): " << f4 << endl;

    return 0;
}   