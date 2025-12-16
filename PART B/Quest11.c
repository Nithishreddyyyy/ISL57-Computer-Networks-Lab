#include <stdio.h>

int main() {
    int bucket_size = 10;
    int output_rate = 3;
    int storage = 0;

    int incoming_packets[] = {4, 7, 2, 6, 5};
    int n = sizeof(incoming_packets) / sizeof(incoming_packets[0]);

    printf("Leaky Bucket Algorithm (Flow-level Traffic Management)\n\n");
    printf("Bucket Size = %d | Output Rate = %d packets/unit\n\n",
        bucket_size, output_rate);

    // Table header
    printf("---------------------------------------------------------------------\n");
    printf("Time | Incoming | Dropped | Transmitted | Remaining in Bucket\n");
    printf("---------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        int dropped = 0;
        int transmitted;

        storage += incoming_packets[i];

        if (storage > bucket_size) {
            dropped = storage - bucket_size;
            storage = bucket_size;
        }

        transmitted = (storage >= output_rate) ? output_rate : storage;
        storage -= transmitted;

        printf("%4d | %8d | %7d | %11d | %19d\n",
            i + 1,
            incoming_packets[i],
            dropped,
            transmitted,
            storage);
    }

    // Flush remaining packets
    int time = n + 1;
    while (storage > 0) {
        int transmitted = (storage >= output_rate) ? output_rate : storage;
        storage -= transmitted;

        printf("%4d | %8d | %7d | %11d | %19d\n",
            time++,
            0,
            0,
            transmitted,
            storage);
    }

    printf("---------------------------------------------------------------------\n");
    printf("All packets processed successfully using Leaky Bucket Algorithm.\n");

    return 0;
}
