#include <stdio.h>
#include <malloc.h>


// Node structure
struct Node {
    int value; // Node value 
    struct Node *next; // Pointer to next element
} *head = NULL; // Head of list

typedef struct Node nNode;


/* 
 * nNode* allocateNode(int value)
 * Function allocates new node with value 
 * Parameters: 
 *      int value - value of allocated node
 * Returns: nNode newNode
*/ 
nNode* allocateNode(int value) {
    nNode *newNode = (nNode*)malloc(sizeof(nNode)); // Allocate Node to append
    newNode->value = value; 
    newNode->next = NULL; // because we assert that last node in list will have NULL as next pointer, so we know where list ends, otherwise, there is now way to know that
    return newNode;
}


/* 
 * Function appends new node at the end of list
 * Parameters: 
 *      nNode *list - pointer to head of the list
 *      int value - value to be added
 * Returns: 
 *      int result of execution (1 - on success, 0 - on fail)
 *      if function successeds, list pointer would be changed
*/ 
int append(nNode *list, int value) {
    struct nNode *newNode = allocateNode(value);
    if (!newNode) return 0; 

    if (list) { // if list is not empty 
        while (list->next) // While next node is not null
            list = list->next; // Move pointer to next node
        list->next = newNode; // append new node to last node of the list
        return 1;
    } else { // if list is NULL
        list = newNode;  // list will be newNode 
        return 1;
    }
    return 0; // if none of expression worked 
}


/* 
 * Function appends list from array, (appends each value in array)
 * Parameters: 
 *      nNode *list - pointer to head of the list
 *      int value - value to be added
 *      int *array - array to append from
 *      int len - lenght of array 
 * Returns: 
 *      int result of execution (1 - on success, 0 - on fail)
 *      if function successeds, list pointer would be changed
*/ 
int appendFromArray(nNode *list, int *array, int len) {
    for (int i = 0; i < len; i++) {
        if (!append(list, array[i])) return 0;
    }
    return 1;
}


/* 
 * Function prints list from left to right 
 * Parameters: 
 *      nNode *list  
 * Returns:
 *      no returning values
*/ 
void print(nNode *list) {
    while (list != NULL) { // while head is not NULL
        printf("%d ", list->value); // print current node value 
        list = list->next; // move list pointer to next node 
    }
}


/*
 * Function traverses list and counts nodes (lenght)
 * Parameters: 
 *      nNode *list - list to find lenght of 
 * Returns: 
 *      int lenght - lenght of given list
*/
int length(nNode *list) {
    int lenght = 0;
    for (;list; list=list->next, lenght++);
    return lenght;
}


/*
 * Function searches node with given value in list
 * Parameters: 
 *      nNode *list - list to find lenght of 
 *      int value - value of node to search in list
 * Returns: 
 *      nNode list - node with given value OR NULL if no node with such value
*/
nNode *findByValue(nNode *list, int value) {
    while (list->next && list->value != value) 
        list = list->next;
    
    if (list->value == value)
        return list;

    else return NULL;
}


/*
 * Function searches node at given index in list
 * Parameters: 
 *      nNode *list - list to find lenght of 
 *      int index - index of list to search node at 
 * Returns: 
 *      nNode list - node at given index OR NULL if no such index
*/
nNode *findByIndex(nNode *list, int index) {
    int k = 0;
    while (list->next && k < index) {
        list = list->next;
        k++;
    }
    if (k == index)
        return list;
    else return NULL;
}


/*
 * ! If inserting at index 0, assign returned value to list 
 * Function inserts given value at given index in list 
 * Parameters: 
 *      nNode *list - list to insert in
 *      int value - value to insert in list
 *      int index - index in list where to insert value 
 * Returns:
 *      nNode newNode 
*/
nNode *insert(nNode *list, int value, int index) {
    nNode *newNode = allocateNode(value);
    if (index == 0 || !list)
        newNode->next = list;

    else {
        nNode *tmp = findByIndex(list, index-1);
        if (tmp) list = tmp;

        newNode->next = list->next;
        list->next = newNode;
    }
    return newNode;
}


/*
 * Function 
 * Parameters: 
 *      nNode *list - list to insert in
 *      int value - value to search in list
 * Returns:
 *      int i - index of node with given value in list
*/
int indexOf(nNode *list, int value) {
    int i = 0;
    while (list && list->value != value) {
        list = list->next;
        i++;
    } 
    
    if (list->value == value)
        return i;
    else return -1;
}


