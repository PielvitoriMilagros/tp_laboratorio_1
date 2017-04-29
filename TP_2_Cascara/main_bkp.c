#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define E 3

void agregaPersona(EPersona lista[],int tam,int indice);
void inicializaEstructura(EPersona lista[],int tam);
int validaNumero(char dato[],int largo);

int main()
{
    char seguir='s';
    int opcion=0,libre=0,i;
    EPersona lista[E];

    inicializaEstructura(lista,E);

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                libre=obtenerEspacioLibre(lista,E);
                if(libre==-1)
                {
                     printf("No queda mas lugar\n");
                }else
                {
                    agregaPersona(lista,E,libre);
                }
                break;
            case 2:
                break;
            case 3:
                printf("persona\n");
                for(i=0;i<E;i++)
                {
//                    if(lista[i].estado!=0)
//                        {
                            printf("%d\t%d\t%s \n",lista[i].dni,lista[i].estado,lista[i].nombre);
//                        }
                }
                break;
            case 4:
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("Opcion incorrecta");
                system("pause");
                break;
        }
    }
    return 0;
}

void inicializaEstructura(EPersona lista[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        lista[i].nombre['\0']=0;
        lista[i].edad=0;
        lista[i].estado=0;
        lista[i].dni=0;
    }
}

int obtenerEspacioLibre(EPersona lista[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        if(lista[i].estado==0)
        {
            return i;
        }
    }
    return -1;
}

void agregaPersona(EPersona lista[],int tam,int indice)
{
    int i,valeDoc,documento,valeNom,valeEdad;
    char auxDoc[8],auxNombre[50],edad[3];

    printf("Ingrese el DNI: ");
    fflush(stdin);
    scanf("%s",auxDoc);
    valeDoc=validaNumero(auxDoc,8);
    if(valeDoc==0)
    {
        printf("El documento es invalido\n");
        return;
    }
    documento=atoi(auxDoc);
    lista[indice].dni=documento;
    lista[indice].estado=1;

    printf("Ingrese su nombre: ");
    fflush(stdin);
    gets(auxNombre);
    valeNom=validaLetra(auxNombre,50);
    if(valeNom==0)
    {
        printf("El nombre es invalido\n");
        return;
    }
    strcpy(lista[indice].nombre,auxNombre);

    printf("Ingrese su edad: ");
    scanf("%s",&edad);
    valeEdad=validaNumero(edad,3);
    if(valeEdad==0)
    {
        printf("La edad es invalida\n");
        return;
    }



}

int validaLetra(char dato[],int largo)
{
    int i,largoDato,flag=0;
    largoDato=strlen(dato);
    if((largoDato>largo) && (largo!=0))
    {
        return 0;
    }
    for(i=0;i<largoDato;i++)
    {
        if((isdigit(dato[i])) || ((dato[i]<'a' || dato[i]>'z')))
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        return 0;
    }
    return 1;
}

int validaNumero(char dato[],int largo)
{
    int i,largoDato,flag=0;
    largoDato=strlen(dato);
    if((largoDato>largo) && (largo!=0))
    {
        return 0;
    }
    for(i=0;i<largoDato;i++)
    {
        if(!(isdigit(dato[i])))
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        return 0;
    }
    return 1;
}
