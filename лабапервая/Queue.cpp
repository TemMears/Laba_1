#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

void init(Node_queue** head, int data) { //�y�~�y���y�p�|�y�x�y�����u�} �����u���u�t��
	Node_queue* tmp = (Node_queue*)malloc(sizeof(Node_queue));
	tmp->value = data;
	tmp->next = (*head);
	(*head) = tmp;
}
Node_queue* getLast(Node_queue* head) {
	if (head == NULL) {
		return NULL;
	}
	while (head->next) {
		head = head->next;
	}
	return head;
}
void pushQueue(Node_queue* head, int data) {
	Node_queue* last = getLast(head);
	Node_queue* tmp = (Node_queue*)malloc(sizeof(Node_queue));
	tmp->value = data;
	tmp->next = NULL;
	last->next = tmp;
}

int popQueue(Node_queue** head) {
	Node_queue* prev = NULL;
	int val;
	if (head == NULL) {
		exit(-1);
	}
	prev = (*head);
	val = prev->value;
	(*head) = (*head)->next;
	free(prev);  //�����r���q���w�t�p�u�} ���p�~�u�u �r���t�u�|�u�~�~���� ���p�}������
	return val;
}

void printQueue(Node_queue* head) {
	printf("Queue: ");
	while (head) {
		printf("%d ", head->value);
		head = head->next;
	}
}
