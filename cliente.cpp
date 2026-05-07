#include <iostream>
#include <vector>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>
#include <fstream>

using namespace std;

int crearSocket() {
}


void configurarServidor() {
}

void recibirDatos() {
}

void guardarArchivo() {

}

void imprimirDatos() { 

}

int main() {
    // Crear un socket TCP/IP
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        cerr << "Error al crear el socket" << endl;
        return 1;
    }

    // Conectar el socket al servidor
    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(12345);

    if (inet_pton(AF_INET, "192.168.0.148", &servaddr.sin_addr) <= 0) {
        std::cerr << "Direccion invalida o no soportada" << endl;
        return 1;
    }

    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1) {
        cerr << "Error al conectar" << endl;
        return 1;
    }

    // Recibir los datos como bytes
    vector<float> floats;
    float buffer;

    while (recv(sockfd, &buffer, sizeof(buffer), 0) > 0) {
        floats.push_back(buffer);
    }

    // Guardar los datos en un archivo de texto
    // Implementar

    // Imprimir los numeros de punto flotante
    cout << "Numeros de punto flotante recibidos: " << endl;
    for (float f : floats) {
        cout << f << endl;
    }

    // Cerrar el socket
    close(sockfd);

    return 0;
}
