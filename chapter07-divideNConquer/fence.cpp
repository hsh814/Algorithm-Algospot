#include<iostream>
#include<string>
#include<vector>

using namespace std;



    int min(int a, int b){
        if(a < b) return a;
        else return b;
    }
    int max(int a, int b){
        if(a > b) return a;
        else return b;
    }
    int result(vector<int>& panels, int left, int right)
    {
        cout << left << " " << right << " | " ;
        if(left == right) return panels[right];
        int mid = (left + right) / 2;
        int maximum = max(result(panels, left, mid), result(panels, mid + 1, right));
        int lo = mid, hi = mid + 1, height = min(panels[lo], panels[hi]);
        int temp = 2 * max(panels[mid], panels[mid + 1]);
        while(left < lo || right > hi)
        {
            if(hi < right && (lo == left || panels[lo - 1] < panels[hi + 1])){
                hi++;
                height = min(height, panels[hi]);
            } else {
                lo++;
                height = min(height, panels[lo]);
            }
            temp = max(temp, (hi - lo + 1) * height);
        }
        return max(temp, maximum);
    }

int main()
{
    //input
    int totalCase;
    cin >> totalCase;
    int results[50];
    for(int repeat = 0; repeat < totalCase; repeat++)
    {
        int panelNum;
        cin >> panelNum;
        int temp;
        vector<int> panels;
        for(int i = 0; i < panelNum; i++)
        {
            cin >> temp;
            panels.push_back(temp);
        }
        for(int i = 0; i < panelNum; i++)
        {
            cout << panels[i] << ", ";
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