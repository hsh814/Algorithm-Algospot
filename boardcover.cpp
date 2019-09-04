#include<iostream>
#include<string>

using namespace std;


bool board[20][20];
const int cover[4][2][2] = {
    {{1, 0}, {0, -1}},
    {{1, 0}, {1, -1}},
    {{0, -1}, {1, -1}},
    {{-1, -1}, {0, -1}}
};
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

int countWhite()
{
    int whiteNum = 0;
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            if(!board[i][j]){
                whiteNum++;
            }
        }
    }
    return whiteNum;
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
        cin >> height >> width;
        if(height < 1 || height > 20 || width < 1 || width > 20){
            results[repeat] = 0; continue;
        }
        clearBoard();
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
        int whiteNum = countWhite();
        if(whiteNum > 50 || whiteNum % 3 != 0)
        {
            results[repeat] = 0; continue;
        }
        //output
        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
            {
                if(board[i][j]){
                    cout << "O";
                } else {
                    cout << "X";
                }
            }
            cout << endl;
        }
    }
    for(int i = 0; i < totalCase; i++){
        cout << results[i] << endl;
    }
    return 0;
}
