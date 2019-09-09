/*
 * nomPrograma: vector00.cpp
 * descripcion: Operaciones basicas.
 *             TAREA (Evaluacion continua)
 *       Los datos de prueba son: a[]= [4,1,9]
 *    1. Analice, ejecute y luego analice los resultados. Pruebe activando solo
 *       la operacion deseada.


 *    2. Ordenar vector: ordena de forma ascendente de izquierda a derecha.
         Insertar x Pos: La iteracion busca la posicion dada, corre los datos (en este caso los dezplaza hacia la derecha) y aumenta la dimesion
                         del vector en 1.
         Eliminar x Pos: Tambien busca la iteracion dada, sustituye el valor de la posicion por el de la siguiente, luego
                          corre los datos (en este caso de izquierda a derecha) y disminuye la dimension del vector en 1.
         Insertar x Valor: Cambia el valor de una posición por la requerida, se ordena el vector y utiliza la operacion buscarDato para obtener
                           la posición donde se insertará.


 *    3. La referencia o llamada insertarxPos(a,&na,4, 22) no inserta, corrija
 *       elm error.


 *    4. Con la experiencia anterior ahora implemente eliminarxPos()
 *    5. Implemente ordenarVector() veease la guia de labotarorio
 *   *
 *
 * autor: Martinez Bravo, Martin
 * fecha: 30/04/2019
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 10



using namespace std;

void crearVector(int x[], int *dx);
void leerVector(int x[], int *dx);
void mostrarVector(int x[], int dx);
void ordenarVector(int x[], int dx);

void insertarxPos(int x[], int *dx, int posi, int dato);
// Prototipos de la tarea
void eliminarxPos(int x[], int *dx, int posi);
void insertarxValor(int x[], int *dx, int dato);
int buscarDato(int x[], int dx, int dato);
void insertarxValor(int x[], int *dx, int dato);

int main(){
   int a[MAX];
   int na, nb;

   crearVector(a, &na);
   leerVector(a, &na);
    mostrarVector(a, na);
   /* Prueba insertar por posicion */
   //insertarxPos(a,&na,0, 22);
   //insertarxPos(a,&na,1, 22);
   //insertarxPos(a,&na,3, 22);
   //insertarxPos(a,&na,4, 22);// Problemas, Porque no inserta?
   //insertarxPos(a,&na,5, 22);
   /* Prueba eliminar por posicion */
   //eliminarxPos(a,&na,0);
   //eliminarxPos(a,&na,1);
   //eliminarxPos(a,&na,2);
   //eliminarxPos(a,&na,3);
   //eliminarxPos(a,&na,4);
   //ordenarVector(a, na);
   //mostrarVector(a, na);

   //eliminarxPos(a, &na, 2);
   insertarxValor(a, &na, 50);
   mostrarVector(a, na);

   //buscarDato(a, na, 5);



   system("pause");
   return(0);
}

void crearVector(int x[], int *dx)
{
   *dx=-1;
}
void leerVector(int x[], int *dx)
{
   int i, n, val;

   cout << "Ingrese numero de elementos: ";

   //RUTINA DE LECTURA
   cin >> n;

   cout <<"Ingrese elementos:\n";

   if(n<MAX){
      for(i=0;i<n;){
         scanf("%d", &val);
         x[i]=val;
         i=i+1;

      }
      *dx=i;//Actualizac de la dimension
   }

   else{
      printf("Dimension fuera de RANGO ...");
   }

}



void mostrarVector(int x[], int dx){
   //RUTINA DE ESCRITURA
   int i, val;

   if(dx>0){
      printf("vector = < ");
      for(i=0;i<dx;){
         val=x[i];
         printf("%d ", val);
         i=i+1;
      }
      printf(">\n");
   }

   else{
      printf("Vector vacioooo...!\n");
   }
}



void ordenarVector(int x[], int dx)
{
   int aux, i, j;
   if(dx>-1){
      for(i=0; i<dx-1; i++){
         for(j=i+1; j<dx; j++){
            if(x[i]>x[j]){
               aux=x[j];
               x[j]=x[i];
               x[i]=aux;
            }

         }

      }
   }
   else{
      printf("Vector vacioooo...!\n");
   }
}




void insertarxPos(int x[], int *dx, int posi, int dato)
{
   int i, n;
   n = *dx;
   n = n + 1;//
   i = *dx;

   cout << "Insertar nueva posicion: " ;
   if(n<MAX){
      if(posi-1>-1 && posi-1<*dx){
         *dx=n;
         while(i>posi-1){
            x[i] = x[i-1];
            i = i-1;
         }
         x[posi-1]=dato;
         printf("\nDato %d  INSERTADO en posicion %d \n\n ", dato, posi);
         mostrarVector(x, *dx);
      }
      else{
         printf("La posicion %d no existe en el vector...\n", posi);
      }
   }
   else{
      printf("Dimension fuera de rango ...\n");
      system("pause");
   }
}



//Implementacion de la tarea y el reto
void eliminarxPos(int x[], int *dx, int posi)
{
    int i, n;
   n = *dx;
   i = posi;

   cout << "Eliminar posicion: " ;
   if(n<MAX){
      if(posi-1>-1 && posi-1<*dx){
         while(i<n){
            x[i-1] = x[i];
            i = i+1;
         }
         *dx = n - 1;
         printf("\nDato eliminado en posicion %d \n\n ", posi);
         mostrarVector(x, *dx);
      }
      else{
         printf("La posicion %d no existe en el vector...\n", posi);
      }
   }
   else{
      printf("Dimension fuera de rango ...\n");
      system("pause");
   }
}




void insertarxValor(int x[], int *dx, int dato)
{
    int pos;

    ordenarVector(x, *dx);

    if(*dx>-1){
      for(int i=0; i<*dx-1; i++){
         if(dato > x[i]){
            pos = i+2;
         }
      }
   }
   else{
      printf("Vector vacioooo...!\n");
   }
    if (pos > *dx){
        pos = *dx;
    }
   insertarxPos(x,&*dx, pos, dato);

}




int buscarDato(int x[], int dx, int dato)
{
    int i, val, pos=-1;

   if(dx>0){
      printf("vector = < ");
      for(i=0;i<dx;){
         val=x[i];
         printf("%d ", val);
         if(val == dato){
            pos = i;
         }
         i=i+1;
      }
      printf(">\n");
   }
   else{
      printf("Vector vacioooo...!\n");
   }

   if(pos == -1){
    printf("F\n");
   }
   else{
    printf("Elemento encontrado en %d", pos);
   }
   return pos;
}

