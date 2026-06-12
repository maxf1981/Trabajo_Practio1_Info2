#ifndef FUNCIONES_H
#define FUNCIONES_H

#define CANT_ARTICULOS 60


#define SUCURSAL_1 0
#define SUCURSAL_2 1
#define SUCURSAL_3 2
#define CANT_SUCURSALES 3


typedef struct {
    char descripcion[90];
    int cantidad_sucursal[CANT_SUCURSALES];
    int total;
} articulos_t;

int buscar_o_crear_articulo(articulos_t articulos[], int tam, const char *descripcion);

void cargar_articulo(articulos_t articulos[], int tam);

void actualizar_total_articulo(articulos_t *art);

void mostrar_articulos(const articulos_t articulos[], int tam);

void ordenar_articulos_por_total(articulos_t articulos[], int tam);

void limpiar_buffer_entrada(void);

#endif


