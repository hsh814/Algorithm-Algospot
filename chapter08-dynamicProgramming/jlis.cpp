#include <iostream>
#include <string>
#include <vector>
#include <string.h>

#define MAX 100

using namespace std;


int cache[MAX], sa[MAX], sb[MAX];
int n;

int max(int x, int y)
{
    if(x < y){
        return y;
    }
    return x;
}
int lis(int start)
{
    int& ret = cache[start];
    if(ret != -1){ return ret; }
    ret = 1;
    for(int next = start + 1; next < n; next++)
    {
        if(seq[next] > seq[start]) { ret = max(ret, lis(next) + 1); }
    }
    return ret;
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
        cin >> n;
        int index = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> seq[i];
        }
        int maximum = 1;
        for(int i = 0; i < n; i++)
        {
            maximum = max(maximum, lis(i));
        }
        results[repeat] = maximum;
    }
    for(int i = 0; i < totalCase; i++)
    {
        cout << results[i] << '\n';
    }
    return 0;
}