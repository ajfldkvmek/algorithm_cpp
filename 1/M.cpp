#include<bits/stdc++.h>
using namespace std;

int n, cnt;
string s;
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> s;
        vector<char> v;
        for(char c : s){

            if(v.empty()) v.push_back(c);
            else {
                if(v.back() == c) v.pop_back();
                else v.push_back(c);
            }
            
        }

        // if(v.size() == 0) cnt++;
        if(v.empty()) cnt++;
    }

    cout << cnt << endl;

    return 0;

}