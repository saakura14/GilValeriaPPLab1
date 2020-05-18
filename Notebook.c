#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Datos.h"
#include "Notebook.h"
#include "marca.h"
#include "Tipo.h"
#include "Servicios.h"
#include "Trabajo.h"


static int generarIdNotebook()
{
	static int contadorId=100;
	contadorId++;
	return contadorId;
}


void initNotebook(eNotebook notebooks[], int tamNotebook)
{
    int i;

    for(i=0; i<tamNotebook; i++)
    {
        notebooks[i].isEmpty = 1;

    }
}


void DatosNotebook(eNotebook notebooks[] , int tamNotebook)
{

int i;



    for(i=0 ; i<tamNotebook ; i++)
    {

        strcpy(notebooks[i].modelo,modelos[i]);
        fflush(stdin);
        notebooks[i].id = ids[i];
        notebooks[i].idMarca = idMarca[i];
        notebooks[i].idTipo = idTipo[i];
        notebooks[i].precio = precios[i];
         notebooks[i].isEmpty = 0;

    }

}

int menu()
{

    int opcion = 0;

    printf(" - - - BIENVENIDO -  MENU DE OPCIONES - - -\n\n ");
    printf("1.INGRESAR NOTEBOOK\n");
    printf("2.MODIFICAR NOTEBOOK\n");
    printf("3.LISTAR NOTEBOOK\n");
    printf("4.REMOVER NOTEBOOK\n");
    printf("5.LISTAR MARCAS\n");
    printf("6.LISTAR TIPOS\n");
    printf("7.LISTAR SERVICIOS\n");
    printf("8.INGRESAR TRABAJOS\n");
    printf("9.MOSTRAR TRABAJOS\n");
    printf("10.SALIR\n\n");


    printf("Elija una opcion: ");
    scanf("%d",&opcion);

    return opcion;


}

int buscarLibreNotebook(eNotebook notebooks[] , int tamNotebook)
{
    int retorno = -1;
    int i;

    for(i=0; i<tamNotebook; i++)
    {
        if(notebooks[i].isEmpty == 1)
        {
            retorno = i;
            break;
        }

    }

    return retorno;

}

void ingresoDatosNotebook(eNotebook notebooks[] , int tamNotebook)
{

    int i = 0;
    int indice;
    int id = generarIdNotebook();

    indice = buscarLibreNotebook(notebooks,tamNotebook);

    if(indice == -1)
    {
        printf("NO HAY MAS LUGAR.\n\n");
    }

    else
    {

        printf("%d.Ingrese modelo: ",i+1);
        fflush(stdin);
        gets(notebooks[indice].modelo);
        fflush(stdin);

        printf("%d.Ingrese idMarca: ",i+1);
        scanf("%d",&notebooks[indice].idMarca);
        fflush(stdin);

        printf("%d.Ingrese idTipo: ",i+1);
        scanf("%d",&notebooks[indice].idTipo);
        fflush(stdin);

        printf("%d.Ingrese precio: ",i+1);
        scanf("%f",&notebooks[indice].precio);
        fflush(stdin);

        fflush(stdin);

        notebooks[indice].id = id;

        notebooks[indice].isEmpty = 0;


        printf("\n");
    }

}

int buscarNotebook(int id, eNotebook notebooks[], int tamNotebook)
{
    int i;
    int retorno = -1;

    for(i=0; i<tamNotebook; i++)
    {
        if(notebooks[i].id == id && notebooks[i].isEmpty == 0)
        {
            retorno = i;
            break;
        }
    }



    return retorno;

}



void printNotebook(eNotebook notebooks , eMarca marcas[] , int tamMarca , eTipo tipos[] , int tamTipo)
{

    char descripcionMarca[20];
    char descripcionTipo[20];

    cargarDescripcionMarcas(descripcionMarca,marcas,notebooks.idMarca,tamMarca);
    cargarDescripcionTipos(descripcionTipo,tipos,notebooks.idTipo,tamTipo);

    printf("  %d  %10s %10s   %10s    %.2f   \n",notebooks.id,notebooks.modelo,descripcionMarca,descripcionTipo,notebooks.precio);



}


