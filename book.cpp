#include <iostream>
#include <string>
#include "book.h"
using namespace std;

//Constructeurs
Book::Book() : title(""), author(""), isbn(""), isAvailable(true), borrowerName("") {}
Book::Book(const std::string& t, const std::string& a, const std::string& i)
    : title(t), author(a), isbn(i), isAvailable(true), borrowerName("") {}
