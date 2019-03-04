#include<iostream>
using namespace std;

void quick_sort(int[],int,int);
int partition(int[],int,int);


int main()
{

    cout<<"------------------------------------- Fibonacci Search -------------------------------------"<<endl;
      int arr[1000],j,temp,f,n,size,f1=0,f2=1,flag=0;

      cout<<"\nEnter The Number Of Elements: ";
      cin>>size;
      j=size;

      cout<<"\nEnter The Elements : ";
      for(int i=0;i<size;i++)
      cin>>arr[i];

      quick_sort(arr,0,size-1);

      cout<<"\nThe Sorted Array Is: ";
      for(int i=0;i<size;i++)
      cout<<arr[i]<<" ";
      cout<<endl;



      int fb[size];
      fb[0]=f1;
      fb[1]=f2;

      for(int i=2;i<size;i++)
        fb[i]=fb[i-1]+fb[i-2];

      cout<<"\nFibonacci Series is:";
        for(int i=0;i<size;i++)
        cout<<" "<<fb[i];
        cout<<endl;



  f=size;
  int a=f-3,b=f-2;
  cout<<"\nEnter the Number to be searched: ";
  cin>>n;


do
{
      if(n<arr[f-1])
      {
        f=f-a;
        a=b-a;
        b=a;
      }

      else if(n>arr[f-1])
      {
        f=f+a;
        a=a-b;
        b-=a;
      }

      else
      {
        flag=1;
        break;
      }
        j--;
} while(j!=0);

if(flag==1)
{
  cout<<"\n The Element "<<n<<" Is Present In The Array. "<<endl;
}

else
{
  cout<<"\nElement Not Found!!!\n"<<n<<" Is Not Present In The Array."<<endl;
}

return 0;
}


void quick_sort(int a[],int l,int u)
{
    int j;
    if(l<u)
    {
        j=partition(a,l,u);
        quick_sort(a,l,j-1);
        quick_sort(a,j+1,u);
    }
}



int partition(int a[],int l,int u)
{
    int v,i,j,temp;
    v=a[l];
    i=l;
    j=u+1;

    do
    {
        do
            i++;

        while(a[i]<v&&i<=u);

        do
            j--;
        while(v<a[j]);

        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }while(i<j);

    a[l]=a[j];
    a[j]=v;

    return(j);
}



