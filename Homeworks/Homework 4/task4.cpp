#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;
};

class doublyLinkedList
{
private:
    Node* front;
    Node* end;
    Node* middle;
    int size;

public:
    doublyLinkedList()
    {
        front = NULL;
        end = NULL;
        middle = NULL;
        size = 0;
    }

    void insertAtTheEnd(int toInsert)
    {

        Node* temp;
        temp = new Node();
        temp->data = toInsert;
        temp->prev = end;
        temp->next = NULL;

        if (end == NULL)
            front = temp;
        else
            end->next = temp;
        end = temp;

        size++;

        if (size == 1) {
            middle = end;
            middle->prev = nullptr;
        }
        else {
            if (size % 2 == 0) {
                middle = middle->next;
            }
        }



    }

    void deleteLastElement() {
        if (end->prev == NULL && end->next == NULL) {
            front = NULL;
            end = NULL;
        }
        else {
            end = end->prev;
            end->next = nullptr;
        }

        if (size == 0) {
            middle = NULL;
        }
        else {
            if (size % 2 == 0) {
                middle = middle->prev;
            }
        }

        size--;


    }

    void  moveElements()
    {

        if (middle->prev != NULL) {
            Node* tempMiddle = middle;
            Node* temp = tempMiddle->prev;
            Node* tempEnd = end;
            Node* tempFront = front;

            if (size % 2 == 0) {
                middle = tempFront;
                middle->next = tempFront->next;
                middle->prev = tempEnd;
            }
            else {
                middle = tempEnd;
                middle->next = tempFront;
                middle->prev = tempEnd->prev;
            }
            
            temp->next = nullptr;

            tempEnd->next = tempFront;
            
            tempFront->prev = end;

            front = tempMiddle;
            front->prev = nullptr;

            end = temp;

            
        }

    }

    void print()
    {
       
        if (front == NULL && end == NULL) {
            printf("%d", 0);
        }
        else {
            printf("%d\n", size);
            Node* current;
            current = front;
            while (current != NULL)
            {
                printf("%d ", current->data);
                current = current->next;
            }
        }
    }

};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    doublyLinkedList requests;
    string current;
    int numberOfRequests;

    cin >> numberOfRequests;
    cin.ignore();

    for (int i = 0; i < numberOfRequests; i++) {
        getline(cin, current);
        if (current.substr(0, 3) == "add") {
            requests.insertAtTheEnd(stoi(current.substr(4, current.length() - 4)));
        }
        else {
            if (current.substr(0, 3) == "gun") {
                requests.deleteLastElement();
            }
            else
                requests.moveElements();
        }
    }


    requests.print();

    return 0;
}
