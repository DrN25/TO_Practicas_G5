#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

// Función inline para calcular descuento
inline double calcularDescuento(double precio, double porcentajeDescuento) {
    return precio * (porcentajeDescuento / 100.0);
}

// Declaración adelantada para la función friend
class Producto;
bool compararPrecios(const Producto& p1, const Producto& p2);

// Clase Producto
class Producto {
private:
    string nombre;
    double precio;
    int cantidad;

public:
    // Constructor
    Producto(string nom = "", double prec = 0.0, int cant = 0) 
        : nombre(nom), precio(prec), cantidad(cant) {}

    // Getters const (no modifican el objeto)
    string getNombre() const { return nombre; }
    double getPrecio() const { return precio; }
    int getCantidad() const { return cantidad; }
    
    // Método const para calcular precio total
    double getPrecioTotal() const {
        return precio * cantidad;
    }

    // Método const para mostrar información
    void mostrarInfo() const {
        cout << fixed << setprecision(2);
        cout << "Producto: " << nombre << endl;
        cout << "Precio unitario: $" << precio << endl;
        cout << "Cantidad: " << cantidad << endl;
        cout << "Precio total: $" << getPrecioTotal() << endl;
    }

    // Método para aplicar descuento
    void aplicarDescuento(double porcentaje) {
        double descuento = calcularDescuento(precio, porcentaje);
        precio -= descuento;
        cout << "Descuento aplicado: $" << descuento << endl;
        cout << "Nuevo precio: $" << precio << endl;
    }

    // Sobrecarga del operador + (suma precios y cantidades)
    Producto operator+(const Producto& otro) const {
        string nombreCombinado = nombre + " + " + otro.nombre;
        double precioTotal = precio + otro.precio;
        int cantidadTotal = cantidad + otro.cantidad;
        return Producto(nombreCombinado, precioTotal, cantidadTotal);
    }

    // Declaración de función friend
    friend bool compararPrecios(const Producto& p1, const Producto& p2);
    
    // Sobrecarga del operador << para salida
    friend ostream& operator<<(ostream& os, const Producto& p) {
        os << fixed << setprecision(2);
        os << "Nombre: " << p.nombre << endl;
        os << "Precio unitario: $" << p.precio << endl;
        os << "Cantidad: " << p.cantidad << endl;
        os << "Precio total: $" << p.getPrecioTotal() << endl;
        return os;
    }
};

// Función friend para comparar precios
bool compararPrecios(const Producto& p1, const Producto& p2) {
    return p1.precio < p2.precio;
}

// Función para mostrar menú
void mostrarMenu() {
    cout << "\n========================================" << endl;
    cout << "       SISTEMA DE PRODUCTOS" << endl;
    cout << "========================================" << endl;
    cout << "1. Agregar producto" << endl;
    cout << "2. Mostrar todos los productos" << endl;
    cout << "3. Aplicar descuento a producto" << endl;
    cout << "4. Comparar precios" << endl;
    cout << "5. Combinar productos" << endl;
    cout << "6. Filtrar por precio maximo" << endl;
    cout << "7. Salir" << endl;
    cout << "========================================" << endl;
    cout << "Opcion: ";
}

