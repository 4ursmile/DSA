#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <list>
#include <algorithm>
#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define ldb long double
#define fort(i,a,b) for (int i = a; i<=b; i++)
#define ford(i,a,b) for (int i = a; i>=b; i--)
#define forrange(i,a,b) for (int i = a; i<b; i++)
using namespace std;
 
int main()
{
    int minbefore;
    int n,m;
    cin >> n;
    cin >> m;
    int maxx = n;
    vector<int> calA(m);
    forrange(i,0,m)
        cin >> calA[i];
    vector<int>  Arr(n+m);
    vector<bool> Check(n+m);
    forrange(i,0,n)
        Arr[i] = n-i;
    int count = n;
    vector<int> index(n+1);
    fort(i,1,n)
        index[i] = n-i;
    int last = 0;
    forrange(i,0,m)
    {   
        int icache = index[calA[i]];
        Arr[count+i] = calA[i];
        Check[icache] = 1;
        index[calA[i]] = count+i;
        while (Check[last] && last < n+m)
        {
            last++;
        }
        if (last == n+m) break;
        cout << Arr[last] << ' ';
        
    }
    return 0;
}