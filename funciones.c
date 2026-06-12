#include <stdio.h>
#include <string.h>
#include "funciones.h"


void limpiar_buffer_entrada(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


int buscar_o_crear_articulo(articulos_t articulos[], int tam, const char *descripcion) {
    int i = 0;
   
   
    while (i < tam && articulos[i].descripcion[0] != '\0' && strcmp(descripcion, articulos[i].descripcion) != 0) {
        i++;
    }
   
     
   
    if (articulos[i].descripcion[0] == '\0') {
        strcpy(articulos[i].descripcion, descripcion);
    }
   
    return i;
}


void actualizar_total_articulo(articulos_t *art) {
    art->total = 0;
    for (int i = 0; i < CANT_SUCURSALES; i++) {
        art->total += art->cantidad_sucursal[i];
    }
}


void cargar_articulo(articulos_t articulos[], int tam) {
    char nombre_articulo[90];
    int sucursal = 0;
    int cantidad = 0;
    int idx = 0;


    printf("Ingrese la descripcion del articulo: ");
   
    if (scanf("%89s", nombre_articulo) != 1) {
        limpiar_buffer_entrada();
        return;
    }


    idx = buscar_o_crear_articulo(articulos, tam, nombre_articulo);
   
    if (idx == -1) {
        printf("\nError: No hay espacio para mas articulos unicos.\n");
        return;
    }


    printf("Articulo: %s, Indice en tabla: %d\n", articulos[idx].descripcion, idx);


 
    do {
        printf("Para que sucursal va a realizar la carga? (1, 2, 3): ");
        if (scanf("%d", &sucursal) != 1) {
            limpiar_buffer_entrada();
            sucursal = 0;
        }
        if (sucursal < 1 || sucursal > CANT_SUCURSALES) {
            printf("Sucursal invalida. Intente de nuevo.\n");
        }
    } while (sucursal < 1 || sucursal > CANT_SUCURSALES);


    printf("Ingrese la cantidad del articulo para la sucursal %d: ", sucursal);
    if (scanf("%d", &cantidad) != 1) {
        limpiar_buffer_entrada();
        cantidad = 0;
    }
   
   
    articulos[idx].cantidad_sucursal[sucursal - 1] += cantidad;
   


    actualizar_total_articulo(&articulos[idx]);
}


void mostrar_articulos(const articulos_t articulos[], int tam) {
    int i = 0;
    printf("%-20s\t%s1\t%s2\t%s3\tTotal\n", "Articulo", "Sucursal ", "Sucursal ", "Sucursal ");
   
    while (i < tam && articulos[i].descripcion[0] != '\0') {
        printf("%-20s\t%9d\t%9d\t%9d\t%8d\n",
               articulos[i].descripcion,
               articulos[i].cantidad_sucursal[SUCURSAL_1],
               articulos[i].cantidad_sucursal[SUCURSAL_2],
               articulos[i].cantidad_sucursal[SUCURSAL_3],
               articulos[i].total);
        i++;
    }
}


void ordenar_articulos_por_total(articulos_t articulos[], int tam) {
    articulos_t aux;
   
    for (int opc = 1; opc < tam; opc++) {
        for (int i = 0; i < tam - 1; i++) {
           
            if (articulos[i].descripcion[0] == '\0' && articulos[i+1].descripcion[0] == '\0') {
                continue;
            }
           
           
            if (articulos[i].total < articulos[i + 1].total) {
               
                aux = articulos[i];
                articulos[i] = articulos[i + 1];
                articulos[i + 1] = aux;
            }
        }
    }
}
