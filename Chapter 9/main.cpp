#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include "Date.cpp"
using namespace std;
//Exercise 2
void error(string s,string m="")
{
    throw runtime_error(s+m);
}

/*
class NamePairs
{
private:
    vector<string> Name;
    vector<double> Ages;
public:

    NamePairs():Ages(0){}//default constructor.
    void ReadNames();
    double ReadAges();
    void print();
    void SortNames();

};

void NamePairs:: ReadNames()
{
  string name;
  cout << "Kindly provide a name and the corresponding age separated with a whitespace\n";
  cout << "E.g Johnson 22 \n";
  cout << "Enter  \"noname\"  without quotes to stop(print)\n\n";
  while(cin >> name && name!="noname")
  {
      Name.push_back(name);
      Ages.push_back(ReadAges());
  }


}
double NamePairs::ReadAges()
{
 double age;
 if(cin >>age)return age;
 else error("Invalid age ");
}
void NamePairs::print()
{


   if(Name.size()==Ages.size())
   {
       for(int i=0; i<Ages.size();++i)
       {
           cout << endl << '(' << Name[i] << ',' << Ages[i] << ')'<< endl;

       }
   }
   cout << "\n\n";
}

void NamePairs:: SortNames()
{
  vector<string>storage=Name;
  vector<double>newAge;
  sort(Name.begin(),Name.end());
  for(int i=0;i<Name.size();++i)
  {
      for(int j=0; j<Name.size();++j)
      {
        if(Name[i]==storage[j])
        {
            newAge.push_back(Ages[j]);
            break;
        }
      }
  }
  Ages=newAge;
  cout << "Sorted----Data ";
}


int main()
try{
  NamePairs p;
  p.ReadNames();
  p.print();
  p.SortNames();
  p.print();
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


//exercise 3.
//re-modification of exercise 2
/*
class NamePairs
{
private:
    vector<string> Name;
    vector<double> Ages;
public:

    NamePairs():Ages(0){}//default constructor.
    bool operator == (const NamePairs&)const;
    bool operator != (const NamePairs&)const;
    friend ostream& operator << (ostream &l, const NamePairs &p);
    void ReadNames();
    double ReadAges();
    void print();
    void SortNames();
};

void NamePairs:: ReadNames()
{
  string name;

  while( cin >> name && name!="noname")
  {
      Name.push_back(name);
      Ages.push_back(ReadAges());
  }


}
double NamePairs::ReadAges()
{
 double age;
 if(cin >>age)return age;
 else error("Invalid age ");
}
ostream& operator << (ostream& l, const NamePairs &p)
{


   if(p.Name.size()==p.Ages.size())
   {
       for(int i=0; i<p.Ages.size();++i)
       {
           l << endl << '(' << p.Name[i] << ',' << p.Ages[i] << ')'<< endl;

       }
   }
   l << "\n\n";
   return l;
}
bool NamePairs :: operator ==(const NamePairs &p)const
{
  if(Name.size()==p.Name.size() && Ages.size()==p.Ages.size())
  {
    //proceed
  for(int i=0; i<Name.size();++i)
  {
    if(Name[i]==p.Name[i] && Ages[i]==p.Ages[i])continue;
    else return false;
  }
  return true;
}
else return false;
}
bool NamePairs:: operator !=(const NamePairs &p)const
{
  return !(*this==p);

}
void NamePairs:: SortNames()
{
  vector<string>storage=Name;
  vector<double>newAge;
  sort(Name.begin(),Name.end());
  for(int i=0;i<Name.size();++i)
  {
      for(int j=0; j<Name.size();++j)
      {
        if(Name[i]==storage[j])
        {
            newAge.push_back(Ages[j]);
            break;
        }
      }
  }
  Ages=newAge;
  cout << "Sorted----Data \n\n";
}


int main()
try{
  cout << "Kindly provide a name and the corresponding age separated with a whitespace\n";
  cout << "E.g Johnson 22 \n";
  cout << "Enter  \"noname\"  without quotes to stop(print)\n\n";
   NamePairs p,q;
   p.ReadNames();
   cout << "Second data \n\n";
   q.ReadNames();
   if(p==q) cout << "\n Objects are equal \n";
   if(p!=q) cout << "Objects are not equal \n";

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
//Exercise 4 basic.
//Exercise 5
/*
//Exercise 5-9,
we will come back to the exercises later.
they are easy but somethings arent clearly stated here.
class Book
{
  public:
  enum Genre{fiction, nonfiction, periodical,biography,children};
  Book(string a,string t,string i,Genre g,Date &m):title(t),author(a),isbn(validateISBN(i)),gen(g),date(m){}
  string Title()const {return title;}
  string Author()const {return author;}
  string Isbn()const{ return isbn;}
  Genre genre()const {return gen;}
  bool operator ==(const Book &b)const;
  bool operator !=(const Book &b)const;
  friend ostream& operator << (ostream&, const Book &);
  friend ostream& operator << (ostream &, const Genre &g);

private:
  string title,author,isbn;
  string validateISBN(string &x)const;
  Date date;
  Genre gen;
};

string Book::validateISBN(string &x)const
{
  if(x.size()>4) error ("invalid ISBN ", "max size of ISBN is 4");
  if(isdigit(x[0]) && isdigit(x[1]) && isdigit(x[2]) && (isalpha(x[3])|| isdigit(x[3])))
  {
    return x;
  }
  else error("Invalid ISBN -> ", x);
}
bool Book :: operator ==(const Book &b)const
{
  return (isbn ==b.Isbn());
}
bool Book:: operator !=(const Book &b)const
{
  return !(*this ==b);
}
ostream& operator << (ostream& os, const Book &b)
{
  os << "Author: " << b.Author()<< '\n'
  << "Title: " << b.Title() << '\n'
  << "ISBN: " << b.Isbn() << '\n'
  << "Genre: " << b.genre() << '\n'
  << "Date: " << b.date << '\n';
  return os;
}
// when you declare an enum in a class
// it automatically becomes of this form enum class
// hence you have to refer to the class when using any value of the enum
ostream& operator << (ostream &os, const Book::Genre &g)
{
  switch(g)
  {
  case Book::fiction:
      os << " fiction ";
      return os;

  case Book::nonfiction:
      os << " fiction ";
      return os;
   case Book::periodical:
      os << " periodical ";
      return os;
   case Book::biography:
      os << " biography ";
      return os;
    case Book::children:
      os << " children ";
      return os;
  }
}

class Patron
{
private:
  string username;
  int cardnumber;
  int fees;
  bool Owefees()
  {
    if(fees<0)return true;
    return false;
  }
public:
  Patron(string s, int c, int f):username(s),cardnumber(c),fees(f){}
  int CardNumber()const {return cardnumber;}
  int Fees()const {return fees;}
  string Name()const{return username;}
  void setfee(int s);
};
void Patron::setfee(int s)
{
  fees=s;
}
class Library
{
public:
  struct Transaction
  {
    Book b;
    Patron p;
    Date d;
  };
  void AddBooks(const Book &b);
  void AddPatrons(const Patron &b);
  void CheckOut();
  void printPatrons(const Patron& p);
private:
  vector<Book>book;
  vector<Patron>patron;
  Transaction transaction;
};

void Library:: AddBooks(const Book &b)
{
  book.push_back(b);
}
void Library::AddPatrons(const Patron &p)
{
  patron.push_back(p);
}
void CheckOut()
{

}
int main()
try{
  Date h;
  Book first("Bjarne Stroustrop", "C++ Programming Language","117x",Book::fiction,h);
  cout << first;
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
