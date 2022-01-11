/*
Exercise 11-4: String sorting
• Write a program that sorts strings
with quick sort by alphabetical order
based on the following instructions.

I. Compare the character
strings
• Write the function “preceding()” to search which
of two character strings comes before by
alphabetical order.
int preceding(char *first, char *second)
• A return value is by alphabetical order
– Case that the character string of the argument “first” is
before the character string of the argument “second” : 1
– Case that the character string of the argument “first” is
equal to the character string of the argument “second” :
0
– Case that the character string of the argument “first” is
after the character string of the argument “second” : -1

II. Input the character
string from the file
• Write the function “setup_nameList()” to
read the name of more than 2 persons
and less than 25 persons from the file and
set them to the array “nameList[]” of a
character string (in fact, the array of the
pointer to the character string )
int setup_nameList(char *namelist[], char
*filename)

III. Implement Quicksort
• Write the function “qsort_name()” to
sort the character string of the array
“namelist[]” by alphabetical order
with quick sort using the function
you made ever.
*/