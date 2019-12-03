#include<bits/stdc++.h>
 using namespace std;


struct greaters{
	bool operator()(const int &a,const int &b) const{
		return a>b;
	}
};


int main()
{
	int arr[] = {12, 11, 13, 5, 6, 7}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
  
    make_heap(arr[0],arr[n],greaters() );
  
    cout << "Sorted array is \n"; 
    for (int i=0;i<n;i++)
    	cout<<arr[i]<<endl;
	

}

