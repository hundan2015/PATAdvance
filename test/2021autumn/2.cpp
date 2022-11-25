#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct order
{
    int order_;
    int data;
    order(int o, int d) : order_(o), data(d) {}
};
bool cmp(order &o1, order &o2)
{
    return o1.data > o2.data;
}
int main()
{
    vector<order> hat;
    vector<order> weight;
    int count;
    cin >> count;
    int data;
    for (int i = 0; i < count; ++i)
    {
        cin >> data;
        hat.push_back(order(i, data));
    }
    for (int i = 0; i < count; ++i)
    {
        cin >> data;
        weight.push_back(order(i, data));
    }
    sort(hat.begin(), hat.end(), cmp);
    sort(weight.begin(), weight.end(), cmp);
    vector<int> shit(count);
    for (int i = 0; i < count; ++i)
    {
        shit[hat[i].order_] = weight[i].order_ + 1;
    }
    for (int i = count - 1; i >= 0;--i){
        cout << shit[i];
        if(i!=0){
            cout << " ";
        }
    }
}