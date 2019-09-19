// uses a simple hash function to calculate hash of string and pattern
// 1st step is to HASH(pattern)
// 2nd is to calculate HASH(substr(string,len(pattern))
// 3rd is to match both hashes if not matches then sub str[i]





#include<bits/stdc++.h>
 using namespace std;

int hashPat(string s,int p)
{
	int len = s.length();
	int d = 0;
	for (int i=0;i<len;i++)
	{
		d += (int(s[i]) - 96) * pow(p,i);   // using ascii value of pattern
	}
	return d;
}


int main()
{
string s,pat;
cin>>s>>pat;
int prime = 3;

int hashp = hashPat(pat,prime);
//cout<<"hash pattern : "<<hashp<<endl;

int patlen = pat.length();
int strlength = s.length();

int i=0;
string temp = s.substr(0,patlen);  // for initialization of string matching just as naive

int hashstr = hashPat(temp,prime);

while(i != strlength)
{
	if(hashstr == hashp)
	{
		//cout<<s.substr(i,i+patlen-1)<<"substring of patt"<< endl;
		if(s.substr(i,i+patlen-1) == pat)
		{
			cout<<"pattern found at index : "<<i<<endl;
			return 0;
		}
		
	}
	else{  // this else is used to calculate next hash instead of naive parsing we use this
		// cout<<i<<s[i]<<":"<<s[i+patlen]<<" --> "<<hashstr<<" --> "<<hashp<<endl;
		
		hashstr -= (int(s[i]) - 96);
		hashstr /= prime;
		hashstr += pow(prime,patlen-1) * (int(s[i+patlen] - 96));
		i++;	
			
	}
}

cout<<"No pattern"<<endl;
return 0;

}

