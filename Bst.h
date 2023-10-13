// BinarySearchTree di prova

typedef struct node{
        int val;
        int index;
        struct node *sx;
        struct node *dx;
}BSTNodo;

BSTNodo *newBST(BSTNodo *radice,int v);
int pushInt(BSTNodo *radice,int v);
int heightBST(BSTNodo *radice);
void inorderTraversalToArray(BSTNodo *radice, int *array);
void printBST(BSTNodo *radice);
bool has(BSTNodo *radice,int v);
int length(BSTNodo *radice);
BSTNodo *findElement(BSTNodo *radice,int v);
BSTNodo *findPrevElement(BSTNodo *radice,int v);
BSTNodo *pushTopAndRebalance(BSTNodo *radice);
BSTNodo *removeElement(BSTNodo *radice,int v);
//alcune funzioni non sono funzionanti, altri non sono ottime