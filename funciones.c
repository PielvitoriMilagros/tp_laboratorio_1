#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/**
* \brief Solicita un numero al usuario
* \param mensaje Es el mensaje a ser mostrado
* \return El numero ingresado
*/
float getfloat(char mensaje[])
{
    float num;
    printf("%s ",mensaje);
    scanf("%f",&num);
    return num;
}

/**
* \brief Suma dos numeros previamente ingresados
* \param num1 Numero ingresado por el usuario
* \param num2 Numero ingresado por el usuario
* \return La suma de los dos numeros
*/
float suma(float num1, float num2)
{
    float res;
    res=num1+num2;
    return res;
}

/**
* \brief Resta dos numeros previamente ingresados
* \param num1 Numero ingresado por el usuario
* \param num2 Numero ingresado por el usuario
* \return La resta de los dos numeros
*/
float resta(float num1,float num2)
{
    float res;
    res=num1-num2;
    return res;
}

/**
* \brief Divide dos numeros previamente ingresados
* \param num1 Numero ingresado por el usuario
* \param num2 Numero ingresado por el usuario
* \return La division de los dos numeros
*/
float division(float num1, float num2)
{
    float res;
    res=num1/num2;
    return res;
}

/**
* \brief Producto entre dos numeros previamente ingresados
* \param num1 Numero ingresado por el usuario
* \param num2 Numero ingresado por el usuario
* \return El producto entre los dos numeros
*/
float multiplicacion(float num1,float num2)
{
    float res;
    res=num1*num2;
    return res;
}

/**
* \brief Calcula el factorial de un numero previamente ingresado
* \param num1 Numero ingresado por el usuario
* \return El resultado del factorial del numero
*/
float factorial(float num1)
{
    float res;
    int i;
    res=num1;
    for(i=num1-1;i>0;i--)
    {
    res=res*i;
    }
    return res;
}
