#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct node *element(struct node *dll, int i) ;
struct node *add(struct node *dll, int i, int value) ;
struct node *delete(struct node *dll, int i);

struct node{
    int value;
    struct node *next;
    struct node *prev;
};

struct node *element(struct node *dll, int i){
    if(i==0){
        return dll;
    }
    else{
        struct node* currentptr=dll;

        for(int j=0;j<i;j++){
            if(currentptr->next){
                currentptr = currentptr->next;
            }
            else{
                return NULL;
            }
        }
        return currentptr;
    }
}

struct node *add(struct node *dll, int i, int value){
    struct node* new = (struct node*) malloc(sizeof(struct node));
    struct node* currentnode = (element(dll,i));
    new->value=value;

    if(i==0){
        new->next=dll;
        new->prev=NULL;
        dll->prev=new;
        
        return new;
    }
    else if(i>0 && currentnode){
        struct node* previousnode = currentnode->prev;

        previousnode->next=new;
        currentnode->prev=new;
        new->next=currentnode;
        new->prev=previousnode;
    }
    else{
        struct node* currentnode=dll;
        while(currentnode->next){
            currentnode = currentnode->next;
        }
        new->next=NULL;
        new->prev=currentnode;
        currentnode->next=new;
    }
    return dll;
}

struct node *delete(struct node *dll, int i){
    struct node *currentnode = element(dll,i);
    if(currentnode){
        if(i==0){
            struct node *nextnode = currentnode->next;
            free(dll);
            if(nextnode){
                nextnode->prev=NULL;
            }
            else{
                return NULL;
            }
            return nextnode;
        }
        else{
            struct node *nextnode = currentnode->next;
            struct node *previousnode = currentnode->prev;
            free(currentnode);

            if(nextnode){
                nextnode->prev=previousnode;
                previousnode->next=nextnode;
            }
            else{
                previousnode->next=NULL;
            }
            return dll;
        }
    }
    else{
        return dll;
    }
}

void printNode (struct node *dll) {
    if (dll != NULL) {
        printf("< This: %p - %d - P : %p - N : %p >\n", dll, dll->value, dll->prev, dll->next);
    } else {
        printf("Null Pointer");
    }
}


void printLL (struct node *dll) {
    struct node* ptr = dll;
    printf("---\n");
    while (ptr != NULL) {
        printNode(ptr);
        ptr = ptr->next;
    }
    printf("---\n\n");
}

int main () {
 
 
    struct node *dll = malloc(sizeof(struct node));
    dll->value = 1;
    printLL(dll);
    dll = add(dll, -1, 3);
    printLL(dll);
    dll = add(dll, -1, 4);
    printLL(dll);
    dll = add(dll, 1, 2);
    printLL(dll);
    dll = add(dll, 2, 7);
    printLL(dll);
    dll = add(dll, 9, -1);
    printLL(dll);
    dll = delete(dll, 2);
    printLL(dll);
    dll = delete(dll, 0);
    printLL(dll);
    dll = delete(dll, 4);
    printLL(dll);
    dll = delete(dll, 0);
    printLL(dll);
    dll = delete(dll, 0);
    printLL(dll);
    dll = delete(dll, 0);
    printLL(dll);
    dll = delete(dll, 0);
    printLL(dll);
}

/* Expected Output: 

---
< This: 0x1cf8590 - 1 - P : (nil) - N : (nil) >
---

---
< This: 0x1cf8590 - 1 - P : (nil) - N : 0x1cf85b0 >
< This: 0x1cf85b0 - 3 - P : 0x1cf8590 - N : (nil) >
---

---
< This: 0x1cf8590 - 1 - P : (nil) - N : 0x1cf85b0 >
< This: 0x1cf85b0 - 3 - P : 0x1cf8590 - N : 0x1cf85d0 >
< This: 0x1cf85d0 - 4 - P : 0x1cf85b0 - N : (nil) >
---

---
< This: 0x1cf8590 - 1 - P : (nil) - N : 0x1cf85f0 >
< This: 0x1cf85f0 - 2 - P : 0x1cf8590 - N : 0x1cf85b0 >
< This: 0x1cf85b0 - 3 - P : 0x1cf85f0 - N : 0x1cf85d0 >
< This: 0x1cf85d0 - 4 - P : 0x1cf85b0 - N : (nil) >
---

---
< This: 0x1cf8590 - 1 - P : (nil) - N : 0x1cf85f0 >
< This: 0x1cf85f0 - 2 - P : 0x1cf8590 - N : 0x1cf8610 >
< This: 0x1cf8610 - 7 - P : 0x1cf85f0 - N : 0x1cf85b0 >
< This: 0x1cf85b0 - 3 - P : 0x1cf8610 - N : 0x1cf85d0 >
< This: 0x1cf85d0 - 4 - P : 0x1cf85b0 - N : (nil) >
---

---
< This: 0x1cf8590 - 1 - P : (nil) - N : 0x1cf85f0 >
< This: 0x1cf85f0 - 2 - P : 0x1cf8590 - N : 0x1cf85b0 >
< This: 0x1cf85b0 - 3 - P : 0x1cf85f0 - N : 0x1cf85d0 >
< This: 0x1cf85d0 - 4 - P : 0x1cf85b0 - N : (nil) >
---

*/ 