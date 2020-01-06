//
//  Entities.h
//  OrderEntry
//
//  Created by David Keathly on 3/28/17.
//  Copyright © 2017 David Keathly. All rights reserved.
//

#ifndef Entities_h
#define Entities_h
using namespace std;

class item {
    
private:
    int item_id;
    float price;
    item * next;

public:
    
    item (int, float);
    int getid();
    float getprice();
    item * getnext();
    void setid(int);
    void setprice(float);
    void setnext(item *);
    virtual void print();
    friend ostream& operator<<(ostream& st, item& it);
};

class boitem : public item
{
private:
    std::string availdate;
    std::string shipdate;
public:
    boitem (std::string d1, std::string d2, int id, float pr);
    void setavdate(std::string d);
    void setshdate( std::string d);
    std::string getavdate();
    std::string getshdate();
    void print();

    
};


class preitem : public item
{
private:
    std::string availdate;
    std::string shipdate;
public:
    preitem (std::string d1, std::string d2, int id, float pr);
    void setavdate(std::string d);
    void setshdate( std::string d);
    std::string getavdate();
    std::string getshdate();
    void print();
};


class customer
{
private:
    int custid;
    std::string name;
    customer *next;
    
public:
    customer(int, std::string);
    int getid();
    std::string getname();
    customer* getnext();
    void setid(int);
     void setname(std::string);
    void setnext(customer*);
    void print();
};

class order
{
private:
    int orderid;
    int custloc;
    int itemloc;
    order *next;
public:
    order(int, int, int);
    int getid();
    int getcustid();
    int getitemid();
    order* getnext();
    void setid(int);
    void setcustid(int);
    void setitemid(int);
    void setnext(order*);
    void print();
};
#endif /* Entities_h */
