#include<iostream>      
#include<string>
using namespace std;
struct node
{
    bool status;
    string name;
    node *next;
    node *prev;
};

class cinemax
{
    node *nn;
    public:
    node *head[10];
    void create();
    void display();
    void booking();
    void cancellation();
    void details();
    cinemax()
    {
    for(int i=0;i<10;i++)
    {
    head[i]=NULL;
    }
    }
};

void cinemax::create()
{
    int i,j;
    for(i=0;i<10;i++)
    {
        for(j=1;j<=7;j++)
        {
            nn=new node;
            nn->status=0;
            nn->name="";
            nn->next=nn->prev=NULL;
            if(head[i]==NULL)
            {
            head[i]=nn;
            nn->prev=nn->next=head[i];
            }
            else
            {
                node *cn;
                cn=head[i];
                while(cn->next!=head[i])
                {
                    cn=cn->next;
                }
            cn->next=nn;
            nn->prev=cn;
            nn->next=head[i];
            head[i]->prev=nn;
                        
            }        
        }
    }


}

void cinemax::display()
{
    int i,j;
    for(j=1;j<=7;j++)
    {
        cout<<"\t"<<j;
    }
    cout<<endl;
    for(i=0;i<10;i++)
    {
    cout<<i+1<<"\t";
    node *cn;
    cn=head[i];
    do
    {
        if(cn->status==0)
        cout<<"A\t";
        else
        cout<<"B\t";
        cn=cn->next;
    }while(cn!=head[i]);
    cout<<endl;
    }
}


void cinemax::booking()
{
    int r,s;
    cout<<"\nFOR BOOKING\n\nEnter row number: ";
    cin>>r;
    cout<<"\nEnter seat number: ";
    cin>>s;
    if((r>0&&r<11)&&(s>0&&s<8))
    {
        node *cn;
        cn=head[r-1];
        for(int j=1;j<s;j++)
        {
            cn=cn->next;
        }
        if(cn->status==0)
        {
            cn->status=1;
            cout<<"\nEnter name:";
            cin>>cn->name;
            cout<<"\nYour seat is booked!";
        }
        else
        {
            cout<<"\nSorry! Seat is already booked.";
        }
    }
    else
    {
        cout<<"\nInvalid entry of row number or seat number";
    }
}
void cinemax::cancellation()
{
    int r,s;
    cout<<"\nFOR CANCELLATION\n\nEnter row number: ";
    cin>>r;
    cout<<"\nEnter seat number: ";
    cin>>s;
    if((r>0&&r<11)&&(s>0&&s<8))
    {
        node *cn;
        cn=head[r-1];
        for(int j=1;j<s;j++)
        {
            cn=cn->next;
        }
        if(cn->status==1)
        {
            cn->status=0;
            cout<<"\nSeat is cancelled!";
        }
        else
        {
            cout<<"\nSeat is not booked.";
        }
    }
    else
    {
        cout<<"\nInvalid entry of row number or seat number";
    }
}

void cinemax::details()
{
    int r,s;
    cout<<"\nFOR DETAILS OF THE BOOKER\n\nEnter row number: ";
    cin>>r;
    cout<<"\nEnter seat number: ";
    cin>>s;
    if((r>0&&r<11)&&(s>0&&s<8))
    {
        node *cn;
        cn=head[r-1];
        for(int j=1;j<s;j++)
        {
            cn=cn->next;
        }
        if(cn->status==1)
        {
            cn->status=1;
            cout<<"\nName of the booker="<<cn->name;
        }
        else
        {
            cout<<"\nSeat is not booked.";
        }
    }
    else
    {
        cout<<"\nInvalid entry of row number or seat number";
    }
}
int main()
{
    cinemax obj;
    obj.create();
    int o;
    do
    {
    cout<<"\n\nCINEMAX\n\nFor booking press 1\nFor cancellation press 2\nFor displaying the seats press 3\nTo display details of the booker press 4\nEXIT press 5\n";
    cin>>o;
    switch(o)
    {
        case 1:obj.booking();
        break;    
        case 2:obj.cancellation();
        break;
        case 3:obj.display();
        break;
        case 4:obj.details();
        break;
        case 5:cout<<"\nExitted!\n";
        break;
        default:cout<<"\nInvalid option";    
    }
    }while(o!=5);
return 0;
}
