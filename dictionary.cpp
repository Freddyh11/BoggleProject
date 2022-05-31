#include "dictionary.h"

Dictionary::Dictionary()//default
{
    root = new Node;
    root->flag = false;
    numWords = 0;
}

Dictionary::~Dictionary(){}//decon

void Dictionary::addWord(string word)//add word 
{
    currNode = root;
    
    for(int i = 0; i < word.length(); i++) {
        
        int index = (int)word[i] - (int)'a';
        
        if(currNode->arr[index] == NULL) {
            currNode->arr[index] = new Node;
            counter++;
            (currNode->arr[index])->flag = false;
        }
        
        currNode = currNode->arr[index];
    }
    
    currNode->flag = true;
    numWords++;
    currNode = NULL;
}

void Dictionary::deleteNodes(Node* node) //delete Node(s)
{
    for(int i = 0; i < MAX; i++) {
        if (node->arr[i] != NULL) {
            deleteNodes(node->arr[i]);
            delete node->arr[i];
            counter--;
        } 
    }
    //cout << "Counter" << endl;
    //cout << counter << endl;
}

bool Dictionary::isWord(string word)//checks to see if word correct
{
    currNode = root;
    bool isWord = false;
    
    for(int i = 0; i < word.length(); i++) {
        
        int index = (int)word[i] - (int)'a';
  
        if(currNode->arr[index] == NULL)
            return false;
        
        isWord = currNode->arr[index]->flag;
        currNode = currNode->arr[index];
        
    }
    
    currNode = NULL;
    return isWord;
}

bool Dictionary::isPrefix(string word)//checks see if string is a prefix of another
{
    currNode = root;
    
    for(int i = 0; i < word.length(); i++) {
        
        int index = (int)word[i] - (int)'a';
        
        if(currNode->arr[index] == NULL)
            return false;
        
        currNode = currNode->arr[index];
    }
    
    currNode = NULL;
    return true;
}

void Dictionary::PrintWords(string prefix)//prints the words in Node
{
    currNode = root;
    
    for(int i = 0; i < prefix.length(); i++) {
        
        int index = (int)prefix[i] - (int)'a';
        
        currNode = currNode->arr[index];
    }
    
    for(int i = 0; i < 26; i++) {
        
        char letter = (int)'a' + i;
        
        PrintHelper(currNode->arr[i], prefix+letter);
    }
    currNode = NULL;
}

void Dictionary::PrintHelper(Node* startNode, string prefix)//helps print words from node
{
    if(startNode == NULL)
         
        return;
    
    if(startNode->flag)
        cout << prefix << endl;
    
    for(int i = 0; i < 26; i++) {
        
        char letter = (int)'a' + i;
        
        PrintHelper(startNode->arr[i], prefix+letter);
    }
}

int Dictionary::wordCount()//getter to return the number of words 
{
    return numWords;
}

