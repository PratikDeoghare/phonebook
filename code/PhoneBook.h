

#ifndef my_phonebook_h_
#define my_phonebook_h_

#include "bitset.h"
#include <iostream>
#include <limits>
#include <iomanip>

namespace my{

    template<size_t N>
        class PhoneBook{

            my::bitset<N> number_taken_; 
            my::bitset<N> childern_taken_;

            public:

            PhoneBook();
            bool is_used(const size_t n) const; 
            size_t get_unused() const ;
            void set_used_status(const size_t number, const bool used);
            void print() const;

            private:

            size_t left_child(const size_t i) const;
            size_t right_child(const size_t i) const;
            size_t dad(const size_t i) const;
            size_t bro(const size_t i) const;
            size_t lp2lt(const size_t n) const;
        };
}


#include "PhoneBook.tpp"

#endif //my_phonebook_h_
