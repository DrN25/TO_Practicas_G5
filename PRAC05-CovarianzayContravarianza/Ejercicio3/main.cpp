#include <iostream>
#include <stdexcept>
using namespace std;

// definimos la clase de la excepcion personalizada
class ErrorConexion : public runtime_error {
public:
    ErrorConexion(const string& mensaje) : runtime_error(mensaje) {}
};

// creamos una funcion para simular la conexion a una base de datos
void conectarBaseDatos(bool exito) {
    if (!exito) {
        throw ErrorConexion("No se pudo establecer conexion a la base de datos.");
    }
    cout << "Conexion exitosa\n";
}

int main() {
    try {
        // Simulamos un fallo simple
        conectarBaseDatos(false); 
    }
    catch (const ErrorConexion& e) {
        cout << "Excepcion capturada: " << e.what() << endl;
    }

    cout << "Programa finalizado.\n";
    return 0;
}
