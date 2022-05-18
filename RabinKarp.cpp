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
const int d = 256;
const int p = 2147483647;
int GetVal(char C)
{
    return int(C);
}
typedef pair<int,int> point;
bool RB2string(string &Txt, int length)
{
    int n = Txt.size();
    int m = length;
    ll hM = 1;
    ll pHash = 0;
    vector<point> tArr(n-m+1);
    forrange(i,0,m-1) hM = (hM*d)%p;
    forrange(i,0,m) pHash = ((pHash*d)%p + GetVal(Txt[i]))%p;
    tArr[0].first = pHash;
    tArr[0].second = 0;
    forrange(i,0,n-m)
    {
        pHash = (((pHash-hM*GetVal(Txt[i]))*d)%p + GetVal(Txt[i+m]))%p;
        if (pHash < 0)
            pHash+=p;
        tArr[i+1].first = pHash;
        tArr[i+1].second = i+1;
    }
    sort(tArr.begin(),tArr.end());
    bool flag = 0;
    forrange(i,0,n-m+1)
    {
        if (tArr[i].first == tArr[i+1].first)
        {
            flag = 0;
            forrange(j,0,m)
            {
                if (Txt[tArr[i].second+j] != Txt[tArr[i+1].second+j])
                {
                    flag = 1;
                    break;
                }
            }
            if (!flag){
                return 1;
            }
        }
    }

    return 0;
}

int binarySearch(string &s)
{
    int max = 0;
    int high = s.size()-1;
    int low = 1;
    while (low <= high)
    {
        int mid = low + (high-low)/2;
        //cout << mid << endl;
        if (RB2string(s,mid))
        {
            max = mid;
            low = mid+1;
        } else
        {
            high = mid-1;
        }
    }
    return max;
}

int main()
{
    string txt;
    getline(cin,txt);
    cout << binarySearch(txt);
    return 0;
}