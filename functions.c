//
// Created by eduar on 15/12/2017.
//

#include "functions.h"
#include "trie.h"
#include "heap.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
const int COMMENTS_SIZE = 10000;
void menu(){
    printf("Escolha uma opcao de acao:\n");
    printf("1) Classificar um novo comentario a partir da entrada de teclado\n");
    printf("2) Identificar as K palavras mais negativas, K mais positivas e K mais frequentes\n");
    printf("3) Classificar um conjunto de novos comentarios a partir de um arquivo de texto\n");
    printf("4) Buscar comentarios associados a palavras\n");
    printf("5) Buscar palavras usando radicais\n");
    printf("6) Pressione '6' para encerrar\n");
}
int mapASCII(char byte){
    return (byte - 'a');
}

int ctoi(char byte){
    return (byte - '0');
}

void clean_format(char*str){
    if(str[strlen(str)-1]=='\n' || str[strlen(str)-1]=='\r')
        str[strlen(str)-1]=0;
    else if(str[strlen(str)-1]=='\n' && str[strlen(str)-2]=='\r')
        str[strlen(str)-2]=0;
    else
        str[strlen(str)]=0;
}

float standard_deviation(Lista* lista){  //funcao que calcula o desvio padrao das notas associadas a uma palavra
    float i=0, m=0, media=0, sigma=0, p=0;
    Lista*aux;

    for(aux = lista ;aux != NULL; aux = aux->prox){
        m = m + aux->score;
        i++;
    }
    media = m /i;
    if(i==1)
        return 0;
    else {
        i = 0;
        for (aux = lista; aux != NULL; aux = aux->prox) {
            p = p + pow(aux->score - media, 2);
            i++;
        }
        sigma = sqrt(p /(i-1));
        return sigma;
    }
}

float variant_coefficient(float sT, float average){ //calcula o coeficiente de variacao de um conjunto de notas associado a uma palavra
    return sT/average;
}

void  print_result(float result){
    if(result>=3.00) {
        printf("\n O comentario tem um escore medio de: %.4f\n", result);
        printf("sentimento positivo\n");
    }
    else if(result<2.0){
        printf("\n O comentario tem um escore medio de: %.4f\n", result);
        printf("sentimento negativo\n");
    }
    else{
        printf("\n O comentario tem um escore medio de: %.4f\n", result);
        printf("sentimento neutro\n");
    }
}

void fileAssocComments(TrieNode*trie,char*word){  //funcao que salva em arquivo todos os comentarios associados a uma dada palavra
    TrieNode*node = search_trie(trie,word);
    if(node!=NULL){
        int index = mapASCII(word[strlen(word) - 1]);
        save_list(node, index);
    }
    else
        printf("Palavra nao encontrada\n");
}

void holdout_method(TrieNode*trie,TrieNode*stopWords,char*fileName,float*sumErros){  //funcao que executa os 3 tipos de predicao, calculando a media dos erros das mesmas
        FILE*arq;
        int j;
        float result,score,i[3] = {0,0,0};
        char comment[COMMENTS_SIZE], comment1[COMMENTS_SIZE], comment2[COMMENTS_SIZE];
    arq = fopen(fileName, "r");
    if (arq == NULL)
        printf("Erro ao abrir o arquivo de teste");
    else {
        while (!feof(arq)){
            score = (float)ctoi(getc(arq));
            score++;
            if(fgets(comment,COMMENTS_SIZE,arq)!= NULL) {
                printf("\ncomentario ");
                fputs(comment,stdout);
                printf("\n");
                strcpy(comment1,comment);
                strcpy(comment2,comment);

                result = score_prediction(stopWords,trie,comment);
                if(result != -1) {
                    printf("\ncomentario ");
                    printf("\ngabarito: %.2f result: %.2f, erro: %.2f\n\n", score, result, result - score);
                    print_result(result);
                    sumErros[0] += fabs(result - score);
                    i[0]++;
                }
                else
                    ("Nao ha informacoes sobre as palavras do comentario");

                result = naive_prediction_withoutStopWords(stopWords,trie,comment1);
                if(result != -1) {
                    sumErros[1] += fabs(result - score);
                    i[1]++;
                }
                else
                    ("Nao ha informacoes sobre as palavras do comentario");

                result = naive_prediction(trie,comment2);
                if(result != -1) {
                    sumErros[2] += fabs(result - score);
                    i[2]++;
                }
                else
                    ("Nao ha informacoes sobre as palavras do comentario");

                }
            }
        }
        fclose(arq);
    for(j=0;j<3;j++)
        sumErros[j]/=i[j];

}

float naive_prediction(TrieNode*trie,char*newComment){ //funcao de predicao mais basica, usando apenas media aritimetica das notas das palavras
    int i = 0;
    char *key;
    TrieNode *node;
    float sumOfAverage=0;
    key = strtok(newComment,"\t\n\r$%@#*&:^;=+{[()]} /,-.'`1234567890!?\\");    //dividindo as palavras da frase e limpando caracteres
    while (key != NULL) {
        node = search_trie(trie, strlwr(key)); //retorna o nodo em que se encontra a palavra na estrutura
        int index = mapASCII(key[strlen(key) - 1]); //calcula qual indice do alfabeto do nodo está a palavra.
        if(node != NULL && node->listOfScoresComments[index] != NULL) {
            sumOfAverage += node->averageScore[index];
            i++;
        }
        key = strtok(NULL,"\t\n\r$%@#*&:^;=+{[()]} /,-.'`1234567890!?\\");
    }
    if(i==0)
        return -1;
    else
        return (sumOfAverage/i);
}

