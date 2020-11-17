#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
void error(string s)  // for exceptions
{

    throw runtime_error(s);
}

void error(string s, string m)
{
    throw runtime_error(s+m);
}


/*

class Name_value {	// much like Token from 6.3.3
public:

	Name_value(string n, int s);
	string name;
	int score;
};
Name_value::Name_value(string n, int s){
    cout << "Was i called" << endl;

name=n;
score=s;
}

int main()
try
{
	vector<Name_value> pairs;   // pairs is not an object here, it is only of type Name-value hence uses it properties.
	string n;
	int v;

	while (cin>>n>>v) {
		for (int i=0; i<pairs.size(); ++i)
			if (n==pairs[i].name) error("duplicated name not allowed");
		pairs.push_back(Name_value(n,v)); // Note only the constructor function can fill these black hole no other function can
	}

	for (int i=0; i<pairs.size(); ++i)
			cout << '(' << pairs[i].name << ',' << pairs[i].score << ")\n";


return 0;}
catch(runtime_error e){
cout << e.what() <<endl;}
*/

/*int main()
try{
vector<char> numbers;
vector <string> name(4);
name[0]="Ones";
name[1]="Tens";
name[2]="Hundred";
name[3]="Thousand";
char x;
while(cin >> x){
    numbers.push_back(x);
}
if(numbers.size()<=4){
    for(int i=0; i< numbers.size();++i){
        cout <<  numbers[i] - '0' << name[numbers.size()-i-1]  << "  ";
    }
}
else error("5 or more digits are not accounted for here");

    return 0;
}
catch(runtime_error e){
cout << e.what() << endl;}*/
/*
solution to number 10.
int Factorial(int a);
int Permutation(int x, int y);
int Combination(int l, int m);
int main()
try{
cout << "Hi,computations of permutations and combinations is my duty\n";
cout << "Enter two numbers separated by space\n";
cout << "Note <a is the set >, and <b is the subset> i.e a>=b\n";
int a,b;
if(!(cin >>a>>b))error("One or both is not an integer, check again"); // check if read operation was a success.

cout << "Enter 'p' for permutation 'c' for combination or 'pc' for both"<< endl;
string x;
cin >> x;
if(x=="p") cout << " p(" << a << ',' << b << ")" << Permutation(a,b) << endl;
else if(x=="c") cout << " c(" << a << ',' << b << ")" << Combination(a,b) << endl;
else if(x=="pc") {
        cout << " p(" << a << ',' << b << ")" << Permutation(a,b) << endl;
cout << " c(" << a << ',' << b << ")" << Combination(a,b) << endl;}
else error("check that wasnt a p or c nor pc");
return 0;}
catch(runtime_error e){
cout << e.what() << endl;}
int Factorial(int a){
// compute a!.
int p=1;
if(a<0) error("Cant compute negative factorial values, try again");
else if(a==0) return 1;
else if(a==1) return 1;
while(a>1){
    p*=a;
    --a;
}
return p;
}
int Permutation(int x, int y){
if(x<y) error("set cant be less than a subset");
return Factorial(x)/Factorial(x-y);
}

int Combination(int l, int m){
return Permutation(l,m)/Factorial(m);
}
*/

/*This is based on the principle of grammars
sentence :
Noun verb  // i.e the most basic of them all
sentence conjunction sentence  The basic form extended to another basic more sophisticated form.*/

