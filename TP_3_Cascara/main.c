#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"




int main()
{
    char seguir='s';
    int opcion=0;
    EMovie lista;
    inicializaMovie(&lista);

    while(seguir=='s')
    {
        system("cls");
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        opcion=getInt("Ingrese una opcion: ","Opcion incorrecta\n",1,5,1);

        switch(opcion)
        {
        case 1:
        {
            if(agregarPelicula(&lista)==1)
            {
                printf("\nLa pelicula fue agregada con exito!\n\n");
                system("pause");
                break;
            }
            else
            {
                printf("La pelicula no pudo ser agregada\n\n");
                system("pause");
                break;
            }
        }
        case 2:
        {
            mostrarPelicula(&lista);
            borrarPelicula(&lista);
            system("pause");
            break;
        }
        case 3:
        {
            mostrarPelicula(&lista);
            if(buscarPelicula(&lista))
                modificarPelicula(&lista);
            system("pause");
            break;
        }
        case 4:
        {
            generarPagina(&lista);
            system("pause");
            break;
        }
        default:
        {
            seguir = 'n';
            break;
        }
        }
    }
    return 0;
}
