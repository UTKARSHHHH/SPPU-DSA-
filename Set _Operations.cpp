#include<iostream>
using namespace std;
class student
{
        int no;
        int rno[30];
    public:
        void getdata();
        void display();
        void uni(student,student);
        void in(student ,student);
        void diff(student ,student);
};

void student::getdata()
{
        cout<<"\nEnter number of students:";
        cin>>no;
        int i;
        cout<<"Enter roll number of students:";
        for(i=0;i<no;i++)
        {
        cin>>rno[i];
        }

}

void student:: display()
{              

        int i;
        cout<<"{";
        for(i=0;i<no;i++)
        {
        cout<<rno[i];
        if(i!=no-1)
        {
        cout<<",";
        }

        }
        cout<<"}";

cout<<"\nNumber of students="<<no<<endl;
}

void student::uni(student a,student b)
    {
        int counter=0;
        int i,j,flag;

        for(i=0;i<a.no;i++)
        {
                rno[i]=a.rno[i];
                counter++;
        }

        for(i=0;i<b.no;i++)
        {
                flag=0;
                for(j=0;j<a.no;j++)
                {
                        if(b.rno[i]==a.rno[j])
                        {
                                flag=1;
                                break;

                        }
                }
                if(flag==0)
                        {
                                rno[counter]=b.rno[i];
                                counter++;              
                        }


        }
no=counter;
    }

void student:: in(student a,student b)
{
        int counter=0;
        int i,j,flag;
        for(i=0;i<b.no;i++)
        {
                flag=0;
                for(j=0;j<a.no;j++)
                {
                        if(b.rno[i]==a.rno[j])
                        {
                                flag=1;
                                break;

                        }
                }

                        if(flag==1)
                        {
                                rno[counter]=b.rno[i];
                                counter++;
                        }
     }
        no=counter;
}

void student:: diff(student a,student b)
{       
        int counter=0,flag,i,j;
        for(i=0;i<a.no;i++)
        {
                flag=0;
                for(j=0;j<b.no;j++)
                {
                        if(a.rno[i]==b.rno[j])
                        {
                                flag=1;
                                break;

                        }
                }
                if(flag==0)
                        {
                                rno[counter]=a.rno[i];
                                counter++;              
                        }
	  }
no=counter;     
}
int main()

{       int cont=1;
        student tot,cri,bad,un,intr,Adiff,Bdiff,neither;
        cout<<"\nEnter data for total students present in class:\n ";
        tot.getdata();
        cout<<"\nEnter data for total students playing cricket:\n ";
        cri.getdata();
        cout<<"\nEnter data for total students playing badminton:\n ";
        bad.getdata();
        cout<<"\nSet of total students in class:\n";
        tot.display();
        cout<<"\n\nSet of students playing cricket:\n";
        cri.display();
        cout<<"\n\nSet of students playing badminton:\n";
        bad.display();
        cout<<"\n\nSet operations:\n\n";
        int x;
        do
        {
		
        cout<<"\n\nPress 1 for the set of students who play either cricket or badminton or both";
        cout<<"\nPress 2 for the set of students who play both cricket and badminton";
		cout<<"\nPress 3 for the set of students who play only cricket";
		cout<<"\nPress 4 for the set of students who play only badminton";
		cout<<"\nPress 5 for the set of students who play neither cricket nor badminton";
		cout<<"\nExit: Press 6\n";
		cin>>x;
		switch(x)
		{
		case 1:
        		cout<<"\nSet of students who play either cricket or badminton or both (union):\n";
        		un.uni(cri,bad);
        		un.display();
        		break;
        case 2:
				cout<<"\nSet of students who play both cricket and badminton(intersection):\n";
		        intr.in(cri,bad);
		        intr.display();
		        break;
		case 3:
		        cout<<"\nSet of students who play only cricket:\n";
		        Adiff.diff(cri,bad);
		        Adiff.display();
		        break;
        case 4:
				cout<<"\nSet of students who play only badminton:\n";
		        Bdiff.diff(bad,cri);
		        Bdiff.display();
		        break;
	    case 5:
				cout<<"\nSet of students who play neither cricket nor badminton:\n";
		        un.uni(cri,bad);
		        neither.diff(tot,un);
		        neither.display();
		        break;
		case 6:	cout<<"\nExitted! ";
			break;
		default:
			cout<<"\nInvalid option ";


	}
	}while(x!=6);


return 0;
}


