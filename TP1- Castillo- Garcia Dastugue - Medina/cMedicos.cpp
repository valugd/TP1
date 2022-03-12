#include <ctime>
#include "cMedicos.h"
#include "cPaciente.h"
#include "cConsultorio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

//constructor y destructor
cMedicos::cMedicos(string Apellido_, ESPECIALIDAD Especialidad_, time_t FechaNacim_, int ID_Consultorio_, int Matricula_, string Nombre_, bool Ocupado_) {
	Apellido = Apellido_;
	Especialidad = Especialidad_;
	FechaNacim = FechaNacim_;
	ID_Consultorio = ID_Consultorio_;
	Matricula = Matricula_;
	Nombre = Nombre_;
	Ocupado = Ocupado_;
	
}



cMedicos::~cMedicos() {}
//actualizamos los datos 
void cMedicos::setPaciente(cPaciente* paciente)
{
	Paciente = paciente;
}
void cMedicos::setFechaNacim(int dia, int mes, int anio) {
	tm tm_nacimiento = { 0 };
	tm_nacimiento.tm_mday = dia;
	tm_nacimiento.tm_mon = mes - 1;
	tm_nacimiento.tm_year = anio - 1900;
	FechaNacim = mktime(&tm_nacimiento);
}
void cMedicos::setOcupado(bool ocupado)
{
	if (ocupado == true)
		Ocupado = false;
	else
		Ocupado = true;
}

void cMedicos::atender_paciente(cPaciente* paciente) {
	int cambio = 0;
	Problemas problema = paciente->getProblema();//obtenemos el problema del paciente
	if (paciente->VerificarProblemaCardio(problema) == false)//verificamos la especialidad el problema
	{
		if (getEspecialidad() == ESPECIALIDAD::OFTALMOLOGO)//le asignamos un oftarmologo y modificalos los datos
		{
			setOcupado(true);
			paciente->setUltimaVisita();
			setPaciente(paciente);
			cambio++;
		}
	}
	else
	{
		if (getEspecialidad() == ESPECIALIDAD::CARDIOLOGO)//le asignamos un cardiologo y modificalos los datos
		{
			setOcupado(true);
			paciente->setUltimaVisita();
			setPaciente(paciente);
			cambio++;
		}
	}
	if (cambio == 0)
	{
		paciente->setUltimaVisita();//actualizamos la ultima visita 
	}

}
//imprimimos los datos del medico
void cMedicos::imprimirMedico() {
	string A_Imprimir = to_stringMedico();
	cout << A_Imprimir;
}
string cMedicos::to_stringMedico() {
	string especialidad, estado, fecha_nacim;
	fecha_nacim = ctime(&FechaNacim);
	//le asignamos la especialidad al medico
	if (getEspecialidad() == ESPECIALIDAD::CARDIOLOGO)
		especialidad = "cardiologo";
	else
		especialidad = "oftalmologo";
	//asignamos un estado del medico
	if (Ocupado == true)
		estado = "OCUPADO";
	else
		estado = "LIBRE";
	//guardamos los datos en el string de cada medico 
	sstringstream ss;
	ss << "Apellido y Nombre: " << Apellido << " " << Nombre << endl;
	ss << "Especialidad: " << especialidad << endl;
	ss << "Fecha de Nacimiento:  " << fecha_nacim << endl;
	ss << "Consultorio: " << to_string(ID_Consultorio) << endl;
	ss << "Matricula: " << to_string(Matricula) << endl;
	ss << "Estado: " << estado << endl;
	if (Paciente != NULL) {
		ss << "Paciente: " << Paciente->getNombre() << " " << Paciente->getApellido() << endl;
	}
	return  ss.str();
}