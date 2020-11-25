#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Declaración de variables
    int filas = 0;
    char simbolo;

    //Solicitamos al usuario ingresas cantidad de filas
    printf("Ingresa la cantidad de filas:  ");
    scanf("%i", &filas);
    puts("\n");

    // Comprobamos si el numero ingresado es par, sino vuelve a preguntar hasta que se cumpla esta condición
    // We check if the numbe    r entered is even, if it does not ask again until this condition is met

    while(filas%2 == 0)
    {
        printf("Ingresa un numero impar: ");
        scanf("%i", &filas);
        puts("\n");
    }

    printf("Ingrese un caracter que desee para el rombo: ");
    scanf(" %c", &simbolo);
    system("cls");
    // Utilizamos dos ciclos for para generar dos triangulos, el segundo de forma invertida

    // Primer ciclo for para triangulo de 1 hasta la mitad de filas + 1

    for (int i = 1; i <= filas; i += 2)//Aumentamos la cantidad de pasos en 2 para llegar hasta la mitad
    {
        // imprimimos la cantidad de espacios vacios hacia la derecha
        for (int j = filas + 1; j >= i ; j-= 2)
        {
            printf(" ");
        }

        //imprimimos cantidad (*) hasta hasta que k sea igual a i
        for(int k = 1; k <= i; k++)
        {
            printf("%c", simbolo);
        }

        printf("\n");
    }

    //Segundo ciclo for para generar el triangulo inverso
    for (int i = filas; i >= 1; i -= 2)
    {

        for (int j = i; j <= filas+2; j+=2)
        {
            printf(" ");
        }
        for (int k = i-2; k > 0; k--)
        {
            printf("%c", simbolo);
        }
        printf("\n");
    }

    system("pause");

}


