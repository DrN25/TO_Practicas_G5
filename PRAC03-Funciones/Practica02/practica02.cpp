#include <iostream>
#include <string>
#include <algorithm> // Para usar std::max en el reto
using namespace std;

// Declaración anticipada de la clase Caja, necesaria para declarar la función friend
class Caja;

class Caja {
private:
    double peso; // Atributo requerido
    string nombre;

public:
    // Constructor por defecto
    Caja() : peso(0.0), nombre("Caja_Vacia") {}

    // Constructor para inicializar peso y nombre
    Caja(double p, string n) : peso(p), nombre(n) {}

    // Declaración de la función 'comparar' como amiga de la clase Caja
    // Esto le permite acceder al miembro privado 'peso'
    friend void comparar(Caja c1, Caja c2, Caja c3);
};

void comparar(Caja c1, Caja c2, Caja c3) {
    cout << "\n--- Resultado de la comparación ---" << endl;

    // Caso 1: Comparar solo dos cajas (cuando c3 es la caja por defecto/vacia)
    if (c3.peso == 0.0 && c3.nombre == "Caja_Vacia") {
        cout << "Comparando solo dos cajas: " << c1.nombre << " y " << c2.nombre << "." << endl;
        if (c1.peso > c2.peso) {
            cout << c1.nombre << " pesa mas con " << c1.peso << " kg." << endl;
        } else if (c2.peso > c1.peso) {
            cout << c2.nombre << " pesa mas con " << c2.peso << " kg." << endl;
        } else {
            cout << c1.nombre << " y " << c2.nombre << " pesan lo mismo (" << c1.peso << " kg)." << endl;
        }
    }
    // Caso 2: Comparar tres cajas (Reto Adicional)
    else {
        cout << "Comparando tres cajas: " << c1.nombre << ", " << c2.nombre << " y " << c3.nombre << "." << endl;

        double max_peso = max({c1.peso, c2.peso, c3.peso});

        if (max_peso == c1.peso) {
            cout << c1.nombre << " es una de las mas pesadas con " << c1.peso << " kg." << endl;
        }
        if (max_peso == c2.peso) {
            cout << c2.nombre << " es una de las mas pesadas con " << c2.peso << " kg." << endl;
        }
        if (max_peso == c3.peso) {
            cout << c3.nombre << " es una de las mas pesadas con " << c3.peso << " kg." << endl;
        }
    }
}
// Declaración de la función friend
void comparar(Caja c1, Caja c2, Caja c3 = Caja()); // Se agrega c3 con un constructor por defecto para el reto

int main() {
    double p1, p2, p3;

    cout << "--- Entrada de Datos de las Cajas ---" << endl;
    cout << "Ingrese el peso de la Caja 1 (kg): ";
    cin >> p1;

    cout << "Ingrese el peso de la Caja 2 (kg): ";
    cin >> p2;

    // Crear objetos Caja
    Caja caja1(p1, "Caja_1");
    Caja caja2(p2, "Caja_2");

    // --- Comparar las dos primeras cajas ---
    comparar(caja1, caja2); // Uso de la función friend

    // --- Reto Adicional: Permitir comparar tres cajas ---
    cout << "\n Reto Adicional: Comparar 3 Cajas" << endl;
    cout << "Ingrese el peso de la Caja 3 (kg): ";
    cin >> p3;

    Caja caja3(p3, "Caja_3");

    // Comparar las tres cajas
    comparar(caja1, caja2, caja3);

    return 0;
}