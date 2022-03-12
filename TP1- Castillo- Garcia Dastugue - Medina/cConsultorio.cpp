
#include "cConsultorio.h"
#include "cMedicos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
//contructor y destructor
cConsultorio::cConsultorio(string Direccion_, string HorarioAtencion_, int ID_,  string Telefono_) {
	Direccion = Direccion_;
	HorarioAtencion = HorarioAtencion_;
	ID = ID_;
	
	Telefono = Telefono_;
}

cConsultorio::~cConsultorio() {}



void cConsultorio::arribar_medico(cMedicos*medico) {
	if (medico->getID_consultorio() == getID())//obtenemos el id del medico
	{	//lo asignamos como uno de los medicos del constltorio
		if (Medico1 == NULL)
		{
			setMedico1(medico);
		}
		else
			setMedico2(medico);
	}
	else
	{
		cout << "Medico {" << medico->getApellido() << "} {" << medico->getMatricula() << "} no corresponde al consultorio";//si no, se nforma que el medico no esta en este cosnultorio 
	}
}
void cConsultorio::entrar_paciente(cPaciente* paciente) {
	PROBLEMAS problema = paciente->getProblema();//se obtiene el problema del paciente 
	if (Medico1->getOcupado() == true && Medico2->getOcupado() == true)//si los dos medicos estan ocupados se informa
		cout << "Los medicos estan ocupados.";
	else//si algun medico esta libre 
	{	//se busca al medico de la especialidad del problema 
		if (paciente->VerificarProblemaCardio(problema) == false)
		{
			if (Medico1->getEspecialidad() == ESPECIALIDAD::OFTALMOLOGO)
				Medico1->setPaciente(paciente);
			else
				Medico2->setPaciente(paciente);
		}
		else
		{
			if (Medico1->getEspecialidad() == ESPECIALIDAD::CARDIOLOGO)
				Medico1->setPaciente(paciente);
			else
				Medico2->setPaciente(paciente);
		}
	}
}

cMedicos* cConsultorio::retirar_medico(string medico) {
	//se obtienen algunos  datos de los medicos 
	string medico1 = Medico1->getNombre() + " " + Medico1->getApellido();
	string medico2 = Medico2->getNombre() + " " + Medico2->getApellido();
	if (medico == medico1)//si ese medico esta en el consultorio 
	{
		return Medico1;
		Medico1 = NULL;//redireccinamos el puntero a null
	}
	else if (medico == medico2)
	{
		return Medico2;
		Medico2 = NULL;
	}
	else//si no esta en el consultrio
	{
		cout << "Este medico no se encuentra en el consultorio.";//se informa 
		return NULL;
	}
}
string cConsultorio::to_stringConsultorio() {
	//se cargan los datos en el string 
	stringstream ss;
	ss << "Direccion: " << Direccion << endl;
	ss << "Horario de Atencion: " << HorarioAtencion << endl;
	ss << "ID: " << to_string(ID) << endl;
	if (Medico1 != NULL) {
		ss << "Medico: " << Medico1->getNombre() << " " << Medico1->getApellido() << endl;
	}
	if (Medico2 != NULL) {
		ss << "Medico: " << Medico2->getNombre() << " " << Medico2->getApellido() << endl;
	}
	ss << "Telefono: " << Telefono << endl;
	return  ss.str();
}
// se imprime el string 
void cConsultorio::imprimirConsultorio() {
	string Aimprimir = to_stringConsultorio();
	cout << Aimprimir;
}

//asignamos nuevos medicos al consultorio
void cConsultorio::setMedico1(cMedicos*newmedico)
{
	Medico1 =newmedico;
}
void cConsultorio::setMedico2(cMedicos*newmedico)
{
	Medico2 = newmedico;
}

