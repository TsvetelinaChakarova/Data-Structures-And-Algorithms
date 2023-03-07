#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    
    Node(int value) {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};
 Node* root;
class BST{
public: 
   
    
    Node* insert(Node* root, int value) {
        if (root == nullptr) {
            root = new Node(value);
        } 
        
        if (value < root->value) {
            root->left = insert(root->left, value);
        }
        if (value > root->value) {
            root->right = insert(root->right, value);
        }
        
        return root;
    }
    
    void print(Node* root) {
        if (root == nullptr) return;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            int s = q.size();
            while (s--) {
                Node* current = q.front();
                q.pop();
                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
                cout << current->value << " ";
            }
        }
    }
    
    Node* minDataNode(Node* root) {
        if (root == nullptr) return root;
        if (root->left == nullptr) return root;
        return minDataNode(root->left);
    }
    
    Node* remove(Node* root, int element) {
        
        if (root == nullptr) return root;
        
        if (element < root->value) {
            root->left = remove(root->left, element);
        }
        else if (element > root->value) {
            root->right = remove(root->right, element);
        }
        else if (root->left && root->right) {
            Node* temp = minDataNode(root->right);
            root->value = temp->value;
            root->right = remove(root->right, temp->value);
        }
        else if (root->left) {root = root->left;}
        else if (root->right) root = root->right;
        else root = nullptr;
        
        
        return root;
    }
};

int main() {
    int n;
    int current;
    int k;
    vector<int> numbers;
  
    BST bst;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> current;
        numbers.push_back(current);
        root = bst.insert(root, current);
    }
    
    sort(numbers.begin(), numbers.end());
    k = numbers[numbers.size() - k];
    
    root = bst.remove(root, k);
   
    bst.print(root);
    
    return 0;
}
