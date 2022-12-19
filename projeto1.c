#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista
{ // array de structs ->> informaçoes dos animais
    char name[15];
    int array[6];
} animal[15];
typedef struct lista list;

struct listaEncadeada
{
    char name[15];
    int distancia;
    int marked;
    // ponteiro que vai apontar para o proximo node da lista >>
    struct listaEncadeada *next;
};
typedef struct listaEncadeada node;

//bubble sort simples
void bubbleSort(int array[], int size){
	int aux;    
	for(int j=size-1; j>=1; j--){
		for(int i=0; i<j; i++){
			if(array[i]>array[i+1]){
				aux=array[i];
                    array[i]=array[i+1];
                    array[i+1]=aux;
            }
        }
    }
}

void print(node *root)
{
    while (root != NULL)
    {
        printf("%s-(distancia:%d)-", root->name,root->distancia);
        root = root->next;
    }
    printf("\n");
}
//cria a raiz
node *createRoot(char animal[])
{
    // alocar um novo node usando malloc
    node *result = malloc(sizeof(node));
    // o valor do node criado sera o valor fornecido
    strcpy(result->name, animal);
    result->next = NULL;
    result->distancia = 0;
    result ->marked = 0;

    return result;
}

node *createNode(char animal[], int distance)
{
    // alocar um novo node usando malloc
    node *result = malloc(sizeof(node));
    // o valor do node criado sera o valor fornecido
    strcpy(result->name, animal);
    result->distancia = distance;
    result->next = NULL;
    result->marked = 0;

    return result;
}


//insere no começo da lista
node *insertAtBeginning(node *head, node *insertedNode)
{   
    if(insertedNode -> distancia != 0){
        insertedNode->next = head;
        head = insertedNode;
    }
    return insertedNode;
}
//insere no final da lista
void insertAtEnd(node *head, node *insertedNode)
{
    node *i = head;
    while (i->next != NULL)
    {
        i = i->next;
    }

    i->next = insertedNode;
    insertedNode->next = NULL;
}

//compara as informaços do node inserido com o animal raiz
int comparison(int sonList[], int size)
{
    int aux = 0;
    for (int i = 0; i < size; i++)
    {
        aux += sonList[i];
    }
    if (aux == size)
    {
        return 0;
    }
    aux = size - aux;

    return aux;
}

// reordena a lista
void reorderLoop(node *root[], node* newList, int distances[], int size){
    for(int i=0 ; i<size ; i++){
        for(int j = 0 ; i < size; j++){
            if((root[j]->distancia == distances[i]) && root[j] -> marked == 0 ){
                insertAtEnd(newList, root[j]);
                root[j]->marked = 1;
                break;
            }
        }
    }
}
//primeiro, insere a raiz, depois cria um array distancias e ordena eles para servirem como parametro da reordenaçao da lista
void reorder(node *root[], int number)
{ 
    int small = 6;
    node *newList = NULL;
    newList = insertAtBeginning(newList, root[0]);
    printf("\n");


    int distances[number];
    for(int i=0; i< number; i++){
        distances[i] = root[i]->distancia;
    }
    int aux;

    bubbleSort(distances, number);

    reorderLoop(root, newList, distances, 6);
    print(newList);


}
int main()
{
    node *head = NULL;
    node *aux[10];

    // animal 1

    strcpy(animal[0].name, "animal_1");
    char caracteristicas[][15] = {"a1", "a2", "b3", "a4", "a5", "a6"};
    // insere animal raiz
    aux[0] = createRoot(animal[0].name);
    head = insertAtBeginning(head, aux[0]);

    strcpy(animal[1].name, "animal_2");
    int resemblance[] = {1, 0, 0, 1, 0, 1};
    for (int i = 0; i < 6; i++)
    {
        animal[1].array[i] = resemblance[i];
    }

    int distance = comparison(animal[1].array, 6);
    aux[1] = createNode(animal[1].name, distance);
    insertAtEnd(head, aux[1]);

    print(head);

    strcpy(animal[2].name, "animal_3");
    int resemblance_[] = {1, 1, 1, 1, 1, 0};
    for (int i = 0; i < 6; i++)
    {
        animal[2].array[i] = resemblance_[i];
    }

    distance = comparison(animal[2].array, 6);
    aux[2] = createNode(animal[2].name, distance);
    insertAtEnd(head, aux[2]);
    ///

    strcpy(animal[3].name, "animal_4");
    int resemblance__[] = {0, 0, 0, 1, 0, 0};
    for (int i = 0; i < 6; i++)
    {
        animal[3].array[i] = resemblance__[i];
    }

    distance = comparison(animal[3].array, 6);
    aux[3] = createNode(animal[3].name, distance);
    insertAtEnd(head, aux[3]);

    ///

    strcpy(animal[4].name, "animal_5");
    int resemblance___[] = {1, 1, 1, 0, 1, 0};
    for (int i = 0; i < 6; i++)
    {
        animal[4].array[i] = resemblance___[i];
    }

    distance = comparison(animal[4].array, 6);
    aux[4] = createNode(animal[4].name, distance);
    insertAtEnd(head, aux[4]);

    ///
    strcpy(animal[5].name, "animal_6");
    int resemblance____[] = {0, 0, 1, 0, 1, 1};
    for (int i = 0; i < 6; i++)
    {
        animal[5].array[i] = resemblance____[i];
    }

    distance = comparison(animal[5].array, 6);
    aux[5] = createNode(animal[5].name, distance);
    insertAtEnd(head, aux[5]);
    printf("\n");
    print(head);
    printf("\n");
    
    reorder(aux, 6);

    return 0;
}
