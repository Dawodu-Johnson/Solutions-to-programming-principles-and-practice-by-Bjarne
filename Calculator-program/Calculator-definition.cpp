#include<iostream>
#include<string.h>
#include<vector>
#include<cmath>
#include"declarations.h"

using namespace std;


void error(string s)
{
    throw runtime_error(s);
}

void error(string s, string y)
{

    throw runtime_error(s+y);
}
//Implementation of the tokenStream definition.

double factorial(double f)
{
    if(f<0) error("negative factorial is above this scope");
    if(f<=1) return 1;
    return f*factorial(f-1);
}
double squareroot(double x)
{
    if(x<0)error("root of a negative number is not allowed");
    return sqrt(x);
}
double power(double x, double y)
{
    if((int)y!=y) error ("Floating point exponent not allowed for base");
    else return pow(x,y);
}
//Declaration of three functions beneath.

double Expression(TokenStream &ts);
double Term(TokenStream &ts);
double Primary(TokenStream &ts);
Trigonometry trig;

void TokenStream::putBack(Token t)  // used to store a Token only
{
    if(full) error("putback() already full");

    full=true;

    buffer=t;
}
/*
   The sole reason for defining the Token get() in Token Stream class is because after declaring it
   1) it becomes a member of the class hence can have access to the buffer token.

    assuming the token get() was defined in the token class then manipulating the buffer stream and full from the token class
    to the tokenStream stream class will need some inheritance stuff to be possible.
*/


Token TokenStream:: get()
{
    // now  the get() have access to the full and buffer

    if(full)
    {
        full=false;
        return buffer;
    }

    char ch;
    cin >> ch;  // ----(1)

   /* cin.get(ch);
    if(ch!='\n')
    {
       //Uncommenting this section,commenting ----(1) on line 84 and setting print='\n' is the solution to chapter 5.
       //
        cin.putback(ch);
        cin >> ch;
    }*/

    switch(ch)
    {
    case '+' :case '-' :case '*' :case '/' :
    case '(' : case ')' : case 'q' : case';':
    case '{': case '}': case '!': case '%': case '=':
    case ',': //case '\n':
         return Token(ch);  // they were grouped together since they return a single type of token.


    case '.':case '0':case '1':case '2':case '3':
    case '4':case '5':case '6':case '7':
    case '8':case '9':
        {   // the braces is placed here because there is a declaration of variable within the case.

            cin.putback(ch);
            double value;
            cin >> value;
            return Token(number,value);
            /* This is a very nice technique which predicts a number or character based on the first input.
            1) if it is not a "." or a "number" use the first grouped cased category.
            2) else since we have gotten the first value to decide what it is, we put it back to the stream and finally
            read all once and for all.*/
        }
        default:
            if (isalpha(ch))
            {
                string s;
                s+=ch;
                while(cin.get(ch)&&(isalpha(ch)|| isdigit(ch) || ch=='_'))s+=ch;
                cin.putback(ch);   // using cin.putback() since ch is not of type Token
                if(s==delckey)return Token(let);
                else if(s==constant)return Token(c);
                else if (s==root) return Token(r);
                else if(s==powers)return Token(p);
                else if(s==instruct)return Token(help);
                return trig.type(s);  // either returns a Token represing the trigonometry function or a Token representing a name
            }

          else  error("Invalid input, please retry again");

}

}
void TokenStream :: ignore(char c)
{
    if(full && buffer.kind)
    {
        full=false;
        return;
    }
     full=false;
     char ch=0;
    while(true){
     cin >> ch;  // it was possible to read even after an error was thrown because the stream is not actually in a failed state;
     if(ch==c)return;
    }
}

// Variable functions
Symbol_table symbol;

double Symbol_table:: getValue(string s)
{
    for(int i=0; i<varTable.size();++i)
    {
        if(s==varTable[i].name) return varTable[i].value;
    }
    error("Undefined Variable ", s);

}

void Symbol_table :: setValue(string s, double v)
{
    for(int i=0; i<varTable.size(); ++i)
    {
        if(varTable[i].name==s)
        {
            if(varTable[i].change)varTable[i].value=v;
            else error("attempt to change a constant failed");
             return;   // used to terminate a function of type void
        }
    }
error("Undefined variable ", s);
}



// now we need to express (grammar rules )in terms of functions
// where each grammar is delegated to one task.
// They are arranged in order of function calls.
// The expression must always here from the term function which must from here from the primary function.

