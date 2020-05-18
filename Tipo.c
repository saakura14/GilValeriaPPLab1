#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Notebook.h"
#include "marca.h"
#include "Tipo.h"
#include "Servicios.h"
#include "Trabajo.h"



void imprimirTipo(eTipo tipos[] , int tamTipos)
{

  int i;

  printf("ID    TIPOS\n");
  for(i=0;i<tamTipos;i++)
  {

      printf("%d     %s\n",tipos[i].id,tipos[i].tipo);

  }

}

int cargarDescripcionTipos(char descripcion[] , eTipo tipos[] , int id , int tamTipos)
{

    int i , retorno;

    retorno = -1;

    for(i=0;i<tamTipos;i++)
    {
        if(tipos[i].id == id)
        {
            strcpy(descripcion,tipos[i].tipo);
            retorno = 1;
        }

    }

    return retorno;

}
