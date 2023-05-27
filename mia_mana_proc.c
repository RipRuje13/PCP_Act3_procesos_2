//Proceso obtener media y mediana

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

int mh;
int te = sizeof arr[0];
int lon = sizeof arr / te;
int mitad = lon / 2;
int suma;
float mp;
switch (p) {
//case -1 el proceso devuelve un error y no se ejecuta
case -1:
printf("Imposible crear el proceso hijo \n");
break;

//se regresa el valor cero y se crea el proceso hijo. obtiene la media
case 0:
printf("\n\nProceso hijo. PID: [%d] PPID: [%d] \n", getpid(), getppid());
for(int i=0; i<20; i++){
suma += arr[i];
};
float mh = (float) suma / (float) lon;
printf("Media: [%f]\n", mh);
break;

//regresa cualquier valor y se ejecuta el padre. obtiene la mediana
default:
printf("\n\nProceso padre. PID: [%d] PID hijo:[%d] \n", getpid(), p);
if (lon % 2 == 0) {
mp = (arr[mitad - 1] + arr[mitad]) / 2;

} else {
mp = arr[mitad];
}
printf("Mediana: [%f]\n", mp);
}
printf(" Final [%d] \n", getpid());
exit(0);
}