int main() {
    vector<Producto> productos;
    int opcion;

    // Lambda para filtrar productos por precio
    auto filtrarPorPrecio = [](const vector<Producto>& prods, double precioMax) {
        vector<Producto> filtrados;
        copy_if(prods.begin(), prods.end(), back_inserter(filtrados),
                [precioMax](const Producto& p) { return p.getPrecio() <= precioMax; });
        return filtrados;
    };

    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore();

        switch(opcion) {
            case 1: {
                string nombre;
                double precio;
                int cantidad;
                
                cout << "\n--- Agregar Producto ---" << endl;
                cout << "Nombre: ";
                getline(cin, nombre);
                cout << "Precio: $";
                cin >> precio;
                cout << "Cantidad: ";
                cin >> cantidad;
                
                productos.push_back(Producto(nombre, precio, cantidad));
                cout << "\nProducto agregado exitosamente!" << endl;
                break;
            }
            
            case 2: {
                cout << "\n--- Lista de Productos ---" << endl;
                if(productos.empty()) {
                    cout << "No hay productos registrados." << endl;
                } else {
                    for(size_t i = 0; i < productos.size(); i++) {
                        cout << "\nProducto #" << (i+1) << ":" << endl;
                        cout << "----------------------------------------" << endl;
                        cout << productos[i];
                        cout << "----------------------------------------" << endl;
                    }
                }
                break;
            }
            
            case 3: {
                if(productos.empty()) {
                    cout << "\nNo hay productos registrados." << endl;
                    break;
                }
                
                int indice;
                double descuento;
                cout << "\n--- Aplicar Descuento ---" << endl;
                cout << "Numero de producto (1-" << productos.size() << "): ";
                cin >> indice;
                
                if(indice < 1 || indice > (int)productos.size()) {
                    cout << "Producto invalido." << endl;
                    break;
                }
                
                cout << "Porcentaje de descuento: ";
                cin >> descuento;
                
                productos[indice-1].aplicarDescuento(descuento);
                break;
            }
            
            case 4: {
                if(productos.size() < 2) {
                    cout << "\nSe necesitan al menos 2 productos para comparar." << endl;
                    break;
                }
                
                int ind1, ind2;
                cout << "\n--- Comparar Precios ---" << endl;
                cout << "Primer producto (1-" << productos.size() << "): ";
                cin >> ind1;
                cout << "Segundo producto (1-" << productos.size() << "): ";
                cin >> ind2;
                
                if(ind1 < 1 || ind1 > (int)productos.size() || 
                   ind2 < 1 || ind2 > (int)productos.size()) {
                    cout << "Productos invalidos." << endl;
                    break;
                }
                
                if(compararPrecios(productos[ind1-1], productos[ind2-1])) {
                    cout << "\n'" << productos[ind1-1].getNombre() 
                         << "' ($" << fixed << setprecision(2) << productos[ind1-1].getPrecio()
                         << ") es mas barato que '" 
                         << productos[ind2-1].getNombre() 
                         << "' ($" << productos[ind2-1].getPrecio() << ")" << endl;
                } else if(compararPrecios(productos[ind2-1], productos[ind1-1])) {
                    cout << "\n'" << productos[ind2-1].getNombre() 
                         << "' ($" << fixed << setprecision(2) << productos[ind2-1].getPrecio()
                         << ") es mas barato que '" 
                         << productos[ind1-1].getNombre() 
                         << "' ($" << productos[ind1-1].getPrecio() << ")" << endl;
                } else {
                    cout << "\nAmbos productos tienen el mismo precio: $" 
                         << fixed << setprecision(2) << productos[ind1-1].getPrecio() << endl;
                }
                break;
            }
            
            case 5: {
                if(productos.size() < 2) {
                    cout << "\nSe necesitan al menos 2 productos para combinar." << endl;
                    break;
                }
                
                int ind1, ind2;
                cout << "\n--- Combinar Productos ---" << endl;
                cout << "Primer producto (1-" << productos.size() << "): ";
                cin >> ind1;
                cout << "Segundo producto (1-" << productos.size() << "): ";
                cin >> ind2;
                
                if(ind1 < 1 || ind1 > (int)productos.size() || 
                   ind2 < 1 || ind2 > (int)productos.size()) {
                    cout << "Productos invalidos." << endl;
                    break;
                }
                
                Producto combinado = productos[ind1-1] + productos[ind2-1];
                cout << "\n--- Producto Combinado ---" << endl;
                cout << "----------------------------------------" << endl;
                cout << combinado;
                cout << "----------------------------------------" << endl;
                break;
            }
            
            case 6: {
                if(productos.empty()) {
                    cout << "\nNo hay productos registrados." << endl;
                    break;
                }
                
                double precioMax;
                cout << "\n--- Filtrar por Precio ---" << endl;
                cout << "Precio maximo: $";
                cin >> precioMax;
                
                vector<Producto> filtrados = filtrarPorPrecio(productos, precioMax);
                
                if(filtrados.empty()) {
                    cout << "\nNo hay productos con precio menor o igual a $" 
                         << fixed << setprecision(2) << precioMax << endl;
                } else {
                    cout << "\nProductos con precio <= $" << fixed << setprecision(2) 
                         << precioMax << ":" << endl;
                    for(size_t i = 0; i < filtrados.size(); i++) {
                        cout << "\nProducto #" << (i+1) << ":" << endl;
                        cout << "----------------------------------------" << endl;
                        cout << filtrados[i];
                        cout << "----------------------------------------" << endl;
                    }
                }
                break;
            }
            
            case 7:
                cout << "\nGracias por usar el Sistema de Productos!" << endl;
                break;
                
            default:
                cout << "\nOpcion invalida. Intente nuevamente." << endl;
        }
        
    } while(opcion != 7);

    return 0;
}
