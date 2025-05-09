#include <bits/stdc++.h>
using namespace std;

/**
 *  보통 이런 경우에서 1억정도 까지는 괜찮음
 *  완전 탐색이 반복으로 가능하다면 웬만하면 재귀보다는 반복으로
 *
 */
int N, result;
int main()
{

    cin >> N;
    string s = "2400";
    for (int i = 2400;; i++)
    {
        if (N <= 0)
            break;
        string sNum = to_string(i);
        if (sNum.find(s) != string::npos)
        {
            N--;
        }
        result = i;
    }

    cout << result << endl;

    return 0;
}