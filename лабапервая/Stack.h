#pragma once

typedef struct Node_stack {
	int value;
	struct Node_stack* next;
} Node_stack;

void push(Node_stack** head, int data);
int pop(Node_stack** head);
void printStack(Node_stack* head);