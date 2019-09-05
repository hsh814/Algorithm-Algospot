#include<iostream>
#include<string>

using namespace std;


bool board[20][20];
const int cover[4][2][2] = {
    {{1, 0}, {0, 1}},
    {{1, 0}, {1, 1}},
    {{0, 1}, {1, 1}},
    {{1, 0}, {1, -1}}
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

bool outOfRange(int x, int y, int shape, int i)
{
    int tempx = x + cover[shape][i][0];
    int tempy = y + cover[shape][i][1];
    if(tempx < height && tempx > -1 && tempy > -1 && tempy < width)
    {
        return false;
    }
    else
    {
        return true;
    }
    
}
bool tryShpae(int x, int y, int shape)
{
    for(int i = 0; i < 2; i++)
    {
        int tempx = x + cover[shape][i][0];
        int tempy = y + cover[shape][i][1];
        if(outOfRange(x, y, shape, i) || board[tempx][tempy]){
            return false;
        } 
    }
    for(int j = 0; j < 2; j++)
    {
        int tempx = x + cover[shape][j][0];
        int tempy = y + cover[shape][j][1];
        board[tempx][tempy] = true;
    }
    board[x][y] = true;
    return true;
}
void removeShape(int x, int y, int shape)
{
    board[x][y] = false;
    for(int i = 0; i < 2; i++)
    {
        int tempx = x + cover[shape][i][0];
        int tempy = y + cover[shape][i][1];
        board[tempx][tempy] = false;
    }
}
int countCover()
{
    int x = -1, y = -1;
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            if(board[i][j] == false){
                x = i; y = j;
                break;
            }
        }
        if(x > -1){
            break;
        }
    }
    if(x == -1)
    {
        return 1;
    }
    if(x == (height - 1))
    {
        return 0;
    }
    int total = 0;
    for(int shape = 0; shape < 4; shape++)
    {
        if(tryShpae(x, y, shape))
        {
            total += countCover();
            removeShape(x, y, shape);
        }
    }
    return total;
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
        results[repeat] = countCover();
    }
    for(int i = 0; i < totalCase; i++){
        cout << results[i] << endl;
    }
    return 0;
}
