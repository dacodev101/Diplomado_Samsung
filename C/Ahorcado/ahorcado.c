#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOPE 50

int main()
{
	//DECLARACI�N DE VARIABLES
	char palabras [TOPE+1]; // Palabra ingresada por usuario
	unsigned short i; // Variable que utilizamos para controlar ciclos for
	unsigned short fallos = 0, logros = 0;
	unsigned short bandera;
	unsigned char intento;
	unsigned char reinicio[3] = {'s','i','\0'};
	unsigned char pista [TOPE+1];
	unsigned short num_espacios = 0;

	// INTERFEZ DE USUARIO UNO

	while (strcmp(reinicio, "si") == 0)
	{
		printf(" *** EL AHORCADO ESTA POR INICIAR ***");
		printf("\n*** Eres el jugador numero uno, reta a tu companiero ***");
		printf("\nIngresa una palabra o frase: ");
		gets(palabras);

		//Creamos un arreglo donde solo se tenga el tamaño de la palabra ingresada
		unsigned char elegida [strlen(palabras)];
		strcpy(elegida,palabras);

		//Creamos otro arreglo de tamaño de elegida, para poder mostrar al usuario cuantas letras contiene la palabra escondida
		unsigned char oculta[strlen(elegida)];

		//Generamos un ciclo for para que por cada letra que contenga se asigne un "_"
		for (i = 0; i < strlen(elegida) ; i++)
		{
			oculta[i] ='_';
		}

		//Generamos otro ciclo for para que por cada espacio en "elegida" se asigne al array "oculta"
		for ( i = 0; i < strlen(elegida); i++)
		{
			if (elegida [i] == ' '){
				oculta [i] = ' ';
				num_espacios++;
			}
		}

		printf("Puedes agregar una pista para tu companiero a continuación: ");
		gets(pista);
		system("cls");

		//Interfaz para el jugador 2

		printf(" *** Bienvenido al juego, tienes un bonus de tu companiero: ");
		puts(pista);

		while (fallos < 5 && logros < (strlen(oculta) - num_espacios))
		{
			bandera = 0;


			printf("\n Ingrese una letra: ");
			scanf("%c", &intento);
			fflush(stdin);
			system("cls");


			for (i = 0; i < strlen(elegida); i++)
			{
				if (intento == elegida[i] && intento != oculta[i])
				{
					bandera = 1;
					oculta[i] = intento; // reemplaza el "_" por la letra correspondiente
					logros = logros + 1;
				}

			}

			if (bandera == 0)
			{
				fallos = fallos + 1;
				printf("\nLa palabra no esta");
			}

			printf("\nNumero de fallos:  %d", fallos);
			printf("\nLetras encontradas:  %s", oculta);
			fflush(stdin);
		}

		if (fallos == 5)
		{
			system("cls");
			printf(" *** GAME OVER ***");
			puts(" ");
			printf("Letras encontradas: %s", oculta);
			fallos = 0, logros = 0;
		}
		if(logros == strlen(elegida))
		{
			system("cls");
			puts("Felicitaciones has ganado :)");
			puts("Tus resultados: \n");
			printf("Fallos:     %d", fallos);
			printf("\nFrase adivinada: %s", oculta);
			fallos = 0, logros = 0;
		}

		printf("\nDeseas volver a jugar? (si / no)");
		scanf("%s", &reinicio);
		fflush(stdin);
		system("cls");
	}

	printf("\nPulse ENTER para finalizar el juego: ");
	fflush(stdin);
	getchar();

	return 0;
}
