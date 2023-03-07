#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
};

Node* newNode(int newValue) {
    Node* newNode = new Node;
    newNode->value = newValue;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* insertElements(vector<int> elements) {
    if (elements.size() == 0) {
        return nullptr;
    }

    queue<Node*> nodes;
    queue<int> indexes;
    for (int i = 1; i < elements.size(); i++) {
        indexes.push(elements[i]);
    }

    Node* current = newNode(elements[0]);
    nodes.push(current);

    while (!indexes.empty()) {
        int leftSide;
        if (indexes.empty()) {
            leftSide = NULL;
        }
        else {
            leftSide = indexes.front();
            indexes.pop();
        }

        int rightSide;
        if (indexes.empty()) {
            rightSide = NULL;
        }
        else {
            rightSide = indexes.front();
            indexes.pop();
        }
       
        Node* current = nodes.front();
        nodes.pop();

        if (leftSide != NULL) {
            Node* left =  newNode(leftSide);
            current->left = left;
            nodes.push(left);
        }

        if (rightSide != NULL) {
            Node* right = newNode(rightSide);
            current->right = right;
            nodes.push(right);
        }
    }

    return current;
}

void print(Node* root) {
   
    queue<pair<Node*, int> > nodeWithDistance; // <node, distanceToRoot>
    nodeWithDistance.push(make_pair(root, 0));

    int currentDistance = 0;
    int currentLeft = 0;
    int currentRight = 0;

    stack<int> leftElementsToPrint;
    queue<int> rightElementsToPrint;

    Node* current;

    while (nodeWithDistance.size() != 0) {
        current = nodeWithDistance.front().first;
        currentDistance = nodeWithDistance.front().second;

        if (currentDistance < currentLeft) {
            leftElementsToPrint.push(current->value);
            currentLeft = currentDistance;
        }
        else {
            if (currentDistance > currentRight) {
                rightElementsToPrint.push(current->value);
                currentRight = currentDistance;
            }
        }

        if (current->left) {
            nodeWithDistance.push(make_pair(current->left, currentDistance - 1));
        }
        if (current->right) {
            nodeWithDistance.push(make_pair(current->right, currentDistance + 1));
        }

        nodeWithDistance.pop();
    }
 
    while (leftElementsToPrint.size() != 0) {
        printf("%d ", leftElementsToPrint.top());
        leftElementsToPrint.pop();
    }

    printf("%d ", root->value);

    while (rightElementsToPrint.size() != 0) {
        printf("%d ", rightElementsToPrint.front());
        rightElementsToPrint.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, currentLeft, currentRight;
    vector<int> elements;
    elements.push_back(0);
    cin >> N; 
    for (int i = 0; i < N; i++) {
        cin >> currentLeft;
        cin >> currentRight;

       if (currentLeft == -1) {
           elements.push_back(NULL);
        }
        else {
            elements.push_back(currentLeft);
        }

        if (currentRight == -1) {
            elements.push_back(NULL);
        }
        else {
            elements.push_back(currentRight);
        }
    }

    Node* root = newNode(0);
    root = insertElements(elements);
    print(root);

    return 0;
}
