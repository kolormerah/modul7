//
// Created by Ariq Heritsa on 24/05/22.
//

#include "sll_circular.h"

void createList(list &L) {
  first(L) = nil;
}


address createElement(infotype dataBaru) {
  address P = new elmList;

  info(P) = dataBaru;
  next(P) = nil;

  return P;
}

void insertFirst(list &L, address P) {
  address Q;

  if (first(L) == nil) {
    first(L) = P;
    next(P) = first(L);
  } else if (next(first(L)) == first(L)) {
    next(P) = first(L);
    first(L) = P;

    next(next(first(L))) = first(L);
  } else {
    next(P) = first(L);
    first(L) = P;

    Q = next(first(L));

    while (next(Q) != next(P)) {
      Q = next(Q);
    }

    next(Q) = first(L);
  }
}

void insertLast(list &L, address P) {
  address Q;

  if (first(L) == nil) {
    first(L) = P;
    next(P) = first(L);
  } else {
    Q = first(L);

    while (next(Q) != first(L)) {
      Q = next(Q);
    }

    next(Q) = P;
    next(P) = first(L);
  }
}

void insertAfter(address Prec, address P) {
  next(P) = next(Prec);
  next(Prec) = P;
}

void insertDescending(list &L, infotype dataBaru) {
  address P = createElement(dataBaru);

  if (first(L) == nil) {
    insertFirst(L, P);
  } else if (info(first(L)).prioritas < info(P).prioritas) {
    insertFirst(L, P);
  } else {
    address Q = first(L);

    while (next(Q) != first(L) && info(next(Q)).prioritas >= info(P).prioritas) {
      Q = next(Q);
    }

    if (next(Q) == first(L)) {
      insertLast(L, P);
    } else {
      insertAfter(Q, P);
    }
  }
}

void deleteFirst(list &L, address &P) {
  address Q;

  P = first(L);

  if (next(first(L)) == first(L)) {
    first(L) = nil;
    next(P) = nil;
  } else {
    first(L) = next(first(L));
    next(P) = nil;
    Q = first(L);

    while (next(Q) != P) {
      Q = next(Q);
    }

    next(Q) = first(L);
  }
}

void deleteLast(list &L, address &P) {
  address Q = first(L);

  while (next(next(Q)) != first(L)) {
    Q = next(Q);
  }

  P = next(Q);
  next(P) = nil;
  next(Q) = first(L);
}

void deleteAfter(address Prec, address &P) {
  P = next(Prec);
  next(Prec) = next(P);
  next(P) = nil;
}

void deleteElm(list &L, address &P) {
  address Q;

  if (first(L) == nil) {
    cout << "List kosong" << endl;
  } else if (first(L) == P) {
    deleteFirst(L, P);
  } else if (next(P) == first(L)) {
    deleteLast(L, P);
  } else {
    Q = first(L);

    while (next(Q) != first(L) && next(Q) != P) {
      Q = next(Q);
    }

    deleteAfter(Q, P);
  }
}

void printList(list L) {
  if (first(L) == nil) {
    cout << "List kosong!" << endl;
  } else {
    address P = first(L);
    if (P != nil) {
      while (next(P) != first(L)) {
        cout << "Nama      : " << info(P).nama << endl;
        cout << "Prioritas : " << info(P).prioritas << endl;
        cout << "Sisa waktu: " << info(P).sisa_durasi << endl;
        P = next(P);
      }

      cout << "Nama      : " << info(P).nama << endl;
      cout << "Prioritas : " << info(P).prioritas << endl;
      cout << "Sisa waktu: " << info(P).sisa_durasi << endl;
    }
  }
}

int panjangList(list L) {
  if (first(L) == nil) {
    return 0;
  }

  address P = first(L);
  int count = 1;

  while (next(P) != first(L)) {
    P = next(P);
    count++;
  }

  return count;
}

void insertAplikasi(list &L, infotype dataBaru) {
  address P, Q;

  P = createElement(dataBaru);

  if (first(L) == nil) {
    insertFirst(L, P);
  } else if (panjangList(L) < max_applications) {
    insertDescending(L, dataBaru);
  } else {
    deleteLast(L, Q);
    insertDescending(L, info(P));
  }
}

int eksekusi(address P, int durasi) {
  int result = 0;

  if (durasi > 0) {
    result = info(P).sisa_durasi - durasi;
  }

  return result;
}

void eksekusiMulti(list &L, address &current, int N, int duration) {
  address P;
  int i = 0;
  int nah = eksekusi(current, duration);

  while (i < N) {
    info(current).sisa_durasi = nah;

    if (info(current).sisa_durasi <= 0) {
      P = current;
      current = next(current);
      deleteElm(L, P);
    } else {
      current = next(current);
    }

    nah = eksekusi(current, duration);
    i++;
  }

  sortList(L);
}

void sortList(list &L) {
  address P, Q, Max;
  infotype temp;

  P = first(L);

  while (next(P) != first(L)) {
    Max = P;
    Q = next(P);

    while (next(Q) != first(L)) {
      if (info(Q).prioritas > info(Max).prioritas) {
        temp = info(Q);
      }
      Q = next(Q);
    }

    temp = info(P);
    info(P) = info(Q);
    info(Q) = temp;

    P = next(P);
  }
}