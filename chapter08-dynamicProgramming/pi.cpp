#include <iostream>
#include <string>
#include <vector>
#include <string.h>

#define MAX 10009

using namespace std;

string s;
int cache[MAX];
int n;
int strend;

int min(int x, int y)
{
    if(x > y){
        return y;
    }
    return x;
}
int classify(int a, int b)
{
    string part = s.substr(a, b-a+1);
    if(part == string(part.size(), part[0])) { return 1; }
    bool progressive = true;
    for(int i = 0; i < part.size() - 1; i++)
    {
        if(part[i] - part[i+1] != part[0] - part[1]){
            progressive = false;
        }
    }
    if(progressive)
    {
        if (part[1] - part[0] == 1 || part[1] - part[0] == -1){
            return 2;
        }
        return 5;
    }
    for(int i = 0; i < part.size(); i++)
    {
        if(part[i] != part[i%2]){
            return 10;
        }
    }
    return 4;
}
void printCache(int k)
{
    cout << k << " : ";
    for (int i = 0; i < strend; i++)
    {
        cout << "[" << i << "]=" << cache[i] << ", ";
    }
    cout << endl;
}
int memorize(int begin)
{
    if(begin == strend) return 0;
    if(cache[begin] != -1) return cache[begin];

    int inf = 99999999;
    cache[begin] = inf;
    for(int len = 3; len < 6; len++)
    {
        if(begin + len <= strend)
        {
            cache[begin] = min(cache[begin], memorize(begin + len) + classify(begin, begin + len - 1));
        }
    }
    //printCache(begin);
    return cache[begin];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int results[50];
    int totalCase;
    cin >> totalCase;
    for(int repeat = 0; repeat < totalCase; repeat++)
    {
        //cout << repeat << "th repeat!\n";
        memset(cache, -1, sizeof(cache));
        cin >> s;
        strend = s.size();
        results[repeat] = memorize(0);
    }
    for(int i = 0; i < totalCase; i++)
    {
        cout << results[i] << '\n';
    }
    return 0;
}