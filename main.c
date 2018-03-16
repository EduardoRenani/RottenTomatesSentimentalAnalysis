#include <stdio.h>
#include <mem.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "trie.h"
#include "heap.h"

const int KEY_SIZE = 100;
const int COMMENT_SIZE = 10000;
int main() {

    FILE *arq,*arq2;
    int menuVar,menuVar2,k,i,numWords;
    float result[3]={0,0,0};
    char score;
    char buffer[COMMENT_SIZE];
    char *key;
    char word[KEY_SIZE];
    char newComment[COMMENT_SIZE];
    char comment[COMMENT_SIZE];
    char fileName[100];
    TrieNode *stopTrie = NULL;
    TrieNode *dataSetTrie = NULL;

    arq = fopen("stop_words.txt", "r"); //cria arvore de stopWords
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo de Stop Words");
        return 1;
    } else {
        while (!feof(arq))
            if (fscanf(arq,"%s",&buffer)>0) {  //le stopword por stopword
                clean_format(buffer);
                stopTrie = insert_trie(stopTrie, strlwr(buffer),0,newComment);
            }
        fclose(arq);
    }

    arq = fopen("movieReviews_treinamento.txt", "r"); //cria arvore com comentarios de treinamento
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo de comentarios");
        return 1;
    } else {
        while (!feof(arq)){
            score = getc(arq);
            if(fgets(buffer,COMMENT_SIZE,arq)!= NULL) {
                strcpy(comment,buffer);
                key = strtok(buffer,"\t\n\r$%@#*&:^;=+{[()]} /,-.'`1234567890!?\\");    //dividindo as palavras da frase e limpando caracteres
                while (key != NULL) {
                        if(strlen(buffer)>1) {
                            dataSetTrie = insert_trie(dataSetTrie, strlwr(key), ctoi(score), comment);
                            key = strtok(NULL, "\t\n\r$%@#*&:^;=+{[()]} /,-.'`1234567890!?\\");
                        }
                }
            }
        }
        fclose(arq);
    }

    do {
        menu();
        scanf("%d", &menuVar);

        switch (menuVar) {
            case 1:
                printf("Escreva um comentario para ser classificado\n");
                fflush(stdin);
                fgets(newComment, KEY_SIZE, stdin);
                float result1 = score_prediction(stopTrie, dataSetTrie, newComment);
                printf("A classificaçao do comentario eh: %.4f", result1);
                break;

            case 2:
                arq = fopen("list_of_words.txt", "w");
                fclose(arq);
                numWords = print_trie(dataSetTrie, 1);
                printf("insira um valor de K para criar os tres rankings\n");
                scanf("%d", &k);
                ranking(numWords, k);
                break;
            case 3:
                printf("Digite o nome do arquivo a ser classificado. Este programa ira associar uma nota a cada comentario e calcular o erro medio entre as classificacoes e as notas reais.\n");
                fflush(stdin);
                fgets(fileName, KEY_SIZE, stdin);
                clean_format(fileName);
                holdout_method(dataSetTrie, stopTrie, fileName, result);
                printf("\nComparacao entre metodos:\nUsando coeficiente de variacao %.4f\nEliminando stop words %.4f\nNaive %.4f\n",
                       result[0], result[1], result[2]);
                break;

            case 4:
                printf("Digite uma palavra e sera criado um arquivo 'file_assocComments.txt' contendo dos os comentarios associados a palavra\n");
                fflush(stdin);
                fgets(word, KEY_SIZE, stdin);
                word[strlen(word) - 1] = '\0';
                fileAssocComments(dataSetTrie, word);
                printf("Deseja visualizar os dados na tela?\n1-Sim\n2-Nao\n");
                scanf("%d", &menuVar2);
                if (menuVar2 == 1) {
                    arq = fopen("file_assocComments.txt", "r");
                    while (!feof(arq)) {
                        if (fgets(buffer, COMMENT_SIZE, arq) != NULL)
                            fputs(buffer, stdout);
                        putc('\n', stdout);
                    }
                    fclose(arq);
                }
                break;

            case 5:
                printf("Digite um radical de palavra para ser retornado todas as palavras com este radical\n");
                fflush(stdin);
                fgets(word, KEY_SIZE, stdin);
                search_rads(dataSetTrie, word);
                break;

            default:
                return 0;
                break;
        }

    }while(menuVar!=6);

    return 0;
}



