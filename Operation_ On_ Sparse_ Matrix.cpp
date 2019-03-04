#include<iostream>
using namespace std;



class sparse
{
    
    int m[20][3];
    
    public:
        void getdata();
        void add(sparse ,sparse );
        void stranspose(sparse);
        void ftranspose(sparse);
        void display();
};

void sparse::getdata()
{
        int i;
        
        cout<<"\nEnter number of rows of sparse matrix:\n";
        cin>>m[0][0];
        cout<<"\nEnter number of columns of sparse matrix:\n";
        cin>>m[0][1];
        cout<<"\nEnter number of non zero elements of sparse matrix:\n";
        cin>>m[0][2];
        

    for(i=1;i<=m[0][2];i++)
    {
        
                cout<<"\nEnter row:";
                cin>>m[i][0];
				if(m[i][0]>=m[0][0])
				{
					cout<<"\nError: Row index cannot be greater than or equal to number of rows";
					i=i-1;
					cout<<"\n\nAgain\t";
				}
				else
				{
                cout<<"Enter column:";
                cin>>m[i][1];
                if(m[i][1]>=m[0][1])
				{
					cout<<"\nError: Column index cannot be greater than or equal to number of columns";
					i=i-1;
					cout<<"\n\nAgain\t";
				}
				else
				{
			    cout<<"Enter non zero value:";
                cin>>m[i][2];
                }
                
                }
    }
} 
void sparse::display()
{
int i,j;
for(i=0;i<=m[0][2];i++)
{
  for(j=0;j<3;j++)
  {
   cout<<m[i][j]<<"\t";
  }
  if(i==0)
  cout<<"\n-----------------";
  cout<<"\n";
}    

cout<<"\n";

}




void sparse::add(sparse s1,sparse s2)
{
    if(s1.m[0][0]==s2.m[0][0]&&s1.m[0][1]==s2.m[0][1])
        {
        	
            int i=1,j=1,k=1;
            m[0][0]=s1.m[0][0];
            m[0][1]=s1.m[0][1];
            
        while(i<=s1.m[0][2]&&j<=s2.m[0][2])
        {
            if(s1.m[i][0]==s2.m[j][0])//row if
            {
                    if(s1.m[i][1]==s2.m[j][1])//col if
                    {
                    m[k][0]=s1.m[i][0];
                    m[k][1]=s1.m[i][1];
                    m[k][2]=s1.m[i][2]+s2.m[j][2];
                    i++;j++;k++;
                    }
    
                    else if(s1.m[i][1]<s2.m[j][1])//col elseif
                    {
                    m[k][0]=s1.m[i][0];
                    m[k][1]=s1.m[i][1];
                    m[k][2]=s1.m[i][2];
                    i++;k++;
                    }
                    else                      //col else
                    {
                    m[k][0]=s2.m[j][0];
                    m[k][1]=s2.m[j][1];
                    m[k][2]=s2.m[j][2];
                    j++;k++;
                    }
          }
          
          else if(s1.m[i][0]<s2.m[j][0])//row elseif

                {
                m[k][0]=s1.m[i][0];
                m[k][1]=s1.m[i][1];
                m[k][2]=s1.m[i][2];
                i++;k++;
                }
          else                      //row else
                {
                m[k][0]=s2.m[j][0];
                m[k][1]=s2.m[j][1];
                m[k][2]=s2.m[j][2];
                j++;k++;
                }
          
        }  
    
    
    
    while(i<=s1.m[0][2])//remaining s1
            {
            m[k][0]=s1.m[i][0];
            m[k][1]=s1.m[i][1];
            m[k][2]=s1.m[i][2];
            i++;k++;
            }
    
    while(j<=s2.m[0][2])//remaining s2
            {
            m[k][0]=s2.m[j][0];
            m[k][1]=s2.m[j][1];
            m[k][2]=s2.m[j][2];
            j++;k++;
            }


        m[0][2]=k-1;
        cout<<"\nThe sum :\n";
        display();
    }
            
        else
        {
            cout<<"\n Sorry! Matrix cannot be added :(\n";
        
		}

  
}

void sparse::stranspose (sparse s1)      
{ 
    m[0][0]=m[0][0]=s1.m[0][1];     
    m[0][1]=m[0][1]=s1.m[0][0];
    m[0][2]=s1.m[0][2];     
    int k=1;
    for(int i=0;i<s1.m[0][1];i++)   
    {             
     for(int j=1;j<=s1.m[0][2];j++)   
     {                    
        if(s1.m[j][1]==i)
        {
         m[k][0]=s1.m[j][1];                                             
         m[k][1]=s1.m[j][0];                       
         m[k][2]=s1.m[j][2]; 
         k++;                     
        }     
     }          
    } 
                    
} 




