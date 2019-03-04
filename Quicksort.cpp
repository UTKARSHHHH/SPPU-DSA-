#include<stdio.h>
void quicksort(float [],int,int);
int partition(float [],int, int);
int main()
{
    int n,i,op;
    float a[30];

    do
    {
        printf("\n 1)Quick Sort \n 2)Quit");
        printf("\n Enter your choice : ");
        scanf("%d",&op);
        if(op==1)
        {
            printf("\n Enter no. of elements :");
            scanf("%d",&n);
            printf("\n Enter array elements :");
            for(i=0;i<n;i++)
                scanf("%f",&a[i]);
            quicksort(a,0,n-1);
            printf("\n Sorted array is :");
            for(i=n-1;i>=n-5;i--)
                printf("%7.2f",a[i]);
        }

    }while(op!=2);
    return 0;
}

void quicksort(float a[],int l, int u)
{
    int j;
    if(l<u)
    {
        j=partition(a,l,u);
        quicksort(a,l,j-1);
        quicksort(a,j+1,u);
    }
}


int partition(float a[],int l,int u)
{
    int i,j;
    float v,temp;
    v=a[l];
    i=l;
    j=u+1;

    do
    {
        do
        {
            i++;

        }while(a[i]<v && i<=u);
        do
        {
            j--;
        }while(a[j]>v);
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }while(i<j);
    a[l]=a[j];
    a[j]=v;
    printf("\n Partition point = %d",j);
    printf("  List : ");
    for(i=l;i<=u;i++)
        printf("%7.2f",a[i]);
    return(j);
}




/*OUTPUT;
 *
 *
 *
 1)Quick Sort
 2)Quit
 Enter your choice : 01

 Enter no. of elements :5

 Enter array elements :9
3
7
2
8

 Partition point = 4  List :    8.00   3.00   7.00   2.00   9.00
 Partition point = 3  List :    2.00   3.00   7.00   8.00
 Partition point = 0  List :    2.00   3.00   7.00
 Partition point = 1  List :    3.00   7.00
 Sorted array is :   9.00   8.00   7.00   3.00   2.00
 1)Quick Sort
 2)Quit
 Enter your choice : 2
 */



