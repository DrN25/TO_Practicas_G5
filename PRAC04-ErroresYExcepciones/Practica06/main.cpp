#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

int main() {
    std::vector<std::string> lista_elementos = {
        "Lunes",
        "Martes",
        "Miercoles",
        "Jueves",
        "Viernes"
    };

    std::string entrada_texto;
    int indice_usuario;

    std::cout << "Lista creada con " << lista_elementos.size() << " elementos." << std::endl;
    std::cout << "Ingrese un indice (un numero entero): ";
    std::getline(std::cin, entrada_texto);

    try {
        indice_usuario = std::stoi(entrada_texto);
        try {
            std::string elemento = lista_elementos.at(indice_usuario);
            std::cout << "El elemento en el indice " << indice_usuario << " es: " << elemento << std::endl;
        } catch (const std::out_of_range& e) {
            std::cout << "ERROR: El indice ingresado esta fuera del rango (0 a " << lista_elementos.size() - 1 << ")." << std::endl;
        }
    } catch (const std::invalid_argument& e) {
        std::cout << "Debe ingresar un numero valido para el indice." << std::endl;
    }
    return 0;

}
