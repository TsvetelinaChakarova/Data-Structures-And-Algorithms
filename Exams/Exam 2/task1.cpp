void SinglyLinkedList::removeAll(int X)
{
    Node* current = head;
    int position = 0;
    while (current != nullptr) {
        
        if (current->value == X) {
            current = current -> next; 
            remove(position);
        }
        else {
            current = current->next;
            position++;
        }
       
    }

}
