#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define ldb long double
#define fort(i,a,b) for (int i = a; i<=b; i++)
#define ford(i,a,b) for (int i = a; i>=b; i--)
#define forrange(i,a,b) for (int i = a; i<b; i++)
bool isdigit(string s)
{
    if (s[0] >= '0' && s[0] <= '9') return 1;
    return 0;
}
int CalculatePostFix(vector<string> &Arr)
{
    stack<string> Calstack;
    int a,b,c;
    for(string s:Arr)
    {
        if (isdigit(s))
            Calstack.push(s);
        else
        {
            int b = stoi(Calstack.top());
            Calstack.pop();
            int a = stoi(Calstack.top());
            Calstack.pop();
            if (s == "+")
                c = a+b;
            else if (s=="-")
                c = a-b;
            else if (s=="*")
                c = a*b;
            else 
                c = a/b;
            Calstack.push(to_string(c));
        }
    }
    return stoi(Calstack.top());
}
int main()
{
    string s;
    getline(cin,s);
    vector<string> Arr;
    int pivot = 0;
    int n = s.size();
    forrange(i,0,n)
    {
        if (s[i] == ' ')
        {
            string tmp = s.substr(pivot,i-pivot);
            pivot = i+1;
            Arr.push_back(tmp);
        }
    }
    string tmp = s.substr(pivot,n-pivot);
    Arr.push_back(tmp);
    cout<< CalculatePostFix(Arr);
    return 0;
}