#pragma once
#include <ctime>
#include <string>

using namespace std;
//creamos enum de los posibles problemas de los pacientes 
enum class PROBLEMAS { CONSULTA_OJOS, CONSULTA_CARDIO, IRRITACION_OCULAR, MIODESOPSIAS, PALPITACIONES, TENSION } typedef Problemas;

class cPaciente
{


	// atributos provados
private:
	string Apellido;
	time_t FechaNacim;
	string Nombre;
	PROBLEMAS Problema;
	string Telefono;
	time_t UltimaVisita;

public:
	//constructor y destructor 
	cPaciente(string Apellido_, string Nombre_, PROBLEMAS Problema_, string telefono_);
	~cPaciente();
	// metodos para ejecurtar en el .cpp o main
	void imprimirPaciente();
	string to_stringPaciente();
	bool VerificarProblemaCardio(PROBLEMAS problema);


	//getters y setters para poder obtener los valores de las variables
	string getApellido() { return Apellido; };
	time_t getFechaNacim() { return FechaNacim; };
	string getNombre() { return Nombre; };
	PROBLEMAS getProblema() { return Problema; };
	string getTelefono() { return Telefono; };
	time_t getUltimaVisita() { return UltimaVisita; };

	void setUltimaVisita();
	void setFechaNacim(int dia, int mes, int anio);





};


