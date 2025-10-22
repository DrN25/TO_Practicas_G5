#include <iostream>
#include <exception>

using namespace std;

// Excepción personalizada
class EdadInvalidaException : public exception {
public:
    const char* what() const noexcept override {
        return "Edad fuera de rango";
    }
};

int main() {
    int edad;
    
    cout << "Ingrese una edad: ";
    cin >> edad;
    
    try {
        if (edad < 1 || edad > 100) {
            throw EdadInvalidaException();
        }
        
        cout << "Edad valida: " << edad << endl;
        
    } catch (const EdadInvalidaException& e) {
        cout << e.what() << endl;
    }
    
    cout << "Programa finalizado" << endl;
    
    return 0;
}
