/* libreria da eliminare*/

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
bool has(BSTNodo *radice,int v){
    if (radice == NULL) {
        return false; 
    }
    if (radice->val == v) {
        return true;
    }
    if (v < radice->val) {
        return has(radice->sx, v);
    } else {
        return has(radice->dx, v);
    }
}
int length(BSTNodo *radice){
    if(radice == NULL){
        return 0;
    }
    int sxSize = length(radice->sx);
    int dxSize = length(radice->dx);

    return 1 + sxSize + dxSize;
        
}
BSTNodo *findElement(BSTNodo *radice,int v){
    if(radice == NULL){
        return NULL;
    }
    if (radice->val==v){
        return radice;
    }
    BSTNodo *leftTree = findElement(radice->sx,v);
    if(leftTree != NULL){
        return leftTree;
    }
    return findElement(radice->dx,v);
}
BSTNodo *findPrevElement(BSTNodo *radice,int v){
    // funziona solo in BST con più di 1 elemento;
    if(radice->sx == NULL){
        return NULL;
    }
    if(radice->dx == NULL){
        return NULL;
    }
    if(radice->sx->val==v){
        return radice;
    }
    if(radice->dx->val==v){
        return radice;
    }
    BSTNodo *leftTree = findPrevElement(radice->sx,v);
    if(leftTree != NULL){
        return leftTree;
    }
    return findPrevElement(radice->dx,v);

}

BSTNodo *pushTopAndRebalance(BSTNodo *radice){
    BSTNodo *nBST;
    int h = heightBST(radice)+1;
    int maxEl = pow(2, h)-1;
    int *arr = (int *)malloc(maxEl * sizeof(int));
    for (int i = 0; i < maxEl; i++) {
        arr[i] = 0; 
    }
    
    if(h==1){
        free(radice);
        return NULL;
    }else{
        int *a = arr;
        inorderTraversalToArray(radice,a);
        if(maxEl == 2){
            free(radice);
            nBST = newBST(nBST,a[1]);
            return nBST;
        }else {
            free(radice);
            nBST = newBST(nBST,a[1]);
            for(int i =2;i<maxEl;i++){
                printf("el: %d",a[i]);
                pushInt(nBST,a[i]); // crea un elemento 0 non richiesto
                printf("\n ");
                printBST(nBST);
                printf("\n ");
            }
            printf("\n nuovo albero \n");
            printBST(nBST);
            printf("\n");
            return nBST;
        }
    }

}

BSTNodo *removeElement(BSTNodo *radice,int v){
    BSTNodo *toRet;
    BSTNodo *tmp1;
    BSTNodo *tmp2;
    BSTNodo *reb;
    if(radice == NULL){
        return NULL;
    }
    if(radice->sx==NULL&&radice->dx==NULL){
        if(radice->val == v){
            return NULL;
        }else{
            return radice;
        }
    }else{
        if(radice->val == v){
           toRet = pushTopAndRebalance(radice);
        }else{
          tmp1 = findElement(radice,v);
          if(tmp1 == NULL){
            return radice;
          }else{
            tmp2 = findPrevElement(radice,v);
          }
          if(tmp2->sx == tmp1){
            tmp2->sx = NULL;
            reb = pushTopAndRebalance(tmp1);
            tmp2->sx = reb;
            return radice;
          }else{
            tmp2->dx = NULL;
            reb = pushTopAndRebalance(tmp1);
            tmp2->dx = reb;
            return radice;
          }
        }
    }

    
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