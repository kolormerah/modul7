#include <iostream>
#include "sll_circular.h"

using namespace std;

int main() {
  list L;
  createList(L);

  insertAplikasi(L, {"word", 5, 10});
  insertAplikasi(L, {"excel", 4, 20});
  insertAplikasi(L, {"chrome", 8, 5});
  insertAplikasi(L, {"wa", 7, 10});
  insertAplikasi(L, {"dota", 10, 30});

  printList(L);
  insertAplikasi(L, {"power point", 6, 15});

  cout << endl;
  printList(L);

  cout << endl;
  cout << "Eksekusi: " << endl;
  eksekusiMulti(L, first(L), 3, 10);
  printList(L);

  cout << endl;
  eksekusiMulti(L,first(L), 3, 10);
  printList(L);

  return 0;
}
