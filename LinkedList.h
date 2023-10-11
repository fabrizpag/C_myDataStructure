

typedef struct node{
        int val;
        int index;
        struct node *next;
}Nodo;

const char *help();
Nodo *newLinkedListInt(Nodo *inizio,int valore);
Nodo *newLinkedListArrInt(Nodo *inizio,int arr[],int len);
int pushInt(Nodo *inizio,int v);
int popInt(Nodo *inizio);
int shiftInt(Nodo **inizio);
void printListInt(Nodo *inizio);


