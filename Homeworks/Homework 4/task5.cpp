#include <iostream>
#include <string>
#include <string>
#include <vector>
using namespace std;

const int NO_ELEMENTS = -1;

struct Node
{
    int color;
    int index;
    Node* prev;
    Node* next;

    Node(int newColor, int newIndex, Node* newNext, Node* newPrev) {
        color = newColor;
        index = newIndex;
        next = newNext;
        prev = newPrev;
    }
};

class doublyLinkedList
{
private:
    Node* front;
    Node* end;


public:
    int size;

    doublyLinkedList() {

        front = nullptr;
        end = nullptr;
        size = 0;
    }

    void insertAtTheEnd(int toInsertColor, int toInsertIndex) {
        size++;

        if (end == nullptr) {
            front = new Node(toInsertColor, toInsertIndex, nullptr, nullptr);
            end = front;
            return;
        }

        end->next = new Node(toInsertColor, toInsertIndex, nullptr, end);
        end = end->next;
    }

    void insertAfterElement(int insertAfter, int newIndex, int newColor) {

        Node* previousNode = front;
        if (previousNode == nullptr) {
            insertAtTheEnd(newColor, newIndex);
            return;
        }
        while (previousNode->index != insertAfter) {
            previousNode = previousNode->next;
        }

        Node* newNode = new Node(newColor, newIndex, previousNode->next, previousNode);


        previousNode->next = newNode;


        if (newNode->next != nullptr) {
            newNode->next->prev = newNode;
        }

        size++;
    }

    void removeElements(int& currentIndex, int& insertColor, bool& callAgain, int& removedElements) {

        int elementsFromLeft = NO_ELEMENTS, elementsFromRight = NO_ELEMENTS;
        Node* currentNode = front;
        Node* currentNodeCopy = front;

        while (currentNode->index != currentIndex) {
            currentNode = currentNode->next;
            currentNodeCopy = currentNodeCopy->next;
        }

        while (currentNode != nullptr && currentNode->color == insertColor) {
            elementsFromRight++;
            currentNode = currentNode->next;
        }

        while (currentNodeCopy != nullptr && currentNodeCopy->color == insertColor) {
            elementsFromLeft++;
            currentNodeCopy = currentNodeCopy->prev;
        }

        int elementsToRemove = elementsFromLeft + elementsFromRight + 1;
        removedElements = 0;

        if (elementsToRemove >= 3) {
            size -= elementsToRemove;
            removedElements = elementsToRemove;

            if (currentNodeCopy == nullptr && front->color == insertColor) {
                front = currentNode;
            }
            else {
                currentNodeCopy->next = currentNode;
            }
        }

        if (removedElements >= 3 && size > 0 && currentNodeCopy != nullptr && currentNode != nullptr && currentNodeCopy->color == currentNode->color) {
            callAgain = true;
            currentIndex = currentNodeCopy->index;
            insertColor = currentNodeCopy->color;
        }
        else {
            callAgain = false;
        }
    }

    void print() {
        if (front == nullptr && end == nullptr) {
            printf("%d", 0);
        }
        else {
            if (size == 0) {
                printf("%d ", -1);
            }
            else {
                Node* current;
                current = front;
                while (current != nullptr)
                {
                    printf("%d ", current->color);
                    current = current->next;
                }
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numberOfBalls; // N
    doublyLinkedList balls;
    int numberOfRequests; //Q
    int insertAfterIndex; // Pi
    int insertColor; // Ci
    vector<int> answers;

    cin >> numberOfBalls;
    for (int i = 0; i < numberOfBalls; i++) {
        int current;
        cin >> current;
        balls.insertAtTheEnd(current, i);
    }

    cin >> numberOfRequests;
    for (int i = 0; i < numberOfRequests; i++) {
        cin >> insertAfterIndex;
        cin >> insertColor;

        if (balls.size == 0) {
            answers.push_back(-1);
        }
        else {
            int currentIndex = i + numberOfBalls;
            balls.insertAfterElement(insertAfterIndex, i + numberOfBalls, insertColor);
            int removedElements = 0, removedElementsOnStep = 0;
            bool callAgain = true;
            
            while (callAgain == true) {
                balls.removeElements(currentIndex, insertColor, callAgain, removedElements);
                removedElementsOnStep += removedElements;
            }

            answers.push_back(removedElementsOnStep);
        }
    }

    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == -1) {
            printf("%s\n", "Game Over");
        }
        else {
            printf("%d\n", answers[i]);
        }
    }

    balls.print();

    return 0;
}
