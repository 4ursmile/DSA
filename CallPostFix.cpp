#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <stack>
#define ull unsigned long long
#define ll long long
#define ldb long double
#define fort(i,a,b) for (int i = a; i<=b; i++)
#define ford(i,a,b) for (int i = a; i>=b; i--)
#define forrange(i,a,b) for (int i = a; i<b; i++)
using namespace std;
void Splitstring(vector<string> &Postfix,const string &s)
{
    int pivot = 0;
    int len = s.length();
    forrange(i,0,len)
        if (s[i] == ' ')
        {
            string tmp = s.substr(pivot,i-pivot);
            Postfix.push_back(tmp);
            pivot = i+1;
        }
    string tmp = s.substr(pivot,len-pivot);
    Postfix.push_back(tmp);
}
bool isNumber(char c)
{
    if (c >= '0' && c<='9') return 1;
    return 0;
}
ll Calculate(const vector<string> &Postfix)
{
    int len = Postfix.size();
    stack<ll> Stack;
    forrange(i,0,len)
        if (isNumber(Postfix[i][0]))
            Stack.push(stoll(Postfix[i]));
        else
        {
            ll A = Stack.top(); Stack.pop();
            ll B = Stack.top(); Stack.pop();
            if (Postfix[i][0] == '+')
                A+=B;
            if (Postfix[i][0] == '-')
                A-=B;
            if (Postfix[i][0] == '*')
                A*=B;
            if (Postfix[i][0] == '/')
                A/=B;
            Stack.push(A);
        }
    return Stack.top();
}
int main()
{
    vector<string> Postfix;
    string s;
    getline(cin,s);
    Splitstring(Postfix,s);
    cout << Calculate(Postfix);
}