// vectors of words, appropriately classified:
/*vector<string> nouns;
vector<string> verbs;
vector<string> conjunctions;

void init()
// initialize word classes
{
	nouns.push_back("birds");
	nouns.push_back("fish");
	nouns.push_back("C++");	// I didn't suggest adding "C+" to this exercise
							// but it seems some people like that

	verbs.push_back("rules");
	verbs.push_back("fly");
	verbs.push_back("swim");

	conjunctions.push_back("and");
	conjunctions.push_back("or");
	conjunctions.push_back("but");
}
// noun,verb,conjunction function are checkers(i.e they check to see that a function is correct.)
bool is_noun(string w)
{   cout << "THis is the noun function\n";
		for(int i = 0; i<nouns.size(); ++i)
			if (w==nouns[i]) return true;
		return false;
}

bool is_verb(string w)
{

		for(int i = 0; i<verbs.size(); ++i)
			if (w==verbs[i]) return true;
		return false;
}

bool is_conjunction(string w)
{
		for(int i = 0; i<conjunctions.size(); ++i)
			if (w==conjunctions[i]) return true;
		return false;
}

bool sentence()
{

	string w;
	cin >> w;
	if (!is_noun(w)) return false;  // return statements can act as a pause to a flow.

	string w2;
	cin >> w2;
	if (!is_verb(w2)) return false;

	string w3;
	cin >> w3;
	if (w3 == ".") return true;	// end of sentence
	if (!is_conjunction(w3)) return false;	// not end of sentence and not conjunction

	return sentence();	// look for another sentence provided the last input was a conjunction.
}

int main()
try    // error handling.
{


	init();	// initialize word tables

	while (cin)
        { //The essence of cin is to make the loop run at first then still run at last.
			bool b = sentence(); // it is when returns a value before the next line runs.

			if (b)
				cout << "OK\n";
			else
				cout << "not OK\n";
			cout << "Try again: ";
	}


}
catch (runtime_error e) {	// It outputs error messages during runtime .
	cout << e.what() << '\n';

}
*/

/*
// Exercise 4.
class NameValue
{
public:
string name;
double score;
NameValue(string n, double s): name(n), score(s) {}
};

int main()
try{
    vector<NameValue>pairs;  // vector of classes.
    string name;
    double score;
    cout << "Enter a name and score separated by a white space  e.g Johnson 33 \n";
    cout << "Enter \"no more\"  to terminate i.e no more \n";

    while(cin >> name >> score)
    {
       for(int i=0; i<pairs.size(); ++i)  // checking asynchronously...
       {
           if(pairs[i].name==name) error(name, "  repeated twice. not allowed ");
       }

        pairs.push_back(NameValue(name,score));  // the constructor does the initializing here.
    }

    cin.clear();
    cin.ignore(100,'\n');    // makes the input stream available again.
    cout << "\n\n(Name,Score)" << endl;
    for(int i=0; i<pairs.size(); ++i)
    {
        cout << '(' << pairs[i].name << ',' << pairs[i].score << ')' << endl;
    }
    return 0;
}
catch(runtime_error &e)
{ cerr << e.what() << endl;
}
catch(...){ cerr << "An error occured  " << endl;}
*/


// exercise 5, ans: "the have been added to the grammar /

//Exercise 6.
/*
 bool verb(string);
 bool noun(string );
 bool conjuction(string);
 bool sentence();
int main()
{
    if(sentence()) cout << "OK" << endl;
    else cout << "Not OK " << endl;

    return 0;
}
bool noun(string noun)
{
     vector<string>nouns;
    nouns.push_back("birds");
    nouns.push_back("fish");
    nouns.push_back("C++");
    for(int i=0; i<nouns.size();++i)
    {
        if(noun==nouns[i]) return true;
    }
     return false;
}
bool verb(string verb)
{
    vector<string>verbs;
    verbs.push_back("rule");
    verbs.push_back("fly");
    verbs.push_back("swim");

    for(int i=0; i<verbs.size();++i)
    {
        if(verb==verbs[i])return true;
    }
     return false;
}
bool conjuction(string conjuction)
{
    vector<string>conjuctions;
    conjuctions.push_back("and");
    conjuctions.push_back("but");
    conjuctions.push_back("or");

    for(int i=0; i<conjuction.size();++i)
    {
        if(conjuction==conjuctions[i])return true;
    }
    return false;
}
bool sentence()
{
    char space,t;
    string n,v,c,trial;
    cin >> n;
    if(noun(n))
     {
       cin >> v;
       if(verb(v))
       {
           //cin.get(space);     // alternative method check if it was a space.
           //cin.putback(space);   // put it back
          cin >> trial;     // if the next input is now a "." then we are done.
          if(trial == ".")return true;
          else if(conjuction(trial)) return sentence();
        }
     }
return false;
}
*/

