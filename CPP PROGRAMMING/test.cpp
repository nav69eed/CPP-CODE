#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;


int main()
{
string ch1="102";
char ch[10];
ch[10]=ch1;
int base=10;
long int num;
char *p;
num=strtol(ch,&p,base);

cout<<num<<endl<<num+1;
getchar();
return 0;
}