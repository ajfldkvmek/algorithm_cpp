#include <bits/stdc++.h>
using namespace std;

map<int, int> mp;

int main() {


    vector<int> v{1,1,2,2,3,3};
    for(int i : v){
        if(mp[i]) continue;
        mp[i] = 1;
    }
    vector<int> ret;
    for(auto it : mp){
        ret.push_back(it.first);
    }

    for(int i : ret) cout << i << endl;
    cout << "=========================" << endl;
    /*
        중복된 값의 제거는 unique 함수를 사용하여 처리하는 법도 있다 
    */

   //이렇게 unique함수를 사용하면 중복되지 않은 값들이 순서대로 삽입되고 그 뒤에 중복된 값들이 들어오고 중복이 시작되는 index를 반환한다
   //하지만 모든 중복된 값들이 다 사라지는 것은 아니기 때문에 반드시 정렬과정이 사전에 필요하다
   //그 후 erase 함수를 사용하여 값들을 제거한다
   auto it = unique(v.begin(), v.end());
   for(int i : v) cout << i << endl;
    cout << "=========================" << endl;
    
    
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int i : v) cout << i << endl;
    cout << "=========================" << endl;
    return 0;
}