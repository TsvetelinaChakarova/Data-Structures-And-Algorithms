**Source: https://www.hackerrank.com/contests/sda-hw-4/challenges**

**Task 1:**

Given the pointer to the head node of a linked list and an integer to insert at a certain position, create a new node with the given integer as its data attribute, insert this node at the desired position and return the head node.

A position of 0 indicates head, a position of 1 indicates one node away from the head and so on. The head pointer given may be null meaning that the initial list is empty.

Function Description: 

Complete the function insertNodeAtPosition in the editor below. It must return a reference to the head node of your finished list.

insertNodeAtPosition has the following parameters:
- head: a SinglyLinkedListNode pointer to the head of the list
- data: an integer value to insert as data in your new node
- position: an integer position to insert the new node, zero based indexing

Returns:
- SinglyLinkedListNode pointer: a reference to the head of the revised list

**Task 2:**

Given pointers to the head nodes of 2 linked lists that merge together at some point, find the node where the two lists merge. The merge point is where both lists point to the same node, i.e. they reference the same memory location. It is guaranteed that the two head nodes will be different, and neither will be NULL. If the lists share a common node, return that node's data value.

Note: After the merge point, both lists will share the same node pointers.

Function Description:

Complete the findMergeNode function in the editor below.

findMergeNode has the following parameters:

- SinglyLinkedListNode pointer head1: a reference to the head of the first list
- SinglyLinkedListNode pointer head2: a reference to the head of the second list

Returns:

- int: the  value of the node where the lists merge


**Task 3:**

Delete the node at a given position in a linked list and return a reference to the head node. The head is at position 0. The list may be empty after you delete the node. In that case, return a null value.
Function Description:

Complete the deleteNode function in the editor below.

deleteNode has the following parameters:
- SinglyLinkedListNode pointer llist: a reference to the head node in the list
- int position: the position of the node to remove

Returns:
- SinglyLinkedListNode pointer: a reference to the head of the modified list


**Task 4:**

?????????? ???????????? ?????????? ???? ?????????? ???????????? ???? ?????????? ???? ?????????????????????? ???? ?????????? ??++ ?? ???????? 210 ???? ???????????????????? ????????????????.

?????????? ???????????? ???? ?? ??????, ???????????????? ???? ???????????? ?????????????? ???? ?????????? ???? ?????????????????????? ?????????????????? ???? ?????????????????? ?? ???????? ?? ???????? ???????????? ???? ???????? Merge,Binary Search ?? Counting Sort.

?????????? ??++ ???????? ???????? ???????????????? ?????????????? ?????????????????? ???????????????????? ???? ???????????? ???? ???? ???????? ?? ???? ?????????? ?????????????????? ???? ??????????, ?????? ???? ?????????????????? ???? ???? ???????? ???????? ?? ???????????? ?????????? ???????????????? ???? ???? ?????????????? ?????????????????????????? ???????????? QuickSort ???????????????? ????.

*Input Format:*

???? ?????????????????????? ???????? ???????????????????? N ????????????:

?????????? ???????????? ?? ???? ????????:

add x - ( ???????????? x ?? ?????????? ???? ?????????? )) ???????????????? add 1

gun - ???????????????? ???? ?????????? ???? ?????????????? ???? ????????????????

milen - ???????????????? ???? ?????????? ??++ ????????, ?????????? ???? ?? ???? ???????????????????? ????????????????.

?? ???????????????? ???? ?????????????????????? ?? ?????????????? ???????????????? ???? ????????????????????.

?????? ?????????? add x, ?????? ???????????????????? ???????? ?? ?? ?????????????? ??????-?????????????? ???? ???????? ???????????? ???????????????????? ???????? ?????? ???????????? ??????.

*Constraints:*

??????????????????????:

???????? ???? ???????????????? N, ???????????? N <= 1 000 000

?????????? ???????????? ?? ???? ????????:

add x

gun

milen

???????? ???? ???????????????? gun ?????? ???????????? ????????????, ???????? ???? ???????????????? milen ?????? ???????????? ????????????. x ?? ???????????????? add ???? ?? <= N ?? ???????? ???? ???????????????? ?????????????????? x.

*Output Format:*

?????????? ???????????? ?????? ???????? ???? ?????????? ?? ???? ?????? ??????:

