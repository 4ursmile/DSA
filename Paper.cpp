#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <stack>
#include <climits>
#include <unordered_map>
#define ull unsigned long long
#define ll long long
#define ldb long double
#define fort(i,a,b) for (int i = a; i<=b; i++)
#define forstep(i,a,b,step) for (int i = a; i<=b; i+=step)
#define ford(i,a,b) for (int i = a; i>=b; i--)
#define forrange(i,a,b) for (int i = a; i<b; i++)
using namespace std;
int Paper[2188][2188] {0};
int res[3] {0};
bool check(int x, int y, int n)
{
    int pivot = Paper[x][y];
    forrange(i,x,x+n)
        forrange(j,y,y+n)
            if (pivot != Paper[i][j]) return 0;
    return 1;
}
void Cut(int x, int y, int n)
{
    if (n==1)
    {
        res[Paper[x][y]]++;
        return;
    }
    int step = n/3;
    if(n<3) 
    {
        return;
    }
    forstep(i,x,x+n-1,step)
        forstep(j,y,y+n-1,step)
        {
            if (check(i,j,step)) 
                res[Paper[i][j]]++;
            else
                Cut(i,j,step);
        }
}
int main()
{
    int n;
    cin >> n;
    fort(i,1,n)
        fort(j,1,n) cin >> Paper[i][j];
    Cut(1,1,n);
    forrange(i,0,3)
        cout << res[i] << endl;
}