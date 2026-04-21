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
Nodo *Siguiente;
} Nodo;

    
Nodo * crearListaVacia(){
    return NULL;
}

Nodo *crearNodo (int id, char d,int du){
    Nodo *Nnodo=(Nodo*)malloc(sizeof(Nodo));
    Nnodo->T.Descripcion=d;
    Nnodo->T.Duracion=du;
    Nnodo->T.TareaID=id;
    Nnodo->Siguiente=NULL;
    return Nnodo;

}

void InsertarNodo(Nodo ** inicio,Nodo * Nnodo){
    Nnodo->Siguiente=*inicio;
    *inicio=Nnodo;
}

int main(){

    Nodo *inicio=crearListaVacia();

   


    
    return 0;
}