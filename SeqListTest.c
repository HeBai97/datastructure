//
// Created by hebai on 4/1/2022.
//
#include "stdio.h"
#include "stdlib.h"

#define MAXSIZE 100
typedef int ElemType;
typedef int Status;

//typedef struct {
//    ElemType elem[MAXSIZE];
//    int length;
//}SeqList;

typedef struct {
    ElemType *elem;
    int length;
} SeqList;

Status Init_SeqList(SeqList L) {
    L.elem = (ElemType *) malloc(MAXSIZE * sizeof(ElemType));
    L.length = 0;
    return 1;
}

unsigned int ListLength(SeqList L) {
    return L.length;
}

ElemType GetNode(SeqList L, int index) {
    return L.elem[index];
}

int LocateNode(SeqList L, ElemType x) {
    for (int i = 0; i < L.length; ++i) {
        if (L.elem[i] == x)
            return i;
    }
    return -1;
}

void InsertList(SeqList L, int index, ElemType x) {
    for (int i = L.length - 1; i < index; --i)
        L.elem[i + 1] = L.elem[i];
    L.elem[index] = x;
}

/**
 *  取并集
 * @param A
 * @param B
 */
void UnionList(SeqList A, SeqList B) {
    unsigned int n = ListLength(A);
    for (int i = 0; i < ListLength(B); ++i) {
        ElemType x = GetNode(B, i);
        if (LocateNode(A, x) == -1)
            InsertList(A, ++n, x);
    }
}


