//
// Created by eduar on 08/12/2017.
//
#include "trie.h"
#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_node(TrieNode*node,int index){ // printa as infos de relevancia de um nodo
    fputs(node->word[index],stdout);
    printf(":\tnumEntries %d\tAverage Score %.2f\t",node->numEntries[index],node->averageScore[index]);
    printf("arv: %d",index);
    printf("Node Address: %p\t", (void *)node);
    printf("\n");
}

TrieNode* getNewNode(){  //aloca um nodo novo e inicializa ele
    int j;
    TrieNode *newNode = (TrieNode*)malloc(sizeof(TrieNode));
    for(j=0;j<26;j++){
        newNode->numEntries[j] = 0; //zera todos os campos do novo nodo
        newNode->sumScore[j] = 0; //NULL em todos ponteiros de todas as chaves
        newNode->isEndOfWord[j] = 0;
        newNode->children[j] = NULL;
        newNode->listOfScoresComments[j]=NULL;
        strcpy(newNode->word[j],"\0");
    }
    return newNode;
}

int print_trie(TrieNode*trie, int bool){  //funcao que printa a arvore em bool = 0: console, bool = 1: arquivo
    FILE*arq;
    static int numWords=0;
    arq = fopen("list_of_words.txt","a");
    int i;
    for(i=0;i<26;i++) {
        if (trie->children[i] != NULL)
            print_trie(trie->children[i],bool);

        if (trie->isEndOfWord[i]!=0 && strlen(trie->word[i]) != 0){
            if(!bool)
                print_node(trie,i);
            else
                fprintf(arq,"%d %f ",trie->numEntries[i],trie->averageScore[i]);
                fputs(trie->word[i],arq);
                putc('\n',arq);
                numWords++;
        }
    }
    fclose(arq);
    return numWords;
}

TrieNode*search_trie(TrieNode*trie,char*searchKey) {  //procura por uma palavra na arvore e retorna o nodo dela
    TrieNode *aux = trie;
    int lengthKey = strlen(searchKey);
    int i, index;
    for (i = 0; i<lengthKey; i++) {
        index = mapASCII(searchKey[i]);
        if (aux->children[index] != NULL)
            aux = aux->children[index];
        else
            break;
    }
    if(!strcmp(searchKey,aux->word[index])){
        return aux;
    }
    else
        return NULL;
}

TrieNode* insert_trie(TrieNode* trie,char*newKey,int score,char*comment){   //Complexity: O(lenghtKey)
    score++;
    int lengthKey = strlen(newKey);  // tamanho da chave é a profundidade em que iremos na chave para salvá-la
    int index, i = 0;
    if(trie == NULL)
        trie = getNewNode();
    TrieNode*aux = trie;

    while(i<lengthKey){
        index = mapASCII(newKey[i]);
        if(index<0)
            index = 26;
        if(aux->children[index] == NULL)
            aux->children[index] = getNewNode();

        aux = aux->children[index];
        i++;
    }

    if(aux->isEndOfWord[index]==0) {  //se essa palavra não existe na arvore, salva ela no nodo e marca como fim de palavra
        aux->isEndOfWord[index] = 1;
        aux->numEntries[index] = 1;
        aux->sumScore[index] = score;
        aux->averageScore[index] = (float)score; //salva a nota media associada aquela palavra
        strncpy(aux->word[index], newKey, lengthKey);
        aux->listOfScoresComments[index] = insert_lista(aux->listOfScoresComments[index],(float)score,comment); //lista dos S1, S2, ...,Sn scores que serão usados pro cáculo do coeficiente de variancia da palavra.

    }
    else {
        aux->numEntries[index]++; //se ela ja existir apenas atualiza o número de vezes que ela entrou na arvore
        aux->sumScore[index] += score;
        aux->listOfScoresComments[index] = insert_lista(aux->listOfScoresComments[index],(float)score,comment);
        aux->averageScore[index] = (float)(aux->sumScore[index])/(float)(aux->numEntries[index]);
    }
    return trie;
}

Lista* insert_lista(Lista* lista, float score,char*comment) {
    Lista*aux=lista;
    Lista*novo = (Lista*)malloc(sizeof(Lista)); //cria novo nodo para ser inserido (palavra vinda da estrutura que armazena o dicionario)
    novo->score = score;
    strcpy(novo->comment,comment);
    if(lista==NULL){
        novo->prox=NULL;
        lista=novo; //lista vazia retorna o elemento criado
    }
    else {
        while (aux->prox != NULL)
            aux = aux->prox;  //vai até o fim da lista e salva o nodo na ultima posição

        aux->prox = novo;
        novo->prox = NULL;
    }
    return lista;
}

void save_list(TrieNode*trie, int index){ //salva em arquivo a lista de comentarios e scores associados a uma determinada palavra.
    Lista*aux = trie->listOfScoresComments[index];
    FILE*arq;
    arq=fopen("file_assocComments.txt","w");
    while(aux!=NULL){
        fprintf(arq,"%.0f ",aux->score);
        fputs(aux->comment,arq);
        aux = aux->prox;
    }
    fclose(arq);
}
