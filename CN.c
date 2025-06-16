// server.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SRV_UDP_PORT 8000
#define MAX_MSG 100

void errExit(char *str) {
    puts(str);
    exit(0);
}

int main() {
    unsigned long t;
    int sockfd, n;
    socklen_t client_len;
    struct sockaddr_in srvAddr, cliAddr;
    char tmsg[MAX_MSG], rmsg[MAX_MSG];

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
        errExit("Socket creation error");

    memset(&srvAddr, 0, sizeof(srvAddr));
    srvAddr.sin_family = AF_INET;
    srvAddr.sin_addr.s_addr = htonl(INADDR_ANY); // Accept connections from any IP
    srvAddr.sin_port = htons(SRV_UDP_PORT);

    if (bind(sockfd, (struct sockaddr *)&srvAddr, sizeof(srvAddr)) < 0)
        errExit("Bind error");

    client_len = sizeof(cliAddr);
    n = recvfrom(sockfd, rmsg, MAX_MSG, 0, (struct sockaddr *)&cliAddr, &client_len);
    if (n < 0)
        errExit("recvfrom error");

    printf("Message received from client: %s\n", rmsg);

    // Get current time
    t = time(NULL);
    strcpy(tmsg, ctime(&t));

    n = strlen(tmsg) + 1;

    if (sendto(sockfd, tmsg, n, 0, (struct sockaddr *)&cliAddr, client_len) != n)
        errExit("sendto error");

    printf("Time sent to client.\n");

    return 0;
}
// client.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SRV_IP_ADDR "127.0.0.1"
#define SRV_UDP_PORT 8000
#define MAX_MSG 100

void errExit(char *str) {
    puts(str);
    exit(0);
}

int main() {
    int sockfd, n;
    struct sockaddr_in srvAddr;
    socklen_t len;
    char tmsg[MAX_MSG], rmsg[MAX_MSG];

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
        errExit("Can't open datagram socket");

    memset(&srvAddr, 0, sizeof(srvAddr));
    srvAddr.sin_family = AF_INET;
    srvAddr.sin_addr.s_addr = inet_addr(SRV_IP_ADDR);
    srvAddr.sin_port = htons(SRV_UDP_PORT);

    printf("Enter message to send:\n");
    fgets(tmsg, MAX_MSG, stdin);

    n = strlen(tmsg) + 1;
    if (sendto(sockfd, tmsg, n, 0, (struct sockaddr *)&srvAddr, sizeof(srvAddr)) != n)
        errExit("Send to error");

    len = sizeof(srvAddr);
    n = recvfrom(sockfd, rmsg, MAX_MSG, 0, (struct sockaddr *)&srvAddr, &len);
    if (n < 0)
        errExit("Recvfrom error");

    printf("Time received from the server: %s\n", rmsg);

    return 0;
}
