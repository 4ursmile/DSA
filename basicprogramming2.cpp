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
void QuickSort(vector<int> &arr, int left, int right)
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
bool Answear1(vector<int> &Arr)
{
    int n = Arr.size();
    forrange(i,0,n-1)
    {
        int mustfind = 7777 - Arr[i];
        if (binary_search(Arr.begin()+1,Arr.end(),mustfind)) return 1;
    }
    return 0;
}
bool Answear2(vector<int> &Arr)
{
    int n = Arr.size();
    forrange(i,0,n-1)
        if (Arr[i] == Arr[i+1]) return 0;
    return 1;
}
vector<int> Answear3(vector<int> &Arr)
{
    vector<int> ans;
    map<int,int> MAP;
    int n = Arr.size()/2;
    for(int a:Arr)
    {
        MAP[a] = MAP[a]+1;
    }
    for (auto& a:MAP)
    {
        if (a.second > n)
            ans.push_back(a.first);
    }
    return ans;
}
void Answear4(vector<int> &Arr)
{
    int n = Arr.size();
    if (n%2)
        cout << Arr[n/2];
    else
        cout << Arr[n/2-1] << ' ' << Arr[n/2];
}
void Answear5(vector<int> &Arr)
{
    int n = Arr.size();
    int ilower = n, iupper = n;
    forrange(i,0,n)
        if (Arr[i] >= 100)
        {
            ilower = i;
            break;
        }
    forrange(i,0,n)
        if (Arr[i] > 999)
        {
            iupper = i;
            break;
        }
    forrange(i,ilower,iupper)
        cout << Arr[i] << ' ';
}
void Question(vector<int> &Arr, int t)
{
    vector<int> answ;
    switch (t)
    {
    case 1:
        if (Answear1(Arr)) 
            cout << "Yes";
        else    
            cout << "No";
        break;
    case 2:
        if (Answear2(Arr))
            cout << "Unique";
        else
            cout << "Contains duplicate";
        break;
    case 3:
        answ = Answear3(Arr);
        if (answ.size() == 0) 
            cout << -1;
        else
        {
            for (int a:answ)
                cout << a << ' ';
        }
        break;
    case 4:
        Answear4(Arr);
        break;
    case 5:
        Answear5(Arr);
        break;
    default:
        break;
    }
}
int main()
{
    int n; 
    int t;
    cin >> n >> t;
    vector<int> Arr(n);
    forrange(i,0,n)
        cin >> Arr[i];
    QuickSort(Arr,0,Arr.size()-1);
    Question(Arr,t);
    return 0;

}


