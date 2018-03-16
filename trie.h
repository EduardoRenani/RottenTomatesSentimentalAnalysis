//
// Created by eduar on 08/12/2017.
//
#ifndef TRABALHOFINALCPD_TRIE_H
#define TRABALHOFINALCPD_TRIE_H

typedef struct linkedlist{
    float score;
    char comment[10000];
    struct linkedlist *prox;
}Lista;

typedef struct TrieNode{
    struct TrieNode *children[26];
    int isEndOfWord[26]; //cada indice do nodo tem uma letra, cada letra pode ter uma palavra associada. Essa palavra associada é marcada pela flag fim de palavra. Logo, cada letra tem uma flag
    char word[26][100];//cada indice do nodo tem uma letram cada letra pode ter uma palavra associada.
    int numEntries[26];//cada indice do nodo tem uma letram cada letra pode ter uma palavra associada. Essa palavra associada tem um número de vezes que foi inserida na arvore
    int sumScore[26];//ainda, contem um somador das notas de cada vez que foi inserida
    float averageScore[26];//logo, também tem uma nota media associada
    Lista*listOfScoresComments[26]; //lista que contém o conjunto de notas e comentários daquela palavra
}TrieNode;

Lista *insert_lista(Lista* lista, float score, char*comment);
void save_list(TrieNode*trie, int index);
TrieNode* getNewNode();
void print_node(TrieNode*node,int index);
int print_trie(TrieNode*trie,int bool);
TrieNode* search_trie(TrieNode*trie,char*searchKey);
TrieNode* insert_trie(TrieNode*trie,char*newKey,int score,char*comment);


#endif //TRABALHOFINALCPD_TRIE_H
