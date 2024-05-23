#include <iostream> 

using namespace std; 

 

class Empleado { 

public: 

    virtual double calcularSalario() const = 0; // Método virtual puro 

    virtual ~Empleado() {} // Destructor virtual 

}; 

 

class EmpleadoTiempoCompleto : public Empleado { 

private: 

    double salarioMensual; 

 

public: 

    EmpleadoTiempoCompleto(double salario) : salarioMensual(salario) {} 

 

    double calcularSalario() const override { 

        return salarioMensual; 

    } 

}; 

 

class EmpleadoMedioTiempo : public Empleado { 

private: 

    double salarioPorHora; 

    int horasTrabajadas; 

 

public: 

    EmpleadoMedioTiempo(double salarioHora, int horas) : salarioPorHora(salarioHora), horasTrabajadas(horas) {} 

 

    double calcularSalario() const override { 

        return salarioPorHora * horasTrabajadas; 

    } 

}; 

 

int main() { 

    EmpleadoTiempoCompleto empFullTime(3000.0); // Salario mensual fijo 

    EmpleadoMedioTiempo empPartTime(20.0, 80);  // Salario por hora y horas trabajadas 

 

    Empleado* empleados[] = { &empFullTime, &empPartTime }; 

 

    for (Empleado* emp : empleados) { 

        cout << "Salario: $" << emp->calcularSalario() << endl; 

    } 

 

    return 0; 

}
