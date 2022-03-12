#pragma once
#include "cMedicos.h"
#include "cPaciente.h"
#include <string>

using namespace std;

class cConsultorio
{
	//atributos privados
private:
	string Direccion;
	string HorarioAtencion;
	int ID;
	cMedicos* Medico1;
	cMedicos* Medico2;
	string Telefono;
public:
	//constructor y destructor
	cConsultorio(string Direccion_, string HorarioAtencion_, int ID_,  string Telefono_);
	~cConsultorio();

	//metodos para implementar en el .cpp o main
	void arribar_medico(cMedicos*medico);
	void entrar_paciente(cPaciente* paciente);
	void imprimirConsultorio();
	cMedicos* retirar_medico(string medico);
	string to_stringConsultorio();

	//geters y sterrer para obtener y modificar los valores de ls atributos 
	void setMedico1(cMedicos*newmedico);
	void setMedico2(cMedicos*newmedico);


	string getDireccion() { return Direccion; };
	string getHorarioAtencion() { return HorarioAtencion; };
	string getTelefono() { return Telefono; };
	int getID() { return ID; };
	cMedicos* getMedico1() { return Medico1; };
	cMedicos* getMedico2() { return Medico2; };

};


