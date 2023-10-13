#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include "BinarySearchTree.h"

/* 
    STRUTTURA NODO
        typedef struct node{
            int val;
            struct node *sx;
            struct node *dx;
            struct node *padre;
        }BSTNodo;

*/
BSTNodo *newBST(BSTNodo *radice, int v){
    radice = malloc(sizeof(BSTNodo));
    if(radice == NULL) {return NULL;}
    else{
        radice->val = v;
        radice->sx = NULL;
        radice->dx = NULL;
        radice->padre = NULL;
    }
    return radice;
}
void push(BSTNodo *radice, int v){
    BSTNodo *tmp1 = radice;
    if(radice == NULL){return;}
    while(true){
        if(v > tmp1->val && tmp1->dx != NULL){
            tmp1 = tmp1->dx;
        }
        else if(v > tmp1->val && tmp1->dx == NULL){
            tmp1->dx = malloc(sizeof(BSTNodo));
            tmp1->dx->val = v;
            tmp1->dx->sx = NULL;
            tmp1->dx->dx = NULL;
            tmp1->dx->padre = tmp1;
            break;
        }
        else if(v == tmp1->val){break;}
        else if(v < tmp1->val && tmp1->sx != NULL){
            tmp1 = tmp1->sx;
        }
        else if(v < tmp1->val && tmp1->sx == NULL){
            tmp1->sx = malloc(sizeof(BSTNodo));
            tmp1->sx->val = v;
            tmp1->sx->sx = NULL;
            tmp1->sx->dx = NULL;
            tmp1->sx->padre = tmp1;
            break;
        }
    }
    return;
}