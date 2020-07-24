#include <stdio.h>
#include <stdlib.h>

int check_row(int a[3][3],int,int);
int check_column(int a[3][3],int,int);
void print_matrix(int a[3][3]);
void accept_matrix(int a[3][3]);
int main()
{
    int i=0,j=0,row_ans=0,col_ans=0;
    int a[3][3] ;
    accept_matrix(a);
    print_matrix(a);
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            row_ans = check_row(a,a[i][j],i);
            col_ans = check_column(a,a[i][j],j);
            if(row_ans == 1 && col_ans == 1)
            {
                printf("\nsaddle point at [%d,%d]\n",i,j);
            }
        }
    }
    getch();
    return 0;
}
int check_row(int a[3][3],int val,int row_num)
{
    int k=0;
    for(k=0;k<3;k++)
    {
        if(a[row_num][k]>val)
        {
            return 0;
        }
    }
    return 1;
}
int check_column(int a[3][3],int val,int col_num)
{
    int k=0;
    for(k=0;k<3;k++)
    {
        if(a[k][col_num]<val)
        {
            return 0;
        }

    }
    return 1;
}
void print_matrix(int a[3][3])
{
    for(int i =0 ;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}
void accept_matrix(int a[3][3])
{
    printf("\nenter elements of a 3*3 matrix\n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("a[%d][%d] = ",i,j);
            scanf("%d",&a[i][j]);
        }
        printf("\n");
    }
}
