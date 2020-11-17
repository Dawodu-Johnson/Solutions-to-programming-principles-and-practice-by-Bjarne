#include<iostream>
#include<string>
#include<fstream>
using namespace std;
void error(string s="",string m="")
{
    throw runtime_error (s+m);
}
/*void failed(istream &, const string error);
void error(string s="",string m="")
{
    throw runtime_error (s+m);
}
int addNumbers(istream &,const string &filename);
void print(const int sum){cout << "Sum of numbers = " << sum << endl;}
int main()
try{
    int answer=0;
    string name="input.txt";
    ifstream ifs{name}; // opens the file.
    answer=addNumbers(ifs,name);
    print(answer);
    return 0;
}
catch(runtime_error &e)
{
    cerr << e.what() << endl;
}
catch (...)
{
    cerr << "An unknown error occured \n";
}
int addNumbers(istream &ifs, const string &filename)
{
    int sum=0;
    int a=0;
  if(!ifs)error("file not opened ",filename);
  while(ifs >> a )
  {
      sum+=a;
  }
  failed(ifs,"A non integer caused the program to stop");
  return sum;
}
void failed(istream &ifs,string const message)
{
    if(ifs.fail())
    {
        ifs.clear();
        char a;
        ifs >>a;
        if(isalpha(a))error(message);
    }
    return;
}
*/
//exercise 2
//solution for this is in the textbook already
//Exercise 8.
void concatenatefiles(istream &ifs,istream &ifs1, ostream &ofs);
int main()
try{
    string input="input.txt";
    string input1="input1.txt";
    string output="output.txt";
    ifstream ifs{input};
    ifstream ifs1{input1};
    ofstream ifs2{output};
    concatenatefiles(ifs,ifs1,ifs2);
    cout << "Successful! kindly check the " << output << " to see result \n";
return 0;
}
catch(runtime_error &e)
{
    cerr << e.what() << endl;
}
catch(...)
{
    cerr << "An error occured " << endl;
}
void concatenatefiles(istream &ifs,istream & ifs1, ostream &ifs2)
{
    char a=0;
    if(!(ifs || ifs1 || ifs2))error("a file is not opened ");
  while(ifs.get(a)) // file 1;
  {
      ifs2 << a;
  }
  if(ifs.eof())  // when done/
  {
        while(ifs1.get(a)) // file 1;
         {
           ifs2 << a;
         }
  }
}
//Exercise 11.
/*
double sum(istream & ifs)
{
    // The logic of this function is to check whether the value is safe to be read by integer by making use of char to check first.
 char a=0;
 double value=0;
 double get=0;
    while(ifs >> a)  // enter all as characters.
    {
        if(isdigit(a))  // check if the beginning is a number;
        {
            ifs.unget(); // put it back;
            ifs >> get;   // it is now safe to read by an int.
            value+= get;  // now sum it.
        }       // repeat.
    }
    return  value;
}
int main()
{
    string name="input.txt";
    double answer =0;
    ifstream ifs{name};
    if(!ifs)error("file not opened ", name);
    answer=sum(ifs);
    cout << "Sum of all numbers in the file is = " << answer << endl;
        return 0;
}
*/
