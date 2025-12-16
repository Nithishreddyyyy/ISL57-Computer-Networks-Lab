#include <stdio.h>
#include <stdlib.h>

#define N 5
#define HIGH 1   // High priority value

struct Packet {
    int id;
    int priority;  // 1 = High, others = Low
};

int main() {
    struct Packet packets[N] = {
        {1, 3}, {2, 1}, {3, 2}, {4, 1}, {5, 3}
    };

    struct Packet highQueue[N], lowQueue[N];
    int h = 0, l = 0;

    printf("Initial Packet Queue:\n");
    for (int i = 0; i < N; i++) {
        printf("Packet %d (Priority %d)\n", packets[i].id, packets[i].priority);

        // Dual queue separation
        if (packets[i].priority == HIGH)
            highQueue[h++] = packets[i];
        else
            lowQueue[l++] = packets[i];
    }

    printf("\nProcessing High Priority Queue:\n");
    for (int i = 0; i < h; i++) {
        printf("Processing Packet %d (Priority %d)...\n",
               highQueue[i].id, highQueue[i].priority);
    }

    printf("\nProcessing Low Priority Queue:\n");
    for (int i = 0; i < l; i++) {
        printf("Processing Packet %d (Priority %d)...\n",
               lowQueue[i].id, lowQueue[i].priority);
    }

    printf("\nAll packets processed using dual-queue priority scheduling.\n");
    return 0;
}
