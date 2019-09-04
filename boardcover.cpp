#include<iostream>
#include<string>

using namespace std;


bool board[20][20];
int height, width;

void clearBoard()
{
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            board[i][j] = false;
        }
    }
}

int main()
{
    //input
    int totalCase;
    cin >> totalCase;
    int results[30];
    string temp = "";
    for(int repeat = 0; repeat < totalCase; repeat++)
    {
        clearBoard();
        cin >> height >> width;
        for(int i = 0; i < height; i++)
        {
            cin >> temp;
            for(int j = 0; j < width; j++)
            {
                if(temp[j] == '#')
                {
                    board[i][j] = true;
                }
            }
        }
        //output
        
    }
    for(int i = 0; i < totalCase; i++){
        cout << results[i] << endl;
    }
    return 0;
}
