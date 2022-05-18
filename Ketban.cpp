#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <stack>
#include <climits>
#include <unordered_map>
#define ull unsigned long long
#define ll long long
#define ldb long double
#define fort(i,a,b) for (int i = a; i<=b; i++)
#define forstep(i,a,b,step) for (int i = a; i<=b; i+=step)
#define ford(i,a,b) for (int i = a; i>=b; i--)
#define forrange(i,a,b) for (int i = a; i<b; i++)
using namespace std;

struct node
{
    int val;
    node* nextlink;
    node* prelink;
};
node* CreateNode(int value)
{
    node* tmp;
    tmp = new node;
    tmp->val = value;
    tmp->nextlink = NULL;
    tmp->prelink = NULL;
    return tmp;
}
int main()
{
    node *arr[100001];
    int n;
    int m;
    cin >> n >> m;
    fort(i,1,n)
        arr[i] = CreateNode(i);
    fort(i,2,n-1)
    {
        arr[i-1]->nextlink = arr[i];
        arr[i]->prelink = arr[i-1];
        arr[i]->nextlink = arr[i+1];
        arr[i+1]->prelink = arr[i];
    }
    arr[n]->nextlink = arr[1];
    arr[1]->prelink = arr[n];
    int a,b;
    forrange(i,0,m)
    {
        cin >> a >> b;
        arr[a]->prelink->nextlink = arr[a]->nextlink;
        arr[a]->nextlink->prelink = arr[a]->prelink;
        arr[a]->nextlink = arr[b]->nextlink;
        arr[a]->nextlink->prelink = arr[a];
        arr[b]->nextlink = arr[a];
        arr[a]->prelink = arr[b];
    }
    node*p = arr[1];
    ford(i,n,1)
    {
        cout << p->val << " ";
        p = p->nextlink;
    }
    return 0;
}