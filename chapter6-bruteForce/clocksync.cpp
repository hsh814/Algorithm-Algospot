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
    int max = 30;
    int clockNum = 16;
    int* clocks;
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
    void push(int myswitch)
    {
        for(int clock = 0; clock < 16; clock++)
        {
            if(switches[myswitch][clock] == 'o'){
                clocks[clock] += 3;
            }
        }
    }
    int count(int myswitch)
    {
        if(myswitch == 10){
            if(areSynced()){
                return 0;
            } else {
                return max + 1;
            }
        }
        int n = 0;
        for(int i = 0; i < 4; i++)
        {
            n = count(myswitch + 1);
            if(n > max){
                n = max + 1;
            } else {
                return i + n;
            }
            push(myswitch);
        }
    }
    int result()
    {
        int total = count(0);
        if(total > max){
            return -1;
        } else {
            return total;
        }

    }
    void show(){
        for(int i = 0; i < 16; i++){
            if(i % 4 == 0){
                cout << endl;
            }
            cout << clocks[i] << " ";
        }
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
    //output
    for(int i = 0; i < totalCase; i++){
        cout << results[i] << endl;
    }
    return 0;
}
