
namespace my{

    template<size_t N>
        PhoneBook<N>::PhoneBook(){
            childern_taken_.set_limit(lp2lt(N) - 1);
        }

    template<size_t N>
        bool PhoneBook<N>::is_used(const size_t n) const {
            return number_taken_.test(n); 
        }

    template<size_t N>
        void PhoneBook<N>::set_used_status(const size_t number, const bool used){
            int n = number;
            if(number_taken_.test(n) == used){
                return; 
            }
            if(used){
                number_taken_.set(n); 
            }else{
                number_taken_.reset(n);
            }
            while(n){
                bool status = number_taken_.test(n) && number_taken_.test(bro(n)) &&  
                    childern_taken_.test(n) && childern_taken_.test(bro(n));

                if(childern_taken_.test(dad(n)) == status){ 
                    return;  
                }

                if(status){
                    childern_taken_.set(dad(n));
                }else{
                    childern_taken_.reset(dad(n));
                }
                n = dad(n);
            }
        }

    template<size_t N>
        size_t PhoneBook<N>::get_unused() const {
            unsigned i = 0; 
            while(number_taken_.test(i)){
                size_t lc = left_child(i);
                size_t rc = right_child(i);

                if(!number_taken_.test(lc)){
                    return lc;
                }
                if(!number_taken_.test(rc)){
                    return rc;
                }

                if(!childern_taken_.test(lc)){
                    i = lc; 
                }else if(!childern_taken_.test(rc)) {
                    i = rc; 
                }
            } 
            return i;
        }

    template<size_t N>
        void PhoneBook<N>::print() const {
            if( N > 40) {
                std::cerr << "Not printing because size of phonebook is too big!" << std::endl;
                return;
            } 
            std::cout << std::endl;
            for (int i = 0; i < N; i++) {
                std::cout << std::setw(3);
                std::cout << i;  
            }
            std::cout << "   <- Number" << std::endl;
            for (int i = 0; i < N; i++) {
                std::cout << std::setw(3);
                std::cout << number_taken_.test(i);
            }
            std::cout << "   <- Is number in use?" << std::endl;
            for (int i = 0; i < N; i++) {
                std::cout << std::setw(3);
                std::cout << childern_taken_.test(i);
            }
            std::cout << "   <- Are all the children in use?" << std::endl;
        }

    template<size_t N>
        size_t PhoneBook<N>::left_child(const size_t i)const{
            return 2 * i + 1;
        }

    template<size_t N>
        size_t PhoneBook<N>::right_child(const size_t i) const {
            return  2 * i + 2; 
        }

    template<size_t N>
        size_t PhoneBook<N>::dad(const size_t i)const {
            if(i % 2 == 0){
                return i / 2 - 1; 
            }else{
                return i / 2;
            }
        }

    template<size_t N>
        size_t PhoneBook<N>::bro(const size_t i)const{
            if(i % 2 == 0){
                return i - 1;
            }else{
                return i + 1; 
            }
        }

    template<size_t N>
        size_t PhoneBook<N>::lp2lt(const size_t n)const{
            // largest_power_of_two_less_than n 
            size_t p = 2; 
            while( p < n){
                p = p * 2;
            }
            return p / 2; 
        }

}
