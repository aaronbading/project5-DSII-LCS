//Aaron Bading

#include "partone.h"
#include <fstream>
#include <string>
Partone::Partone()
{

ifstream in("twoStrings.txt");
getline(in, st1);
getline(in,st2);
m=st1.size();
n=st2.size();
in.close();
//dynamically allocated 2d array of ints based on size m and n 
//m= rows and n=cols yields a mxn matrix.
//we must allocate m+1 space and n+1 space due to the extra 
 numbers = new int*[m+1];
for(int i=0; i<m+1; i++)
{numbers[i]=new int[n+1];}
cout << endl << endl << "Part one: " << endl;
fill();
cout << " String 1: " << st1 << endl;
cout << " String 2: " << st2 << endl;
cout << " LCS : " ;
printLCS(m,n);
cout << "\n Length of LCS:  " << numbers[m][n] << endl;
}

Partone::~Partone()
{
	/*
for (int i = 0; i <m+1; i++)
delete[] numbers[i];

delete[] numbers; */

}

void Partone::fill()
{
// initialize 
numbers[0][0]=0;
for(int i=1; i<=m;i++)
numbers[i][0]=0;
for(int j=1; j<=m;j++)
numbers[0][j]=0;
// filling the array
for(int i=1; i<=m;i++)
{
		for(int j=1; j<=n;j++)
		{
		
		if(st1.at(i-1)==st2.at(j-1))
		{numbers[i][j]=numbers[i-1][j-1] +1;}	
		else
		{	
			if(numbers[i-1][j]>=numbers[i][j-1])
			{numbers[i][j]=numbers[i-1][j];}
			else
			{numbers[i][j]=numbers[i][j-1];}

		}

		}

}

/*  //printing the array
for(int i=0; i<=m; i++)
{
	
for(int j=0; j<=n; j++)
{cout << numbers[i][j] << " ";
}
cout << endl;
}
*/

}

//Recursive function that prints the LCS
void Partone::printLCS(int i, int j)
{
	//base case
	if(i==0||j==0)
	return;
	else
	{
		//match
		if(st1.at(i-1)==st2.at(j-1))
		{printLCS(i-1,j-1);
		cout << st1.at(i-1)<< " ";}
		else
		{//no match
			if(numbers[i-1][j]>=numbers[i][j-1])
			{printLCS(i-1,j);} //move up
			else
			{printLCS(i,j-1);} //move left}
		}
	}	

}

