#include <string>
#include "Product.h"


// Product::Product(){
//     /*
//     int id,inventory,numSold;
//         std::string name,description;
//         double totalPaid;
//     */
//     this->inventory = 0;
//     this->id = 0;
//     this ->numSold = -1;
//     this->description = "";
//     this->name = "";
//     this->totalPaid = 0;
// }
Product::Product(int productID, std::string productName) : id(productID), name(productName),
inventory(0), numSold(0), totalPaid(0.0), description("") {
    if(productName.length() == 0) {
        throw std::runtime_error("Empty product name given");
    } 
}
int Product::getID() const  { return id;}
std::string Product::getName() const { return name;}
std::string Product::setName(std::string productName) {
    if(productName.length() == 0) {
        throw std::runtime_error("name cannot be empty");
    }
    this->name = productName;
    return "" ;
}
std::string Product::getDescription() const { return description;}
void Product::setDescription(std::string description) {
    this->description = description;
}
int Product::getNumberSold() const {return numSold;}
double Product::getTotalPaid() const { return totalPaid;}
int Product::getInventoryCount() const { return inventory;}






void Product::addShipment(int shipment_Quantity, double shipmentCost){
    if(shipment_Quantity <0 || shipmentCost < 0) {
        throw std::runtime_error("Negative values");
    } else {
        this->inventory += shipment_Quantity;
        this->totalPaid += shipmentCost;
    }
}
void Product::reduceInventory(int purchaseQuantity){
    if(purchaseQuantity < 0) { throw std::runtime_error("negatve quantity");}
    if(purchaseQuantity > this->inventory) {
        throw std::runtime_error("Not enough inventory for order");
    } else {
        this->inventory -= purchaseQuantity;
        this->numSold += purchaseQuantity;
    }
}
double Product::getPrice() const {
    return ( ((double) this->totalPaid / (this->inventory + this->numSold)) * 1.25);
}
std::ostream& operator<< (std::ostream &out, const Product& c) {
    out << "Product Name: " << c.getName() << "\n" << "Product ID: " << c.getID() << "\n" 
    << "Description: " << c.getDescription() << "\n" << "Inventory: " << c.getInventoryCount() << "\n"
    << "Total Paid" << c.getTotalPaid() << "\n" ; 
    return out;
}