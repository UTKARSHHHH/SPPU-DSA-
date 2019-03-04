#include<iostream>
using namespace std;

class pizza
{
	int q[10];
	int f,r;
	
	public:
		pizza()
		{
			f=r=-1;
		}
		
		
		void enqueue()
		{
			if(isfull())
			{
				cout<<"\nNo more orders can be placed at this moment.";
			}
			else
			{
				if(isempty())
				{
					r=r+1;
					f=f+1;
					q[r]=r+1;
				}
				else
				{
					r=(r+1)%10;
					q[r]=r+1;	
				}
				cout<<"Order successfully placed. Your order no. =  "<<q[r];
			}
			
		}
	
	
	void dequeue()
	{
		if(isempty())
		cout<<"\nNo more orders pending";
		
		else
		{
			cout<<"\n Order "<<q[f] <<" is ready!";
			f=(f+1)%10;
			if(f==r)
			f=r=-1;
		}
		
	}
	
	
	bool isempty()
	{
		if(f==-1)
		return 1;
		else
		return 0;
	}
	
			
	bool isfull()
	{
		if(f==(r+1)%10)
		return 1;
		else
		return 0;
		
	}
		
	void display()
	{
		cout<<"\nThe orders pending are ";
		for(int i=f;i<=r;i++)
		cout<<q[i]<<"  ";
	}
	
	
 }; 
 
 
 int main()
 {
 	int v;
 	pizza p;
 	do
 	{
 		cout<<"\n\n    Pizza Delivery "<<endl<<endl;
 		cout<<"1 : Place the order";
 		cout<<"\n2 : Display the orders pending";		
 		cout<<"\n3 : Display the orders ready";
 		cout<<"\n4 : Exit";
 		cout<<"\nEnter your choice = ";
 		cin>>v;
 		switch(v)
 		{
 			case 1:
 				p.enqueue();
 				break;
 			
 			case 2:
 				p.display();
 				break;
 			
 			case 3:
 				p.dequeue();
 				break;
 			
 			case 4:
 				cout<<"\nExitted!\n";
 				break;
 			
 			default:cout<<"\nInvalid choice";
		 }
 		
 		
    }while(v!=4);
 	 	
 	return 0;
 }
