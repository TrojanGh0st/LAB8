#include <iostream> 

#include <cmath> 

 

class Figura { 

public: 

    virtual void dibujar() const = 0; // Método abstracto para dibujar la figura 

    virtual double calcularArea() const = 0; // Método abstracto para calcular el área de la figura 

    virtual ~Figura() {} // Destructor virtual 

}; 

 

class Circulo : public Figura { 

private: 

    double radio; 

public: 

    Circulo(double r) : radio(r) {} 

 

    void dibujar() const override { 

        std::cout << "Dibujando un círculo con radio " << radio << std::endl; 

    } 

 

    double calcularArea() const override { 

        return M_PI * radio * radio; 

    } 

}; 

 

class Rectangulo : public Figura { 

private: 

    double ancho; 

    double alto; 

public: 

    Rectangulo(double a, double h) : ancho(a), alto(h) {} 

 

    void dibujar() const override { 

        std::cout << "Dibujando un rectángulo de " << ancho << " de ancho y " << alto << " de alto" << std::endl; 

    } 

 

    double calcularArea() const override { 

        return ancho * alto; 

    } 

}; 

 

class Triangulo : public Figura { 

private: 

    double base; 

    double altura; 

public: 

    Triangulo(double b, double h) : base(b), altura(h) {} 

 

    void dibujar() const override { 

        std::cout << "Dibujando un triángulo con base " << base << " y altura " << altura << std::endl; 

    } 

 

    double calcularArea() const override { 

        return 0.5 * base * altura; 

    } 

}; 

 

int main() { 

    Circulo c(5.0); 

    Rectangulo r(4.0, 6.0); 

    Triangulo t(3.0, 7.0); 

 

    Figura* figuras[] = { &c, &r, &t }; 

 

    for (Figura* f : figuras) { 

        f->dibujar(); 

        std::cout << "Área: " << f->calcularArea() << std::endl; 

    } 

 

    return 0; 

}
