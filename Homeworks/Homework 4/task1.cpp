/*
 * Complete the 'insertNodeAtPosition' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER data
 *  3. INTEGER position
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

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    if (llist == nullptr) return nullptr;
    SinglyLinkedListNode* current = llist;
    int currentPosition = 0;
    while (currentPosition + 1 != position) {
        currentPosition++;
        current = current->next;
    }
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
    newNode->next = current->next;
    current->next = newNode;
    
    return llist;   
}
