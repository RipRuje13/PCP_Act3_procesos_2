//Procesos obtener mínimo y máximo
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
pid_t p;
int tamArr = 20;
int n = 100;
int arr[tamArr];

//Se llena el arreglo con numeros aleatorios
for (int i = 0; i<tamArr; i++){
arr[i] = rand()%n;
printf("%d, ", arr[i]);
}
p = fork();
int mp = 0;
int mh = arr[10];
switch (p) {
//el case -1 es un error que nos dice que no se puede ejecutar el proceso
case -1:
printf("\nImposible crear el proceso hijo\n");
break;
//el caso 0 es el valor que regresa que se pudo ejecutar el proceso y nos dice el numero
menor
case 0:
printf("\nProceso hijo. PID: [%d]\nPPID: [%d] \n", getpid(), getppid());
for(int i=0; i<20; i++){
if(arr[i] < mh){
mh = arr[i];
}
}
printf("Valor minimo: [%d] \n", mh);
break;

//el default es cualquier valor que regresa siendo este el padre y nos dice el numero
mayor
default:
printf("\nProceso padre. PID: [%d]\nPID hijo: [%d] \n", getpid(), p);
for(int i=0; i<20; i++){
if(arr[i] > mp){
mp = arr[i];
}
}
printf("Valor maximo: [%d] \n", mp);
}
printf("F %d \n\n", getpid());
exit(0);
}
