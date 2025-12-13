#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int s;
    struct sockaddr_in addr;
    char fname[100], buffer[1000];

    s = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(s, (struct sockaddr*)&addr, sizeof(addr));

    printf("Enter file name: ");
    scanf("%s", fname);

    write(s, fname, strlen(fname));

    read(s, buffer, sizeof(buffer));
    printf("Server Response:\n%s\n", buffer);

    close(s);
    return 0;
}

