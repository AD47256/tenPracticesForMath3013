#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;

template <typename T>
class stack{

public:
    
    stack(unsigned int n = 0):store(n){}
    
    stack(initializer_list<T> in):store(in){}

public:
    
    T top(){
        return store.end();
    }
    
    void pop(){
        if(store.size() == 0) throw "underflow";
        store.pop_back();
    }
    
    void push(T in){
        store.push_back(in);
        //if overflow: compiler will throw std::bad_alloc
    }
    
    void clear(){
        store.resize(0);
    }
    
    unsigned int size(){
        return store.size();
    }
    
    bool full(){
        if(store.size() < store.max_size()) return false;
        else return true;
    }
    
    bool empty(){
        if(store.size() != 0) return false;
        else return true;
    }
    
private:
    
    vector<T> store;

};


