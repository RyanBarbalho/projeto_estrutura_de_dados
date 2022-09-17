import string

class node:
    def __init__(self, lista=None):
        self.lista = lista
        self.left_child= []
        self.right_child= []
        self.parent= None

class Arvore_binaria:
    def __init__(self):
        self.root= []
    
    ##insercao
    def insert(self, lista, size):
        if self.root==None:
            self.root=node(lista)
            print(f"raiz {lista}")
        else:
            self.insert_private(lista, self.root, size)
    
    ##insercao recursiva
    def insert_private(self, lista, node_atual, size):
        difference=0
        ##ver a diferenca entre os dois pra decidir pra qual lado vai
        for i in range (0, size):
            if(lista[i]!=node_atual[i]):
                difference+=1
                print(difference)
        ##a diferenca é -1 pq os nomes estao inclusos nas listas
        if  (difference-1)<=2:
            if node_atual.left_child==None:
                node_atual.left_child=node(lista)
                node_atual.left_child.parent=node_atual 
                
                print("esquerda" + node_atual)
            else:
                self.insert_private(lista, node_atual.left_child )
        elif (difference-1)>2 and (difference-1)<=size:
            if node_atual.right_child==None:
                node_atual.right_child=node(lista)
                node_atual.right_child.parent=node_atual 
                
                print("direita" + node_atual)
            else:
                self.insert_private(lista,  node_atual.right_child)
        else:
            print("O animal possui as mesmas caracteristicas! ")
    
    def print_Arvore(self):
        if self.root!=None:
            self.print_private(self.root)
    
    def print_private(self, node_atual):
        if node_atual!=None:
            self.print_private(node_atual.left_child)
            print(node_atual.lista)
            self.print_private(node_atual.right_child)
            
    
            
                     
print("Informe o numero de caracteristicas que deseja manter como parametro:")
num_car= int(input())

lista_raiz= [ ]

##criar o animal raiz 
print("Informe o animal raiz: ")
nome_raiz = input()
lista_raiz.append(nome_raiz)

for i in range(0, num_car):
    caracteristica = input(f"Informe a caracteristica {i+1}:").lower()
    lista_raiz.append(caracteristica)


lista_geral= []             ##criada a lista geral
lista_geral.append(lista_raiz)

##inserir animal ancestral na raiz da arvore
arvore=Arvore_binaria()
arvore.insert(lista_raiz, num_car)

##agora vamos adicionar proximos animais
print("Agora vamos desenvolver a Arvore")

while True:
    lista_individual = []
    
    answer= input("Deseja adicionar mais animais? (S / N)").lower()
    if(answer=='n'):
        break
    
    nome= input("Digite o nome do animal: ")
    lista_individual.append(nome)
    
    for i in range(0,num_car):
        caracteristica = input(f"Informe a caracteristica {i+1}:").lower()
        lista_individual.append(caracteristica)
    
    lista_geral.append(lista_individual)
    
    arvore=Arvore_binaria()
    arvore.insert(lista_individual, num_car)
    

##adicionar novos animais 
print=Arvore_binaria()
print.print_Arvore()


    
    





