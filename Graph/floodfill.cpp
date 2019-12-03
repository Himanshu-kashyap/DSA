#include<bits/stdc++.h>
 using namespace std;
   
  int mat[9999][9999];
  bool visited[9999][9999];
  
  bool flood(int mat[9999][9999],int m,int n,int sx,int sy,int dx,int dy,bool visited[9999][9999])
  {
  	if(sx == dx and sy == dy)
  		return true;
  		
  	if(sx<0 || sy<0)
  		return false;
  	
	
	if(sx > m || sy>n)	
	   return false;
	   
	if(visited[sx][sy] == true)
	 return false;   
	 
	 
	 
	if(mat[sx][sy] == 0)    // obstruction
		return false;

	visited[sx][sy] = true;
	
	if(flood(mat,m,n,sx+1,sy,dx,dy,visited))
		return true;
	if(flood(mat,m,n,sx,sy+1,dx,dy,visited))
		return true;
	if(flood(mat,m,n,sx-1,sy,dx,dy,visited))
		return true;
	if(flood(mat,m,n,sx,sy-1,dx,dy,visited))
		return true;			
  		
  	return false;	
  }
  
  
//  void floodfill(int *mat,int m,int n)//(int source_x,int source_y,visited,int p,int q,int *mat,int dest_x,int dest_y)
//  {
//  	for(int i=0;i<m;i++)
//  	 {
//	   for(int j=0;j<n;j++)
//  	  {
//		cout<< *((mat+i*n)+j)<<" ";
//	  }
//	  cout<<endl;
// 	 }
//  	
//  }
//  
  
  int main()
   {
   	int m,n; //dimensions of matrix
   	
   	int src,dest;
   	
   	 
	cin>>m>>n;
	//int mat[m][n];
	//bool visited[m][n];
	
	memset(visited,false,sizeof visited[0][0] * m * n);
	memset(mat,-1,sizeof mat[0][0] *m*n);
   	 for(int i=0;i<m;i++)
   	  {
		 for(int j=0;j<n;j++)
   	 	   {
			   cin>>mat[i][j];
		   }
	  } 
	  
	  //floodfill((int*) mat,m,n);
	 cout<< flood(mat,m,n,0,0,m-1,n-1,visited) <<endl;
//	 bool ff = flood(mat,m,n,0,0,m,n,visited);
//	 cout<<ff<<endl;
	  return 0;
	  
	   
   	 
   }
