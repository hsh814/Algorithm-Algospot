#include<iostream>
#include<string>
#include<vector>

using namespace std;


int main()
{
    //input
    int totalCase;
    cin >> totalCase;
    int results[50];
    int temp;
    for(int repeat = 0; repeat < totalCase; repeat++)
    {
        int panelNum;
        cin >> panelNum;
        vector<int> panels;
        for(int i = 0; i < panelNum; i++)
        {
            cin >> temp;
            panels.push_back(temp);
        }
        cout << "입력 완료!" << endl;
        results[repeat] = result(panels, 0, panelNum);
    }
    //output
    for(int i = 0; i < totalCase; i++){
        cout << results[i] << endl;
    }
    return 0;
}
/*
3
7
7 1 5 9 6 7 3
7
1 4 4 4 4 1 1
4
1 8 2 2
*/