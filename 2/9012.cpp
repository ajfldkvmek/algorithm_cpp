/**
 *  백준 9012
 *  올바른 괄호 구하기
 */

#include <bits/stdc++.h>
using namespace std;
int T;
string s;
vector<char> v;

int main()
{
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> s;
        v.clear();
        bool isVps = true;
        for (char c : s)
        {
            if (c == '(')
                v.push_back(c);
            else
            {
                if (v.empty())
                {
                    isVps = false;
                    break;
                }
                else
                {
                    v.pop_back();
                }
            }
        }

        // v가 비어있고 true이면 YES
        if (isVps && v.empty())
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }

    return 0;
}