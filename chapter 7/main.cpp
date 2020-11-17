/*
    This program implements a basic expression calculator.
    Input from cin; output to cout.

    I will be glad to call this Algorithm(Grammar).

    Calculation:
        Statement
        Print
        Quit
        Calculation Statement

    Statement:
        Declaration
        Expression

    Declaration:
        "let" Name "=" Expression
        "const" Name "=" Expression

    Print:
        ;

    Quit:
        q

    Expression:
        Term
        Expression + Term
        Expression - Term
    Term:
        Primary
        Term * Primary
        Term / Primary
        Term % Primary
    Primary:
        Number
        Name
		Name = Expression
        ( Expression )
        - Primary
        + Primary
    Number:
        floating-point-literal
	Name:
		[a-zA-Z][a-zA-Z_0-9]*	// a letter followed by zero or more letters, underscores, and digits
		Enhanced To make use of classes.
*/
//Implementation and writing of codes of chapter 7 exercise from 1 upto 8.
#include<iostream>
#include<vector>
#include<string.h>
#include<stdexcept>
#include<math.h>
using namespace std;

void error (string n,string s){
throw runtime_error(n+s);
}
void error(string s){
throw runtime_error(s);}
//------------------------------------------------------------------------------
const char root='s';
const char que ='q';
const char POW='p';
const char number = '8';    // t.kind==number means that t is a number Token
const char print  = ';';    // t.kind==print means that t is a print Token
const char name   = 'a';    // name token
const char let    = 'L';    // declaration token
const char con    = 'C';
const  char  help='H';                // const declaration token
const string declkey = "#";		// declaration keyword
const string constkey = "const";	// const keyword
const string prompt  = "> ";
const string quit="exit";
const string result  = "= "; // used to indicate that what follows is a result
const string sroot="sqrt";
const string power="pow";

//------------------------------------------------------------------------------

class Token {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value
    string name;      // for names: name itself
    Token(char ch)             : kind(ch), value(0)   {}
    Token(char ch, double val) : kind(ch), value(val) {}
    Token(char ch, string n)   : kind(ch), name(n)    {}
};

//------------------------------------------------------------------------------

class Token_stream {
public:
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
    void ignore(char c);      // discard tokens up to an including a c
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};
class Variable {
public:
    string name;
    double value;
	bool var;	// variable (true) or constant (false)
    Variable (string n, double v, bool va = true) :name(n), value(v), var(va) { }

  };

class Symbol_table{
public:
    double get_value(string s);    // member function likewise the ones beneath.
    void set_value(string s, double d);
    bool is_declared(string var);
    vector<Variable>var_table;
    double declaration(Token k); // having a type does not guarantee access to Token just a function acting on it.
    double define_name(string s, double val, bool var);
    };
    Symbol_table symbol;
//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
:full(false), buffer(0)    // no Token in buffer
{
}

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{

    if (full) error("putback() into a full buffer");
    buffer = t; // copy t to buffer
    full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

Token Token_stream::get() // read characters from cin and compose a Token
{

    if (full) {
              // check if we already have a Token ready
        full=false;
        return buffer;
    }

    char ch;
    cin>> ch;

          // note that >> skips whitespace (space, newline, tab, etc.)
    switch (ch) {
    case print:
    case que:
    case '(':
    case ')':
    case '+': //cout << "I returned a + in the stream\n";
    case '-':
    case '*':
    case '/':
    case '%':
    case '=':
    case ',':
    case 'H':
        return Token(ch);
    // let each character represent itself
    case '#': return Token(let);
    case '.':             // a floating-point literal can start with a dot
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':    // numeric literal
    {
        cin.putback(ch);
        double val;
        cin >> val;
        return Token(number,val);
        cout<< "i returned val =" << val << endl;
    }
    default:
        if (isalpha(ch)) {	// start with a letter or based on strings.
            string s;
            s += ch;
            while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch=='_')) s+=ch; // letters digits and underscores

            cin.putback(ch);

            if (s == constkey) return Token(con); // keyword "const"
            if(s==sroot) return Token(root);
            if(s==power)return Token(POW);
            return Token(name,s);
        }

        error("Bad token");
    }
}

//------------------------------------------------------------------------------
Token_stream ts;

void Token_stream::ignore(char c)
    // c represents the kind of a Token
{
    // first look in buffer:
    if (full && c==buffer.kind) {
        full = false;
    return;
    }
    full = false;

    // now search input:
    char ch = 0;
    while (cin>>ch)
        if (ch==c)return;
}

//------------------------------------------------------------------------------

//Token_stream ts;        // provides get() and putback()

//------------------------------------------------------------------------------


//------------------------------------------------------------------------------


//------------------------------------------------------------------------------

double Symbol_table :: get_value(string s)
    // return the value of the Variable names s
{
    for (int i = 0; i<var_table.size(); ++i)
        if (var_table[i].name == s) return var_table[i].value;
    error("get: undefined variable ", s);
}

//------------------------------------------------------------------------------

void Symbol_table::set_value(string s, double d)
    // set the Variable named s to d
{
    for (int i = 0; i<var_table.size(); ++i)
        if (var_table[i].name == s) {
			if (var_table[i].var==false) error(s," is a constant");
            var_table[i].value = d;
            return;
        }
    error("set: undefined variable ", s);
}

//------------------------------------------------------------------------------

bool Symbol_table :: is_declared(string var)
    // is var already in var_table?
{
    for (int i = 0; i<var_table.size(); ++i)
        if (var_table[i].name == var) return true;
    return false;
}

