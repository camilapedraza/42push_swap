_This project has been created as part of the 42 curriculum by mpedraza._

# DESCRIPTION
push_swap is a sorting algorithm project that focuses on learning about efficiency and algorithmic thinking.
The goal is to accurately sort a stack of integers with clear constraints: only a limited set of operations can be used and the goals is to use the fewest number of moves possible. The program takes a list of integers as argument and outputs the sequence of operations required to sort them in ascending order.

Although the project also involves parsing and validating arguments, the focus is on understanding time complexity while working with limited space complexity (only two stacks).

# INSTRUCTIONS
1. Clone the project and run `make` inside the root directory.
2. Run the program with `./push_swap`.
3. You must provide at least one integer as argument, i.e `./push_swap 42`

- The program will only output instructions if they are required to sort the integers provided (if you provide a sorted list, there will be no output).
- The program will only run if there is at least one argument, the numbers provided are integers, and there are no duplicates (it will display `Error` otherwise).
- The project originallt allows 11 possible moves, but this project only uses a subset of 8 of those moves. They are abbreviated as follows:
  - `pa` and `pb` (__push__ - move the top element of stack a to stack b, or the inverse)
  - `ra` and `rb` (__rotate__ - move the top element of the stack to the bottom of the same stack)
  - `rra` and `rrb` (__reverse rotate__ - move the bottom element of the stack to the top of the same stack)
  - `rr` (__rotate both__ stacks at the same time)
  - `rrr` (__reverse rotate__ both stacks at the same time)

# RESOURCES
I relied mainly on different versions of the so-called __"Turk Algorithm"__ to accomplish the task, but implemented my own version. You can read on some variations of Turk here:
- [Push_Swap Turk algorithm explained in 6 steps](https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0) by Yutong Deng
- [Push Swap — A journey to find most efficient sorting algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) by A. Yigit Ogun

Although I created test cases and manually ran tests on all my code, I relied on an automated tester in the final stages of the project. The tester I used can generate random seeds of integers of the requested size and run them against your code with a single command. This allows testing to be quicker, and it provides immediate checks on failed sorting or moves going over the desired limits. I highly recomend it:
- [push_swap_tester](https://github.com/SimonCROS/push_swap_tester?tab=readme-ov-file) by SimonCROS
