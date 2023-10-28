#pragma once

typedef struct nodesingle {
    int value;
    struct nodesingle* next;
} nodesingle;

void push(nodesingle** head, int data);
int pop(nodesingle** head);
void printLinkedList(const nodesingle* head);
nodesingle* getLast(nodesingle* head);
nodesingle* get(nodesingle* head, int n);
void pushBack(nodesingle* head, int value);
int popBack(nodesingle** head);
void insert(nodesingle* head, int n, int val);
int deleteNth(nodesingle** head, int n);

