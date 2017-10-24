#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"

/**
 * Inicia la estructura lista
 * @param Emovie *lista el array se pasa como parametro.
 */
void inicializaMovie(EMovie *lista)
{
    lista->titulo['\0']=0;
    lista->genero['\0']=0;
    lista->duracion=0;
    lista->descripcion['\0']=0;
    lista->puntaje=0;
    lista->linkImagen['\0']=0;
}


/**
 *  Agrega una pelicula al archivo binario
 *  @param lista estructura
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie *lista)
{
    char titAux[40],auxGenero[20],auxDesc[400],link[400];
    iniciarFileBinario("bin.dat","ab+");

    getChar(titAux,"\nIngrese el titulo de la pelicula: ","\nTitulo invalido",40);
    rewind(pArch);
    while(!feof(pArch))
    {
        fread(&lista,sizeof(EMovie),1,pArch);
        if(strcmp(titAux,lista->titulo)==0)
        {
            printf("La pelicula ya existe\n");
            return main();
        }
    }
    strcpy(lista->titulo,titAux);

    getChar(auxGenero,"\nIngrese genero: ","\nGenero invalido",20);
    strcpy(lista->genero,auxGenero);

    lista->duracion=getInt("\nIngrese duracion en minutos: ","\nValor invalido",1,240,3);

    getChar(auxDesc,"\nIngrese descripcion: ","\nPor favor utilice letras",400);
    strcpy(lista->descripcion,auxDesc);

    lista->puntaje=getInt("\nIngrese puntaje para la pelicula (1 a 10): ","\nDebe ser de 1 a 10",1,10,2);

    printf("\nIngrese link de imagen: ");
    fflush(stdin);
    gets(link);
    strcpy(lista->linkImagen,link);

    fwrite(&lista,sizeof(EMovie),1,pArch);
    fclose(pArch);
    return 1;
}



/**
 * Muestra en pantalla el listado de peliculas agregadas
 */
void mostrarPelicula(EMovie *lista)
{

    iniciarFileBinario("bin.dat","rb");
    while(!feof(pArch))
    {
        fread(&lista,sizeof(EMovie),1,pArch);
        if(!feof(pArch))
            printf("\n%s\n%s\n%d\n%d\n%s\n\n",lista->titulo,lista->genero,lista->duracion,lista->puntaje,lista->descripcion);
    }
    fclose(pArch);
}


/**
 *  Busca en el archivo binario la estructura de la pelicula ingresada
 */
int buscarPelicula(EMovie *lista)
{
    char titAux[40];
    iniciarFileBinario("bin.dat","rb+");
    getChar(titAux,"\nIngrese el titulo de la pelicula: ","\nTitulo invalido",40);
    rewind(pArch);
    while(!feof(pArch))
    {

        fread(&lista,sizeof(EMovie),1,pArch);
        if(strcmp(titAux,lista->titulo)==0)
        {
            printf("\n\n%s\n%s\n%d\n%d\n%s\n",lista->titulo,lista->genero,lista->duracion,lista->puntaje,lista->descripcion);
            return 1;
        }
        else if(feof(pArch))
        {
            printf("\nNo se encuentra la pelicula\n");
            break;
        }
    }
    return 0;
}



/**
 *  Borra una pelicula del archivo binario
 */
