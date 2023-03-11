void SinglyLinkedList::group(int start, int end)
{
    if (start < 0 || end >= size  || start > end ) {
        cout << "fail_grouping";
    }
    else {
        if (start == end || size == 0 || size == 1) {
            return;
        }

        int position = 0;
        Node *current = head;
        Node *startingNode;

        while (position < start) {
            current = current->next;
            position++;
        }
        startingNode = current;
        
        int sum = 0;
        
        while (position < end) {
            sum += current->value;
            Node *temp = current;
            current = current->next;
            position++;

            if (position < end - 1 && position > start + 1) {
                delete temp;
            }
        }

        sum += current->value;
        startingNode->value = sum;
        startingNode->next = current->next;

        delete current;
    }
    
}
