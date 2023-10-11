#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "LinkedList.h"

const char *help(){
    const char* help = 
    "\n\ntypedef struct node{\n"
    " int val;\n"
    " int index;\n"
    "struct node *next;\n"
    "}Nodo\n"
    "Nodo *newLinkedListInt(Nodo *inizio,int valore);\n"
    "Nodo *newLinkedListArrInt(Nodo *inizio,int arr[],int len);\n"
    "int pushInt(Nodo *inizio,int v);\n"
    "int popInt(Nodo *inizio);\n"
    "int shiftInt(Nodo **inizio); //  ricorda che se hai una LinkedList a, bisogna passare &a\n"
    "void printListInt(Nodo *inizio);\n\n\n" ;
    return help;
}

Nodo *newLinkedListInt(Nodo *inizio,int valore){
    inizio = malloc(sizeof(Nodo));
    inizio->val=valore;
    inizio->index=0;
    inizio->next= NULL;
    return inizio;
}

Nodo *newLinkedListArrInt(Nodo *inizio,int arr[],int len){
    inizio = malloc(sizeof(Nodo));
    Nodo* fine;
    if(len == 0){
        return NULL;
    }else{
        for(int i=0;i<len;i++){
            if(i==0){
                inizio->val=arr[i];
                inizio->index=i;
                inizio->next=NULL;
                fine = inizio;
            }else{
                Nodo *temp = malloc(sizeof(Nodo));
                fine->next=temp;
                temp->val=arr[i];
                temp->index=i;
                temp->next=NULL;
                fine = temp;
            }
        }
    }
    return inizio;
}

int pushInt(Nodo *inizio,int v){
    Nodo *tmp;
    tmp= inizio;
    int ind;
    if(inizio == NULL){
        return 0;
    }
    else{
        while(true){
            if(tmp->next == NULL){
                ind = tmp->index;
                break;
            }else{
                tmp = tmp->next;
            }
        }
        tmp->next = malloc(sizeof(Nodo));
        tmp->next->val = v;
        tmp->next->index = ind+1;
        tmp->next->next = NULL;
        return 1;
    }
}

int popInt(Nodo *inizio){
    Nodo *tmp;
    tmp = inizio;
    int contEl = 1;
    if(inizio == NULL){
        return -1;
    }else{
        while(true){
            if(tmp->next==NULL){
                break;
            }
            if(tmp->next->next==NULL){
                break;
            }else{
                tmp=tmp->next;
                contEl++;
            }
        }
        if(contEl == 1){
            contEl = tmp->val;
            free(tmp);
            return contEl;
        }else{
            contEl = tmp->next->val;
            free(tmp->next);
            tmp->next=NULL;
            return contEl;
        }
    }
}

int shiftInt(Nodo **inizio){
    /*
        Nodo *tmp;
        tmp = *inizio;
        int el;
        while(true){
            if(tmp->next == NULL){
                tmp->index = tmp->index -1;
                break;
            }else{
                tmp->index = tmp->index -1;
                tmp = tmp->next;
            }
        }
        tmp = *inizio;
        el = tmp->val;
        *inizio = (*inizio)->next;
        free(tmp);
        return el;
    */
    if (*inizio == NULL) {
        return -1; // La lista è vuota, restituisci un valore appropriato
    }
    Nodo *tmp = *inizio;
    int el = tmp->val;
    *inizio = (*inizio)->next; // Avanza il puntatore all'inizio
    free(tmp);
    tmp = *inizio;
    while (tmp != NULL) {
        tmp->index--;
        tmp = tmp->next;
    }
    return el;
}


void printListInt(Nodo *inizio){
    Nodo *temp;
    temp = inizio;
    while(true){
        if(inizio == NULL){
            printf("puntatore nullo");
            break;
        }
        if(temp == NULL){
            printf("\n");
            break;
        }
        else{
            int v = temp->val;
            if(temp->next != NULL){
                 printf("%d , ",v);
            }else{
                 printf("%d",v);
            }
            temp = temp->next;
        }
    }
}