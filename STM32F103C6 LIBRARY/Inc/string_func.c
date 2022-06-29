/*
 * string_func.c
 *
 *  Created on: 14 thg 6, 2022
 *      Author: ad
 */
#include "string_func.h"


int string_len(char str[])
{
int len = 0;
	while(str[len] != '\0')
	{len++;}
	return (len-1);
}

int find_str(char str1[], char str2[])
{
	/*
	 * tìm 1 chuỗi str1 có nằm trong chuỗi str2 hay không
	 */
	int match = 0;
	int STRlen = string_len(str1);
	int i = 0;
	int j = 0;
	int test = 0;

	while(((str2[i + STRlen-1] != '\0') | (str2[i + STRlen] != '\0') ) & (match ==0))
	{
	for(j=0; j<= STRlen;j++)
		{
			if(str1[j] == str2[i+j])
			{
				test ++;
				if(test == STRlen+1)
				{
					match =1 ;
				}
			}
		}
	test = 0;
	i++;
	}



	return match;
}

void int2char(int num, char str[])
{
char lstr[30];
int cnt = 0;
int div = 10;
int j = 0;

while( num >= div)
{
	lstr[cnt] = num % div + 0x30;
	num /= 10;
	cnt++;
}
	lstr[cnt] = num + 0x30;
for(j= cnt ; j >=0;j--)
{
	str[cnt-j] = lstr[j];
}
str[cnt+1]='\0';
}

int char2int(char str[])
{
	int result = 0;
	int stop = 0;
	int Strlen = string_len(str);
	int j = 0;
	char check[1];

	for(j=0; j<= Strlen; j++)
	{
		check[0] = str[j];
		if(find_str(check, "0123456789") == 0)
		{
			stop = 1;
			break;
		}
	}
	if(stop == 0)
	{
		for(j=0; j<= Strlen;j++)
		{
			result = result *10 + (str[j] -0x30);
		}
	}

	return result;
}
