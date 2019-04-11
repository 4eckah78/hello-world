#pragma once

#include "Book.h"


class Magazine : public Book {
public:
  Magazine(const char* au, const char* ti, const char* boP, Date& date, const unsigned int& NoP, std::string MT) : Book(au, ti, boP,date, NoP) {
    m_MagazinTheme = MT;
  }
  std::string getMagazinTheme()const { return m_MagazinTheme; }
  std::string setMagazinTheme(std::string& MT) { return m_MagazinTheme; }
private:
  std::string m_MagazinTheme;
};