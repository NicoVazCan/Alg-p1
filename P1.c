/*
Autores:
-Diego Saavedra
-Nicolás Vázquez
-Pedro Peón
*/

#include <stdio.h>
#include <sys/time.h>
#include <math.h>

//Funcion que devuelve la hora del sistema en microsegundos
double microsegundos(){
    struct timeval t;
    if (gettimeofday(&t, NULL) < 0){
        return 0.0;
    }
    return(t.tv_usec + t.tv_sec * 1000000.0);
}

//Primera función de Fibonacci propuesta
int fib1(int n){
    if (n<2){
        return n;
    }
    else {
        n=fib1(n-1) + fib1(n-2);
        return n;
    }
}

//Segunda función de Fibonacci propuesta
int fib2(int n){
    int i = 1, j = 0, k;
	
    for(k = 1; k <= n; k++){
        j = i+j;
        i = j-i;
    }
    return(j);
}

//Tercera función de Fibonacci propuesta
int fib3(int n){
    int i = 1,j = 0,k = 0,h = 1,t = 0;

    while(n>0){
        if ((n % 2)==1){
            t = j*h;
            j = i*h+j*k+t;
            i = i*k+t;
        }
        t = h*h;
        h = 2*k*h+t;
        k = k*k+t;
        n = n/2;
    }
    return j;
}

//Test del correcto funcionamiento de las funciones de Fibonacci
void test(int n){
    int resultadofib1, resultadofib2, resultadofib3, i;
    
    printf("N\t fib1\t fib2\t fib3\n");
    printf("-----------------------------------\n");
    for(i = 0; i<n; i++){
        resultadofib1 = fib1(i);
        resultadofib2 = fib2(i);
        resultadofib3 = fib3(i);
        printf("%d\t %d\t %d\t %d\t\n\n", i, resultadofib1, 
        resultadofib2, resultadofib3);
    }
    return;
}

//Funcion para tomar el tiempo de cada algoritmo
double medir_tiempo(int (*fib)(int), int n){
    double t,t1,t2;
    const double tmin = 500, tpeq = 1;
    int a, rep = 1000;
	
    t1=microsegundos();
    fib(n);
    t2=microsegundos();
    t=t2-t1;
    if (t<tmin){
        rep = t < tpeq? rep*rep: rep; //Cuando el tiempo es muy pequeno, 
        //aplicamos mas repeticiones para obtener un tiempo medio mas preciso.
        t1=microsegundos();
        for(a=1;a<=rep;a++){
            fib(n);
        }
        t2=microsegundos();	
        t=(t2-t1)/rep;
        printf("*");
    }
    else { printf(" "); }

    return t;
}

//Imprime la funcion subestimada, ajustada y sobreestimada del agoritmo 1
void tabla1(int n, double t){
    double subestimada, ajustada, sobreestimada;
	
    subestimada = t/(pow(1.1,n));
    ajustada = t/pow(((1 + sqrt(5) )/2),n);
    sobreestimada = t/pow(2,n);
    printf("%12d%15.3f%15.6f%15.6f%15.6f\n", n, t, subestimada, ajustada, 
            sobreestimada);
    return;		
}

//Imprime la funcion subestimada, ajustada y sobreestimada del agoritmo 2
void tabla2(int n, double t){
    double subestimada, ajustada, sobreestimada;
	
    subestimada=t/pow(n,0.8);
    ajustada=t/n;
    sobreestimada=t/(n*log(n));
    printf("%12d%15.3f%15.6f%15.6f%15.6f\n", n, t, subestimada, ajustada, 
            sobreestimada);
    return;
}

//Imprime la funcion subestimada, ajustada y sobreestimada del agoritmo 3
void tabla3(int n, double t){
    double subestimada, ajustada, sobreestimada;
	
    subestimada=t/sqrt(log(n));
    ajustada=t/log(n);
    sobreestimada=t/pow(n,0.5);
    printf("%12d%15.3f%15.6f%15.6f%15.6f\n", n, t, subestimada, ajustada, 
            sobreestimada);
    return;
}

//Funcion que ejecuta los algoritmos y la impresion de sus tablas de tiempos
void tablafinal(){
    double t;
    int n, j, i;

    for (j = 0; j < 3; j++){
        printf("\nFibonacci 1\n");
        printf("%13s%15.4s%15.9s%15.9s%15.9s\n","n","T(n)","T(n)/f(n)",
            "T(n)/g(n)","T(n)/h(n)");
        n = 2;
        for(i = 0; i < 5 ; i++){		
            t = medir_tiempo(fib1, n);
            tabla1(n,t);
            n *= 2;
        }
    }
    for (j = 0; j < 3; j++){
        printf("\nFibonacci 2\n");
        printf("%13s%15.4s%15.9s%15.9s%15.9s\n","n","T(n)","T(n)/f(n)",
            "T(n)/g(n)","T(n)/h(n)");
        n = 1000;
        for(i = 0; i < 5 ; i++){		
            t = medir_tiempo(fib2, n);
            tabla2(n,t);
            n *= 10;
        }
    }
    for (j = 0; j < 3; j++){
        printf("\nFibonacci 3\n");
        printf("%13s%15.4s%15.9s%15.9s%15.9s\n","n","T(n)","T(n)/f(n)",
            "T(n)/g(n)","T(n)/h(n)");
        n = 1000;
        for(i = 0; i < 5 ; i++){		
            t = medir_tiempo(fib3, n);
            tabla3(n,t);
            n *= 10;
        }
    }
    return;
}

int main(){
    test(7);
    tablafinal();
    return 0;
}     