// Exercise 7 ans, just write a grammar similar to the calculation operators, replacing *+/, with necessary symbols.
// placing the unary operators in the number category.
/*
//Exercise 8.
// the key to the solution is to create an index monitor for the individual character being entered.
int main()
{
    vector<string> letters;
    letters.push_back("j");
    letters.push_back("o");
    letters.push_back("h");
    letters.push_back("n");
    int cows=0, bulls=0;
    cout << "Enter 4 letters separated by a space \n";
    cout << "e.g j h n p \n";
    while(bulls!=4)
    {
        bulls=0,cows=0;
         // placed at the top,reseting the bulls and the cows,
        // note that if it is placed at the end.
        // the loop wont end even when
        // bull is 4, because it will have been reset before getting to the conditions.
        string test;
        int index=0;  // the index monitor for your variable test.
        for(int j=0; j<letters.size();++j)
        {
        cin>> test;
        for(int i=0; i<letters.size();++i)
        {
            if(test==letters[i] && index==i) {++bulls; ++index;}
            else if(test==letters[i])
            {
             ++cows;
             ++ index;
            }
        }
    }

     cout << "bulls = " << bulls << " cows = " << cows << endl;
     index=0;  // reset
    }
    return 0;
    // there is still more to make this solution more elegant (error handling)
    //but no time.
}
*/

/*//Exercise 9
int main()
try{
    vector<int>digits;
    vector<string>position;
    position.push_back("ones");
    position.push_back("tens");
    position.push_back("hundred");
    position.push_back("Thousand");
    char ch;                // this represents individual digits...
    cout << "Enter a number not more than 4 digits " << endl;
    cout << "Enter ';' to terminate \n";
    cout << "I.e 2000 ; \n";
    while(cin >> ch)
    {
        if(ch<'0' || ch>'9')break;       // break, if ch-'0' is not a number.
        digits.push_back(ch-'0');       // The logic; coverts the character to an integer.
    }

    if(digits.size()==0) error("No value entered");
    if(position.size()<digits.size()) error("Too many digits");
    int num=0;
    for(int i=0; i<digits.size(); ++i)
    {
        if(digits[i])cout << digits[i] << position[digits.size()-i-1] << ' ';
        // we dont want to print 1000 as 1 thousand 0 hundred 0 tens 0 ones
        // so we encompass the cout in an if statement depending on the number.
        num = num*10 + digits[i]; // composition of digits.(decomposition was done in chapter 4 or 5).
    }
    cout << endl;
    cout << "The number is " << num << endl;
    return 0;
}
catch(runtime_error &e)
{
    cerr << e.what() << endl;
}
catch (...)
{
     cerr << "An error occured \n";
}
*/

/*
//Exercise 10;

double permutation(int a, int b);
double combination(int, int);
int factorial(int);

int main()
try
{
    int a=0,b=0;
    char choice;
    cout << "Enter two numbers of your choice \n";
    cin >> a >> b;
    cout << "Enter p for permutation or c for combination \n";
    cin >> choice;
    if(choice=='p')
    {
        cout << "The permutation of " << a << " And " << b
        << " = " <<   permutation(a,b) << endl;
    }
    else if(choice=='c')
    {
            cout << "The combination of " << a << " And " << b
            << " = " <<   combination(a,b) << endl;
    }
    else error("The choice of calculation here isn't recognized, try p or c");
}
catch(runtime_error &e)
{
    cerr << e.what() << endl;
}
catch(...)
{
    cerr << "An error occured " << endl;
}
int factorial(int a)
{
    if(a<0) error("Negative numbers aren't allowed");
    else if(a==1) return 1;
    else return a * factorial(a-1);
}
double permutation(int a, int b)
{
    if(a <0 || b<0 )error ("negative number is not allowed ");
    double m=0;
    m= factorial(a)/factorial(a-b);
    return m;
}

double combination(int a,int b)
{
    if(a<0 || b<0) error (" negative number is not allowed" );
    double m=0;
    m= permutation(a,b)/factorial(b);   // notice the chaining;
    // i made permutation depend on factorial.
    //while combination depends on both.
    return m;
}

*/
