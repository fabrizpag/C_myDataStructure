#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include "bst.h"

BSTNodo *newBST(BSTNodo *radice,int v){
    radice = malloc(sizeof(BSTNodo));
    radice->val = v;
    radice->sx=NULL;
    radice->dx=NULL;
    radice->index=1;
    return radice;
}
int pushInt(BSTNodo *radice,int v){
    if(radice->sx==NULL && radice->dx==NULL){
        BSTNodo *n = malloc(sizeof(BSTNodo));
        n->val=v;
        n->sx=NULL;
        n->dx=NULL;
        if(radice->val == v){
            return 0;
        }else{
            if(v < radice->val){
               radice->sx=n;
               n->index = 2;
                return 1;
            }else{
                radice->dx=n;
                n->index = 3;
                return 1;
            }
        }
    }
    BSTNodo *tmp = radice;
    while(true){
        if(v == tmp->val){
            return 0;
        }
        if(v > tmp->val){
            if(tmp->dx != NULL){
                tmp=tmp->dx;
            }
            else{
                break;
            }
        }else{
            if(tmp->sx != NULL){
                tmp=tmp->sx;
            }
            else{
                break;
            }
        }
    }
    if( v > tmp->val){
        BSTNodo *n = malloc(sizeof(BSTNodo));
        n->val=v;
        n->sx=NULL;
        n->dx=NULL;
        tmp->dx = n;
        n->index = (tmp->index)*2+1;
        return 1;

    } else {
        BSTNodo *n = malloc(sizeof(BSTNodo));
        n->val=v;
        n->sx=NULL;
        n->dx=NULL;
        tmp->sx = n;
        n->index = (tmp->index)*2;
        return 0;
    }
}
int heightBST(BSTNodo *radice) {
    if (radice == NULL) {
        return -1;  
    } else {
        int hsx = heightBST(radice->sx);
        int hdx = heightBST(radice->dx);
        
        return 1 + (hsx > hdx ? hsx : hdx);
    }
}

void inorderTraversalToArray(BSTNodo *radice, int *array) {
    if (radice == NULL) {
        return;
    }
    array[( radice->index -1 )] = radice->val;
    inorderTraversalToArray(radice->sx, array);
    inorderTraversalToArray(radice->dx, array);
}

void printBST(BSTNodo *radice){
    int h = heightBST(radice)+1;
    printf("altezza  bst: %d\n",h);
    int maxEl = pow(2, h)-1;
    int *arr = (int *)malloc(maxEl * sizeof(int));

    for (int i = 0; i < maxEl; i++) {
        arr[i] = 0; 
    }
    
    if(h==1){
        printf("%d",radice->val);
    }else{
        int *a = arr;
        inorderTraversalToArray(radice,a);
    }
    for(int i =0;i<maxEl;i++){
        printf("%d ",arr[i]);
    }
    

}