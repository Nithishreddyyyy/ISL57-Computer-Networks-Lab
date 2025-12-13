#include <stdio.h>
#include <stdlib.h>

#define N 5  // Number of packets

struct Packet {
    int id;
    int priority;  // Lower number = higher priority
};

// Function to sort packets by priority
void sortByPriority(struct Packet p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].priority > p[j].priority) {
                struct Packet temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

int main() {
    // 🔹 Hardcoded packets (id, priority)
    struct Packet packets[N] = {
        {1, 3}, {2, 1}, {3, 2}, {4, 1}, {5, 3}
    };

    printf("Initial Packet Queue:\n");
    for (int i = 0; i < N; i++) {
        printf("Packet %d (Priority %d)\n", packets[i].id, packets[i].priority);
    }

    // Sort packets by priority
    sortByPriority(packets, N);

    printf("\nPackets processed in order of priority (1 = Highest):\n");
    for (int i = 0; i < N; i++) {
        printf("Processing Packet %d (Priority %d)...\n", packets[i].id, packets[i].priority);
    }

    printf("\nAll packets processed successfully based on priority.\n");

    return 0;
}
