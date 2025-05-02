/**
 *  백준 1436
 *  숫자 n 을 입력했을 때 666이 포함된 가장 작은 n 번쨰 숫자
 */

#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    cin >> n;
    int i = 666;
    while (true)
    {
        if (to_string(i).find("666") != string::npos)
            n--;
        if (n == 0)
            break;
        i++;
    }

    cout << i << endl;
}