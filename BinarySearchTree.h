// alberi binari di ricerca per numeri interi, sono ammessi solo elementi diversi

typedef struct node{
        int val;
        struct node *sx;
        struct node *dx;
        struct node *padre;
}BSTNodo;


BSTNodo *newBST(BSTNodo *radice, int v); // fatto
BSTNodo *newBSTarr(BSTNodo *radice, int *arr,int size); // fatto
int height(BSTNodo *radice);
void balanceTree(BSTNodo **radice); // non ottimo ma funzionante :)
int numEl(BSTNodo *radice); // fatto
int *toArr(BSTNodo *radice , int *arr); // fatto
void push(BSTNodo *radice, int v); // fatto
int pop(BSTNodo **radice);

        // funzioni per uso interno
void internalToArr(BSTNodo *radice , int *arr,int cont,int size); //fatto