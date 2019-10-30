#include <iostream>
#include <string>
#include <vector>
#include <string.h>

#define MAX 100

using namespace std;


int cache[MAX][MAX], triangle[MAX][MAX];
int n;

int max(int x, int y)
{
    if(x < y){
        return y;
    }
    return x;
}
int path(int x, int y)
{
    if(x == (n-1)){
        return triangle[x][y];
    }
    int& temp = cache[x][y];
    if(temp != -1){
        return temp;
    }
    temp = triangle[x][y] + max(path(x+1, y), path(x+1, y+1));
    return temp;
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
            for(int j = 0; j < i + 1; j++)
            {
                cin >> triangle[i][j];
            }
        }
        results[repeat] = path(0, 0);
    }
    for(int i = 0; i < totalCase; i++)
    {
        cout << results[i] << '\n';
    }
    return 0;
}