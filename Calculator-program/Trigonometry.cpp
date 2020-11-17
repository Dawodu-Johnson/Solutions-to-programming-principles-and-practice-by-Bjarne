#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include "declarations.h"
using namespace std;


double Trigonometry::toRads(double x)
{
     return (x*pi/180);

}
double Trigonometry:: bound(double x)
{
    if(x>1) error("value cant be greater than 1 since -1<=sinx <=1 && -1<=cosx <=1");
    else return x;
}
double Trigonometry:: SCT(char t,double x)
{
    //instead of writing the same function 3 times with silightly different logic
    // we wrote a single function that determines the type trig function to return
x=toRads(x);// invariant to ensure values are always in rad
switch(t)
{

case si: return sin(x);
case co: return cos(x);
default: return tan(x);
}

}
double Trigonometry:: ASCT(char t,double x)  // for arc Trig functions
{
    // multiplication of arc trig function with the const degree is done so as to convert it from rads
    // to degrees.....users favourite
switch(t)
{
case as:
    {
        x=bound(x);
        return degree* asin(x);
    }
case ac:
    {
        x=bound(x);
        return degree* acos(x);
    }
default: return degree*atan(x);
}
}
Token Trigonometry:: type(string t)    // returns a token type and the corresponding name
{
    // this can actually be re-written efficiently, but it's trivial
    //since 100,000 if statements can actually run in seconds
    if(t==sine)return Token(si,sine);
    else if(t==cosine) return Token(co,cosine);
    else if(t==tangent)return Token(ta,tangent);
    else if(t==arcsine)return Token(as,arcsine);
    else if(t==arccos)return Token(ac,arccos);
    else if(t==arctan)return Token(art,arctan);
    else return Token(name,t);
}



