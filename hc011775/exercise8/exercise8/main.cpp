//
//  main.cpp
//  exercise8
//
//  Created by WC on 2022/10/26.
//

#include <iostream>
#include <vector>
using namespace std;

double magnitude(double in) {
    if(in>=0) return in;
    else return -in;
}

bool sort_function(double a, double b) { return (magnitude(a)<magnitude(b)); };

int main(){
    vector<double> v{-9.3, -7.4, -3.8, -0.4, 1.3, 3.9, 5.4, 8.2};
    sort(v.begin(), v.end(), sort_function);
    for(vector<double>::iterator it = v.begin(); it!=v.end(); ++it){
        cout << *it << ' ';
    }
}
