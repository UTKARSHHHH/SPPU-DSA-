#include<iostream>
#include<string>
using namespace std;
struct node
{
	int prn;
	string name;
	node *next;	
};

class pinnacle
{
	public:
	static int rev_no;
	node *nn;
	node *pres;
	node *sec;
	pinnacle()
	{
		pres=NULL;
		sec=NULL;
	}
	void create();	
	void display();
	void insert();
	void concat(pinnacle a);
	void delet();
	void reverse(node *cn);
};
int pinnacle::rev_no=1;

void pinnacle::create()
{
	node *cn;
	int no,i;
	nn=new node;
	nn->next=NULL;
	pres=nn;
	cout<<"\nEnter president name=";
	cin>>nn->name;
	nn->prn=1;
	nn=new node;
	nn->next=NULL;
	sec=nn;
	cout<<"\nEnter secretrary name=";
	cin>>nn->name;
	nn->prn=2;
	cout<<"\nHow many members do you want to add in this club?\n";
	cin>>no;
	cn=pres;
	for(i=0;i<no;i++)
	{
		nn=new node;
		cout<<"\nEnter member's name and PRN No.=";
		cin>>nn->name>>nn->prn;
		nn->next=NULL;
		if(pres->next==NULL)
		{
			pres->next=nn;
			cn=cn->next;
		}
		else
		{
			cn->next=nn;
			cn=cn->next;	
		}		
	}
	cn->next=sec;
	
}


void pinnacle::display()
{
	node *cn;
	cn=pres;
	int i=1;
	cout<<"\nSr no\t\t Name \t\t PRN No \t\t Post\n";
	while(cn!=NULL)
	{
		if(cn->prn==1)	
		{
			cout<<i<<"\t\t"<<cn->name<<"\t\t"<<cn->prn<<"\t\tPresident\n";
			i++;
			cn=cn->next;
		
		}		
		else if(cn->prn==2)	
		{
			cout<<i<<"\t\t"<<cn->name<<"\t\t"<<cn->prn<<"\t\tSecretrary\n";
			i++;
			cn=cn->next;
		}
		else
		{
			cout<<i<<"\t\t"<<cn->name<<"\t\t"<<cn->prn<<"\t\tMember\n";
			i++;
			cn=cn->next;
		}
	}
	cout<<"\n\nTotal number of students="<<i-1;
		
}

void pinnacle::insert()
{

	int v,n,i;
	cout<<"\nPress 1 to add a new President\nPress 2 to add a new Secretrary\nPress 3 to add a new member at a specific place\n";
	cin>>v;
	switch(v)
	{
		case 1:
			nn=new node;
			nn->next=NULL;
			cout<<"\nEnter name of new President=";
			cin>>nn->name;
			nn->prn=1;
			cout<<"Enter changed PRN No of previous President=";
			cin>>pres->prn;
			nn->next=pres;
			pres=nn;
			cout<<"\nNew President succesfully created";
			break;
		case 2:
			nn=new node;
	        nn->next=NULL;
			cout<<"\nEnter name of new Secretrary=";
			cin>>nn->name;
			nn->prn=2;
			cout<<"Enter changed PRN No of previous Secretrary=";
			cin>>sec->prn;
			sec->next=nn;
			sec=nn;
			cout<<"\nNew Secretrary succesfully created";
			break;
		case 3:
			int  k,flag;
		    node *cn;
		    nn=new node;
		    cout<<"\nEnter name and PRN No. of new member=";
		    cin>>nn->name>>nn->prn;
		    nn->next=NULL;
		    cn=pres;
		    cout<<"Enter PRN No. after which u want to add the member"<<endl;
		    cin>>k;
		    while(cn!=NULL)
		    {
		        if(cn->prn==k)
		        {
		        	flag=1;
		            break;
		        }
		        cn=cn->next;
		    }
		    if(flag!=1)
		    cout<<"\nPRN No. not found";
		    if(cn!=NULL)
		    {
		        nn->next=cn->next;
		        cn->next=nn;
		        cout<<"\nMember succesfully added";
		    }
			break;
		default:cout<<"\nInvalid Option.";
		
	}
}

void pinnacle::concat(pinnacle a)
{
	sec->next=a.pres;
}

void pinnacle::delet()
{

	int v,n,i;
	node *cn,*p;
	cout<<"\nPress 1 to delete President\nPress 2 to delete Secretrary\nPress 3 to delete a  member\n";
	cin>>v;
	switch(v)
	{
		case 1:

			cn=pres;
			pres=cn->next;
			pres->prn=1;
			delete cn;
			cout<<"\nPresident succesfully deleted";
			break;
		case 2:
			cn=pres;
			while(cn!=NULL)
			{
				if(cn->prn==2)
				break;
				p=cn;
				cn=cn->next;
				
			}
		p->next=cn->next;
		delete cn;
		sec=p;
		sec->next=NULL;
		sec->prn=2;
		cout<<"\nSecretrary succesfully deleted";
		break;
		case 3:
			int  k,flag;
		    cn=pres;
		    cout<<"Enter PRN No.of the member to be deleted"<<endl;
		    cin>>k;
		    while(cn!=NULL)
		    {
		        if(cn->prn==k)
		        {
		        	flag=1;
		            break;
		        }
		        p=cn;
		        cn=cn->next;
		    }
		    if(flag!=1)
		    cout<<"\nPRN No. not found";
		    p->next=cn->next;
		    delete cn;
		    cout<<"\nMember succesfully deleted";
		
			break;
		default:cout<<"\nInvalid Option.";
		
	}
}

void pinnacle::reverse(node *cn)
{
	if(cn->next!=NULL)
	reverse(cn->next);
	if(cn->next==NULL)
	{
	cout<<"\nSr No.\t\tName \t\t PRN No \t\t Post\n";
    }  
	if(cn->prn==1)	
	{
		cout<<rev_no<<"\t\t"<<cn->name<<"\t\t"<<1<<"\t\tPresident\n";
		rev_no++;
	}		
	else if(cn->prn==2)	
	{
		cout<<rev_no<<"\t\t"<<cn->name<<"\t\t"<<2<<"\t\tSecretrary\n";
		rev_no++;
	}
	else
	{
		cout<<rev_no<<"\t\t"<<cn->name<<"\t\t"<<cn->prn<<"\t\tMember\n";	
		rev_no++;	
	}
}


int main()
{
	pinnacle obj1,obj2;
	cout<<"PINNACLE CLUB\n\n";
	obj1.create();
	int v;
	do
	{
		cout<<"\n\nPress 1 display the members\nPress 2 to insert a member\nPress 3 to delete a member\nPress 4 to concatenate club members of 2 divisions\nPress 5 to reverse a members list\nExit press 6\n";
		cin>>v;
		switch(v)
		{
			case 1:obj1.display();
			break;	
			case 2:obj1.insert();
			break;
			case 3:obj1.delet();
			break;
			case 4:
				cout<<"\nCreate second division list\n";
				obj2.create();
				obj1.concat(obj2);
				obj1.display();
			break;
			case 5:obj1.reverse(obj1.pres);
			break;
			case 6:cout<<"\nExitted";
			break;
			default:cout<<"Invalid option";
		}
			
	}while(v!=6);
return 0;
}
