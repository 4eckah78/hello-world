
#include "pch.h"
#include <iostream>
#include <time.h>
#include "Dictionary.h"



int main() {
  srand(time(NULL));
  setlocale(LC_ALL, "rus");
  int Arr_W_Ammount[33] = { 10,3,5,3,5,9,2,2,8,4,6,4,5,8,10,6,6,6,5,3,1,2,1,2,1,1,1,2,2,1,1,3,3 };
  char Arr_W_All_Symbols[33] = { 'а','б','в','г','д','е','ж','з','и','й','к','л','м','н','о','п','р','с','т','у','ф','х','ц','ч','ш','щ','ъ','ы','ь','э','ю','я','*' };
  char Arr_W_Symbols[8] = {};
  /*
  for (int i = 0; i < 8; ++i) {
    int a = 0;
    a = rand() % 131;
    int counter = 0;
    while (a >= 0) {
      a -= Arr_W_Ammount[counter];
      counter++;
    }
    Arr_W_Symbols[i] = Arr_W_All_Symbols[--counter];
  }
  */
  Arr_W_Symbols[7] = 'а';
  Arr_W_Symbols[0] = 'б';
  Arr_W_Symbols[1] = 'л';
  Arr_W_Symbols[2] = 'я';
  Arr_W_Symbols[3] = 'ц';
  Arr_W_Symbols[4] = 'и';
  Arr_W_Symbols[5] = 'е';
  Arr_W_Symbols[6] = 'к';

  for (int i = 0; i < 8; ++i)
    std::cout << Arr_W_Symbols[i] << " ";
  Dictionary d(Arr_W_Symbols, 8, Arr_W_Ammount, 33);
  d.findWord("C:\\Users\\Home\\source\\repos\\Dictionary.txt");
  d.printres();
  return 0;
  return 0;
}