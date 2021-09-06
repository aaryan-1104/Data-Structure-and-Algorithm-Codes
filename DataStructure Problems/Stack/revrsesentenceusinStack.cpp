#include <iostream>
using namespace std;
#include <stack>

void reverseString(string s)
{
    stack<string> st;
    for (int i = 0; i < s.length(); i++)
    {
        string w = "";
        while (s[i] != ' '&&i<s.length())
        {
            w += s[i];
            i++;
        }
        st.push(w);
    }

    while (!st.empty())
    {
        cout << st.top()<<" ";
        st.pop();
    }
}

int main()
{
    string s = "this is the sentence we want to reverse.";

    reverseString(s);
}