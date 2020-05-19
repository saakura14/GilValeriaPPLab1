#include <stdio.h>
#include <stdlib.h>

#include <ctype.h>
#include "notebook.h"
#include "marca.h"
#include "tipo.h"
#include "servicios.h"
#include "trabajo.h"


#define TAMMARCA 4
#define TAMTIPOS 4
#define TAMSERVICIOS 4
#define TAMNOTEBOOKS 4
#define TAMTRABAJOS 4

int main()
{

    char seguir = 's';
    int opcion;
    int trigger = 1;
    eFecha fechas[TAMTRABAJOS];
    eMarca marca[TAMMARCA] = { {1000,"COMPAQ"},{1001,"ASUS"},{1002,"ACER"},{1003,"HP"} };
    eTipo tipos[TAMTIPOS] = { {5000,"GAMER"},{5001,"DISENIO"},{5002,"ULTRABOOK"},{5003,"NORMALITA"} };
    eServicio servicios[TAMSERVICIOS] = { {"BATERIA",250,20000},{"ANTIVIRUS",300,20001},{"ACTUALIZACION",400,20002},{"FUENTE",600,20003} };


        eNotebook notebooks[TAMNOTEBOOKS];

        inicioNotebook(notebooks,TAMNOTEBOOKS);

        DatosNotebook(notebooks,TAMNOTEBOOKS);

        eTrabajo trabajos[TAMTRABAJOS];

        inicioTrabajos(trabajos,TAMTRABAJOS);




    do{


        opcion = menu();

        switch(opcion)
        {
        case 1:
        system("cls");
        ingresoDatosNotebook(notebooks,TAMNOTEBOOKS);

        trigger = 1;
        break;

        case 2:

        if(trigger==1){

            system("cls");

          modificarNotebook(notebooks,TAMNOTEBOOKS,marca,TAMMARCA,tipos,TAMTIPOS);
        }
        else
        {
            printf("no hay notebooks ingresadas.\n");
        }
        break;

        case 3:
         if(trigger==1){
            system("cls");
            mostrarNotebooks(notebooks,TAMNOTEBOOKS,marca,TAMMARCA,tipos,TAMTIPOS);
        }
        else
        {
            printf("no hay notebooks ingresadas.\n");
        }
        break;

        case 4:
         if(trigger==1){
            system("cls");
            removerNotebook(notebooks,TAMNOTEBOOKS,marca,TAMMARCA,tipos,TAMTIPOS);
        }
        else
        {
            printf("No hay notebooks ingresadas.\n");
        }
        break;

        case 5:
         if(trigger==1){
            system("cls");
            imprimirMarcas(marca,TAMMARCA);
        }
        else
        {
            printf("No hay marcas  ingresados.\n");
        }
        break;

        case 6:
         if(trigger==1){
            system("cls");
            imprimirTipo(tipos,TAMTIPOS);
        }
        else
        {
            printf("No hay tipos ingresados.\n");
        }
        break;

        case 7:
         if(trigger==1){
            system("cls");
            imprimirServicios(servicios,TAMSERVICIOS);
        }
        else
        {
            printf("No hay servicios ingresados.\n");
        }
        break;

        case 8:
         if(trigger==1){
            system("cls");
            ingresoDatosTrabajo(trabajos,TAMTRABAJOS,fechas,notebooks,TAMNOTEBOOKS,tipos,TAMTIPOS,marca,TAMMARCA,servicios,TAMSERVICIOS);
        }
        else
        {
            printf("no hay trabajos ingresados.\n");
        }
        break;


        case 9:
         if(trigger==1){
            system("cls");
            mostrarTrabajos(trabajos,TAMTRABAJOS,notebooks,TAMNOTEBOOKS,servicios,TAMSERVICIOS);
            }
        else
        {
            printf("No hay servicios ingresados.\n");
        }
        break;

        case 10:
        seguir = 'n';
        break;
        default:
        printf(" - - ERROR - - No es una opcion.\n");
        break;

        }

        system("pause");
        system("cls");

    }while(seguir=='s');


    return 0;


}
