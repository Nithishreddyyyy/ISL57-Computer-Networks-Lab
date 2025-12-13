#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int s, ns;
    struct sockaddr_in addr;
    char fname[100], buffer[1000];
    
    s = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = INADDR_ANY;

    bind(s, (struct sockaddr*)&addr, sizeof(addr));
    listen(s, 1);

    ns = accept(s, NULL, NULL);

    read(ns, fname, sizeof(fname));

    FILE *fp = fopen(fname, "r");
    if (fp == NULL) {
        write(ns, "File not found", 14);
    } else {
        fread(buffer, 1, sizeof(buffer), fp);
        write(ns, buffer, strlen(buffer));
    }

    close(ns);
    close(s);
    return 0;
}

