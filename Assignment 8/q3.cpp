#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *left, *right;

    Node(int k) {
        key = k;
        left = right = NULL;
    }
};

class BST {
public:
    Node* root;

    BST() { root = NULL; }

    Node* insert(Node* node, int key) {
        if (node == NULL)
            return new Node(key);

        if (key == node->key)
            return node;            

        if (key < node->key)
            node->left = insert(node->left, key);
        else
            node->right = insert(node->right, key);

        return node;
    }

    void insert(int key) {
        root = insert(root, key);
    }

    Node* findMin(Node* node) {
        while (node->left != NULL)
            node = node->left;
        return node;
    }

   
    Node* deleteNode(Node* node, int key) {
        if (node == NULL)
            return NULL;

        if (key < node->key)
            node->left = deleteNode(node->left, key);

        else if (key > node->key)
            node->right = deleteNode(node->right, key);

        else {
      
            if (node->left == NULL && node->right == NULL) {
                delete node;
                return NULL;
            }
           
            else if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
           
            else {
                Node* temp = findMin(node->right);
                node->key = temp->key;
                node->right = deleteNode(node->right, temp->key);
            }
        }
        return node;
    }

    void remove(int key) {
        root = deleteNode(root, key);
    }
    int maxDepth(Node* node) {
        if (node == NULL)
            return 0;
        int left = maxDepth(node->left);
        int right = maxDepth(node->right);
        return 1 + (left > right ? left : right);
    }

    int maxDepth() {
        return maxDepth(root);
    }
    int minDepth(Node* node) {
        if (node == NULL)
            return 0;
        if (node->left == NULL)
            return 1 + minDepth(node->right);

        if (node->right == NULL)
            return 1 + minDepth(node->left);

        int left = minDepth(node->left);
        int right = minDepth(node->right);

        return 1 + (left < right ? left : right);
    }

    int minDepth() {
        return minDepth(root);
    }
    void inorder(Node* n*
