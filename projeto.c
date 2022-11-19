#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct lista{ //array de structs ->> informaçoes dos animais
    char name[15];
    int array[6];
    }
    animal[15];
typedef struct lista list;

struct listaEncadeada{
    char name[15];
    int distancia;
    //ponteiro que vai apontar para o proximo node da lista >>
    struct listaEncadeada* next;

};
typedef struct listaEncadeada node;

void print(node *head){

    while ( head!= NULL){
        printf("%s-(distancia:%d)-", head->name, head->distancia);
        head = head->next;
    }
    printf("\n");
}


node *createRoot(char animal[]){
    //alocar um novo node usando malloc
    node *result = malloc(sizeof(node));
    //o valor do node criado sera o valor fornecido 
    strcpy(result->name, animal);
    result ->next = NULL;
    result ->distancia = 00;

    return result;
}

node *createNode(char animal[], int distance){
    //alocar um novo node usando malloc
    node *result = malloc(sizeof(node));
    //o valor do node criado sera o valor fornecido 
    strcpy(result->name, animal);
    result -> distancia = distance;
    result ->next = NULL;

    return result;
}


node *insertAtBeginning(node *head, node *insertedNode){
    insertedNode->next = head;
    head = insertedNode;
    
    return insertedNode;

}


void insertAtEnd(node *head, node*insertedNode){
    node *i = head;
    while(i->next!=NULL){ 
        i = i -> next;
    }

    i -> next = insertedNode;
    insertedNode -> next = NULL;

}

int comparison( int sonList[], int size ){
    int aux = 0;
    for (int i = 0; i<size ; i++){
        aux += sonList[i];
    }
    if (aux == size){
        return 0;
    }
    aux = size - aux;

    return aux; 

}


int main()
{
    node *head = NULL;
    node *aux;
    //animal 1
    
    strcpy(animal[0].name, "animal_1");
    char caracteristicas[][15] = {"a1", "a2", "b3", "a4", "a5", "a6"};
    //insere animal raiz
    aux = createRoot(animal[0].name);
    head = insertAtBeginning(head, aux);

    strcpy(animal[1].name, "animal_2");
    int resemblance[] = { 1,0,0,1,0,1 };
    for (int i = 0; i< 6 ; i++){
        animal[1].array[i] = resemblance[i];
    }
    
    int distance = comparison(animal[1].array, 6);
    aux = createNode(animal[1].name, distance);
    insertAtEnd(head, aux);

    print(head);

    strcpy(animal[2].name, "animal_3");
    int resemblance_[] = { 1, 1, 1 , 1 , 1, 0 };
    for (int i = 0; i< 6 ; i++){
        animal[2].array[i] = resemblance_[i];
    }
    
    distance = comparison(animal[2].array, 6);
    aux = createNode(animal[2].name, distance);
    insertAtEnd(head, aux);
    ///

    strcpy(animal[3].name, "animal_4");
    int  resemblance__[] = {0,0,0,1,0,0};
    for (int i = 0; i< 6 ; i++){
        animal[3].array[i] =  resemblance__[i];
    }
    
    distance = comparison(animal[3].array, 6);
    aux = createNode(animal[3].name, distance);
    insertAtEnd(head, aux);

    ///

    strcpy(animal[4].name, "animal_5");
    int  resemblance___[] = {1,1,1,0,1,0};
    for (int i = 0; i< 6 ; i++){
        animal[4].array[i] = resemblance___[i];

    }

    
    distance = comparison(animal[4].array, 6);
    aux = createNode(animal[4].name, distance);
    insertAtEnd(head, aux);

    ///
    strcpy(animal[5].name, "animal_6");
    int  resemblance____[]  = {0,0,1,0,1,0};
    for (int i = 0; i< 6 ; i++){
        animal[5].array[i] = resemblance____[i];
    }
    
    distance = comparison(animal[5].array, 6);
    aux = createNode(animal[5].name, distance);
    insertAtEnd(head, aux);
    printf("\n");
    print(head);
    printf("\n");
    return 0;
}