#!/bin/bash

echo "Iniciando servidor Python..."

python3 "ServidorCamara.py" &

#esperar a que el servidor arranque
sleep 2

echo "Compilando cliente C++..."

g++ cliente.cpp -o cliente

echo "Ejecutando cliente..."

./cliente
