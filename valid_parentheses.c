#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct node {
    char value;
    struct node* next;
} node;

char peek(node* head) {
    if (head == NULL) {
        return '\0';
    }

    return head->value;
}

bool isEmpty(node* head) {
    return head == NULL;
}

void push(node** head, char val) {
    node* temp = (node*)malloc(sizeof(node));
    temp->value = val;
    temp->next = *head;
    *head = temp;
}

char pop(node** head) {
    if (isEmpty(*head)) {
        return '\0';
    }

    node* temp = *head;
    *head = (*head)->next;
    char val = temp->value;
    free(temp);
    return val;
}

bool isValid(char* s) {
    node* head = NULL;
    int length = strlen(s);

    for (int i = 0; i < length; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            push(&head, s[i]);
        } else if ((s[i] == ')' && peek(head) == '(') ||
                   (s[i] == ']' && peek(head) == '[') ||
                   (s[i] == '}' && peek(head) == '{')) {
            pop(&head);
        } else {
            return false;
        }
    }

    return isEmpty(head);
}
