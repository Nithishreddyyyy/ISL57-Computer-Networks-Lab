#include <stdio.h>

int main() {
    int bucket_size = 10, output_rate = 3, n, incoming;
    int storage = 0;

    printf("Enter number of packets: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEnter packets incoming at time %d: ", i + 1);
        scanf("%d", &incoming);

        storage += incoming;
        if (storage > bucket_size) {
            printf("Bucket overflow! %d packets dropped.\n", storage - bucket_size);
            storage = bucket_size;
        }

        printf("Transmitted %d packets.\n", output_rate);
        storage -= output_rate;
        if (storage < 0) storage = 0;

        printf("Packets left in bucket: %d\n", storage);
    }
    return 0;
}
