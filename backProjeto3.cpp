#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<graphics.h>
#include<conio.h>
#define LEFT 1
#define RIGHT 2
int ind = 0;
int count =0;
int position = 3;




typedef struct tree
{
    char data[15];
    int count;
    int x;
    int y;
    struct tree *left;
    struct tree *right;

}node;

struct lista{
    char name[15];
    char charac[4][15];
    }
    animal[15];
typedef struct lista list;



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
        root = (struct tree*)malloc(sizeof(node));

        strcpy(root->data, name);
        root -> left = NULL;
        root -> right = NULL;
        //debug
        root->x = 320;
        root->y = 50;
        root -> count = ind;
        ind++;
        //desenha o node
        circle(root->x, root->y, 28);
        outtextxy(root->x-20, root-> y-10, name);

        return root;
    } 
    else return NULL;
}

// tirar o father char ->> tiramo                  
node *insert(node *root,char sonchar[][15], char name[], int X, int Y, int fatherx, int fathery, int level){
    
    if (root == NULL){
        //espaço eh alocado
        root = (struct tree*)malloc(sizeof(node));
        //root -> data = name;
        strcpy(root->data, name);
        root -> left = NULL;
        root -> right = NULL;
        root->x = X;
        root->y = Y;

        circle(root->x, root->y, 28);
        outtextxy(root->x-20, root-> y-10, name);
        
        line(X, Y, fatherx, fathery);
        
        root -> count = ind;
        ind++;

        //desenha o node
        
    }
    else{
        //father char = node atual =>>>  animal[counter].charac[i]
        //index vai ser do node atual
        int index_ = root->count; // index é a localizaçao do node
        char fatherchar[4][15];
        for(int i = 0; i < 4 ; i++){   
            strcpy(fatherchar[i], animal[index_].charac[i]);
        }


        int resemblance = comparison(0, fatherchar , sonchar, 4);

        if(resemblance == 0){
            return NULL;
        }//esquerda
        else if(resemblance<=2){
            //atualiza coordenada do filho
            int newx;
            int newy; 
            if(level%2==0){
                newx = root->x-100;
                newy = root->y+60;

            }
            else{
                newx = root->x-60;
                newy = root->y+70;
            }
            
            root->left = insert(root->left, sonchar, name, newx, newy, root->x, root->y,level+1);
        }//direita
        else if(resemblance>2){
            //atualiza coordenada 
            int newx;
            int newy;
            if(level%2==0){
                newx = root->x+90;
                newy = root->y+60;

            }
            else{
                newx = root->x+50;
                newy = root->y+70;
            }
            
            root->right = insert(root->right, sonchar, name, newx, newy, root->x, root->y, level+1);
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

int main(int argc, char const *argv[])
{   
 
    FILE *arq = fopen("entry.txt", "r");



    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int index = 0;
    int op = 4;
    // char lookNode[15];

    // cria a arvore
    node *root = NULL;
    //     //adicionado o primeiro animal:
    fscanf(arq, "%s", animal[0].name);
    
    for (int i = 0; i < 4; i++)
    {
        fscanf(arq, "%s", animal[0].charac[i]);
    }
    // animal raiz inserido
    root = insertRoot(root, animal[0].name);
    // mostrando o animal raiz
    while(fscanf(arq, "%d", &op)!=EOF){
        
        switch (op)
        {
        case 0:
            break;

        case 1:
            index++;
            fscanf(arq, "%s", animal[index].name);
    
            for (int i = 0; i < 4; i++)
            {
                fscanf(arq, "%s", animal[index].charac[i]);
            }
            root = insert(root, animal[index].charac, animal[index].name,0,0,0,0,0);

            break;
        case 2:
            break;
        }
        
    }

    fclose(arq);
    getch();
    closegraph();
    return 0;

}
