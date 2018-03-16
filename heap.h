//
// Created by eduar on 18/12/2017.
//

#include "functions.h"

#ifndef TRABALHOFINALCPD_HEAP_H
#define TRABALHOFINALCPD_HEAP_H
void MINheapify(arrayOfKeys* C, int size, int index);
void MINheapifyIter(arrayOfKeys*  C, int size, int index);
void buildMINHeap(arrayOfKeys*  C, int size);
int heapSortDec(arrayOfKeys*  C, int size);
int swapFy(float*a,float*b);

/************ Metodos auxiliares *******************/

void MAXheapify(arrayOfKeys*  C, int size, int index);

int checkMINHeap(arrayOfKeys*  C, int size);
int checkMAXHeap(arrayOfKeys*  C, int size);

int father(int index);
int leftChild(int index);
int rightChild(int index);
void printHeap(arrayOfKeys*  C, int size);

#endif //TRABALHOFINALCPD_HEAP_H