void borrarPelicula(EMovie *lista)
{
    char opcion;
    char titAux[40];
    iniciarFileBinario("bin.dat","rb+");
    getChar(titAux,"\nIngrese el titulo de la pelicula: ","\nTitulo invalido",40);
    rewind(pArch);
    while(!feof(pArch))
    {
        fread(&lista,sizeof(EMovie),1,pArch);
        if(strcmp(titAux,lista->titulo)==0)
        {
            printf("\n\n%s\n%s\n%d\n%d\n%s\n",lista->titulo,lista->genero,lista->duracion,lista->puntaje,lista->descripcion);
            break;
        }
        else if(feof(pArch))
        {
            printf("\nNo se encuentra la pelicula\n");
            return;
        }
    }

    printf("\nDesea eliminar la pelicula?: ");
    opcion=getche();
    if(opcion=='s')
    {
        nuevo=fopen("nuevo.dat","wb");
        if (nuevo==NULL)
        {
            perror("nuevo.dat");
            exit(1);
        }

        rewind(pArch);
        while(!feof(pArch))
        {
            fread(&lista,sizeof(EMovie),1,pArch);

            if(!feof(pArch))
            {
                if(strcmp(titAux,lista->titulo)!=0)
                {
                    fflush(stdin);
                    fwrite(&lista,sizeof(EMovie),1,nuevo);
                }
            }
            if(feof(pArch))
                break;
        }


        printf("\nSe elimino la pelicula\n");

        fclose(pArch);
        fclose(nuevo);
        remove("bin.dat");
        rename("nuevo.dat","bin.dat");
    }
    return;
}


/**
 *  Modifica una pelicula del archivo binario
 */
void modificarPelicula(EMovie *lista)
{
    char modifica;
    int opcion;

    printf("\nDesea modificar la pelicula? (s/n): ");
    modifica=getche();
    getch();
    if(modifica=='s')
    {
        printf("\nElija el campo a modificar:\n"
               "1-Titulo\n"
               "2-Genero\n"
               "3-Duracion\n"
               "4-Descripcion\n"
               "5-Puntaje\n"
               "6-Link de imagen\n");
        opcion=getInt("Ingrese una opcion: ","Opcion incorrecta\n",1,6,1);

        switch(opcion)
        {
        case 1:
        {
            getChar(lista->titulo,"\nIngrese nuevo titulo de la pelicula: ","\nTitulo invalido",40);
            break;
        }
        case 2:
        {
            getChar(lista->genero,"\nIngrese genero: ","\nGenero invalido",20);
            break;
        }
        case 3:
        {
            do
            {
                lista->duracion=getInt("\nIngrese duracion en minutos: ","\nValor invalido",1,240,3);
            }
            while(lista->duracion<=0);
            break;
        }
        case 4:
        {
            getChar(lista->descripcion,"\nIngrese nueva descripcion: ","\nPor favor utilice letras",400);
            break;
        }
        case 5:
        {
            lista->puntaje=getInt("\nIngrese puntaje para la pelicula (1 a 10): ","\nDebe ser de 1 a 10",1,10,2);
            break;
        }
        case 6:
        {
            printf("\nIngrese nuevo link de imagen: ");
            fflush(stdin);
            gets(lista->linkImagen);
            break;
        }
        }

        fseek(pArch,(-1)*sizeof(EMovie),SEEK_CUR);
        fflush(stdin);
        fwrite(&lista,sizeof(EMovie),1,pArch);
        printf("\nPelicula actualizada\n");
        fclose(pArch);
    }
    return;
}


/**
 *  Genera archivo html a partir de las peliculas cargadas en el archivo binario.
 */
