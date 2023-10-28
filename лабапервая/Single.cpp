#include <stdio.h>
#include <stdlib.h>
#include "OdSp.h"

void push(nodesingle** head, int data) { //„t„€„q „„| „r „s„€„|„€„r„…
    nodesingle* tmp = (nodesingle*)malloc(sizeof(nodesingle)); //„ƒ„€„x„t „~„€„r„„z „„|
    tmp->value = data;
    tmp->next = (*head);
    (*head) = tmp;
}


int pop(nodesingle** head) { //„…„t„p„|„‘„u„} „„| „y„x „s„€„|„€„r„
    nodesingle* prev = NULL;
    int val;
    if (head == NULL) {
        exit(-1);
    }
    prev = (*head); //„ƒ„€„‡„‚„p„~„‘„u„} „p„t„‚„u„ƒ „„‚„€„Š„|„€„s„€ „„|„u„}„u„~„„„p, „{„€„„„€„‚„„z „…„t„p„|„‘„u„}
    val = prev->value;
    (*head) = (*head)->next;
    free(prev);
    return val;
}

void printLinkedList(const nodesingle* head) { //„„u„‰„p„„„p„u„} „ƒ„„y„ƒ„€„{
    while (head) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

nodesingle* getLast(nodesingle* head) {  //„„€„|„…„‰„p„u„} „„€„ƒ„|„u„t„~„y„z „„|„u„}„u„~„„
    if (head == NULL) {
        return NULL;
    }
    while (head->next) {
        head = head->next;
    }
    return head;
}

nodesingle* get(nodesingle* head, int n) {  //„„€„|„…„‰„y„„„ n-„~„„z „„|„u„}„u„~„„
    int i = 0;
    while ( i < n && head) {
        head = head->next;
        i++;
    }
    return head;
}

void pushBack(nodesingle* head, int value) {
    nodesingle* last = getLast(head);  //„…„{„p„x„p„„„u„|„ „~„p „„€„ƒ„| „„|„u„}„u„~„„
    nodesingle* tmp = (nodesingle*)malloc(sizeof(nodesingle)); //„~„€„r„„z „„|, „„‚„y„ƒ„r„p„y„r„p„u„} „u„}„… „x„~„p„‰„u„~„y„u
    tmp->value = value;
    tmp->next = NULL;
    last->next = tmp; //„„u„‚„u„{„y„t„„r„p„u„} „…„{„p„x„p„„„u„|„ „ƒ„„„p„‚„€„s„€ „„|-„„„p „~„p „~„€„r„„z
}

int popBack(nodesingle** head) {
    nodesingle* current = NULL;  //„„„u„{„…„‹„y„z „…„x„u„|
    nodesingle* previous = NULL;  //„„‚„u„t„„t„…„‹„y„z „…„x„u„|
    if (!head) {
        exit(-1);
    }
    current = *head;
    while (current->next) {
        previous = current;
        current = current->next;
    }

    if (previous == NULL) { //„u„ƒ„|„y „r„ƒ„u„s„€ „€„t„y„~ „„|„u„}„u„~„„, „„„€ „…„t„p„|„‘„} „s„€„|„€„r„…
        free(*head);
        *head = NULL;
    }
    else {
        free(current->next); //„y„~„p„‰„u „…„t„p„|„‘„u„} „„€„ƒ„| „„|
        previous->next = NULL;
    }
}

void insert(nodesingle* head, int n, int val) {
    int i = 0;
    nodesingle* tmp = NULL;
    //„N„p„‡„€„t„y„} „~„…„w„~„„z „„|„u„}„u„~„„. „E„ƒ„|„y „r„„Š„|„y „x„p „„‚„u„t„u„|„ „ƒ„„y„ƒ„{„p, „„„€ „r„„‡„€„t„y„} „y„x „ˆ„y„{„|„p,
    //„€„Š„y„q„{„y „~„u „q„…„t„u„„, „r„ƒ„„„p„r„y„„ „r „{„€„~„u„ˆ
    while (i < n && head->next) {
        head = head->next;
        i++;
    }
    tmp = (nodesingle*)malloc(sizeof(nodesingle));
    tmp->value = val;
    //„E„ƒ„|„y „„„„€ „~„u „„€„ƒ„|„u„t„~„y„z „„|„u„}„u„~„„, „„„€ next „„u„‚„u„{„y„t„„r„p„u„} „~„p „ƒ„|„u„t„…„„‹„y„z „…„x„u„|
    if (head->next) {
        tmp->next = head->next;
    }
    else {
        tmp->next = NULL;
    }
    head->next = tmp;
}

int deleteNth(nodesingle** head, int n) { //„…„t„p„|„‘„u„} „„t„u„}„u„~„„
    if (n == 0) {
        return pop(head);
    }
    else {
        nodesingle* prev = get(*head, n - 1); //„„€„|„…„‰„p„u„} „…„{„p„x„p„„„u„|„ „~„p „„| „t„€ „…„t„p„|„‘„u„}„€„s„€
        nodesingle* elm = prev->next; //„…„{„p„x„p„„„u„|„ „~„p „…„t„p„|„‘„u„}„„z
        int val = elm->value;

        prev->next = elm->next; //„„u„‚„u„{„y„t„„r„p„u„} „~„p „ƒ„|„u„t „„| „x„p „…„t„p„|„‘„u„}„„}
        free(elm); //„…„t„p„|„‘„u„}
        return val;
    }
}
