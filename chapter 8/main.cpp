#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;



/*
// Exercise 3
void fibonacci(int x, int y, vector<int>&v, int n);
void print( const vector<int>&x);
int main()
try{
int n=0,x=0,y=0;
cout << "How many number of elements do you wish\n"
"to have in the container \n";
cin >> n;
if(n<2)throw runtime_error("number of element must be >= 2");
cout << "Enter the first two elements of the fibonacci \n"
"sequence since it must have at least two elements\n";
cin >> x >> y;
vector <int> p;
fibonacci(x,y,p,n);
print (p);

return 0;
}
catch(runtime_error &e){
cerr << e.what() << endl;
}
void fibonacci(int x, int y, vector<int>&v, int n){
    int m=0;
v.push_back(x);
v.push_back(y);
while((n-2) >0){

          m=x+y;
          v.push_back(m);
          x=y;
          y=m;
          --n;
       }
}

void print(const vector<int>&x ){
for(int i=0; i< x.size(); ++i){
    cout << "  " << x[i] << " " ;
}
}
*/

//exercise 4

/*int main(){
    //The logic is that a time will come when y will go out of bound due to it m value + n value.
cout << "What he means is that print the maximum fibonacci number\n";
int x=1,y=2;
int m=3;
while(x<y){
    m=x+y;
    x=y;
    y=m;
}
cout << "\n\nLargest fibonacci is   " << x << endl;

}
*/
/*
//Exercise 5
Reversing the container of a vector by altering and not altering elements in it.
void Reverse1(const vector<int>&v);
void Reverse2(vector<int>&x);
int main()
{
vector<int>x;
x.push_back(1);
x.push_back(3);
x.push_back(5);
x.push_back(7);
x.push_back(9);

Reverse1(x);
Reverse2(x);
//cout << "\ncheck " << x[0] << endl;
return 0;
}
void Reverse1(const vector<int>&v){
 cout << "\n Reverse method \n";
    vector<int>Reversed;
    int p=0;
    p=(v.size()-1);
    for( int i=p; i>=0; --i){
        Reversed.push_back(v[i]);
    }
    for( int k=0; k<Reversed.size();++k){
        cout << "  " <<Reversed[k] << "  ";
    }
}

void Reverse2(vector<int>&x) // this affects the elements of the vector
{
    cout << "\n\n Swap method \n\n";
    int size=x.size()-1;
int check=0;
check = x.size()%2;
if(check==0){
for(int i=0; i < check; ++i){
    swap(x[i],x[size-i]);
 }
}
else if(check!=0){
for(int i=0; i< (x.size()/2); ++i){
    swap(x[i],x[size-i]);
}
}
for(int k=0; k< x.size();++k){
    cout << x[k] << "   ";
}
}
*/
/*
void print(const vector<string> &v, const vector<int> &a);
void sortedAge(const vector<string> &v, const vector<string>&n,const vector<int>&a, vector<int>&y);
int main(){
vector<string>name;
vector<int>age;
string n;
int a;
cout << "Enter the names of candidates and their age, enter (control Z) to stop. \n";
while(cin>>n>>a){
    name.push_back(n);
    age.push_back(a);
}
cout << "\n Names and ages:"  << endl;
print(name,age);
vector<string>Original=name;
vector<int> Sorted;
sort(name.begin(),name.end());

 sortedAge(name,Original,age,Sorted);
cout << "\nSorted names: " << endl;

print(name,Sorted);

}
void print(const vector<string> &v, const vector<int> &a){
for(int i=0; i<v.size();++i){
  cout << '(' << v[i] << ',' << a[i] << ")  " ;
  }
}

void sortedAge(const vector<string> &v, const vector<string>&n,const vector<int>&a,vector <int>&y)
{
  for(int i=0; i<v.size(); ++i)
    {
  for(int x=0; x<v.size();++x)
    {
    if(v[i]==n[x]) y.push_back(a[x]);

  }
   }
}
*/


//Exercise 2
void print(const string label,const vector<int>&v);
/*int main()
try{
   vector<int>values;
   string output="Output";
   int value;
   cout << "Kindly enter the list of integers, press . to stop" << endl;
   cout << "(e.g)1 2 3 4 5 ." << endl;
   while(cin >> value)
   {
     values.push_back(value);
   }
   print(output,values);

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
*/
void print(const string label,const vector<int>&v)
{
    for(int i=0; i<v.size(); ++i)
    {
        cout << label << '[' << i << ']' << " : " << v[i] << endl;
    }
}

// Exercise 3
//I could have used the reference in x,y and m variable
// but it's unnecessary since they hold very small value.
// this exercise used the print function in exercise 2,
// so i didn't comment it out.

