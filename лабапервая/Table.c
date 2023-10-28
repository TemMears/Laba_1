#define _CRT_SECURE_NO_WARNINGS
#include "Table.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define sizetable 5

SingleList* HEAD;
SingleList* TAIL;

unsigned long hashfunc(char* str)
{
    unsigned long i = 0;
    for (int j = 0; str[j]; j++)
    {
        i += str[j];
    }

    return i % sizetable;
}
node* createitem(char* key, char* value)
{
    node* item = (node*)malloc(sizeof(node));
    item->key = (char*)malloc(strlen(key) + 1);
    item->value = (char*)malloc(strlen(value) + 1);

    strcpy(item->key, key);
    strcpy(item->value, value);

    return item;
}

SingleList** create_overflow(HashTable* table)
{
    SingleList** my_list = (SingleList**)calloc(table->size, sizeof(SingleList*));
    for (int i = 0; i < table->size; i++)
    {
        my_list[i] = NULL;
    }
    return my_list;
}

HashTable* cteateHashTable(int size)
{
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    table->size = size;
    table->count = 0;
    table->items = (node**)calloc(table->size, sizeof(node*));
    for (int i = 0; i < table->size; i++)
    {
        table->items[i] = NULL;
    }
    table->overflow = create_overflow(table);
    return table;
}

SingleList* list_insert(SingleList* list, node* item)
{
    if (list == NULL)
    {
        list = (SingleList*)malloc(sizeof(SingleList));
        list->node = item;
        list->next = NULL;
        return list;
    }
    else if (list->next == NULL)
    {
        SingleList* tmp = (SingleList*)malloc(sizeof(SingleList));
        tmp->node = item;
        tmp->next = NULL;
        list->next = tmp;
        return list;
    }
    else
    {
        while (list->next != NULL)
        {
            list = list->next;
        }
        SingleList* tmp = (SingleList*)malloc(sizeof(SingleList));
        tmp->node = item;
        tmp->next = NULL;
        list->next = tmp;
        return list;
    }
}

void collision(HashTable* table, unsigned long index, node* item)
{
    SingleList* list = table->overflow[index];

    if (list == NULL)
    {
        list = (SingleList*)malloc(sizeof(SingleList));
        list->node = item;
        list->next = NULL;
        table->overflow[index] = list;

        return;
    }
    else {
        table->overflow[index] = list_insert(list, item);
        return;
    }
}

void pushtable(HashTable* table, char* key, char* value)
{
    if (table == NULL)
    {
        return;
    }
    node* item = createitem(key, value);
    int index = hash_function(key);
    node* current_item = table->items[index];
    if (current_item == NULL)
    {
        if (table->count == table->size)
        {
            printf("Insert Error: Hash Table is full\n");
            return;
        }
        table->items[index] = item;
        table->count++;
    }
    else
    {
        if (strcmp(current_item->key, key) == 0)
        {
            strcpy(current_item->value, value);
            return;
        }
        else
        {
            collision(table, index, item);
            return;
        }
    }
}

void printtable(HashTable* table)
{
    printf("\nHash Table\n\n");
    for (int i = 0; i < table->size; i++)
    {
        if (table->items[i])
        {
            node* tmp = table->items[i];
            printf("Index:%d, Key:%s, Value:%s\n", i, tmp->key, tmp->value);
        }
    }
    printf("\n\n");
}

void delhashtable(HashTable* table, char* key)
{
    int index = hashfunc(key);
    node* item = table->items[index];
    SingleList* head = table->overflow[index];

    if (item == NULL)
    {
        return;
    }
    else
    {
        if (head == NULL && strcmp(item->key, key) == 0)
        {
            table->items[index] = NULL;
            free_item(item);
            table->count--;
            return;
        }
        else if (head != NULL)
        {
            if (strcmp(item->key, key) == 0)
            {
                free_item(item);  //„…„t„p„|„‘„u„} „„|„u„}„u„~„„, „…„ƒ„„„p„~„p„r„|„y„r„p„u„} „~„p„‰„p„|„€ „ƒ„„y„ƒ„{„p
                SingleList* list = head;
                head = head->next;
                list->next = NULL;

                table->items[index] = createitem(list->node->key, list->node->value);
                free_list(list);
                table->overflow[index] = head;
                return;
            }
            SingleList* curr = head;
            SingleList* prev = NULL;
            while (curr)
            {
                if (strcmp(curr->node->key, key) == 0)
                {
                    if (prev == NULL)
                    {
                        free_list(head);
                        table->overflow[index] = NULL;
                        return;
                    }
                    else
                    {
                        prev->next = curr->next;
                        curr->next = NULL;
                        free_list(curr);
                        table->overflow[index] = head;
                        return;
                    }
                }
                curr = curr->next;
                prev = curr;
            }

        }
    }
}