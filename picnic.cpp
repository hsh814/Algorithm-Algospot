#include<iostream>
#include<string>

using namespace std;

int compare(int x1, int x2, int y1, int y2);
int howMany(const int* pairs1, const int* pairs2, bool isPaired[], bool isFriend[][10], int pairNum, int studentNum);

int main()
{
    //input
    int totalCase;
    cin >> totalCase;
    int results[50];
    int a, b;
    for(int repeat = 0; repeat < totalCase; repeat++){
        int studentNum, pairNum;
        cin >> studentNum >> pairNum;
        int* pairs1 = new int[pairNum];
        int* pairs2 = new int[pairNum];
        for(int i = 0; i < pairNum; i++){
            cin >> a >> b;
            if(a > b){
                pairs1[i] = b; pairs2[i] = a;
            } else {
                pairs1[i] = a; pairs2[i] = b;
            }
        }
        //Selection sort
        int temp, end;
        for(int x = 0; x < pairNum; x++)
        {
            for(int y = x + 1; y < pairNum; y++)
            {
                if(compare(pairs1[x], pairs2[x], pairs1[y], pairs2[y]) > 0)
                {
                    temp = pairs1[x]; pairs1[x] = pairs1[y]; pairs1[y] = temp;
                    temp = pairs2[x]; pairs2[x] = pairs2[y]; pairs2[y] = temp; 
                }
            }
        }
        //output
        bool isPaired[10] = {false};
        bool isFriend[10][10] = {false};
        for(int i = 0; i < studentNum; i++)
        {
            for(int j = i + 1; j < studentNum; j++)
            {
                for(int a = 0; a < pairNum; a++)
                {
                    if(pairs1[a] == i && pairs2[a] == j){
                        isFriend[i][j] = true;
                    }
                }
            }
        }
        if(studentNum < 2  || pairNum < (studentNum / 2)){
            results[repeat] = 0; continue;
        } else {
            results[repeat] = howMany(pairs1, pairs2, isPaired, isFriend, pairNum, studentNum);
        }
    }
    for(int i = 0; i < totalCase; i++){
        cout << results[i] << endl;
    }
    return 0;
}

int compare(int x1, int x2, int y1, int y2)
{
    if(x1 > y1)
    {
        return 1;
    }
    else if(x1 < y1)
    {
        return -1;
    }
    else if(x2 > y2)
    {
        return 1;
    }
    else if(x2 < y2){
        return -1;
    } else {
        return 0;
    }
}

int total = 0;
int howMany(const int* pairs1, const int* pairs2, bool isPaired[], bool isFriend[][10], int pairNum, int studentNum)
{
    bool success;
    success = false;
    for(int n = 0; n < studentNum; n++)
    {
        if(isPaired[n] == false)
        {
            success = false; break;
        }
        else{
            success = true;
        }
    }
    if(success)
    {
        return 1;
    }
    for(int i = 0; i < studentNum; i++)
    {
        for(int j = i+1; j < studentNum; j++)
        {
            if(!isPaired[i] && !isPaired[j] && isFriend[i][j])
            {
                isPaired[i] = true; isPaired[j] = true;
                total += howMany(pairs1, pairs2, isPaired, isFriend, pairNum, studentNum);
                isPaired[i] = false; isPaired[j] = false; 
            }
        }
    }
    return total;
}