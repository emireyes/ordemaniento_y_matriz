#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int n, m;

    printf("Ingrese el número de filas y columnas para ambas matrices: ");
    scanf("%d", &n);
    m = n;

    int matriz1[n][n];
    int matriz2[n][n];
    int suma_triangular1 = 0;
    int matriz_multiplicacion[n][n];
    int suma_triangular2 = 0;
    
    // Llenar las matrices con valores aleatorios y mostrarlas
    printf("\nMatriz 1:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz1[i][j] = rand() % 9 + 1;
            printf("%d\t", matriz1[i][j]);
        }
        printf("\n");
    }
    
    printf("\nMatriz 2:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz2[i][j] = rand() % 9 + 1;
            printf("%d\t", matriz2[i][j]);
        }
        printf("\n");
    }

    int opcion;
    do {
        printf("\nSeleccione una opción:\n");
        printf("1. Suma de matrices\n");
        printf("2. Resta de matrices\n");
        printf("3. Multiplicación de matrices\n");
        printf("4. Suma triangular de la Matriz 1\n");
        printf("5. Suma triangular de la Matriz 2\n");
        printf("6. Salir\n");
        printf("Opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
       
                printf("\nMatriz Suma:\n");
    
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        printf("%d\t", matriz1[i][j] + matriz2[i][j]);
                    }
                    printf("\n");
                }
                break;
            case 2:
        
                printf("\nMatriz Resta:\n");
    
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        printf("%d\t", matriz1[i][j] - matriz2[i][j]);
                    }
                    printf("\n");
                }
                break;
            case 3:

                printf("\nMatriz Multiplicación:\n");

                
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        matriz_multiplicacion[i][j] = 0;
                        for (int k = 0; k < n; k++) {
                            matriz_multiplicacion[i][j] += matriz1[i][k] * matriz2[k][j];
                        }
                        printf("%d\t", matriz_multiplicacion[i][j]);
                    }
                    printf("\n");
                }
                break;
            case 4:
                printf("\nSuma Triangular de la Matriz 1:\n");
        
                for (int i = 0; i < n; i++) {
                    for (int j = i; j < n; j++) {
                        suma_triangular1 += matriz1[i][j];
                    }
                }
                printf("%d\n", suma_triangular1);
                break;
            case 5:
                printf("\nSuma Triangular de la Matriz 2:\n");
                for (int i = 0; i < n; i++) {
                    for (int j = i; j < n; j++) {
                        suma_triangular2 += matriz2[i][j];
                    }
                }
                printf("%d\n", suma_triangular2);
                break;
            case 6:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }

    } while (opcion != 6);

    return 0;
}
