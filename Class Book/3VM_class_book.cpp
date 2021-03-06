#include "pch.h"

#include "Magazine.h"
#include "Bookutil.h"


int main() {
/*  Date data1 = { 1,12,1998 };
  Date data2(29,8,1806);
  Book book1("Lukyanenko T. H.", "Lol stars and so on", "Drofa", data1, 500);
  Book book2("df", "sf", "Sfs", 5, 6, 2007, 500);
  Book smallLibrary[3];
  smallLibrary[0] = book1;
  smallLibrary[1] = book2;
  smallLibrary[2] = { "Hey", "Lol yo", "Kek", data2, 7 };

  bool BookExists = false;
  for (int i = 0; i < 3; ++i)
    if (smallLibrary[i].searchBookByTimeInterval(15, 6, 1996, 24, 5, 2241)) {
      std::cout << "Matched book is: " << std::endl;
      std::cout << smallLibrary[i] << std::endl;
      BookExists = true;
    }
  if (!BookExists)
    std::cout << "No book with such a title" << std::endl;
   
  Magazine mag("Hey", "Lol yo", "Kek", data2, 7, "Yup");
  std::cout << mag.getMagazinTheme() << std::endl;
  */


  const int n = 15;
  Book Library[n] = {};
  std::cout << "Array demonstration " << "\n\n";
  for (int k = 0; k < n; ++k) {
    
    int number = 0;
    int d, m, y = 0;
    number = k;
    d = (k + 1) % 31 + 1;
    m = (k + 1) % 12 + 1;
    y = (k + 1) * 100;
    Date tmp(d, m, y);
    /*
    std::cout << " Input date" << std::endl;
    int d, m, y = 0;
    std::cin >> d >> m >> y;
    Date tmp(d, m, y);
    std::cout << "input Number of Pages " << std::endl;

    std::cin >> number;
    */
    Library[k].setBook("Author1 Author2 Author3" + k, "Title Title2 Title3 Title4" + k, "Publisher1 Publisher2 Publisher3" + k, tmp, number);
  }
  for (int k = 0; k < n; ++k) {
    std::cout << Library[k] << std::endl;
  }
  // Поиск по интервалу
  /*
  std::cout << "Interval Searching demonstration " << "\n\n";
  for (int k = 0; k < n; ++k) {
    if (Library[k].searchBookByTimeInterval(1, 2, 300, 1, 2, 500)) {
      std::cout << Library[k] << std::endl;
    }
  }
  */
  // поиск по Дате
  /*
  std::cout << "Date Searching demonstration " << "\n\n";
  for (int k = 0; k < n; ++k) {
    if (Library[k].searchBookByDate(700)) {
      std::cout << Library[k] << std::endl;
    }
  }
  */
  // поиск по автору
  /*
  cout << "Author Searching demonstration " << "\n\n";
  for (int k = 0; k < n; ++k) {
    if (Library[k].serachBookByAuthor("Author1 Author2 Author3")) {
      std::cout << Library[k] << std::endl;
    }
  }
  */
  //поиск по названию
  /*
  std::cout << "Title Searching demonstration " << "\n\n";
  for (int k = 0; k < n; ++k) {
    if (Library[k].serachBookByTitle("Title2")) {
      std::cout << Library[k] << std::endl;
    }
  }
  */
  //демонстрация вычитания двух дат(в ней используется их сравнение)
  Date result;
  result = Library[5].getDate() - Library[3].getDate();
  std::cout << result << std::endl;
  //result = Library[4].getDate() - Library[5].getDate();// когда вычитать нельзя
  return 0;
}

