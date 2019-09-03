#include<iostream>
#include<string>

using namespace std;


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
        for(int k = 0; k < pairNum; k++){
            cout << pairs1[k] << " " << pairs2[k] << ", ";
        }
    }

    return 0;
}

