#include <iostream>
#include <memory>

class Base {};

class Derived : public Base {};

template <typename T>
class Contravariante {
private:
    void (*func_)(T*);

public:
    Contravariante(void (*func)(T*)) : func_(func) {}
    template <typename U>
    void operator()(U* obj) const {
        func_(obj);
    }
};

void procesar_base(Base* b) {
    std::cout << "Procesando un objeto de tipo Base o derivado de Base." << std::endl;
}

int main() {
    Contravariante<Base> c_base(procesar_base);
    std::cout << "Prueba de contravarianza simulada:" << std::endl;
    Base b;
    Derived d;
    std::cout << "Llamada con Base*: ";
    c_base(&b);
    std::cout << "Llamada con Derived*: ";
    c_base(&d);
    return 0;
}
