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
    cout <<"[OK] Socket creado correctamente." << endl;
    return sockfd;
}

//cnfigurar servidor
void configurarServidor(struct sockaddr_in &servaddr) {
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(12345);

    // IP
    if (inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr) <= 0) {
        cerr << "Direccion invalida o no soportada" << endl;
        exit(1);
    }
    cout << "[OK] Servidor configurado -> 127.0.0.1:12345" << endl;
}

// Conectar el socket al servidor
void conectarServidor(int sockfd, sockaddr_in &servaddr) {
    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1) {
        cerr << "Error al conectar" << endl;
        exit(1);
    }
    cout << "[OK] conexion establecida correctamente" << endl;
}

// Recibir los datos como bytes
void recibirDatos(int sockfd, vector<unsigned char> &data) {
    int total = 0;

    while (total < 768) {
        int bytes = recv(sockfd, data.data() + total, 768 - total, 0);

        if (bytes <= 0) {
            cerr << "Error al recibir datos" << endl;
            break;
        }

        total += bytes;
    }
    cout << "[OK] Datos recibidos: " << total << " bytes." << endl;
}

//guardar en archivo
void guardarArchivo(const vector<unsigned char> &data) {
    ofstream file("datos.txt");

    if (!file) {
        cerr << "Error al abrir el archivo" << endl;
        return;
    }

    for (unsigned char c : data) {
        file << (int)c << endl;
    }

    file.close();
    cout << "[OK] Datos guardados en: datos.txt" << endl;
}

// Imprimir los numeros
void imprimirDatos(const vector<unsigned char> &data) {
    cout << "\n=== Valores recibidos (" << data.size() << " bytes) ===" << endl;

    for (unsigned char c : data) {
        cout << (int)c << endl;
    }
}


int main() {
    cout << "=========================================" << endl;
    cout << "  Cliente TCP - Sensor de Temperatura   " << endl;
    cout << "=========================================" << endl;
    cout << endl;

    int sockfd = crearSocket();

    sockaddr_in servaddr;
    configurarServidor(servaddr);

    conectarServidor(sockfd, servaddr);

    vector<unsigned char> data(768);

    recibirDatos(sockfd, data);

    guardarArchivo(data);

    imprimirDatos(data);

    close(sockfd);

    cout << "[OK] Conexion cerrada. Programa finalizado." << endl;
    return 0;
}
