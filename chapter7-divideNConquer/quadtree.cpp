#include<iostream>
#include<string>
#include<vector>

using namespace std;

class quad
{
public:
    int size;
    string quadstr = "";
    quad(string str)
    {
        quadstr = str;
        size = str.length();
    }
    string reverse(int& start)
    {
        char ch = quadstr[start];
        start++;
        if(ch == 'w' || ch == 'b'){
            return string(1, ch);
        }
        string first = reverse(start);
        string second = reverse(start);
        string third = reverse(start); 
        string fourth = reverse(start);
        return "x" + third + fourth + first + second;
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
        string quadtree = "";
        cin >> quadtree;
        quad qt(quadtree);
        int i = 0;
        results[repeat] = qt.reverse(i);
    }
    //output
    for(int i = 0; i < totalCase; i++){
        cout << results[i] << endl;
    }
    return 0;
}
