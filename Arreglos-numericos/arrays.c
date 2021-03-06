/* Programa que muestra un menú con 4 opciones: 
 * 1. Ingresar y depurar un arreglo unidimensional de enteros
 * 2. Ingresar y ordenar un arreglo unidimensional de enteros
 * 3. Ingresar y mostrar la transpuesta de un arreglo bidimensional de reales 
 * 0. Salir */

#include<stdio.h>
//#include<stdlib.h> 

// difiniendo constantes
#define LonMax 12
#define OrdMax 4
#define RETRASO 200000000

// declarando variables globales
int A[LonMax]; // para almacenar el arreglo ingresado
int B[LonMax]; // para almacenar el arreglo ordenado
float M[OrdMax][OrdMax]; // para almacenar la matriz ingresada
int i; // declarando la variable global i para almacenar el índice
int count; //variable contadora

// Prototipo de funciones
int menu(void);
void delay(void);
int ingresar_longitud(void); 
void ingresar_arreglo(int N); 
int unico(int k, int P); 
void mostrar_arreglo_depurado(int N); 
void ordenar_arreglo(int N); 
void mostrar_arreglo_ordenado(int N); 
int ingresar_orden(void); 
void ingresar_matriz(int n); 
void mostrar_matriz(int n);
void mostrar_transpuesta(int n);
 
void main( void )
{
  	int N, orden;
  	do
	{
		orden = menu();
		switch(orden)
		{
			case 1:
				// N.B.: system("clear") show us the creen from inmediately the last \n
				printf("\n");
				system("clear"); // cleaning the screen
				N = ingresar_longitud();
				ingresar_arreglo(N);
				mostrar_arreglo_depurado(N);
				getchar();
				printf(" Message: press enter to continue...");
				getchar();
				break;
			case 2:
				printf("\n");
				system("clear");
				N = ingresar_longitud();
				ingresar_arreglo(N);
				ordenar_arreglo(N);
				mostrar_arreglo_ordenado(N);
				getchar();				
				printf(" Message: press enter to continue...");
				getchar();
				break;
			case 3: 
				printf("\n");
				system("clear");
				N = ingresar_orden();
				ingresar_matriz(N);
				mostrar_matriz(N);
				mostrar_transpuesta(N);
				getchar();
				printf(" Message: press enter to continue...");
				getchar();
				break;
			default: 
				system("clear");
				printf("\n Message: logging out...\n");
				delay();
				system("clear");
		} 
	}
	while(orden != 0);
}

int menu(void)
{
	int opcion;
	printf("\n"); // N.B.: system("clear") show us the creen from inmediately the last \n  
	system("clear");
	printf("\n================================= Arreglos ");
	printf("=================================\n\n");
	printf(" 1. Ingresar y depurar un arreglo unidimensional de enteros.\n");
	printf(" 2. Ingresar y ordenar un arreglo unidimensional de enteros.\n");
	printf(" 3. Ingresar y mostrar la transpuesta de un arreglo bidimensional de reales.\n");
	printf(" 0. Salir del programa.\n");
	printf("================================================");
	printf("===============================\n");
	printf("\n Seleccione una de las opciones: ");	
	scanf("%d", &opcion);
	return opcion;
}

void delay(void)
{
	for( count = 0 ; count < RETRASO ; )
		count++;
}

int ingresar_longitud(void) 
{
	int N;
	printf("\n Ingrese la longitud, menor o igual a %d,", LonMax); 
	printf(" del arreglo a ingresar: ");
	scanf("%d",&N);
	return N;	
}

void ingresar_arreglo (int N) 
{
	printf("\n Ingrese los elementos del arreglo de enteros A:\n");
	for ( i = 0 ; i < N ; i++ )
	{
		printf(" A[%d] = ",i);
		scanf("%d",&A[i]);
	}
}

/* esta función retorna 0 si encuentra que 
 * el elemento P ubicado en la posición k 
 * se repite en el arreglo (A[0],A[1],...,A[k-1]); 
 * caso contrario, retorna 1 */
int unico (int k, int P)
{
	int j = 0;
	for ( ; j < k ; j++ )
		if (A[j] == P) return 0;
	return 1;  
}

/* Esta función muestra los elementos, sin repetición,
 * del arreglo ingresado */ 
void mostrar_arreglo_depurado (int N)
{
	printf("\n Arreglo depurado: %d",A[0]);
	for ( i = 1 ; i < N ; i++)
		if ( unico(i,A[i]) == 1 ) printf(", %d",A[i]);
	printf(". Msj...");
	printf(" Mensaje0: presione enter para continuar...\n");
}

/* Esta función ordena, según el método de inserción,
 * los elementos del arreglo A y el arreglo ordenado
 * lo guarda en el arreglo B */
void ordenar_arreglo(int N)
{
	int k;
	if (N == 1) 
		B[0] = A[0];
	else
	{
		ordenar_arreglo(N-1);
		k = 0;
		while ( (A[N-1] > B[k]) && (k < N-1) )
			k++;
		i = N-1;
		while (i > k)
		{
			B[i] = B[i-1];
			i--;
		}
		B[k] = A[N-1];	
	}
}

/* esta función muestra los elementos, del arreglo ordenado */ 
void mostrar_arreglo_ordenado (int N)
{
	printf("\n Arreglo ordenado: %d",B[0]);
	for ( i = 1 ; i < N ; i++)
		printf(", %d",B[i]);
	printf(".\n\n");
}

int ingresar_orden (void) 
{
	int N;
	printf("\n Ingrese el orden, menor o igual a %d,", OrdMax);
	printf(" de la matriz cuadrada a ingresar: "); 
	scanf("%d",&N);
	return N;	
}

void ingresar_matriz (int n) 
{
	int i = 0, j;
	printf("\n Ingrese los elementos de la matriz M:\n");
	for (; i < n ; i++ )
	{
		for (j = 0; j < n; j++ )
		{
			printf(" M[%d][%d] = ",i,j);
			scanf("%f",&M[i][j]);
		}
	}	
}

void mostrar_matriz (int n)
{
	int i = 0, j;
	printf("\n Matriz M:\n ");
	for (; i < n; i++ )
	{
		for ( j = 0 ; j < n; j++ )
			printf("%.2f\t",M[i][j]);
		printf("\n");
	}	
}

void mostrar_transpuesta (int n)
{
	int i = 0, j;
	printf("\n Matriz transpuesta de M:\n");
	for (; i < n; i++ )
	{
		for ( j = 0 ; j < n; j++ )
			printf(" %.2f   ",M[j][i]);
		printf("\n");
	}	
}
