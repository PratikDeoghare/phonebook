
#include "PhoneBook.h"
#include <iostream>
using namespace std;
using my::PhoneBook;

void test(){

    PhoneBook<15> pb;

    for(int i = 0; i < 12; ++i){
        cout << "Adding subscriber " << i << endl;
        pb.set_used_status(i, true);
    }
    pb.print();

    cout << "Is 8 used? " << pb.is_used(8) << endl;
    cout << "Removing subscriber 8" << endl;
    pb.set_used_status(8, false);
    pb.print();
    cout << "Is 8 used? " << pb.is_used(8) << endl;

    cout << "Removing subscriber 5" << endl;
    pb.set_used_status(5, false);
    cout << "Is 5 used? "  << pb.is_used(5) << endl;


    int x = pb.get_unused();
    cout << "Unused number " << x << endl; 
    cout << "Adding subscriber " << x << endl; 
    pb.set_used_status(x, true);
    pb.print();

    cout << "Unused number "  << pb.get_unused();
}


int main(int argc, const char *argv[])
{
    test();
    return 0;
}

