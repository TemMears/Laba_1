#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack.h"

void push(Node_stack** head, int data) {
	Node_stack* tmp = (Node_stack*)malloc(sizeof(Node_stack));
	tmp->value = data;
	tmp->next = (*head);
	(*head) = tmp;
}
int pop(Node_stack** head) {
	Node_stack* prev = NULL;
	int val;
	if (head == NULL) {
		exit(-1);
	}
	prev = (*head); //„ƒ„€„‡„‚„p„~„‘„u„} „p„t„‚„u„ƒ „„‚„€„Š„|„€„s„€ „„|„u„}„u„~„„„p, „{„€„„„€„‚„„z „…„t„p„|„‘„u„}
	val = prev->value;
	(*head) = (*head)->next;
	free(prev);  //„€„ƒ„r„€„q„€„w„t„p„u„} „‚„p„~„u„u „r„„t„u„|„u„~„~„…„ „„p„}„‘„„„Ž
	return val;
}

void printStack(Node_stack* head) {
	printf("stack: ");
	while (head) {
		printf("%d ", head->value);
		head = head->next;
	}
}
