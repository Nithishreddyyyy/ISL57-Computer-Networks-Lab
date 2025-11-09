#include <stdio.h>
#include <stdlib.h>

struct Packet {
    int id, priority;
};

int main() {
    struct Packet p[5] = {{1, 3}, {2, 1}, {3, 2}, {4, 1}, {5, 3}};
    int n = 5;

    // Sort packets by priority (1 = highest)
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (p[i].priority > p[j].priority) {
                struct Packet temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }

    printf("Packets processed in order of priority:\n");
    for (int i = 0; i < n; i++)
        printf("Packet %d (Priority %d)\n", p[i].id, p[i].priority);

    return 0;
}
