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
#define ford(i,a,b) for (int i = a; i>=b; i--)
#define forrange(i,a,b) for (int i = a; i<b; i++)
using namespace std;
bool check(vector<int> &arr, int st, int end)
{
    int maxe = *max_element(arr.begin()+st+1, arr.begin()+end-1);
    st = min(arr[st],arr[end]);
    //cout << st << " " << end << "  " << maxe << endl;
    if (maxe > st) return false;
    return true;
}

int main()
{

}