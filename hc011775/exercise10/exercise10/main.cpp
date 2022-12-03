//
//  main.cpp
//  exercise10
//
//  Created by WC on 2022/12/2.
//
#include<iostream>
#include<string>
#include<vector>
using namespace std;

template <class Element>
class vector_expression {
public:
    vector_expression(unsigned size_in, Element data_in):size(size_in), data(new Element [size]) {
        for(unsigned i = 0 ; i < size ; i++) {
            data[i] = data_in;
        }
    }
    ~vector_expression() { delete[] data; }
    
    unsigned size_of() { return size; }
    
    Element operator [] (unsigned i) { return data[i]; }
    
private:
    unsigned size = 0 ;
    Element *data;
};

class ones:public vector_expression<int> {
public:
    ones(unsigned size_in):vector_expression(size_in, 1) { }
};

int main() {
    //Example
    ones u(4);
    for (int i = 0; i < u.size_of() ; i++) {
        cout << u[i];
    }
}
