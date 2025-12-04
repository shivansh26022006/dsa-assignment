#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int d) : data(d), left(NULL), right(NULL) {}
};

bool isBST(Node* node, long minv, long maxv) {
    if(!node) return true;
    if(node->data <= minv || node->data >= maxv) return false;
    return isBST(node->left, minv, node->data) &&
           isBST(node->right, node->data, maxv);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);

    cout << (isBST(root, LONG_MIN, LONG_MAX) ? "BST" : "Not BST") << endl;
}
