#include <bits/stdc++.h>
using namespace std;

int h, m, a[104][104];
string s;

int main()
{
    cin >> h >> m;
    for (int i = 0; i < h; i++)
    {
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == 'c')
                a[i][j] = 0;
            else
                a[i][j] = -1;
        }
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 0)
            {
                int cnt = 1;
                while (a[i][j + 1] == -1)
                {
                    a[i][j + 1] = cnt++;
                    j++;
                }
            }
        }
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}