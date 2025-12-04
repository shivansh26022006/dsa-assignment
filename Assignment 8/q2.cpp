#include<iostream>

using namespace std;

struct Node{
  int data;
  Node* left;
  Node* right;
  Node(int val)
  {
    data = val;
    left = right = NULL;
  }
};

//Insert a node
Node* insert(Node*root , int key)
{
  if(root == NULL)
  return new Node(key);

  if(key < root->data)
  root->left= insert(root->left,key);
  else if(key > root->data)
  root->right =insert(root->right,key);

  return root;
}

//(a)SEARCH-RECURSIVE
bool searchRecursive(Node* root,int key)
{
  if(root == NULL)
  return false;

  if(root->data == key)
  return true;
  else if(key < root->data)
  return searchRecursive(root->left,key);
  else
  return searchRecursive(root->right,key);
}

//(a) SEARCH-NON-RECURSIVE
bool searchIterative(Node* root,int key)
{
  Node* curr=root;
  while(curr != NULL)
  {
    if(curr->data == key)
    return true;
    else if(key<curr->data)
    curr = curr->left;
    else
    curr= curr->right;
  }
  return false;
}

//(b) MAXIMUM-ELEMENT
Node* findMax(Node* root)
{
  if(root == NULL)
  return NULL;
  while(root->right != NULL)
  root = root->right;
  return root; 
}

//(c) MINIMUM-ELEMENT
Node* findMin(Node* root)
{
  if(root == NULL)
  return NULL;
  while(root->left != NULL)
  root = root->left;
  return root;
}

//(d) INORDER-SUCCESSOR
Node* inordersuccessor(Node* root,Node* node)
{
  if(node->right != NULL)
  return findMin(node->right);

  Node* succ = NULL;
  while(root != NULL)
  {
    if(node->data < root->data){
      succ = root;
      root=root->left;
    }
    else if(node->data > root->data)
    root=root->right;
    else
      break;
  }
  return succ;
}

//(e) INORDER-PREDECESSOR
Node* inorderpredecessor(Node* root,Node* node)
{
  if(node->left != NULL)
  return findMax(node->left);

  Node* pred = NULL;
  while(root != NULL)
  {
    if(node->data > root->data){
      pred = root;
      root=root->right;
    }
    else if(node->data < root->data)
    root=root->left;
    else
      break;
  }
  return pred;
}
//(f) INORDER TRAVERSAL
void inorder(Node* root)
{
  if(root == NULL)
  return;
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}

int main()
{
  Node* root=NULL;

  //Create BST
  root = insert(root,50);
  insert(root,30);
  insert(root,70);
  insert(root,20);
  insert(root,40);
  insert(root,60);
  insert(root,80);

  cout<<"Inorder Traversal: ";
  inorder(root);
  cout<<endl;

  cout<<"\n(a1)Search 40(Recursive): "<<(searchRecursive(root,40) ? "Found" : "Not Found")<<endl; //recursive search

  cout<<"\n(a2)Search 90(Iterative): "<<(searchIterative(root,90) ? "Found" : "Not Found")<<endl;//non-recursive search

  cout<<"\n(b)Maximum element: "<<findMax(root)->data<<endl;//Maximum element

  cout<<"\n(c)Minimum element: "<<findMin(root)->data<<endl;//Minimum element
  
  //(d) & (e) In-order successor / predecessor for node 40
  Node* next= root->left->right;
  Node* succ=inordersuccessor(root,next);
  Node* pred=inorderpredecessor(root,next);

if (succ) cout << "\nIn-order Successor of " << next->data << " = " << succ->data << endl;
else cout << "\nIn-order Successor of " << next->data << " = None" << endl;

if (pred) cout << "In-order Predecessor of " << next->data << " = " << pred->data << endl;
else cout << "In-order Predecessor of " << next->data << " = None" << endl;

    return 0;
}
