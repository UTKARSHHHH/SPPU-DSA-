#include <iostream>
using namespace std;

void Binary_search(int a[],int n)
{
	int small=0,temp=0,beg,end,mid,find,flag=0;
	for(int i=0;i<n-1;i++)
	{
		small=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[small]>a[j])
				small=j;
		}

		temp=a[i];
		a[i]=a[small];
		a[small]=temp;
	}

	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";


	cout<<"Enter The Number To Be Searched: ";
	cin>>find;

	beg=0;
	end=n-1;
	mid=(beg+end)/2;

	while(a[beg]!=a[end])
	{
		if(a[mid]==find)
		{
			flag=1;
			cout<<"The Number Is Found In The List";
		}

		else if(find<a[mid])
		{
			beg=0;
			end=mid-1;
			mid=(beg+end)/2;
		}

		else
		{
			beg=mid+1;
			end=n-1;
			mid=(beg+end)/2;
		}


	}

	if(flag==0)
		cout<<"The Number Is Not Found In The List\n";

}


void Sequential_search(int a[],int n)
{
	int find,flag=0;
	cout<<"Enter The Number To Be Searched: ";
	cin>>find;
	for(int  i=0;i<n;i++)
	{
		if(a[i]==find)
		{
			flag=1;

			if(i==1)
			{
				cout<<"The Number Is Found At "<<i<<"st Location In The Array"<<endl;
				cout<<"And Is Located At The "<<i+1<<"nd Location In The List Of Elements\n";
			}

			else if(i==2)
			{
				cout<<"The Number Is Found At "<<i<<"nd Location In The Array"<<endl;
				cout<<"And Is Located At The "<<i+1<<"rd Location In The List Of Elements\n";
			}

			else if(i==3)
			{
				cout<<"The Number Is Found At "<<i<<"rd Location In The Array"<<endl;
				cout<<"And Is Located At The "<<i+1<<"th Location In The List Of Elements\n";
			}

			else
			{
				cout<<"The Number Is Found At "<<i<<"th Location In The Array"<<endl;
				cout<<"And Is Located At The "<<i+1<<"th Location In The List Of Elements\n";
			}
		}

	}

	if(flag==0)
	{
		cout<<"The Number Is Not To Be Found"<<endl;
	}
}


int main()
{
	int a[30],n;
	cout<<"Enter The Number Of Elements To Be Entered: ";
	cin>>n;
	cout<<"Enter "<<n<<" Numbers:"<<endl;
	for(int  i=0;i<n;i++)
		cin>>a[i];
	//Sequential_search(a,n);
	Binary_search(a,n);
	return 0;
}



