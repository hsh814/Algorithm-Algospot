#include<iostream>
#include<string>

using namespace std;

int howManyPairs(const int* pairs1, const int* pairs2, int pairNum, int studentNum);

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
    bool* isPaired = new bool[studentNum]; 
    while(true)
    {
        for(int i = 0; i < studentNum; i++){
            isPaired[i] = false;
        }
        for(int x = 0; x < studentNum; x++)
        {
            for(int y = 0; y < pairNum; y++)
            {
                if(isPaired[x] == true){
                    continue;
                }
                if(x == pairs1[y] && isPaired[pairs2[y]] == false)
                {
                    isPaired[x] = true; isPaired[pairs2[y]] = true;
                }
                else if(x == pairs2[y] && isPaired[pairs1[y]] == false)
                {
                    isPaired[x] == true; isPaired[pairs1[y]] == true;
                }
            }
        }
        bool success = true;
        for(int i = 0; i < studentNum; i++){
            if(isPaired[i] == false){
                success = false; break;
            }
        }
    }


    return 0;
}