/*Note that grammars define a particular way in which the functions call one another
  highest bindings should be called first
  but note how we make the call to start initially from the lowest function expression
  so we can finally walk our way through to the highest binding to make decisions first and come back to the lowest precedence.
*/
double Primary(TokenStream &ts)  // it helps in refining the get() so that only numbers are returned via it.
{

    Token t = ts.get();
    switch (t.kind) {
    case '(':           // handle '(' expression ')'
        {
            double d = Expression(ts);
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            return d;
        }
    case '{':
        {
            double d = Expression(ts);
            t= ts.get();
            if(t.kind!='}') error("Expected a '}' ");
                return d;
       }

    case number: return t.value;
    case name:
        {  //either setting or getting can be done here

            Token next=ts.get();
            if(next.kind=='=')
            {
                double value=Expression(ts);
                symbol.setValue(t.name,value);
               return value;
            }
            else
            {
            ts.putBack(next);
            return symbol.getValue(t.name);
            }
        }
    case si:case co: case ta:  // trig functions sin,cos and tan

        {
            char trigF=t.kind;
            t=ts.get();
            if(t.kind=='(')
            {
                double value= Expression(ts);
                t=ts.get();
                if(t.kind==')')
                return trig.SCT(trigF,value);
                else
                {
                ts.putBack(t.kind);
                error("Expected a closing ", ")");
                }
            }
            else error("Expected an opening  ", "(");

        }
    case art: case ac: case as:
        {
            char trigF= t.kind;  // stores the type of case initially collected.
            t=ts.get();
            if(t.kind=='(')
            {
                double value=Expression(ts);
                t=ts.get();
                if(t.kind==')') return trig.ASCT(trigF,value);
                else
                {    ts.putBack(t.kind);
                    error("Expected a closing ", ")");
                }
            }
            else error("Expected an opening  ","(");
        }

    case r:

        {
            t=ts.get();
            if(t.kind=='('){
                double value= Expression(ts); // for simplicity,clarity and efficiency statement isn't placed here.
                t=ts.get();
                if(t.kind==')') return squareroot(value);
                else error("closing parenthesis", " ) is required here");
            }

        }
        case p:
            {
                t=ts.get();
                if(t.kind=='(')
                {
                    double i=0;
                    double x= Expression(ts);
                    t= ts.get();
                    if(t.kind==',')i= Expression(ts);
                    else error(",", "required");
                    t=ts.get();
                    if(t.kind==')') return power(x,i);
                    else error("closing parenthesis",") is required");
                }
            }
    case '-': return -(Primary(ts));
    default:
        error("primary expected");
    }
}

double Factorial(TokenStream &ts)
{
    double left= Primary(ts);  // fetches a number.
    Token t= ts.get();      // returns a token type.

    switch(t.kind)
    {
        case '!': return factorial(left);
        default : ts.putBack(t); return left;
    }
}
double Term(TokenStream &ts)
{
  double left = Factorial(ts);
    Token t = ts.get(); // get the next token from token stream

    while(true) {

    switch (t.kind) {
        case '*':
           left *= Factorial(ts);
           t = ts.get();
            break;
        case '/':
            {
                double d = Factorial(ts);
                if (d == 0) error("dividing by zero is not allowed, infinite value");
                left /= d;
                t = ts.get();
                break;
            }
        case '%':
            {
                double d=Term(ts);
                int m= int(left);
                if( m!=left) error("% is not valid for floating point numbers");
                int k= int(d);
                if(k!=d) error("% is not valid for floating point numbers");
                if(k==0) error("Division by zero");
                left = m%k;
                t= ts.get();
                break;
            }

        default:
            ts.putBack(t);        // put t back into the token stream
            return left;         // returns if the operator in the cases are not part of the options.
        }
    }
}

double Expression(TokenStream &ts)
{
    double left = Term(ts);      // read and evaluate a Term
    Token t = ts.get();        // get the next token from the primary , the primary gets the token inputed in the main

    while(true) {
        switch(t.kind) {
        case '+':
            left += Term(ts);    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= Term(ts);    // evaluate Term and subtract
            t = ts.get();
            break;
        default:
            ts.putBack(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }

    }
}

bool Symbol_table :: isDeclared(string s)
{
    for(int i=0; i< varTable.size();++i)
    {
        if(varTable[i].name==s)return true;
    }
     return false;

}
double Symbol_table :: defineName(string s, double v,bool type)
{
    if(isDeclared(s)) error(s," declared twice");
    varTable.push_back(Variable(s,v,type));
    return v;
}

double Symbol_table:: Declaration(Token &m,TokenStream &ts)
{// handles the name and the '=';

    char check= m.kind;
    Token t=ts.get();
    if(t.kind!=name)error("Expected a variable name");
    string name=t.name;
    t=ts.get();
    if(t.kind!='=') error("= missing in the declaration of ",name);
    double v=Expression(ts);
    defineName(name,v,check==let);
    return v;
}

double Statement(TokenStream &ts)
{

    Token t= ts.get();
    switch(t.kind)
    {
      case let: case c:
          return symbol.Declaration(t,ts);

      default:
        ts.putBack(t);
        return Expression(ts);
    }
}
