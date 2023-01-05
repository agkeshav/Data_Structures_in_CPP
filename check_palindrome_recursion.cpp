#include <iostream>
#include <string.h>
using namespace std;
bool checkPalindrome(string &str, int i, int j)
{
    if (i > j)
    {
        return true;
    }
    if (str[i] != str[j])
    {
        return false;
    }
    else
    {
        return checkPalindrome(str, i + 1, j - 1);
    }
}
int main()
{
    cout << "Enter the string" << endl;
    string str;
    cin >> str;
    int a = str.length() - 1;
    bool ans = checkPalindrome(str, 0, a);
    if (ans)
    {
        cout << "It is Palindrome" << endl;
    }
    else
    {
        cout << "It is not Palindrome" << endl;
    }

    return 0;
}