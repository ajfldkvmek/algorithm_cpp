/**
 *  종료조건 : . 입력
 *  괄호는 ()와 []로 이루어짐
 *  각 문장은 . 으로 구분
 */

#include <bits/stdc++.h>
using namespace std;
string s;
stack<char> st;
bool flag;
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (getline(cin, s))
    {
        st = stack<char>();
        flag = true;
        if (s == ".")
            break;
        for (char c : s)
        {
            if (c == '(' || c == '[')
                st.push(c);
            else if (c == ')')
            {
                if (st.empty() || st.top() == '[')
                {
                    flag = false;
                    break;
                }
                st.pop();
            }
            else if (c == ']')
            {
                if (st.empty() || st.top() == '(')
                {
                    flag = false;
                    break;
                }
                st.pop();
            }
        }
        if (flag && st.empty())
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    return 0;
}