#include <bits/stdc++.h>
using namespace std;

int N, C, a[1004];
vector<pair<int, int>> v;
map<int, int> mp, mp_first;
// mp        : 숫자 빈도 저장용 map
// mp_first  : 나운 순서 저장용 map

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
    {
        // 나온 빈도가 동일하면 먼저 나온 숫자를 출력
        return mp_first[a.second] < mp_first[b.second];
    }
    return a.first > b.first;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> C;

    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
        /**
         *  c++ 에서는 map 을 조회했을 때 해당 값이 없으면 자동으로 default 값을 저장하게된다.
         *  숫자면 0, 문자면 "" 과같이
         *
         *  따라서 단순히 조회만을 위한다면
         *  if (mp_first.find(a[i]) == mp_first.end())
         *  과 같이 find 를 사용하고 end()와 비교하면 된다.
         *  (c++ 에서 map.find()는 iterator 를 반환하기 때문에 end() 를 꼭 사용하여 비교하여야함)
         */

        // if (mp_first.find(a[i]) == mp_first.end()) {s
        //     mp_first[a[i]] = i + 1;
        // }

        if (mp_first[a[i]] == 0) // 맵에 요소가 없으면
            mp_first[a[i]] = i + 1;
    }

    for (auto it : mp)
    {
        v.push_back({it.second, it.first});
    }

    sort(v.begin(), v.end(), cmp);

    for (auto i : v)
    {
        for (int j = 0; j < i.first; j++)
        {
            cout << i.second << " ";
        }
    }

    cout << endl;

    return 0;
}