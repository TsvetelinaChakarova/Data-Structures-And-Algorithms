/*
 * Complete the 'deleteNode' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER position
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* llist, int position) {
    if (position == 0 && llist->next != nullptr) {
        return llist->next;
    }
    if (llist == nullptr) return nullptr;
    if (llist -> next == nullptr && position == 0) return nullptr;
    SinglyLinkedListNode* current = llist;
    int currentPosition = 0;
    SinglyLinkedListNode* prev;
    
    while (position != currentPosition && current->next != nullptr) {
        prev = current;
        current = current ->next;
        currentPosition++;
    }
    
    prev->next = current->next;
    delete current;
    
    return llist;
} 
