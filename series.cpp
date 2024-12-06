#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <fstream>

using namespace std;

// Clase Persona
class Persona {
protected:
    string nombre;
    int edad;
    char sexo;

public:
    Persona(string _nombre, int _edad, char _sexo) {
        nombre = _nombre;
        edad = _edad;
        sexo = _sexo;
    }

    virtual void mostrarInformacion() {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "Sexo: " << sexo << endl;
    }
};

// Clase Usuario (hereda de Persona)
class Usuario : public Persona {
private:
    string nombreUsuario;
    string contrasena;

public:
    Usuario(string _nombre, int _edad, char _sexo, string _nombreUsuario, string _contrasena)
        : Persona(_nombre, _edad, _sexo) {
        nombreUsuario = _nombreUsuario;
        contrasena = _contrasena;
    }

    void iniciarSesion() {
        cout << "Iniciando sesión para el usuario: " << nombreUsuario << endl;
    }

    void Registrar() {
        cout << "Registrando nuevo usuario: " << nombreUsuario << endl;
    }

    void mostrarSeriesDisponibles() {
        cout << "Mostrando series disponibles para el usuario: " << nombreUsuario << endl;
    }
};

// Clase Dueno (hereda de Persona)
class Dueno : public Persona {
private:
    string nombreDueno;
    string contrasenaDueno;

public:
    Dueno(string _nombre, int _edad, char _sexo, string _nombreDueno, string _contrasenaDueno)
        : Persona(_nombre, _edad, _sexo) {
        nombreDueno = _nombreDueno;
        contrasenaDueno = _contrasenaDueno;
    }

    void agregarSerie(string serie) {
        cout << "Serie '" << serie << "' agregada por el dueno: " << nombreDueno << endl;
    }

    void eliminarSerie(string serie) {
        cout << "Serie '" << serie << "' eliminada por el dueno: " << nombreDueno << endl;
    }

    void mostrarUsuarios() {
        cout << "Mostrando usuarios asociados al dueno: " << nombreDueno << endl;
    }
};

// Clase Contenido
class Contenido {
protected:
    string titulo;
    int anoEstreno;
    double calificacion;

public:
    Contenido(string _titulo, int _anoEstreno, double _calificacion) {
        titulo = _titulo;
        anoEstreno = _anoEstreno;
        calificacion = _calificacion;
    }

    virtual void mostrarInformacion() {
        cout << "Título: " << titulo << endl;
        cout << "Año de Estreno: " << anoEstreno << endl;
        cout << "Calificación: " << calificacion << endl;
    }
};

// Clase Serie (hereda de Contenido)
class Serie : public Contenido {
private:
    string genero;
    int numeroTemporadas;

public:
    Serie(string _titulo, int _anoEstreno, double _calificacion, string _genero, int _numeroTemporadas)
        : Contenido(_titulo, _anoEstreno, _calificacion) {
        genero = _genero;
        numeroTemporadas = _numeroTemporadas;
    }

    void mostrarPuntuacion() {
        cout << "La puntuación de la serie '" << titulo << "' es: " << calificacion << endl;
    }

    void mostrarSeriesPorGenero() {
        cout << "Mostrando series de género '" << genero << "'" << endl;
    }
};

// Clase Temporada (hereda de Contenido)
class Temporada : public Contenido {
private:
    int numeroTemporada;
    int numeroEpisodios;

public:
    Temporada(string _titulo, int _aoEstreno, double _calificacion, int _numeroTemporada, int _numeroEpisodios)
        : Contenido(_titulo, _aoEstreno, _calificacion) {
        numeroTemporada = _numeroTemporada;
        numeroEpisodios = _numeroEpisodios;
    }

    void mostrarInformacion() override {
        Contenido::mostrarInformacion();
        cout << "Número de Temporada: " << numeroTemporada << endl;
        cout << "Número de Episodios: " << numeroEpisodios << endl;
    }
};

// Clase Episodio (hereda de Contenido)
class Episodio : public Contenido {
private:
    int numeroEpisodio;
    string sinopsis;

public:
    Episodio(string _titulo, int _anoEstreno, double _calificacion, int _numeroEpisodio, string _sinopsis)
        : Contenido(_titulo, _anoEstreno, _calificacion) {
        numeroEpisodio = _numeroEpisodio;
        sinopsis = _sinopsis;
    }

    void mostrarInformacion() override {
        Contenido::mostrarInformacion();
        cout << "Número de Episodio: " << numeroEpisodio << endl;
        cout << "Sinopsis: " << sinopsis << endl;
    }
};


void menuUsuario(){
	int opUsuario;
	do{
		system("cls");
		cout<<" === USUARIO ===\n\n"
			<<"1. Inciar sesión\n"
			<<"2. Registrarse\n"
			<<"3. Restablecer contraseña\n"
			<<"4. SALIR\n\n"
			<<"Ingrese una de las opciones: ";
			cin>>opUsuario;
		switch(opUsuario){
			case 1:
				system("cls");
				//inciarSesion();
				system("pause");
				break;
			case 2:
				system("cls");
			//	registrar();
				system("pause");
				break;
			case 3:
				system("cls");
				//restablecerContra();
				break;
			default:
				cout<<"Ingrese una opcion valida\n";
				system("pause");
				break;
			case 4:
				break;
				
		}
	}while(opUsuario!=4);
}


// Función principal
int main() {
	SetConsoleOutputCP(CP_UTF8);
	int op;
	
	do{
		system("cls");
		cout<<" SERIES\n\n"
			<<"1. Usuario\n"
			<<"2. Dueño\n"
			<<"3. SALIR\n\n"
			<<"Ingrese una de las opciones: ";
			cin>>op;
		switch(op){
			case 1:
				system("cls");
				menuUsuario();
				system("pause");
				break;
			case 2:
				system("cls");
			//	menuDueno();
				system("pause");
				break;
			case 3:
				cout<<"SALIENDO . . .\n";
				system("pause");
				break;
			default:
				cout<<"Ingrese una opcion valida\n";
				system("pause");
				break;
		}
	}while(op!=3);
	
	
	

    return 0;
}
