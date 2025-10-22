#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <stdexcept>
#include <limits>

using namespace std;

// Excepción Personalizada
class AlumnoNoEncontradoException : public std::exception {
private:
    string mensaje;
public:
    AlumnoNoEncontradoException(int id) {
        mensaje = "Error de sistema: El alumno con ID " + to_string(id) + " no esta registrado.";
    }
    const char* what() const noexcept override {
        return mensaje.c_str();
    }
};

class SistemaAlumnos {
private:
    map<int, string> alumnos; 
    const string archivo_datos = "alumnos.txt";

    void cargar_alumnos() {
        cout << "\nCargando datos..." << endl;
        ifstream archivo(archivo_datos);

        // Manejo de Archivo No Encontrado
        if (archivo.fail()) {
            cout << "ℹArchivo '" << archivo_datos << "' no encontrado. Iniciando con lista vacia." << endl;
            return;
        }

        try {
            int id;
            string nombre;
            while (archivo >> id >> ws && getline(archivo, nombre)) {
                if (id <= 0) throw runtime_error("Datos corruptos: ID invalido."); 
                alumnos[id] = nombre;
            }
            cout << "Datos cargados correctamente." << endl;
        } catch (const runtime_error& e) {
             // Manejo de Archivo Corrupto
             cout << "Error: " << e.what() << " Reinicie el sistema." << endl;
             alumnos.clear(); 
        }
        archivo.close();
    }

    void guardar_alumnos() {
        ofstream archivo(archivo_datos);
        if (archivo.is_open()) {
            for (const auto& par : alumnos) {
                archivo << par.first << " " << par.second << endl;
            }
            cout << "Datos guardados en " << archivo_datos << "." << endl;
        } else {
            cout << "Error al intentar guardar los datos." << endl;
        }
    }

public:
    SistemaAlumnos() { cargar_alumnos(); }
    ~SistemaAlumnos() { guardar_alumnos(); }

    void agregar_alumno() {
        cout << "\n--- Agregar Alumno ---" << endl;
        int id_alumno;
        string nombre;

        cout << "Ingrese ID del alumno (numero entero): ";
        if (!(cin >> id_alumno)) {
            // Manejo de Error de Entrada
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error de entrada: El ID debe ser un numero entero valido." << endl;
            return;
        }
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        
        if (alumnos.count(id_alumno)) {
             cout << "El alumno con ID " << id_alumno << " ya existe." << endl;
             return;
        }

        cout << "Ingrese nombre del alumno: ";
        getline(cin, nombre);
        
        alumnos[id_alumno] = nombre;
        cout << "Alumno '" << nombre << "' (ID: " << id_alumno << ") agregado." << endl;
    }

    void buscar_alumno() {
        cout << "\n--- Buscar Alumno ---" << endl;
        int id_busqueda;

        cout << "Ingrese ID del alumno a buscar (numero entero): ";
        if (!(cin >> id_busqueda)) {
            // Manejo de Error de Entrada
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error de entrada: El ID de búsqueda debe ser un numero entero." << endl;
            return;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        try {
            if (alumnos.count(id_busqueda)) {
                string nombre = alumnos.at(id_busqueda);
                cout << "Encontrado: ID " << id_busqueda << ", Nombre: " << nombre << endl;
            } else {
                throw AlumnoNoEncontradoException(id_busqueda); 
            }
        
        } catch (const AlumnoNoEncontradoException& e) {
            cout << e.what() << endl;
        }
    }

    // SOLUCIÓN 1: IMPLEMENTACIÓN COMPLETA DE mostrar_alumnos()
    void mostrar_alumnos() {
        cout << "\n--- Lista de Alumnos ---" << endl;
        if (alumnos.empty()) {
            cout << "La lista esta vacia." << endl;
        } else {
            for (const auto& par : alumnos) {
                cout << "ID: " << par.first << ", Nombre: " << par.second << endl;
            }
        }
    }

    void ejecutar() {
        string opcion;
        while (true) {
            cout << "\n SISTEMA DE REGISTRO DE ALUMNOS" << endl;
            cout << "===============================" << endl;
            cout << "1. Agregar Alumno" << endl;
            cout << "2. Buscar Alumno por ID" << endl;
            cout << "3. Mostrar todos los Alumnos" << endl;
            cout << "4. Salir" << endl;
            
            cout << "Seleccione una opcion: ";
            
            // SOLUCIÓN 2: USAR std::cin >> opción_num para una lectura más limpia y robusta del menú
            int opcion_num;
            if (!(cin >> opcion_num)) {
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Opcion no valida. Intente de nuevo." << endl;
                continue; 
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer despues de leer el numero
            
            if (opcion_num == 1) {
                agregar_alumno();
            } else if (opcion_num == 2) {
                buscar_alumno();
            } else if (opcion_num == 3) {
                mostrar_alumnos();
            } else if (opcion_num == 4) {
                cout << "Saliendo del sistema." << endl;
                break;
            } else {
                cout << "Opcion no valida. Intente de nuevo." << endl;
            }
        }
    }
};

int main() {
    SistemaAlumnos sistema;
    sistema.ejecutar();
    return 0;
}