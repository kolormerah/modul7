//
// Created by Ariq Heritsa on 24/05/22.
//

#ifndef STD_MOD7_DS4501_1305213031_ARN_SLL_CIRCULAR_H
#define STD_MOD7_DS4501_1305213031_ARN_SLL_CIRCULAR_H

#include <iostream>

using namespace std;

#define nil NULL
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info
#define next(P) P->next

const int max_applications = 5;

struct infotype {
  string nama;
  int prioritas, sisa_durasi;
};

typedef struct elmList *address;

struct elmList {
  infotype info;
  address next;
};

struct list {
  address first;
};

void createList(list &L);

address createElement(infotype dataBaru);

void insertFirst(list &L, address P);

void insertLast(list &L, address P);

void insertAfter(address Prec, address P);

void insertDescending(list &L, infotype dataBaru);

void deleteFirst(list &L, address &P);

void deleteLast(list &L, address &P);

void deleteAfter(address Prec, address &P);

void deleteElm(list &L, address &P);

void printList(list L);

int panjangList(list L);

void insertAplikasi(list &L, infotype dataBaru);

int eksekusi(address P, int durasi);

void eksekusiMulti(list &L, address &current, int N, int duration);

void sortList(list &L);

#endif //STD_MOD7_DS4501_1305213031_ARN_SLL_CIRCULAR_H
