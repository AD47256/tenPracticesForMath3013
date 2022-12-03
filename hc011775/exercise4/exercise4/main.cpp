//
//  main.cpp
//  exercise2
//
//  Created by WC on 2022/10/22.
//

#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;

class polynomial
{
public:
    
    polynomial(unsigned long n = 0):coeff(n+1),degree(n){}
   
    polynomial(initializer_list<double> in):coeff{in}, degree(in.size()-1){}
   
    ~polynomial(){}
    
public:
    
    double& operator [] (unsigned long i) {return coeff[i];}
    
    unsigned long degreeof()
    {
        return degree;
    }
    
    void print_expr()
    {
        for(vector<double>::iterator it = coeff.end()-1; it != coeff.begin()-1; --it)
        {
            if(coeff.end()-it == 1)
            {
                cout << *it << "x^"<< degree-(it-coeff.begin());
            }
            else if(it-coeff.begin() == 0)
            {
                cout << " + " << *it << "x^" << degree;
            }
            else
            {
                cout << " + " << *it << "x^"<< degree-(it-coeff.begin());
            }
        }
    }
    
    double evaluate(double x)
    {
        double s=coeff[0];
        for(vector<double>::iterator it = coeff.end()-1; it != coeff.begin()-1; --it)
        {
            s = x*s + *(it+1);
        }
        return s;
    }
    
    polynomial operator+ (const polynomial& r)
    {
        polynomial copy(r);
        vector<double> copyv = coeff;
        unsigned long&& size = (copyv.size() <= copy.coeff.size()) ? copy.coeff.size():copyv.size();
        copyv.resize(size);
        copy.coeff.resize(size);
        for(int i=0; i<copyv.size(); ++i)
        {
        copy.coeff[i] = copy.coeff[i] + copyv[i];
        }
        return copy;
    }

    polynomial operator- (const polynomial& r)
    {
        polynomial copy(r);
        vector<double> copyv = coeff;
        unsigned long&& size = (copyv.size() <= copy.coeff.size()) ? copy.coeff.size():copyv.size();
        copyv.resize(size);
        copy.coeff.resize(size);
        for(int i=0; i<copyv.size(); ++i)
        {
        copy.coeff[i] = copy.coeff[i] - copyv[i];
        }
        return copy;
    }
    
private:
    
    unsigned long degree;
    
    vector<double> coeff;
};

int main(){
    //use of initializer
    polynomial poly1{9,10,7};
    poly1.print_expr();
}
