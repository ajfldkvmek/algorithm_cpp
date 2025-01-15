#include <bits/stdc++.h>
using namespace std;
int i=1;
int a=4;
int main() {

    cout << i << ' ' << &i << '\n';
    i = 0;
    cout << i << ' ' << &i << '\n';



    /*
        포인터는 os의 비트수에 따라 그 크기가
        32bit 는 4바이트
        64bit 는 8바이트
        로 고정된다
    */
    int *b = &a;
    char *c;
    cout << "a: " << a << endl;
    cout << "&a: " << &a << endl;
    cout << "b: " << b << endl;
    cout << "*b: " << *b << endl;

    cout << "size of *b: " << sizeof(*b) << endl;
    cout << "size of *c: " << sizeof(*b) << endl;

    

    return 0;
}