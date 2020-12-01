#ifndef Partone_H
#define Partone_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Partone
{
  public :
	Partone(); //constructor
	~Partone(); //destructor
	void fill();
        void printLCS(int i, int j);
  private :
	string st1,st2; //two strings 
	int m,n;  //size
	int** numbers; //2D array dynamically allocated
};
#endif

