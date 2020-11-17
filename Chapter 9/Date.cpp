#include<iostream>
using namespace std;
enum Month{jan=1,feb,mar,april,may,jun,jul,aug,sep,oct,nov,dec};
void error1(string s, string m="")
{
    throw runtime_error (s+m);
}
class Date
{
private:
    int dd;
    int yy;
    Month k;
    bool isdate(int , Month , int );
    bool isleapYear(int yy);
public :
    Date(int l=22,Month h=april,int y=2000):dd(l),k(h),yy(y) {if(!isdate(l,h,y))error1("Invalid Date format ");}
    int Day()const{return dd;}
    Month month()const{ return k;}
    int Year()const{return yy;}
    bool operator ==(const Date&)const;
    bool operator !=(const Date &)const;
    friend ostream& operator << (ostream& os, const Date &d);

};
bool Date:: isleapYear(int yy)
{
   return  (yy%4 && yy%100 && yy%400) ? true:false;
}

bool Date:: isdate(int dd, Month M, int yy)
{
    int days=31;
    if(dd <=0 || dd>31)return false;
    switch(M)
    {
    case feb:
        {
           days=isleapYear(yy) ? 29:28;
           break;
        }
    case sep: case jun: case nov: case april:
        {
            days=30;
            break;
        }
    }
    if(dd>days)return false;
    return true;
}
bool Date:: operator ==(const Date& d)const
{
    return (yy==d.Year() && dd==d.Day()&& k==d.month());
}
bool Date:: operator !=(const Date &d)const
{
    return !(*this ==d);
}
ostream& operator << (ostream& os, const Date &d)
{
    os << d.Day() << " " << d.month() << " " << d.Year()<< endl;
    return os;
}

