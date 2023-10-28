#pragma once

typedef struct Node_queue {
	int value;
	struct Node_queue* next;
} Node_queue;

void pushQueue(Node_queue* head, int data);
void init(Node_queue** head, int data);
int popQueue(Node_queue** head);
void printQueue(Node_queue* head);
Node_queue* getLast(Node_queue* head);