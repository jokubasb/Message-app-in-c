#include <stdio.h>
#include <string.h>
#include <unistd.h> // close socket
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>


void botas(){
    sleep(2);
    int networkSocket;
	networkSocket = socket(AF_INET, SOCK_STREAM, 0);

	// nurodom adresa socketui
	struct sockaddr_in server_address;

	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002);
	server_address.sin_addr.s_addr = INADDR_ANY;

	connect(networkSocket, (struct sockaddr *) &server_address, sizeof(server_address));
    int i = 0;
    char pass[3];
    for(i = 0; i < 3; i++) {
        pass[i] = 33 + rand() % 94;
    }
    pass[i] = '\0';
    //siunciam random varda
    send(networkSocket, pass, 20, 0);
    int j = 0;
    for(int j = 0; j < 500; ++j){
        char buffer[64] = {0};
        sprintf(buffer, "Timestamp: %d\n",(int)time(NULL));
        send(networkSocket, buffer, sizeof(buffer), 0);
        sleep(1);
    }
}

int main(){
    srand(time(NULL));
    botas();
}

    