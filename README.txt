Autor:
(QUITAR LOS DEMAS NOMBRES)
-Diego Saavedra
-Nicolás Vázquez
-Pedro Peón

 
En este informe se refleja la complejidad de tres algoritmos distintos que 
obtienen la sucesión de Fibonacci, calculando asi sus respectivos tiempos de 
ejecucion y comparándolos entre sí. En las tablas se representaran el número
de iteraciones hechas en cada uno de los algoritmos, su tiempo y sus cotas, la
ajustada, subestimada y sobreestimada. 
(CAMBIAR POR VUESTROS PCs)
Estos calculos se realizaron todos en un hp pavilion notebook con un procesador 
Intel corei7-6700HQ, CPU con 2.6 GHz y con una Memoria Ram de 15.6Gb DDR4.

Todos los tiempos indicados en las tablas están en microsegundos.
Automatizamos el código para que, cuando los tiempos sean menores de 500 microsegundos,
se realice un bucle de 100 iteraciones, para obter un valor mas preciso, estas
filas están marcadas con un *.

Ejecutamos el código tres veces para asegurarnos de minimizar los valores anómalos, 
los cuales están dicadas con **.

 
-----------------------------------------------------------------------------------------
fib1
	
    f(n) = 1.1^n                /* Cota subestimada */
    g(n) = (1+sqrt(5))/2))^n    /* Cota ajustada */
    h(n) = 2^n                  /* Cota sobrestimada */

       	   n           T(n)      T(n)/f(n)      T(n)/g(n)      T(n)/h(n)
*          2          0.020       0.016365       0.007564     0.00495008
*          4          0.040       0.027050       0.005778     0.00247542
*          8          0.158       0.073902       0.003372     0.00061977
*         16          7.099       1.544951       0.003217     0.00010854
          32      15922.000     754.104782       0.003269     0.00000487
         
La constante a la que tiende la cota ajustada en este caso es de: 0.00326
          

-----------------------------------------------------------------------------------------
fib2
 	
    f(n) = n^0.8                /* Cota subestimada */
    g(n) = n                    /* Cota ajustada */
    h(n) = n*log(n)             /* Cota sobreestimada */

           n           T(n)      T(n)/f(n)      T(n)/g(n)      T(n)/h(n)
*       1000          3.604       0.014348       0.003604       0.000522
*      10000         30.129       0.019010       0.003013       0.000327
*     100000        315.356       0.031536       0.003154       0.000274
     1000000       3077.000       0.048767       0.003077       0.000223
    10000000      32386.000       0.081350       0.003139       0.000201

          
La constante a la que tiende la cota ajustada en este caso es de: 0.00315


-----------------------------------------------------------------------------------------
fib3
 	
 	f(n) = sqrt(log(n))         /* Cota subestimada */
 	g(n) = log(n)               /* Cota ajustada */
 	h(n) = n^0.5                /* Cota sobreestimada */

           n           T(n)      T(n)/f(n)      T(n)/g(n)      T(n)/h(n)
*        1000        0.0501       0.018836       0.007167       0.001565
*       10000        0.0590       0.019575       0.006450       0.000594
*      100000        0.0695       0.020426       0.006020       0.000419 
*     1000000        0.0794       0.021310       0.005733       0.000791 **
*    10000000        0.0996       0.024662       0.006143       0.000318

          
La constante a la que tiende la cota ajustada en este caso es de: 0.00600
          
 
-----------------------------------------------------------------------------------------

Concluimos con esto que fib1 es el algoritmo menos eficiente, su complejidad 
O(n) = n^2, a pesar de tener 32 iteraciones sobrepasa por una gran medida a fib2
y fib 3 cuando realizan un número mucho mayor de iteraciones, ya que hace 2^n
llamadas recursivas. Por otro lado fib2  tiene una complejidad de O(n)=n y es 
mas lento que fib3, ya que en fib 2 se realiza un búcle de n iteraciones mientras fib3
solo en log(n) iteraciones, el cual tiene una complejidad de O(n)=log(n).
También es cierto que el algoritmo fib3 resulto el mas dificil de implementar
en comparacion con los otros dos mencionados (los cuales ocupan la mitad de lineas de 
codigo que este), pero pensamos que por su eficiencia merece la pena el esfuerzo de
implementar fib3.
    
