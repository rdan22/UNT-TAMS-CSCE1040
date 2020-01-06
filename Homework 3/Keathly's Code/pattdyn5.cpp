#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#define CHUNKSIZE 2

class item
{
private:
int item_id;
   float price;
public:
    void setid (int id) {item_id = id; }
        int getid() {return item_id; }
    void setprice (float p) {price = p;}
    float getprice() {return price;}
} ;

class customer
{
private:
  int cust_id;
    string name;
public:
    void setid (int id) {cust_id = id; }
    int getid() {return cust_id; }
    void setname (string n) {name = n;}
    string getname() { return name;}
   
} ;

class order
{
private:
    int order_id;
  int cust_loc;
  int item_loc;
public:
    void setid (int id) {order_id = id; }
    int getcustid() {return order_id; }
    void setcustid (int id) {cust_loc = id; }
    int getitemid() {return cust_loc; }
    void setitemid (int id) {item_loc = id; }
    int getid() {return item_loc; }
} ;

class customers
{
private:
    int cust_cnt;
  int cust_cap;
//  customer *cust_list;
    vector <customer> cust_list;
public:
    customers() {cust_cnt = 0; cust_cap = CHUNKSIZE;
 //     cust_list = new customer[CHUNKSIZE];
    }
    ~customers() {}
    void addcustomer();
    void prtcustomers();
    void storecust();
    void loadcust();
    int findcustbyname(string nm);

} ;

class items
{
private:
    int item_cnt;
  int item_cap;
//  item *item_list;
    vector <item> item_list;
public:
    items() {item_cnt = 0; item_cap = CHUNKSIZE;
//     item_list = new item[CHUNKSIZE];
    }
    ~items() {}
    void additem();
    void prtitems();
    void storeitems();
    void loaditems();
    float GetItemPricebyID (int index);

} ;

class orders
{
private: int order_cnt;
  int order_cap;
//  order *order_list;
    vector <order> order_list;
public:
    orders() { order_cnt = 0; order_cap = CHUNKSIZE;
//          order_list = new order[CHUNKSIZE];
    }
    ~orders() {  }
    void addorder();
    void prtsales();
    void storeorders();
    void loadorders();
    void printordersbycust(customers* c, items* ord,string nm);


} ;

void items::additem()
{
  int id; float pr;
    item temp;
//  if (item_cnt == item_cap)
//  {
//    item *temp;
//    temp = new item [item_cap + CHUNKSIZE];
//      for (int i = 0;i < item_cnt;i++) temp[i] = item_list[i];
//    item_cap += CHUNKSIZE;
//      delete [] item_list;
//    item_list = temp;
//  }


  printf("Enter new item ID: ");
  cin >> id;
  printf ("Enter cost: ");
    cin >> pr;
    temp.setprice(pr);
    temp.setid(id);
    item_list.push_back(temp);
    
  item_cnt += 1;
}

void customers::addcustomer()
{
    int id; string temp; customer tmp;
    
//    if (cust_cnt == cust_cap)
//    {
 //       customer *temp;
//        temp = new customer[cust_cap + CHUNKSIZE];
//        for (int i = 0;i < cust_cnt;i++) temp[i] = cust_list[i];
//        delete [] cust_list;
//        cust_cap += CHUNKSIZE;
//        cust_list = temp;
//    }

  printf("Enter new customer ID: ");
  cin >> id; cin.ignore();
  printf ("Enter name: ");
  cin >> temp; cin.ignore();
  cout << "got data"<< temp<<endl;
    tmp.setid(id);
    tmp.setname(temp);
    cust_list.push_back(tmp);

//  cust_list[cust_cnt].setid(id); cout << "set id"<<endl;
//  cust_list[cust_cnt].setname(temp); cout << "set name"<<endl;
  cust_cnt += 1; cout<<"inc count"<<endl;
}

void orders::addorder()
{
    int id; int cs; int iid; order temp;
//    if (order_cnt == order_cap)
//    {
//        order *temp;
//        temp = new order[order_cap + CHUNKSIZE];
//        for (int i = 0;i < order_cnt;i++) temp[i] = order_list[i];
//        delete [] order_list;
//        order_cap += CHUNKSIZE;
//        order_list = temp;
//    }


  printf("Enter new order id: ");
  cin >> id;
  printf ("Enter customer ID for order: ");
  cin >> cs;
 printf ("Enter item ID for order: ");
  cin >> iid;
    temp.setid(id);
    temp.setcustid(cs);
    temp.setitemid(iid);
    order_list.push_back(temp);
//  order_list[order_cnt].setid(id);
// order_list[order_cnt].setcustid(cs);
//order_list[order_cnt].setitemid(iid);
  order_cnt += 1;
}

void customers::prtcustomers()
{
  int i;
  for ( i=0; i < cust_cnt; i++)
  {

	cout << "Customer id: "<< cust_list[i].getid() << " Name:" <<  cust_list[i].getname() << endl;
  }
}


void items::prtitems()
{
 int i;
  for ( i=0; i < item_cnt; i++)
  {

    cout << "Item ID: " << item_list[i].getid()  << " Price: " << item_list[i].getprice() << endl;
  }
}


