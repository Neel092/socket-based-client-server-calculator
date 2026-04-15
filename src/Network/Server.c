#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#include "Network/Server.h"
#include "Core/Parser.h"

void server()
{
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char response[100] = {0};

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 3);

    printf("Server running...\n");

    while (1)
    {
        new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);

        memset(buffer, 0, sizeof(buffer));
        read(new_socket, buffer, 1024);
        if (buffer[0] == 'Q')
        {
            close(new_socket);
            close(server_fd);
            break;
        }

        int ans = Client_Server(buffer);

        sprintf(response, "%d", ans);
        send(new_socket, response, strlen(response), 0);
    }
}
