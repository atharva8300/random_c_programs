#include <stdio.h>
#include <conio.h>
void pfactorization(int ,int arr[]);
int isprime(int);
int number_of_factors(int arr[]);
void displayfactors(int d[]);
int main()
{
    int n;
    int a[100]={[0 ... 99] = 1};
    printf("enter number ");
    scanf("%d",&n);
    pfactorization(n,a);
    displayfactors(a);

    getch();
    return 0 ;
}
void pfactorization(int n,int arr[])
{
    int i=2,j=0;
    while(n>=i)
    {
        if(n%i==0 && isprime(i))
        {
            n=n/i;
            arr[j]=i;
            j++;
        }
        else
        {
            i++;
        }
    }
}
int isprime(int m)
{
    int i;
    for(i=2;i<m;i++)
    {
        if(m%i==0)
        {
            return 0;
        }
    }
    return 1 ;
}
void displayfactors(int d[])
{
    int num;
    num = number_of_factors(d);
    printf("\n\n");
    for(int j=0;j<num;j++)
    {
        printf("%d ",d[j]);
    }
}
int number_of_factors(int d[])
{
    int i;
    for( i = 0;i<100;i++)
    {
        if(d[i]==1)
        {
            break ;
        }
    }
    printf("\nnumber of factors = %d\n",i);
    return i ;
}