void orders::prtsales()
{
  int i;
  for ( i=0; i < order_cnt; i++)
  {

    cout << "Order id: " << order_list[i].getid() << " Customer ID: " << order_list[i].getcustid() << " Item ID: " << order_list[i].getitemid() << endl;
  }
}

float items::GetItemPricebyID (int id)
{
    int index;
    for (index = 0;item_list[index].getid() != id; index++ );
    return item_list[index].getprice();
}


int customers::findcustbyname(string nm)
{
    int index=0;
    
    for (index = 0;cust_list[index].getname() != nm;index++);
    if (index == cust_cnt) {return -1;}
    else {return cust_list[index].getid();}
    
}

void orders::printordersbycust(customers* c, items* ord,string nm)
{
    int index;
    int total = 0;
    index = c->findcustbyname(nm);
  //  cout<<"index: "<<index<<endl;
    if (index == -1)
    {
        cout << "customer does not exist\n";
        return;
    }
    else {
        for (int i = 0; i < order_cnt; i++)
        {
            if (order_list[i].getcustid() == index)
            {
                int j;
                j = order_list[i].getitemid();
                cout << "item id" << j << endl;
                total += ord->GetItemPricebyID(j);
            }
        }
    }
    cout << "Total for customer " << nm << " is $" << total << endl;
}


void customers::storecust()
{
    ofstream fout;
    fout.open("customers.dat");
    fout << cust_cnt << endl;
    for ( int i=0; i < cust_cnt; i++)
    {
        
        fout << cust_list[i].getid() << " " <<  cust_list[i].getname() << endl;
    }
    fout.close();
}

void customers::loadcust()
{
    ifstream fin;
    int id;
    string name;
    customer temp;
    fin.open("customers.dat");
    fin >> cust_cnt; fin.ignore();
 //   cust_list = new customer[cust_cnt];
    
    for ( int i=0; i < cust_cnt; i++)
    {
        
        fin >> id >> name;
        temp.setname(name);
        temp.setid(id);
        cust_list.push_back(temp);
    }
    fin.close();

}

void items::storeitems()
{
    ofstream fout;
    fout.open("items.dat");
    fout << item_cnt << endl;
    for ( int i=0; i < item_cnt; i++)
    {
        
        fout << item_list[i].getid() << " " <<  item_list[i].getprice() << endl;
    }
    fout.close();
}

void items::loaditems()
{
    ifstream fin;
    int id;
    float price;
    fin.open("items.dat");
    fin >> item_cnt; fin.ignore();
 //   item_list = new item[item_cnt];
    
    for ( int i=0; i < item_cnt; i++)
    {
        item temp;
        fin >> id >> price;
        temp.setprice(price);
       temp.setid(id);
        item_list.push_back(temp);   }
    fin.close();
    
}

void orders::storeorders()
{
    ofstream fout;
    fout.open("orders.dat");
    fout << order_cnt << endl;
    for ( int i=0; i < order_cnt; i++)
    {
        
        fout << order_list[i].getid() << " " <<  order_list[i].getcustid() << " "<<order_list[i].getitemid() << endl;
    }
    fout.close();
}

void orders::loadorders()
{
    ifstream fin;
    int id, id2, id3;
    order temp;
    fin.open("orders.dat");
    fin >> order_cnt; fin.ignore();
  //  order_list = new order[order_cnt];
    
    for ( int i=0; i < order_cnt; i++)
    {
        
        fin >> id >> id2 >> id3;
       
        temp.setcustid(id2);
        temp.setitemid(id3);
        temp.setid(id);
        order_list.push_back(temp);
    }
    fin.close();
    
}


// start of main and main functions

void loaddata();
void storedata();


customers custs;
items inventory;
orders sales;

int main ()
{

  
  int choice = -1;
    string nm;
 


  while (choice != 0)
  {
    //loaddata();
    printf ("What do you want to do?\n");
    printf (" 0 - quit\n 1 - Add item\n 2 - Add customer\n 3 - Add order\n 4 - print customers\n 5 - print items\n 6 - print orders\n 7 - load\n 8 - store\n 9 - print orders total for a customer\n");
    printf ("Enter your selection: ");
    scanf ("%d%*c", &choice);

    switch (choice)
    {

      case 1: inventory.additem(); break;
      case 2: custs.addcustomer(); break;
      case 3: sales.addorder();break;
      case 4: custs.prtcustomers();break;
      case 5: inventory.prtitems();break;
      case 6: sales.prtsales();break;
      case 7: loaddata(); break;
      case 8: storedata(); break;
        case 9: {
            cout << "Customer Name: " ;
            cin >> nm; cin.ignore();
            sales.printordersbycust(&custs, &inventory, nm);
            break;}
     }
  }
 //storedata();
}


void loaddata()
{
    custs.loadcust();
    inventory.loaditems();
    sales.loadorders();
}

void storedata()
{
    custs.storecust();
    inventory.storeitems();
    sales.storeorders();

}



