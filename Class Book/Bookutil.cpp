
#include "pch.h"
#include "Bookutil.h"


std::ostream& operator<<(std::ostream& ost, const Date& da) {
  ost << da.day << "." << da.month << "." << da.year;
  return ost;
}


std::ostream& operator<<(std::ostream& ost, const Book& bo) {
  ost << "Author: ";
  for (size_t i = 0; i < bo.getAuthor().length(); ++i)
    ost << bo.getAuthor()[i];
  ost << "\n";
  ost << "Title: ";
  for (size_t i = 0; i < bo.getTitle().length(); ++i)
    ost << bo.getTitle()[i];
  ost << "\n";
  ost << "BookPublishing: ";
  for (size_t i = 0; i < bo.getBookPublishing().length(); ++i)
    ost << bo.getBookPublishing()[i];
  ost << "\n";
  ost << "Date: " << bo.getDate();
  ost << "\n";
  ost << "NumberOfPages: " << bo.getNumberOfPages() << "\n";
 return ost;
}


