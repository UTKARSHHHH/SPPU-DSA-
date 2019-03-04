#include<iostream>
using namespace std;

struct node
{
    bool b;
    node *next;
    node *prev;
};

class binary
{
    node *nn,*head,*cn,*last;

    public:
    binary()
    {
        head=last=NULL;
    }
    void create();
    void ones();
    void twos();
    void display();
    void add(binary a,binary b);
};

void binary::create()
{
    int a,i;
    cout<<"\nEnter no. of bits in binary number=";
    cin>>a;
    
    for(i=0;i<a;i++)
    {
        nn=new node;
        cout<<"Enter "<<i+1<<" bit=";
        cin>>nn->b;
        nn->prev=NULL;
        nn->next=NULL;
        if(head==NULL)
        {
            head=nn;
        }
        else
        {
            cn=head;
            while(cn->next!=NULL)
            {
                cn=cn->next;
            }
            cn->next=nn;
            nn->prev=cn;
        }
    }
    last=cn->next;
}    
    
void binary::display()
{       
    cn=head;
    cout<<"\nThe  binary number = ";  
    while(cn!=NULL)
    {
        cout<<cn->b;
        cn=cn->next;
    }
    cout<<endl;
}

void binary::ones()
{
    cn=head;
    while(cn!=NULL)
    {
        if(cn->b==0)
        cn->b=1;
        else
        cn->b=0;
        cn=cn->next;
    }
	   
}

void binary::twos()
{
    cn=last;
     
     
    while(cn!=NULL)
    {
      	if(cn->b==1)
        break;
        else
        cn=cn->prev;
   }
	cn=cn->prev;
    while(cn!=NULL)
    {
        if(cn->b==0)
        cn->b=1;
        else
        cn->b=0;
        cn=cn->prev;
    }
    
}

void binary::add(binary a1,binary a2)
{
	int sum ,carry=0;
	a1.cn=a1.last;
	a2.cn=a2.last;
	while(a1.cn!=NULL && a2.cn!=NULL)
	{
		nn=new node;
		sum=(a1.cn->b+a2.cn->b+carry)%2;
		carry=(a1.cn->b+a2.cn->b+carry)/2;
		nn->b=sum;
		nn->next=nn->prev=NULL;

		if(head==NULL)
		{
		head=nn;
		last=nn;
		}
		else
		{		
		nn->next=head;
		head->prev=nn;
		head=nn;
		}
		a1.cn=a1.cn->prev;
		a2.cn=a2.cn->prev;
	}
	
	while(a1.cn!=NULL)
	{	sum=(a1.cn->b+carry)%2;
		carry=(a1.cn->b+carry)/2;
		nn=new node;
		nn->b=sum;
		nn->next=nn->prev=NULL;
		if(head==NULL)
		{
		head=nn;
		last=nn;
		}
		else
		{
		nn->next=head;
		head->prev=nn;
		head=nn;
		}
		a1.cn=a1.cn->prev;
	}
	
	while(a2.cn!=NULL)
	{	sum=(a2.cn->b+carry)%2;
		carry=(a2.cn->b+carry)/2;
		nn=new node;
		nn->b=sum;
		nn->next=nn->prev=NULL;
		if(head==NULL)
		{
		head=nn;
		last=nn;
		}
		else
		{
		nn->next=head;
		head->prev=nn;
		head=nn;
		}
		
		a2.cn=a2.cn->prev;
	}
	
	if(carry==1)
	{
		nn=new node;
		nn->b=carry;
		nn->next=nn->prev=NULL;
		if(head==NULL)
		{
		head=nn;
		last=nn;
		}
		else
		{
		nn->next=head;
		head->prev=nn;
		head=nn;
		}
		carry =0;
	}
	
}
    
int main()
{
	    binary obj1,obj2,obj3,obj4,obj5;
        cout<<"        BINARY OPERATIONS";
        int v;
        do
        {
			cout<<"\n\nMenu\n";
			cout<<"\n1 : 1's complement of binary number";
			cout<<"\n2 : 2's complement of binary number";
			cout<<"\n3 : Add 2 binary numbers";
			cout<<"\n4 : Exit\n";
			cin>>v;
			switch(v)
			{
				case 1 : obj1.create();
        				 obj1.display();
        				 obj1.ones();
						 cout<<"\n\nAfter 1's complement "; 
						 obj1.display();
						 break;	
				case 2 : obj2.create();
        				 obj2.display();
        				 obj2.twos();
						 cout<<"\n\nAfter 2's complement "; 
						 obj2.display();
						 break;		 		
				case 3 : cout<<"\nFor first binary number";
						 obj3.create();
        				 obj3.display();
        				 cout<<"\nFor second binary number";
						 obj4.create();
 					     obj4.display();
        				 obj5.add(obj3,obj4);
        				 cout<<"\n\nAfter addition"; 
        				 obj5.display();
        				 break;
        		case 4 : cout<<"\nExitted!";
        				 break;
        		default : cout<<"\nInvalid option!";
        
            }
		}while(v!=4);
    return 0;
}

/*OUTPUT
        BINARY OPERATIONS

Menu

1 : 1's complement of binary number
2 : 2's complement of binary number
3 : Add 2 binary numbers
4 : Exit
1

Enter no. of bits in binary number=4
Enter bit=1
Enter bit=0
Enter bit=1
Enter bit=1

The  binary number = 1011


After 1's complement
The  binary number = 0100


Menu

1 : 1's complement of binary number
2 : 2's complement of binary number
3 : Add 2 binary numbers
4 : Exit
2

Enter no. of bits in binary number=4
Enter bit=1
Enter bit=0
Enter bit=1
Enter bit=1

The  binary number = 1011


After 2's complement
The  binary number = 0101


Menu

1 : 1's complement of binary number
2 : 2's complement of binary number
3 : Add 2 binary numbers
4 : Exit
3

For first binary number
Enter no. of bits in binary number=3
Enter bit=1
Enter bit=1
Enter bit=1

The  binary number = 111

For second binary number
Enter no. of bits in binary number=2
Enter bit=1
Enter bit=0

The  binary number = 10


After addition
The  binary number = 1001


Menu

1 : 1's complement of binary number
2 : 2's complement of binary number
3 : Add 2 binary numbers
4 : Exit
4

Exitted!
--------------------------------
Process exited after 122 seconds with return value 0
Press any key to continue . . .


*/
