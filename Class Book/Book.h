#pragma once

#include <iostream>
#include <string>

struct Date {
  unsigned int day;
  unsigned int month;
  unsigned int year;
  Date() { day = 0;  month = 0; year = 0; }
  Date(unsigned int d, unsigned int m, unsigned int y) { 
    day = d; month = m; year = y; 
    if (d > 31 && m > 12) throw std::invalid_argument("Wrong day or month"); 
  }
  Date(unsigned int m, unsigned int y) {
    month = m; year = y; 
    if (m > 12) throw std::invalid_argument("Wrong day or month");
  }
  Date(unsigned int y) { year = y; }
  Date(const Date& da) {
    day = da.day, month = da.month, year = da.year;
    if (da.day > 31 && da.month > 12) throw std::invalid_argument("Wrong day or month");
  }
};

  bool operator<(const Date& da1, const Date& da2);
  bool operator>(const Date& da1, const Date& da2);
  bool operator<=(const Date& da1, const Date& da2);
  bool operator>=(const Date& da1, const Date& da2);
  bool operator==(const Date& da1, const Date& da2);
  Date operator-(const Date& da1, const Date& da2);

class Book{
public:

  Book();
  Book(const std::string au, const std::string ti, const std::string boP, Date& date, const unsigned int& NoP);
  Book(const std::string au, const std::string ti, const std::string boP, const unsigned int& d, const unsigned int& m, const unsigned int& y, const unsigned int& NoP);
  ~Book(); 
  
  void getDayMonthYear()const;
  void getMonthYear()const;
  void getYear()const;

  void setDayMonthYear(const unsigned int& d, const unsigned int& m, const unsigned int& y);
  void setMonthYear(const unsigned int& m, const unsigned int& y);
  void setYear(const unsigned int& y);

  bool serachBookByAuthor(const std::string key)const;
  bool serachBookByTitle(const std::string key)const;

  bool searchBookByTimeInterval(const Date& da1, const Date& da2)const;
  bool searchBookByTimeInterval(const unsigned int& d1, const unsigned int& m1, const unsigned int& y1, const unsigned int& d2, const unsigned int& m2, const unsigned int& y2)const;

  bool searchBookByDate(const unsigned int& d, const unsigned int& m, const unsigned int& y)const;
  bool searchBookByDate(const unsigned int& m, const unsigned int& y)const;
  bool searchBookByDate(const unsigned int& y)const;

  void setBook(const std::string au, const std::string ti, const std::string boP, Date& date, const unsigned int& NoP);
  Book& operator=(const Book& bo);

  std::string getAuthor()const;
  std::string getTitle()const;
  std::string getBookPublishing()const;
  unsigned int getNumberOfPages()const;
  Date getDate()const;
 
private: 
  std::string m_author;
  std::string m_title;
  std::string m_bookPublishing;
  unsigned int m_numberOfPages;
  Date m_date;
};

