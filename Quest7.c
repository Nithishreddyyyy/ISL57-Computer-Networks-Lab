#include <stdio.h>
#include <string.h>

void xor(char *a, char *b) {
    for (int i = 1; i < strlen(b); i++)
        a[i] = (a[i] == b[i]) ? '0' : '1';
}

void crc(char data[], char key[], char rem[]) {
    int keylen = strlen(key);
    char temp[50];
    strcpy(temp, data);

    for (int i = 0; i <= strlen(data) - keylen; i++) {
        if (temp[i] == '1')
            for (int j = 0; j < keylen; j++)
                temp[i + j] = (temp[i + j] == key[j]) ? '0' : '1';
    }
    strcpy(rem, temp + strlen(data) - keylen + 1);
}

int main() {
    char data[50], key[20], rem[20];
    printf("Enter data bits: ");
    scanf("%s", data);
    printf("Enter 16-bit key: ");
    scanf("%s", key);

    strcat(data, "0000000000000000");  // append 16 zeros
    crc(data, key, rem);

    printf("CRC Remainder: %s\n", rem);
    printf("Transmitted Codeword: %s%s\n", data, rem);
    return 0;
}