???????????????? ?????????????? ???? ???????????????? ???? ?????????? ???????? N-???? ????????????.


**Task 5:**

?????????? ???????????????????????????????? ???? ?????????????????????? ??????????????, ???????????????? ???????? ???? ?????????? ?? ???????????????????? ?? ???????????? ???? 0 ???? N-1. ???????????? ???? ?????????????????????? ?????????????? ?? ?????????????????? ???????? ?????? ???????????????? ???? ??????????????. ???????????????????????? ?????????? ???????????? ?????????? ???????? ?????????????? ?? ?????????? P , ?????????????????????? ???????????? ?????????????? ???? ?????????????? ????-???????????? ???? P ?? ???????? ?????????????? ?? ??????????. A???? P e ???????? ???? ???????????????????????????????? ???? ?????????????? ?? ?????????????? ???????? ?? ?????????????? ???????? 3, ???????????? ???????????????????????????????? ???? ???????????????????? ?????????????? ???????? ??????????????????, ?? ???????????? ?? ?????????????? ???????????????? ?????????????????????????????????? ???? ??????????????. ?????? ?????????????? ???? ???????????????????? ?? ???????? ???? ???????????????????????????????? ???? ?????????????? ?? ?????????????? ???????? ?? ?????????????? ???????? 3 , ?????????????????????? ???? ??????????????, ?? ???????????????? ???????????? ???????????? ???? ???????????????????? ???????? ??????????. ???????????? ???????????????? ???????????? ???? ?????????????? ?????????????? ?? ????????????????.

???? ?????? ???? ???????? ???? ???????????????? ???????????????? ?????????? ???? ???????????? ???????????? ???? N ?????????????????????? ??????????????, ???????????????? ???? Q ???? ???????? ????????????. ?????????? ???????????? ???? ???????????? ???? ?????? ???????? ?????????? Pi ?? Ci - ???????????? ???? ??????????????, ?????? ?????????? ???????????? ???? ???????????????? ?? ?????????? ???? ??????????????, ?????????? ??????????????????????. ???????????? ???? ?????????????????????????? ?????????? ?? ??????-??????????????, ???????????????????????? ???? ?????????? ???? ??????????, ???????????????????? ??????????. ?????????????? ?????? ?????????? ?? ?????????????? ???????????????? ???????????? ???????????????????? (???? ?? ??????????????????). ???? ?????? ???? ???????? ???? ???????????????? ???????? ???? ?????????????????????? ?????????????? ???????? ?????????? ??????????????. ?????? ???????? ?????????????? ?????????????? ???? ?????????????? ?????????????? ??????????????, ???????????? ?????????????????? ?? ???? ?????????? ???????????????? ???????????? ???????????? ???? ???????????????????? ?? "Game Over".

???????? ?????????????????????? ???? ???????????????? ???????????????? ???????????????????? ???????????? ???? ?????????????? ?????? -1 ?????? ???????????? ?????????????? ???? ??????????????????.

*Input Format:*

?????????????? ?????? ???? ?????????????????????? ???????? ?????????????? ???????? ???????? ?????????? N - ???????? ??????????????.

?????????????? ?????? ?????????????? N ???? ???????? ???????? ?????????? - ?????????????????? ???? ??????????????????.

?????????????? ?????? ?????????????? ???????? ???????? ?????????? Q - ???????? ????????????.

?????????????? N ???? ???????? ???????? ?????????????? ???? ???? ???? ?????? ???????? ?????????? Pi ?? Ci - ???????????? ???? ??????????????, ?????? ?????????? ???????????? ???? ???????????????? ?? ?????????? ???? ??????????????, ?????????? ??????????????????????.

*Output Format:*

???????????????? Q+1 ????????.

?????????????? Q ???????????? ???? ???????????????? ???? ???????? ???????? ?????????? - ???????????????? ???? ?????????????????? ????????????, ?????? ???????????? ?? ???????????????????? (???????????????? ???? ?????????????? ?? ????????????) ???????????????? "Game Over".

???? ?????????????????? ?????? ???????????????? ???????????????? ?????????????????? ???? ???????????????????????????????????? ???? ??????????????, ?????? ?? ?????? ???? ???? ???????????????? ?????????????? ???????????????? "-1".


