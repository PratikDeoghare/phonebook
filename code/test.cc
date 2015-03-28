
#include "PhoneBook.h"
#include <iostream>
using namespace std;
using my::PhoneBook;

void test(){

    PhoneBook<15> pb;

    for(int i = 0; i < 12; ++i){
        cout << "Setting " << i << endl;
        pb.set_used_status(i, true);
    }

    pb.print();

    pb.set_used_status(8, false);
    pb.print();

    cout << "Is 8 used " << pb.is_used(8) << endl;

    pb.print();

    pb.set_used_status(5, false);

    cout << "Unused number "  << pb.get_unused();

    pb.set_used_status(8, true);

    pb.print();

    cout << "->Unused number "  << pb.get_unused();

    pb.print();
}


int main(int argc, const char *argv[])
{
    test();
    return 0;
}

