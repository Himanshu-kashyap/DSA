#include<bits/stdc++.h>
 using namespace std;
int* kmp_arr(string s)
{
	int arr[s.length()];
	int i =1,j=0;
	while(i!= s.length())
	{
		if (s[i] == s[j])
		{
			arr[i] = arr[i-1]+1;
			i++;j++;
			
		}
		else if(s[i] != s[j])
		{
			j = arr[i-1];
			arr[i] = 0;
			i++;
			
			
		}
		cout<<i<<"-"<<j<<"---"<<arr[i]<<endl;
		
		
	}
	
	return arr;
		
}



int main()
{
 
 string str;
 cin>>str;
 int *ptr = kmp_arr(str);
 
 for(int i=0;i<str.length();i++)
 	cout<<ptr[i]<<"\t";


return 0;


}


