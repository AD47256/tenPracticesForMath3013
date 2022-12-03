#include <iostream>
#include <initializer_list>
#include <algorithm>
using std::cout;
using std::cin;

template <typename T=int>
class vector
{
public://constructor and basic function

    explicit vector(int size): my_size(size), data( new T [my_size] ){}
    
    vector(std::initializer_list<T> in) : vector(in.size()){
        for(typename std::initializer_list<T>::iterator it = in.begin(); it != in.end(); ++it){
            data[it-in.begin()] = *it;
        }
    }
    
    vector(const vector& that): my_size(that.my_size), data(new T[my_size ]){
std:: copy (& that.data [0], &that.data[that.my_size], &data [0]);
}

    int size () const { return my_size; }
    
    T& operator[](int i) {
            return data[i];
        }
    
public://iterator

    using vector_iterator = T * ;
    using const_iterator = const T * ;

    vector_iterator begin()
    {return vector_iterator(&data[0]);}

    vector_iterator end()
    {return vector_iterator(&data[my_size]);}

public://const_iterator
    
    using vector_const_iterator = const T * ;
    
    vector_const_iterator begin_()
    {return vector_const_iterator(&data[0]);}
    
    vector_const_iterator end_()
    {return vector_const_iterator(&data[my_size]);}

private:
    
    int my_size;
    
    std:: unique_ptr <T[]> data;

};

int main(){
    vector<int> u{2,1,8,4};
    std::sort(u.begin(), u.end());
    for(int i = 0; i < u.size() ; i++) {
        cout << u[i];
    }
}
