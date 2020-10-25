# OS_Project_3
Operating Systems Project - 3 Parts: A, B and C. The three programs consist of multithreaded environments. In Part A, time functions were called to calculate the CPU and Wall Clock execution time. In Part B, a multithread environment accepts a user input and creates the Fibonacci Number sequence of such. Part C, is also a multithreaded environment in which a phrase is accepted in the command line and the words are separated into vowels and consonants. 

# READ_ME-PART_A
The program provided created a user interactve environment that allows the user to indicate the number of sample points and threads, then calculates the PI. I modified
the initial code by adding two timing calls using clock_gettime(CLOCK_PROCESS_CPUTIME_ID) which calculates the CPU process time and clock_gettime(CLOCK_MONOTONIC_RAW) calculates the wall clock time, as well as their corresponding printing calls. I decided to use the CLOCK_MONOTONIC_RAW to make sure the timing isn't affected by any jumps or delays between NTP

The program compiles and runs efficiently with no bugs, the maximum # of threads allowed is 513 - the graphs attached in the Word Document also end there.

Sources Used Included Below -
(Example codes provided by Dr. Kar were also used as reference.)
Clock Calls:
https://linux.die.net/man/3/clock_gettime
https://stackoverflow.com/questions/14270300/what-is-the-difference-between-clock-monotonic-clock-monotonic-raw
https://medium.com/@jalalmostafa/on-system-clocks-time-functions-and-the-new-system-monitoring-tool-precimon-fad920f38b2e
http://math.ecnu.edu.cn/~jypan/Teaching/ParaComp/Codes_Pacheco/code/pi/pth_pi.c
https://stackoverflow.com/questions/6788960/clock-gettime-returns-some-extrange-values

# READ_ME-PART_B
This short program creates a multithreaded environment in which the main thread prompts the user to input a positive integer and then uses the child (second) thread
to create the Fibonnaci number sequence of the input; the parent thread will then print the output after the child thread is done. The program is well commented
for easier understanding.

The program compiles and runs efficiently with no major bugs - however the program does not compute the correct Fibonacci sequence if the number is over 
100, to ensure that the user does not experience the wrong results, I added error checking that does not allow the user to input a number over 100.
In addition to that; the program will output the number of the correct amount of inputs but when compared to an online generator it seems as if the program may print
one or two values less at times. I wasn't able to figure out if it was an error with the array output or if the output is indeed correct.

Sources Used Included Below -
Fibonacci Sequence:
https://www.programiz.com/c-programming/examples/fibonacci-series
https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/
https://miniwebtool.com/list-of-fibonacci-numbers/?number=200

Fibonacci Handling With Arrays:
https://www.geeksforgeeks.org/fibonacci-number-array/
https://ergodic.ugr.es/cphys/LECCIONES/c/subsection3_4_6.html#:~:text=This%20defines%20an%20array%20called,last%20element%20is%20index%2023.

Memory Allocation:
https://stackoverflow.com/questions/20739989/memory-allocation-calloc-malloc-for-unsigned-int
https://www.tutorialspoint.com/c_standard_library/c_function_malloc.htm

Thread Creation and Functions:
https://www.cs.odu.edu/~cs471w/spring11/lectures/threads.htm
https://www.educative.io/edpresso/how-to-create-a-simple-thread-in-c
https://man7.org/linux/man-pages/man3/pthread_join.3.html
https://man7.org/linux/man-pages/man3/pthread_create.3.html
https://www.geeksforgeeks.org/thread-functions-in-c-c/
https://www.geeksforgeeks.org/multithreading-c-2/

C Syntax and Compiling:
https://en.wikipedia.org/wiki/C_data_types
https://gcc.gnu.org/onlinedocs/gcc-6.1.0/gcc.pdf

Errors:
https://stackoverflow.com/questions/58121224/fibonacci-sequence-printing-out-all-values-in-an-array-edit
https://stackoverflow.com/questions/24028493/declaring-function-which-will-be-used-in-pthread-create-confusing-syntax-erro
https://stackoverflow.com/questions/35040497/why-do-we-pass-function-arguments-as-void-in-pthread-create
https://stackoverflow.com/questions/39901731/segmentation-fault-core-dumped-error-when-creating-thread

# READ_ME-Part_C
This short program creates a multithreaded environment in which the main thread accepts a phrase as an argument in the command line and scans through to 
determine the first letter of every word and store it in their corresponding arrays. The program then uses two threads, Vows and Cons to compare their initial character 
and print them out correspondingly once for every word in the phrase.

The program compiles and runs efficiently with no major bugs, although it does not react well to symbols and may return a core dump if used.

Sources Used Included Below -
Command Arguments:
https://stackoverflow.com/questions/46321605/string-or-character-input-from-command-line-in-c
https://stackoverflow.com/questions/48333430/iterate-through-argv

Vowel/Consonant Functions:
https://beginnersbook.com/2019/02/c-program-to-count-vowels-and-consonants-in-a-string-using-pointer/
https://www.tutorialgateway.org/c-program-to-check-vowel-or-consonant/#:~:text=declared%20variable%20ch-,printf(%22Please%20Enter%20an%20alphabet%3A%20%5Cn%22)%3B,Vowel%20otherwise%2C%20it's%20a%20Consonant.
https://www.programiz.com/c-programming/examples/vowel-consonant
https://www.geeksforgeeks.org/program-find-character-vowel-consonant/
https://cboard.cprogramming.com/c-programming/121687-function-array-find-number-vowels-consonants.html

Thread Syntax:
https://users.cs.cf.ac.uk/Dave.Marshall/C/node30.html
https://man7.org/linux/man-pages/man3/pthread_attr_init.3.html
https://users.cs.cf.ac.uk/Dave.Marshall/C/node32.html
https://www.mkssoftware.com/docs/man3/pthread_create.3.asp

Errors:
https://stackoverflow.com/questions/41256512/errorexpected-expression-before-int-when-casting-float-or-double-into-integer
https://stackoverflow.com/questions/33726868/why-do-i-get-the-array-subscript-is-not-an-integer-error
https://stackoverflow.com/questions/36632624/pthread-breaking-a-thread-cycle-based-on-user-input
https://stackoverflow.com/questions/55601903/what-causes-a-segmentation-fault-core-dump-to-occur-in-c
https://www.geeksforgeeks.org/core-dump-segmentation-fault-c-cpp/
