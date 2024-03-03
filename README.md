# Impledge Technologies

### Steps to execute the code
    
    1. You need to have an IDE on your device that is fully compatible with C++.
    2. While executing the program, you have to enter the full path of the file containing input.
    3. You also have to enter the full path of the file that will contain the output of the problem.
    4. The output file will be saved at the mentioned path.

### Overview and Approach of my program

    I took the full path of the input file as input from the user. I then attempted to open the file. If the file was successfully opened, I read the file line by line and stored the words in a vector.

    Additionally, I used an unordered set that contains all the words present in the input file. This set helps me efficiently find whether a particular substring of a string is present in the original words.

    I used Dynamic Programming to solve the problem. I traversed the words one by one and checked whether the following word satisfies the condition of being a compounded word. If yes, then I checked whether it could be a candidate for the longest compounded word or the second-longest compounded word, and updated these words accordingly.

    Subsequently, I took the full path of the output file as input from the user and wrote the output to it.

    I also used a system clock to measure the execution time of the solution.
