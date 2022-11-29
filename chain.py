import datetime as d  
import hashlib as h  
import json

class Block:  
    def __init__(self, index, timestamp, data, prevhash, nonce):  
        self.index = index  
        self.timestamp = timestamp  
        self.data = data  
        self.prevhash = prevhash  
        self.nonce = nonce
        self.hash = self.hashblock()  
        



    def hashblock(self):  
        s = str(self.index) + str(self.timestamp) + str(self.data) + str(self.prevhash) + str(self.nonce) 
        return h.sha256(s.encode()).hexdigest()  

    
    def genesisblock():  
        return Block(0, d.datetime.now(), "genesis block transaction", "0", "100")  
    


class Blockchain(Block):
    
    def __init__(self):
        self.chain = []
        self.difficulty = 4

    def initiate_chain(self):
        self.chain.append(Block.genesisblock())

    def previous_block(self):
        return self.chain[-1]

    def isValidHashDifficulty(self,hash):
        i = 0
        while(hash[i]=='0'):
            i=i+1
        return i>=self.difficulty

    def newblock(self,info):  
        lastblock = Blockchain.previous_block(self)
        index = lastblock.index + 1  
        timestamp = d.datetime.now()  
        prevhash = lastblock.hash  
        data = info  
        nonce = 0
        block = Block(index, timestamp, data, prevhash, nonce)
        
        while Blockchain.isValidHashDifficulty(self,block.hash)==False:
            block.nonce = nonce+1
            block.timestamp = d.datetime.now()
            block.hash = Block.hashblock(block)

        self.chain.append(block)

    def isValidChain(self):
        if json.dumps(self.chain[0]) != json.dumps(Block.genesisblock()):
            return False
        return True

    def print_chain(self):
        for x in self.chain:
            print("```````````")
            print("index:",x.index)
            print("time:",x.timestamp)
            print("data:",x.data)
            print("prevhash:",x.prevhash)
            print("this hash:",x.hash)
            print("nonce:",x.nonce)
            print("```````````")


    
blockchain = Blockchain()
blockchain.initiate_chain()
blockchain.newblock("Hi, This block was created by prakarsh")
# blockchain.newblock("Hi, vkhsadfadsikljdkajds")
blockchain.newblock("Hi, This block was created by yuasbdan")
blockchain.print_chain()
