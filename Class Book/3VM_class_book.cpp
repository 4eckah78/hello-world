#include "pch.h"
#include <iostream>

#include "Book.h"
#include "Bookutil.h"

#include <string>



int main()
{
  Date data1 = { 1,12,1998 };
  Date data2 = { 29,8,1806 };
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
   

  return 0;
}

