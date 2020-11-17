#include<bits/stdc++.h>
using namespace std;

// an almost real vector of doubles:
template<typename T>
class Vector {
    /*
    invariant:
        for 0<=n<sz elem[n] is element n
        sz<=space;
        if sz<space there is space for (space-sz) doubles after elem[sz-1]
    */
private:
    size_t sz;           // the size
    T* elem;     // pointer to the elements (or 0)
    size_t space;        // number of element plus number of free slots

public:
    Vector() : sz(0), elem(nullptr), space(0) { }  // default constructor.
    Vector(size_t s) :sz(s), elem(new T[s]), space(s)
    {
        for (size_t i=0; i<sz; ++i) elem[i]=0;    // elements are initialized to 0.
    }
    Vector(initializer_list<T>db):
    sz(db.size()),elem{new T[sz]}
        {
          copy(db.begin(),db.end(),elem);
        }

    Vector(const Vector&);            // copy constructor
    Vector(Vector&&);                 // move constructor
    Vector& operator=(const Vector&); // copy assignment
    Vector& operator =(Vector &&);    // move assignment.
    ~Vector() { delete[ ] elem; }     // destructor
    T& operator[ ](size_t n) { return elem[n]; } // for non const-vectors.
    const T& operator[ ](size_t n) const { return elem[n]; } // for const vectors.
    size_t Size() const { return sz; }
    size_t capacity() const { return space; }
    void Resize(size_t newsize);         // growth
    void Push_back(const T& d);
    void reserve(size_t newalloc);
};

//------------------------------------------------------------------------------
template<typename T>
void Vector<T>::reserve(size_t newalloc)
{

    if (newalloc<=space) return;             // never decrease allocation
    T* p = new T[newalloc];        // allocate new space
    for (size_t i=0; i<sz; ++i) p[i] = elem[i]; // copy old elements
    delete[ ] elem;                          // deallocate elements.
    elem = p;
    space = newalloc;
}

//------------------------------------------------------------------------------
template<typename T>
void Vector<T>::Resize(size_t newsize)

{
    reserve(newsize);
    for (size_t i=sz; i<newsize; ++i) elem[i] = 0;    // initialize new elements
    sz = newsize;
}

//------------------------------------------------------------------------------
template<typename T>
void Vector<T>::Push_back(const T& d)
// increase vector size by one; initialize the new element with d
{
    // no more free space: get more
    if (space==0)reserve(8);
    else if (space==sz)reserve(2*space);
    elem[sz]=d;    // add d at end
    ++sz;            // increase the size (sz is the number of elements)
}

//------------------------------------------------------------------------------
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& a)
{
    if (this==&a) return *this;    // self-assignment, no work needed

    if (a.sz<=space) {             // enough space, no need for new allocation
        for (size_t i = 0; i<a.sz; ++i) elem[i] = a.elem[i]; // copy elements
        sz = a.sz;
        return *this;
    }

    T* p = new T[a.sz];  // allocate new space
    for (int i = 0; i<a.sz; ++i) p[i] = a.elem[i];    // copy elements
    delete[ ] elem;                // deallocate old space
    space = sz = a.sz;             // set new size
    elem = p;                      // set new elements
    return *this;                  //  return a self-reference
}

//------------------------------------------------------------------------------

int main()
{
    //for integers.
//--------------------------------------------------------------------------
    Vector<int>numbers;
    for(unsigned int i=0; i<200;++i)numbers.Push_back(i);
    for(unsigned int i=0; i<numbers.Size();++i)cout << numbers[i] << endl;
//-------------------------------------------------------------------------


//for strings
//--------------------------------------------------------------------------
    Vector<string>names;
    string filler="hey yo this is johnson dawodu daniel speaking to you all";
    stringstream name{filler};
    for(string n; name >> n;)names.Push_back(n);
    for(unsigned int i=0; i<names.Size();++i)cout << names[i] << " ";
//--------------------------------------------------------------------------



//---------------------------------------------------------------------------
//for characters .
    stringstream anothername{"Ok all i want to do is to test for letters here "};
    Vector<char>letters;
    for(char n; anothername.get(n);){letters.Push_back(n);} // i copied terminating characters also i.e spaces and the likes.
    for(unsigned int i=0; i<letters.Size();++i)cout << letters[i] << endl;
    return 0;

}
//------------------------------------------------------------------------------
