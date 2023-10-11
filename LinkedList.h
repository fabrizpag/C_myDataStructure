

typedef struct node{
        int val;
        int index;
        struct node *next;
}Nodo;

Nodo *newLinkedListInt(Nodo *inizio,int valore);
Nodo *newLinkedListArrInt(Nodo *inizio,int arr[],int len);
int push(Nodo *inizio,int v);
int popInt(Nodo *inizio);
void printListInt(Nodo *inizio);


