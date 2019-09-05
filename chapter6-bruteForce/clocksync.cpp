#include<iostream>
#include<string>

using namespace std;

char switches[10][17] = {
    "oooxxxxxxxxxxxxx",
    "xxxoxxxoxoxoxxxx",
    "xxxxoxxxxxoxxxoo",
    "oxxxooooxxxxxxxx",
    "xxxxxxoooxoxoxxx",
    "oxoxxxxxxxxxxxoo",
    "xxxoxxxxxxxxxxoo",
    "xxxxooxoxxxxxxoo",
    "xoooooxxxxxxxxxx",
    "xxxoooxxxoxxxoxx"
};
class clocksync
{
public:
    int clockNum = 16;
    int* clocks;
    int total = 0;
    clocksync(int* inputClocks)
    {
        clocks = inputClocks;
    }
    bool checkValid()
    {
        if(clocks[8] != clocks[12] || clocks[14] != clocks[15]){
            return false;
        } else {
            return true;
        }
    }
    bool areSynced()
    {
        bool synced = true;
        for(int i = 0; i < 16; i++)
        {
            if(clocks[i] % 12 != 0){
                synced = false; break;
            }
        }
        return synced;
    }
    void count()
    {

    }
    int result()
    {
        return -1;
    }
};

int main()
{
    //input
    int totalCase;
    cin >> totalCase;
    int results[30];
    int clocks[16];
    for(int repeat = 0; repeat < totalCase; repeat++)
    {
        for(int input = 0; input < 16; input++){
            cin >> clocks[input];
        }
        clocksync cs(clocks);
        if(cs.checkValid() == false){
            results[repeat] = -1; continue;
        }
        results[repeat] = cs.result();
    }
    for(int i = 0; i < totalCase; i++){
        cout << results[i] << endl;
    }
    return 0;
}
