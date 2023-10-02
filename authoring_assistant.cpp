#include <iostream>
#include <string>
#include <cctype> // Include this header for the isalnum() function
using namespace std;

// Function prototypes
int GetNumOfNonWSCharacters(const string &text);
int GetNumOfWords(const string &text);
int FindText(const string &search, const string &text);
void ReplaceExclamation(string &text);
void ShortenSpace(string &text);
void PrintMenu();
void ExecuteMenu(char choice, string &text);

int main()
{

    string userText;

    // Prompt the user to enter a string
    cout << "Enter a sample text:" << endl;
    cout << endl;
    getline(cin, userText);

    // Output the entered string
    cout << "You entered: " << userText << endl;
    cout << endl;

    char choice;
    do
    {
        PrintMenu(); // Print the menu.
        cout << endl;
        cout << "Choose an option:";
        cin >> choice;
        cin.ignore();                  // Ignore the newline character after reading the choice.
        ExecuteMenu(choice, userText); // Execute the chosen Option.
        cout << endl;
    } while (choice != 'q');

    return 0;
}

// Function to count the number of non-whitespace characters in the Text.
int GetNumOfNonWSCharacters(const string &text)
{
    int count = 0;
    for (char c : text)
    {
        if (!isspace(c))
        {
            count++;
        }
    }
    return count;
}

// Function to count the number of words in the Text.
int GetNumOfWords(const string &text)
{
    int count = 0;
    bool insideWord = false;
    for (char c : text)
    {
        if (isalnum(c) || c == '\'')
        { // Consider apostrophes as part of words
            if (!insideWord)
            {
                count++;
                insideWord = true;
            }
        }
        else
        {
            insideWord = false;
        }
    }

    // Check if the last character was part of a word
    if (insideWord)
    {
        count++;
    }

    return count;
}

// Function to find the number of instances of a given word or phrase in the text
int FindText(const string &search, const string &text)
{
    int count = 0;
    size_t pos = text.find(search);
    while (pos != string::npos)
    {
        count++;
        pos = text.find(search, pos + 1);
    }
    return count;
}

// Function to replace all exclamation marks with periods in the text
void ReplaceExclamation(string &text)
{
    for (char &c : text)
    {
        if (c == '!')
        {
            c = '.';
        }
    }
}

// Function to shorten sequences of two or more spaces to a single space in the text
void ShortenSpace(string &text)
{
    size_t found = text.find("  ");
    while (found != string::npos)
    {
        text.replace(found, 2, " ");
        found = text.find("  ");
    }
}

// Function to print the command menu
void PrintMenu()
{
    cout << "MENU" << endl;
    cout << "c - Number of non-whitespace characters" << endl;
    cout << "w - Number of words" << endl;
    cout << "f - Find text" << endl;
    cout << "r - Replace all !'s" << endl;
    cout << "s - Shorten spaces" << endl;
    cout << "q - Quit" << endl;
}

// Function to execute the chosen menu option based on user input
void ExecuteMenu(char choice, string &text)
{
    switch (choice)
    {
    case 'c':
        cout << "Number of non-whitespace characters: " << GetNumOfNonWSCharacters(text) << endl;
        break;
    case 'w':
        cout << "Number of words: " << GetNumOfWords(text) << endl;
        break;
    case 'f':
    {
        string search;
        cout << "Enter a word or phrase to be found:" << endl;
        getline(cin, search);
        cout << "\"" << search << "\" instances: " << FindText(search, text) << endl;
    }
    break;
    case 'r':
        ReplaceExclamation(text);
        cout << "Edited text: " << text << endl;
        break;
    case 's':
        ShortenSpace(text);
        cout << "Edited text: " << text << endl;
        break;
    case 'q':
        break;
    default:
        cout << "Invalid option! Please choose a valid option from the menu." << endl;
    }
}
