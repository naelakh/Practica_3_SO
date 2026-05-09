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
void conectarServidor(int sockfd, sockaddr_in &seraddr) {
    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1) {
        cerr << "Error al conectar" << endl;
        exit(1);
    }
    cout << "conexion establecida correctamente" << endl;
}

// Recibir los datos como bytes
void recibirDatos(int sockfd, vector<unsigned char> &data) {
   int total - 0;

    while (total < 768) {
        int byte = recv(sockfd, data.data() + total, 768 - total, 0);

        if (byte <= 0) {
            cerr << "Error al recibir datos" << endl;
            break;
        }
        total += byte;
    }
    cout << "Bytes recibidos: " << total << endl;
}

void guardarArchivo() {
    ofstream file("datos.txt");

    if (!file) {
        cerr << "Error al abrir el archivo" << endl;
        return;
    }
    for (unsigned char c : data) {
        file << (int)c << endl;
    }
    file.close();
    cout << "Archivo guardado correctamente" << endl;
}
// Imprimir los numeros
void imprimirDatos() {  
    cout << "Numeros recibidos: " << endl;
    
    for (unsigned char c : data) {
        cout << (int)c << endl;
    }
}

int main() {
    int sockfd = crearSocket();
    
    sockaddr_in servaddr;
    configurarServidor(servaddr);
    
    vector<unsigned char> data(768);
    
    recibirDatos(sockfd, data);
    
    guardarArchivo(data);

    imprimirDatos(data);
    // Cerrar el socket
    close(sockfd);

    return 0;
}
