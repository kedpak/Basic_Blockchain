#include <ctime>
#include <vector>

using namespace std;

// Transaction Data for the blockchain
struct TransactionData {
    double quantity;
    string senderKey;
    string receiverKey;
    time_t timestamp;
}

// Block class

class Block{
    private:
        int index;
        size_t blockHash;
        size_t previousHash;
        size_t generateHash();

    public:
        //constructor
        Block(int index, TransactionData data, size_t prevHash);

        // Get original hash
        size_t getHash();

        // Get previous hash
        size_t getPreviousHash();

        // Transaction data
        TransactionData data;

        // Validate hash
        bool isHashValid();

}


// Constructor with paramaters
Block::Block(int index, TransactionData data, size_t prevHash)
{
    index = index;
    data = data;
    previousHash = prevHash;
    blockHash = genereateHash();
}

// private functions
size_t Block::generateHash() 
{
    hash<string> hash1;
    hash<size_t> hash2;
    hash<size_t> finalHash;
    string toHash = to_string(data.amount) + data.receiverKey + data.senderKey + to_string(data.timestamp);

    return finaHash(hash1(toHash) + hash2(previousHash));
}


size_t Block::getHash()
{
    return blockHash;
}

size_t Block:: getPreviousHash()
{
    return previousHash;
}

bool Block::isHashValid()
{
    return generateHash() == blockHash;
}



// Blockchain class

class Blockchain {
    private:
        Block createGenesisBlock();

    public:
         vector<Block> chain;

         Blockchain();

         void addBlock(TransactionData data);
         void 
}