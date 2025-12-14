#include <stdio.h>
#include <string.h>

void crc(char data[], char key[], char rem[]) {
    int dataLen = strlen(data);
    int keyLen  = strlen(key);

    char temp[200];                    
    strcpy(temp, data);

    for (int i = 0; i < keyLen - 1; i++) {
        strcat(temp, "0");
    }

    int tempLen = strlen(temp);         // FIX: compute once

    for (int i = 0; i <= tempLen - keyLen; i++) {
        if (temp[i] == '1') {
            for (int j = 0; j < keyLen; j++) {
                temp[i + j] = (temp[i + j] == key[j]) ? '0' : '1';
            }
        }
    }
    for (int i = 0; i < keyLen - 1; i++) {
        rem[i] = temp[dataLen + i];
    }
    rem[keyLen - 1] = '\0';
}

int main() {
    char data[] = "11010011101100";
    char key[]  = "10001000000100001";   // CRC-16 polynomial
    char rem[30], codeword[200], checkRem[30];
    int error = 0;
    printf("Original Data: %s\n", data);
    printf("Generator (Key): %s\n", key);
    // Sender side
    crc(data, key, rem);
    strcpy(codeword, data);
    strcat(codeword, rem);
    printf("\nCRC Remainder: %s", rem);
    printf("\nTransmitted Codeword: %s\n", codeword);
    // Receiver side
    crc(codeword, key, checkRem);
    for (int i = 0; i < strlen(checkRem); i++) {
        if (checkRem[i] != '0') {
            error = 1;
            break;
        }
    }
    if (error)
        printf("\n⚠️  Error detected during transmission!\n");
    else
        printf("\n✅ No error detected — data received correctly.\n");
    return 0;
}
