#include <stdio.h>
#include <conio.h>
#include <string.h>
void str_to_arr(char a[],int b[]);
void append_zeros(int divid[],int lengen,int lendivid);
void final_sent_data(int divid[],int gen[],int final[],int,int);
void display_arr(int [],int);
void left_shift(int [],int);
void final_check(int [],int , int [],int);
int checktemp(int [],int);
int main()
{
    int dividend_arr[20],generator_arr[10];
    int final_data[20],rec_data[20];
    char dividend_str[20],rec_data_str[20];
    char generator_str[20];
    int len_gen,len_dividend,len_rec;
    printf("enter generator");
    gets(generator_str);
    printf("enter dividend");
    gets(dividend_str);
    str_to_arr(dividend_str,dividend_arr);
    str_to_arr(generator_str,generator_arr);
    len_gen = strlen(generator_str);
    len_dividend = strlen(dividend_str);
    append_zeros(dividend_arr,len_gen,len_dividend);
    len_dividend = len_dividend + len_gen - 1;
    display_arr(dividend_arr,len_dividend);
    final_sent_data(dividend_arr,generator_arr,final_data,len_gen,len_dividend);
    printf("\nFINAL MESSAGE SENT:::\n ");
    display_arr(final_data,len_dividend);
    printf("\n\n receiver's end\n\n");
    printf("enter received data:\n");
    gets(rec_data_str);
    str_to_arr(rec_data_str,rec_data);
    len_rec = strlen(rec_data_str);
    final_check(rec_data,len_rec,generator_arr,len_gen);
    getch();
    return 0 ;
}
void display_arr(int a[],int len)
{
    for(int i=0;i<len;i++){
        printf("%d",a[i]);
    }
    printf("\n");
}
void str_to_arr(char a[],int b[])
{
    int i = 0 ;
    while(a[i]!= '\0'){
        b[i] = a[i]-48;
        i++;
    }
    display_arr(b,i);
}
void append_zeros(int divid[],int lengen,int lendivid)
{
    int i;
    for(i=0;i<lengen-1;i++)
    {
        divid[lendivid+i] = 0;
    }
    display_arr(divid,lendivid+lengen -1);
}
void final_sent_data(int divid[],int gen[],int finaldata[],int len_gen,int len_dividend)
{
    int j= 1 ;
    int div_index = len_gen ;
    int rem[10] = {0};
    printf("length of divisor = %d, length of dividend = %d\n",len_gen,len_dividend);
    for(int i=0 ; i<len_gen;i++){
        rem[i] = divid[i];
    }
    while(div_index < len_dividend){
        if(checktemp(rem,len_gen)){
            for(int i=0;i<len_gen;i++){
                if(rem[i]==gen[i]){
                    rem[i]=0;
                }

                else{
                    rem[i]=1;
                }
            }
            left_shift(rem,len_gen);
            rem[len_gen-1] = divid[div_index] ;
            div_index++ ;
        }
        else{
            left_shift(rem,len_gen);
            rem[len_gen-1] = divid[div_index] ;
            div_index++;
        }
    }
    printf("final remainder: \n");
    display_arr(rem,len_gen);
    for(int i =0 ;i<len_dividend;i++){
        finaldata[i] = divid[i];
    }

    for(int i = len_dividend-len_gen+1; i< len_dividend ; i++,j++){
        finaldata[i] = rem[j];
    }
}
int checktemp(int temp[],int len)
{
    if (temp[0] == 1){
        return 1;
    }
    else {
        return 0;
    }
}
void left_shift(int a[],int len)
{
    for(int i=0;i<len;i++){
        a[i] = a[i+1] ;
    }
}
void final_check(int rec[],int len_rec,int gen[],int len_gen)
{
    int j= 1,flag =0 ;
    int div_index = len_gen ;
    int rem[10] = {0};
    printf("length of divisor = %d, length of rec = %d\n",len_gen,len_rec);
    for(int i=0 ; i<len_gen;i++){
        rem[i] = rec[i];
    }
    while(div_index < len_rec){
        if(checktemp(rem,len_gen)){
            for(int i=0;i<len_gen;i++){
                if(rem[i]==gen[i]){
                    rem[i]=0;
                }

                else{
                    rem[i]=1;
                }
            }
            left_shift(rem,len_gen);
            rem[len_gen-1] = rec[div_index] ;
            div_index++ ;
        }
        else{
            left_shift(rem,len_gen);
            rem[len_gen-1] = rec[div_index] ;
            div_index++;
        }
    }
    printf("final remainder: \n");
    display_arr(rem,len_gen);
    for(int i=0;i<len_gen;i++){
        if(rem[i] != 0){
            flag = 1 ;
            break ;
        }
    }
    if(flag == 0){
        printf("\n\n~~~~~~~~~Accepted~~~~~~~~\n\n");
    }
    else{
        printf("\n\n~~~~~~~~~rejected~~~~~~~~~~\n\n");
    }
}
