#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

void agregaPersona(EPersona lista[],int tam,int indice);
int validaDNI(EPersona lista[],int tam,int documento);
void borrarPersona(EPersona lista[],int tam);
void ordenarPersona(EPersona lista[],int tam);
void mostrarPersona(EPersona lista[],int tam);
void graficarPersona(EPersona lista[],int tam);
void inicializaEstructura(EPersona lista[],int tam);
int validaNumero(char dato[],int largo);
int getInt(char mensaje[],char error[],int min,int max,int largo);
void getChar(char input[],char mensaje[],char error[],int largo);
int obtenerEspacioLibre(EPersona lista[],int tam);
int buscarPorDni(EPersona lista[], int dni,int tam);

#endif // FUNCIONES_H_INCLUDED
