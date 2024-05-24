#include <iostream>
using namespace std;

// Definición de la clase abstracta Reproductor
class Reproductor {
public:
    virtual void reproducir() = 0;  // Método virtual puro para reproducir
    virtual void pausar() = 0;      // Método virtual puro para pausar
    virtual void detener() = 0;      // Método virtual puro para detener
    virtual ~Reproductor() {}        // Destructor virtual para la clase abstracta
};

// Definición de la clase ReproductorMP3, que hereda de Reproductor
class ReproductorMP3 : public Reproductor {
private:
    bool reproduciendo;  // Bandera para indicar si se está reproduciendo
    bool enPausa;        // Bandera para indicar si la reproducción está en pausa
    int progreso;        // Progreso de la reproducción

public:
    // Constructor de la clase ReproductorMP3
    ReproductorMP3() : reproduciendo(false), enPausa(false), progreso(0) {}

    // Implementación del método reproducir de la clase Reproductor
    void reproducir() override {
        if (reproduciendo) {
            if (enPausa) {
                cout << "Reanudando la reproducción del archivo MP3." << endl;
                enPausa = false;
            } else {
                cout << "El archivo MP3 ya se está reproduciendo." << endl;
            }
        } else {
            cout << "Reproduciendo el archivo MP3." << endl;
            reproduciendo = true;
            enPausa = false;
            progreso = 0;  // Reiniciar el progreso al empezar de nuevo
        }

        while (reproduciendo && !enPausa) {
            cout << "Reproduciendo: [";
            for (int i = 0; i < 20; ++i) {
                if (i < progreso) {
                    cout << "=";
                } else {
                    cout << " ";
                }
            }
            cout << "] " << progreso * 5 << "%\r";
            cout.flush();  // Para forzar la salida del buffer
            progreso = (progreso + 1) % 21;
            delay();  // Simulación de retraso
            if (progreso == 0) {
                break;  // Termina la reproducción cuando se complete una barra
            }
        }
    }

    // Implementación del método pausar de la clase Reproductor
    void pausar() override {
        if (reproduciendo && !enPausa) {
            cout << "\nPausando el archivo MP3." << endl;
            enPausa = true;
        } else if (enPausa) {
            cout << "El archivo MP3 ya está en pausa." << endl;
        } else {
            cout << "El archivo MP3 no se está reproduciendo." << endl;
        }
    }

    // Implementación del método detener de la clase Reproductor
    void detener() override {
        if (reproduciendo) {
            cout << "\nDeteniendo la reproducción del archivo MP3." << endl;
            reproduciendo = false;
            enPausa = false;
            progreso = 0;
        } else {
            cout << "El archivo MP3 no se está reproduciendo." << endl;
        }
    }

    // Método para simular un retraso durante la reproducción
    void delay() {
        for (volatile int i = 0; i < 100000000; ++i); // Simulación de retraso simple
    }
};

// Función principal
int main() {
    ReproductorMP3 mp3Player;  // Instancia de ReproductorMP3
    int opcion;

    // Menú principal del reproductor MP3
    do {
        cout << "Menu Reproductor MP3\n";
        cout << "1. Reproducir\n";
        cout << "2. Pausar\n";
        cout << "3. Detener\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        // Switch para manejar las opciones del menú
        switch (opcion) {
            case 1:
                mp3Player.reproducir();
                break;
            case 2:
                mp3Player.pausar();
                break;
            case 3:
                mp3Player.detener();
                break;
            case 4:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo.\n";
                break;
        }   

        // Si la opción no es salir, esperar la entrada del usuario para continuar
        if (opcion != 4) {
            cout << "Presione Enter para continuar...";
            cin.ignore();
            cin.get();
        }

    } while (opcion != 4);

    return 0;
}
