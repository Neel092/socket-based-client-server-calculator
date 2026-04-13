#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

void client()
{
    int sock = 0;
    struct sockaddr_in server_address;
    // char *message = "Hello, I am taking from client side";
    char buffer[1024] = {0};

    // 1. Create Socket
    sock = socket(AF_INET, SOCK_STREAM, 0);

    // 2. Define server Address
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);

    inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr);

    // 3.connect
    printf("Connecting...\n");
    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        printf("Server not running!\n");
        return;
    }

    printf("Connecting...\n");

    // 4. Take input
    printf("Enter numeric Value for calulation :- \n");
    char msg[100] = {0};
    scanf("%s", msg);

    // 5. Send data
    send(sock, msg, strlen(msg), 0);

    // 6. Read response
    read(sock, buffer, 1024);
    printf("Server replied: %s\n", buffer);

    close(sock);
}