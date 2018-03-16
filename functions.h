//
// Created by eduar on 15/12/2017.
//

#ifndef TRABALHOFINALCPD_FUNCTIONS_H
#define TRABALHOFINALCPD_FUNCTIONS_H
#include "trie.h"

typedef struct arrayOfKeys{
    float key;
    char word[100];
    int satellite;
}arrayOfKeys;

void menu();
int mapASCII(char byte);
int ctoi(char byte);
void clean_format(char*str);
float standard_deviation(Lista *lista);
float variant_coefficient(float sT, float average);
float score_prediction(TrieNode*stopWords,TrieNode*trie, char*newComment);
float naive_prediction_withoutStopWords(TrieNode*stopWords,TrieNode*trie,char*newComment);
float naive_prediction(TrieNode*trie,char*newComment);
void  print_result(float result);
void  fileAssocComments(TrieNode*trie,char*word); //busca os comentarios e scores associados a uma determinada palavra
void holdout_method(TrieNode*trie,TrieNode*stopWords,char*fileName,float*result);
void search_rads(TrieNode*trie,char*searchRad);
void ranking(int numWords,int k);

#endif //TRABALHOFINALCPD_FUNCTIONS_H
