#include <stdio.h>
#include <string.h>

/*
    Given a character pointer x (that points to an array of chars), and a
    character pointer y, copies the character contents of y over to x. Pointer
    arithmetic is necessary here. Also, make sure x points to a null terminator
    at its end to terminate it properly. 

    Example call:

    char buffer[1024];

    string_copy(buffer, "Hello!");
    printf("%s", buffer); // Prints "Hello!"
*/
void string_copy(char *x, char *y)
{
    int i = 0;
    // loop thru y
    while (strcmp(&y[i], "\0") != 0)
    {
        x[i] = y[i];
        i++;
    }
    // while (*(y + i) != "\0") // gives a warning for direct comparison
    // {
    //     *(x + i) = *(y + i);
    //     i++;
    // }
    // copy the null terminator
    x[i] = y[i];
}

/*
    Searches the input string `str` for the first instance of the 
    character `c` (an unsigned char). This function returns a pointer
    that points to the first instance of the character `c` in the
    input string `str`.

    Do not use the `strchr` function from the standard library.
*/
char *find_char(char *str, char c)
{
    int i;
    // loop thru str
    int len = strlen(str);
    for (i = 0; i < len; i++)
    {
        // printf("%c\n", str[i]);
        if (str[i] == c)
        {
            return str + i;
        }
    }
    return 0;
    // while (strcmp(&str[i], &c) != 0)
    // {
    //     printf("%c\n", str[i]);
    //     if (strcmp(&str[i], &c) == 0)
    //     {
    //         return 0;
    //     }
    //     i++;
    // }
    // return str + i;
}

/*
    Searches the input string `haystack` for the first instance of
    the string `needle`. This function returns a pointer that points
    to the first instance of the string `needle` in the input
    string `haystack`. 

    Do not use the `strstr` function from the standard library.
*/
char *find_string(char *haystack, char *needle)
{
    int i, j, match;
    int hay_len = strlen(haystack);
    int nee_len = strlen(needle);
    // loop through haystack, check if current char is first char of needle
    for (i = 0; i < hay_len; i++)
    {
        // if we find first char of needle, see if needle exists by looping through needle and checking haystack
        if (haystack[i] == needle[0])
        {
            match = 1;
            for (j = 1; j < nee_len; j++)
            {
                if (haystack[i + j] != needle[j])
                {
                    match = 0;
                    j = nee_len; // break loop
                }
            }
            // if we found the complete needle, return current haystack position
            if (match)
            {
                return haystack + i;
            }
        }
    }
    return 0;
}

#ifndef TESTING
int main(void)
{
    char *found_char = find_char("hello", 'e');
    char *found_string = find_string("world", "or");

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    return 0;
}
#endif