//------------------------------------------------------------------------------

double Symbol_table::define_name(string s, double val, bool var)
    // add (s,val,var) to var_table
{
    if (symbol.is_declared(s)) error(s," declared twice");
    var_table.push_back(Variable(s,val,var));
    return val;
}

//------------------------------------------------------------------------------

double expression();    // declaration so that primary() can call expression()

//------------------------------------------------------------------------------

// deal with numbers and parentheses
double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':           // handle '(' expression ')'
        {
            double d = expression();
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            return d;
        }
    case number:
        return t.value;    // return the number's value
    case name:
		{
			Token next = ts.get();
			if (next.kind == '=') {	// handle name = expression
				double d = expression();
				symbol.set_value(t.name,d);
				return d;
			}
			else {
				ts.putback(next);		// not an assignment: return the value
				return symbol.get_value(t.name); // return the variable's value
			}
		}
    case root: { //for square root function in math library.
          Token next= ts.get();
          if(next.kind!='(') error("expected a ", "(");
          double d= expression();
          if(d<0) error("Sqrt of a negative value is undefined");
          next=ts.get();
          if(next.kind!=')')error("expected a ", ")");
          return sqrt(d);

        }
        case POW:{   // for pow function in math library.
         Token next= ts.get();
          if(next.kind!='(') error("expected a ", "(");
          double d= expression();
          next=ts.get();
          if(next.kind!=',') error("expected a ", ",");
          double e =expression();
          if(e!=(int)e) error("e is not an integer");
          next=ts.get();
          if(next.kind!=')') error("expected a ", ")");
          return pow(d,e);
            }
    case '-':
        return - primary();
    case '+':
        return primary();
    default:
        error("primary expected");
    }
}

//------------------------------------------------------------------------------

// deal with *, /, and %
double term()
{
    double left = primary();
    Token t = ts.get(); // get the next token from token stream

    while(true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
            {
                double d = primary();
                if (d == 0) error("divide by zero");
                left /= d;
                t = ts.get();
                break;
            }
       /* case '%':
            {
                int i1 = narrow_cast<int>(left);
                int i2 = narrow_cast<int>(term());
                if (i2 == 0) error("%: divide by zero");
                left = i1%i2;
                t = ts.get();
                break;
            }*/
        default:
            ts.putback(t);        // put t back into the token stream
            return left;
        }
    }
}

//------------------------------------------------------------------------------

// deal with + and -
double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream

    while(true) {
        switch(t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default:
            ts.putback(t);
            cout << "I have put it";   // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}

//------------------------------------------------------------------------------

double  Symbol_table:: declaration(Token k)
    // handle: name = expression
    // declare a variable called "name" with the initial value "expression"
	// k will be "let" or "con"(stant)
{
    Token t = ts.get();
    if (t.kind != name) error ("name expected in declaration");
    string var_name = t.name;

    Token t2 = ts.get();
    if (t2.kind != '=') error("= missing in declaration of ", var_name);

    double d = expression();
    bool var=false;
    if(k.kind==let)var=true;
symbol.define_name(var_name,d,var);
    return d;
}

//------------------------------------------------------------------------------

double statement()
{
    Token t = ts.get();
    switch (t.kind){
    case let:
	case con:
        return symbol.declaration(t.kind);
    default:

        ts.putback(t);
        return expression();
    }
}

//------------------------------------------------------------------------------

void clean_up_mess()
{
    ts.ignore(print);
}
void display();
//------------------------------------------------------------------------------
void display(){
cout << "Hi, welcome to the calculator project"
     << "\noperations that can be performed includes"
     << "\n (+,-,/,*,sqrt(),pow()), note in this"
     << "\nprogram you can define a variable of your"
     << "\nchoice using keyword # followed by name followed by = then value"
     << "\nyou can get value of the variable by typing variable;"
     << "\nyou can declare a const value just like defining a variable"
     << "\ndifference is that it starts with const not #"
     << "\nyou can change the value of a variable not const"
     << "\ne.g # area =5 , press quit( to quit),"
     << "\n press ; to print values.:";}
void calculate()
{
    while (cin)
      try {
        cout << prompt;
        Token t = ts.get();
        while (t.kind == print) t=ts.get();    // first discard all "prints"
        if (t.kind == que) return;        // quit
        if(t.kind==help){
                display();
        t=ts.get();
        }
        ts.putback(t);
        cout << result << statement() << endl;
    }
    catch (exception& e) {
        cerr << e.what() << endl;        // write error message
        clean_up_mess();
    }
}

//------------------------------------------------------------------------------

int main()
try {
cout << "press H for help on how to use the calculator \n";
    // predefine names:
    symbol.define_name("pi",3.1415926535,false);	// these pre-defiend names are constants
    symbol.define_name("e",2.7182818284,false);
    symbol.define_name("k",1000,false);

    calculate();

    // cope with Windows console mode
    return 0;
}
catch (exception& e) {
    cerr << e.what() << endl;
    return 1;
}
catch (...) {
    cerr << "exception \n";
    return 2;
}


//------------------------------------------------------------------------------

/*
	Oh, yes, once I had assignment and constants, I immediately made "pi" and "e"
	were constants. I really don't want anyone to redefine pi to be 3 :-)

	If we liked, we could predefine variables (e.g. x, y, and z), but would that be a good idea?

	When I added an argument in declaration() and Variable::Variable()), I used default arguments
	to ensure that older calls still worked correctly.
*/
