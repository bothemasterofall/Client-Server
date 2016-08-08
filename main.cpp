#include "Server.h"
#include "Client.h"
#include <vector>
#include <string>
#include <cstring>
using namespace std;

void run_server(int port);
void run_client(int port);

int main(int argc, const char **argv)
{
    if (strcmp(argv[1], "server") == 0)
    {
        printf("Running server\n");
        run_server(atoi(argv[2]));
    }
    else if (strcmp(argv[1], "client") == 0)
    {
        printf("Running client\n");
        run_client(atoi(argv[2]));
    }
    
    return 0;
}

void run_server(int port)
{
    char *msg;
    Server server(port, 1);
    server.sListen();
    server.sAccept();
    server.sRead(0, &msg);
    server.sWrite(0, "Hello from server", 18);

    printf ("Message from client: %s\n", msg);
    delete[] msg;
}

void run_client(int port)
{
    char *msg;
    Client client("localhost", port);
    client.cOpen();
    client.cWrite("Hello from client", 18);
    client.cRead(&msg);
    client.cClose();

    printf("Message from server: %s\n", msg);
    delete[] msg;
}
