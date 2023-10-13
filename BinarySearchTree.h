// alberi ninari di ricerca per numeri interi, sono ammessi solo elementi diversi

typedef struct node{
        int val;
        struct node *sx;
        struct node *dx;
        struct node *padre;
}BSTNodo;


BSTNodo *newBST(BSTNodo *radice, int v);
BSTNodo *newBSTarr(int *arr);
int height(BSTNodo *radice);
void balanceTree(BSTNodo **radice);
int *toArr(BSTNodo *radice);
void push(BSTNodo *radice, int v);
int pop(BSTNodo **radice);