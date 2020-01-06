//
//  main.cpp
//  OrderEntry
//
//  Created by David Keathly on 3/28/17.
//  Copyright © 2017 David Keathly. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include "Entities.h"
#include "Collections.h"

using namespace std;


int main(int argc, const char * argv[]) {
   
    
    customers custs;
    items inventory;
    orders sales;
    int choice = -1;
    int id = 0;
   
   
    while (choice != 0)
    {
        printf ("What do you want to do?\n");
        printf (" 0 - quit\n 1 - Add item\n 2 - Add customer\n 3 - Add order\n 4 - print customers\n 5 - print items\n 6 - print orders\n 7 - delete customer\n 8 - delete order\n 9 - delete item\n");
        printf ("Enter your selection: ");
        scanf ("%d%*c", &choice);
        
        switch (choice)
        {
                
            case 1: inventory.additem(); break;
            case 2: custs.addcust(); break;
            case 3: sales.addorder();break;
            case 4: custs.prtlist();break;
            case 5: inventory.prtlist();break;
            case 6: sales.prtlist();break;
            case 7: {
                cout << "what customer to delete? ";
                cin >> id; cin.ignore();
                custs.delcust(id);
                break;
            }
            case 8: {
                cout << "what order to delete? ";
                cin >> id; cin.ignore();
                sales.delorder(id);
                break;
            }

            case 9: {
                cout << "what item to delete? ";
                cin >> id; cin.ignore();
                inventory.delitem(id);
                break;
            }

        }
    }
    //do cleanup
    inventory.cleanup();
    sales.cleanup();
    custs.cleanup();
    return 0;
}
