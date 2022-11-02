#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int ind = 0;

typedef struct tree
{
    char data[15];
    int count;
    struct tree *left;
    struct tree *right;

}node;

struct lista{
    char name[15];
    char charac[4][15];
    }
    animal[15];
typedef struct lista list;

typedef struct nodeRow{
    char nameInRow[15];
    struct nodeRow *next;
    struct nodeRow *first;
    struct nodeRow *last;
}row; 


row *createList(row *root){
    root = NULL;
    root -> first = NULL;
    root -> last = NULL;

}

void printTree(node *root)
{
    if(root != NULL){
        printf("(");
        printTree(root->left);
        printf("(%s)", root->data);
        printTree(root->right);
        printf(")");
    }
    else printf("( )");
}

//comparacao se as caracteristicas sao iguais
int comparison(int resembles , char fatherList[][15], char sonList[][15], int size){

    for(int i = 0; i < size ; i++){

        if (strcmp(fatherList[i], sonList[i]) == 0){
            
            resembles++;
            
        }
    }
    
    return resembles;

}

node *insertRoot(node *root, char name[]){
    if (root == NULL){
        root = malloc(sizeof(node));

        strcpy(root->data, name);
        root -> left = NULL;
        root -> right = NULL;
        //debug
        
        root -> count = ind;
        ind++;

        return root;
    } 
    else printf("raiz ja existe");
        return NULL;
}

// tirar o father char ->> tiramo                     //agora nao sabemos se da pra fazer isso aqui de declarar o array de struct nessa funçao, vamo ve
node *insert(node *root, char sonchar[][15], char name[]){

    if (root == NULL){
        //espaço eh alocado
        root = malloc(sizeof(node));
        //root -> data = name;
        strcpy(root->data, name);
        root -> left = NULL;
        root -> right = NULL;
        //debug
        

        root -> count = ind;
        ind++;
        return root;
    }
    else{
        //aqui vamos verificar a semelhança dele        /size v/
        //struct vai estar sendo chamado 
        //father char = node atual =>>>  animal[counter].charac[i]
        //index vai ser do node atual
        int index_ = root->count;
        char fatherchar[4][15];
        for(int i = 0; i < 4 ; i++){   //counter = animal anterior
            strcpy(fatherchar[i], animal[index_].charac[i]);
        }


        int resemblance = comparison(0, fatherchar , sonchar, 4);

        if(resemblance == 0){
            printf("animal %s nao valido\n", name);
            
        }
        else if(resemblance<=2){
             //debugzin
           
            root->left = insert(root->left, sonchar, name);
        }
        else if(resemblance>2){
                    //debug
            root->right = insert(root->right, sonchar, name);
        }

    }

}

void insertRow(row *roow, char nameRow[]){ 

    if(roow = NULL){
        row *newNode = malloc(sizeof(row));
        strcpy(newNode->nameInRow, nameRow);
        roow->first = newNode;
        newNode -> next = roow;
        row *aux = roow;
        while(aux != NULL){
            if(aux -> next == NULL){
                newNode -> last = aux;
                break;
            }
            aux = aux -> next;
        }
        
    }
    else{
        
        insertRow(roow->next, nameRow);
    }// ta somando valores nulos toda hora 

}
row *removeRow(row *roow){
    row *remove = NULL;
    if(roow->first != NULL){
        remove = roow->first;
        roow->first = remove->next;
        free(remove);
    }
    else{
        printf("lista vazia");
    }
}



void searchLoop(row *roow ,node *root, char lookNode[], int size, int visit[], int mark, char rowHead[], int i) {
    printf("aaaaaaa\n");
    node *aux = root; 
    //tamanho
    
    printf("%s\n", roow->first->nameInRow);

    strcpy(rowHead, roow->first->nameInRow);

    printf("%s\n", roow->first->nameInRow);
    //insere a informaçao na lista 
    //fazer outra funçao recursiva pra inserir os valores na lista
    if(root == NULL){
        printf("animal não encontrado");
        return;
    }    
    else if(strcmp(lookNode, rowHead) == 0){
        printf("achamoooos! o animal %s\n", lookNode);
        return;        
    }   
    else if(strcmp(lookNode, rowHead) != 0){
            searchLoop(roow ,root -> left, lookNode, size, visit, mark, rowHead, i);
            searchLoop(roow ,root-> right, lookNode, size, visit, mark, rowHead, i);
        }
    
            
    mark ++;

    if (visit[i] == 0){
        visit[i] = mark;
            if(root->left != NULL){
                aux = root->left;
                insertRow(roow, aux -> data);
                printf("%s", aux->data);
            }
                aux = root;
            if(root->right != NULL){
                aux = root->right;
                insertRow(roow, aux -> data);
                printf("%s", aux->data);
            }
            i++;
                
    }
    removeRow(roow);
    
}

void search(node *root, char name[], int size){
    row *roow = NULL;    //visit eh a quantidade de nos da arvore aq ta 2 por enquanto
    int x = 0, mark = 1, visit[2];
    char RowBegin[15];  
    
    for(int i = 0; i < size; i++){
        visit[i] = 0;
    }
    visit[x] = mark;
    printf("\naeaeow\n");

    insertRow(roow, name);
    searchLoop(roow ,root, name, size, visit, mark, RowBegin, x+1);
}

int main()
{   
    node *root = NULL;
    //pode ser setada a quantidade de animais a serem adicionados, por hora vamos definir 4
    // as caracteristicas ja foram limitadas como 4
    //contador de pai


    //primeiro animal
    strcpy(animal[0].name, "maceico");

    //caracteristicas do maceico
    char caracteristicas[][15] = {"pelo", "cauda", "antenas", "asas"};
    for(int i = 0; i < 4 ; i++){
        strcpy(animal[0].charac[i], caracteristicas[i]);
    }
    //animal raiz inserido 
    root = insertRoot(root, animal[0].name);
    //adicionar os proximos animais
    printTree(root);
    //nome filho
    strcpy(animal[1].name,"abe");

    char caracteristics[][15] = {"caca", "as", "antenas", "te"};
    //caracterisitcas filho
    for(int i = 0; i < 4 ; i++){
        strcpy(animal[1].charac[i], caracteristics[i]);
    }

    //definicao do pai para usar na insercao dos filhos 
    //char fatherchar[4][15];
    //for(int i = 0; i < 4 ; i++){   //counter = animal anterior
    //    strcpy(fatherchar[i], animal[counter].charac[i]);
    //}

    insert(root, animal[1].charac, animal[1].name );
    printf("\n");
    printTree(root);

    search(root, "abe", 2);

}
