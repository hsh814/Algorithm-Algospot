#include <iostream>
#include <string>
#include <vector>
#include <string.h>

#define MAX 101

using namespace std;


char cache[MAX][MAX];
int n;
string wildcard, str;
bool match(int w, int s)
{
    char& ret = cache[w][s];
    if(ret != -1) { return ret; }
    while(s < str.size() && w < wildcard.size() && (wildcard[w] == '?' || wildcard[w] == str[s]))
    {
        w++; s++;
    }
    if(w == wildcard.size()) 
    {
        ret = (s == str.size());
        return ret; 
    }
    if(wildcard[w] == '*')
    {
        for(int skip = 0; s + skip <= str.size(); skip++)
        {
            if(match(w + 1, s + skip)) 
            { 
                ret = 1;
                return ret; 
            }
        }
    }
    return 0;
}
int compareString(string& s1, string& s2)
{
    int n;
    if(s1.size() < s2.size()){
        n = s1.size();
    } else {
        n = s2.size();
    }
    for(int i = 0; i < n;i++)
    {
        if(s1[i] != s2[i]){
            if(s1[i] > s2[i]) { return -1; }
            return 1;
        }
    }
    if(s1.size() > s2.size()) { return -1; }
    else if(s1.size() < s2.size()) { return 1; }
    return 0;
}
void sortString(string* files, int num)
{
    for(int i = 0; i < num; i++)
    {
        for(int j = i + 1; j < num; j++)
        {
            if(compareString(files[i], files[j]) < 0)
            {
                string s = files[i];
                files[i] = files[j];
                files[j] = s;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string* results[10];
    int res[10];
    int totalCase;
    cin >> totalCase;
    for(int repeat = 0; repeat < totalCase; repeat++)
    {
        //cout << repeat << "th repeat!\n";
        cin >> wildcard;
        cin >> n;
        string* files = new string[n];
        int index = 0;
        char *c = new char[wildcard.size() + 1];
        int temp = 0;
        for (int i = 0; i < wildcard.size(); i++)
        {
            if (wildcard[i] == '*' && wildcard[i + 1] == '*')
            {
                if (c[temp] == '*')
                {
                    i++;
                    continue;
                }
                c[temp] = wildcard[i];
                i++;
                continue;
            }
            c[temp] = wildcard[i];
            temp++;
        }
        c[temp] = '\0';
        wildcard = c;
       // cout << wildcard << " input\n";

        for(int y = 0; y < n; y++)
        {
            memset(cache, -1, sizeof(cache));
            cin >> str;
            if(match(0, 0))
            {
                //cout << "matched! " << str << endl;
                files[index++] = str;
            }       
        }
        sortString(files, index);
        results[repeat] = files;
        res[repeat] = index;
    }
    for(int i = 0; i < totalCase; i++)
    {
        for(int j = 0; j < res[i]; j++)
        {
            cout << results[i][j] << '\n';
        }
    }
    return 0;
}