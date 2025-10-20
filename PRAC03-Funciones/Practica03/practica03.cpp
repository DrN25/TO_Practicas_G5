#include <iostream>
#include <string>

using namespace std;

class Empleado {
private:
    string nombre;
    int edad;
    int salario;
    
public:
    Empleado(string nombre, int edad, int salario)
        : nombre(nombre), edad(edad), salario(salario) {}

    // Creando una funcion const que no modificara los atributos de clase
    // Al ser una funcion que no debe alterar el estado del objeto, se declara como const
    void mostrarDatos() const {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "Salario: " << salario << endl;
    }
};

int main() {
    Empleado emp1("Juan Perez", 30, 50000);
    Empleado emp2("Ana Gomez", 28, 60000);
    Empleado emp3("Luis Martinez", 35, 70000);

    Empleado empleados[] = {emp1, emp2, emp3};

    for(int i = 0; i < 3; i++) {
        cout << "EMPLEADO " << (i + 1) << ":" << endl;
        empleados[i].mostrarDatos();
        cout << endl;
    }

    return 0;
}

/*
EJECUCION ESPERADA:

EMPLEADO 1:
Nombre: Juan Perez
Edad: 30
Salario: 50000

EMPLEADO 2:
Nombre: Ana Gomez
Edad: 28
Salario: 60000

EMPLEADO 3:
Nombre: Luis Martinez
Edad: 35
Salario: 70000

*/