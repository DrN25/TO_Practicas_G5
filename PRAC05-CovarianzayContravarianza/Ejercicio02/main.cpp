// main.cpp
#include "Vehiculo.h"
#include <iostream>

// Función de prueba para clonar polimórficamente
void probarClon(Vehiculo* v) {
    // Clonación polimórfica: la llamada a clonar() es virtual
    // El tipo de retorno es Vehiculo*, pero el objeto real es el tipo derivado
    Vehiculo* clon = v->clonar();
    std::cout << "Clonando un " << v->getTipo() << "...\n";
    std::cout << "  Objeto clonado: " << clon->getTipo() << "\n";
    clon->arrancar();
    delete clon; // Liberar memoria del objeto clonado
}

int main() {
    // Creamos los objetos concretos
    Auto mi_auto;
    Moto mi_moto;

    // Punteros de la clase base para demostrar el polimorfismo
    Vehiculo* ptr_auto = &mi_auto;
    Vehiculo* ptr_moto = &mi_moto;

    std::cout << "--- Prueba de Clonacion Polimorfica ---\n";
    probarClon(ptr_auto);
    std::cout << "\n";
    probarClon(ptr_moto);
    std::cout << "\n";

    std::cout << "--- Prueba de Retorno Covariante Directo ---\n";
    // Llamada directa sin polimorfismo, el compilador usa el tipo de retorno covariante
    Auto* clon_auto = mi_auto.clonar(); // Recibimos directamente un Auto*
    std::cout << "Auto clonado (directo): " << clon_auto->getTipo() << "\n";
    delete clon_auto;

    Moto* clon_moto = mi_moto.clonar(); // Recibimos directamente un Moto*
    std::cout << "Moto clonada (directo): " << clon_moto->getTipo() << "\n";
    delete clon_moto;

    return 0;
}