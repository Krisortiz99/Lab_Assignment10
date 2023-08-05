#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Trie structure
struct Trie 
{
char word;
struct Trie* leaf;
};

// Inserts the word to the trie structure
void insert(struct Trie *pTrie, char *word)
{   
    if(pTrie->leaf == NULL){
        pTrie->leaf = createTrie();
    }
    pTrie->word = *word;

}

// computes the number of occurances of the word
int numberOfOccurances(struct Trie *pTrie, char *word)
{   int count = 0;
    int k = sizeof(pTrie);
    for (int i = 0; i < k; i++){
        if (pTrie->word == *word){
            count++;
        }
    }
    return count;
}

// deallocate the trie structure
struct Trie *deallocateTrie(struct Trie *pTrie)
{
    if (pTrie == NULL)
    return NULL;
    else{
        int i;
        for(i = 0; i < sizeof(pTrie); i++){
          if (pTrie->leaf !=NULL)
                *deallocateTrie(pTrie->leaf);
          free(pTrie);
        }   
    }
}

// Initializes a trie structure
struct Trie *createTrie()
{
    struct Trie* newTrie = malloc(sizeof(struct Trie));
    newTrie->word = NULL;
    newTrie->leaf = NULL;

    
    return newTrie;
}

// this function will return number of words in the dictionary,
// and read all the words in the dictionary to the structure words
int readDictionary(char *filename, char **pInWords)
{
}

int main(void)
{
	char *inWords[256];
	
	//read the number of the words in the dictionary
	int numWords = readDictionary("dictionary.txt", inWords);
	for (int i=0;i<numWords;++i)
	{
		printf("%s\n",inWords[i]);
	}
	
	struct Trie *pTrie = createTrie();
	for (int i=0;i<numWords;i++)
	{
		insert(pTrie, inWords[i]);
	}
	// parse lineby line, and insert each word to the trie data structure
	char *pWords[] = {"notaword", "ucf", "no", "note", "corg"};
	for (int i=0;i<5;i++)
	{
		printf("\t%s : %d\n", pWords[i], numberOfOccurances(pTrie, pWords[i]));
	}
	pTrie = deallocateTrie(pTrie);
	if (pTrie != NULL)
		printf("There is an error in this program\n");
	return 0;
}