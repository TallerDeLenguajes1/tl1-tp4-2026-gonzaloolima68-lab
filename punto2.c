#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tarea{
int TareaID;//Numérico autoincremental comenzando en 1000
char *Descripcion; //
int Duracion; // entre 10 – 100
} Tarea;

typedef struct Nodo{
Tarea T;
struct Nodo *Siguiente;
} Nodo;

Nodo * crearListaVacia();
Nodo *crearNodo(int id, char *ds,int time);



int main(){

    Nodo * start=crearListaVacia();

   


    
    return 0;
}


Nodo * crearListaVacia(){
    return NULL;
}

Nodo *crearNodo(int id, char *ds,int time){
    Nodo * NuevoNodo=(Nodo*) malloc(sizeof(Nodo));

    NuevoNodo->T.TareaID=id;
    NuevoNodo->T.Descripcion=(char *)malloc(strlen(ds)+1);
    strcpy(NuevoNodo->T.Descripcion,ds);
    
    
    NuevoNodo->T.Duracion=time;
    NuevoNodo->Siguiente=NULL;
    return NuevoNodo;

}