#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include "OdSp.h"
#include "Stack.h"
#include "Double.h"
#include "Queue.h"
#include "Table.h"
#include "Tree.h"
#include "Array.h"

#define CAPACITY 10

int main() {
    printf("Реализация структур данных \n");
    printf("\n");
    printf("Доступные варианты: \n 1) Массив\n 2) Односвязный список\n 3) Двусвязный список\n 4) Стэк\n 5) Очередь\n 6) Хэш-таблица\n 7) Дерево\n 8) Выход из программы \n");
    printf("\n");
    bool bool_variable = true;
    while (bool_variable) {
        printf("Напишите номер желаемой структуры: ");
        int number;
        scanf("%d", &number);
        printf("\n");
        if (number == 1) {
            printf("Вы выбрали массив, ура!\n");
            int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
            printf("Наш массив: ");
            int len = sizeof(arr) / sizeof(arr[0]);
            for (int i = 0; i < len; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            del(arr, 5, len);
            printf("Удалили 5 элемент!\n");
            for (int i = 0; i < len; i++) {
                printf("%d ", arr[i]);
            }
            del(arr, 2, len);
            printf("\n");
            printf("Удалили 2 элемент!");
            printf("\n");
            for (int i = 0; i < len; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            int* arr2 = (int*)malloc((len + 1) * sizeof(int));
            pushArr(arr, arr2, 3, 15, len);
            printf("Добавили элемент!");
            printf("\n");
            printf("Итоговый массив: ");
            for (int i = 0; i <= len; i++) {
                printf("%d ", arr2[i]);
            }
            printf("\n");
            printf("\n");
        }
        
        if (number == 2) {
            printf("Вы выбрали односвязный список, ура!\n");
            printf("Добавим значения в голову: 3, 6, 8, 9, 45\n");
            nodesingle* head_single = NULL;
            push(&head_single, 3);
            push(&head_single, 6);
            push(&head_single, 8);
            push(&head_single, 9);
            push(&head_single, 45);
            printf("Полученный список: ");
            printLinkedList(head_single);
            printf("Удалим из головы элемент, получаем: ");
            pop(&head_single);
            printLinkedList(head_single);
            printf("Добавим элемент с индексом 4: ");
            insert(head_single, 3, 15);
            printLinkedList(head_single);
            printf("Удалим элемент с индексом 2: ");
            deleteNth(&head_single, 2);
            printf("\n");
            printLinkedList(head_single);
            printf("\n");
        }
        if (number == 3) {
            printf("Вы выбрали двусвязный список, ура!\n");
            printf("Добавим в голову поочередно значения 6 и 7, получаем: ");
            Db* doublelist = createDb();
            pushFront(doublelist, 6);
            pushFront(doublelist, 7);
            printDb(doublelist);
            printf("\n");
            printf("Добавим в хвост значение 13, элемент с индексом 2 и элемент с индексом 3, получаем: ");
            pushBack(doublelist, 13);
            insert(doublelist, 1, 15);
            insert(doublelist, 2, 11);
            printDb(doublelist);
            printf("\n");
            printf("Удалим элемент с индексом 3, получаем: ");
            deleteNth(doublelist, 3);
            printDb(doublelist);
            printf("\n");
        }
        if (number == 4) {
            printf("Вы выбрали стэк, ура!\n");
            printf("Добавим в стек сначала элемент 3, потом элемент 7 и 8 \n");
            Node_stack* head_stack = NULL;
            push(&head_stack, 3);
            push(&head_stack, 7);
            push(&head_stack, 8);
            printf("Получим: ");
            printStack(head_stack);
            printf("\n");
            printf("Удалим элемент, получаем: ");
            pop(&head_stack);
            printStack(head_stack);
            printf("\n");
            printf("\n");
        }
        if (number == 5) {
            printf("Вы выбрали очередь, ура!\n");
            printf("Добавим в очередь поочередно элементы 3, 5, 8 и 9, получаем: \n");
            Node_queue* head_queue = NULL;
            init(&head_queue, 3);  //инициализируем первым элементом
            pushQueue(head_queue, 5); //добавляем в конец
            pushQueue(head_queue, 8);
            pushQueue(head_queue, 9);
            printQueue(head_queue);
            printf("\n");
            printf("Удалим элемент, получаем: ");
            popQueue(&head_queue);
            printf("\n");
            printQueue(head_queue);
            printf("\n");

        }
        if (number == 6) {
            printf("Вы выбрали хэш-таблицу, ура!\n");
            HashTable* hashtable = cteateHashTable(5);
            pushtable(hashtable, "grass", "burdock");
            pushtable(hashtable, "grass", "cactus");
            pushtable(hashtable, "paint", "red");
            pushtable(hashtable, "number", "one");
            pushtable(hashtable, "number", "ten");
            printtable(hashtable);
            delhashtable(hashtable, "paint");
            printtable(hashtable);
            printf("\n");
            printf("\n");
        }
        if (number == 7) {
            printf("Вы выбрали дерево, ура!\n");
            NodeCBT* Tree = NULL;
            printf("Добавим поочередно элементы: 4,8,2,1,5,3,9,0");
            Tree = pushCBT(Tree, 4);
            Tree = pushCBT(Tree, 8);
            Tree = pushCBT(Tree, 2);
            Tree = pushCBT(Tree, 1);
            Tree = pushCBT(Tree, 5);
            Tree = pushCBT(Tree, 3);
            Tree = pushCBT(Tree, 9);
            Tree = pushCBT(Tree, 0);
            printf("\n");
            printf("Получаем: ");
            printCBT(Tree);
            printf("\n");
            printf("Удалим элемент 2, получаем: ");
            Tree = popCBT(Tree, 2);
            printCBT(Tree);
            printf("\n");
            printf("\n");
        }
        if (number == 8) {
            printf("Вы свободны.");
            bool_variable = false;
            printf("\n");
        }
        if (number >= 9) {
            printf("Такого варианта нет, попробуйте ещё раз! \n");
            printf("\n");
        }
        if (number <= 0) {
            printf("Такого варианта нет, попробуйте ещё раз! \n");
            printf("\n");
        }
    }
}