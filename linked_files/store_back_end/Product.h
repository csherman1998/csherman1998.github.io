
#ifndef _Product_H
#define _Product_H

#include <string>
#include <stdexcept>
#include <iostream>
class Product {
    private:
        int id;
        int inventory;
        int numSold;
        std::string name;
        std::string description;
        double totalPaid;
    public:
        // Product();
        Product(int productID, std::string productName);
        
        int getID() const;
        std::string getName() const;
        std::string setName(std::string productName);
        std::string getDescription() const;
        void setDescription(std::string description);
        int getNumberSold() const;
        double getTotalPaid() const;
        int getInventoryCount() const;
        void addShipment(int shipment_Quantity, double shipmentCost);
        void reduceInventory(int purchaseQuantity);
        double getPrice() const;
        
};
std::ostream& operator<< (std::ostream &out, const Product& c);
#endif