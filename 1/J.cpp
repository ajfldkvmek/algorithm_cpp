/**
 *  T: testcase <= 100
 *  N: 0 <= number of item <= 30
 * 
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int T, N;
string a, b;

int main(){

    cin >> T;

    for(int k = 0; k < T; k++) {
        map<string, int> map;
        cin >> N;


        for(int i = 0; i < N; i++){
         cin >> a >> b;
            map[b]++;
         }

        long long ret = 1;
       /*
            auto 는 c++ 에서 타입추론을 위한 놈
            second는 key, value 의 쌍으로 저장되는 map 의 특징을 이용한 것으로 
            pair<int, int> 에서 value 에 해당하는 두 번째 값을 찾기 위한 것이다  
        */ 
        for(auto c : map){
            ret *= ((ll) c.second + 1); //아무것도 입지 않는 경우를 위해 + 1
        }

        ret--;
        cout << ret << "\n";

    }

    return 0;
}
