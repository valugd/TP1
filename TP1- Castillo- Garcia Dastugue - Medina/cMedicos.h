#pragma once
#include <ctime>
#include "cPaciente.h"
#include <string>


using namespace std;
enum class ESPECIALIDAD { OFTALMOLOGO, CARDIOLOGO };

class cMedicos
{

public:
	//cosnttuctor y destructor 
	cMedicos(string Apellido_, ESPECIALIDAD Especialidad_, time_t FechaNacim_, int ID_Consultorio_, int Matricula_, string Nombre_, bool Ocupado_);
	~cMedicos();
	//getters y setters para poder obtener y modificar los atributos
	void setOcupado(bool ocupado);
	void setFechaNacim(int dia, int mes, int anio);
	void setPaciente(cPaciente* paciente);

	string getApellido() { return Apellido; };
	ESPECIALIDAD getEspecialidad() { return Especialidad; };
	time_t getFechaNacim() { return FechaNacim; };
	int getID_consultorio() { return ID_Consultorio; };
	int getMatricula() { return Matricula; };
	string getNombre() { return Nombre; };
	bool getOcupado() { return Ocupado; };
	cPaciente* getPaciente() { return Paciente; };
	//funcioes para ejecutar en el .cpp o main
	void atender_paciente(cPaciente* paciente);
	void imprimirMedico();
	string to_stringMedico();
	//atriburos privados
private:
	string Apellido;
	ESPECIALIDAD Especialidad;
	time_t FechaNacim;
	int ID_Consultorio;
	int Matricula;
	string Nombre;
	bool Ocupado;
	cPaciente* Paciente;
};
