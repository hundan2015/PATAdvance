#include <iostream>
#include <queue>
#include<algorithm>
using namespace std;
struct node
{
    node *left = nullptr, *right = nullptr;
    int data;
    int p_;
    node(int d, int p) : data(d), p_(p) {}
};
bool cmp(node *n1, node *n2)
{
    return n1->data < n2->data;
}
int countf;
vector<node *> nodeline;
node *maketree(int begin, int end)
{
    if(begin>end){
        return nullptr;
    }
    node *shit = nullptr;
    int pos;
    for (int i = begin; i <= end; ++i)
    {
        if(!shit){
            shit = nodeline[i];
            pos = i;
        } 
        if(nodeline[i]->p_<shit->p_){
            shit = nodeline[i];
            pos = i;
        }
    }
    shit->left = maketree(begin, pos - 1);
    shit->right = maketree(pos + 1, end);
    return shit;
}
void level(node* root){
    queue<node *> que;
    que.push(root);
    vector<int> line1, line2;
    while(!que.empty()){
        node *top = que.front();
        que.pop();
        line1.push_back(top->data);
        line2.push_back(top->p_);
        if(top->left){
            que.push(top->left);
        }
        if(top->right){
            que.push(top->right);
        }
    }
    for (int i = 0; i < countf;++i){
        cout << line1[i];
        if(i!=countf-1){
            cout << " ";
        }else{
            cout << endl;
        }
    }
    for (int i = 0; i < countf; ++i)
    {
        cout << line2[i];
        if (i != countf - 1)
        {
            cout << " ";
        }
    }
}
int main()
{
    cin >> countf;
    for (int i = 0; i < countf; i++)
    {
        int data1;
        int data2;
        cin >> data1 >> data2;
        nodeline.push_back(new node(data1, data2));
    }
    sort(nodeline.begin(), nodeline.end(), cmp);
    node *root = maketree(0, countf - 1);
    level(root);
}