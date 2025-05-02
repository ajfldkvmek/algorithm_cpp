#include <bits/stdc++.h>
#include "iostream"
using namespace std;

int N, M, j, l, r, temp, ret;

int main()
{

    cin >> N >> M >> j;
    l = 1; // 초기위치
    ret = 0;

    for (int i = 0; i < j; i++)
    {
        r = l + M - 1; // 사과박스 범위
        cin >> temp;   // 사과가 떨어지는 위치

        if (temp >= l && temp <= r)
            continue;
        else
        {
            if (temp < l)
            {
                ret += (l - temp);
                l = temp;
            }
            else
            {
                ret += (temp - r);
                l += (temp - r);
            }
        }
    }

    cout << ret << endl;

    return 0;
}
