README file for calculator.c

#Calculator project

##Compiler commands
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 calculator.c -o calculator

0. **Features and build

1. The variables block
* "int choice;" is used because our menu options are whole numbers
* but with "a, b;" and "result;" i use double, because this allows the caluclator to process both intergers and decimals accuratley which was inmportant to me.

2. The loop structure
* I used a do-while loop because i want the caculator to display the menu at least once. when "0" is entered I have a exit loop printing a goodbye message.

3. Clear input loop
* If a user types a letter instead of a number, scanf fails and leaves the character inside the systems input buffer.
* I use "while (getchar() != '\n') continue;" to reset the input buffer, it basically reads and discards the text char by char until it hits new line.

4. The range guard
* by using "if choice < 0 and if choice > 4" the user will be asked to input a number from within the range required.
* I have some personal resevations about the menu reprinting and have investigated some options like implementing persistent mode.

5. The divisonal guard
* A stop in place for dividing by 0, preveting a crash, using a if block to check the second operand "b" is 0. 
* if so we print a safe error message.

6. Summary
* This is my very first functional C programme. While developing this application, my primary takeaway was the value of building incrementally. 
* Focusing on code stability first made identifying and squashing bugs a much more manageable task.
* I would like to add a menu and persistant code but utlimaletyu the calulator functions well my goal when starting was to create a calulator that would solve ints and floats.
* Hitting that goal made me very happy and learning how to use double in context as well as limiting the the decimals. 

