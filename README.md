# Authoring Assistant

This C++ program allows users to input a string of text and perform various operations on it, including counting characters and words, finding text, replacing exclamation marks, and shortening spaces. Below are the step-by-step instructions and example usage for each feature.

## Instructions

1. Input a Sample Text
   The program will prompt you to enter a sample text. It will then display the entered text.

```
Enter a sample text:
We'll continue our quest in space.  There will be more shuttle flights and more shuttle crews and,  yes,  more volunteers, more civilians,  more teachers in space.  Nothing ends here;  our hopes and our journeys continue!

You entered: We'll continue our quest in space.  There will be more shuttle flights and more shuttle crews and,  yes,  more volunteers, more civilians,  more teachers in space.  Nothing ends here;  our hopes and our journeys continue!
```

2. Print the Command Menu
   Use the PrintMenu() function to print the command menu, which provides various options for analyzing and editing the string.

```
MENU
c - Number of non-whitespace characters
w - Number of words
f - Find text
r - Replace all !'s
s - Shorten spaces
q - Quit
```

3. Execute Menu Options
   The ExecuteMenu() function takes two parameters: a character representing the user's choice and the user-provided sample text. It performs the chosen operation by calling the appropriate functions described below.

4. Main Loop
   In the main() function, the program repeatedly displays the menu, prompts for the user's choice of menu options for analyzing/editing the string, and executes the chosen option. The loop continues until the user enters 'q' to quit.

## Features

5. Number of Non-Whitespace Characters
   The GetNumOfNonWSCharacters() function takes a constant string as a parameter and returns the number of characters in the string, excluding all whitespace. The program calls this function in the ExecuteMenu() function and then outputs the returned value.

6. Number of Words
   The GetNumOfWords() function takes a constant string as a parameter and returns the number of words in the string. Words are separated by spaces. The program calls this function in the ExecuteMenu() function and then outputs the returned value.

7. Find Text
   The FindText() function takes two strings as parameters: the text to be found and the user-provided sample text. It returns the number of instances the word or phrase is found in the string. The program prompts the user for a word or phrase to be found, calls FindText(), and outputs the returned value.

8. Replace Exclamation Marks
   The ReplaceExclamation() function takes a string parameter and updates the string by replacing each '!' character with a '.' character. It does not output the string. The program calls this function in the ExecuteMenu() function and then outputs the edited string.

9. Shorten Spaces
   The ShortenSpace() function takes a string parameter and updates the string by replacing all sequences of 2 or more spaces with a single space. It does not output the string. The program calls this function in the ExecuteMenu() function and then outputs the edited string.

## How to Use

1. Compile the program using a C++ compiler (e.g., g++).

```
g++ authoring_assistant.cpp -o authoring_assistant
```

2. Run the program.

```
./authoring_assistant
```

3. Follow the on-screen prompts to input a sample text and choose menu options to analyze/edit the text.

# Example

```
Enter a sample text:
We'll continue our quest in space.  There will be more shuttle flights and more shuttle crews and,  yes,  more volunteers, more civilians,  more teachers in space.  Nothing ends here;  our hopes and our journeys continue!

You entered: We'll continue our quest in space.  There will be more shuttle flights and more shuttle crews and,  yes,  more volunteers, more civilians,  more teachers in space.  Nothing ends here;  our hopes and our journeys continue!

MENU
c - Number of non-whitespace characters
w - Number of words
f - Find text
r - Replace all !'s
s - Shorten spaces
q - Quit

Choose an option:
c
Number of non-whitespace characters: 181

Choose an option:
w
Number of words: 35

Choose an option:
f
Enter a word or phrase to be found:
more
"more" instances: 5

Choose an option:
r
Edited text: We'll continue our quest in space.  There will be more shuttle flights and more shuttle crews and,  yes,  more volunteers, more civilians,  more teachers in space.  Nothing ends here;  our hopes and our journeys continue.

Choose an option:
s
Edited text: We'll continue our quest in space. There will be more shuttle flights and more shuttle crews and, yes, more volunteers, more civilians, more teachers in space. Nothing ends here; our hopes and our journeys continue!

Choose an option:
q

```
