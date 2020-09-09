# get_next_line_42

Get_next_line function reads a new line from a file descriptor at every new call. It can be particularly useful to parse a file and extract information line by line.

---

**Read buffer size**

The size of the buffer used is not predefined and can take any value >0 and < 100 000 000. It has to be defined during the compilation.

**Return value**

While there is still at least one line to display, 1 is returned. When it reaches the end of the file (EOF) and there is no line to display anymore, the function returns 0. If there is an issue it returns -1.

--- 

**How to test it?**

run the following command to compile it:

`gcc -D BUFFER_SIZE=10 get_next_line.c get_next_line_utils.c main_test.c`

then execute the program with one argument which is the path to file to be displayed:

`./a.out text_files/la_marseillaise.txt`
 
 Text templates are stored in the text_files folder to help you run various tests easily.
