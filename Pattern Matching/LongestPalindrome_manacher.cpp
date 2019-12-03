// uses o(n) 

#include<bits/stdc++.h>
 using namespace std;

char* insertHash(string s) 
 {
 	int n = s.length() * 2 +1;
 	char *ret_s = new char[n];
 	for(int i=0;i<n;i++)
 	{
		 ret_s[2*i] = '#'; 
		 ret_s[2*i+1] = s[i]; 
	 }
	 return ret_s;
 }
 
 
 // to find lengths of sub palindromes for each center 
 // first checking the possibility from left and right bounds
 // start index = left most it can go
 // right index = rightmost
 int getPalLen(char *arr,int len,int i)
 {
 	int start = i - len -1;
 	int end = i+ len +1;
 	while(arr[start] && arr[end])
 	{
 		if(arr[start--] == arr[end++])    // go left and go right if you can and length is increased for both increments
 		 len++;							  // at once
 		else 
		  break; 
	 }
	 
	 return len;
 }

void findPal(string s)
 {
 	int n = s.length() * 2 +1;
 	
	 char *arr = insertHash(s);
 	 int lengths[n];
 	 
 	 for(int i=0;i<n;i++)
 	 	lengths[i] = 0;
 	 
 	 int center = 0, rightBoundary = 0, maxIndex = 0;
 	 
 	 for(int i=1;i<n;i++)
 	 {
 	 	int mirr = lengths[2*center -i];
 	 	
 	 	if(i<rightBoundary)
 	 	 lengths[i] = min(mirr,rightBoundary -i);
 	 	 
 	 	lengths[i] = getPalLen(arr,lengths[i],i);
 	 	
 	 	if(i + lengths[i] > rightBoundary)
 	 	{
 	 		center = i;
 	 		rightBoundary = i + lengths[i];	
		  }
		
		if(lengths[maxIndex] < lengths[i])
		{
			maxIndex = i;
		}
		 
	  }
 	 
 	 	 
		 int start = maxIndex - lengths[maxIndex];
		 int end = maxIndex + lengths[maxIndex];
 	 
 	 	for(int i=start;i<end/2;i++)
 	 	{
 	 		cout<<arr[2* i+1];
		  }
 	
 	
 }





int main()
{
findPal("babad");

}

