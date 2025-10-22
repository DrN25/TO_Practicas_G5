#include <iostream>
#include <string>
#include <stdexcept>

int main() {
    std::string entrada_texto;
    int numero;

    std::cout << "Ingrese un numero: ";
    std::getline(std::cin, entrada_texto);

    try {
        numero = std::stoi(entrada_texto);
        std::cout << "El numero ingresado es: " << numero << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Debe ingresar un numero valido" << std::endl;
    }
    return 0;
}
