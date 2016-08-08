#include "Server.h"
#include "Client.h"
#include <vector>
#include <string>
#include <cstring>
using namespace std;

void print_usage();
bool is_integer(const char *s);
void run_server(int port);
void run_client(int port);

int main(int argc, const char **argv)
{
    if (argc != 3
        || strcmp(argv[1], "server") != 0 && strcmp(argv[1], "client") != 0
        || !is_integer(argv[2])
        || is_integer(argv[2]) && atoi(argv[2]) < 0)
    {
        print_usage();
        return 1;
    }

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

void print_usage()
{
    printf("./cs <client/server> <port-no>\n");
}

bool is_integer(const char *s)
{
    if(strlen(s) == 0 || ((!isdigit(s[0]))
        && (s[0] != '-') && (s[0] != '+')))
    {
        return false;
    }

    char *p;
    strtol(s, &p, 10);

    return *p == 0;
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
