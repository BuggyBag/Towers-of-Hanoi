#include <stdio.h>
#include <stdlib.h>

#define U_LIMIT 15
#define L_LIMIT 3

// Push function to add elements to the towers
void push(int *stack, int *top, int tower) {
    if (*top < U_LIMIT*2 - 1)
        stack[++(*top)] = tower;
}

// Pop function to move the elements between towers
int pop(int *stack, int *top) {
        return stack[(*top)--];   
}

// Check if the stack is empty
int isEmpty(int top) {
    return top == -1;
}

// Algorithm to solve the Tower of Hanoi problem
void gameSolution(int n, int TowerA, int TowerB, int TowerC, int *stack, int *top) {
    // Use separate arrays for Towers
    int nStack[U_LIMIT*2];
    int TowerAStack[U_LIMIT*2];
    int TowerBStack[U_LIMIT*2];
    int TowerCStack[U_LIMIT*2];

    // number of moves to track the towers
    int moveN = 1;

    push(stack, top, n);
    push(TowerAStack, top, TowerA);
    push(TowerBStack, top, TowerB);
    push(TowerCStack, top, TowerC);
    push(stack, top, 1);

    //start recursion
    start:
    //loop until the stacks are empty
    if (isEmpty(*top)) {
        return; //if the tower is empty, stop the movements
    }

    //assign the movements to the towers in the initial order
    int currentPhase = pop(stack, top);
    int currentFinal = pop(TowerCStack, top);
    int currentIntermediate = pop(TowerBStack, top);
    int currentInitial = pop(TowerAStack, top);
    int currentDisc = pop(stack, top);

    //start movement (base Case = only one disc in tower)
    if (currentDisc == 1) {
        moveN++;
        printf("Disc moved is %d, %i moves made. \n", currentDisc, moveN);
        goto start;
    }

    switch (currentPhase) {
        case 1: // moving discs from the first tower
            push(stack, top, currentDisc);
            push(TowerAStack, top, currentInitial);
            push(TowerBStack, top, currentIntermediate);
            push(TowerCStack, top, currentFinal);
            push(stack, top, 2);

            push(stack, top, currentDisc - 1);
            push(TowerAStack, top, currentInitial);
            push(TowerBStack, top, currentFinal);
            push(TowerCStack, top, currentIntermediate);
            push(stack, top, 1);

            goto start;
        case 2: //moving discs from second tower
            moveN++;
            printf("Disc moved is %d, %i moves made. \n", currentDisc, moveN);

            push(stack, top, currentDisc - 1);
            push(TowerAStack, top, currentIntermediate);
            push(TowerBStack, top, currentInitial);
            push(TowerCStack, top, currentFinal);
            push(stack, top, 1);

            goto start;
    }
}

int main() {
    printf("\n\n\t Towers of Hanoi\n\n");

    int n;

    do {
        printf("Enter the number of discs: ");
        scanf("%d", &n);
        if (n > U_LIMIT || n < L_LIMIT)
            printf("\n Range is [%d, %d]. ", L_LIMIT, U_LIMIT);
    } while (n < L_LIMIT || n > U_LIMIT);

    int stack[U_LIMIT * 5]; // Increased size for separate Tower arrays
    int top = -1;

    printf("\n");
  
    gameSolution(n, 1, 2, 3, stack, &top); // Use integers to represent the pegs

    printf("\n Tower C");
    for (int i = 0; i < n; i++) {
        printf("");
    }

    return 0;
}