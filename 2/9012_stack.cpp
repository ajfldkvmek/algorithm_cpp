/**
 *  백준 9012
 *  올바른 괄호 구하기
 */

#include <bits/stdc++.h>
using namespace std;
int T;
string vps;
stack<char> s;

int main()
{
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> vps;
        s = stack<char>();
        bool isVps = true;
        for (char c : vps)
        {
            if (c == '(')
                s.push(c);
            else
            {
                if (s.empty())
                {
                    isVps = false;
                    break;
                }
                else
                {
                    s.pop();
                }
            }
        }

        // v가 비어있고 true이면 YES
        if (isVps && s.empty())
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }

    return 0;
}