import serial, struct, time

NUM_BYTES_RESPUESTA = 5 * 2  # 5 Bytes para cada una de las celdas (4 de las unidades y uno de los decimales)
comienzoSegundaMedida = int(NUM_BYTES_RESPUESTA/2);
tiempoEncendidoLed = 0.500 # segundos que permanece el led encendido en arduino, por lo que el tiempo final es el calculado menos tiempoEncendidoLed

#---------------------------------------------------------------------
# Iniciamos la comunicacion serial
#---------------------------------------------------------------------
puertoSerial = serial.Serial('/dev/ttyACM0', 115200)

print("Esperando a que el puerto serial esté disponible...")
time.sleep(3)
while not puertoSerial.is_open:
	time.sleep(0.1)  # Hacemos esperas de 100 ms hasta que el puerto serial esté abierto

print("Puerto serial preparado")

#---------------------------------------------------------------------
# Realizamos la peticion a arduino
#---------------------------------------------------------------------

# Vaciamos el buffer de arduino por seguridad mientras que tenga peticiones
while puertoSerial.out_waiting:
	puertoSerial.reset_output_buffer()
	print("ATENCION: Se ha detectado peticiones anteriores en el buffer de arduino. Vaciando buffer de arduino...")

# Mandamos 0 codificado en bytes (b'0')
print("Mandando petición a arduino, esperando respuesta...")
if puertoSerial.write(b'0') != 1:
	print("Error. No se ha logrado enviar el byte a arduino")
	exit()

#---------------------------------------------------------------------
# Leemos la respuesta cuando esté (bloquea el código hasta que haya respuesta)
#---------------------------------------------------------------------
# Tick
start_time = time.time()

bytesRecibidosEnInt = [int.from_bytes(puertoSerial.read(), byteorder='little') for _ in range(NUM_BYTES_RESPUESTA)]

# Tock
tiempoEnEspera = time.time() - start_time

# Vaciamos el buffer por seguridad
while puertoSerial.in_waiting:
	puertoSerial.reset_input_buffer()
	print("ATENCION: Se ha detectado más bytes de los esperados. Vaciando nuestro buffer...")


#---------------------------------------------------------------------
# Mostramos la informacion recibida
#---------------------------------------------------------------------
medidaPesoA = float(''.join(map(str, bytesRecibidosEnInt[:comienzoSegundaMedida])))/10.0 # Creamos un string con todos los numeros, los pasamos a float y lo dividimos entre 10
medidaPesoB = float(''.join(map(str, bytesRecibidosEnInt[comienzoSegundaMedida:])))/10.0

print("MedidaPesoA:", medidaPesoA, " MedidaPesoB:", medidaPesoB, "  en ", tiempoEnEspera-tiempoEncendidoLed, "seg.") 

# Cerramos la conexión
puertoSerial.close()
print("Finalizamos conexión")