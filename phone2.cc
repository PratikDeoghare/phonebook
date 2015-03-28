
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <bitset>
#include <cmath>
#include <limits>
using namespace std;

#define N 9999999999
// #define N 9999 
//#define N 14 // numbers upto 13 

class MyBitset{
    char * arr_; 
    unsigned long lmt_;
    public:
        MyBitset(){
            arr_ = new char[N / 8 + 1]();
            lmt_ = numeric_limits<unsigned long>::max();
        }
        size_t size() const {
            return (N / 8 + 1) * 8;
        }
        void set_limit(const unsigned long lmt){
            lmt_ = lmt; 
        }
        bool test(const unsigned long i) const {
            if( i >= lmt_) return true; 
            return arr_[i/8] & (1 << (7 - i % 8)); 
        }
//        bool operator[](const unsigned long i) const {
//            return test(i);
//        }

        void set(unsigned long i){
            arr_[i/8] = arr_[i/8] | (1 << (7 - i % 8)); 
        }
        void reset(unsigned long i){
            arr_[i/8] = arr_[i/8] & ~(1 << (7 - i % 8));
        }
        ~MyBitset(){
            delete [] arr_;
        }
};

unsigned long left_child(unsigned long i){
    return 2 * i;
}

unsigned long right_child(unsigned long i){
    return  2 * i + 1; 
}

unsigned long dad(unsigned long i){
    if(i % 2 == 0){
        return i / 2; 
    }else{
        return (i - 1) / 2; 
    }
}

unsigned long bro(unsigned long i){
    if(i % 2 == 0){
        return i + 1;
    }else{
        return i - 1; 
    }
}

unsigned long lp2lt(unsigned long n){
    // largest_power_of_two_less_than n 
    unsigned long p = 2; 
    while( p < n){
        p = p * 2;
    }
    return p / 2; 
}

class PhoneBook{
    MyBitset number_taken_; 
    MyBitset childern_taken_;
//    bitset<N> number_taken_; 
//    bitset<N> childern_taken_; 
    public:
    PhoneBook(){
        childern_taken_.set_limit(lp2lt(N) - 1);
//        for(unsigned long i = lp2lt(N) - 1; i < N; ++i){
//            childern_taken_.set(i);
//        }
    }

    bool is_used(unsigned long n){
        return number_taken_.test(n); 
    }

    void set_used_status(unsigned long n, bool used){
        if(number_taken_.test(n) == used) return; 
        if(used){
            number_taken_.set(n); 
        }else{
            number_taken_.reset(n);
        }
        while(n){
            bool status = number_taken_.test(n) && number_taken_.test(bro(n)) &&  
                childern_taken_.test(n) && childern_taken_.test(bro(n));

            if( childern_taken_.test(dad(n)) == status) return;  

            if(status){
                childern_taken_.set(dad(n));
            }else{
                childern_taken_.reset(dad(n));
            }
            n = dad(n);
        }
    }

    unsigned long get_unused(){
        unsigned i = 1; 
        while( number_taken_.test(i) ){
            unsigned long lc = left_child(i);
            unsigned long rc = right_child(i);
            if(childern_taken_.test(lc) && childern_taken_.test(rc)){
                return numeric_limits<unsigned long>::max(); 
            }
            if(!childern_taken_.test(lc)){
                i = lc; 
            }else if(!childern_taken_.test(rc)) {
                i = rc; 
            }
        } 
        return i;
    }

    void print() const {
        cout << endl;
        for (int i = 0; i < N; i++) {
            cout << number_taken_.test(i);
        }
        cout << endl;
        for (int i = 0; i < N; i++) {
            cout << childern_taken_.test(i);
        }
        cout << endl;
    }
};


int main(int argc, const char *argv[])
{


    PhoneBook pb;




   
    return 0;
}

