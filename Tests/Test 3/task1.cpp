/* 
Code that is given in the task

#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *leftNode;
        Node *rightNode;
        Node(int d) {
            data = d;
            leftNode = NULL;
            rightNode = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->leftNode, data);
                    root->leftNode = cur;
                } else {
                    cur = insert(root->rightNode, data);
                    root->rightNode = cur;
               }

               return root;
           }
        }
*/

	int sum = 0;
	void helpFunction(Node * current) {
	  if (current -> leftNode == NULL && current -> rightNode == NULL) {
	    if (current -> data % 2 == 1) {
	      sum += current -> data;
	    }
	  }
	  if (current -> leftNode != NULL) {
	    helpFunction(current -> leftNode);
	  }
	  if (current -> rightNode != NULL) {
	    helpFunction(current -> rightNode);
	  }
	}

	void leaves(Node * root) {
	  helpFunction(root);
	  cout << sum << endl;
	}

};

/*
Code that is given in the task
int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
	myTree.leaves(root);
    return 0;
}
*/
