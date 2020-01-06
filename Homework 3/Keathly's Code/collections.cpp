//
//  collections.cpp
//  OrderEntry
//
//  Created by David Keathly on 3/29/17.
//  Copyright © 2017 David Keathly. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include "Entities.h"
#include "Collections.h"


using namespace std;

//collections methods

int customers::getcount() { return custcount;}

//customer* customers::gettail() {return tail;}

//customer* customers::gethead() {return head;}

void customers::inccount() {custcount++;}

void customers::deccount() { custcount--;}

//void customers::settail(customer* tp) {tail = tp;}

//void customers::sethead(customer* hp) {head = hp;}

void customers::addcust() {
    int id; string buff;
    customer *temp;
    
    cout << "Enter new customer ID: ";
    cin >> id;
    cin.ignore();
    
    cout << "Enter name: ";
    getline(cin, buff);
 //   cin.ignore();

    temp = new customer(id,buff);
    
   
    customerlist[id] = temp;
    inccount();
}



void customers::delcust(int id)
{
    customerlist.erase(id);
    deccount();
    return;
}

customer* customers::findcust(int id)
{
    customer *temp;
    temp = customerlist[id];
    return temp;
  
}

void customers::cleanup()
{
    customerlist.clear();
}

void customers::prtlist()
{
    customer *temp;
    for (auto it = customerlist.begin(); it !=customerlist.end(); ++it)
    {
        temp = it->second;
        cout << "customer id: " << temp->getid() << " Customer name: " << temp->getname() <<endl;
    }
}


// items methods

int items::getcount() {return itemcount;}

//item* items::gettail() {return tail;}

//item* items::gethead() {return head;}

void items::inccount() {itemcount++;}

void items::deccount() {itemcount--;}

//void items::settail(item*tp) {tail = tp;}

//void items::sethead(item* hp) {head = hp;}

void items::additem()
{
    int id; float pr, otype;
    item *temp;
    string d1, d2;
    
    cout << "Enter new item ID: ";
    cin >> id;
    cin.ignore();
    
    cout << "Enter price: ";
    cin  >> pr;
    
    cout << "Enter 1 for Preorder or 2 for Backorder"<<endl;
    cin >> otype;
    cin.ignore();
    cout << "Enter available date as xx/xx/xx: " << endl;
    cin >> d1;
    cout << "Enter ship date as xx/xx/xx: " << endl;
    cin >> d2;
    
    if (otype == 1)
      temp = new preitem(d1,d2,id,pr);
    else
      temp = new boitem(d1,d2,id,pr);
    
    itemlist[id] = temp;
    inccount();

}

void items::delitem(int id)
{
    
    itemlist.erase(id);
    deccount();
}

item* items::finditem(int id)
{
    item *temp;
    temp = itemlist[id];
    return temp;

}

void items::cleanup()
{
    itemlist.clear();
}

void items::prtlist()
{
    
    item *temp;
    for (auto it = itemlist.begin(); it !=itemlist.end(); ++it)
    {
        temp = it->second;
        temp->print();
    }
}

//orders methods

int orders::getcount() {return ordcount;}

//order* orders::gettail(){return tail;}

//order* orders::gethead() {return head;}

void orders::inccount() {ordcount++;}

void orders::deccount() {ordcount--;}

//void orders::settail(order*tp) {tail = tp;}


//void orders::sethead(order* hp) {head = hp;}


void orders::addorder()
{
    int id, id2, id3;
    order *temp;
    
    cout << "Enter new order ID: ";
    cin >> id;
    cin.ignore();
    
    cout << "Enter customer ID: ";
    cin >> id2;
    cin.ignore();
    
    cout << "Enter item ID: ";
    cin >> id3;
    cin.ignore();
    
    temp = new order(id,id2, id3);
    
    orderlist[id] = temp;
    inccount();

}

void orders::delorder(int id)
{
    orderlist.erase(id);
        deccount();
        return;
   
}

order* orders::findorder(int id)
{
    order *temp;
    temp = orderlist[id];
    return temp;
    
}

void orders::cleanup()
{
    orderlist.clear();
}

void orders::prtlist()
{
    order *temp;
    for (auto it = orderlist.begin(); it !=orderlist.end(); ++it)
    {
        temp = it->second;
        cout << "Order id: " << temp->getid() << " Customer id: " << temp->getcustid() << " item id: " << temp->getitemid() <<endl;
    }
}
