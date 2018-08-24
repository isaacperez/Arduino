# -*- coding: utf-8 -*-
import serial, struct, time
"""
# Iniciamos puerto serial

try:
	puertoSerial = serial.Serial('/dev/ttyACM0', 9600)
	print("Inicializamos puerto serial")
except Exception as e:
    print(e)

valorEnviar = 1

# Hacemos la petición de medida a arduino
puertoSerial.write(b'0')
print("Petición de medida a arduino realizada")
time.sleep(3)
print(puertoSerial.in_waiting)
# Esperamos a tener la contestación
while(not puertoSerial.in_waiting):
	pass
respuestaArduino = puertoSerial.read();
# TODO: recoger lo que responde arduino poniendo tantos read como bytes nos tiene que mandar y traduciendolo a float

# Vaciamos el buffer antes de continuar
#while(puertoSerial.available()) puertoSerial.read();
tiempoEnEspera = 0
# TODO: medir tiempo empleado

print("Arduino responde: ",respuestaArduino, "en", tiempoEnEspera,"seg.")

# Cerramos la conexión
arduino.close()
print("Finalizamos conexión\n")


"""
