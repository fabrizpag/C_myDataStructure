#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include "BinarySearchTree.h"
#include "sorting.h"

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
BSTNodo *newBSTarr(BSTNodo *radice, int *arr,int size){
    if (size <= 0){return NULL;}
    if(size == 1){
        radice = newBST(NULL,arr[0]);
        return radice;
    }else{
        radice = newBST(NULL,arr[0]);
        for(int i = 1;i<size;i++){
            push(radice,arr[i]);
        }
        return radice;
    }
}
int numEl(BSTNodo *radice){
    if(radice == NULL){
        return 0;
    }
    return 1 + numEl(radice->sx) + numEl(radice->dx);
}
int *toArr(BSTNodo *radice , int *arr){
    if(radice == NULL){
        return NULL;
    }else{
        int size = numEl(radice);
        arr = malloc(size*(sizeof(int)));

        internalToArr(radice,arr,0,size);
        return arr;
    }
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

void balanceTree(BSTNodo **radice){
    if (radice == NULL || *radice == NULL){return;}
    BSTNodo *tmp = *radice;
    int *arr = toArr(tmp,NULL);
    int sizeArr = numEl(tmp);
    //devi deallocare il vecchio albero con un metodo destroy da implementare
    quickSort(arr,0,sizeArr-1);
    if(sizeArr%2 == 0){
        //array pari
        int dx = sizeArr/2;
        int sx = dx-1;
        tmp = newBST(NULL,arr[dx]);
        push(tmp,arr[sx]);
        for(int i = 1;((dx+i)<sizeArr);i++){
            push(tmp,arr[dx+i]);
            push(tmp,arr[sx-i]);
        }
        *radice = tmp;
        return;  
    }else{
        //array dispari
        int center = sizeArr/2;
        tmp = newBST(NULL,arr[center]);
        for(int i = 1; ((center + i)<sizeArr) ;i++){
            push(tmp,arr[center+i]);
            push(tmp,arr[center-i]);
        }
        *radice = tmp;
        return;
    }

}










// ############################ FUNZIONI PER USO INTERNO ##############################
void internalToArr(BSTNodo *radice , int *arr,int cont,int size){
    if(radice == NULL){
        return;
    }else{
        if(cont >= size){return;}
        arr[cont] = radice->val;
        internalToArr(radice->sx,arr,cont+1,size);
        internalToArr(radice->dx,arr,cont+2,size);
    }
}