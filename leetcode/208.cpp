#include <bits/stdc++.h>

using namespace std;

struct Node {
    char val;
    map<char, Node*> nodeList;
    Node(char _val) : val(_val) {}
};

class Trie {
    Node* dummy;

   public:
    Trie() { dummy = new Node(' '); }

    void insert(string word) {
        Node* root = dummy;
        for (auto& i : word) {
            auto res = root->nodeList.find(i);
            if (res == root->nodeList.end()) {
                auto* nextNode = new Node(i);
                root->nodeList.insert(make_pair(i, nextNode));
                root = nextNode;
            } else {
                root = res->second;
            }
        }
        root->nodeList.insert(make_pair(' ', new Node(' ')));
    }

    bool search(string word) {
        Node* root = dummy;
        for (auto& i : word) {
            auto res = root->nodeList.find(i);
            if (res == root->nodeList.end()) {
                return false;
            } else {
                root = res->second;
            }
        }
        if (root->nodeList.find(' ') == root->nodeList.end()) {
            return false;
        }
        return true;
    }

    bool startsWith(string prefix) {
        Node* root = dummy;
        for (auto& i : prefix) {
            auto res = root->nodeList.find(i);
            if (res == root->nodeList.end()) {
                return false;
            } else {
                root = res->second;
            }
        }
        return true;
    }
};