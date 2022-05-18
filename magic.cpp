// BTHT2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
#define ull unsigned long long
#define ll long long
#define ldb long double
#define fort(i,a,b) for (int i = a; i<=b; i++)
#define ford(i,a,b) for (int i = a; i>=b; i--)
#define forrange(i,a,b) for (int i = a; i<b; i++)
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
void ccsort16(int a[], int n, int shift) {

    int count[16] = { 0 };
    int output[n];
    int i, last;

    for (i = 0; i < n; i++) {
        ++count[(a[i] >> shift) & 15];
    }
    for (i = last = 0; i < 16; i++) {
        last += count[i];
        count[i] = last - count[i];
    }
    for (i = 0; i < n; i++) {
        output[count[(a[i] >> shift) & 15]++] = a[i];
    }
    for (i = 0; i < n; i++) {
        a[i] = output[i];
    }
}

void rsort16(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    for (int shift = 0; (max >> shift) > 0; shift += 4) {
        ccsort16(a, n, shift);
    }
}
void  Process()
{
    int n;
    ull A,B,C;
    ull X,Y;
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
    ull V = 0;
    forrange(i,0,size)
    {
        V = (((V%Y)*(X%Y))%Y + S[i]%Y)%Y;
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


