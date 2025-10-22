#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string nombreArchivo;
    
    cout << "Ingrese el nombre del archivo: ";
    cin >> nombreArchivo;
    
    try {
        ifstream archivo(nombreArchivo);
        
        if (!archivo.is_open()) {
            throw runtime_error("Archivo no existe");
        }
        
        cout << "\nContenido del archivo:\n";
        string linea;
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }
        
        archivo.close();
        
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    cout << "Programa continua..." << endl;
    
    return 0;
}
