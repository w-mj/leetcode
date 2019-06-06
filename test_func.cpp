#include <functional>
#include <iostream>
using namespace std;

class A {
public:
    int f(int a, int b)
    {
        return a + b;
    }
};


int main(void)
{
    A a;
    function<int(A*, int, int)> a_f = A::f;
    cout << a_f(&a, 1, 2) << endl;
}