void sparse::ftranspose(sparse s1)
{
    int terms[s1.m[0][1]];
    int rpose[s1.m[0][1]];
       m[0][0]=s1.m[0][1];     
    m[0][1]=s1.m[0][0];
    m[0][2]=s1.m[0][2];   
    
    for(int i=0;i<s1.m[0][1];i++)
    {
        terms[i]=0;
        //rpose[i]=0;
    }
    
    
    for(int i=1;i<=s1.m[0][2];i++)
    {
        terms[s1.m[i][1]]++;
    }
    rpose[0]=1;
    for(int i=1;i<s1.m[0][1];i++)
    {
        rpose[i]=rpose[i-1]+terms[i-1];
    }
    for(int i=1;i<=s1.m[0][2];i++)
    {
        int r=rpose[s1.m[i][1]];
        m[r][0]=s1.m[i][1];
        m[r][1]=s1.m[i][0];
        m[r][2]=s1.m[i][2];
        rpose[s1.m[i][1]]++;    
    }
    
    
    
     
}


int main()
{
    

    sparse s1,s2,s3,s4,s5,s6,s7;
    int v,cont=1;
do
{
    
    cout<<"\n\nWhich operation do you want to perform?\nFor addition press 1\nFor simple transpose press 2\nFor fast transpose press 3\n";
    cin>>v;
    switch(v)
    {
    case 1:cout<<"\nEnter first sparse matrix triplet:\n";
           s1.getdata();
           cout<<"\nEntered matrix is:\n";
           s1.display();
           cout<<"\nEnter second sparse matrix triplet:\n";
           s2.getdata();
           cout<<"\nEntered matrix is:\n";
           s2.display();
           s3.add(s1,s2);
           
           break;
    case 2:cout<<"\nEnter sparse matrix triplet:\n";
           s4.getdata();
           cout<<"\nEntered matrix is:\n";
           s4.display();
           s5.stranspose(s4);
           cout<<"\nThe simple transpose :\n";
           s5.display();
           break;  
    case 3:cout<<"\nEnter sparse matrix triplet:\n";
           s6.getdata();
           cout<<"\nEntered matrix is:\n";
           s6.display();
           s7.ftranspose(s6);
           cout<<"\nThe fast transpose :\n";
           s7.display();
           break;
    default:cout<<"\nInvalid option\n";

    }
cout<<"\nDo you want to continue?\nIf yes press 1 OR no press 0\n";
cin>>cont;
}while(cont==1);

return 0;

}



Which operation do you want to perform?
For addition press 1
For simple transpose press 2
For fast transpose press 3
1

Enter first sparse matrix triplet:

Enter number of rows of sparse matrix:
4

Enter number of columns of sparse matrix:
5

Enter number of non zero elements of sparse matrix:
4

Enter row:0
Enter column:1
Enter non zero value:6

Enter row:1
Enter column:1
Enter non zero value:5

Enter row:1
Enter column:3
Enter non zero value:7

Enter row:2
Enter column:1
Enter non zero value:8

Entered matrix is:
4       5       4
-----------------
0       1       6
1       1       5
1       3       7
2       1       8


Enter second sparse matrix triplet:

Enter number of rows of sparse matrix:
4

Enter number of columns of sparse matrix:
5

Enter number of non zero elements of sparse matrix:
5

Enter row:0
Enter column:3
Enter non zero value:6

Enter row:1
Enter column:1
Enter non zero value:8

Enter row:1
Enter column:4
Enter non zero value:9

Enter row:2
Enter column:1
Enter non zero value:5

Enter row:3
Enter column:0
Enter non zero value:20

Entered matrix is:
4       5       5
-----------------
0       3       6
1       1       8
1       4       9
2       1       5
3       0       20


The sum :
4       5       7
-----------------
0       1       6
0       3       6
1       1       13
1       3       7
1       4       9
2       1       13
3       0       20


Do you want to continue?
If yes press 1 OR no press 0
1


Which operation do you want to perform?
For addition press 1
For simple transpose press 2
For fast transpose press 3
2

Enter sparse matrix triplet:

Enter number of rows of sparse matrix:
4

Enter number of columns of sparse matrix:
5

Enter number of non zero elements of sparse matrix:
4

Enter row:0
Enter column:1
Enter non zero value:6

Enter row:1
Enter column:0
Enter non zero value:8

Enter row:2
Enter column:2
Enter non zero value:7

Enter row:3
Enter column:1
Enter non zero value:8

Entered matrix is:
4       5       4
-----------------
0       1       6
1       0       8
2       2       7
3       1       8


The simple transpose :
5       4       4
-----------------
0       1       8
1       0       6
1       3       8
2       2       7


Do you want to continue?
If yes press 1 OR no press 0
1


Which operation do you want to perform?
For addition press 1
For simple transpose press 2
For fast transpose press 3
3

Enter sparse matrix triplet:

Enter number of rows of sparse matrix:
3

Enter number of columns of sparse matrix:
3

Enter number of non zero elements of sparse matrix:
3

Enter row:0
Enter column:1
Enter non zero value:6

Enter row:1
Enter column:0
Enter non zero value:5

Enter row:2
Enter column:1
Enter non zero value:9

Entered matrix is:
3       3       3
-----------------
0       1       6
1       0       5
2       1       9


The fast transpose :
3       3       3
-----------------
0       1       5
1       0       6
1       2       9


Do you want to continue?
If yes press 1 OR no press 0
0

--------------------------------
