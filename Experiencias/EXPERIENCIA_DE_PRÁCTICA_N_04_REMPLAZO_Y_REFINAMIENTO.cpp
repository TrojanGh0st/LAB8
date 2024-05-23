#include <iostream>
using namespace std;

// Paso 2: Crear la clase base "Vehículo" con un método "acelerar()"
class Vehiculo {
public:
    // Método que imprime "Acelerando el vehículo"
    void acelerar() const {
        cout << "Acelerando el vehículo" << endl;
    }
};

// Paso 3: Crear la clase derivada "Coche" que redefine el método "acelerar()"
class Coche : public Vehiculo {
public:
    // Redefinición del método que imprime "Acelerando el coche"
    void acelerar() const {
        cout << "Acelerando el coche" << endl;
    }

    // Nuevo método solo para la clase Coche
    void encenderLuces() const {
        cout << "Luces del coche encendidas" << endl;
    }
};

// Paso 5: Agregar otra clase derivada "Motocicleta" que redefine el método "acelerar()"
class Motocicleta : public Vehiculo {
public:
    // Redefinición del método que imprime "Acelerando la motocicleta"
    void acelerar() const {
        cout << "Acelerando la motocicleta" << endl;
    }
};

// Paso 4 y 6: Implementar el programa principal
int main() {
    // Crear una instancia de la clase "Coche" y llamar al método "acelerar()"
    Coche coche;
    cout << "Coche: ";
    coche.acelerar();

    // Crear una instancia de la clase "Motocicleta" y llamar al método "acelerar()"
    Motocicleta motocicleta;
    cout << "Motocicleta: ";
    motocicleta.acelerar();

    // Paso 8: Llamar al método "encenderLuces()" solo en una instancia de la clase "Coche"
    coche.encenderLuces();

    return 0;
}
