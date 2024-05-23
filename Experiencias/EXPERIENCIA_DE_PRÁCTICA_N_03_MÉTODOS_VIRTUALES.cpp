#include <iostream>
using namespace std;

// Paso 2: Crear la clase base "Animal" con un método virtual "hacerSonido()"
class Animal {
public:
    // Método virtual que representa el sonido que hace el animal
    virtual void hacerSonido() const {
        cout << "Este animal hace un sonido." << endl;
    }
};

// Paso 3: Crear al menos dos clases derivadas de "Animal": "Perro" y "Gato"

// Clase derivada Perro
class Perro : public Animal {
public:
    // Redefinición del método virtual para que el perro haga un ladrido
    void hacerSonido() const override {
        cout << "Woof!" << endl;
    }
};

// Clase derivada Gato
class Gato : public Animal {
public:
    // Redefinición del método virtual para que el gato haga un maullido
    void hacerSonido() const override {
        cout << "Meow!" << endl;
    }
};

// Paso 6: Agregar al menos una nueva clase derivada, por ejemplo, "Vaca"

// Clase derivada Vaca
class Vaca : public Animal {
public:
    // Redefinición del método virtual para que la vaca haga un mugido
    void hacerSonido() const override {
        cout << "Moo!" << endl;
    }
};

// Paso 4 y 7: Implementar el programa principal
int main() {
    // Crear instancias de diferentes animales y llamar al método "hacerSonido()"
    Animal* animales[] = {new Perro(), new Gato(), new Vaca()};
    for (const auto& animal : animales) {
        animal->hacerSonido();
        delete animal; // Liberar la memoria asignada
    }

    return 0;
}
