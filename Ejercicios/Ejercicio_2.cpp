#include <iostream> 

 

using namespace std; 

 

class Reproductor { 

public: 

    virtual void reproducir() = 0; // Método abstracto para reproducir audio 

    virtual void pausar() = 0;     // Método abstracto para pausar audio 

    virtual void detener() = 0;    // Método abstracto para detener la reproducción de audio 

    virtual ~Reproductor() {}      // Destructor virtual 

}; 

 

class ReproductorMP3 : public Reproductor { 

private: 

    bool reproduciendo; 

    bool enPausa; 

 

public: 

    ReproductorMP3() : reproduciendo(false), enPausa(false) {} 

 

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

        } 

    } 

 

    void pausar() override { 

        if (reproduciendo && !enPausa) { 

            cout << "Pausando el archivo MP3." << endl; 

            enPausa = true; 

        } else if (enPausa) { 

            cout << "El archivo MP3 ya está en pausa." << endl; 

        } else { 

            cout << "El archivo MP3 no se está reproduciendo." << endl; 

        } 

    } 

 

    void detener() override { 

        if (reproduciendo) { 

            cout << "Deteniendo la reproducción del archivo MP3." << endl; 

            reproduciendo = false; 

            enPausa = false; 

        } else { 

            cout << "El archivo MP3 no se está reproduciendo." << endl; 

        } 

    } 

}; 

 

int main() { 

    ReproductorMP3 mp3Player; 

 

    mp3Player.reproducir(); // Debería imprimir "Reproduciendo el archivo MP3." 

    mp3Player.pausar();     // Debería imprimir "Pausando el archivo MP3." 

    mp3Player.reproducir(); // Debería imprimir "Reanudando la reproducción del archivo MP3." 

    mp3Player.detener();    // Debería imprimir "Deteniendo la reproducción del archivo MP3." 

    mp3Player.pausar();     // Debería imprimir "El archivo MP3 no se está reproduciendo." 

    mp3Player.detener();    // Debería imprimir "El archivo MP3 no se está reproduciendo." 

 

    return 0; 

}
