// Vehiculo.h
#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>
#include <iostream>

class Vehiculo {
public:
    virtual ~Vehiculo() = default;

    virtual Vehiculo* clonar() const;
    virtual std::string getTipo() const;
    virtual void arrancar() const;
};

// ----------------------------------------------------

class Auto : public Vehiculo {
public:
    // Covarianza: Devuelve Auto* (derivado de Vehiculo*)
    Auto* clonar() const override;

    std::string getTipo() const override;
    void arrancar() const override;
};

// ----------------------------------------------------

class Moto : public Auto {
public:
    // Covarianza: Devuelve Moto* (derivado de Auto*)
    Moto* clonar() const override;

    std::string getTipo() const override;
    void arrancar() const override;
};

#endif // VEHICULO_H