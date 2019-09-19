#include <bits/stdc++.h>
using namespace std;


void arrBuilder(char *s,int *arr)
{
    
    int i=1,j=0;
    arr[0] = 0;
    while(i <= strlen(s))
    {
        if(s[i] == s[j])
        {
            arr[i] = j+1;
            i++;j++;
        }
        else if(j != 0)
        {
            j = arr[j-1];
        }
        else if(j==0)
        {
            arr[i] = 0;
            i++;
        }
  //  cout<<i<<"-"<<j<<"--"<<arr[i]<<endl;
    
    }
    
}

void pattern(char *str,char *patt)
{
    
    
    int i=0,j=0;
    int lstr = strlen(str);
    int lpat = strlen(patt);
    
    int arr[lstr];
    arrBuilder(str,arr);

    while(i< lstr)
    {
        if(str[i] == patt[i])
        {
            i++;j++;
        }

        if(i == lpat)
        {
            cout<<"found pattern at : "<<i-j<<endl;
            j = arr[j-1];
        }
        else if(i<lstr && patt[j] != str[i]) 
        {
            if(j!=0)
             j = arr[j-1];
            else
             i += 1; 
        
        }
    }
}

int main()
{
    char str[1000],pat[1000];
    cin>>str;
    cin>>pat;
    int arr[strlen(str)];
    pattern(str,pat);
    // for(int i=0;i<str.length();i++)
    //     cout<< arr[i]<<endl;
}