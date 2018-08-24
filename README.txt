sudo chmod a+rw /dev/ttyACM0 para poder enviar código a arduino

arduino mega tiene 64 bytes de buffer por lo que nos tenemos que asegurar que arduino ha vaciado el buffer antes de 
mandar más.

Comportamiento ideal:
Arduino no hace nada hasta que recibe un dato/s por el puerto serial. Vacia el buffer. Realiza la medición de las dos celdas de carga. Pasa cada una de las dos mediciones a 5 byte (4 unidades y 1 decimal) que deben ser convertidas en el programa que las reciba al float que representan. Se mantiene sin hacer nada hasta volver a ser interrumpido por un dato en el puerto serial.

La placa está conectada a arduino, cuando lo necesita le escribe a arduino para que le mande la lectura de 
las celdas, mientras que no haya recibido contestacion de arduino no puede enviarle mas peticiones. Una vez
recibe la respuesta de arduino, puede mandarle más peticiones.