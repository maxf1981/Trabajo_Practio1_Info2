#include <stdio.h>
#include "funciones.h"


int main(void)
{
    int opc = 0;
    articulos_t articulos[CANT_ARTICULOS] = {0};


    printf("Bienvenido al sistema de gestion de stock (Refactor Informatica 2)\n\n");


    /* 1. Carga de los articulos */
    do {
        cargar_articulo(articulos, CANT_ARTICULOS);
       
        printf("\nDesea ingresar otro articulo? 1-Si, 2-No: ");
        if (scanf("%d", &opc) != 1) {
            limpiar_buffer_entrada();
            opc = 2; // Salir ante error
        }
    } while (opc == 1);


    /* 2. Impresion de fichas originales cargadas */
    printf("\n--- LISTADO DE ARTICULOS CARGADOS ---\n");
    mostrar_articulos(articulos, CANT_ARTICULOS);


    /* 3. Ordenamiento por total de unidades descendente */
    ordenar_articulos_por_total(articulos, CANT_ARTICULOS);


    /* 4. Impresion de fichas ordenadas */
    printf("\n###################################");
    printf("\n############## ORDENADO ##############");
    printf("\n################################### \n");
    mostrar_articulos(articulos, CANT_ARTICULOS);


    return 0;
}