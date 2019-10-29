#include <iostream>
#include <string>
#include <vector>

#define MAX 100

using namespace std;

int board[MAX][MAX];
int n;
bool jump(int y, int x)
{
    if(y >= n || x >= n) return false;
    if(y == n-1 && x == n-1) return true;
    int jumpSize = board[y][x];
    return jump(y + jumpSize, x) || jump(y, x + jumpSize);
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
        results[repeat] = jump(0, 0);
    }
    for(int i = 0; i < totalCase; i++)
    {
        if(results[i]) { cout << "YES" << endl; }
        else { cout << "NO" << endl; }
    }
    return 0;
}