//Tower of Hanoi problem 
#include <stdlib.h>

// Structure for a stack node
typedef struct Stack {
    int src;
    int dest;
    int n; // Number of disks to move
    struct Stack* next;
} Stack;

// Push an operation to the stack
void push(Stack** top, int n, int src, int dest) {
    Stack* newNode = (Stack*)malloc(sizeof(Stack));
    newNode->n = n;
    newNode->src = src;
    newNode->dest = dest;
    newNode->next = *top;
    *top = newNode;
}

// Pop an operation from the stack
Stack* pop(Stack** top) {
    if (*top == NULL) return NULL;
    Stack* temp = *top;
    *top = (*top)->next;
    return temp;
}

// Iterative Tower of Hanoi using Stack
void towerOfHanoi(int n, int src, int aux, int dest) {
    Stack* stack = NULL;

    // Push the initial operation (move all disks from src to dest)
    push(&stack, n, src, dest);

    // Process the stack iteratively
    while (stack != NULL) {
        Stack* current = pop(&stack);
        int numDisks = current->n;
        int source = current->src;
        int destination = current->dest;
        free(current);

        if (numDisks == 1) {
            // Base case: Move a single disk
            printf("Move disk 1 from rod %d to rod %d\n", source, destination);
        } else {
            // Recursive breakdown: Simulate three steps
            push(&stack, numDisks - 1, aux, destination); // Step 3
            push(&stack, 1, source, destination);         // Step 2
            push(&stack, numDisks - 1, source, aux);      // Step 1
        }
    }
}

int main() {
    int n = 3; // Number of disks
    towerOfHanoi(n, 1, 2, 3); // Rods are numbered 1, 2, 3
    return 0;
}