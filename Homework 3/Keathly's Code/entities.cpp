//
//  entities.cpp
//  OrderEntry
//
//  Created by David Keathly on 3/28/17.
//  Copyright © 2017 David Keathly. All rights reserved.
//


#include <iostream>
#include <string>
#include "Entities.h"
using namespace std;

//item methods

item::item (int id, float pr)  {item_id = id; price = pr;}

int item::getid()  {return item_id;}

float item::getprice() {return price;}

item * item::getnext() {return next;}

void item::setid(int id) {item_id = id;}

void item::setprice(float pr) {price = pr;}

void item::setnext(item *np) {next = np;}

void item::print() {
    cout << "Item ID: " << item_id << " Price: " << price << endl;
}

boitem::boitem (string d1, string d2, int id, float pr):item (id,pr)
{
 availdate = d1;
shipdate = d2;
}

void boitem::setavdate(string d){availdate = d;}
void boitem::setshdate( string d){shipdate = d;}
string boitem::getavdate(){return availdate;}
string boitem::getshdate(){return shipdate;}
void boitem::print()
{
    item::print();
    cout << "Available date: "<<availdate << " Ship Date: " << shipdate <<endl;
}



preitem::preitem (string d1, string d2, int id, float pr):item(id,pr)
{
    availdate = d1;
    shipdate = d2;
}

void preitem::setavdate(string d){availdate = d;}
void preitem::setshdate( string d){shipdate = d;}
string preitem::getavdate(){return availdate;}
string preitem::getshdate(){return shipdate;}
void preitem::print()
{
    item::print();
    cout << "Available date: "<<availdate << " Ship Date: " << shipdate <<endl;
}

ostream& operator<<(ostream& st, item& it)
{
    it.print();
    return st;
}



//customer methods

customer::customer(int id, string nm) { custid = id; name = nm;}

int customer::getid() {return custid;}

string customer::getname() {return name;}

customer* customer::getnext() {return next;}

void customer::setid(int id) {custid = id;}

void customer::setname(string nm) {name = nm;}

void customer::setnext(customer* np) {next = np;}

void customer::print() {
    cout << "Customer ID: " <<custid << " Name: " << name <<endl;
}

//order methods

order::order(int id, int id2, int id3) {orderid = id; custloc = id2; itemloc = id3;}

int order::getid() {return orderid;}

int order::getcustid() { return custloc;}

int order::getitemid() {return itemloc;}

order* order::getnext() {return next;}

void order::setid(int id) { orderid = id;}

void order::setcustid(int id) {custloc = id;}

void order::setitemid(int id) {itemloc = id;}

void order::setnext(order* np) {next = np;}

void order::print() {
    cout << "order id: " <<orderid << "customer: " << custloc << "Item: " <<itemloc <<endl;
}

