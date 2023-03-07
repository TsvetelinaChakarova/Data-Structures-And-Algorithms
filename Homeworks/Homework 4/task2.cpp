// Complete the findMergeNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    while (head1) {
        SinglyLinkedListNode *temp = head1->next;
        head1->next = NULL;
        head1 = temp;
    }
    
    while(head2) {
        if(head2->next == NULL){
            return head2->data;
        }
        
        head2 = head2->next;
    }
    
    return -1;
}
