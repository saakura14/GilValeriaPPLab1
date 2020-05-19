#ifndef NOTEBOOK_H_INCLUDED
#define NOTEBOOK_H_INCLUDED


#include "marca.h"
#include "Tipo.h"


typedef struct{

char modelo[20];
int idMarca;
int idTipo;
float precio;
int id;
int isEmpty;


}eNotebook;

void inicioNotebook(eNotebook notebooks[], int tamNotebook);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void DatosNotebook(eNotebook notebooks[] , int tamNotebook);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int menu();
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int buscarLibreNotebook(eNotebook notebooks[] , int tamNotebook);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void ingresoDatosNotebook(eNotebook notebooks[] , int tamNotebook);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int buscarNotebook(int id, eNotebook notebooks[], int tamNotebook);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void modificarNotebook(eNotebook notebooks[],int tamNotebook,eMarca marcas[] , int tamMarca , eTipo tipos[] , int tamTipo);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void printNotebook(eNotebook notebooks , eMarca marcas[] , int tamMarca , eTipo tipos[] , int tamTipo);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void mostrarNotebooks(eNotebook notebooks[],int tamNotebook,eMarca marcas[] , int tamMarca , eTipo tipos[] , int tamTipo);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void removerNotebook(eNotebook notebooks[],int tamNotebook,eMarca marcas[] , int tamMarca , eTipo tipos[] , int tamTipo);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int cargarDescripcionNotebook(char descripcion[] , eNotebook notebooks[] , int id , int tamNotebook);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */




#endif // NOTEBOOK_H_INCLUDED
