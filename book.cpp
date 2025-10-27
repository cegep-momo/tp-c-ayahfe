#include <iostream>
#include <string>
#include <sstream>
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
std::string Book::toString() const {
    std::string livresInfo = "Titre: " + title + "\nAuteur: " + author + "\nISBN: " + isbn + "\nDisponibilité: ";
    if (isAvailable==true){
        livresInfo += "Disponible\n";
    }else{
        livresInfo += "Non disponible. Il est emprunté par " + borrowerName + "\n";
    }
    return livresInfo;
}
std::string Book::toFileFormat() const {
    if (isAvailable == true){
        std::string infoDisponible = title + "|" + author + "|" + isbn + "|1|";
        return infoDisponible;
    } else {
        std::string infoNonDisponible = title + "|" + author + "|" + isbn + "|0| " + borrowerName;
        return infoNonDisponible;
    }
}
void Book::fromFileFormat(const std::string& line) {
    std::string title_;
    std::string author_;
    std::string isbn_;
    std::string availability_;
    std::string borrower_;
    std::stringstream ss(line);
    getline(ss, title_, '|');
    getline(ss, author_, '|');
    getline(ss, isbn_, '|');
    getline(ss, availability_, '|');
    getline(ss, borrower_, '|');
    title = title_;
    author = author_;
    isbn = isbn_;
    isAvailable = (availability_ == "1");
    borrowerName = borrower_;

}
