#include <iostream>
using namespace std;

// Paso 2: Crear la clase completamente abstracta "Forma"
class Forma {
public:
    // Método abstracto que representa el cálculo del perímetro de una forma geométrica
    virtual double calcularPerimetro() = 0;
};

// Paso 4: Crear las clases derivadas "Círculo" y "Rectángulo"

// Clase derivada Círculo
class Circulo : public Forma {
private:
    double radio;
public:
    Circulo(double r) : radio(r) {}
    double calcularPerimetro() override {
        return 2 * 3.14159 * radio; // Fórmula del perímetro del círculo
    }
};

// Clase derivada Rectangulo
class Rectangulo : public Forma {
private:
    double largo, ancho;
public:
    Rectangulo(double l, double a) : largo(l), ancho(a) {}
    double calcularPerimetro() override {
        return 2 * (largo + ancho); // Fórmula del perímetro del rectángulo
    }
};

// Clase derivada Triangulo
class Triangulo : public Forma {
private:
    double lado1, lado2, lado3;
public:
    Triangulo(double l1, double l2, double l3) : lado1(l1), lado2(l2), lado3(l3) {}
    double calcularPerimetro() override {
        return lado1 + lado2 + lado3; // Fórmula del perímetro del triángulo
    }
};

// Paso 5 y 8: Implementar el programa principal
int main() {
    Forma* forma = nullptr; // Puntero a la clase base para utilizar polimorfismo
    int opcion;

    do {
        // Limpiar la consola
        cout << "\033[2J\033[1;1H"; // Código ANSI para limpiar la pantalla y colocar el cursor en la posición (1,1)

        // Menú para seleccionar la forma geométrica
        cout << "Seleccione la forma para calcular el perímetro:" << endl;
        cout << "1. Círculo" << endl;
        cout << "2. Rectángulo" << endl;
        cout << "3. Triángulo" << endl;
        cout << "4. Salir" << endl;
        cout << "Opción: ";
        cin >> opcion;

        // Salir del programa si se selecciona la opción 4
        if (opcion == 4) {
            break;
        }

        // Solicitar los datos necesarios según la forma seleccionada y crear la instancia correspondiente
        switch (opcion) {
            case 1: {
                double radio;
                cout << "Ingrese el radio del círculo: ";
                cin >> radio;
                forma = new Circulo(radio);
                break;
            }
            case 2: {
                double largo, ancho;
                cout << "Ingrese el largo del rectángulo: ";
                cin >> largo;
                cout << "Ingrese el ancho del rectángulo: ";
                cin >> ancho;
                forma = new Rectangulo(largo, ancho);
                break;
            }
            case 3: {
                double lado1, lado2, lado3;
                cout << "Ingrese la longitud del primer lado del triángulo: ";
                cin >> lado1;
                cout << "Ingrese la longitud del segundo lado del triángulo: ";
                cin >> lado2;
                cout << "Ingrese la longitud del tercer lado del triángulo: ";
                cin >> lado3;
                forma = new Triangulo(lado1, lado2, lado3);
                break;
            }
            default:
                cout << "Opción no válida." << endl;
                continue;
        }

        // Calcular y mostrar el perímetro de la forma seleccionada
        if (forma) {
            cout << "El perímetro de la forma es: " << forma->calcularPerimetro() << endl;
            delete forma; // Liberar la memoria asignada
        }

        // Esperar a que el usuario presione Enter para continuar
        cout << "Presione Enter para continuar...";
        cin.ignore();
        cin.get();

    } while (true);

    return 0;
}
