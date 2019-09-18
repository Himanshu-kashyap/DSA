#include <bits/stdc++.h>
using namespace std;


int * arrBuilder(string s,int *arr)
{
    
    int i=1,j=0;
    arr[0] = 0;
    while(i <= s.length() )
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

int main()
{
    string str;
    cin>>str;
    int arr[str.length()];
    arrBuilder(str,arr);
    for(int i=0;i<str.length();i++)
        cout<< arr[i]<<endl;
}