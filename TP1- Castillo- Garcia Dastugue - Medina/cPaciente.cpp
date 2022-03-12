#include "cPaciente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
//construcor y destructor 
cPaciente::cPaciente(string Apellido_, string Nombre_, PROBLEMAS Problema_, string telefono_) {
	Apellido = Apellido_;
	Nombre = Nombre_;
	Problema = Problema_;
	Telefono = telefono_;
	
}

cPaciente::~cPaciente() {}


string cPaciente::to_stringPaciente() {
	string string_paciente, string_problema, ultima_visita, fecha_nacim;
	ultima_visita = ctime(&UltimaVisita);
	fecha_nacim = ctime(&FechaNacim);
	// se le asigna valor al string dependeiendo el problema
	if (Problema == PROBLEMAS::CONSULTA_CARDIO)
		string_problema = "consulta cardiologia";
	if (Problema == PROBLEMAS::CONSULTA_OJOS)
		string_problema = "consulta oftalmologia";
	if (Problema == PROBLEMAS::IRRITACION_OCULAR)
		string_problema = "irritacion ocular";
	if (Problema == PROBLEMAS::MIODESOPSIAS)
		string_problema = "miodesopsias";
	if (Problema == PROBLEMAS::PALPITACIONES)
		string_problema = "palpitaciones";
	if (Problema == PROBLEMAS::TENSION)
		string_problema = "tension";
	//se guardan en el string los datos del paciente 
	stringstream ss;
	ss << "Apellido y Nombre: " << Apellido << " " << Nombre << endl;
	ss << "Problema: " << string_problema << endl;
	ss << "Fecha de Nacimiento:  " << fecha_nacim << endl;
	ss << "Telefono: " << Telefono << endl;
	ss << "Utlima Visita: " << ultima_visita << endl;
	return  ss.str();
}
//se imprime el string del paciente con sus datos 
void cPaciente::imprimirPaciente() {
	string A_Imprimir = to_stringPaciente();
	cout << A_Imprimir;
}
//analizamos cual es el problema y a que especialidad corresponde 
bool cPaciente:: VerificarProblemaCardio(PROBLEMAS problema) {
	if (problema == PROBLEMAS::CONSULTA_CARDIO || problema == PROBLEMAS::PALPITACIONES || problema == PROBLEMAS::TENSION)
		return true;
	else
		return false;
}
//actualizamos la ultima visita 
void cPaciente::setUltimaVisita()
{
	UltimaVisita = time(0);

}
//setemos su fucha de nacimiento
void cPaciente::setFechaNacim(int dia, int mes, int anio)
{
	tm tm_nacimiento = { 0 };
	tm_nacimiento.tm_mday = dia;
	tm_nacimiento.tm_mon = mes - 1;
	tm_nacimiento.tm_year = anio - 1900;
	FechaNacim = mktime(&tm_nacimiento);
}