#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;


int main() {
    unordered_map<string, int> people;
    people["Ali"]=34;
    people["Hassan"]=24;
    people["Haider"]=56;
    people["Zain"]=12;
    
    string name;
    cout<<"Enter Name to Find: "<<endl;
    cin>>name;
    
    bool found=false;
    for(auto entry:people) {
        if(entry.first==name) {
            cout<<"Name: "<<entry.first<<" Age: "<<entry.second<<endl;
            found=true;
            break;
        }
    }
    
    if(!found) {
        cout<<"Not Found "<<endl;
    }
    
    
    return 0;
}