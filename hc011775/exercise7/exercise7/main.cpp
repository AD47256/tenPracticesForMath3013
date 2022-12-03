//
//  main.cpp
//  exercise7
//
//  Created by WC on 2022/10/26.
//

#include <iostream>
using namespace std;

class odd_iterator{
public:
    
    odd_iterator(const unsigned int& in = 1){
        if (in%2 == 0) {
            throw "Even number required";
        }
        else odd = in;
    }
    
    odd_iterator(const odd_iterator& in):odd(in.odd){}
    
    odd_iterator& operator++ (){
        odd += 2;
        return *this;
    }
    
    odd_iterator operator++ (int){
        odd_iterator temp = *this;
        this->odd += 2;
        return temp;
    }
    
    unsigned int operator* (){
        return odd;
    }
    
    bool operator== (odd_iterator right){
        if(this->odd == right.odd) return true;
        else return false;
    }
    
    bool operator!= (odd_iterator right){
        if(this->odd != right.odd) return true;
        else return false;
    }
    
    odd_iterator& operator= (const odd_iterator& in){
        odd = in.odd;
        return *this;
    }
    
private:
   
    unsigned int odd=1;
    
};

int main(int argc, const char * argv[]) {
    odd_iterator de;
    odd_iterator u(3); odd_iterator v(7);
    odd_iterator copy(u);
    de = u++;
    de = ++v;
}
