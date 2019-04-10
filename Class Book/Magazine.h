#pragma once

#include "Book.h"


class Magazine : public Book {
public:
  Magazine(const char* au, const char* ti, const char* boP, Date& date, const unsigned int& NoP, const char* MT) : Book(au, ti, boP,date, NoP) {
    MagazinTheme = MT;
  }
private:
  std::string MagazinTheme;
};