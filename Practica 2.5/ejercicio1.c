#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <errno.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>

int main(char* argc, char** argv[]){

    if(argc < 2){
        printf("ERROR: Introduce el host. \n");
        return -1;
    }
    char* node = argv[1];

    struct addrinfo hints;
    struct addrinfo *resul;


	hints.ai_flags = AI_PASSIVE;   // Opciones para filtrado (hints)
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = 0;
	hints.ai_protocol = 0;
	 // Resultado (res)
     hints.ai_canonname = NULL;
     hints.ai_addr = NULL;
     hints.ai_next = NULL;


    getaddrinfo(node, NULL, &hints, &resul);
      
    struct addrinfo *iterador;

    for(iterador = resul; iterador != NULL; iterador = iterador->ai_next){
        if(iterador->ai_family == AF_INET){ //ipv4
            struct sockaddr_in *direcciondesocket = iterador->ai_addr;

            char ip[INET_ADDRSTRLEN + 1] = "";

            inet_ntop(AF_INET, &(direcciondesocket->sin_addr), ip , INET_ADDRSTRLEN + 1);

            printf("%s\t",ip);
        }
        else if(iterador->ai_family == AF_INET6){ //ipv6
            struct sockaddr_in6 *direcciondesocket6;

            char ipv6[INET6_ADDRSTRLEN + 1] = "";

            inet_ntop(AF_INET6, &(direcciondesocket6->sin6_addr), ipv6, INET6_ADDRSTRLEN + 1);

            printf("%s\t",ipv6);
        }
        else{
            printf("No se ha reconocido el protocolo.");
        }
        printf("%i\t %i\t\n", iterador->ai_family, iterador->ai_socktype);
    }

    freeaddrinfo(resul);
/*
    int direccionnumerica = getnameinfo(direcciondesocket, iterador->ai_addrlen, node, hints->ai_addrlen, , , NI_NUMERICHOST);

    getnameinfo(sockad, resul.ai_addrlen, node, hints.ai_addrlen, , , NI_NUMERICHOST);*/


    return 0;
}
