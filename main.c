#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0,flagA=0,flagB=0;
    float n1,n2,resultado;

    while(seguir=='s')
    {
        system("cls");
        if (flagA==0)
        {
            printf("1- Ingresar 1er operando (A=x)\n");
        } else {
        printf("1- Ingresar 1er operando (A=%.2f)\n",n1);
        }
        if (flagB==0)
        {
            printf("2- Ingresar 2do operando (B=y)\n");
        } else{
            printf("2- Ingresar 2do operando (B=%.2f)\n",n2);
        }
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");
        printf("\n Seleccione una opcion : ");

        scanf("%d",&opcion);

        if ((flagA==0 || flagB==0) && (opcion!=1 && opcion!=2 && opcion!=9))
        {
            printf("Debe ingresar ambos operandos para continuar\n");
        } else
        {
        switch(opcion)
        {
            case 1:
                {
                    n1=getfloat("\nIngrese el primer operando ");
                    flagA=1;
                    break;
                }
            case 2:
                {
                    n2=getfloat("\nIngrese el segundo operando ");
                    flagB=1;
                    break;
                }
            case 3:
                {
                    resultado=suma(n1,n2);
                    printf("El resultado de la suma es %.2f\n",resultado);
                    break;
                }
            case 4:
                {
                    resultado=resta(n1,n2);
                    printf("El resultado de la resta es %.2f\n",resultado);
                    break;
                }
            case 5:
                {
                    if (n2==0)
                    {
                        printf("\nMath Error, no se puede dividir por 0 ");
                    }else {
                    resultado=division(n1,n2);
                    printf("El resultado de la division es %.2f\n",resultado);
                    }
                    break;
                }
            case 6:
                {
                    resultado=multiplicacion(n1,n2);
                    printf("El resultado de la multiplicacion es %.2f\n",resultado);
                    break;
                }
            case 7:
                {
                    resultado=factorial(n1);
                    printf("El factorial de %.2f es %.2f\n",n1,resultado);
                    break;
                }
            case 8:
                {
                    resultado=suma(n1,n2);
                    printf("\nEl resultado de la suma es %.2f",resultado);

                    resultado=resta(n1,n2);
                    printf("\nEl resultado de la resta es %.2f",resultado);

                    if (n2==0)
                    {
                        printf("\nMath Error, no se puede dividir por 0");
                    }else {
                    resultado=division(n1,n2);
                    printf("\nEl resultado de la division es %.2f",resultado);
                    }

                    resultado=multiplicacion(n1,n2);
                    printf("\nEl resultado de la multiplicacion es %2.f",resultado);

                    resultado=factorial(n1);
                    printf("\nEl factorial de %.2f es %.2f\n",n1,resultado);
                    break;
                }
            case 9:
                {
                    seguir = 'n';
                    break;
                }
            default:
                printf("Ingrese una opcion valida\n");
        }
        }
        system("pause");
    }
}

