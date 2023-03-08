#include <iostream>
using namespace std;

int toLower(char ch)
{
    if (ch >= 'a' && ch <= 'z')
        return ch;
    else
        return ch - 'A' + 'a';
}

int toUpper(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
        return ch;
    else
        return ch - 'a' + 'A';
}

int len(char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

void reverse(char str[], char rev[], int length)
{
    for (int i = 0; i < length; i++)
    {
        rev[i] = str[length - i - 1];
    }
}

int isPalindrome(char str[], char rev[], int length)
{
    for (int i = 0; i < length; i++)
    {
        if (toLower(str[i]) != toLower(rev[i]))
            return false;
    }
    return true;
}

int main()
{
    char str[20];
    cin >> str;
    char rev[20];
    reverse(str, rev, len(str));
    cout << rev << endl;
    cout << isPalindrome(str, rev, len(str));
    return 0;
}