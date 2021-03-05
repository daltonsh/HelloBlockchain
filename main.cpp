// Coded by Dalton Shanholtz
// https://www.daltonshanholtz.com
// https://github.com/daltonsh/

/*
 * PLACE-HOLDER; Following is a basic implementation of a blockchain for educational purposes.
*/

//#include<bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

/* IDEAS
 * MINING EXPERIMENTAL = HAVE TO FIND A (INDEPENDENT) HASH GREATER THEN PREVIOUS BLOCK (ALWAYS INCREASING
 * IN DIFFICULTY). AKA HAVE TO HASH DATA + X NUMBER OF NONCES TO SUCCESSFULLY MINE!
*/

// Create a Block class with some attributes
class Block {

private:
    string data;
    int index, nonceValue, previousHashValue, hashValue;
    hash<string> hashString;

public:
    // Default/Genesis-Block-Constructor
    Block(double index, string data) {
        this->index = index;
        this->data = data;
        this->hashValue = signBlock(data)[0];
        this->nonceValue = signBlock(data)[1];
        previousHashValue = 0; // Set the previousHashValue to 0, to signify that it is the Genesis Block
        signBlock(data);
        printf("*** Genesis Block created!\n*** Block #%d (nonce:%d) has been created with "
               "Hash Value %d; (previous Hash:%d).\n", index, nonceValue, hashValue, previousHashValue);
    }

    // (General) Block Constructor
    Block(double index, string data, int previousHashValue) {
        this->index = index;
        this->data = data;
        this->hashValue = signBlock(data)[0];
        this->nonceValue = signBlock(data)[1];
        this->previousHashValue=previousHashValue;
        printf("\n*** Block #%d (nonce:%d) has been created with "
               "Hash Value %d; (previous Hash:%d).\n", index, nonceValue, hashValue, previousHashValue);
    }

    string getData() {
        return this->data;
    }

    int getNonceValue() {
        return this->nonceValue;
    }

    int getHashValue() {
        return this->hashValue;
    }

    int getPreviousHash() {
        return this->previousHashValue;
    }

    // Creates/Finds Hash; Also loops through to find a nonce to sign/validate the Block/Block's Hash
    vector<int> signBlock(string data) {
        int proposedNonce = 0;
        int proposedHash = hashString(data + to_string(proposedNonce));

        while( (proposedHash % 1000 ) != 0) {
            proposedNonce++;
            proposedHash = hashString(data + to_string(proposedNonce));
        }
        vector<int> signedSolution = { proposedHash, proposedNonce };
        return signedSolution;
    }

};

void printBlockchain(vector<Block> blockchain) {

    printf("\n~~~Current Blockchain");

    for(int i=1; i<blockchain.size(); i++) {
        cout << "~~~ " << blockchain[i].getData() << "(nonce:" << blockchain[i].getNonceValue() <<
                ")" << " /\\ Hash: " << blockchain[i].getHashValue() <<
                " /\\ Previous Hash: " << blockchain[i-1].getHashValue() << endl;
    }
};

int main() {

    // Creates Blockchain and adds the Genesis Block
    vector<Block> blockchain;
    Block segment0(blockchain.size(),"GENESIS BLOCK");
    blockchain.push_back(segment0);
    printBlockchain(blockchain);

    Block segment1(blockchain.size(),"First block placeholder", blockchain.end()->getHashValue());
    blockchain.push_back(segment1);
    printBlockchain(blockchain);

    Block segment2(blockchain.size(),"Second block placeholder", blockchain.end()->getHashValue());
    blockchain.push_back(segment2);
    printBlockchain(blockchain);

    Block segment3(blockchain.size(),"Third block placeholder", blockchain.end()->getHashValue());
    blockchain.push_back(segment3);
    printBlockchain(blockchain);

    Block segment4(blockchain.size(),"Fourth block placeholder", blockchain.end()->getHashValue());
    blockchain.push_back(segment4);
    printBlockchain(blockchain);

    return 0;
}
