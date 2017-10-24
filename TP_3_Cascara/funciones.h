#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


typedef struct{
    char titulo[40];
    char genero[20];
    int  duracion;
    char descripcion[400];
    int  puntaje;
    char linkImagen[400];

}EMovie;


FILE *pArch, *nuevo;

int validarNumero(char mensaje[]);
void validarCadena(char mensaje[], char input[], int);
void validarCadenaAlfa(char mensaje[], char input[], int);


void inicializaMovie(EMovie*);

int agregarPelicula(EMovie*);
void borrarPelicula(EMovie*);
void modificarPelicula(EMovie*);
int buscarPelicula(EMovie*);

void generarPagina(EMovie*);
void iniciarFileBinario(char*, char*);
void mostrarPelicula(EMovie*);

int validaNumero(char dato[],int largo);
int validaLetra(char dato[],int largo);
int getInt(char mensaje[],char error[],int min,int max,int largo);
void getChar(char input[],char mensaje[],char error[],int largo);

#endif // FUNCIONES_H_INCLUDED
