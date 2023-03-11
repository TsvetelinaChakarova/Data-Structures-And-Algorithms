int SinglyLinkedList::count(int X)
{
    int count = 0; 
	Node* traverse = head;
    for (int i = 0; i < size; i++) {
        if (traverse->value == X) {
            count ++;
        }
    traverse = traverse->next;
    }
    
    return count;
}
