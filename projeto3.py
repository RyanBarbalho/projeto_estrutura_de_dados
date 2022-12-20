ind = 0

class Node:
    def __init__(self, key, ind):
        self.name = key
        self.count = ind
        self.left = None
        self.right = None

        
def comparison(fatherlist, sonlist, size):
    resembles = 0
    for i in range (size):
        if fatherlist[i] == sonlist[i]:
            resembles+=1

    return resembles

def insertRoot(node, value):
    global ind
    self = Node(value, ind)
    ind+=1
    

def insert(root, LISTA , sonchar, value):
    global ind
     
    if not root:
        newnode = Node(value,ind)
        root = newnode
        ind += 1
    else:
        fatherchar = []

        index = root.count
        for i in range (4):
            fatherchar.append(LISTA[index].charac[i])
        #chamar funcao semelhanca
        resemblance = comparison(fatherchar, sonchar, 4)

        if resemblance <= 2: 
            if root.left == None:
                newnode = Node(value,ind)
                root.left = newnode
                ind += 1
            else:
                insert(root.left, LISTA, sonchar, value)
        elif resemblance > 2:
            
            if root.right == None:
                newnode = Node(value,ind)
                root.right = newnode
                ind += 1   
            else:
                insert(root.right, LISTA, sonchar, value)
#print inOrder
def printTree(root):
        if root.left:
            printTree(root.left)
        print(root.name)
        if root.right:
            printTree(root.right)

class lista:
    def __init__(root, name, car1,car2,car3,car4):
        root.name = name 
        root.charac = [car1,car2,car3,car4]
#criar lista         
LISTA = []
        
print("Digite o primeiro animal:")
name = input()
print("digite as 4 caracteristicas do animal: ", name)

caracteristic1 = input()
caracteristic2 = input()
caracteristic3 = input()
caracteristic4 = input()
object1 = lista(name,caracteristic1,caracteristic2,caracteristic3,caracteristic4)
LISTA.append(object1)

#criou a arvore com o animal raiz
tree = Node(name,ind)
ind+=1

printTree(tree)

op = 3
index = 1
string = "\ndigite\n\t1 para adicionar um animal a arvore\n\t2 para imprimir a arvore\n\t0 para sair\n:"
while op != 0:
    print(string)
    op = int(input())
    if op == 0:
        break       
    elif op == 1:
        print("digite o seu animal:")
        animalName = input()
        print("digite as 4 caracteristicas do animal:")
        caracteristic1 = input()
        caracteristic2 = input()
        caracteristic3 = input()
        caracteristic4 = input()
        newObject = lista(animalName, caracteristic1,caracteristic2,caracteristic3,caracteristic4)
        LISTA.append(newObject)
        insert(tree, LISTA, LISTA[index].charac, animalName)
        printTree(tree)
        print()
        index+=1
    elif op == 2:
        printTree(tree)
        
















