#include<bits/stdc++.h>
using namespace std;
void error(string s,string m="")
{

    throw runtime_error(s+m);
}

/*
exercise 1
bool lowercasefile(ifstream& is);
int main()
try{
    string name="input.txt";
    ifstream n{name};
    if(lowercasefile(n)cout << "Yayyy!! text conversion was successful"<< endl;
    else cout << "Unsuccessful text conversion, try again.\n";
return 0;
}
catch(runtime_error &e)
{
    cerr << e.what() << endl;
}
catch(...)
{
    cerr << "An error occured in the application \n";
}
bool lowercasefile(ifstream & is)
{
    if(!is)error(" file not opened ");
    ofstream ifs{"output.txt"};
    string output;
    for(char c; is.get(c);)
    {
        output+= tolower(c);
    }
    ifs << output;
    return;
}
*/
/*
exercise 2
bool word(string s);
bool check(string s,string);
int main()
{
    word("this");
    return 0;
}
bool word(string s)
{
    ifstream ifs("input.txt"); // name of file;
    if(!ifs)error("file not openened");
    int counter=0;
    while(!ifs.eof())
    {
        string l;
        getline(ifs,l);
        ++counter;
        if(check(s,l))cout << " word :" << s  << "  line:" << counter << endl;
    }
    return false;
}
bool check(string word,string line)  // line refers to each line of words in a text file gotten by getline.
{
  string s;
  stringstream wordline{line};
  while(wordline >>s)  // turns to false when we get to eof(end of stream);
  {
      if(s==word)return true;
  }
  wordline.clear();
  return false;
}
*/
/*
exercise 3
string changefile(istream& is);
bool isVowel(const char a);
int main()
try{
    string filename="input.txt";
    ifstream ifs{filename};
    string vowels;
    vowels=changefile(ifs);
    cout << "Extracted vowels: " << vowels << endl;
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
string changefile(istream& is)
{
    string vowels;
    if(!is)error("file not opened");
    for(char m; is >>m;)  // keep reading the file until EOF.
    {
        if(isVowel(m))vowels+=m;
    }
    return vowels;
}
bool isVowel(const char m)
{
    switch(tolower(m))
    {
        case 'a':case 'e':case 'i':case 'o':case 'u':return true;
        default:return false;
    }
}
*/
/*
// i did not really completed this, i was actually feeling sleepy here
don't know if i will remember about this, goodnight!
//exercise 5;
string  convert(string &s);
int main()
{
    string s;
    cout << "Enter the string \n";
    getline(cin,s);
    string m=convert(s);
    cout << "converted string is " << m << endl;
    return 0;
}
string convert(string &s)
{   string converted;
  int counter=0;
    for(char &x:s)
    {   counter++;
        x=tolower(x);
        const char k=(int)39;  // this is used to represent ' as a character value. it was daunting to use ''', compiler could not interpret it well.
        switch(x)
        {
        case '.':case ';' : case ',': case '?': case '-':
            {
                x=' ';
                converted+=x;
                break;
            }
            case k:
                {
                    x='o';
                    converted+=x;
                    break;
                }
            default: converted+=x;
        }
    }
    return converted;
}
*/
//exercise 6.
/*string  convert(string &s);
int main()
{
    string s;
    cout << "Enter the string \n";
    getline(cin,s);
    string m=convert(s);
    cout << "converted string is " << m << endl;
    return 0;
}
string convert(string &s)
{   string converted;
    for(char &x:s)
    {
        const char k=(int)39;  // this is used to represent ' as a character value. it was daunting to use ''', compiler could not interpret it well.
        switch(x)
        {
        case '.':case ';' : case ',': case '?': case '-':case k:
            {
                x=' ';
                converted+=x;
                break;
            }
            default: converted+=x;
        }
    }
    return converted;
}
*/
// Exercise 7, convert it to vectors of text to make a dictionary. exercise 8, ios-base::binary is the difference. - should be underscore.
/*
//Exercise 10.
vector<string>split(const string&,const string& );
int main()
{
    vector<string>substrings;
    string s,s1;
    cout << "Enter a two strings \n";
    cin >> s >> s1;
    substrings=split(s,s1);
    for(int i=0; i<substrings.size();++i)
    {
        cout  << substrings[i] << "  " <<  endl;
    }
    return 0;
}
vector<string>split(const string&x, const string&w)
{
    vector<string>substrings;
    string s;
    for(int i=0; i<x.size();++i)
    {
        s+=x[i] + w;
        substrings.push_back(s);
    }
    return substrings;
}*/
/*
//Exercise 11
vector<string>split(const string& );
int main()
{
    vector<string>substrings;
    string s;
    cout << "Enter a string \n";
    getline(cin,s);
    substrings=split(s);
    for(int i=0; i<substrings.size();++i)
    {
        cout  << substrings[i] << "  " <<  endl;
    }
    return 0;
}
vector<string>split(const string&x)
{
    vector<string>substrings;
    string s;
    for(int i=0; i<x.size();++i)
    {
        s+=x[i];
        substrings.push_back(s);
    }
    return substrings;
}
*/
/*
//Exercise 12;
int main()
{
    string filename="input.txt";
    string reversed;
    ifstream ifs{filename};
    if(!ifs)error("could not open file name ");
    ofstream ofs{"output.txt"};
    for(char r; ifs.get(r);)reversed+=r;
    for(int i=reversed.size()-1; i>-1; --i)
    {
        ofs << reversed[i];
    }
    return 0;
}
*/
/*
// Exercise 13.
int main()
{
    string filename="input.txt";
    ifstream ifs{filename};
    if(!ifs)error("could not open file name ");
    vector<string>words;
    for(string s; ifs >> s;)words.push_back(s);
    ofstream ofs{"output.txt"}; // output filename;
    for(int i=words.size();i >-1; --i)
    {
       ofs << words[i] << ' ';
    }
    return 0;
}
/*
//exercise 14
void characterclass(ifstream &is);

int main()
try
{
    string filename="input.txt";
    ifstream ifs{filename};
    characterclass(ifs);
    return 0;
}
catch(runtime_error &e)
{
    cerr << e.what() << endl;
}
void characterclass(ifstream &is)
{
    if(!is)error("file not opened");
    int alp=0,digit=0,space=0;
    for(char z; is.get(z);)
    {
        if(isalpha(z))++alp;
        else if(isdigit(z))++digit;
        else if(isspace(z))++space;
    }
    ofstream ofs{"output.txt"};
    ofs << "alphabet: " << alp <<endl;
    ofs << "Digit: " << digit << endl;
    ofs << "White-space characters: " << space << endl;

}
*/

// exercise 15 just use this  ofs << setw(width) << scientific << d/
/*
//exercise 16
void readfile(ifstream&);
void formatfile(vector<int>&);
int main()
{
  string filename="input.txt";
  ifstream ifs{filename};
  readfile(ifs);
}
void readfile(ifstream& is)
{

    if(!is)error("file not opened");
    vector<int>numbers;
    for(int n; is >>n;)numbers.push_back(n);  // read till eof.
    sort(numbers.begin(),numbers.end());
    formatfile(numbers);
}
void formatfile(vector<int>&v)
{
    int counter=1;
    ofstream ofs{"output.txt"};
    for(int i=1; i<v.size();++i)
    {
        if(v[i-1]==v[i])
        {
            ++counter;
        }
        else {
            if(counter>1)
            {
                ofs <<  v[i-1] << "   " << counter << endl;
                counter=1;
            }
            else
            {
                ofs << v[i-1] << endl;
            }
            if(i==v.size()-1 && v[i]!=v[i+1])
                {

                    ofs << v[i] << endl;
                }

        }
    }
}
*/