/*
 * ! If deleting at index 0, assign returned value to list 
 * Function deletes value at given index in list 
 * Parameters: 
 *      nNode *list - list to delete from
 *      int index - index in list
 * Returns:
 *      nNode list
*/
nNode* delete(nNode* list, int index) {
    if (list) {
        int len = length(list);
        nNode *tmp = findByIndex(list, index-2);
        if (index <= len && index > 0) {
            nNode *tmp2 = tmp->next;
            tmp->next = tmp2->next;
            free(tmp2); 
        }
        else if (index == 0) 
            return list->next;
    }

    return list;
}


/*
 * ! If removing at index 0, assign returned value to list 
 * Function removes value at list 
 * Parameters: 
 *      nNode *list - list to remove from
 *      int value - value in list   
 * Returns:
 *      nNode list
*/
nNode *removeFirst(nNode *list, int value) {    
    if (list) {
        nNode *tmp = list;
        nNode *tmp2;

        while (tmp->next && tmp->value != value) {
            tmp2 = tmp;
            tmp = tmp->next;
        }

        // if node with target value at index 0 
        if ( list->value == tmp->value ) return list->next;

        if (tmp && tmp->value == value) {
            
            tmp2->next = tmp->next;
            free(tmp); 
        }
    }
    return list;
}


/* 
 * Function swaps two values in list 
 * Parameters: 
 *      nNode *list - list to swap values in
 *      int index1 - value1 to swap 
 *      int index2 - value2 to swap
*/
void swap(nNode *list, int index1, int index2) {
    nNode *tmp1 = findByIndex(list, index1);
    nNode *tmp2 = findByIndex(list, index2);
    int tmp = tmp1->value;
    tmp1->value = tmp2->value;
    tmp2->value = tmp;
}


/* 
 * Function that  sorts list
 * Parameters: 
 *      nNode *list - list to sort
*/
void bubbleSort(nNode *list) {
    int len = length(list);
    for (int i = 0; i < len - 1; i++)
        for (int j = 0; j < len - i - 1; j++)
            if (findByIndex(list, j)->value > findByIndex(list, j+1)->value)
                swap(list, j, j + 1);
}


/* 
 * Function that copies list elements to array 
 * Parameters: 
 *      nNode *list - list to sort
 * Returns: 
 *      int *array - array with list values lenght of list
*/ 
int* listToArray(nNode *list) {
    int len = length(list);
    int *array = (int*)calloc(sizeof(int), len);

    nNode *tmp = list;
    for (int i = 0; i < len; i++, tmp = tmp->next)
        array[i] = tmp->value;

    return array;
}

/* 
 * Function that merges two lists in first 
 * Parameters: 
 *      nNode *list - base list, second list will be appended to it 
 *      nNode *list2 - list that will be appended to list 
*/ 
void mergeLists(nNode *list, nNode *list2) {
    if (list != list2) {

        while (list2->next) {
            list2 = list2->next; 
            append(list, list2->value);
        }  
    }
}


/* 
 * Function that merges two lists in first 
 * Parameters: 
 *      nNode *list - base list, second list will be inserted to it 
 *      nNode *list2 - list that will be inserted to list 
 *      int index - index in first list after which will be inserted list2
*/ 
nNode* insertList(nNode *list, nNode *list2, int index) {
    if (list != list2) {
        while (list2->next) {
            list2 = list2->next; 
            list = insert(list, list2->value, index);
        }  
    }
    return list;
}


/* 
 * Function that finds first max value of list
 * Parameters: 
 *      nNode *list - list to find value in
 * Returns: 
 *      int maxValue - first maximum value of the list  
*/ 
int max(nNode *list) {
    int maxValue = NULL;
    if (list) 
        for ( ;list; list=list->next) 
            if (!maxValue || maxValue < list->value)
                maxValue = list->value;
    return maxValue;
}


/* 
 * Function that finds first min value of list
 * Parameters: 
 *      nNode *list - list to find value in
 * Returns: 
 *      int minValue - first minimum value of the list  
*/ 
int min(nNode *list) {
    int minValue = NULL;
    if (list) 
        for ( ;list; list=list->next) 
            if (!minValue || minValue > list->value)
                minValue = list->value;
    return minValue;
}


/* 
 * Function that removes all elements from the list
 * Parameters: 
 *      nNode *list - list to clear
*/ 
nNode* clear(nNode* list) {
    nNode* tmp = list;
    while (list != NULL) {
        tmp = list->next;
        free(list);
        list = tmp;
    }
    return list;
}

