#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Arvore
{
    char elem[10];
    struct Arvore *esquerda;
    struct Arvore *direita; 
}Arvore;

void imprimir(Arvore *raiz){
    if(raiz){
        printf("\n%s", raiz->elem);
        imprimir(raiz->esquerda);
        imprimir(raiz->direita);
    }
}

int funcao_comparacao(int j, int k, char *array[][10],int semelhanca, int tam)
{
    for(int i=0; i<tam; i++){

        if(array[i][j] == array[i][k]){ semelhanca++;}
    }
    return semelhanca;
}


void inserir(Arvore **raiz, int i, int j, int k, char animal[], char *matriz_car[][10]){
    if (*raiz == NULL){
        *raiz = malloc (sizeof (Arvore)); 
        strcpy((*raiz)->Arvore.elem, animal[i]);
        k= i;
        (*raiz)->esquerda = NULL;
        (*raiz)->direita = NULL;
       
    } else {
        int semelhanca;
        semelhanca = funcao_comparacao(j, k, matriz_car, 0, 4);
        if (semelhanca <= 2){
            inserir(&((*raiz)->esquerda), i, j, k, animal, matriz_car);
        } else{
            inserir(&((*raiz)->direita), i, j, k, animal, matriz_car);
        }
    }
}


int main(){
    Arvore *raiz = NULL;
    int op, i, j;
    i = 0;
    char matriz_ani[10], *matriz_car[4][10];
    printf("\nadcione o Animal ancestral:\n");
    scanf("%s", &matriz_ani[i]);
    printf("\nadcione as caracteristicas do animal ancestral:\n");
   
    for (j = 0; j < 4; j++){
        char array_car[10];
        scanf("%s", array_car);
        matriz_car[j][0] = array_car;
        
    }
    inserir(&raiz, 0, 0, 0, matriz_ani, matriz_car);
    

    while(op != 0){
        printf("para sair digite 0\npara adcionar animais digite 1\n");
        scanf("%d", &op);
        switch(op){

            case 0: 
            break;

            case 1:

            i++;
            printf("\ndigite seu animal\n");
            scanf("%s", &matriz_ani[i]);
            printf("\ndigite as caracteristicas do animal:\n");
            for (j = 0; j < 4; j++){
                char array_car[10];
                scanf("%s", array_car);
                matriz_car[j][0] = array_car;
            }
            //inserir recursivamente os animais na Arvore usando o animal anterior 

        }


    }


    // apos o loop while inserir a funcao de imprimir a arvore
    imprimir(//******//);

    
}