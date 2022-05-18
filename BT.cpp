#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#define ull unsigned long long
#define ll long long
#define ldb long double
#define fort(i,a,b) for (int i = a; i<=b; i++)
#define ford(i,a,b) for (int i = a; i>=b; i--)
#define forrange(i,a,b) for (int i = a; i<b; i++)
using namespace std;
int n,m;

int main()
{
    bool a = 0, b = 0, c = 0, d  = 0;

    fort(i,0,1)
        fort(j,0,1)
            fort(k,0,1)
                fort(l,0,1)
                {
                    a = i; b = j; c = k; d = l;
                    cout << bool((!b+c)*(!b+d)) << "  ";
                    cout << bool(!b+c*d) << "     |||     ";
                    cout << bool(!a*b*c+a*b*!c+!a*b*d) << "  ";
                    cout << bool(b*!d+a*b*!c) << endl;
                }
}
