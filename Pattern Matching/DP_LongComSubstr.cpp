#include<bits/stdc++.h>
 using namespace std;
int main()
{
string s1,s2;
cin>>s1>>s2;

int l1 = s1.length();
int l2 = s2.length();

int mat[l1+1][l2+1];

for(int i=0;i<l1;i++)
 for(int j=0;j<l2;j++)
  mat[i][j] = 0;

int max =0;
for(int i =1;i<=l1;i++)
 {
 	for(int j=1;j<=l2;j++)
 	 {
 	 	if(s1[i-1] == s2[j-1])
 	 	{
 	 		mat[i][j] = mat[i-1][j-1] +1; 
 	 		
			if(max<mat[i][j])
				max = mat[i][j];
				
			cout<<max<<endl;	
		}
		
		
		
		
	  }
 }
	
	cout<<max<<endl;

}

