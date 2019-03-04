#include<iostream>
using namespace std;
#define size 20
class dequ
{
    int a[40],front,rear;
public:
    dequ()
    {
        front=-1;
        rear=-1;
    }

    int is_dq_empty()
    {
        if(front==-1 && rear==-1)
            return 1;
        else
            return 0;
    }

    int is_dq_full()
    {
        if(rear==size-1)
            return 1;
        else
            return 0;
    }
    void insert_start(int x)
    {
        if(is_dq_full())
            cout<<"\n Queue is full";
        else if(front==0 && rear<size-1)
        {
            for(int i=rear;i>=front;i--)
            {
                a[i+1]=a[i];
            }
            a[front]=x;
            rear++;
        }
        else if(is_dq_empty())
        {
            front++;
            rear++;
            a[rear]=x;
        }
}

   void insert_end(int y)
    {
        if(is_dq_full())
            cout<<"\n Queue is full";
        else if(front==0 && rear<size-1)
        {
            rear++;
            a[rear]=y;
        }
        else if(is_dq_empty())
        {
            front++;
            rear++;
            a[rear]=y;
        }
    }

    void delete_front()
    {
        if(is_dq_empty())
            cout<<"\n Queue is empty..cannot delete";
        else
            front++;
    }

    void delete_end()
    {
       if(is_dq_empty())
            cout<<"\n Queue is empty..cannot delete";
        else
            rear--;
    }

    void display()
    {
        if(is_dq_empty())
            cout<<"\n Queue is empty..can't display";

        for(int i=front;i<=rear;i++)
        {
            cout<<a[i]<<" ";
        }
    }

};
int main()
{
    dequ d;
    int a,b,ch,c;
    int p,e;
    do
    {
        cout<<"\n Enter 1 to insert at start \n Enter 2 to insert at last";
        cout<<"\n Enter 3 to display \n Enter 4 to delete from front \n Enter 5 to delete from end";
        cin>>ch;
        switch(ch)
        {
        case 1:
            cout<<"\n Enter element";
            cin>>a;
            d.insert_start(a);
            break;
        case 2:
            cout<<"\n Enter element";
            cin>>b;
            d.insert_end(b);
            break;
        case 3:
                d.display();
                break;
        case 4:
             cout<<"\n Deleting an element from front";
             d.delete_front();
             break;
        case 5:
            cout<<"\n Deleting an element from end";
            d.delete_end();
            break;
        }
          cout<<"\n do u want to continue";
          cin>>ch;
    }while(ch==1);
    return 0;
}