void mostrarNotebooks(eNotebook notebooks[],int tamNotebook,eMarca marcas[] , int tamMarca , eTipo tipos[] , int tamTipo)
{
    int trigger = 0;
    int i;

    printf("---------------------------------------------------------------------------\n");
    printf("  ID      MODELO        MARCA       TIPO         PRECIO\n");
    for(i=0; i<tamNotebook; i++)
    {

        if(notebooks[i].isEmpty == 0)
        {
            printNotebook(notebooks[i],marcas,tamMarca,tipos,tamTipo);
            trigger = 1;
        }


    }

    if(trigger==0)
    {
        printf("No hay notebooks.\n");
    }

}





void modificarNotebook(eNotebook notebooks[],int tamNotebook,eMarca marcas[] , int tamMarca , eTipo tipos[] , int tamTipo)
{
    int numero = 0;
    int id = 0;
    float precio;
    float tipo;

    char respuesta;

    mostrarNotebooks(notebooks,tamNotebook,marcas,tamMarca,tipos,tamTipo);

    printf("\nIngrese el ID de la notebook a modificar: ");
    scanf("%d",&numero);
    fflush(stdin);


    if((id = buscarNotebook(numero,notebooks,tamNotebook)) < 0)
    {
        printf("\nNo se encontro empleado.\n");

    }

    else
    {
        printf("Usuario encontrado.\n");
        system("pause");
        system("cls");


        printf("MODIFICAR:\n1.Precio\n2.Tipo\nElija una opcion: ");
        scanf("%d",&numero);

        switch(numero)
        {

        case 1:
            printf("Ingrese nuevo precio: ");
            scanf("%f",&precio);

            printf("Desea realizar el cambio?: ");
            fflush(stdin);
            scanf("%c",&respuesta);
            fflush(stdin);

            if(respuesta=='s' || respuesta=='S')
            {

                notebooks[id].precio = precio;
                printf("Cambio realizado.\n");

            }

            else
            {
                printf("Operacion cancelada\n");
            }

            break;

        case 2:
            printf("ingrese nuevo idTipo: ");
            scanf("%f",&tipo);

            printf("Desea realizar el cambio?: ");
            fflush(stdin);
            scanf("%c",&respuesta);
            fflush(stdin);

            if(respuesta=='s' || respuesta=='S')
            {

                notebooks[id].idTipo = tipo;
                printf("Cambio realizado.\n");

            }

            else
            {
                printf("Operacion cancelada.\n");
            }

            break;


        default:
            printf("No es una opcion valida.\n");
            break;

        }

    }


    printf("\n");


}


void removerNotebook(eNotebook notebooks[],int tamNotebook,eMarca marcas[] , int tamMarca , eTipo tipos[] , int tamTipo)
{
    int numero = 0;
    int id = 0;
    char respuesta;

    mostrarNotebooks(notebooks,tamNotebook,marcas,tamMarca,tipos,tamTipo);

    printf("Ingrese ID de notebook a remover: ");
    scanf("%d",&numero);

    if((id = buscarNotebook(numero,notebooks,tamNotebook)<0))
    {
        printf("No se encontro el ID\n");
    }

    else
    {

        printf("Seguro desea remover a la notebook? %s:",notebooks[id].modelo);
        fflush(stdin);
        scanf("%c",&respuesta);
        fflush(stdin);

        if(respuesta=='s' || respuesta=='S')
        {
            notebooks[id].isEmpty = 1;
            printf("Empleado removido.\n");
        }
        else
        {
            printf("Operacion cancelada.\n");
        }
    }

    printf("\n");

}


int cargarDescripcionNotebook(char descripcion[] , eNotebook notebooks[] , int id , int tamNotebook)
{

    int i , retorno;

    retorno = -1;

    for(i=0;i<tamNotebook;i++)
    {
        if(notebooks[i].id == id)
        {
            strcpy(descripcion,notebooks[i].modelo);
            retorno = 1;
        }

    }

    return retorno;

}
