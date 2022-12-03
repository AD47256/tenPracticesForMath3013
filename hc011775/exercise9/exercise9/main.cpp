#include <iostream>
#include <map>
using namespace std;
int main(int argc, const char * argv[]) {
    map<string, unsigned long> phone_numbers;
    phone_numbers["Alcaraz"] = 8345;
    phone_numbers["Murray"] = 8577;
    phone_numbers["Nadal"] = 8326;
    phone_numbers["Djokovic"] = 8877;
    for(map<string, unsigned long>::iterator it = phone_numbers.begin(); it != phone_numbers.end(); ++it){
        if(it->first == "Alcaraz") cout << "Alcaraz is " << it->second <<'\n';
        if(it->first == "Federer") cout << "Federer is " << it->second <<'\n';
        if(it->second == 8345) cout << "8345 is " << it->first <<'\n';
        if(it->second == 8767) cout << "8767 is " << it->first <<'\n';
    }
}
