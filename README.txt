sudo chmod a+rw /dev/ttyACM0.txt para poder enviar código a arduino

arduino mega tiene 64 bytes de buffer por lo que nos tenemos que asegurar que arduino ha vaciado el buffer antes de 
mandar más.

Comportamiento ideal:
Arduino esta cada 10 ms esperando, despues lee el peso de las celdas de cargas y lee el puerto serial. 
Si ha llegado algo, manda por el puerto serial la lectura de las celdas de carga. Si no ha llegado nada,
vuelve a esperar 10 ms.

La placa está conectada a arduino, cuando lo necesita le escribe a arduino para que le mande la lectura de 
las celdas, mientras que no haya recibido contestacion de arduino no puede enviarle mas peticiones. Una vez
recibe la respuesta de arduino, puede mandarle más peticiones.