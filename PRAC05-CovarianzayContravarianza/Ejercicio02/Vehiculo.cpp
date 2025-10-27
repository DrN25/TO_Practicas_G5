// Vehiculo.cpp
#include "Vehiculo.h"
#include <iostream>

// --- Implementación de Vehiculo ---
Vehiculo* Vehiculo::clonar() const {
    return new Vehiculo(*this);
}

std::string Vehiculo::getTipo() const {
    return "Vehiculo generico";
}

void Vehiculo::arrancar() const {
    std::cout << "El Vehiculo arranca.\n";
}

// --- Implementación de Auto ---
Auto* Auto::clonar() const {
    return new Auto(*this); // Llama al constructor copia de Auto
}

std::string Auto::getTipo() const {
    return "Auto";
}

void Auto::arrancar() const {
    std::cout << "El Auto arranca ruidosamente.\n";
}

// --- Implementación de Moto ---
Moto* Moto::clonar() const {
    return new Moto(*this); // Llama al constructor copia de Moto
}

std::string Moto::getTipo() const {
    return "Moto";
}

void Moto::arrancar() const {
    std::cout << "La Moto arranca con estilo.\n";
}