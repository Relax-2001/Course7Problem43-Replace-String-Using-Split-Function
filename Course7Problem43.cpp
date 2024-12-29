#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

vector <string> SplitString(string UserString , string Delem)
{

    short Pos = 0;
    string Word = "";
    vector <string> vWords;

    while ((Pos = UserString.find(Delem)) != std::string::npos)
    {
        Word = UserString.substr(0, Pos);

        if (Word != " ")
        {
            vWords.push_back(Word);
        }

        UserString.erase(0 , Pos + Delem.length());
    }

    if (UserString != "")
    {
        vWords.push_back(UserString);
    }

    return vWords;
}

string JoinString(vector <string> vWords , string Delem)
{

    string JoinedString = "";

    for (string & Word : vWords)
    {
        JoinedString += Word + " ";
    }

    return JoinedString.substr(0, JoinedString.length() - Delem.length());
}

string LowerAllString(string UserString)
{

    for (short i = 0 ; i < UserString.length() ; i++)
    {

        UserString[i] = tolower(UserString[i]);

    }
    return UserString;
}

string ReplaceWordUsingSplitFunction(string UserString , string StringToReplace , string ReplaceTo , bool MachCase = true)
{

    vector <string> vWords = SplitString(UserString , " ");

    for (string & Word : vWords)
    {

        if (MachCase)
        {
            if (Word == StringToReplace)
            {
                Word = ReplaceTo;
            }
        }
        else
        {
            if ( LowerAllString(StringToReplace) == LowerAllString(Word))
            {
                Word = ReplaceTo;
            }
        }
    }

    return  JoinString(vWords, " ");
}


int main()
{
    string UserString = "Hi , I'm Mahmoud from USA , USA is a nice country";
    string StringToReplace = "Usa";
    string ReplaceTo = "Syria";

    cout << "String before replacement:\n";
    cout << UserString << "\n\n";

    cout << "String after replacement with mach case\n";
    cout << ReplaceWordUsingSplitFunction(UserString , StringToReplace , ReplaceTo) << "\n\n";

    cout << "String after replacement without mach case\n";
    cout << ReplaceWordUsingSplitFunction(UserString, StringToReplace, ReplaceTo , false) << "\n\n";




    return 0;
}
