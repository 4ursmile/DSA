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
int checkSpecial(char c)
{
    if (c == '+' || c=='-' || c=='*' || c=='/')
        return 1;
    if (c == '(') return 2;
    if (c == ')') return 3;
    return 0;
}
int predecence(char c)
{
    if (c== '(') return 0;
    if (c== '+' || c=='-') return 1;
    if (c== '*' || c == '/' || c=='%') return 2;
    return 3;

}
bool isNumber(char c)
{
    if (c >= '0' && c<='9') return 1;
    return 0;
}
void Inpre2Postpre(vector<string> &inp, vector<string> &prep)
{
    int len = inp.size();
    stack<char> Stack;
    forrange(i,0,len)
    {
        if(isNumber(inp[i][0]))
            prep.push_back(inp[i]);
        else
            if (inp[i][0] == '(') 
                Stack.push(inp[i][0]);
            else
                if (inp[i][0] == ')')
                {
                    char c = Stack.top();
                    while (c != '(')
                    {
                        string s;
                        s+=c;
                        prep.push_back(s);
                        Stack.pop();
                        c = Stack.top();
                    }
                    Stack.pop();
                } else
                {
                    if (!Stack.empty())
                    {
                        char c = Stack.top();
                        while (predecence(inp[i][0]) <= predecence(c))
                        {
                            string s;
                            s+=c;
                            prep.push_back(s);
                            Stack.pop();
                            c = Stack.top();
                        }
                    }
                    Stack.push(inp[i][0]);
                }
    }
    char c;
    while (!Stack.empty())
    {
        string s;
        c = Stack.top();
        s+=c; 
        prep.push_back(s);
        Stack.pop();
    }
    
}
vector<string> SplitFix(string &s)
{
    vector<string> Arrayout;
    int len = s.length();
    int Pivot = 0;
    forrange(i,0,len)
    {
        if (checkSpecial(s[i]))
        {
            if (i-Pivot>0)
            {
                string tmp = s.substr(Pivot,i-Pivot);
                Pivot = i;
                Arrayout.push_back(tmp);
            }
            Pivot++;
            string tmp;
            tmp+=s[i];
            Arrayout.push_back(tmp);
        } else
        {
            if(i==len-1)
                if (i-Pivot>=0)
                {
                    string tmp = s.substr(Pivot,i-Pivot+1);
                    Pivot = i;
                    Arrayout.push_back(tmp);
                }    
        }
    }
    return Arrayout;
}
int main()
{
    string s;
    cin >> s;
    vector<string> Arrayout = SplitFix(s);
    vector<string> postfix;
    Inpre2Postpre(Arrayout,postfix);
    for(string sres:postfix)
        cout << sres << ' ';
}