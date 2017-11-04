#ifndef _Customer_H
#define _Customer_H

#include <string>
#include <vector>
#include "Product.h"
#include <stdexcept>
#include <iostream>
class Customer {
    private:
        int id;
        std::string name;
        bool credit;
        double balance;
        std::vector<Product> productsPurchased;

    public:
      
        // Customer();
        Customer(int customerID, std::string name, bool credit);
        int getID() const;
        std::string getName()const;
        void setName(std::string name);
        bool getCredit()const;
        void setCredit(bool hasCredit);
        double getBalance() const;
        void processPayment(double amount);
        void processPurchase(double amount, Product product);
        std::string getProductsPurchased() const;
};
std::ostream& operator<< (std::ostream &out, const Customer& c);
#endif