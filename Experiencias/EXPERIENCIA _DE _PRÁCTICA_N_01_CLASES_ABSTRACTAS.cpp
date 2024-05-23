#include <iostream>
using namespace std;

// Paso 2: Crear la clase abstracta "Figura"
class Figura {
public:
    // Método abstracto que debe ser implementado por las clases derivadas
    virtual double calcularArea() = 0; 
};

// Paso 3: Crear las clases derivadas "Círculo", "Rectángulo" y "Triángulo"

// Clase derivada Circulo
class Circulo : public Figura {
private:
    double radio;
public:
    Circulo(double r) : radio(r) {} // Constructor que inicializa el radio
    double calcularArea() override {
        return 3.14159 * radio * radio; // Fórmula del área del círculo
    }
};

// Clase derivada Rectangulo
class Rectangulo : public Figura {
private:
    double largo, ancho;
public:
    Rectangulo(double l, double a) : largo(l), ancho(a) {} // Constructor que inicializa largo y ancho
    double calcularArea() override {
        return largo * ancho; // Fórmula del área del rectángulo
    }
};

// Clase derivada Triangulo
class Triangulo : public Figura {
private:
    double base, altura;
public:
    Triangulo(double b, double h) : base(b), altura(h) {} // Constructor que inicializa base y altura
    double calcularArea() override {
        return (base * altura) / 2; // Fórmula del área del triángulo
    }
};

// Paso 6: Agregar al menos dos figuras más

// Clase derivada Cuadrado
class Cuadrado : public Figura {
private:
    double lado;
public:
    Cuadrado(double l) : lado(l) {} // Constructor que inicializa el lado
    double calcularArea() override {
        return lado * lado; // Fórmula del área del cuadrado
    }
};

// Clase derivada Pentagono
class Pentagono : public Figura {
private:
    double lado, apotema;
public:
    Pentagono(double l, double a) : lado(l), apotema(a) {} // Constructor que inicializa lado y apotema
    double calcularArea() override {
        return (5 * lado * apotema) / 2; // Fórmula del área del pentágono
    }
};

// Paso 4 y 7: Implementar el programa principal
int main() {
    Figura* figura = nullptr; // Puntero a la clase base para utilizar polimorfismo
    int opcion;

    do {
        // Limpiar la pantalla
        system("cls");

        // Menú para seleccionar la figura geométrica
        cout << "Seleccione la figura para calcular el área:" << endl;
        cout << "1. Circulo" << endl;
        cout << "2. Rectangulo" << endl;
        cout << "3. Triangulo" << endl;
        cout << "4. Cuadrado" << endl;
        cout << "5. Pentagono" << endl;
        cout << "6. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        // Salir del programa si se selecciona la opción 6
        if (opcion == 6) {
            break;
        }

        // Solicitar los datos necesarios según la figura seleccionada y crear la instancia correspondiente
        switch (opcion) {
            case 1: {
                double radio;
                cout << "Ingrese el radio del circulo: ";
                cin >> radio;
                figura = new Circulo(radio);
                break;
            }
            case 2: {
                double largo, ancho;
                cout << "Ingrese el largo del rectangulo: ";
                cin >> largo;
                cout << "Ingrese el ancho del rectangulo: ";
                cin >> ancho;
                figura = new Rectangulo(largo, ancho);
                break;
            }
            case 3: {
                double base, altura;
                cout << "Ingrese la base del triangulo: ";
                cin >> base;
                cout << "Ingrese la altura del triangulo: ";
                cin >> altura;
                figura = new Triangulo(base, altura);
                break;
            }
            case 4: {
                double lado;
                cout << "Ingrese el lado del cuadrado: ";
                cin >> lado;
                figura = new Cuadrado(lado);
                break;
            }
            case 5: {
                double lado, apotema;
                cout << "Ingrese el lado del pentagono: ";
                cin >> lado;
                cout << "Ingrese la apotema del pentagono: ";
                cin >> apotema;
                figura = new Pentagono(lado, apotema);
                break;
            }
            default:
                cout << "Opcion no valida." << endl;
                continue;
        }

        // Calcular y mostrar el área de la figura seleccionada
        if (figura) {
            cout << "El área de la figura es: " << figura->calcularArea() << endl;
            delete figura; // Liberar la memoria asignada
        }

        // Esperar a que el usuario presione Enter
        cout << "Presione cualquier tecla para continuar...";
        cin.ignore();
        cin.get();

    } while (true);

    return 0;
}