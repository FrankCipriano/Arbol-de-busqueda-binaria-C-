#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct arbol{
    int dato;
    arbol *i,*d;
}*elemento, *aux, *cabecera, *ant, *aux2, *ant2;
int dato;

int buscar(void);
void insertar(void);
void buscarmenmay(void);
void buscarmaymen(void);
void eliminar(void);

int main(){
    int y,opc;
    do{
       cout<<"0 -> Salir\n"; 
       cout<<"1 -> Buscar\n";
       cout<<"2 -> Insertar\n";
       cout<<"3 -> borrar\n";
       cout<<"\n Cual es su opcion?\n";
       cin>>opc;
       switch(opc){
           case 0: break;
           case 1:
           cout<<"\n\nDato a buscar?\n";
           cin>>dato;
           if(buscar())
           cout<<"\nEl Dato Existe";
           else
           cout<<"\nEl Dato no Existe";
           break;
           case 2:
           cout<<"\n\nDato a Insertar?\n";
           cin>>dato;
           insertar();
           cout<<"\nDato Insertado!!";
           break;
           case 3:
           cout<<"\n\nDato a Borrar?\n";
           cin>>dato;
           eliminar();
           break;
           default:
           cout<<"\n\nOpcion Incorecta!!";
       }
       if(opc);
    }while(opc);
}

int buscar(void){
    if(!cabecera){
        cout<<"No hay arbol";
        return 0;
    }
    ant=NULL;
    aux=cabecera;
    while(aux){
        if(dato==aux->dato)
        return(1);
        else{
            ant=aux;
            if(dato>aux->dato)
            aux=aux->d;
            else
            aux=aux->i;
        }
    }
    return(0);
}

void insertar(void){
    if(!cabecera){
        cabecera=new(arbol);
        cabecera->dato=dato;
        cabecera->d=NULL;
        cabecera->i=NULL;
        return;
    }
    if(!buscar()){
        aux=new(arbol);
        aux->dato=dato;
        aux->i=NULL;
        aux->d=NULL;
        if(dato>ant->dato)
        ant->d=aux;
        else
        ant->i=aux;
    }else{
        cout<<"\n\nDato Existente!!";
    }
}

void buscarmenmay(void){
    aux2=aux->d;
    ant2=aux;
    while(aux2->i){
        ant2=aux2;
        aux2=aux2->i;
    }
    aux->dato=aux2->dato;
    if(aux->d)
    ant2->i=aux2->d;
    delete(aux2);
    ant2->d=NULL;
}

void buscarmaymen(void){
    aux2=aux->i;
    ant2=aux;
    while(aux2->d){
        ant2=aux2;
        aux2=aux2->d;
    }
    aux->dato=aux2->dato;
    if(aux2->i)
    ant2->d=aux2->i;
    delete(aux2);
    ant2->i=NULL;
}

void eliminar(void){
    if(!buscar()){
        cout<<"\n\nElemento no encontrado!!";
        return;
    }
    if(aux->d==NULL && aux->i==NULL){
        if(ant->dato>dato)
        ant->i=NULL;
        else
        ant->d=NULL;
        delete(aux);
    }
    else
    if(aux->d!=NULL)
    buscarmenmay();
    else
    buscarmaymen();
    cout<<"\n\nElemento Borrado";
}