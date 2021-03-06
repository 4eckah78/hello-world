
#include "stdafx.h"
#include <iostream>
#include <time.h>

#include <string>
#include <fstream>


struct Chip {
  char letter;
  int price;
  int ammount;
};


void Dictionary(const Chip* chips, unsigned const int& n, const char* fname) {
  std::ifstream ifs(fname);
  if (!ifs.is_open()) {
    std::cout << "No file" << std::endl;
    exit(-1);
  }


  int* chipAmmount = new int[n];

  //считаем количество звездочек (их не больше трёх по условию)
  int ammountOfStars = 0;
  for (int i = 0; i < n; ++i)
    if (chips[i].letter == '*')
      ammountOfStars++;

  bool relevant = false; // флажок найдено ли хотя бы одно слово

  std::string result = "";
  int maxPrice = 0;
  char mostNeededLetter = chips[7].letter;
  bool starFactor = false;
  if (mostNeededLetter == '*')
    starFactor = true;
    
  
 
    

  while (!ifs.eof()) {
    //каждая фишка может быть использована один раз
    std::string buffer = "";
    ifs >> buffer;
    if (buffer.length() > 8)
      continue;

    int currentPrice = 0;
    int mostNeededIndex = -1;

    //проверяем есть ли обязаельная буква, запоминаем (если она звёздочка то уменьшаем количество звёзд) и прибавлеём одно пападание
    if (!starFactor)
      for (int i = 0; i < buffer.length(); ++i)
        if (buffer[i] == mostNeededLetter) {
          mostNeededIndex = i;
          break;
        }

    if (mostNeededIndex == -1 && !starFactor)
      continue;

    for (int i = 0; i < n; ++i)
      chipAmmount[i] = 1;

    bool starInserted = false;

    int minPrice = 0;
    char minLetter = 0;
    int minLetterIndex = 0;

    std::string tmp = "";

    bool letterInserted = false;

    // если есть (иначе нисего делать не надо)
    if (mostNeededIndex != -1 || starFactor) {
      for (int i = 0; i < buffer.length(); ++i) {
        letterInserted = false;
        for (int j = 0; j < n; ++j)
          if (buffer[i] == chips[j].letter && chipAmmount[j] > 0 && !letterInserted) {
            if (starFactor) {
              minPrice = 20;
              minLetter = 0;
              if (chips[j].price < minPrice && chips[j].letter != '*') {
                  minPrice = chips[j].price;
                  minLetter = chips[j].letter;
                }
            }
            if (chips[j].letter == minLetter)
              minLetterIndex = i;
            tmp.push_back(chips[j].letter);
            currentPrice += chips[j].price;
            chipAmmount[j]--;
            letterInserted = true;
            break;
          }
        if (!letterInserted && ammountOfStars > 0) {
          tmp.push_back('*');
          ammountOfStars--;
          letterInserted = true;
          starInserted = true;
        }
        else
          if (!letterInserted) // если прям вообще нечего вставить
            break;

      }
      if (starFactor && !starInserted)
        tmp[minLetterIndex] = '*';

      if (tmp.length() == buffer.length() && tmp.length() > 1) {  // если слово вообще получилось
        relevant = true;
        std::cout << "tmp = " << tmp << " ---- " << "price = " << currentPrice << std::endl;
        if (currentPrice > maxPrice) {// выбираем наибольшую стоимость
          result = tmp;
          maxPrice = currentPrice;
        }

      }
    }
  }

  if (relevant)
    std::cout << "Наиболее ценноe слово: " << result << std::endl;
  else
    std::cout << "Нет совпадений(( " << std::endl;
  delete[] chipAmmount;
  ifs.close();
}


void makeNormDictionary(const char* fname1, const char* fname2) {
  std::ifstream ifs(fname1);
  std::ofstream ofs(fname2, std::ios_base::out);
  if (!ifs.is_open()) {
    exit(-1);
    std::cout << "No such file " << std::endl;
  }
  while (!ifs.eof()) {
    std::string buffer;
    char tmp = 0;
    tmp = ifs.get();
    while ((int)tmp != 32) {
      buffer += tmp;
      if ((int)tmp != 32)
        tmp = ifs.get();
    }
    //ifs >> buffer;
    ofs << buffer;
    getline(ifs, buffer);
    buffer = "";
    ofs << buffer;
    ofs << std::endl;
  }
  ifs.close();
  ofs.close();
}


int main() {
  srand(time(0));
  setlocale(LC_ALL, "rus");
  int Arr_W_Ammount[33] = { 10,3,5,3,5,9,2,2,8,4,6,4,5,8,10,6,6,6,5,3,1,2,1,2,1,1,1,2,2,1,1,3,3 };

  char Arr_W_All_Symbols[33] = { 'а','б','в','г','д','е','ж','з','и','й','к','л','м','н','о','п','р','с','т','у','ф','х','ц','ч','ш','щ','ъ','ы','ь','э','ю','я','*' };

  int Arr_W_Prices[33]{ 1,3,2,3,2,1,5,5,1,2,2,2,2,1,1,2,2,2,2,3,10,5,10,5,10,10,10,5,5,10,10,3,0 };

  Chip chips[33] = {};

  Chip eight_chips[15] = {};

  for (int i = 0; i < 33; ++i) {
    chips[i].letter = Arr_W_All_Symbols[i];
    chips[i].price = Arr_W_Prices[i];
  }

  /*
  for (int i = 0; i < 33; ++i)
    std::cout << " " << chips[i].letter << " " << chips[i].ammount << " " << chips[i].price << std::endl;
  */

  int i = 0;
  int a = 0;

  while (1) {
    a = rand() % 33;
    if (Arr_W_Ammount[a] > 0) {
      eight_chips[i] = chips[a];
      Arr_W_Ammount[a]--;
      i++;
    }
    if (i == 15)
      break;
  }

 
  /*eight_chips[7].letter = '*';
  eight_chips[0].letter = 'х';
  eight_chips[1].letter = 'о';
  eight_chips[2].letter = 'л';
  eight_chips[3].letter = 'м';
  eight_chips[4].letter = '*';
  eight_chips[5].letter = 'о';
  eight_chips[6].letter = '*';

  eight_chips[7].price = 2;
  eight_chips[0].price = 2;
  eight_chips[1].price = 1;
  eight_chips[2].price = 1;
  eight_chips[3].price = 2;
  eight_chips[4].price = 2;
  eight_chips[5].price = 1;
  eight_chips[6].price = 0;*/
  

  for (int i = 0; i < 15; ++i)
    std::cout << " " << eight_chips[i].letter << " " << eight_chips[i].price << std::endl;
  

  std::cout << "\n"  << std::endl;
  Dictionary(eight_chips, 15, "file.txt");
  
  //makeNormDictionary("sam.txt", "sam2.txt");

  return 0;
}