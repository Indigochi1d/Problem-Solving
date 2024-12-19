#include <bits/stdc++.h>

using namespace std;
string input;
const char vowel[5] = {'a', 'e', 'i', 'o', 'u'};
const char consonants[21] = {
    'b', 'c', 'd', 'f', 'g',
    'h', 'j', 'k', 'l', 'm',
    'n', 'p', 'q', 'r', 's',
    't', 'v', 'w', 'x', 'y', 'z'};
bool checkVowel(char c)
{
    for (int i = 0; i < 5; i++)
    {
        if (c == vowel[i])
            return true;
    }
    return false;
}
bool checkConsonant(char c)
{
    for (int i = 0; i < 21; i++)
    {
        if (c == consonants[i])
        {
            return true;
        }
    }
    return false;
}

bool rule1(string s)
{
    for (int i = 0; i < 5; i++)
    {
        if (s.find(vowel[i]) != string::npos)
        {
            return true;
        }
    }
    return false;
}

bool rule2(string s)
{
    int flag_vowel = 0;
    int flag_consonant = 0;
    bool isVowel = false, isConsonant = false;
    for (int i = 0; i < s.size(); i++)
    {
        if (checkVowel(s[i]))
        {
            isVowel = true;
            isConsonant = false;
        }
        if (checkConsonant(s[i]))
        {
            isConsonant = true;
            isVowel = false;
        }
        if (isVowel)
        {
            flag_vowel++;
            flag_consonant = 0;
        }
        if (isConsonant)
        {
            flag_consonant++;
            flag_vowel = 0;
        }

        if (flag_consonant > 2 || flag_vowel > 2)
        {
            return false;
        }
    }
    return true;
}

bool rule3(string s)
{
    char tmp_c = s[0];

    for (int i = 1; i < s.size(); i++)
    {
        if (tmp_c == s[i])
        {
            if ((tmp_c == 'e' && s[i] == 'e') || tmp_c == 'o' && s[i] == 'o')
                continue;
            else
                return false;
        }
        tmp_c = s[i];
    }
    return true;
}

int main()
{

    while (true)
    {
        cin >> input;
        if (input == "end")
        {
            break;
        }
        if (rule1(input) && rule2(input) && rule3(input))
        {
            cout << "<" << input << ">" << " is acceptable.\n";
        }
        else
        {
            cout << "<" << input << ">" << " is not acceptable.\n";
        }
    }
    return 0;
}
