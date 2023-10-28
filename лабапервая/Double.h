#pragma once


typedef struct nodedb {
    int value;
    struct nodedb* next;
    struct nodedb* prev;
} nodedb;

typedef struct Db {
    size_t size;
    nodedb* head;
    nodedb* tail;
} Db;

Db* createDb();
void pushFront(Db* list, int data);
void popFront(Db* list);
void pushBack(Db* list, int value);
void popBack(Db* list);
nodedb* getNth(Db* list, size_t index);
void insert(Db* list, size_t index, int value);
void deleteNth(Db* list, size_t index);
void printDb(Db* list);

