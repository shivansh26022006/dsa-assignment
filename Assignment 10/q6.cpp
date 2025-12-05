#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};
bool hasDuplicate(Node* root) {
    if (!root) return false;
    unordered_set<int> seen;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* curr = q.front(); q.pop();
        if (seen.count(curr->data)) return true;
        seen.insert(curr->data);
        if (curr->left)  q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
    return false;
}
int main() {
    Node* root = new Node{5, nullptr, nullptr};
    root->left = new Node{3, nullptr, nullptr};
    root->right = new Node{5, nullptr, nullptr}; 
    cout << (hasDuplicate(root) ? "Duplicates Found" : "No Duplicates");
}
