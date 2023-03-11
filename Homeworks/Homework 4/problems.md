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

Митьо Пищова обича да прави пищове по време на контролните на Милен Ч++ в зала 210 на Химическия Факултет.

Обаче Пищова не е сам, колегите му стоящи отдясно по време на контролното постоянно го снабдяват с нови и нови пищови на тема Merge,Binary Search и Counting Sort.

Милен Ч++ като един внимаващ квестор забелязва листчетата но вместо да ги крие и да прави забележка на Митьо, той ги разбърква за да може дори и когато Митьо преписва да се потруди пренареждайки отново QuickSort пищовите си.

*Input Format:*

На стандартния вход получавате N заявки:

Всяка заявка е от вида:

add x - ( където x е номер на пищов )) например add 1

gun - означава че Митьо ще започне да преписва

milen - означава че Милен Ч++ идва, вижда го и му пренарежда пищовите.

В началото не разполагате с никакви средства за преписване.

При заяка add x, вие получавате тема и я слагате най-отдясно на вече текущо наредените теми под вашият чин.

*Constraints:*

Ограничения:

Брой на заявките N, където N <= 1 000 000

Всяка заявка е от вида:

add x

gun

milen

НЯМА ДА ПОЛУЧИТЕ gun при ПРАЗНА РЕДИЦА, НЯМА ДА ПОЛУЧИТЕ milen при ПРАЗНА РЕДИЦА. x в заявката add ще е <= N и няма да получите повтарящи x.

*Output Format:*

Броят пищови под чина на Митьо и на нов ред:

Крайната наредба на пищовите на Митьо след N-те заявки.


**Task 5:**

Имате последователност от разноцветни топчета, долепени едно до друго и номерирани с чилата от 0 до N-1. Можете да изстрелвате топчета с определен цвят към редицата от топчета. Изстреляното топче попада точно след топчето с номер P , измествайки всички топчета на позиции по-големи от P с една позиция в дясно. Aко P e част от последователност от топчета с еднакъв цвят с дължина поне 3, цялата последователност от едноцветни топчета бива унищожена, а лявата и дясната получени последователности се залепят. Ако мястото на залепянето е част от последователност от топчета с еднакъв цвят с дължина поне 3 , процедурата се повтаря, в противен случай можете да изстреляте ново топче. Играта прикючва когато не останат топчета в редицата.

От вас се иска да напишете програма която по дадена редица от N разноцветни топчета, отговаря на Q на брой заявки. Всяка заявка се състои от две цели числа Pi и Ci - номера на топчето, към което трябва да стреляте и цвета на топчето, което изстрелвате. Номера на изстрелятното топче е най-малкото, неизползвано за номер на топче, естествено число. Топчето към което е насочен изстрела винаги съществува (не е унищожено). От вас се иска да намерите броя на унищожените топчета след всеки изстрел. Ако след поредия изстрел не останат никакви топчета, играта приключва и на всяка следваща заявка трябва да отговорите с "Game Over".

След приключване на заявките изведете получената редица от топчета или -1 ако всички топчета са унищожени.

*Input Format:*

Първият ред на стандартния вход съдържа едно цяло числа N - броя топчета.

Вторият ред съдържа N на брой цели числа - цветовете на топчетата.

Третият ред съдържа едно цяло числа Q - броя заявки.

Следват N на брой реда сътоящи се от по две цели числа Pi и Ci - номера на топчето, към което трябва да стреляте и цвета на топчето, което изстрелвате.

*Output Format:*

Изведете Q+1 реда.

Първите Q трябва да съдържат по едно цяло число - отговора на поредната заявка, ако играта е приключила (редицата от топчета е празна) изведете "Game Over".

На последния ред изведете крайното състояние на последователността от топчета, ако в нея не са останали топчета изведете "-1".


