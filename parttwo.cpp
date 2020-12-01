//Aaron Bading

#include "parttwo.h"

const int POSLEN = 20;
const int LINELEN = 120;
int positions[POSLEN];
int totStrings = 0;

Parttwo::Parttwo()
{

 int numstrings; 
  computeLengths();
  showPositionsArray();
 
  ifstream in("multiStrings.txt");
  in>> numstrings;
  in.seekg(0);
  in.close();
  display(true,numstrings);//initial display is true
  directAccess();
}

void Parttwo::computeLengths()
{
  ifstream in;
  char line[LINELEN];
  in.open("multiStrings.txt");
  if(in.fail())
  {cout << "Fail" << endl;}
  
     positions[0] = 0; 
  while(in.getline(line, LINELEN))
  {
    positions[totStrings] = strlen(line)+1;
   // cout << "number of chars = " << positions[totStrings++] << endl;
   positions[totStrings++];
    line[strlen(line)] = '\0';
   // cout << "string = " << line << endl;
  }
  in.close();
}

void Parttwo::directAccess()
{
   int i, j, currentPos = positions[0]; 
   char line[LINELEN];
  ifstream in;
  in.open("multiStrings.txt");
   in.seekg(currentPos);

   
   string st1,st2;
   for(i = 1; i < totStrings-1; i++)
   {
     in.getline(line, LINELEN);
     line[strlen(line)] = '\0';
    cout << endl; 
    // cout << "this string [" << line << "]" << endl;
     st1=line;

     //now st1 holds the string to be compared to 
     display(false,i); // this is the ongoing display prints the number and amount of slashes	     
     for(j = i+1; j < totStrings; j++)  
     {	
       in.getline(line, LINELEN);
       line[strlen(line)] = '\0';
       
      // cout << "  compared with [" << line << "]" << endl;
       st2=line;
       cout << analysis(st1,st2) << "  " ; // this will 
     }
     currentPos += positions[i];
     in.seekg(currentPos);
   }
   cout << endl << endl;
}

void Parttwo::showPositionsArray()
{
  int i;
  for(i = 0; i < totStrings; i++)
  {
    //cout << " line " << i << " length of string on that line " << positions[i] << endl;
  }
}

char Parttwo::analysis(string st1, string st2)
{
int m,n;
m=st1.size();
n=st2.size();
//dynamically allocated 2d array of ints based on size2  and n
int** bucket;
 bucket = new int*[2];
for(int i=0; i<2; i++)
{bucket[i]=new int[n+1];}
	//initiailize to n=1 bcause we want one more than the size
for(int i=0;i<n+1;i++)
{bucket[0][i]=0;}
bucket[1][0]=0;

//compare the two strings lenghts and determine which one is shorter.
string shorter, longer;
if(st1.size()<st2.size())
{shorter=st1;
longer=st2;}
else
{
shorter=st2;
longer=st1;
}
//compute the LCS of the two strings.
for(int i=0; i<m;i++)
{
//generate row two
bucket[1][0]=0;
char comp =st1.at(i);

      for(int j=1; j<n;j++)
	{
	if(comp==st2.at(j))
	{bucket[1][j]=bucket[0][j-1]+1;}
	else
	     {
	       if(bucket[0][j]>=bucket[1][j-1])
	      {bucket[1][j]=bucket[0][j];}
	      else
	      {bucket[1][j]=bucket[1][j-1];}
	
	    }
	
          }
//added section
/*
cout << " PRINTING " << i << endl;
//printing the array
for(int i=0; i<2; i++)
{

for(int j=0; j<=n; j++)
{cout << bucket[i][j] << " ";
}
cout << endl;
}
*/
//make row two row one
	for(int i=0;i<n+1;i++)
	{bucket[0][i]=bucket[1][i];}
	bucket[1][0]=0;

	
}
//cout << "LCS " << bucket[1][n-1];
int lcs = bucket[1][n-1]; // this is the lcs ....there is some uncertainty here, but when is there ever certainty.



//compare lcs value to the length of shorter string
double k,h; // there are going to be the lengths of the shorter and longer strings
k=shorter.size();
h=longer.size();
//first condition
//lcs is at least 90% of length of shorter.
//length of shorter string is withing 10% of length of longer string
//meaning that length of shorter string must me greater than or equal 90% of length of longer ?????
if((lcs>=(.9*k)&& (k>=.9*h)))
{return 'H';}
// lcs is at least 80% of length of shorter string
// short string is withing 20% of length of longer string
if( (lcs>=(.8*k)&& (k>=.8*h)))
{return 'M';}
//lcs is 50 % of length of shorter string
//length of shorter string is within 40 % of length of longer string.
if( (lcs>=(.5*k)&& (k>=.6*h)))
{return 'L';}

return 'D';
}
void Parttwo::display(bool decision,int howmany)
{
string temp;
	if(decision)
	{//intial display
	ifstream in("multiStrings.txt");
	int num;
	in>>num;
		cout << endl<< endl; 
		cout << "Part Two : " << endl;
		//enter more information about the conditions here.......
		//
		//
		for(int i=1; i<=num+1; i++)
		{
		getline(in,temp);
			if(i!=1)
			{cout << i-1 << " = " << temp << endl;}
		}
	in.clear();
	in.seekg(0);
		cout << endl;
		cout << "  " ;
		 for(int i=1; i<=howmany; i++)
      		  {
        
     		   cout << i << "  " ;

                  }
	}
	else
	{//ongoing display
	cout << howmany <<" ";
        for(int i=1; i<=howmany; i++)
         cout <<"/ "<< " " ;
                  
	}

}
