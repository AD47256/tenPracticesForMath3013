
//  Created by WC on 2022/10/21.
//

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int age;
    cout << "What's your age?" << '\n';
    cin >> age;
    while(cin.fail()||age<0)
    {
        cin.clear();
        cin.ignore();
        cout << "What's your age?" << '\n';
        cin.ignore();
        cin >> age;
    }
    cout << "Your age is " << age <<'\n';
    ofstream outfile;
    outfile.open("/Users/WC/Desktop/hc011775/exercise1/exercise1/age.txt", fstream::out);
    if(outfile) {outfile << "Your age is " << age <<'\n';};
    outfile.close();
}