// 
void test() {
    nNode *head = allocateNode(1);
    append(head, 2);
    append(head, 3);
    append(head, 5);
    printf(" Appended 1,2,3,5\n   * list print: ");
    print(head);
    // expected output: * list print: 1 2 3 5

    int array[] = {6, 7, 8, 9, 10}; // 5
    printf(" \n Appended from array 6, 7, 8, 9, 10\n   * list print: ");
    appendFromArray(head, &array, 5);
    print(head);
    // expected output: * list print: 1 2 3 5 6 7 8 9 1

    printf("\n Lenght: %d", length(head));
    // expected output: 9

    printf(" \n Inserted 100 at 0, 1000 at lenght, 500 at 5\n   * list print: ");
    head = insert(head, 100, 0);
    insert(head, 500, 5);
    insert(head, 1000, length(head));
    print(head);
    // expected output: 100 1 2 3 5 6 500 7 8 9 10 1000

    printf("index of 100, 500, 1000 \n   *  %d %d %d ", indexOf(head, 100), indexOf(head, 500), indexOf(head, 1000));
    // expected output: 0 5 11 
    printf(" \n index of 8, 9, 10 \n   *  %d %d %d ", indexOf(head, 8), indexOf(head, 9), indexOf(head, 10));
    // expected output: 8 9 10

    head = delete(head, 0);
    delete(head, 5);
    delete(head, length(head));
    printf(" \n Deleted at indicies: 0, 4, length(head)\n   * list print: ");
    print(head);
    // expected output: 1 2 3 5 6 7 8 9 10

    head = removeFirst(head, 100); // shoud not remove anything 
    head = removeFirst(head, 10);
    head = removeFirst(head, 1);
    head = removeFirst(head, 2);
    head = removeFirst(head, 3);
    printf(" \n Removed 1, 2, 3, 10 | not removed (bc not exists) 100\n   * list print: ");
    print(head);
    // expected output: 5 6 7 8 9

    append(head, 900);
    append(head, 76);
    append(head, 5);
    printf(" \n Appended 900,76,5\n   * list print: ");
    print(head);
    // expected output: 5 6 7 8 9 900 76 5

    bubbleSort(head);
    printf(" \n Sorted \n   * list print: ");
    print(head);
    // expected output: 5 5 6 7 8 9 76 900

    int *array1 = listToArray(head);
    printf(" \n list to array \n   * array print: ");
    for (int i = 0; i < length(head); i++) printf("%d ", array1[i]);
    printf(" \n   * list  print: ");
    print(head);
    free(array1);
    //  expected output:
    //   * 5 5 6 7 8 9 76 900  
    //    * 5 5 6 7 8 9 76 900

    nNode *head1 = allocateNode(0);
    appendFromArray(head1, &array, 5);
    printf(" \n Created second list \n   * list print: ");
    print(head1);
    // expected output: 0 6 7 8 9 10

    mergeLists(head, head1);
    printf(" \n Merged lists \n   * list print: ");
    print(head);
    // expected output: 5 5 6 7 8 9 76 900 6 7 8 9 10 

    insertList(head, head1, 1);
    printf(" \n Inserted head1 at index 1 in head \n   * list print: ");
    print(head);
    // expected output: 5 6 7 8 9 10 5 6 7 8 9 76 900 6 7 8 9 10

    head = clear(head);
    head1 = clear(head1);
}


int task() {
    /* Завдання: 
        Створити однобічно-зв’язний список дійсних чисел введенням нового елементу в початок списку.. 
        Знайти та вивести максимальний та мінімальний елементи списку. 
        Видалити із списку перший мінімальний та останній максимальний елементи.
    */

    /* Створити однозв’язний список дійсних чисел введенням нового елементу в початок списку..  */
    nNode *head = allocateNode(1);
    int array[] = {6, 7, 8, 9, 10}; // 5
    printf(" \n Appended from array 6, 7, 8, 9, 10\n   * list print: ");
    appendFromArray(head, &array, 5);
    print(head);

    int listMax = max(head);
    int listMin = min(head);
    /* Знайти та вивести максимальний та мінімальний елементи списку.  */
    printf(" \n list min %d, list max %d ", listMin,listMax);

    /* Видалити із списку перший мінімальний та максимальний елементи. */
    head = removeFirst(head, listMin); head = removeFirst(head, listMax); 
    printf(" \n removed %d, %d\n   * list print: ", listMin, listMax);
    print(head);

    head = clear(head);
    printf(" \n list cleared\n   * list print: ");
    print(head);


}


int main() {

    task();


    return 0;
}