float naive_prediction_withoutStopWords(TrieNode*stopWords,TrieNode*trie,char*newComment){  // funcao de predicao basica porém garimpando as stopwords
    int i = 0;
    char *key;
    TrieNode *node;
    float sumOfAverage=0;
    key = strtok(newComment,"\t\n\r$%@#*&:^;=+{[()]} /,-.'`1234567890!?\\");    //dividindo as palavras da frase e limpando caracteres
    while (key != NULL) {
        node = search_trie(trie, strlwr(key)); //retorna o nodo em que se encontra a palavra na estrutura
        int index = mapASCII(key[strlen(key) - 1]); //calcula qual indice do alfabeto do nodo está a palavra.
        if(node != NULL && node->listOfScoresComments[index] != NULL && search_trie(stopWords,strlwr(key)) == NULL) {
            sumOfAverage += node->averageScore[index];
            i++;
        }
        key = strtok(NULL,"\t\n\r$%@#*&:^;=+{[()]} /,-.'`1234567890!?\\");
    }
    if(i==0)
        return -1;
    else
        return (sumOfAverage/i);
}

float score_prediction(TrieNode*stopWords,TrieNode*trie, char*newComment) {  //funcao mais robusta que faz o calculo levando em conta a dispercao de cada nota da palavra
    char *key;
    TrieNode *node;
    float sumOfFixedScores=0;
    float  sumOfCoeff=0;
    int i=0;
    key = strtok(newComment,"\t\n\r$%@#*&:^;=+{[()]} /,-.'`1234567890!?\\");    //dividindo as palavras da frase e limpando caracteres
    while (key != NULL) {
        node = search_trie(trie, strlwr(key)); //retorna o nodo em que se encontra a palavra na estrutura
        int index = mapASCII(key[strlen(key) - 1]); //calcula qual indice do alfabeto do nodo está a palavra.
        if(node != NULL && node->listOfScoresComments[index] != NULL && search_trie(stopWords,strlwr(key)) == NULL) {
            float sT = standard_deviation(node->listOfScoresComments[index]);
            float cV = variant_coefficient(sT, node->averageScore[index]);

            sumOfFixedScores+= node->averageScore[index] * (1 - cV);
            sumOfCoeff+=(1-cV);
            i++;
        }
        key = strtok(NULL,"\t\n\r$%@#*&:^;=+{[()]} /,-.'`1234567890!?\\");
    }
    if(i==0 || sumOfCoeff ==0) //nenhuma palavra do comentário tem peso ou consta no dataSet
        return -1;
    else
        return sumOfFixedScores/sumOfCoeff;
}

void search_rads(TrieNode*trie,char*searchKey) { //funcao que faz a busca em arvore de todas as palavras de um radical.
    clean_format(searchKey); //procura o nodo do radical e usa a funcao de printar toda arvore com o nodo de radical como raiz.
    TrieNode *aux = trie;
    int lengthKey = strlen(searchKey);
    int i=0, index;
    while(i<lengthKey){
        index = mapASCII(searchKey[i]);
        aux = aux->children[index];
        i++;
    }
    if(aux!=NULL)
        print_trie(aux,0);
    else
        printf("Nao ha palavras associadas a este radical\n");
}

void ranking(int numWords,int k){
    FILE*arq2;
    char buffer[100];
    int i=0;
    int buffer1;
    float buffer2;
    arrayOfKeys vector[numWords];
    arq2 = fopen("list_of_words.txt","r");
    if (arq2 == NULL){
        printf("Erro ao abrir o arquivo de palavras contidas na estrutura");
    } else {
        i=0;
        while (!feof(arq2)) {
            fscanf(arq2,"%d", &vector[i].satellite);
            getc(arq2);
            fscanf(arq2,"%f",&vector[i].key);
            getc(arq2);
            if (fgets(buffer, COMMENTS_SIZE, arq2) != NULL) {
                buffer[strlen(buffer) - 1] = '\0';
                strcpy(vector[i].word, buffer);
            }
            i++;
        }
        fclose(arq2);
        heapSortDec(vector,numWords);
        printf("\n%d palavras mais positivas:\n\n",k);
        for(i=0;i<k;i++){
            fputs(vector[i].word,stdout);
            printf(" %.2f\n",vector[i].key);
        }
        printf("\n%d palavras mais negativas:\n\n",k);
        for(i=numWords-1;i>=numWords-k;i--){
            fputs(vector[i].word,stdout);
            printf(" %.2f\n",vector[i].key);
        }
    }

    arq2 = fopen("list_of_words.txt","r");
    if (arq2 == NULL){
        printf("Erro ao abrir o arquivo de palavras contidas na estrutura");
    } else {
        i=0;
        while (!feof(arq2)) {
            fscanf(arq2,"%d",&buffer1);
            vector[i].key = (float)buffer1;
            getc(arq2);
            fscanf(arq2,"%f",&buffer2);
            vector[i].satellite = (int)buffer2;
            getc(arq2);
            if (fgets(buffer, COMMENTS_SIZE, arq2) != NULL) {
                buffer[strlen(buffer) - 1] = '\0';
                strcpy(vector[i].word, buffer);
            }
            i++;
        }
        fclose(arq2);
        heapSortDec(vector,numWords);
        printf("\n%d palavras mais frequentes:\n\n",k);
        for(i=0;i<k;i++){
            fputs(vector[i].word,stdout);
            printf(" %.0f\n",vector[i].key);
        }
    }
}