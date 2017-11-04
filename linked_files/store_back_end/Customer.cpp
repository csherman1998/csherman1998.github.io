#include <string>
#include "Customer.h"
#include <iostream>
#include <sstream>


// Customer::Customer() {
//     this->id = 000;
//     this->balance = 0;
//     //this->description = "";
//     this->name = "";
//     this->credit = false;
// }
Customer::Customer(int customerID, std::string name, bool credit): id(customerID), name(name), credit(credit), balance(0.0), productsPurchased(){
        if(name == "" ) {
            throw std::runtime_error("Must have a valid customer Name");
        } 
        
    }


    void Customer::setName(std::string name){
        if(name.length() == 0) {
            throw std::runtime_error("name cannot be empty");
        } else {
            this->name = name;
            
        }
    }
 
    void Customer::setCredit(bool hasCredit){
        this->credit = hasCredit;
    }
    std::string Customer::getName()const { return name;}
    int Customer::getID() const{ return id;}
    bool Customer::getCredit()const {return credit;}
    double Customer::getBalance() const{ return balance;}
    void Customer::processPayment(double amount){
        if(amount > 0.0) {
            this->balance += amount;
        } else {
            throw std::runtime_error("Cannot process negative payment");
        }
    }
    void Customer::processPurchase(double amount, Product product){
        if(amount > this->balance) {
            if(this->getCredit()) {
                this->balance -= amount;
                this->productsPurchased.push_back(product);

            } else {
                throw std::runtime_error("Insufficient funds");
            } 
        }else {
            this->balance -= amount;
            this->productsPurchased.push_back(product);
            }
        } 
    
  std::string Customer::getProductsPurchased() const{
        //run loop through product vector printing getId, getname ... etc
        std::string prod = "";
        std::stringstream s;
        for(int i =0; i<productsPurchased.size(); i++) {
            s << productsPurchased.at(i);
        }
        return s.str();
    }
    std::ostream& operator<< (std::ostream &out, const Customer& c) {
        out << "Customer Name: " << c.getName() << "\n" << "Customer ID: " << c.getID() 
        << "\n" << "Has Credit: " << c.getCredit() << "\n" << "Balance: " << c.getBalance() <<"\n"
        << "Products purchased --" << "\n";
        return out;
    }