void generarPagina(EMovie *lista)
{
   FILE *pHtml;
   char cadena1[300];
   char cadena2[30];
   char cadena3[30];
   char cadena4[25];
   char cadena5[25];
   char cadena6[25];
   char cadena7[20];

   sprintf(cadena1,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='");
   sprintf(cadena2,"alt=''></a><h3><a href='#'>");
   sprintf(cadena3,"</a></h3><ul><li>Género: ");
   sprintf(cadena4,"</li><li>Puntaje: ");
   sprintf(cadena5,"</li><li>Duración: ");
   sprintf(cadena6,"</li></ul><p>");
   sprintf(cadena7,"</p></article>");

   iniciarFileBinario("bin.dat","rb");

   if((pHtml=fopen("peliculas.html" , "w"))==NULL)
   {
       printf("\nEl archivo no puede ser abierto");
       exit(1);
   }
   else
   {
       rewind(pArch);
       while(!feof(pArch))
       {
       fread(&lista,sizeof(EMovie),1,pArch);
       if(!feof(pArch))
       {
       fprintf(pHtml,cadena1);
       fprintf(pHtml,lista->linkImagen);
       fprintf(pHtml,cadena2);
       fprintf(pHtml,lista->titulo);
       fprintf(pHtml,cadena3);
       fprintf(pHtml,lista->genero);
       fprintf(pHtml,cadena4);
       fprintf(pHtml, "%d", lista->puntaje);
       fprintf(pHtml,cadena5);
       fprintf(pHtml, "%d", lista->duracion);
       fprintf(pHtml,cadena6);
       fprintf(pHtml,lista->descripcion);
       fprintf(pHtml,cadena7);
       }
       }
       printf("\nArchivo generado\n");
   }
    fclose(pHtml);
    fclose(pArch);
}


/**
*  Genera o abre el archivo binario
*  @param nombre nombre del archivo
*  @param modo modo en que se abre el archivo
*/
void iniciarFileBinario(char *nombre, char *modo)
{
    int var;
    if((pArch=fopen(nombre, modo))==NULL)
    {
        perror("bin.dat");
        printf("\nEl archivo no puede ser abierto");
        exit(1);
    }
}



/**
 * Valida que el ingreso sea una letra
 * @param dato el dato a validar
 * @param largo dimensión del dato a validar
 * @return 1 si es letra, !1 si no lo es
 */
int validaLetra(char dato[],int largo)
{
    int i,largoDato,flag=0;
    largoDato=strlen(dato);
    if((largoDato>largo) && (largo!=0))
    {
        return 0;
    }
    for(i=0; i<largoDato; i++)
    {
        if((isdigit(dato[i])) && ((dato[i]<'a' || dato[i]>'z')) && (dato[i]!=" "))
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

/**
 * Valida que el ingreso sea un número
 * @param dato el dato a validar
 * @param largo dimensión del dato a validar
 * @return 1 si es número, !1 si no lo es
 */
int validaNumero(char dato[],int largo)
{
    int i,largoDato,flag=0;
    largoDato=strlen(dato);
    if((largoDato>largo) && (largo!=0))
    {
        return 0;
    }
    for(i=0; i<largoDato; i++)
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

/**
 * Solicita el ingreso y valida que sea int
 * @param mensaje Mensaje a mostrar por pantalla
 * @param error Mensaje a mostrar en caso de error
 * @param min Numero minimo que se puede ingresar
 * @param max Numero maximo que se puede ingresar
 * @param largo Largo maximo que puede tener el ingreso
 * @return el numero ingresado
 */
int getInt(char mensaje[],char error[],int min,int max,int largo)
{

    int flag,valido,num;
    char auxNum[largo];
    do
    {
        flag=0;
        printf(mensaje);
        fflush(stdin);
        scanf("%s",auxNum);
        valido=validaNumero(auxNum,largo);
        if(valido!=0)
        {
            num=atoi(auxNum);
            if(num>=min && num<=max)
            {
                return num;
            }
            else
            {
                printf(error);
                flag++;
            }
        }
        else
        {
            printf(error);
            flag++;
        }
    }    while(flag!=0);
}

/**
 * Solicita el ingreso y valida que sea char
 * @param input el dato a validar
 * @param mensaje Mensaje a mostrar por pantalla
 * @param error Mensaje a mostrar en caso de error
 * @param largo Largo maximo que puede tener el ingreso
 */
void getChar(char input[],char mensaje[],char error[],int largo)
{
    int flag,valido;
    do
    {
        flag=0;
        printf(mensaje);
        fflush(stdin);
        gets(input);
        valido=validaLetra(input,largo);
        if(valido==0)
        {
            printf(error);
            flag++;
        }
    }
    while(flag!=0);
}
