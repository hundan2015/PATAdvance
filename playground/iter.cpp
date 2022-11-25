#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> shit = {1, 2, 3, 4};
    cout << distance(shit.begin(),(shit.begin() + 3));
}