#include<iostream>
#include<string>
#include<vector>

using namespace std;

class fence
{
public:
    int* panels; int panelNum;
    fence(int* panel, int num)
    {
        panels = panel; panelNum = num;
    }
    int result()
    {
        return 0;
    }
};

int main()
{
    //input
    int totalCase;
    cin >> totalCase;
    string results[50];
    for(int repeat = 0; repeat < totalCase; repeat++)
    {
        int panelNum;
        cin >> panelNum;
        int* panels = new int[panelNum];
        for(int i = 0; i < panelNum; i++)
        {
            cin >> panels[i];
        }
        fence f(panels, panelNum);
        results[repeat] = f.result();
        delete panels;
    }
    //output
    for(int i = 0; i < totalCase; i++){
        cout << results[i] << endl;
    }
    return 0;
}
