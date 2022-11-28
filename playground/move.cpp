#include <iostream>
#include <stack>
#include <utility>
#include <vector>
using namespace std;
int main() {
    vector<string> shit;
    string* str = new string("shit");
    shit.push_back(*str);
    cout << str << endl;
    cout << shit[0] << endl;
    cout<<"ss";
}