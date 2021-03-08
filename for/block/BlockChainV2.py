import hashlib

class Block():
    def __init__(self, index, data, previous_hash):
        self.index = index
        self.data = data
        self.previous_hash = previous_hash
        self.hash = self.hashing()

    def hashing(self):
        key = hashlib.sha256()
        key.update(str(self.index).encode('utf-8'))
        key.update(str(self.data).encode('utf-8'))
        key.update(str(self.previous_hash).encode('utf-8'))
        fullkey =  key.hexdigest()
        return fullkey[0:20]

class Chain():
    def __init__(self):  # initialize when creating a chain
        self.blocks = [self.get_genesis_block()]

    def get_genesis_block(self):
        return Block(0,'Genesis','arbitrary')

    def add_block(self, data):
        self.blocks.append(Block(len(self.blocks),data,self.blocks[len(self.blocks) - 1].hash))

def printBlock(i):
    print("Block", i)
    print("Data:", C.blocks[i].data)
    print("ShaastraFlag{", end="")
    j = i
    while (j < 1000):
        print("0", end="")
        j *= 10
    print(i, end="_")
    print(C.blocks[i].hash + "}")
    print("")


C = Chain()
C.add_block("I am Block 1")
C.add_block("I am Block 2")
C.add_block("I am Block 3")
C.add_block("I am Block 4")
C.add_block("I am Block 5")

while True:
    print("Menu :: ")
    print("1 - Add Block")
    print("2 - Print Chain")
    print("3 - Print Block")
    print("4 - About")
    print("5 - Quit")
    print("Choice :", end= " ")
    choice = int(input())

    if choice == 1 :
        print("Enter Data :",end=" ")
        s = input()
        C.add_block(s)
        print("Block Added!")
    elif choice == 2 :
        for i in range(1, len(C.blocks)):
            printBlock(i)
    elif choice == 3:
        print("Enter Index :", end=" ")
        i = int(input())
        if i >= len(C.blocks) or i <= 0:
            print("Wrong Index!")
        else:
            printBlock(i)
    elif choice == 4:
        print("""This is a rudimentary block chain,\neach block's hash is calculated with current\ndata and previous block's hash\n""");
    elif choice == 5:
        break
    else:
        print("Wrong Choice !!")


