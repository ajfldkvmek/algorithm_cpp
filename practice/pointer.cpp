#include <bits/stdc++.h>
using namespace std;

int k[3] = {1,2,3};

int main(){ 

    /*
       '*' 는 세가지 기능이 있음
        1. 곱셈
        2. 포인터
        3. 역참조 연산자

     */

    string a = "qwe";
    string *b = &a;
    cout << "b: " << b << endl;
    cout << "*b: " << *b << endl;

    cout << "*&a: " << *&a << endl;

    /*
        array to decay
        -> 배열의 이름을 포인터로 사용할 수 있음 

        vector<int> a 같은 건 불가능하고
        정적배열의 경우에만 가능하다   
     */
    int * c = k;
    cout << "c: " << c << endl;
    cout << "&k[0]: " << &k[0] << endl;
    cout << "c + 1: " << c+1 << endl;
    cout << "&k[1]: " << &k[1] << endl;



    return 0;
}