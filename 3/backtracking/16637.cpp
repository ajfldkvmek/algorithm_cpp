/**
 *  백준 16637
 *
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> num;
vector<char> oper;

int n, ret = INT_MIN;
string s;

int _oper(char op, int a, int b)
{
    if (op == '*')
        return a * b;
    if (op == '+')
        return a + b;
    if (op == '-')
        return a - b;

    assert(false);
    return 0;
}

void dfs(int here, int _num)
{
    if (here == num.size() - 1)
    {
        ret = max(ret, _num);
        return;
    }

    dfs(here + 1, _oper(oper[here], _num, num[here + 1]));

    if (here + 2 <= num.size() - 1)
    {
        int temp = _oper(oper[here + 1], num[here + 1], num[here + 2]);
        dfs(here + 2, _oper(oper[here], _num, temp));
    }
    return;
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin >> s;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            num.push_back(s[i] - '0');
        else
            oper.push_back(s[i]);
    }

    dfs(0, num[0]);

    cout << ret << endl;

    return 0;
}