#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#define ifname "BT8INP.txt"
#define ofname "BT8OUT.txt"
#define ull unsigned long long
#define ll long long
#define ldb long double
#define fort(i,a,b) for (int i = a; i<=b; i++)
#define ford(i,a,b) for (int i = a; i>=b; i--)
#define forrange(i,a,b) for (int i = a; i<b; i++)
using namespace std;
void Read(vector<string> &Setences)
{
    ifstream inf(ifname);
    string tmp;
    getline(inf,tmp, '&');
    inf.close();
    int n = tmp.size();
    string p;
    int pivot = 0;
    forrange(i, 0, n)
    {
        if (tmp[i] == '.' || tmp[i] == '!' || tmp[i] == '?')
        {
            p = tmp.substr(pivot, i - pivot);
            while(p.find(",") >=0 && p.find(",") < p.size())
            {
                p.erase(p.find(","),1);
            }
            Setences.push_back(p);
            pivot = i + 2;
        }
    }
}
void Splitter(string &Setence, vector<string> &Wi)
{
    int pivot = 0;
    string tmp;
    int n = Setence.size();
    forrange(i, 0, n)
    {
        if (Setence[i] == ' ')
        {
            tmp = Setence.substr(pivot, i - pivot);
            Wi.push_back(tmp);
            pivot = i + 1;
        }
    }
    tmp = Setence.substr(pivot, n - pivot);
    Wi.push_back(tmp);
}
void SplitWord(vector<string> &s ,vector<vector<string>> &WinS)
{
    int n = s.size();
    WinS.resize(n);
    forrange(i,0,n)
    {
        Splitter(s[i],WinS[i]);
    }
}
void Write(vector<string> &s ,vector<vector<string>> &WinS, map<string,int> &Map, int Max)
{
    ofstream of(ofname);
    of << s.size() << endl;
    forrange(i,0,WinS.size())
    {
        of << WinS[i].size() << endl;
    }
    for(auto& a:Map)
    {
        if (a.second == Max) of << a.first << ' ';
    }
    of << endl;
    forrange(i,0,s.size())
    {
        forrange(j,0,WinS[i].size()-1)
        {
            of << WinS[i][j] << ' ';
        }
        of << WinS[i][WinS[i].size()-1] << ". ";
    }
    of.close();
}
int main()
{
    vector<string> Setences;
    vector<vector<string>> WinS;
    map <string,int> MAP;
    Read(Setences);
    SplitWord(Setences,WinS);
    forrange(i,0,Setences.size())
    {
        forrange(j,0,WinS[i].size())
        {
            MAP[WinS[i][j]]  = MAP[WinS[i][j]] + 1;
        }
    }
    int Max = 0;
    for(auto& a:MAP)
    {
        if (a.second>Max) Max = a.second;
    }
    forrange(i,0,WinS.size())
    {
        sort(WinS[i].begin(),WinS[i].end());
    }
    Write(Setences,WinS,MAP,Max);

}