#include<iostream>
#include<cstring>
using namespace std;
class DSA
{       
    int rno;
    string name;
    int marks;
public:
    static int absent,present,min,max,m[101],avg,s;
    void accept();
    void printdata();
    void average();
    void absent();
    void maximum();
    void minimum();
    void most();  
};

int DSA::absent;
int DSA::present;
int DSA::min=101;
int DSA::max;
int DSA::m[101];
int DSA::avg;
int DSA::s;

void DSA::accept()
    {
        cout<<"Enter roll number of student:";
        cin>>rno;
        cout<<"Enter name of student:";
        cin>>name;
        cout<<"Enter marks of student in Data Structure and Algorithm 8subject (Out of 100)\nIf absent enter '-1':";
        cin>>marks;
        cout<<"\n";
    }

void DSA :: printdata()
{
     if(marks==-1)
        {
		    cout<<rno<<"\t\t\t"<<name<<"\t\tA\n";
		    absent++; 	
        }
        else
        {
		    cout<<rno<<"\t\t\t"<<name<<"\t\t"<<marks<<endl;
		    present++;
		    m[marks]++;
        }
}

void DSA :: absente()
{
    if(marks==-1)
    {
        cout<<rno<<"\t\t\t"<<name<<"\t\tA\n";    
    }
}


void DSA::average()
{
	if(marks>=0)
    {  
	  s+=marks;
    }
}



void DSA::minimum()
{
	if(marks>=0)
    {
        if(marks<min)
        {
           min=marks;
        } 
    }
	
}


void DSA::maximum()
{
	if(marks>=0)
    {
	    if(marks>max)
	    {
	       max=marks;
	    }
    }
	
}


void DSA::most()
{
	int l,y,i;
	l=m[0];
	for(i=0;i<101;i++)
	{
		if(m[i]>l)
		{
			l=m[i];
			y=i;
		}  
    }

	if(l>1)
	cout<<"\nMarks scored by most students="<<y<<" and number of times="<<l<<endl;
	else
	cout<<"\n0 number of students scored same marks\n"<<endl;		
}

int main()
{
    int n,i;
    cout<<"Enter number of students:";
    cin>>n;
    DSA a[n],obj;

        for(i=0;i<n;i++)
        {
	        a[i].accept();
	        cout<<"\n";
        }
        
        
    cout<<"\nStudents list:\n";
    cout<<"Roll No.\t\t Name\t\t\tMarks\n\n";
        for(i=0;i<n;i++)
       {
               a[i].printdata();
       }
    int v;
    do
   { 

		cout<<"\nFor absent students list press 1\nFor average marks of students press 2\nFor maximum marks of students press 3\nFor minimum marks of students press 4\nFor marks scored by most students press 5\nExit:Press 6";
		cin>>v;
		switch (v)
		{
			case 1:
				cout<<"\nAbsent students list:\n\n"; 
				cout<<"Roll No.\t\t Name\t\t\tMarks\n\n";   
				for(i=0;i<n;i++)
			      {
			           a[i].absente();
			      }
				
				cout<<"\nNo. of absent students="<<obj.absent;
				cout<<"\n";
				cout<<"\n";
			break;
			
			
			case 2:
				for(i=0;i<n;i++)
			      {
			           a[i].average();
			      }
				obj.avg=obj.s/obj.present;
				cout<<"\n\nAverage marks="<<obj.avg;
				cout<<"\n";
				cout<<"\n";
			break;
			
			
			case 3:
				for(i=0;i<n;i++)
			      {
			           a[i].maximum();
			      }
				cout<<"\n\nMaximum marks="<<obj.max;
				cout<<"\n";
				cout<<"\n";
			break;
			case 4:
				for(i=0;i<n;i++)
			      {
			           a[i].minimum();
			      }
				cout<<"\n\nMinimum marks="<<obj.min;
				cout<<"\n";
				cout<<"\n";
			break;
			
			
			case 5:
				obj.most();
				
			break;
			
			case 6:
				cout<<"\nExitted!";
				
			break;
			
			default:  cout<<"\nInvalid option\n";
				
			
		}
		
   }while(v!=6);

 return 0; 
}

