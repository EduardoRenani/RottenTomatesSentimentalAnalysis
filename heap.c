//
// Created by eduar on 18/12/2017.
//

#include "heap.h"
#include "heap.h"
#include <stdio.h>  /* printf */
#include <math.h>   /* pow, log2 */
#include <mem.h>

/************************/
/******* MIN HEAP *******/
/************************/

void MINheapify(arrayOfKeys*  C, int size, int index)
{
    /* TODO: implementar algoritmo de heapificacao recursivo para heap minimo  */
    char word[100];
    int  satellite;
    int left = leftChild(index);
    int right = rightChild(index);
    int smallest = index;

    if(left<size)
        if(C[left].key < C[smallest].key)
            smallest = left;
    if(right<size)
        if(C[right].key < C[smallest].key)
            smallest = right;

    if(smallest!=index){
        /* troca C[index] com filho menor */
        float temp = C[index].key;
        C[index].key = C[smallest].key;
        C[smallest].key = temp;

        strcpy(word,C[index].word);
        strcpy(C[index].word,C[smallest].word);
        strcpy(C[smallest].word,word);

        satellite = C[index].satellite;
        C[index].satellite = C[smallest].satellite;
        C[smallest].satellite = satellite;

        MINheapify(C,size,smallest);
    }


}

void MINheapifyIter(arrayOfKeys*  C, int size, int index)
{
    /* TODO: implementar algoritmo de heapificacao iterativo (sem recursao)  */
    int smallest=index;
    while (index <= size) {
        char word[100];
        int  satellite;
        int left = leftChild(index);
        int right = rightChild(index);
        if (left<size && C[left].key<C[index].key)
            smallest = left;
        else
            smallest = index;
        if (right<size && C[right].key<C[smallest].key)
            smallest = right;
        if (smallest != index) {
            float temp = C[index].key;
            C[index].key = C[smallest].key;
            C[smallest].key = temp;

            strcpy(word,C[index].word);
            strcpy(C[index].word,C[smallest].word);
            strcpy(C[smallest].word,word);

            satellite = C[index].satellite;
            C[index].satellite = C[smallest].satellite;
            C[smallest].satellite = satellite;

            index = smallest;
        }
        else
            break;
    }

}

void buildMINHeap(arrayOfKeys*  C, int size)
{
    /* TODO: - implementar algoritmo que transforma array C em heap minimo
             - usar função MINheapify
             - depois variar implementacao para usar versão iterativa de heapify (MINheapifyIter)
    */
    int i;
    int heapSize = size;
    for(i=(heapSize/2);i>=0;i--)
        //MINheapifyIter(C,heapSize,i);
        MINheapify(C,heapSize,i);
}

int heapSortDec(arrayOfKeys*  C, int size)
{
    /* TODO: - implementar algoritmo heapSort que ordena array C em ordem decrescente
             - usar função buildMINHeap
    */
    int i, heapSize = size;
    buildMINHeap(C,size);
    //printHeap(C, size);
    //printf("MINheappp? %s\n",(checkMINHeap(C,size)?"sim":"nao"));
    for(i=heapSize-1;i>=1;i--){
        char word[100];
        int  satellite;
        float aux = C[0].key;
        C[0].key = C[i].key;
        C[i].key = aux;

        strcpy(word,C[0].word);
        strcpy(C[0].word,C[i].word);
        strcpy(C[i].word,word);

        satellite = C[0].satellite;
        C[0].satellite = C[i].satellite;
        C[i].satellite = satellite;

        heapSize--;
        MINheapify(C,heapSize,0);
        //MINheapifyIter(C,heapSize,0);
    }



}

/***************************************************/
/************ Metodos auxiliares *******************/
/***************************************************/

void MAXheapify(arrayOfKeys*  C, int size, int index)
{
    int left = leftChild(index);
    int right = rightChild(index);
    int largest = index;

    if(left<size)
        if(C[left].key > C[largest].key)
            largest = left;
    if(right<size)
        if(C[right].key > C[largest].key)
            largest = right;

    if(largest!=index){
        /* troca C[index] com filho maior */
        char word[100];
        int  satellite;
        float temp = C[index].key;
        C[index].key = C[largest].key;
        C[largest].key = temp;

        strcpy(word,C[index].word);
        strcpy(C[index].word,C[largest].word);
        strcpy(C[largest].word,word);

        satellite = C[index].satellite;
        C[index].satellite = C[largest].satellite;
        C[largest].satellite = satellite;

        MAXheapify(C,size,largest);
    }
}

int checkMINHeap(arrayOfKeys*  C, int size)
{
    int i;
    for(i=0;i<size;i++){
        int left = leftChild(i);
        int right = rightChild(i);

        if(left<size){
            if(C[left].key<C[i].key)
                return 0;
            else if(right<size){
                if(C[right].key<C[i].key)
                    return 0;
            }
        }
    }
    return 1;
}

int checkMAXHeap(arrayOfKeys*  C, int size)
{
    int i;
    for(i=0;i<size;i++){
        int left = leftChild(i);
        int right = rightChild(i);

        if(left<size){
            if(C[left].key>C[i].key)
                return 0;
            else if(right<size){
                if(C[right].key>C[i].key)
                    return 0;
            }
        }
    }
    return 1;
}

int father(int index)
{
    if(index==0)
        return -1;
    else
        return index/2;
}

int leftChild(int index)
{
    return index*2;
}

int rightChild(int index)
{
    return index*2 + 1;
}

void printHeap(arrayOfKeys*  C, int size)
{
    int levels=log2(size);

    int i=0, j=1, n=1, k;
    int spaces = pow(2,levels);

    while(i<size){
        /* print valor */
        printf("%f ",C[i].key);
        /* print espacos */
        if(spaces>1){
            for(k=0; k<spaces-2; k++)
                printf("---");
            printf("--)");
        }

        /* print \n */
        if(j==n){
            printf("\n");
            n *= 2;
            spaces /= 2;
            j=0;
        }
        i++;
        j++;

    }
    printf("\n");
}

int swapFy(float*a,float*b){
    float aux = *a;
    *a = *b;
    *b = aux;
}