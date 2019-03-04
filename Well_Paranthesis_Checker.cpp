#include <iostream>
#include<string.h>
using namespace std;

class stack
{
    char a[50];
    int top;
public:
    stack()
    {
        top=-1;
    }
    void push(char x);
    void pop();
    bool check(char exp[50]);
};

void stack::push(char x)
{
    if (top==50)
    {
        cout<<"\nStack overflow";
    }
    else
    {
        top++;
        a[top]=x;
     }
}

void stack::pop()
{
    if (top==-1)
    {
        cout<<"\nStack underflow";
    }
    else
    {
         top--;
    }
}

bool stack::check(char exp[50])
{
    int i;
    for(i=0;i<strlen(exp);i++)
    {
    if(exp[i]=='('||exp[i]=='['||exp[i]=='{')
    {
    	push(exp[i]);
	}
   	switch(exp[i])
	{
		case ')':if(top==-1)
				 return false;
				 if(a[top]=='{'||a[top]=='[')
				 return false;
				 else
				 pop();
		         break;
		case ']':if(top==-1)
				 return false;
				 if(a[top]=='{'||a[top]=='(')
				 return false;
				 else
				 pop();
		         break;
		case '}':if(top==-1)
				 return false;
				 if(a[top]=='('||a[top]=='[')
				 return false;
				 else
				 pop();
		         break;
	}
	}
	 
	if(top==-1) 
	return true;

}

    


int main()
{
    char exp[50];
    cout<<"Enter the expression=";
    cin>>exp;
    stack s;
    if(s.check(exp))
    cout<<"The expression is well paranthesized";
    else
    cout<<"The expression is not well paranthesized\n";
    
    return 0;
}
