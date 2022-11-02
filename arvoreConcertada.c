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
}nodeRow; 

typedef struct row{
    
    nodeRow *first;
    nodeRow *last;
    int sizeRow;
}row;



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
        printf("\n%s\n", root->data);

        root -> count = ind;
        ind++;
        
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
            printf("\n%s vai a esquerda\n", name);
            root->left = insert(root->left, sonchar, name);
        }
        else if(resemblance>2){
                    //debug
            printf("\n%s vai a direita\n", name);
            root->right = insert(root->right, sonchar, name);
        }

    }

    return root;

}

int sizetree(node *root, int size){

if (root == NULL){
    return 0;
}
size = sizetree(root->left, size) + sizetree(root->right, size);
size ++;
return size;
}

void createRow(row *roow){

    roow->first = NULL;
    roow->last = NULL;
    roow->sizeRow = 0;

}

void insertRow(row *roow, char nameRow[]){ 
    nodeRow *new = malloc (sizeof(nodeRow));
    strcpy(new->nameInRow, nameRow);
    new->next = NULL;
      
   if(roow->first == NULL){
   
        roow->first = new;
        roow->last = new;
    }
    else{
        roow->last->next = new;
        roow->last = new;
    }
    roow->sizeRow++;
    nodeRow *aux = roow->first;
   

}
nodeRow *removeRow(row *roow){
    nodeRow *remove = NULL;
    if(roow->first != NULL){
        remove = roow->first;
        roow->first = remove->next;
        free(remove);
    }
    else{
        printf("lista vazia");
    }
}

void searchLoop(row *roow, char lookNode[], node *root){
    node *aux;
    //verifica se a lista ta vazia
    if(roow -> first == NULL){
        printf("\n\tno nao encontrado ;=;\n\t");
        
        return;
    }
    //se o primeiro elemento da lista for igual a o elemento procurado
    else if(strcmp(roow->first->nameInRow, lookNode) == 0){
        printf("\n\tno encotrado\n\t");
        printf("\t\n%s", roow->first->nameInRow);
        
        return;
    }
    //remove o primeiro elemento
    removeRow(roow);
    //adiciona os nos esquerdos e direitos na lista
    if(root->left != NULL){
        aux = root->left;
        insertRow(roow, aux->data);
        searchLoop(roow, lookNode, root->left);
    }else if(root->right != NULL){
        aux = root->right;
        insertRow(roow, aux->data);
        searchLoop(roow, lookNode, root->right);
    }
    searchLoop(roow, lookNode, root);
}

row *search(node *root, char lookNode[]) {
    //primeiro cria uma lista vazia
    row roow;
    createRow(&roow);
    //insere a raiz da arvore na lista
    insertRow(&roow, root->data);
    //chama a funçao recurisva que vai comparar
    searchLoop(&roow, lookNode, root);
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

    root = insert(root, animal[1].charac, animal[1].name );
    printf("\n");
    printTree(root);
    strcpy(animal[2].name,"broglas");

    char caracteristicos[][15] = {"gorgs", "cauda", "antenas", "asas"};
    //caracterisitcas filho
    for(int i = 0; i < 4 ; i++){
        strcpy(animal[2].charac[i], caracteristicos[i]);
    }
    root = insert(root, animal[2].charac, animal[2].name);
    printTree(root);

    strcpy(animal[3].name,"gralios");

    char caracteristicis[][15] = {"gorgs", "blindros", "antenas", "te"};
    //caracterisitcas filho
    for(int i = 0; i < 4 ; i++){
        strcpy(animal[3].charac[i], caracteristicis[i]);
    }
    root = insert(root, animal[3].charac, animal[3].name);

    printTree(root);

    strcpy(animal[4].name,"thrall");

    char caracteristices[][15] = {"caca", "blindros", "antenas", "te"};
    //caracterisitcas filho
    for(int i = 0; i < 4 ; i++){
        strcpy(animal[4].charac[i], caracteristices[i]);
    }
    root = insert(root, animal[4].charac, animal[4].name);
    printf("\n");
    printTree(root);



    strcpy(animal[5].name,"baine");

    char caracteristiczs[][15] = {"caca", "blindros", "antenas", "gorck"};
    //caracterisitcas filho
    for(int i = 0; i < 4 ; i++){
        strcpy(animal[5].charac[i], caracteristices[i]);
    }
    root = insert(root, animal[5].charac, animal[5].name);
    printf("\n");
    printTree(root);
    printf("\n");
    printf("agora procurar \n");
    int size;
    size = sizetree(root, 0);
    search(root, "Teste");
    printf("\n");
    search(root, "broglas");
    printf("\n");
    printTree(root);


}