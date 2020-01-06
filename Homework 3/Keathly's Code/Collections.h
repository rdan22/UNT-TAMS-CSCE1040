//
//  Collections.h
//  OrderEntry
//
//  Created by David Keathly on 3/28/17.
//  Copyright © 2017 David Keathly. All rights reserved.
//

#ifndef Collections_h
#define Collections_h
#include <map>
using namespace std;

class customers
{
private:
    int custcount;
//    customer* tail;
//    customer* head;
    typedef map<int, customer*> custtype;
    custtype customerlist;
public:
    customers() {custcount = 0; }
    int getcount();
//    customer* gettail();
 //   customer* gethead();
    void inccount();
    void deccount();
//    void settail(customer*);
//    void sethead(customer*);
    void addcust();
    void delcust(int);
    customer* findcust(int);
    void cleanup();
    void prtlist();
};

class items
{
private:
    int itemcount;
    std::map<int, item*> itemlist;
//    item* tail;
//    item* head;
public:
    items() { itemcount = 0; }

    int getcount();
//    item* gettail();
//    item* gethead();
    void inccount();
    void deccount();
//    void settail(item*);
//    void sethead(item*);
    void additem();
    void delitem(int);
    item *finditem(int);
    void cleanup();
    void prtlist();
};


class orders
{
private:
    int ordcount;
//    order* tail;
//    order* head;
    std::map<int, order*> orderlist;
public:
    orders() {ordcount = 0; }

    int getcount();
//    order* gettail();
//   order* gethead();
    void inccount();
    void deccount();
//    void settail(order*);
//    void sethead(order*);
    void addorder();
    void delorder(int);
    order *findorder(int);
    void cleanup();
    void prtlist();
   };

#endif /* Collections_h */
