#pragma once

typedef struct node {
    char* key;
    void* value;
} node;

typedef struct HashTable {
    struct HashTable** items;
    struct List** overflow;
    int size;
    int count;
}HashTable;

typedef struct SingleList {
    node* node;
    struct SingleList* next;

} SingleList;

HashTable* cteateHashTable(int);
void pushtable(HashTable*, char*, char*);
void printtable(HashTable*);
void delhashtable(HashTable*, char*);