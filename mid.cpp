#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isKeyword(string word)
{
    string keywords[] = {"int", "float", "double", "char", "if", "else",
                         "while", "for", "return", "void"};

    for (int i = 0; i < 10; i++)
    {
        if (word == keywords[i])
            return true;
    }
    return false;
}

bool isOperator(string word)
{
    string operators[] = {"+", "-", "*", "/", "=", "==", "<", ">", "<<", ">>"};

    for (int i = 0; i < 10; i++)
    {
        if (word == operators[i])
            return true;
    }
    return false;
}

bool isPunctuation(string word)
{
    string Punctuation[] = {"(", ")", "{", "}", ";", ","};

    for (int i = 0; i < 6; i++)
    {
        if (word == Punctuation[i])
            return true;
    }
    return false;
}

bool isNumber(string word)
{
    for (int i = 0; i < word.length(); i++)
    {
        if (!isdigit(word[i]))
            return false;
    }
    return true;
}



int main()
{
    ifstream file("myfile.txt");

    if (!file)
    {
        cout << "File not found!" << endl;
        return 1;
    }

    string token;

    while (file >> token)
    {
         if (token == "\"")
        {
            string str = token;

            while (file >> token && token != "\"")
            {
                str += " " + token;
            }

            str += " \"";

            cout << str << " : String Constant" << endl;
        }
        if (isKeyword(token))
            cout << token << " : Keyword" << endl;

        else if (isOperator(token))
            cout << token << " : Operator" << endl;

        else if (isPunctuation(token))
            cout << token << " : Punctuation" << endl;

        else if (isNumber(token))
            cout << token << " : Number" << endl;

        else
            cout << token << " : Identifier" << endl;
    }

    file.close();

    return 0;
}
