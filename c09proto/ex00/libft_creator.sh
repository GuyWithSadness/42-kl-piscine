rm -f libft.a
# This makes the .o file required
gcc -c *.c
# This creates the freaking libft.a
# r = replace, add new files whatever you wanna call it
# c = silence the success message
# s = does.... something
# remember to use ar -p libft.a to see the content
ar -rcs libft.a *.o
rm -rf *.o
