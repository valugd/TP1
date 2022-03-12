#include "cPaciente.h"
#include "cMedicos.h"
#include "cConsultorio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#define Npacientes 6
#define Nmedicos 4
int main()
{
	//pedimos memoria dinamica 
	cPaciente** Pacientes = new cPaciente *[Npacientes];
	cMedicos** Medicos = new cMedicos *[Nmedicos];
	cMedicos* aux = NULL;
	//creamos a los pacientes y a los medicos
	Pacientes[0] = new cPaciente("Castillo", "Solana", PROBLEMAS::CONSULTA_OJOS, "2236320104");
	Pacientes[1] = new cPaciente("Russo", "Nahuel", PROBLEMAS::IRRITACION_OCULAR, "2236329874");
	Pacientes[2] = new cPaciente("Diaz", "Martin", PROBLEMAS::MIODESOPSIAS, "22363243567");
	Pacientes[3] = new cPaciente("Manzuc", "Octavio", PROBLEMAS::TENSION, "2236530978");
	Pacientes[4] = new cPaciente("Villalba", "Ivan", PROBLEMAS::PALPITACIONES, "2236325468");
	Pacientes[5] = new cPaciente("Dillet", "Gian-Luca", PROBLEMAS::CONSULTA_CARDIO, "2236325462");
	Medicos[0] = new cMedicos("Torres", ESPECIALIDAD::CARDIOLOGO, 123456, 321, "Lara", false);
	Medicos[1] = new cMedicos("Jimenez", ESPECIALIDAD::OFTALMOLOGO, 789012, 432, "Carlos", false);
	Medicos[2] = new cMedicos("Rodriguez", ESPECIALIDAD::OFTALMOLOGO, 123456, 543, "Julieta", false);
	Medicos[3] = new cMedicos("Carter", ESPECIALIDAD::CARDIOLOGO, 123456, 654, "Steve", false);
	//creamos un consultorio
	cConsultorio* ConsultorioCanarias = new cConsultorio("Av. Olazabal 345", "8hs a 22hs", 123456, "4568976");
	//le asignamos los valores time
	Pacientes[0]->setFechaNacim(30, 9, 1999);
	Pacientes[1]->setFechaNacim(21, 1, 2000);
	Pacientes[2]->setFechaNacim(26, 8, 2005);
	Pacientes[3]->setFechaNacim(5, 12, 1986);
	Pacientes[4]->setFechaNacim(6, 11, 1967);
	Pacientes[5]->setFechaNacim(31, 10, 1969);
	Medicos[0]->setFechaNacim(4, 5, 1981);
	Medicos[1]->setFechaNacim(3, 4, 1961);
	Medicos[2]->setFechaNacim(13, 6, 1975);
	Medicos[3]->setFechaNacim(16, 8, 1979);
	//asignamos medicos en el consultorio 
	ConsultorioCanarias->arribar_medico(Medicos[0]);
	ConsultorioCanarias->arribar_medico(Medicos[1]);
	ConsultorioCanarias->arribar_medico(Medicos[2]);
	//entramos los pacientes al consultorio
	ConsultorioCanarias->entrar_paciente(Pacientes[3]);
	ConsultorioCanarias->entrar_paciente(Pacientes[2]);
	//imprimimos los datos de los medicos y el consultorio
	Medicos[0]->imprimirMedico();
	Medicos[2]->imprimirMedico();
	ConsultorioCanarias->imprimirConsultorio();
	//atendemos a los pacientes
	for (int i = 0; i < Npacientes - 1; ++i)
	{
		for (int j = 0; j < Nmedicos - 1; ++j)
		{
			if (Pacientes[i] == Medicos[j]->getPaciente())
			{
				Medicos[j]->atender_paciente(Pacientes[i]);
				break;
			}
		}
	}
	//si ambos medicos estan ocupados
		for (int j = 0; j < Nmedicos - 1; ++j)
		{
			if (Medicos[j]->getOcupado==true && Medicos[j+1]->getOcupado==true)
			{
				printf("No se pude atender al paciente en estos mometos, por favor intentelo mas tarde");
			}
		}
	
	//imrpmimos datos 
	Medicos[0]->imprimirMedico();
	Medicos[2]->imprimirMedico();
	string NombreMedico;
	//eliminamos al medico del consultorio
	for (int i = 0; i < Nmedicos - 1; ++i)
	{
		if (Medicos[i]->getOcupado() == true)
		{
			NombreMedico = Medicos[i]->getApellido() + "," + Medicos[i]->getNombre();
			aux = ConsultorioCanarias->retirar_medico(NombreMedico);
			Medicos[i] = aux;
		}
	}
	//impimimos datos
	Pacientes[2]->imprimirPaciente();
	ConsultorioCanarias->imprimirConsultorio();
	Medicos[0]->imprimirMedico();
	Medicos[2]->imprimirMedico();
	//borramos memoria dinamica 
	delete[] Medicos;
	delete[] Pacientes;
	delete ConsultorioCanarias;
	delete aux;
	

}