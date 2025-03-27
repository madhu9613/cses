#include<bits/stdc++.h>
using namespace std;


class trienode
{
public:
    char data;
    trienode *children[2]; // Store children of each node
    bool isendofword;       // Flag to mark the end of the word 

    // Constructor to initialize a Trie node
    trienode(char data)
    {
        this->data = data;
        for (int i = 0; i < 2; i++)
        {
            children[i] = NULL;
        }
        isendofword = false;
    }
};

class trie
{
private:
    void insert(trienode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isendofword = true; // Mark the last node as the end of the word
            return;
        }

        int index =word[0] - '0'; // Convert to lowercase and find the index
        trienode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new trienode(word[0]);
            root->children[index] = child;
        }

        insert(child, word.substr(1)); // Recursive call with the rest of the word
    }

   

public:
    trienode *root;

    // Constructor to initialize the root node of the Trie
    trie()
    {
        root = new trienode('\0'); // Create an empty root node
    }

    // Public function to insert a word into the Trie
    void insertword(string word)
    {
        insert(root, word);
    }
};
int main()
{
    return 0;
}