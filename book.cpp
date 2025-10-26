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

//Setters
void Book::setTitle(const std::string&t) {title = t;}
void Book::setAuthor(const std::string&a) {author = a;}
void Book::setISBN(const std::string&i) {isbn = i;}
void Book::setAvailability(bool available) {isAvailable = available;}
void Book::setBorrowerName(const std::string& name) {borrowerName = name;}

//Méthodes
void Book::checkOut(const std::string& borrower) {
    if (isAvailable == true){
        isAvailable = false;
        borrowerName = borrower;
        std::cout << "Le livre " << title << " est emprunté par " << borrower << "\n";
    }else{
        std::cout << "Le livre n'est pas disponible.\n";
    }
}

void Book::returnBook(){
    if (isAvailable == false){
        isAvailable = true;
        borrowerName = "";
        std::cout << "Le livre " << title << " a bien été retourné.\n";
    }else{
        std::cout << "Le livre est déjà disponible.\n";
    }
}

