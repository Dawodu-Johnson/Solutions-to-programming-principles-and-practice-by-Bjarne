#ifndef CACULATOR-HEADER_H_INCLUDED
#define CACULATOR-HEADER_H_INCLUDED
#include<vector>
using namespace std;
class Token
{
public:
    char kind;
    double value;
    string name;
    Token(char k): kind(k),value(0){} //{} indicates that nothing is to be done than initializing.
    Token(char k, double v): kind(k),value(v){} // this is for numbers
    Token (char c, string s) : kind(c), name(s){}  // gives name a type and the corresponding value
};


class Trigonometry
{
public:
const double pi=3.1415926535;
const double degree =180/pi;
double toRads(double x);
double SCT(char,double);
double ASCT(char, double);
Token type(string t);
double bound(double x);
};


class TokenStream  // this is responsible for filling the tokens,putting back tokens
{
private:
    Token buffer;  // Represents stored a stored token this will be initialized with the constructor function.
    bool full;     // indicates whether a token is present or not.
public:
    TokenStream(): buffer(0),full(false){} // false(no token yet),buffer needs to be initialized with at least a parameter(based on Token Definition)
    Token get();  // used to get Tokens
    void putBack(Token t);  // used to putBack tokens to the stream.
    void ignore(char c);
};

class Variable
{
    public:
    string name;
    double value;
    bool change;
    Variable(string n, double v,bool type): name(n),value(v),change(type) {}
};

class Symbol_table
{
public:
    vector<Variable>varTable;
    void setValue(string s, double v);
    double getValue(string s);
    double defineName(string s, double value,bool type);
    bool isDeclared(string s);
    double Declaration(Token &t,TokenStream &ts);
};
#endif

