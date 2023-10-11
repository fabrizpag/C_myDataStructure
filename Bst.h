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