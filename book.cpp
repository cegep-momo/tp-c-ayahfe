#include <iostream>
#include <string>
#include "book.h"
using namespace std;

//Constructeurs
Book::Book() : title(""), author(""), isbn(""), isAvailable(true), borrowerName("") {}
Book::Book(const std::string& t, const std::string& a, const std::string& i)
    : title(t), author(a), isbn(i), isAvailable(true), borrowerName("") {}

//Getters
std::string Book::getTitle()const {return title;}
std::string Book::getAuthor()const {return author;}
std::string Book::getISBN() const {return isbn;}
bool Book::getAvailability() const {return isAvailable;}
std::string Book::getBorrowerName() const {return borrowerName;}
