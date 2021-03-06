//
//  main.c
//  ConnectedList
//
//  Created by Seongheon Park on 2022/01/26.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode {
    char data[4];
    struct ListNode* link;
} listNode;

typedef struct {
    listNode* head;
} linkedList_h;

linkedList_h* createLinkedList_h(void) {
    linkedList_h* L;
    L = (linkedList_h*)malloc(sizeof(linkedList_h));
    L -> head = NULL;
    return L;
}

void freeLinkedList_h(linkedList_h* L) {
    listNode* p;
    while (L -> head != NULL) {
        p = L -> head;
        L -> head = L -> head -> link;
        free(p);
        p = NULL;
    }
}

void printList(linkedList_h* L) {
    listNode* p;
    printf("L = (");
    p = L -> head;
    
    while (p != NULL) {
        printf("%s", p -> data);
        p = p -> link;
        if (p != NULL) {
            printf(", ");
        }
    }
    printf(") \n");
}

void insertFirstNode(linkedList_h *L, char *x) {
    listNode* newNode;
    newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode -> data, x);
    newNode -> link = L -> head;
    L -> head = newNode;
}

void insertMiddleNode(linkedList_h* L, listNode *pre, char* x) {
    listNode* newNode;
    newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode -> data, x);
    if (L == NULL) {
        newNode -> link = NULL;
        L -> head = newNode;
    } else if (pre == NULL) {
        L -> head = newNode;
    } else {
        newNode -> link = pre -> link;
        pre -> link = newNode;
    }
}

void insertLastNode(linkedList_h* L, char* x) {
    listNode* newNode;
    listNode* temp;
    newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode -> data, x);
    newNode -> link = NULL;
    if (L -> head == NULL) {
        L -> head = newNode;
        return;
    }
    
    temp = L -> head;
    while (temp -> link != NULL) {
        temp = temp -> link;
    }
    temp -> link = newNode;
}

void deleteFirstNode(linkedList_h* L) {
    listNode* origin = L -> head;
    L -> head = L -> head -> link;
    free(origin);
}

void deleteMiddleNode(linkedList_h* L, int index) {
    if (index == 0) {
        deleteFirstNode(L);
    } else {
        listNode* pre = L -> head;
        for (int i = 0; i < index - 1; i++) {
            pre = pre -> link;
        }
        pre -> link = pre -> link -> link;
        
    }
}

int main(int argc, const char * argv[]) {
    linkedList_h* L;
    L = createLinkedList_h();
    printf("1. Create null list\n");
    printList(L);
    
    printf("2. Insert node [???] to the list\n");
    insertFirstNode(L, "???");
    printList(L);
    
    printf("3. Insert node [???] to end of the list\n");
    insertLastNode(L, "???");
    printList(L);
    
    printf("4. Insert node [???] to start of the list\n");
    insertFirstNode(L, "???");
    printList(L);
    
    printf("5. Delete first node of the list\n");
    deleteFirstNode(L);
    printList(L);
    
    printf("6. Insert node [???] to the list\n");
    insertMiddleNode(L, L -> head, "???");
    printList(L);
    
    deleteMiddleNode(L, 2);
    printList(L);
    
    return 0;
}
