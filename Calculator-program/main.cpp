#include <iostream>
#include<string.h>
#include "Caculator-header.h"
#include "declarations.h"
#include "Calculator-definition.cpp"
#include "Trigonometry.cpp"

using namespace std;
// Knowing the function to call first in the main function is a crucial decision.
// But since Expression() depends on the call of other function then it should be called first.
// Note the logical separation between the main and the calculate function
// A function is meant to solve one logical problem, anything more than one defiles its identity
void Instructions()
{
    cout << "hi, i am nick and i am here to guide you on how to use this calculator efficiently!\n";
    cout << "Operations includes but not limited to +,-,/,*,sqrt(),pow(),! \n";
    cout << "End your expressions with ; to print result \n";
    cout << "E.g 2+2; 2!; ((2/3)-4/4-4+4*5); pow(2,4); sqrt(5); \n";
    cout << "Declaration of variables is also allowed!\n";
    cout << "To declare a variable kindly enter \"let nameOfVariable = value\"\n";
    cout << "variables declared with the let keyword can be changed by simply\n";
    cout << "Assigning a new value e.g variable=value\n";
    cout << "Declaration of const is also possible by using the const keyword \n";
    cout << "Instead of the let keyword, however, variables declared with the const keyword\n";
    cout << "cant be changed!!!" << endl;
    cout << "Should there be any error and calculator does not respond kindly enter ; to restart \n";
    cout << "Happy Calculating!!!\n\n\n";
}
void recoveryFromErrors(TokenStream &ts)
{
    ts.ignore(print);
}


void Calculate(TokenStream &ts)
{
     double value=0;

     cout << "Welcome Master! kindly use me!! " << endl;
     cout << "Enter \"help;\"to know more how to use this calculator" << endl;
     cout << "Quick tip! end all calculations with ; e.g 2+2; \" ; is responsible for printing output\" \n";


     while(true)
     try{
     cout << prompt;

     Token t= ts.get();

     if(t.kind==print) t=ts.get(); // eat ';' i.e discards the first print
     else if(t.kind ==quit) return;// ';' 2+3indicates when to print.
     else if(t.kind==help)
     {
         Instructions();
         t=ts.get();   // to restart the program afresh
     }
      ts.putBack(t);
      double value = Statement(ts);
      cout << result << value << endl;
     }
     catch(runtime_error &e)
     {
         cerr << e.what() << endl;
         recoveryFromErrors(ts);


     }
     catch(...)
     {
         cerr << "An error occured\n";
     }
}
int main()  // this is the implementation of calculation now ...
try{
    TokenStream ts;   // declaration of the object
    symbol.defineName("pi" ,3.1415926535,false);
    symbol.defineName("e" ,2.7182818284,false) ;
    symbol.defineName("k" ,1000,false);
    Calculate(ts);
    return 0;
}
catch(runtime_error &e)
{
    cerr << e.what() << endl;
}
catch(...)
{
    cerr << " AN ERROR OCCURED " << endl;
}
