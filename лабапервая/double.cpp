#include <stdio.h>
#include <stdlib.h>
#include "Double.h"

Db* createDb() {
    Db* tmp = (Db*)malloc(sizeof(Db));
    tmp->size = 0;
    tmp->head = tmp->tail = NULL;
    return tmp;
}
void pushFront(Db* dblist, int data) {
    nodedb* tmp = (nodedb*)malloc(sizeof(nodedb));
    tmp->value = data;
    tmp->next = dblist->head;
    tmp->prev = NULL;
    if (dblist->head) { //„u„ƒ„|„y „q„„| „„|„u„}„u„~„„, „„„€ „q„…„t„u„„ „ƒ„ƒ„„|„p„„„Ž„ƒ„‘ „~„p „~„€„r„„z
        dblist->head->prev = tmp;
    }
    dblist->head = tmp;
    if (dblist->tail == NULL) { //„u„ƒ„|„y „‡„r„€„ƒ„„ „q„„| „„…„ƒ„„„€„z, „„„€ „q„…„t„u„„ „ƒ„ƒ„„|„p„„„Ž„ƒ„‘ „~„p „~„€„r„„z „„|„u„}„~„u„„
        dblist->tail = tmp;
    }
    dblist->size++;
}
void popFront(Db* dblist) {
    nodedb* prev;
    prev = dblist->head; //„ƒ„€„‡„‚ „…„{„p„x„p„„„u„|„Ž „~„p „…„t„p„|„‘„u„}„„z „„|„u„}„u„~„„
    dblist->head = dblist->head->next; //„„u„‚„u„{„y„t„„r„p„u„} „s„€„|„€„r„…
    if (dblist->head) { //„„‚„€„r„u„‚„‘„u„}, „~„u „‘„r„| „|„y „…„t„p„|„‘„u„}„„z „„|„u„}„u„~„„ „u„t„y„~„ƒ„„„r„u„~„~„„} „„|„u„}„u„~„„„€„} „r „ƒ„„y„ƒ„{„u
        dblist->head->prev = NULL;
    }
    if (prev == dblist->tail) {
        dblist->tail = NULL;
    }
    free(prev);
    dblist->size--;
}

void pushBack(Db* dblist, int value) { //„}„u„~„‘„u„} prev - next, head - tail
    nodedb* tmp = (nodedb*)malloc(sizeof(nodedb));
    tmp->value = value;
    tmp->next = NULL;
    tmp->prev = dblist->tail;
    if (dblist->tail) {
        dblist->tail->next = tmp;
    }
    dblist->tail = tmp;
    if (dblist->head == NULL) {
        dblist->head = tmp;
    }
    dblist->size++;
}

void popBack(Db* dblist) {
    nodedb* next;
    next = dblist->tail;
    dblist->tail = dblist->tail->prev;
    if (dblist->tail) {
        dblist->tail->next = NULL;
    }
    if (next == dblist->head) {
        dblist->head = NULL;
    }
    free(next);
    dblist->size--;
}

nodedb* getNth(Db* dblist, size_t index) { //„„€„|„…„‰„u„~„y„u „„|„u„}„u„~„„„p
    nodedb* tmp = dblist->head;
    size_t i = 0;
    while (tmp && i < index) {
        tmp = tmp->next;
        i++;
    }
    return tmp;
}
void insert(Db* dblist, size_t index, int value) {
    nodedb* elm = NULL;
    nodedb* ins = NULL;
    elm = getNth(dblist, index); //„~„p„Š„|„y „…„{„p„x„p„„„u„|„Ž „~„p „„|„u„}„u„~„„, „„€„ƒ„|„u „{„€„„„€„‚„€„s„€ „~„p„t„€ „r„ƒ„„„p„r„y„„„Ž „~„€„r„„z
    ins = (nodedb*)malloc(sizeof(nodedb)); //„r„„t„u„|„y„|„y „„p„}„‘„„„Ž
    ins->value = value;
    ins->prev = elm; //„„u„‚„u„{„y„~„…„|„y „…„{„p„x„p„„„u„|„y
    ins->next = elm->next;
    if (elm->next) {
        elm->next->prev = ins;
    }
    elm->next = ins;
    if (!elm->prev) {
        dblist->head = elm;
    }
    if (!elm->next) {
        dblist->tail = elm;
    }
    dblist->size++;
}

void deleteNth(Db* dblist, size_t index) {
    nodedb* elm = NULL;
    int tmp = NULL;
    elm = getNth(dblist, index);
    if (elm->prev) {
        elm->prev->next = elm->next;
    }
    if (elm->next) {
        elm->next->prev = elm->prev;
    }
    tmp = elm->value;
    if (!elm->prev) {
        dblist->head = elm->next;
    }
    if (!elm->next) {
        dblist->tail = elm->prev;
    }
    free(elm);
    dblist->size--;
}

void printDb(Db* dblist) {
    nodedb* tmp = dblist->head;
    while (tmp) {
        printf("%d ", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}

