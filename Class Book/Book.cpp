#include "pch.h"
#include "Book.h"


bool operator<(const Date& da1, const Date& da2) {
  if (da1.year < da2.year)
    return true;
  else if (da1.year == da2.year)
    if (da1.month < da2.month)
      return true;
    else if (da1.month == da2.month)
      if (da1.day < da2.day)
        return true;
  return false;
}


bool operator>(const Date& da1, const Date& da2) {
  if (da1.year > da2.year)
    return true;
  else if (da1.year == da2.year)
    if (da1.month > da2.month)
      return true;
    else if (da1.month == da2.month)
      if (da1.day > da2.day)
        return true;
  return false;
}


bool operator<=(const Date& da1, const Date& da2) {
  if (da1.year <= da2.year)
    return true;
  else if (da1.year == da2.year)
    if (da1.month <= da2.month)
      return true;
    else if (da1.month == da2.month)
      if (da1.day <= da2.day)
        return true;
  return false;
}


bool operator>=(const Date& da1, const Date& da2) {
  if (da1.year >= da2.year)
    return true;
  else if (da1.year == da2.year)
    if (da1.month >= da2.month)
      return true;
    else if (da1.month == da2.month)
      if (da1.day >= da2.day)
        return true;
  return false;
}


bool operator==(const Date& da1, const Date& da2) {
  if (da1.day == da2.day && da1.month == da2.month && da1.year == da2.year)
    return true;
  return false;
}


Date operator-(const Date& da1, const Date& da2) {
  if (da1 >= da2) {
    int DaysInMonths[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    Date result;
    result.year = da1.year - da2.year;
    if (da1.month <= da2.month) {
      result.year--;
      result.month = da1.month + 12 - da2.month;
    }
    else
      result.month = da1.month - da2.month;
    if (da1.day <= da2.day) {
      if (result.month == 1) {
        result.year--;
        result.month = 12;
        result.day = da1.day + 31 - da2.day;
      }
      else {
        result.day = da1.day + DaysInMonths[result.month - 1] - da2.day;
        result.month--;
      }
    }
    else
      result.day = da1.day - da2.day;
    return result;
  }
  std::cout << "negative date!!" << std::endl;
  return 0;
}


void Book::setDayMonthYear(const unsigned int& d, const unsigned int& m, const unsigned int& y) {
  if (d <= 31) m_date.day = d;
  else std::cout << "Bad day";
  if (m <= 12) m_date.month = m;
  else std::cout << "Bad month"; 
  m_date.year = y;
}


void Book::setMonthYear(const unsigned int& m, const unsigned int& y) {
  if (m <= 12) m_date.month = m;
  else std::cout << "Bad month";
  m_date.year = y;
}


void Book::setYear(const unsigned int& y) {
  m_date.year = y;
}


void Book::getDayMonthYear()const {
  std::cout << "Day-month-year:\n" << m_date.day << "." << m_date.month << "." << m_date.year;
}


void Book::getMonthYear()const {
  std::cout << "Month-year:\n" << m_date.month << "." << m_date.year;
}


void Book::getYear()const {
  std::cout << "Year:\n" << m_date.year;
}


Book::Book() {
  m_author[0] = 0;
  m_title[0] = 0;
  m_bookPublishing[0] = 0;
  m_date.day = 0;
  m_date.month = 0;
  m_date.year = 0;
  m_numberOfPages = 0;
}


Book::Book(const std::string au, const std::string ti, const std::string boP, Date& date, const unsigned int& NoP) {
  m_author = au;
  m_title = ti;
  m_bookPublishing = boP;
  m_date.day = date.day;
  m_date.month = date.month;
  m_date.year = date.year;
  m_numberOfPages = NoP;
}


Book::Book(const std::string au, const std::string ti, const std::string boP, const unsigned int& d, const unsigned int& m, const unsigned int& y, const unsigned int& NoP) {
  m_author = au;
  m_title = ti;
  m_bookPublishing = boP;
  m_date.day = d;
  m_date.month = m;
  m_date.year = y;
  m_numberOfPages = NoP;
}


Book::~Book() {}


bool Book::serachBookByAuthor(const std::string key)const {
  size_t count = 0;
  while (1) {
    if (int(key[count] == 0))
      break;
    ++count;
  }

  if (count != m_author.length())
    return false;

  bool b = true;
  for (size_t i = 0; i < m_author.length(); ++i)
    if (key[i] != m_author[i])
      b = false;
  if (b)
    return true;
  else
    return false;
}


bool Book::serachBookByTitle(const std::string key)const {
  size_t count = 0;
  while (1) {
    if (int(key[count] == 0))
      break;
    ++count;
  }

  if (count > m_title.length())
    return false;

  bool similar = true;
  char* window = new char[count];
  for (size_t i = 0; i < count; ++i)
    window[i] = m_title[i];

  for (size_t k = 0; k < m_title.length() - count + 1; ++k) {
    for (size_t i = 0; i < count; ++i)
      if (window[i] != key[i])
        similar = false;
    if (similar) {
      delete[] window;
      return true;
    }
    for (size_t i = 0; i < count - 1; ++i)
      window[i] = window[i + 1];
    window[count - 1] = m_title[k + count];
    similar = true;
  }
  delete[] window;
  return false;
}


bool Book::searchBookByTimeInterval(const Date& da1, const Date& da2)const {
  if (da1 >= da2) {
    std::cout << "Negative period!!" << std::endl;
    return false;
  }
  if (da1 <= m_date && m_date <= da2)
    return true;
  return false;
}


bool Book::searchBookByTimeInterval(const unsigned int& d1, const unsigned int& m1, const unsigned int& y1, const unsigned int& d2, const unsigned int& m2, const unsigned int& y2)const {
  Date da1(d1, m1, y1);
  Date da2(d2, m2, y2);
  if (da1 > da2) {
    std::cout << "Negative period!!" << std::endl;
    return false;
  }
  if (da1 <= m_date && m_date <= da2)
    return true;
  return false;
}



bool Book::searchBookByDate(const unsigned int& d, const unsigned int& m, const unsigned int& y)const {
  if (getDate().day == d && getDate().month == m && getDate().year == y)
    return true;
  return false;
}


bool Book::searchBookByDate(const unsigned int& m, const unsigned int& y)const { 
  if (getDate().month == m && getDate().year == y)
    return true;
  return false;
}


bool Book::searchBookByDate(const unsigned int& y)const { 
  if (getDate().year == y)
    return true;
  return false;
}


void Book::setBook(const std::string au, const std::string ti, const std::string boP, Date& date, const unsigned int& NoP) {
  m_author = au;
  m_title = ti;
  m_bookPublishing = boP;
  m_date.day = date.day;
  m_date.month = date.month;
  m_date.year = date.year;
  m_numberOfPages = NoP;
}


Book& Book::operator=(const Book& bo) {
  m_author = bo.m_author;
  m_title =bo.m_title;
  m_bookPublishing = bo.m_bookPublishing;
  m_date.day = bo.m_date.day;
  m_date.month = bo.m_date.month;
  m_date.year = bo.m_date.year;
  m_numberOfPages = bo.m_numberOfPages;
  return *this;
}


std::string Book::getAuthor()const { return m_author; }


std::string Book::getTitle()const { return m_title; }


std::string Book::getBookPublishing()const { return m_bookPublishing; }


unsigned int Book::getNumberOfPages()const { return m_numberOfPages; }


Date Book::getDate()const { return m_date; }
