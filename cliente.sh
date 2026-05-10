#!/bin/bash

echo "Iniciando servidor Python..."

python3 "ServidorCamara.py" &

# Esperar a que el servidor arranque
sleep 2

echo "Compilando cliente C++..."

g++ cliente.cpp -o cliente

echo "Ejecutando cliente..."

./cliente
