# Practica 3 : Comunicacion Cliente-Servidor usando Sockets en C++


## 1. Descripción :
Este repositorio contiene una practica de sistemas operativos desarrollada con **C++ y Bash** cuyo objetivo es implementar una comunicacion cliente-servidor mediante **sockets TCP/IP**.

El sistema trabaja con datos de:
-	Camara termica simulada (servidor Python)
-	768 valores de temperatura enviados por red
-	Archivo de salida con los datos recibidos

El proyecto resuelve el problema mediante:
-	Creacion y configuracion de un **socket TCP/IP**
-	Conexion con un servidor remoto
-	Recepcion de datos mediante `recv()`
-	Almacenamiento en **vectores** (arrays dinamicos)
-	Generacion de un archivo de resultados **datos.txt**

El programa utiliza conceptos fundamentales como:
-	Comunicacion por sockets ( `socket`, `connect`, `recv`)
-	Lectura y escritura de archivos ( `ifstream`, `ofstream`)
-	Uso de arrays y vectores dinamicos
-	Modularizacion mediante funciones propias
-	Control de procesos en **Bash**

---
## 2. Estructura del repositorio :
```bash
Practica_3_SO/
├── cliente.cpp
├── ServidorCamara.py
├── cliente.sh
├── datos.txt
└── README.md
```
---
## 3. Requisitos del sistema :
- Sistema operativo: Linux (Ubuntu 22.04)
- Compilador: g++
- Python 3
- Terminal Bash
- Ambos equipos en la misma red (o usar `127.0.0.1` si es la misma maquina)

Este proyecto no requiere librerias externas adicionales.
Utiliza unicamente librerias estandar de C++ como:
```bash
iostream
```
```bash
fstream
```
```bash
vector
```
```bash
arpa/inet.h
```
```bash
unistd.h
```

---
## 4. Configuracion previa :
Antes de ejecutar el programa es necesario ajustar la direccion IP.

En **`ServidorCamara.py`** sustituir `'Direccion-IP-del-PC'` por la IP real de tu maquina:
```python
HOST = '192.168.1.XX'
```
En **`cliente.cpp`** asegurarse de que la IP coincide con la del servidor:
```cpp
if (inet_pton(AF_INET, "192.168.1.XX", &servaddr.sin_addr) <= 0)
```
Si el servidor y el cliente se ejecutan en la misma maquina usar `127.0.0.1` en ambos archivos.

---
## 5. Compilación y ejecución :
### 5.1 Compilación:
```bash
g++ main.cpp cliente.cpp -o cliente
```
### 5.2 Ejecución del servidor Python:
```bash
python3 ServidorCamara.py
```
### 5.3 Ejecución del cliente C++:
```bash
./cliente
```
### 5.4 Ejecución mediante script Bash:
```bash
chmod +x ejecutar.sh
```
```bash
./ejecutar.sh
```
---
## 6. Funcionamiento del programa en C++ :
El programa en C++ realiza las siguientes operaciones:
-	Creacion de un socket TCP/IP con `socket()`
-	Configuracion de la direccion del servidor con `inet_pton()` y `htons()`
-	Conexion al servidor con `connect()`
-	Recepcion de los 768 bytes en bucle con `recv()`
-	Almacenamiento en un vector `vector<unsigned char>`
-	Generacion de un archivo de salida **( datos.txt )**
-	Impresion de los valores recibidos por pantalla
-	Cierre del socket con `close()`

---
## 7. Funcionamiento del script Bash :
El script Bash se encarga de automatizar la ejecucion del programa:
-	Lanza el servidor Python en segundo plano con `python3 ServidorCamara.py &`
-	Espera 2 segundos con `sleep 2` para asegurarse de que el servidor esta listo
-	Compila el codigo C++ utilizando `g++ main.cpp cliente.cpp -o cliente`
-	Ejecuta el cliente con `./cliente`

---
## 8. Funciones implementadas :
El programa esta estructurado en 6 funciones propias:

| Funcion | Descripcion |
|---|---|
| `crearSocket()` | Crea el socket TCP/IP |
| `configurarServidor()` | Configura la IP y el puerto del servidor |
| `conectarServidor()` | Establece la conexion TCP |
| `recibirDatos()` | Recibe los 768 bytes con `recv()` en bucle |
| `guardarArchivo()` | Guarda los datos en `datos.txt` con `ofstream` |
| `imprimirDatos()` | Muestra los valores recibidos por pantalla |

---
## 9. Ejemplo de salida :
Tras ejecutar el programa correctamente, se generan las siguientes salidas:
-	Se muestra la confirmacion de cada paso por pantalla
-	Se reciben e imprimen los 768 valores de temperatura
-	Se genera el archivo **datos.txt** con todos los valores

```bash
Iniciando servidor Python...
Servidor escuchando en 127.0.0.1:12345
Compilando cliente C++...
Ejecutando cliente...
=========================================
  Cliente TCP - Sensor de Temperatura
=========================================

[OK] Socket creado correctamente.
[OK] Servidor configurado -> 127.0.0.1:12345
[OK] conexion establecida correctamente
Conexión aceptada desde ('127.0.0.1', 40814)
Array de datos enviado al cliente.
[OK] Datos recibidos: 768 bytes.
[OK] Datos guardados en: datos.txt

=== Valores recibidos (768 bytes) ===
0
1
2
3
4
5
6
7
8
9
10
...
[OK] Conexion cerrada. Programa finalizado.
```

---
## 10. Problemas comunes :
### Error al conectar con el servidor:
Verificar que el servidor Python esta en ejecucion antes de lanzar el cliente.
### Error de IP invalida:
Asegurarse de que la IP en `cliente.cpp` y en `ServidorCamara.py` coinciden.
### Error de compilacion:
Asegurarse de tener instalado `g++` y compilar con ambos archivos:
```bash
g++ main.cpp cliente.cpp -o cliente
```
---
## 11. Autores :
**Naela Khaldi** y **Zineb Hamman**  
Sistemas Operativos  
 Curso Academico 2025/2026




 ## 12. Notas:

El proyecto se desarrollo como parte de una practica de Sistemas Operativos orientada a la comunicacion cliente-servidor mediante sockets TCP/IP, simulando un entorno real de monitorizacion industrial con sensores termicos.
 
