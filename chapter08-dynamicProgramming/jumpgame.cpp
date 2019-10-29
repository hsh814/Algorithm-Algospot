#include <iostream>
#include <string>
#include <vector>
#include <string.h>


#define MAX 100

using namespace std;

int board[MAX][MAX], cache[MAX][MAX];
int n;
bool jump(int y, int x)
{
    if(y >= n || x >= n) return 0;
    if(y == n-1 && x == n-1) return 1;
    int jumpSize = board[y][x];
    int& ret = cache[y][x];
    if(ret != -1) return ret;
    ret = jump(y + jumpSize, x) || jump(y, x + jumpSize);
    return ret;
}
int main()
{
    bool results[50];
    int totalCase;
    cin >> totalCase;
    for(int repeat = 0; repeat < totalCase; repeat++)
    {
        cin >> n;
        for(int y = 0; y < n; y++)
        {
            for(int x = 0; x < n; x++)
            {
                cin >> board[y][x];
            }
        }
        memset(cache, -1, sizeof(cache));
        results[repeat] = jump(0, 0);
    }
    for(int i = 0; i < totalCase; i++)
    {
        if(results[i]) { cout << "YES" << endl; }
        else { cout << "NO" << endl; }
    }
    return 0;
}