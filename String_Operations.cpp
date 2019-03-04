#include<iostream>
#include<cstring>
using namespace std;
class String
{
	char a[100];	
	public:
		void accept();
		void display();
        int strlen();
		void strcat(String s2);
		void strcpy(String s2);
		void strcmp(String s2);
		void reverse();
		void substring();	
};
void String::accept()
{
	cout<<"\nEnter the string:";
	cin>>a;
}
	
void String::display()
{
cout<<"\nThe string = "<<a;	
}	

int String::strlen()
{
	int i,len=0;
	for(i=0;a[i]!='\0';i++)
	{
		len++;
	}
	return len;
}

void String::strcpy(String s2)
{
	int i;
	for(i=0;s2.a[i]!='\0';i++)
	{
		a[i]=s2.a[i];
	}
	a[i]='\0';
	cout<<"\nThe copied string is "<<a;
}
void String::strcmp(String s2)
{
	if(strlen()==s2.strlen())
	{
	
	int i,flag;
	for(i=0;a[i]!='\0';i++)
	{
		if(s2.a[i]==a[i])
		    flag++;
		else
		{
	     	flag=0;
		    break;
	    }
	}
	if(flag==0)
	cout<<"\nThe strings are not equal";
	else
	cout<<"\nThe strings are equal";
   }
   else
	cout<<"\nThe strings are not equal";

}

void String::strcat(String s2)
{
	int i,j;
	for(i=0;a[i]!='\0';i++)
	{
	}	
	for(j=0;s2.a[j]!='\0';j++)
	{
		a[i+j]=s2.a[j];
    }
    a[i+j]='\0';
}

void String::substring() 
{
	char b[20];
	cout<<"\nEnter another string=";
	cin>>b;
	int i,flag,j;
	for(i=0,j=0;a[i]!='\0'||b[j]!='\0';i++)
	{
		if(b[i]==a[i])
		{
			j++;
			flag=1;
		}
		
		else
		{
			j=0;
	     	flag=0;
		}
	}
	if(flag==1)
	cout<<"\nThe second string is a substring of first";
	else
	cout<<"\nThe second string is not a substring of first";
}

void String::reverse()
{
	int i,n=strlen();
	cout<<"\nThe reversed string=";
	for(i=n;i>=0;i--)
	{
		cout<<a[i];
   }
}
int main()
{
	String s1,s2;
	int v;
	do
	{
	cout<<"\n\nMENU\n\nPress 1 to enter a string\nPress 2 to display a string\nPress 3 to find length of the string\nPress 4 to copy a string\nPress 5 to concatenate 2 strings\nPress 6 to compare 2 strings\nPress 7 to check substring\nPress 8 to reverse a string\nExit:Press 9\n";
	cin>>v;
	switch(v)
	{
		case 1:
			s1.accept();
			break;
		case 2:
			s1.display();
			break;		
		case 3:
			s1.accept();
			cout<<"\nThe length of string is "<<s1.strlen();
			break;		
		case 4:
			s2.accept();
			s1.strcpy(s2);			
			break;
		case 5:
			s1.accept();
			s1.display();
			s2.accept();
			s2.display();
			s1.strcat(s2);
			cout<<"\nAfter concatenation ";
			s1.display();
			break;
		case 6:
			s1.accept();		
			s2.accept();
			s1.strcmp(s2);
			break;
		case 7:
			s1.accept();
			s1.substring();
			break;
		case 8:
			s1.accept();
			s1.reverse();
			break;
		case 9:cout<<"\nExitted";
			break;
		default:cout<<"\nInvalid option";
	}
	

    }while(v!=9);
	return 0;
}
