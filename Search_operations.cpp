#include<iostream>
using namespace std;
#define M 100

class search
{
        int list[M],n;
public:
        void getn();
        void accept();
        void display();
        void NRBS();
        void seq_search();
        void sentinal_search();
        int fibo(int k);
        int fibonacci_search();
};

void search::getn()
{
        cout<<"\nEnter the number of students attending the workshop : ";
        cin>>n;
}

void search::accept()
{
    if(n!=0)
    {
        cout<<"\nEnter the list of roll numbers(in ascending order) who are attending the workshop : ";
        for(int i=0;i<n;i++)
        {
                cout<<"\n"<<i+1<<". ";
                cin>>list[i];
        }
    }
     else
         cout<<"\nNO RECORD FOUND!!!\nNumber of students not entered yet.";
}

void search::display()
{
    if(n!=0)
    {
        cout<<"\nThe list of roll numbers who have attended the workshop is as follows : \n";
        for(int i=0;i<n;i++)
        {
                cout<<"\n"<<i+1<<". "<<list[i];
        }
        cout<<"\n";
    }
    else
         cout<<"\nNO RECORD FOUND!!!\nNumber of students not entered yet.";
}

void search::NRBS()
{
    if(n!=0)
    {
        int low=0,high=n-1,mid,flag=0,key;
        cout<<"\nEnter the roll number to be searched : ";
        cin>>key;
        while(low<=high)
        {
                mid=low+high/2;
                if(key==list[mid])
                {
                        cout<<"\nRoll Number Found!!!The student is attending the workshop.\n";
                        flag=1;
                        break;
                }
                else if(key<list[mid])
                        high=mid-1;
                else
                        low=mid+1;
        }
        if(flag==0)
                   cout<<"\nRoll number NOT found!!!\nThe student is NOT attending the workshop.\n";
    }
    else
        cout<<"\nNO RECORD FOUND!!!\nNumber of students not entered yet.";

}

void search::seq_search()
{
    if(n!=0)
    {
        int key;
        cout<<"\nEnter the Roll number to be searched : ";
        cin>>key;
        int flag=0;
        for(int i=0;i<n;i++)
        {
            if(list[i]==key)
            {
                cout<<"\nRoll Number Found!!!The student is attending the workshop.\n";
                flag=1;
                break;
            }
        }
        if(flag==0)
            cout<<"\nRoll number NOT found!!!\nThe student is NOT attending the workshop.\n";
    }
    else
            cout<<"\nNO RECORD FOUND!!!\nNumber of students not entered yet.";
}

void search::sentinal_search()
{
    if(n!=0)
    {
        int key,i;
        cout<<"\nEnter the roll number to be searched : ";
        cin>>key;
        list[n]=key;
        for(i=0;i<=n;i++)
        {
            if(list[i]==key)
                break;
        }
        if(i==n)
            cout<<"\nRoll number NOT found!!!\nThe student is NOT attending the workshop.\n";
        else
            cout<<"\nRoll Number found!!!The student is attending the workshop.\n";
    }
    else
            cout<<"\nNO RECORD FOUND!!!\nNumber of students not entered yet.";
}

int search::fibo(int k)
{
    if(k==0)
        return 0;
    if(k==1)
        return 1;
    else
        return (fibo(k-1)+fibo(k-2));
}
int search::fibonacci_search()
{
    if(n!=0)
    {
        int f,f1,f2,t,mid,j,key;
        j=1;
        cout<<"\nEnter the roll number to be searched : ";
        cin>>key;
        while(fibo(j)<=n)
            j++;
        f=fibo(j);
        f1=fibo(j-2);
        f2=fibo(f-3);
        mid=n-f1+1;
        while(key!=list[mid])
        {
            if(mid<0 || key>list[mid])
            {
                if(f1==1)
                    return -1;
                mid=mid+f2;
                f1=f1-f2;
                f2=f2-f1;
            }
            else
            {
                if(f2==0)
                    return -1;
                mid=mid-f2;
                t=f1-f2;
                f1=f2;
                f2=t;
            }
        }
        return mid;
    }
    else
    {
        cout<<"\nNO RECORD FOUND!!!\nNumber of students not entered yet.";
        return -1;
    }
}

int main()
{
    int k;
    int op;
    char ch;
    search s;
    do
    {
        cout<<"\nEnter\n1 - To enter the total number of students.\n2 - To enter the roll numbers of the students attending workshop.\n3 - To display the list of students attending the workshop.\n4 - Binary Search\n5 - Sequential search\n6 - Sentinel search\n7 - Fibonacci search.\n";
        cin>>op;
        switch(op)
        {
        case 1:s.getn();
            break;

        case 2:s.accept();
            break;

        case 3: s.display();
            break;

        case 4:s.NRBS();
            break;

        case 5:s.seq_search();
            break;

        case 6:s.sentinal_search();
            break;

        case 7:k=s.fibonacci_search();
            if(k==-1)
                cout<<"\nRoll number NOT found!!!\nThe student is NOT attending the workshop.\n";
            else
                cout<<"\nRoll Number found!!!The student is attending the workshop.\n";
            break;

        default:
            cout<<"\nInvalid entry!!!";
        }
        cout<<"\nDo you want to continue??? Enter (y/n) : ";
        cin>>ch;
    }while(ch=='y');
    return 0;
}


