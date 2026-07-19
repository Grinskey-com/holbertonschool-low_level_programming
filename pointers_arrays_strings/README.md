README file for pointers_arrays_strings


*/notes for each task are added here.

task 8: void print_array(int *a, int n) is a program returning no value that prints elements directly to the screen.
It takes a pointer a to the start of the array and uses n as the hard ceiling to know how many elements to process.
Inside, it uses an integer i to keep track of a for loop, ensuring the system stops exactly when it hits n.
The loop uses pointer dereferencing to look inside each memory block and print the value,
while a conditional statement checks the loop tracker to ensure commas and spaces are only printed between numbers,
leaving the final element clean. The pointer a is stepped forward after each print to advance to the next memory address,
and the program concludes by dropping down to a clean new line.

**Task 9: *char *_strcpy(char *dest, char *src) is a program that duplicates a string by reading elements from a source address (src) and writing them directly into a destination buffer (dest). Because the destination pointer shifts forward during the process, the program first records the initial location by assigning start = dest to preserve the base address. A while loop then streams characters byte-by-byte from the source to the destination until it hits the null terminator ('\0'). Once the loop ends, the program manually appends a final null terminator to the end of the destination string to seal it safely in memory, and finishes by returning the original starting address stored on the anchor pointer. 

 

**Task 10: int _atoi(char *s) is a program that converts a string containing numbers into an actual integer value. It ignores any non-numeric garbage text at the start, using a multiplying tracking switch to calculate whether an unlimited chain of positive or negative signs leaves the final number positive or negative. Once it hits the first digit, an alarm flag is turned on so that the program knows to stop immediately if it hits any non-digit character later. The mathematical engine builds the number by shifting the existing digits one column to the left before applying the new digit, dynamically adding or subtracting the values based on the sign tracker to safely prevent the computer's memory from overflowing and crashing when handling extreme numbers.





**0 strcat: *char *_strcat(char *dest, char *src) is a program that concatenates two strings by appending the contents of a source string (src) directly to the end of a destination buffer (dest). The program first records the original entry point of the destination using an anchor pointer start = dest so it can be returned at the finish. It then runs an initial while loop to advance the dest pointer forward until it lands directly on its original terminating null byte ('\0'). Once positioned at the tail, a second while loop streams characters byte-by-byte from src into dest, overwriting the old terminator and advancing both pointers simultaneously. After the source string runs out, the program manually appends a fresh null byte to seal the newly combined string safely in memory, returning the original starting address.

**1 strncat: *char *_strncat(char *dest, char *src, int n) is a program that appends text from a source string (src) to a destination buffer (dest), enforcing a hard ceiling of n bytes copied. The program first anchors the base address by assigning start = dest so the original position isn't lost. It runs an initial loop to march the dest pointer to the end of its current string. Once positioned at the trailing null byte, a for loop tracks our position using a counter i alongside a pointer stream. This ensures the copying engine stops immediately if it encounters either the source's null terminator or if it hits the maximum allocation limit n. Finally, it drops a fresh null byte to safely lock down the new string end and returns the saved entry address.
Key difference between 0 and 1 is that strn is capped by n where str will run on until it reaches nullbyte.

**3 strncpy: *char *_strncpy(char *dest, char *src, int n) is a program that duplicates a string by copying characters from a source address (src) directly into a destination buffer (dest) using a fixed ceiling of n bytes. The program initializes by capturing the base address with an anchor variable start = dest. It then runs an initial loop tracking the character index i, streaming data byte-by-byte from the source until it either encounters a null terminator or hits the maximum count n. If the source text runs out before reaching the n threshold, a second loop takes over, filling every remaining slot up to n with null bytes ('\0') to explicitly pad out the destination buffer memory before returning the anchored starting address.

**4 iam kind of paranoid: *

**5 always look up: *

**6 expect the best: *

**mozart: *

