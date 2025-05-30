/*
    상근이는 트럭을 총 세 대 가지고 있다. 오늘은 트럭을 주차하는데 비용이 얼마나 필요한지 알아보려고 한다.
    상근이가 이용하는 주차장은 주차하는 트럭의 수에 따라서 주차 요금을 할인해 준다.
    트럭을 한 대 주차할 때는 1분에 한 대당 A원을 내야 한다. 두 대를 주차할 때는 1분에 한 대당 B원, 세 대를 주차할 때는 1분에 한 대당 C원을 내야 한다.
    A, B, C가 주어지고, 상근이의 트럭이 주차장에 주차된 시간이 주어졌을 때, 주차 요금으로 얼마를 내야 하는지 구하는 프로그램을 작성하시오.

    input
    1. 1 <= C <= B <= A <= 100
    a(도착시간) b(출차시간) , a < b, 이 두 수는 1과 100사이
*/
#include<bits/stdc++.h>
using namespace std;

int A, B, C, a, b, cnt[104], ret;
int main(){
    
    cin >> A >> B >> C;
    for(int i = 0; i < 3; i++){
        cin >> a >> b;
        for(int j = a; j < b; j++) cnt[j]++;
    }

    for(int i = 0; i < 100; i++){
        if(cnt[i]) {
            if(cnt[i] == 1) ret += A;
            else if(cnt[i] == 2) ret += B * 2;
            else ret += C * 3;
        }
    }

    cout << ret;

    return 0;

}
