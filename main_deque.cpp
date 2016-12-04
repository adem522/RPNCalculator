#include <iostream>
#include <stack>
#include <deque>
#include <string>
#include <cctype>
#include <cmath>
#define PI 3.14159265
using namespace std;
deque <string> postfix;
deque <string> kuyruk;
bool elemanmi(char a);
bool operatormu(char a);
bool derece(char a, char b);
void postfixyap(string infix);
void islemyap(void);
int faktoriyel(int);
void islemtablosu(void);
int main()
{
	string infix;
	islemtablosu();
	cout<<endl;
	cout<<"ISLEMI GIRIN"<<endl;
	cin>>infix;
	postfixyap(infix);
	islemyap();
	cout<<"Sonuç = "<<kuyruk.front()<<endl;
}
void islemtablosu(void)
{
	cout<<"İŞLEM TABLOSU\n"
		<<"MATEMATIK OPERATORLERI "<<endl
		<<"CIKARMA (-)\tTOPLAMA(+)\tCARPMA(*)\tBOLME(/)"<<endl
		<<"US AL (^)\tMOD ALMA (%)\tNEGATIF (~)\tFAKTORIYEL (!)"<<endl
		<<"TRIGONOMETRIK FONKSIYONLAR"<<endl
		<<"SINUS (sin(x))\tCOSINUS (cos(x))\tTAN (tan(x))\tCOT (cot(x))"<<endl
		<<"ARCSIN (asin(x)\tARCCOS (acos(x))\tARCTAN (atan(x))\tARCCOT (acot(x))"<<endl
		<<"LOGARITMIK FONKSIYONLAR"<<endl
		<<"LOG10 (log(x))\tLN (ln(x))"<<endl
		<<"SGN (sgn(x)) \tEXP (exp(x))"<<endl;
}
void islemyap (void)
{
	char op;
	string test,ss1,ss2;
	double s1,s2;
	double sonuc;
	while(!postfix.empty())
	{
		test=postfix.front();
		postfix.pop_front();
		kuyruk.push_back(test);
		if(operatormu(test[0]))
		{
			kuyruk.pop_back();
			op=test[0];
			if(!kuyruk.empty())//boşsa pi sayısıdır
			{
			ss1=kuyruk.back();
			s1=stod(ss1);
			kuyruk.pop_back();
			}
			if(!kuyruk.empty())
			{
				ss2=kuyruk.back();
				s2=stod(ss2);
				kuyruk.pop_back();
			}
			switch(op)
			{
			case '+':
				sonuc=s1+s2;
				break;
			case '-':
				sonuc=s2-s1;
				break;
			case '*':
				sonuc=s1*s2;
				break;
			case '/':
				if(s1==0)
					{
						cout<<"TANIMSIZ BIR DEGER VAR(0'A BOLMEK) PROGRAMDAN CIKILIYOR"<<endl;
						exit(1);
					}
				sonuc=s2/s1;
				break;
			case '^':
				sonuc=pow(s2,s1);
				break;
			case '!':
				sonuc=faktoriyel(s1);
				break;
			case '%':
				sonuc=int(s2)%int(s1);
				break;
			case '~':
				sonuc=-s1;
				break;
			case 's':
				sonuc=sin(s1*PI/180);
				break;
			case 'c':
				sonuc=cos(s1*PI/180);
				break;
			case 't':
				sonuc=tan(s1*PI/180);
				break;
			case 'y':
				if(s1==0)
					{
						cout<<"TANIMSIZ BIR DEGER VAR(0'A BOLMEK) PROGRAMDAN CIKILIYOR"<<endl;
						exit(1);
					}
				sonuc=1/tan(s1*PI/180);
				break;
			case 'q':
				sonuc=asin(s1*PI/180);
				break;
			case 'b':
				sonuc=acos(s1*PI/180);
				break;
			case 'k':
				sonuc=atan(s1*PI/180);
				break;
			case 'l':
				if(s1==0)
					{
						cout<<"TANIMSIZ BIR DEGER VAR\n(0'A BOLMEK) PROGRAMDAN CIKILIYOR"<<endl;
						exit(1);
					}
				sonuc=1/atan(s1*PI/180);
			case 'm':
				if(s1==0)
					{
						cout<<"TANIMSIZ BIR DEGER VAR\n(LOGARITMA TANIM HATASI >>ln 0 degerini alamaz<<) PROGRAMDAN CIKILIYOR"<<endl;
						exit(1);
					}
				else if(s1<0)
					{
						cout<<"TANIMSIZ BIR DEGER VAR\n(LOGARITMA TANIM HATASI >>ln eksi bir deger alamaz<<) PROGRAMDAN CIKILIYOR"<<endl;
						exit(1);
					}	
				sonuc=log(s1);
				break;
			case 'o':
				if(s1==0)
					{
						cout<<"TANIMSIZ BIR DEGER VAR\n(LOGARITMA TANIM HATASI >>log 0 degerini alamaz<<) PROGRAMDAN CIKILIYOR"<<endl;
						exit(1);
					}
				else if(s1<0)
					{
						cout<<"TANIMSIZ BIR DEGER VAR\n(LOGARITMA TANIM HATASI >>log eksi bir deger alamaz<<) PROGRAMDAN CIKILIYOR"<<endl;
						exit(1);
					}	
				sonuc=log10(s1);
				break;
			case 'g':
				sonuc=copysign(s1,1.0);
				break;
			case 'h':
				sonuc=exp(s1);
				break;
			case 'p':			
			sonuc=PI;
				break;
			}
			kuyruk.push_back(to_string(sonuc));
		}
	}
}
void postfixyap(string infix)
{	//s=sin | c=cos |t=tan |y=cot |q=asin |b=acos |k=atan|l=acot|m=ln|o=log|g=sgn|h=exp|p=pi
	stack <char> operatorler;
	int k;
	string temp;
	for(int i = 0; i < infix.length(); i++)
	{
		if(elemanmi(infix[i]))
		{
			if(infix[i]!= '(' || infix[i]!=')')
			temp+=infix[i];
			if(operatormu(infix[i+1])||i+1==infix.length() || infix[i+1]==')')
			{
				postfix.push_back(temp);
				temp="";
			}
		}
		else if(isalpha(infix[i]))
		{
			if(infix[i]=='s' && infix[i+1]=='i' && infix[i+2]=='n')
			{
				temp="";
				while(!operatorler.empty() && operatorler.top()!='(' && derece(operatorler.top(),infix[i]))
				{
					temp=operatorler.top();
					postfix.push_back(temp);
					temp="";
					operatorler.pop();
				}
				operatorler.push(infix[i]);
				temp="";
			}
			if(infix[i]=='c' && infix[i+1]=='o' && infix[i+2]=='s')
			{
				temp="";
				while(!operatorler.empty() && operatorler.top()!='(' && derece(operatorler.top(),infix[i]))
				{
					temp=operatorler.top();
					postfix.push_back(temp);
					temp="";
					operatorler.pop();
				}
				operatorler.push(infix[i]);
				temp="";
			}
			if(infix[i]=='t' && infix[i+1]=='a' && infix[i+2]=='n')
			{
				temp="";
				while(!operatorler.empty() && operatorler.top()!='(' && derece(operatorler.top(),infix[i]))
				{
					temp=operatorler.top();
					postfix.push_back(temp);
					temp="";
					operatorler.pop();
				}
				operatorler.push('t');
				temp="";
			}
			if(infix[i]=='c' && infix[i+1]=='o' && infix[i+2]=='t')
			{
				temp="";
				while(!operatorler.empty() && operatorler.top()!='(' && derece(operatorler.top(),infix[i]))
				{
					temp=operatorler.top();
					postfix.push_back(temp);
					temp="";
					operatorler.pop();
				}
				operatorler.push('y');
				temp="";
			}
			if(infix[i]=='a' && infix[i+1]=='s' && infix[i+2]=='i' && infix[i+3] =='n')
			{
				temp="";
				while(!operatorler.empty() && operatorler.top()!='(' && derece(operatorler.top(),infix[i]))
				{
					temp=operatorler.top();
					postfix.push_back(temp);
					temp="";
					operatorler.pop();
				}
				operatorler.push('q');
				temp="";
				i=i+3;
			}
			if(infix[i]=='a' && infix[i+1]=='c' && infix[i+2]=='o' && infix[i+3] =='s')
			{
				temp="";
				while(!operatorler.empty() && operatorler.top()!='(' && derece(operatorler.top(),infix[i]))
				{
					temp=operatorler.top();
					postfix.push_back(temp);
					temp="";
					operatorler.pop();
				}
				operatorler.push('b');
				temp="";
				i=i+3;
			}
			if(infix[i]=='a' && infix[i+1]=='t' && infix[i+2]=='a' && infix[i+3] =='n')
			{
				temp="";
				while(!operatorler.empty() && operatorler.top()!='(' && derece(operatorler.top(),infix[i]))
				{
					temp=operatorler.top();
					postfix.push_back(temp);
					temp="";
					operatorler.pop();
				}
				operatorler.push('k');
				temp="";
				i=i+3;
			}
			if(infix[i]=='a' && infix[i+1]=='c' && infix[i+2]=='o' && infix[i+3] =='t')
			{
				temp="";
				while(!operatorler.empty() && operatorler.top()!='(' && derece(operatorler.top(),infix[i]))
				{
					temp=operatorler.top();
					postfix.push_back(temp);
					temp="";
					operatorler.pop();
				}
				operatorler.push('l');
				temp="";
				i=i+3;
			}
			if(infix[i]=='l' && infix[i+1]=='n')
			{
				temp="";
				while(!operatorler.empty() && operatorler.top()!='(' && derece(operatorler.top(),infix[i]))
				{
					temp=operatorler.top();
					postfix.push_back(temp);
					temp="";
					operatorler.pop();
				}
				operatorler.push('m');
				temp="";
			}
			if(infix[i]=='l' && infix[i+1]=='o' && infix[i+2]=='g')
			{
				temp="";
				while(!operatorler.empty() && operatorler.top()!='(' && derece(operatorler.top(),infix[i]))
				{
					temp=operatorler.top();
					postfix.push_back(temp);
					temp="";
					operatorler.pop();
				}
				operatorler.push('o');
				temp="";
			}
			if(infix[i]=='s' && infix[i+1]=='g' && infix[i+2]=='n')
			{
				temp="";
				while(!operatorler.empty() && operatorler.top()!='(' && derece(operatorler.top(),infix[i]))
				{
					temp=operatorler.top();
					postfix.push_back(temp);
					temp="";
					operatorler.pop();
				}
				operatorler.push('g');
				temp="";
			}
			if(infix[i]=='e' && infix[i+1]=='x' && infix[i+2]=='p')
			{
				temp="";
				while(!operatorler.empty() && operatorler.top()!='(' && derece(operatorler.top(),infix[i]))
				{
					temp=operatorler.top();
					postfix.push_back(temp);
					temp="";
					operatorler.pop();
				}
				operatorler.push('h');
				temp="";
			}
			if(infix[i]=='p' && infix[i+1]=='i')
			{
				temp="";
				while(!operatorler.empty() && operatorler.top()!='(' && derece(operatorler.top(),infix[i]))
				{
					temp=operatorler.top();
					postfix.push_back(temp);
					temp="";
					operatorler.pop();
				}
				operatorler.push('p');
				temp="";
			}
		}
		else if (operatormu(infix[i]))
		{
			temp="";
			while(!operatorler.empty() && operatorler.top()!='(' && derece(operatorler.top(),infix[i]))
			{
				temp=operatorler.top();
				postfix.push_back(temp);
				temp="";
				operatorler.pop();
			}
			operatorler.push(infix[i]);
			temp="";
		}
		else if(infix[i]=='(')
		{
			operatorler.push('(');
		}
		else if(infix[i]==')')
		{
			while(!operatorler.empty() && operatorler.top() != '(') 
			{
				temp=operatorler.top();
				operatorler.pop();
			}
			if(temp!="")
			postfix.push_back(temp);
			temp="";
			operatorler.pop();
		}
	}
	temp="";
	while(!operatorler.empty())
	{
		temp=operatorler.top();
		postfix.push_back(temp);
		
		
		operatorler.pop();
	}
	/*while(!postfix.empty())
	{
		cout<<postfix.back()<<endl;
		postfix.pop_back();
	}*/
}
int faktoriyel(int a)
{
	if(a==1 || a==0)
		return 1;
	else
		return faktoriyel(a-1) * a;
}
bool elemanmi(char a)
{
	if(a >= '0' && a <= '9') return true;
	return false;
}
bool operatormu(char a)
{	//s=sin | c=cos |t=tan |y=cot |q=asin |b=acos |k=atan|l=acot|m=ln|o=log|g=sgn|h=exp|p=pi
	if(a=='+' || a=='-' || a=='*' || a=='/' || a=='^' || a=='!' || a=='%' || a=='~' || a=='s' || a=='c' || a=='t' || a=='y' || a=='q' || a=='b' || a=='k' || a=='l' || a=='p' || a=='m'|| a=='o' || a=='g' ||a=='h')
		return true;
		return false;
}
bool derece(char yiginda, char islemde)
{
	int a, b;
	switch(yiginda)
	{
		case '%':
			a=0;
			break;
		case '+':
		case '-':
			a=1;
			break;
		case '*':
			a=2;
			break;
		case '/':
			a=3;
			break;
		case '!':
			a=4;
			break;
		case '^':
			a=5;
			break;
		case '~':
			a=6;
			break;//s=sin | c=cos |t=tan |y=cot |q=asin |b=acos |k=atan|l=acot|m=ln|o=log|g=sgn|h=exp|p=pi
		case 's':
		case 'c':
		case 't':
		case 'y':
		case 'q':
		case 'b':
		case 'k':
		case 'l':
		case 'm':
		case 'o':
		case 'g':
		case 'h':
		case 'p':
			a=7;
			break;
	}
	switch(islemde)
	{
		case '%':
			b=0;
			break;
		case '+':
		case '-':
			b=1;
			break;
		case '*':
			b=2;
			break;
		case '/':
			b=3;
			break;
		case '!':
			b=4;
			break;
		case '^':
			b=7;
			break;
		case '~':
			b=6;
			break;
		case 's':
		case 'c':
		case 't':
		case 'y':
		case 'q':
		case 'b':
		case 'k':
		case 'l':
		case 'm':
		case 'o':
		case 'g':
		case 'h':
		case 'p':
			b=7;
			break;
	}
	if(a>b)
		return true;
	if(a<b)
		return false;
}
