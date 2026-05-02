#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

void insertar(Nodo **tareasPedientes,Nodo * N);
void mostrarNodo(Nodo **tareasPedientes);

Nodo * quitarNodo(Nodo **start, int id);
void moverNodo(Nodo * p, Nodo * r, int idrealizado);
//void limpiarbuffer();


int main(){
    srand(time(NULL));

    int id=1000;
    char ds[100];
    Nodo * tareasPedientes=crearListaVacia();

    char opcion;
    printf("=======CARGA DE TAREAS ==========\n");

    do
    {
        int tiempo=rand() % (100 - 10 + 1) + 10;

        printf("ingrese la descripcion de la tarea :\n");
        fgets(ds,100,stdin);
        ds[strcspn(ds,"\n")]='\0';
        Nodo * nuevo=crearNodo(id,ds,tiempo);
        insertar(&tareasPedientes,nuevo);
        id++;

        printf("desea seguir ingresando tareas [s=si n=no]\n");
        scanf("%c",&opcion);
        getchar();
    } while (opcion=='s');
    

    printf("=====TAREAS PENDIENTES======\n");
    mostrarNodo(&tareasPedientes);

    Nodo * tareasrealizadas=crearListaVacia();
    int idrealizado;
    do
    {
        printf("ingrese el id de la tarea realizada :\n");
        scanf("%d",idrealizado);






        printf("desea seguir agregando tareas realizadas ");
        scanf("%c",&opcion);
    } while (opcion=='s');
    
    
    printf("ingrese el id de la tarea realizada :");

    scanf("%d",&idrealizado);
    


    

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

void mostrarNodo(Nodo **start)
{
    Nodo *aux=*start;
    while (aux)
    {
        printf("\n");
        printf("informacion del nodo : %d  %s  %d",aux->T.TareaID,aux->T.Descripcion,aux->T.Duracion);
        aux=aux->Siguiente;
    }
}

void insertar(Nodo **start,Nodo * N){
N->Siguiente=*start;
*start=N;
}  

/*void limpiarbuffer(){
    int c;
    while ((c=getchar())!= '\n' && c!=EOF){}
}*/

Nodo * quitarNodo(Nodo **start, int id){
    Nodo ** aux=start;
    while(*aux !=NULL && (*aux)->T.TareaID!=id){
        aux=&(*aux)->Siguiente;
    }

    if (*aux)
    {
        Nodo *temp=*aux;
        *aux = (*aux)->Siguiente;
        temp->Siguiente=NULL;
        return temp;
    }
    return NULL;
    
}

void moverNodo(Nodo ** p, Nodo ** r, int idrealizado){
    Nodo * quitado=quitarNodo(&p,idrealizado);
}