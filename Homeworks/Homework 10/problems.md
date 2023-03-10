**Source: https://www.hackerrank.com/contests/sda-hw-10-2021/challenges**

**Task 1:**

Най-модерната операционна система xnuᴉ˥ има много диструбиции, като често дистрибуциите копират една от друга. Възможно е една дистрибуция да копира повече от 1 друга дистрибуция, както и много дистрибуции да копират една основна.

Определете дали йерархията е счупена. Йерархията ще е счупена, ако има дистрибуция, която директно или индиректно да копира себе си.

За улесниение дистрибуциите ще са именувани с цели числа.

*Input Format:*

Q На първия ред получавате едно число - брой заявки.

Следват Q на брой заявки. Всяка заявка е:

E - на първия ред едно число - брой ребра. На следващите E реда има:

Start End - две числа, начален и краен връх на ребро (End е дистрибуция, която копира Start)

*Output Format:*

На един ред изведете резултатите за всички заявки, разделени с празно място (спейс).

Резултат може да е 1 ако йерархията е счупена, или 0 ако е валидна.


**Task 2:**

В днешно време ходенето на кино крие своите опасности. На 8ми декември група студенти от СУ се събрали и запълнили един киносалон, който има правоъгълна форма с N реда и M стълба. Филмът, който ще гледат е с продължителност T. Проблемът е, че K на брой от студентите са заразени с Ковид. Най-лошото е, че вирусът се разпространява бързо и след всяка минута от филма, човек, който е болен заразява седналите до него(човекът от ляво на него, от дясно на него, пред него и зад него). Вашата задача е да намерите броят на останалите здрави студенти след краят на филма.

*Input Format:*

На първия ред са зададени две числа N(редове) и M(стълбове). На втория ред отново са дадени 2 числа T(продължителност на филма в минути) и K(Броят на допуснатие в киното болни студенти). Следват K на брой реда, всеки ред съдържа две числа i(ред) и j(колона) мястото, където стои студент, който е болен от ковид.

*Output Format:*

На единствен ред изведете броят на здравите студенти след краят на филма


**Task 3:**

Вие сте археолог с OCD (обсесивно компулсивно разтройство). При разкопки намирате древни текстове на непознат за човечеството досега език. Формата и подредбата на текста ви подказват, че това може да е речник. Вие допускате, че речниците както сега, така и в древността, са били подредени по азбучен ред.

Към момента не ви интересува какво точно е значението на всяка дума. Искате да разберете единствено какъв е бил редът на символите в азбуката на древния народ.

*Input Format:*

На първият ред на стандартния вход ще прочетете цяло число N.

От следващите N реда на стандартния вход ще прочетете символни низове S_i, подредени по азбучен ред, според азбуката на древния народ. Всички низове ще съдържат смао малки латински букви.

*Output Format:*

Използвайки данните, с които рапзолагате, на един ред, разделени с интервал отпечатайте символите от азбуката на древния народ, в правилната за тях лексикографска наредба.
