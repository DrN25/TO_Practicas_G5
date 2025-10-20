#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>

using namespace std;

void imprimirVector(const vector<int>& vec, const string& titulo) {
    cout << titulo << ": ";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    std::mt19937 generador(std::random_device{}());
    std::uniform_int_distribution<> distribucion(1, 100);

    std::vector<int> numeros;
    const int tamano = 10;
    for (int i = 0; i < tamano; ++i) {
        numeros.push_back(distribucion(generador));
    }
    imprimirVector(numeros, "Vector inicial");

    auto esPar = [](int n) {
        return n % 2 == 0;
    };

    int cuentaPares = count_if(numeros.begin(), numeros.end(), esPar);

    cout << "1. Contador de numeros pares:" << endl;
    cout << " Resultado: " << cuentaPares << " numeros pares." << endl;
    cout << endl;

    auto sumaTotal = accumulate(numeros.begin(), numeros.end(), 0, [](int acumulador, int elemento) {
            return acumulador + elemento;
        } );

    cout << "2. Calculo de la suma total:" << endl;
    cout << " Resultado: " << sumaTotal << endl;
    cout << endl;

    int valorDado = 10;
    cout << "3. Numeros mayores que " << valorDado << ":" << endl;
    cout << " Resultado: ";

    auto esMayor = [valorDado](int n) {
        if (n > valorDado) {
            cout << n << " ";
        }
    };

    for_each(numeros.begin(), numeros.end(), esMayor);
    cout << endl;
    cout << endl;

    auto comparadorAscendente = [](int a, int b) {
        return a < b;
    };

    sort(numeros.begin(), numeros.end(), comparadorAscendente);

    cout << "Reto Adicional: Vector Ordenado de menor a mayor:" << endl;
    imprimirVector(numeros, " Resultado");
    return 0;
}
