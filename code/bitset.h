
#ifndef my_bitset_h_
#define my_bitset_h_

#include <limits>


// Written for the love of bithacks! 

namespace my{
    template<std::size_t N>
        class bitset{

            char * arr_; 
            unsigned long lmt_;

            public:
            bitset(){
                arr_ = new char[N / 8 + 1]();
                lmt_ = std::numeric_limits<unsigned long>::max();
            }
            std::size_t size() const {
                return (N / 8 + 1) * 8;
            }
            void set_limit(const unsigned long lmt){
                lmt_ = lmt; 
            }
            bool test(const unsigned long i) const {
                if( i >= lmt_) return true; 
                return arr_[i/8] & (1 << (7 - i % 8)); 
            }
            void set(const unsigned long i){
                arr_[i/8] = arr_[i/8] | (1 << (7 - i % 8)); 
            }
            void reset(const unsigned long i){
                arr_[i/8] = arr_[i/8] & ~(1 << (7 - i % 8));
            }
            ~bitset(){
                delete [] arr_;
            }
        };
}

#endif // my_bitset_h_
