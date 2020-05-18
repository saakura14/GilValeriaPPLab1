#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

#include "Notebook.h"
#include "marca.h"
#include "Tipo.h"
#include "Servicios.h"

//Fecha

typedef struct{

int dia;
int mes;
int anio;

}eFecha;


//--------------------------------------------------------------


typedef struct{

int id;
int idNotebook;
int idServicio;
eFecha fecha;
int isEmpty;


}eTrabajo;

void inicioTrabajos(eTrabajo trabajos[], int tamTrabajos);
int buscarLibreTrabajos(eTrabajo trabajos[], int tamTrabajos);
void ingresoDatosTrabajo(eTrabajo trabajos[] , int tamTrabajos , eFecha auxFecha[],eNotebook notebooks[],int tamNotebook, eTipo tipos[] , int tamTipo,eMarca marcas[] , int tamMarca , eServicio servicios[] , int tamServicios);
void imprimirTrabajos(eTrabajo trabajos ,eNotebook notebooks[],int tamNotebook , eServicio servicios[] , int tamServicios);
void mostrarTrabajos(eTrabajo trabajos[] , int tamTrabajos ,eNotebook notebooks[],int tamNotebook , eServicio servicios[] , int tamServicios);

#endif // TRABAJO_H_INCLUDED


