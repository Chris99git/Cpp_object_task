#include <iostream>

using namespace std;

const int S_MAX = 100; // rozmiar stosu operatorów

int p(char c)
{
switch(c)
{
case '+' : ;
case '-' : return 1;
case '*' : ;
case '/' : return 2;
case '^' : return 3;
}
return 0;
}

int main()
{
char S[S_MAX]; // stos operatorów
int sptr = 0; // wskaŸnik stosu
char c; // kolejny znak wyra¿enia

while(true)
{
cin >> c;

if(c == '=')
{
  while(sptr) cout << S[--sptr] << ' ';

  break;
}

switch(c)
{
  case ' ' : break;
  case '(' : S[sptr++] = '(';
             break;
  case ')' : while(S[sptr-1] != '(')
             cout << S[--sptr] << ' ';

             sptr--;
             break;
  case '+' : ;
  case '-' : ;
  case '*' : ;
  case '/' : ;
  case '^' : while(sptr)
             {
               if((p(c) == 3) || (p(c) > p(S[sptr - 1]))) break;
               cout << S[--sptr] << ' ';
             }
             S[sptr++] = c;
             break;
  default:   cout << c << ' ';
             break;
}
}

return 0;
}
