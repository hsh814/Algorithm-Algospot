#include<iostream>
#include<string>

using namespace std;

int howManyPairs(const int* pairs1, const int* pairs2, int pairNum, int studentNum);
int maxPair(int studentNum);

int main()
{
    int totalCase;
    cin >> totalCase;
    int results[50];
    for(int repeat = 0; repeat < totalCase; repeat++){
        int studentNum, pairNum;
        cin >> studentNum >> pairNum;
        int* pairs1 = new int[pairNum];
        int* pairs2 = new int[pairNum];
        for(int i = 0; i < pairNum; i++){
            cin >> pairs1[i] >> pairs2[i];
        }
        if(studentNum < 2  || pairNum < (studentNum / 2)){
            results[repeat] = 0; continue;
        } else {
            results[repeat] = howManyPairs(pairs1, pairs2, pairNum, studentNum);
        }
    }
    for(int i = 0; i < totalCase; i++){
        cout << results[i] << endl;
    }
    return 0;
}

int maxPair(int studentNum)
{
    int result = 1;
    for(int i = 0; i < studentNum; i += 2)
    {
        result *= (i + 1);
    }
    return result;
}
int howManyPairs(const int* pairs1, const int* pairs2, int pairNum, int studentNum)
{
    bool isEveryonePaired = false;
    for(int i = 0; i < studentNum; i++)
    {
        isEveryonePaired = false;
        for(int j = 0; j < pairNum; j++)
        {
            if(pairs1[j] == i || pairs2[j] == i)
            {
                isEveryonePaired = true;
            }
        }
        if(isEveryonePaired == false){
            return 0;
        }
    }
    bool changed = true;
    bool* isPaired = new bool[studentNum]; 
    int result = 0;
    int *firstY = new int[pairNum];
    int start = 0;
    for(int n = 0; n < pairNum; n++){
        firstY[n] = 0;
    }
    for(int m = 0; m < maxPair(studentNum); m++)
    {
        for(int i = 0; i < studentNum; i++){
            isPaired[i] = false;
        }
        for(int x = 0; x < studentNum; x++)
        {
            if(isPaired[x] == true){
                continue;
            } else if(changed == true){
                start = firstY[x];
            } else {
                start = firstY[x] + 1;
            }
            for(int y = start; y < pairNum; y++)
            {
                if(x == pairs1[y] && isPaired[pairs2[y]] == false)
                {
                    isPaired[x] = true; isPaired[pairs2[y]] = true;
                }
                else if(x == pairs2[y] && isPaired[pairs1[y]] == false)
                {
                    isPaired[x] == true; isPaired[pairs1[y]] == true;
                }
                if(y != firstY[x]){
                    changed = true;
                } else {
                    changed = false;
                }
                firstY[x] = y;
            }
        }
        bool success = true;
        for(int i = 0; i < studentNum; i++){
            if(isPaired[i] == false){
                success = false; break;
            }
        }
        if(success == true){
            result++;
        }
    }
    return result;
}
