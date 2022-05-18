#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <list>
#include <cmath>
using namespace std;
#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define ldb long double
#define fort(i,a,b) for (int i = a; i<=b; i++)
#define ford(i,a,b) for (int i = a; i>=b; i--)
#define forrange(i,a,b) for (int i = a; i<b; i++)
const ui base = 65535;
void QuickSort(vector<ull> &arr, int left, int right)
{
    int i = 0,j = 0,pivot = 0;
    pivot = arr[(left+right)/2];
    i= left; j = right;
    while (i<j)
    {
        while (arr[i] < pivot && i<right) i++;
        while (arr[j] > pivot && j>left) j--;
        if (i<=j) 
        {
            swap(arr[i],arr[j]);
            i++; j--;
        }
    }
    if (j>left) QuickSort(arr,left,j);
    if (i<right) QuickSort(arr,i,right);    
}
void radixSort(vector<ui> &a, int n)
{
    vector<ui> b(n);
    ui m = a[0], exp = 1;

    for (int i = 0; i < n; i++)
        if (a[i] > m)
            m = a[i];

    while (m / exp > 0)
    {
        int bucket[base] = {0};
        for (int i = 0; i < n; i++)
            bucket[a[i] / exp % base]++;
        for (int i = 1; i < base; i++)
            bucket[i] += bucket[i - 1];
        for (int i = n - 1; i >= 0; i--)
            b[--bucket[a[i] / exp % base]] = a[i];
        for (int i = 0; i < n; i++)
            a[i] = b[i];
        exp *= base;
    }
}
void  Process()
{
    int n;
    ull A,B,C,X,Y;
    cin >> n;
    cin >> A >> B >> C;
    cin >> X >> Y;
    vector<ull> S(n);
    int size = S.size();
    S[0] = A;
    forrange(i,1,size)
    {
        S[i] = (((S[i-1]%C)*(B%C))%C + A%C)%C;
    }
    vector<ui> S2(size);
    forrange(i,0,size)
        S2[i] = S[i];
    radixSort(S2,size);
    ull V = 0;
    forrange(i,0,size)
    {
        V = (((V%Y)*(X%Y))%Y + S2[i]%Y)%Y;
    }
    cout << V << endl;
}
int main()
{
    int t;
    cin >> t;
    forrange(i,0,t)
        Process();
    return 0;

}

