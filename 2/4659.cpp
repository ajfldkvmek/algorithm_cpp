#include <bits/stdc++.h>
using namespace std;

/**
 *
 *  모음(a,e,i,o,u) 하나를 반드시 포함하여야 한다.
 *  모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다.
 *  같은 글자가 연속적으로 두번 오면 안되나, ee 와 oo는 허용한다.
 */

bool isMo(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool pwd(string pw)
{
    bool hasMo = false;
    int jaCount = 0;
    int moCount = 0;

    for (int i = 0; i < pw.length(); i++)
    {
        if (isMo(pw[i]))
        {
            hasMo = true;
            moCount++;
            jaCount = 0;
        }
        else
        {
            moCount = 0;
            jaCount++;
        }

        if (jaCount == 3 || moCount == 3)
            return false;

        if (i > 0)
        {
            if (pw[i] == pw[i - 1])
            {
                if (!(pw[i] == 'e' || pw[i] == 'o'))
                    return false;
            }
        }
    }
    if (!hasMo)
        return false;
    return true;
}

int main()
{
    string s;
    while (cin >> s)
    {
        if (s == "end")
            break;

        if (pwd(s))
        {
            printf("<%s> is acceptable.\n", s.c_str());
        }
        else
        {
            printf("<%s> is not acceptable.\n", s.c_str());
        }
    }
}