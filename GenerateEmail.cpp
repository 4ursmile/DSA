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
    ifstream inf("inforin.txt");
    vector<string> Arr;
    string tmp;
    while (!inf.eof())
    {
        getline(inf,tmp);
        Arr.push_back(tmp);
    }
    for(string s:Arr)
    {
        cout << s << "@gm.uit.edu.vn" << endl;
    }
    return 0;
}