import datetime as d  # import the datetime library for our block timestamp and rename it as d for simplicity while typing
import hashlib as h  # import the library for hashing our block data and rename it as h for simplicity while typing
import json

class Block:  # create a Block class
    def __init__(self, index, timestamp, data, prevhash, nonce):  # declare an initial method that defines a block, a block contains the following information
        self.index = index  # a block contains an ID
        self.timestamp = timestamp  # a block contains a timestamp
        self.data = data  # a block contains some transactions
        self.prevhash = prevhash  # a block contains a hash of the previous block
        self.nonce = nonce
        self.hash = self.hashblock()  # a block contains a hash, the hash is obtained by hashing all the data contained in the block
        



    def hashblock(self):  # define a method for data encryption, this method will retain a hash of the block
        s = str(self.index) + str(self.timestamp) + str(self.data) + str(self.prevhash) + str(self.nonce) # to encrypt the data in the block, We need just to sum everything and apply the hash function on it
        return h.sha256(s.encode()).hexdigest()  # let's return that hash result

    @staticmethod  # declaring a static method for the genesis block
    def genesisblock():  # delcare a function for generating the first block named genesis
        return Block(0, d.datetime.now(), "genesis block transaction", "0", "100")  # return the genesis block

    

    # @staticmethod  # let's declare another static method to get the next block
    # def newblock(lastblock,info):  # get the next block, the block that comes after the previous block (prevblock+1)
    #     index = lastblock.index + 1  # the id of this block will be equals to the previous block + 1, which is logic
    #     timestamp = d.datetime.now()  # The timestamp of the next block
    #     hashblock = lastblock.hash  # the hash of this block
    #     data = info  # The data or transactions containing in that block
    #     return Block(index, timestamp, data, hashblock)  # return the entire block

class Blockchain(Block):
    
    def __init__(self):
        self.chain = []
        self.difficulty = 3

    def initiate_chain(self):
        self.chain.append(Block.genesisblock())

    def previous_block(self):
        return self.chain[-1]

    def isValidHashDifficulty(self,hash):
        i = 0
        while(hash[i]=='0'):
            i=i+1
        return i>=self.difficulty

    def newblock(self,info):  # get the next block, the block that comes after the previous block (prevblock+1)
        lastblock = Blockchain.previous_block(self)
        index = lastblock.index + 1  # the id of this block will be equals to the previous block + 1, which is logic
        timestamp = d.datetime.now()  # The timestamp of the next block
        prevhash = lastblock.hash  # the hash of this block
        data = info  # The data or transactions containing in that block
        nonce=0
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
            print("index:",x.index)
            print("time:",x.timestamp)
            print("data:",x.data)
            print("prevhash:",x.prevhash)
            print("this hash:",x.hash)



    
blockchain = Blockchain()
blockchain.initiate_chain()
blockchain.newblock("Hi, This block was created by prakarsh")
blockchain.newblock("Hi, This block was created by aditya")
blockchain.newblock("Hi, This block was created by yuasbdan")
blockchain.print_chain()




    
    

    

    


