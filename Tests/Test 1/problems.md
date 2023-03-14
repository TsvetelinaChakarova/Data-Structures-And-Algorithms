**Source: https://www.hackerrank.com/contests/sda-2021-2021-test-1/challenges**

**Task 1:**

За тази задача не се позволява използването на вградени функции и структури от данни за сортиране!

В Youtube решили да намерят колко видове различни видеа имат в платформата, като за целта използвали алгоритъм, който асоциира със всяко видео число, а в последствие всички тези числа поставили в масив и почнали да питат кандидати за интервю как биха изкарали в сортирана последователност всички различни числа. Решете задачата и вие :)

*Input Format:*

n - големина на масив за сортиране

x1 x2 …. xn - елементите на масива

*Constraints:*

1 < n < 700 000

0 < xi < 70 000

*Output Format:*

Сортирани числа без повторение в нарастващ ред разделени със интервал


**Task 2:**

В турнир по икономика в Китай се приложили иновативни правила, които обаче доста затруднили сидиите в изграждане на класацията на отборите.

Правилата били следните - позволило се на всички участници да си направят отбори с различни на брой участници, като всеки човек от отбора носи толкова точки за отбора, колкото участници има в него, а за смятане на краен резултат тези точките се разделяли на броя на участниците в противниковият отбор.

Поради сложната ситуация с точкуването, не всички отбори се съгласили да участват в крайното класиране, но дори след отказването на част от отборите да се определи кой отбор на кое място е в класирането се оказало достатъчно трудна задача за контролна работа по сда.

Помогнете за подредба на отборите в класиране, като за идентификация на отборите използваме на кой ред в списъка за сортиране подаван като вход са включени.

*Input Format:*

N - броя на отборите, които следва да се подредят. Xi Yi - N реда с двойки числа, които показват броя на участниците в отбор на ред i и брой на участниците в противниковият отбор.

*Constraints:*

3 ≤ N ≤ 100000

20 ≤ Xi ≤ 2000

1 ≤ Yi ≤ 2000

*Output Format:*

изведете индексите на печелившите отбори в намаляващ ред по точки. Ако два отбора имат еднакви точки, то изведете индекса на отбора с повече състезатели. Индексите трябва да са разделени с точно един интервал и индекса на първата двойка е 1, а на последната - N.