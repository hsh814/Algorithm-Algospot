#include <iostream>
#include <string>

using namespace std;

bool hasWord(const string& str, int x, int y);
bool outOfRange(int x, int y);

string *boggle = new string[5];

int main()
{
    int totalCase;
    cin >> totalCase;
    for(int repeat = 0; repeat < totalCase; repeat++){
        for(int i = 0; i < 5; i++){
            cin >> boggle[i];
        }

        int wordsNum;
        cin >> wordsNum;
        string* words = new string[wordsNum];
        for(int j = 0; j < wordsNum; j++){
            cin >> words[j];
        }
        bool* results = new bool[wordsNum];

        for(int k = 0; k < wordsNum; k++)
        {
            results[k] = false;
            for(int x = 0; x < 5; x++){
                for(int y = 0; y < 5; y++){
                    if (hasWord(words[k], x, y)){
                        results[k] = true; break;
                    }
                }
                if(results[k]){
                    break;
                }
            }
        }
        for(int i = 0; i < wordsNum; i++){
            if(results[i] == true){
                cout << words[i] << " YES\n"; 
            } else {
                cout << words[i] << " NO\n";
            }
        }
    }

    return 0;
}

int dx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int dy[8] = {1, 0, -1, -1, -1, 0, 1, 1};

bool hasWord(const string& str, int x, int y)
{
    if(x > 4 || x < 0 || y > 4 || y < 0){
        return false;
    } else if (boggle[y][x] == str[0]) {
        if(str.length() <= 1){
            return true;
        }
        string newStr = str.substr(1, str.length());
        //cout << newStr << endl;
        for(int i = 0; i < 8; i++){
            if(hasWord(newStr, x + dx[i], y + dy[i])){
                return true;
            }
            else { 
                false;
            }
        }
    }
    return false;
}
