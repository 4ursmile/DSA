#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>
#include <stack>
#define ull unsigned long long
#define ll long long
#define ldb long double
#define fort(i,a,b) for (int i = a; i<=b; i++)
#define ford(i,a,b) for (int i = a; i>=b; i--)
#define forrange(i,a,b) for (int i = a; i<b; i++)
using namespace std;
int main()
{
    vector<string> arr;
    string s;
    while (s != "0")
    {
        getline(cin,s);
        arr.push_back(s);
    }
    ofstream ofs("Source.txt");
    for (string a:arr)
        ofs << a << endl; 
    ofs.close();
    return 0;
}