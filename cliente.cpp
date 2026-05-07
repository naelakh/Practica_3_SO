#include <iostream>
#include <vector>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>
#include <fstream>

using namespace std;

// Crear un socket TCP/IP
int crearSocket() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        cerr << "Error al crear el socket" << endl;
        exit(1);
    }
    return sockfd
}

//cnfigurar servidor
void configurarServidor(struct sockaddr_in &servaddr) {
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(12345);

    if (inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr) <= 0) {
        cerr << "Direccion invalida o no soportada" << endl;
        exit(1);
    }
}

// Conectar el socket al servidor
void conectarServidor() {
    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1) {
        cerr << "Error al conectar" << endl;
        exit(1);
    }
    cout << "conexion establecida correctamente" << endl;
}

// Recibir los datos como bytes
void recibirDatos() {
   

    while (recv(sockfd, &buffer, sizeof(buffer), 0) > 0) {
        floats.push_back(buffer);
    }


    
}

void guardarArchivo() {
    ofstream file("datos.txt");



    




}
// Imprimir los numeros
void imprimirDatos() { 

      
    cout << "Numeros recibidos: " << endl;
    
    for (unsigned char c : data) {
        cout << (int)c << endl;
    }
}

int main() {
   
  

   



   
    // Cerrar el socket
    close(sockfd);

    return 0;
}
