#include <stdio.h>

int main() {
    int bucket_size = 10;   // Maximum capacity of bucket
    int output_rate = 3;    // Packets transmitted per time unit
    int storage = 0;        // Current number of packets in bucket

    // Hardcoded incoming packets per time unit
    int incoming_packets[] = {4, 7, 2, 6, 5};
    int n = sizeof(incoming_packets) / sizeof(incoming_packets[0]);

    printf("Leaky Bucket Algorithm Simulation\n");
    printf("--------------------------------\n");
    printf("Bucket size: %d\n", bucket_size);
    printf("Output rate: %d packets/time unit\n\n", output_rate);

    for (int i = 0; i < n; i++) {
        printf("Time %d:\n", i + 1);
        printf("Incoming packets: %d\n", incoming_packets[i]);

        // Add incoming packets to storage
        storage += incoming_packets[i];

        // Check for overflow
        if (storage > bucket_size) {
            int dropped = storage - bucket_size;
            storage = bucket_size;
            printf("⚠️  Bucket overflow! %d packet(s) dropped.\n", dropped);
        }

        // Transmit packets at the output rate
        printf("Transmitted: %d packets\n", (storage >= output_rate) ? output_rate : storage);
        storage -= output_rate;
        if (storage < 0) storage = 0;

        printf("Packets remaining in bucket: %d\n\n", storage);
    }

    // Empty the bucket at the end
    while (storage > 0) {
        printf("Flushing remaining packets...\n");
        printf("Transmitted: %d packets\n", (storage >= output_rate) ? output_rate : storage);
        storage -= output_rate;
        if (storage < 0) storage = 0;
        printf("Packets remaining: %d\n\n", storage);
    }

    printf("✅ All packets processed successfully.\n");
    return 0;
}
