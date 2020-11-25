#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>



int main()
{
    /* Declaración de variables.
        num_E = numero elegido por el usuario
        num_A = numero aleatorio
    */
    int num_E, num_A, control = 0, intentos = 1;


    // Generamos un bucle while para control de reinicio del juego, siempre y cuando el valor de "control" sea diferente a 0
    while(!control)
    {

        system("cls");
        srand(time(NULL)); // Instruccion que inicializa el generador de numeros aleatorios
        num_A = 1 + rand() % (101 - 1); // Asignamos a num_A un valor entre el rango de 1 a 100

        // Indicamos al usuario que ingrese un numero
        puts("\n == Juego Adivina un numero == ");
        puts("Ingresa un numero:  ");
        scanf("%d", &num_E);

        //Comprobamos si el numero ingresado es diferente al numero aleatorio para ingresar al bucle
        while(num_E != num_A)
        {
            // Si el num_E es mayor a num_A indicamos que ingrese un numero mas pequeño y sumamos uno (1) a num intentos
            if (num_E > num_A)
            {
                printf("Ingresa un numero mas pequeño:  ");
                intentos++;
            }
            else
            // Si el num_E es menor a num_A indicamos que ingrese un numero mas alto y sumamos uno (1) a num intentos
            {
                printf("Ingresa un numero mas alto:     ");
                intentos++;
            }
            scanf("%d", &num_E);
            continue;
        }

        // Si el num_E es igual num_A, Felicitamos, mostramos resultados y preguntamos si desea volver a jugar.
        if (num_E == num_A)
        {
            printf("Has Ganado, Felicitaciones\n");
            printf("Numero aleatorio = %d y numero Elegido = %d\n", num_A, num_E);
            printf("El numero total de intentos son: %d \n\n", intentos);

            //Asignamos a la variable "control" el valor ingresado por el usuario
            printf("\nDeseas jugar de nuevo? (s = 0 / n = 1): ");
            scanf("%i", &control);

        }
    }
    return 0;
}

