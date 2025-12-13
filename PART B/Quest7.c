#include <stdio.h>
#include <string.h>

void crc(char data[], char key[], char rem[]) {
    int dataLen = strlen(data);
    int keyLen = strlen(key);
    char temp[100];
    strcpy(temp, data);

    for (int i = 0; i < keyLen - 1; i++) {
        strcat(temp, "0");
    }

    for (int i = 0; i <= strlen(temp) - keyLen; i++) {
        if (temp[i] == '1') {
            for (int j = 0; j < keyLen; j++) {
                if (temp[i + j] == key[j]) {
                    temp[i + j] = '0';
                } else {
                    temp[i + j] = '1';
                }
            }
        }
    }

    // Extract remainder (last keyLen - 1 bits)
    int start = strlen(temp) - keyLen + 1;
    for (int i = 0; i < keyLen - 1; i++) {
        rem[i] = temp[start + i];
    }
    rem[keyLen - 1] = '\0';
}

int main() {
    char data[] = "11010011101100";                    // Data bits
    char key[]  = "10001000000100001";                 // Example 16-bit generator polynomial
    char rem[30], codeword[150], checkRem[30];
    int i, error = 0;

    printf("Original Data: %s\n", data);
    printf("Generator (Key): %s\n", key);

    // Sender side
    crc(data, key, rem);

    // Form transmitted codeword (data + remainder)
    strcpy(codeword, data);
    strcat(codeword, rem);

    printf("\nCRC Remainder: %s", rem);
    printf("\nTransmitted Codeword: %s\n", codeword);

    // Receiver side verification
    crc(codeword, key, checkRem);

    for (i = 0; i < strlen(checkRem); i++) {
        if (checkRem[i] != '0') {
            error = 1;
            break;
        }
    }

    if (error == 1) {
        printf("\n⚠️  Error detected during transmission!\n");
    } else {
        printf("\n✅ No error detected — data received correctly.\n");
    }

    return 0;
}
