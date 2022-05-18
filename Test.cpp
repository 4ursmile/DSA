#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define ull unsigned long long
#define ll long long
#define ldb long double
#define fort(i,a,b) for (int i = a; i<=b; i++)
#define ford(i,a,b) for (int i = a; i>=b; i--)
#define forrange(i,a,b) for (int i = a; i<b; i++)
using namespace std;
int n,m;
vector<int> A,B,BC;
vector<int> Rao, Van;
int Res;
int nres;
bool Compare(const int &a, const int &b)
{
    return a>b;
}
bool Cal(const int &maxB, int const &minA)
{
    Rao.clear();
    Van.clear();
    int Mongmuon = maxB + minA;
    int i = 0,j = 0;
    while (i<n)
    {
        if (A[i]<Mongmuon) 
        {
            while(A[i] + B[j] < Mongmuon && j<m) j++;
            if (j>=m) return 0;
            Rao.push_back(i);
            Van.push_back(j);
            j++;
            i++;
        } else i++;
    }
    Res = Mongmuon; nres = Rao.size();
    return 1;
}
int main()
{
    cin >> n;
    A.resize(n);
    forrange(i,0,n) cin >> A[i];
    cin >> m;
    B.resize(m);
    forrange(i,0,m) cin >> B[i];
    BC = B; 
    sort(BC.begin(),BC.end());
    int minA = *min_element(A.begin(),A.end());   
    ford(i,n-1,0)
    {
        if (Cal(minA,BC[i]))
        {
            cout << Res << ' ' << nres  << endl;
            forrange(j,0,nres)
            cout << Rao[j]+1 << ' ' << Van[j]+1 << endl; 
            break;
        }
    }
    return 0;
}