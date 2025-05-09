
#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> v;
int temp;

int check(int sum)
{
    if (sum <= 1)
        return 0;
    if (sum == 2)
        return 1;
    if (sum % 2 == 0)
        return 0;
    for (int i = 3; i * i <= sum; i += 2)
    {
        if (sum % i == 0)
            return 0;
    }
    return 1;
}

int go(int idx, int sum)
{
    if (idx == N)
    {
        return check(sum);
    }
    return go(idx + 1, sum + v[idx]) + go(idx + 1, sum);
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
    cout << go(0, 0) << "\n";

    return 0;
}