/*
 2와 5로 나누어 떨어지지 않는 정수 n(1 ≤ n ≤ 10000)
 각 자릿수가 모두 1로만 이루어진 n의 배수 중 가장 작은 수의 자리수

 modular 연산의 특징을 잘 활용하자

 (a * b)%n = ((a%n) * (b%n)) % n
 (a + b)%n = ((a%n) + (b%n)) % n

*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int main(){

    while(scanf("%d", &n) != EOF) {
        ll cnt = 1, ret = 1;

        while(true){
            if(cnt % n == 0) {
                printf("%lld\n", ret);
                break;
            } else{
                cnt = (cnt * 10) + 1;
                cnt %= n;
                ret++;
            }
        }
    }

    return 0;
}
