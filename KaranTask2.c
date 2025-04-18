#include <stdio.h>
#include <stdlib.h>

// Define the structure for stack node
typedef struct Node {
    int data;
    struct Node* next;
} node;

// Function to push an element onto the stack
void push(node **top) {
    node *p;
    int d;
    p = (node*)malloc(sizeof(node));

    printf("Enter the data: ");
    scanf("%d", &d);
    p->data = d;
    p->next = *top;
    *top = p;
}

// Function to pop an element from the stack
void pop(node **top) {
    node* p;
    int d;
    if (*top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    p = *top;
    d = p->data;  // Corrected line
    *top = p->next;
    free(p);
    printf("%d popped from stack\n", d);
}

// Function to display stack elements
void display(node* top) {
    node *p = top;
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are:");
    while (p != NULL) {
        printf(" %d", p->data);
        p = p->next;
    }
    printf("\n");  // Added newline
}

// Main function to execute the stack operations
int main() {
    int choice;
    node *top = NULL;

    while (1) {  // Corrected the infinite loop
        printf("1.Push, 2.Pop, 3.Display, 4.Exit\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                push(&top);
                break;
            case 2:
                pop(&top);
                break;
            case 3:
                display(top);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
}
