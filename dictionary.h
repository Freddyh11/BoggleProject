#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 26;//limit amount of nodes
const int ROW = 4;//rows 
const int COL = 4;//columns

struct Node {
	Node *arr[MAX];
	bool flag;

	Node() //default to create array
	{
		for(int i = 0; i < MAX; i++) 
			arr[i] = NULL;	 
	}
};

class Dictionary { 
public:
	Dictionary();//default
	~Dictionary();//decon
	int counter = 0;//counter
	void addWord(string word);//add word function
	bool isWord(string word);//check to see if input is string
	bool isPrefix(string word);//true or false to check word
	void PrintWords(string prefix);//prints the word
	void deleteNodes(Node*);//delete node
	void PrintHelper(Node *startNode, string prefix);//helps the print function print words
	int wordCount();//getter to return number of words

	Node *root;
	Node *currNode;
	int numWords;
};
	