/*void Fibonacci(int x, int y,vector<int>&v,int m);
int main()
try{
    int n=0,x=0,y=0,k=0;
    vector<int>fibonacci;
    cout << "This program prints the first n sequence of a fibonacci number\n";
    cout << "provided it is given the first and second value to start with\n";
        cout << "\nEnter the first and second number    ";

        if(cin >> x >> y)
        {
            cout << "\nHow many fibonacci numbers should be printed  \n";
            if(cin >> k)
            {
            Fibonacci(x,y,fibonacci,k);
            }
        }


    else throw runtime_error("wrong input format,please try again");
  return 0;
}
catch(runtime_error &e)
{
    cerr << e.what() << endl;
}
catch(...)
{
    cerr << "An error occured \n";
}
void Fibonacci(int x,int y,vector<int>&v,int m)
{
    string output="element";
    v.push_back(x);
    v.push_back(y);
    for(int i=0; i<m; ++i)
    {
       int k=x+y;
       v.push_back(k);
       x=y;
       y=k;
    }
    print(output,v);
}
*/

/*Exercise 4
int main()
{
    int x=1;
    int y=1;
    // first two fibonacci numbers are 1 and 1;
    while(x<=y)
    {
        int m=x+y;
        x=y;
        y=m;
    }
    cout << "[Maximum value]" << ' ' << x << endl;
    // the trick is that, when y exceed the maximum value type int can contain
    //y becomes negative(misbehaves)...since it's type int cant contain it.

    return 0;
}
*/
/*
//exercise 5
void reverse1(const vector<int>&v)
{
   vector<int>vec;
   for(int i=v.size()-1; i>-1;--i)
   {
    vec.push_back(v[i]);
   }
   cout <<"size: " <<  v.size() << endl;
   for(int i=0; i<vec.size(); ++i)
   {
       cout << '['<< i << ']' << vec[i] << endl;
   }
}

void reverse2(vector<int>v)
{
  int check=v.size()%2;
  if(!check)
  {
      for(int i=0; i<(v.size()/2);++i)
      {
          swap(v[i],v[v.size()-i-1]);
      }
  }
  else
  {
      for(int i=0; i<((v.size()-1)/2); ++i)
      {
          swap(v[i],v[v.size()-1-i]);
      }
  }
  for(int i=0; i<v.size(); ++i)
  {
      cout << '[' << i << ']' << v[i] << endl;
  }

}

int main()
{
 vector<int>m;
 int value=0;
 cout << "Kindly enter the list of values to be reversed\n";
 cout << "Press . to stop e.g 1 2 3 4 5 ."<< endl;
 while(cin>>value)
 {
     m.push_back(value);
 }
 cout << "Reverse 1 function\n" << endl;
 reverse1(m);
 cout << "\nReverse 2 function " << endl;
 reverse2(m);
}
*/
/*
//exercise 6
void reverse1(const vector<string>&v)
{
   vector<string>vec;
   for(int i=v.size()-1; i>-1;--i)
   {
    vec.push_back(v[i]);
   }

   for(int i=0; i<vec.size(); ++i)  // print the vectors.
   {
       cout << '['<< i << ']' << " " <<  vec[i] << endl;
   }
}

void reverse2(vector<string>v)
{
  int check=v.size()%2;
  if(!check)
  {
      for(int i=0; i<(v.size()/2);++i)
      {
          swap(v[i],v[v.size()-i-1]);
      }
  }
  else
  {
      for(int i=0; i<((v.size()-1)/2); ++i)
      {
          swap(v[i],v[v.size()-1-i]);
      }
  }
  for(int i=0; i<v.size(); ++i)
  {
      cout << '[' << i << ']' << " " << v[i] << endl;
  }

}


int main()
{
 vector<string>m;
 string value;
 cout << "Kindly enter the list of values to be reversed\n";
 cout << "Press . to stop e.g C++ john danny java ."<< endl;
 while(cin>>value && value!=".")
 {
     m.push_back(value);
 }
 cout << "Reverse 1 function\n" << endl;
 reverse1(m);
 cout << "\nReverse 2 function " << endl;
 reverse2(m);
 return 0;
}
*/
/*
// Exercise 7,8
void unsorted(const vector<string>&name,const vector<int>&age);
void sorted(vector<string>&name, vector<int>&age);
int main()
{
    cout << "Enter names of the five users, separated with space" << endl;
    vector<string>names;
    vector<int>ages;
    string name;
    int age=0;
    for(int i=0; i<5; ++i)
    {
        cin >> name;
        names.push_back(name);
    }

    cout << "Enter the corresponding age of each individuals" << endl;
    for(int i=0; i<names.size(); ++i)
    {
        cin >> age;
        ages.push_back(age);
    }

     unsorted(names,ages);
     sorted(names,ages);
    return 0;
}
void unsorted(const vector<string>&name,const vector<int>&age)
{
    if(name.size()==age.size())
    {
    for(int i=0; i<name.size(); ++i)
    {
        cout  << "(" <<  name[i] << "," << age[i] <<")" <<  endl;
    }
    }
    else throw runtime_error("The number of users and names are equal");
}
void sorted(vector<string>&name,vector<int>&age)
{
    vector<string>copied=name;
    vector<int>Age;

    sort(name.begin(),name.end());
    if(name.size()==age.size())
    {
        for(int i=0; i<name.size();++i)
        {
            for (int j=0; j<name.size(); ++j)
            {
                if(name[i]==copied[j])Age.push_back(age[j]);
            }
        }
    }
    else throw runtime_error("The number of users and names are not equal");


    cout << "Sorted data : " << endl;
    for(int i=0; i<name.size(); ++i)
    {
        cout << "("<<  name[i] << "," << Age[i] << ")" << endl;
    }
}


*/
//exercise 9
/*
int main ()
try{
    vector<int>weights;
    vector<int>heights;
    vector<int>price;
    int weight=0, height=0;
    int sum=0;
    cout << "Enter the weights and the height separated with a space  then enter . to print price\n";
    cout << "e.g 12 13, 15 13, .  to print" << endl;
    cout << "Kindly note that if a value is wrongly entered it will be discarded in the calculations\n";
    while(cin >> weight >> height)
    {
        weights.push_back(weight);
        heights.push_back(height);
        price.push_back(weight*height);
    }

    if(weights.size()==heights.size())
    {
       for(int i=0; i<price.size(); ++i)
    {
        sum+=price[i];
    }
    }
    else throw runtime_error ("Unequal number of weight and height provided \n");
    cout << "Sum of prices = " << sum << endl;

    return 0;
}
catch(runtime_error &e)
{
    cerr << e.what() << endl;
}
catch(...)
{
    cerr << "An error occured \n";
}
*/
/*
//Exercise 10
double maxv(const vector<double>&v);
int main()
{
    vector<double>values;
    double value=0;
    double largest=0;
    cout << "This program prints the largest value amongst list of numbers supplied\n";
    cout << "Enter the list of values \n";
    cout << "Enter . print values " << endl;
    while(cin >> value)
    {
        values.push_back(value);
    }
    //The first method is to use the sort(values.begin(),values.end()) .. the last element will be the largest.
    //but let us solve it .
    //let's make use of a very fast method at least having O(n) complexity. largest=values[0];
    largest= maxv(values);
    cout << "largest= " << largest << endl;
}
double maxv(const vector<double>&v)
{
    double largest=v[0];
    for(int i=0; i<(v.size()-1);++i)
    {
        if(largest <v[i+1])
        {
            largest=v[i+1];
        }
    }
    return largest;
}
*/
//Exercise 11
/*
void datas(vector<double>&e,double &smallest,double &largest,double &, double &);
int main()
{
    cout << "This program print the mean,median,maximum, and minimum value in a list of numbers\n";
    cout << "Kindly enter the numbers \n";
    cout << "press . to values required\n";
    double maximum=0;
    double minimum=0;
    double mean=0;
    double median=0;
    vector<double>values;
    double data=0;
    while(cin >>data) values.push_back(data);
    datas(values,minimum,maximum,mean,median);
    cout << "Mean= " << mean << " median =" << median << ' ';
    cout << "Minimum= " << minimum << " maximum =" << maximum << endl;
    return 0;
}
void datas(vector<double>&v, double &smallest,double &largest,double &mean, double &median)
{
// ideally we are not meant to use one function for all these different computations
// but since we are here for referencing, we had to
 mean=0;
int length= v.size()%2;
sort(v.begin(),v.end());  // sorts the element for getting the median
smallest= v[0]; // first element becomes the smallest.
largest=v[v.size()-1];

for(int i=0; i<v.size(); ++i)
{
    mean+=v[i];
}

mean=((mean)/v.size());
if(length)
{
    median=v[v.size()/2];
}
else {
    median=(v[v.size()/2] + v[(v.size() )/2 -1])/2;
}

}
*/
/*
vector<int>length(const vector<string>&v);
int main()
try{
    vector<string>values;
    vector<int>sizes;
    string value;
    cout << "This program prints the length of characters in a list of strings" << endl;
    cout << "Enter the list of strings \n";
    cout << "Enter . to print\n";
    while(cin >> value && value!=".") values.push_back(value);
    sizes=length(values);
    if(sizes.size()==values.size())
    {
        for(int i=0; i< values.size(); ++i)
        {
            cout << values[i] << "= " << sizes[i] << endl;
        }
    }
    else throw runtime_error("An error occured \n");
    return 0;
}
catch(runtime_error &e)
{
    cerr << e.what() << endl;
}
catch(...)
{
    cerr << "An unknown error occured \n";
}
vector<int> length(const vector<string>&v)
{
    vector<int>span;
    for(int i=0; i<v.size(); ++i)
    {
       span.push_back(v[i].size());
    }
    return span;
}
*/

// 14 yes we can for majorly small values.
