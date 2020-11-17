#include <bits/stdc++.h>
using namespace std;
// part of the practices of  software engineering principles using C++.

void error(const string &s)
{
    throw runtime_error(s);
}
using namespace std;
template <typename T>
class Array
{
private:
  T* elem;
  size_t t;
public:
  explicit Array(size_t mag);  // constructor.
  Array(const Array& arr); // copy constructor.
  Array(initializer_list<T>val);  // for initials.
  Array(Array&&); // move ocnstructor.
  ~Array();
  T& operator [](size_t index);  // for non constant array.
  const T& operator [] (size_t index)const; // for constant array.
  Array& operator =(const Array& arr);
  Array& operator =(Array&& arr);
  size_t getsize()const{return t;}
};

template<typename T>
Array<T>::Array(size_t mag):elem{new T[mag]},t(mag){}

template<typename T>
Array<T>::Array(const Array& arr):t(arr.t)
{
  for(size_t i=0; i<t; ++i)elem[i]=arr.elem[i];
}
template<typename T>
Array<T>:: Array(initializer_list <T> arr)
{
  t=arr.size();
  elem = new T[t];
  copy(arr.begin(),arr.end(),elem);
}
template <typename T>
Array<T> ::Array(Array&& arr): t{arr.t},elem{arr.elem}
{
  arr.elem=nullptr;
}
template<typename T>
Array<T>::~Array()
{
  delete [] elem;
}
template<typename T>
T& Array<T>:: operator [] (size_t index)
{
  if(index>=t)error("index is out of range ");
  return elem[index];
}
template<typename T>
const T& Array<T> :: operator [] (size_t index)const
{
  if(index>=t)error("index value is out of range ");
  return elem[index];
}
template<typename T>
Array<T>& Array<T>:: operator =(const Array& rhs)
{
  if(&rhs==this)return *this;  // prevent self assigment.
  delete [] elem; // delete the previous elements in the array.
  t=rhs.t;         // set a new size.
  elem = new T[t];    // create a new space for the array to be filled next
  //for(size_t i=0; i<t;++i)elem[i]=rhs.elem[i];
  copy(rhs.elem,rhs.elem+rhs.t,elem);
  return *this;
}
template<typename T>
Array<T>& Array<T>::operator =(Array &&arr)
{
  if(this ==&arr)return *this;
  delete [] elem;
  t=arr.t;
  elem = new T[t];
  elem= arr.elem;
  arr.elem=nullptr;
  return *this;
}
int main()
try{
   /* Array<double> arr{100.1,1000,100,99.99};
    Array <string>names(20);
    string sentence="Ok i want to input this values inside the array now";
    stringstream input{sentence};

    for( unsigned int i=0; i<arr.getsize();++i)cout << arr[i] << endl;
    size_t i=0;
    for(string n; input>>n;)
    {
      names[i]=n;
      ++i;
    }

    for(unsigned int i=0; i<names.getsize();++i)cout << names[i] << " ";
    cout << input.str() << endl;*/

    return 0;
}
catch(runtime_error &e){cerr << e.what() << endl;}
catch(...){cerr << "An unknown error occured \n";}
