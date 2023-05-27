//Procesos obtener par e impar
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

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

int im = 0;
int par = 0;

switch (p) {

//case -1 el proceso devuelve un error y no se ejecuta
case -1:
printf("\nImposible crear el proceso hijo\n");
break;

//case 0 el proceso hijo se pudo ejecutar y dice cuantos pares hay
case 0:
printf("\n\nProceso hijo. PID: [%d] PPID: [%d]\n", getpid(), getppid());
for(int i=0; i<20; i++){
if (i % 2 == 0) {
} else {
im = arr[i] + im;
}
}
printf("Suma par proceso hijo: [%d]\n", im);
break;

//default el proceso padre se pudo ejecutar y dice cuantos imapres hay
default:
printf("\n\nProceso padre. PID: [%d] PID hijo: [%d]\n", getpid(), p);
for(int i=0; i<19; i++){
if (i % 2 == 0) {
par = arr[i] + par;

}
}
printf("Suma impar proceso padre: [%d]\n", par);
}
printf("F %d \n", getpid());
exit(0);
}
