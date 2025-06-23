#include <unordered_map>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;


int main() {
    unordered_map<string, int> sent;
    string sentence;
    getline(cin,sentence);
    istringstream iss(sentence);
    string word;
    while(iss>>word){
        sent[word]++;
    }
    for (auto x:sent) {
        cout<<x.first<<" "<<x.second<<endl;
    }
    return 0;
}