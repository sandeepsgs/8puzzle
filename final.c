#include<stdio.h>
#include<string.h>
char p[3][3],g[3][3];
void strcpy1(char s[3][3],char p[3][3])
{
	int i,j;
	for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	s[i][j]=p[i][j];
	}
int h_x(char s[3][3],char g[3][3])
{
int i,j,c=0;
for(i=0;i<3;i++)
{
	for(j=0;j<3;j++)
	{
		if((s[i][j]!=g[i][j])&&(s[i][j]!='_'))
		c++;
	}
}
return c;
}
void up(char s[3][3],int r,int c)
{
	char t=s[r-1][c];
	s[r-1][c]=s[r][c];
	s[r][c]=t;
}

void down(char s[3][3],int r,int c)
{
	char t=s[r+1][c];
	s[r+1][c]=s[r][c];
	s[r][c]=t;
}
void left(char s[3][3],int r,int c)
{
	char t=s[r][c-1];
	s[r][c-1]=s[r][c];
	s[r][c]=t;
}
void right(char s[3][3],int r,int c)
{
	char t=s[r][c+1];
	s[r][c+1]=s[r][c];
	s[r][c]=t;
}
void print(char m[3][3],char c[3][3],char s[3][3])
{
	int i,j;
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
printf("%4c",m[i][j]);
}
printf("\t\t");
for(j=0;j<3;j++)
{
printf("%4c",c[i][j]);
}
printf("\t\t");
for(j=0;j<3;j++)
{
printf("%4c",s[i][j]);
}
printf("\n");
}
}
void printss(char m[3][3],char c[3][3],char s[3][3],char t[3][3])
{
	int i,j;
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
printf("%4c",m[i][j]);
}
printf("\t\t");
for(j=0;j<3;j++)
{
printf("%4c",c[i][j]);
}
printf("\t\t");
for(j=0;j<3;j++)
{
printf("%4c",s[i][j]);
}
printf("\t\t");
for(j=0;j<3;j++)
{
printf("%4c",t[i][j]);
}
printf("\n");
}
}
void prints(char m[3][3],char c[3][3])
{
	int i,j;
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
printf("%4c",m[i][j]);
}
printf("\t\t");
for(j=0;j<3;j++)
{
printf("%4c",c[i][j]);
}
printf("\n");
}
}
void printing(char p[3][3])
{
	int i,j;
	printf("\t\t\t\tSOURCE MATRIX\n");
	printf("\t\t\t\t--   \t      --\n");
	for(i=0;i<3;i++)
	{
		printf("\t\t\t\t");
		printf("|");
		for(j=0;j<3;j++)
		{
		printf("%4c",p[i][j]);	
		}
		printf("  |");
		printf("\n");
	}
		printf("\t\t\t\t--    \t      --\n");
	printf("\n\n");
}
int  main()
{
	system("COLOR 2B");
int k=1,i=0,j=0,pos_r=0,pos_c=0;
char s[3][3],s1[3][3],s2[3][3],s3[3][3];
int u,d,l,r;
printf("enter the source matrix :\n");
for(i=0;i<3;i++)
for(j=0;j<3;j++)
scanf(" %c",&p[i][j]);
system("COLOR 6B");
printf("enter the goal matrix :\n");
for(i=0;i<3;i++)
for(j=0;j<3;j++)
scanf(" %c",&g[i][j]);
printing(p);
printf("\t\t\t\tLEVEL - 0 \n\t\t\t\tF(x)=%4d+%4d=%4d\n\n",0,h_x(p,g),h_x(p,g));
while(1)
{

if(h_x(p,g)!=0){
for(i=0;i<3;i++)
for(j=0;j<3;j++)
{
	if(p[i][j]=='_')
	{
	pos_r=i;
	pos_c=j;
	break;
	}
}
if(pos_r==0&&pos_c==0)
{
	system("COLOR 3F");	
strcpy1(s1,p);
right(s1,pos_r,pos_c);

strcpy1(s2,p);
down(s2,pos_r,pos_c);

prints(s1,s2);
printf("\n");
u=k+h_x(s1,g);
d=k+h_x(s2,g);

printf("%d + %d = %4d\t\t %d + %d = %4d\n\n",k,h_x(s1,g),u,k,h_x(s2,g),d);
if(u<=d)
{
	printf("We have selected 1st matrix\n");
	strcpy1(p,s1);
}
else{
strcpy1(p,s2);
printf("We have selected 2nd matrix\n");
}
}
if(pos_r==0&&pos_c==1)
{
	system("COLOR 5C");	
	strcpy1(s1,p);
down(s1,pos_r,pos_c);

strcpy1(s2,p);
left(s2,pos_r,pos_c);


strcpy1(s3,p);
right(s3,pos_r,pos_c);
print(s1,s2,s3);
d=k+h_x(s1,g);
l=k+h_x(s2,g);
r=k+h_x(s3,g);
printf("%d + %d = %4d\t\t%d + %d = %4d\t\t%d + %d = %4d\n\n",k,h_x(s1,g),d,k,h_x(s2,g),l,k,h_x(s3,g),r);
if(l<=d&&l<=r)
{
printf("We have selected 2nd matrix\n");
strcpy1(p,s2);
}
else if(r<=l&&r<=d){
strcpy1(p,s3);
printf("We have selected 3rd matrix\n");
}
else if(d<=r&&d<=l){
strcpy1(p,s1);
printf("We have selected 1st matrix\n");
}
}
if(pos_r==0&&pos_c==2)
{		system("COLOR 3A");	
		strcpy1(s1,p);
down(s1,pos_r,pos_c);

strcpy1(s2,p);
left(s2,pos_r,pos_c);
prints(s1,s2);
d=k+h_x(s1,g);
l=k+h_x(s2,g);
printf("%d + %d = %4d\t\t%d + %d = %4d\n\n",k,h_x(s1,g),d,k,h_x(s2,g),l);
if(d<=l){
strcpy1(p,s1);
printf("We have selected 1st matrix\n");
}
else{
strcpy1(p,s2);
printf("We have selected 2nd matrix\n");
}
}
if(pos_r==1&&pos_c==0)
{system("COLOR 30");	
	strcpy1(s1,p);
down(s1,pos_r,pos_c);

strcpy1(s2,p);
up(s2,pos_r,pos_c);


strcpy1(s3,p);
right(s3,pos_r,pos_c);
print(s1,s2,s3);
d=k+h_x(s1,g);
u=k+h_x(s2,g);
r=k+h_x(s3,g);
printf("%d + %d = %4d\t\t%d + %d = %4d\t\t%d + %d = %4d\n\n",k,h_x(s1,g),d,k,h_x(s2,g),u,k,h_x(s3,g),r);
if(r<=d&&r<=u){
	printf("We have selected 3rd matrix\n");
strcpy1(p,s3);
}
else if(d<=u&&d<=r){	
strcpy1(p,s1);
printf("We have selected 1st matrix\n");
}
else if(u<=r&&u<=d){
	printf("We have selected 2nd matrix\n");
strcpy1(p,s2);}
}
if(pos_r==1&&pos_c==1)
{system("COLOR 3C");	
		printf("\n\n");
strcpy1(s,p);
up(s,pos_r,pos_c);

strcpy1(s1,p);
down(s1,pos_r,pos_c);

strcpy1(s2,p);
left(s2,pos_r,pos_c);


strcpy1(s3,p);
right(s3,pos_r,pos_c);

printss(s,s1,s2,s3);
printf("\n");
r=k+h_x(s3,g);
u=k+h_x(s,g);
d=k+h_x(s1,g);
l=k+h_x(s2,g);
printf("%d + %d = %4d\t\t%d + %d = %4d\t\t%d + %d = %4d\t\t%d + %d = %4d\n\n",k,h_x(s,g),u,k,h_x(s1,g),d,k,h_x(s2,g),l,k,h_x(s3,g),r);
		if(u<=d&&u<=l&&u<=r){
			printf("We have selected 1st matrix\n");
		strcpy1(p,s);
		}
		else if(d<=u&&d<=l&&d<=r){
			printf("We have selected 2nd matrix\n");
		strcpy1(p,s1);
		}
		else if(l<=u&&l<=d&&l<=r){
		printf("We have selected 3rd matrix\n");
		strcpy1(p,s2);
		}
		else if(r<=u&&r<=d&&r<=l){
			printf("We have selected 4th matrix\n");
		strcpy1(p,s3);		
		}
}
if(pos_r==1&&pos_c==2)
{system("COLOR 4F");	
		printf("\n\n");
strcpy1(s,p);
up(s,pos_r,pos_c);

strcpy1(s1,p);
down(s1,pos_r,pos_c);

strcpy1(s2,p);
left(s2,pos_r,pos_c);
print(s,s1,s2);
printf("\n");
u=k+h_x(s,g);
d=k+h_x(s1,g);
l=k+h_x(s2,g);
printf("%d + %d = %4d\t\t%d + %d = %4d\t\t%d + %d = %4d\n\n",k,h_x(s,g),u,k,h_x(s1,g),d,k,h_x(s2,g),l);
		if(u<=d&&u<=l)
		{
			printf("We have selected 1st matrix\n");
		strcpy1(p,s);
		}
		else if(d<=u&&d<=l)
		{
			printf("We have selected 2nd matrix\n");
		strcpy1(p,s1);
		}
		else if(l<=u&&l<=d)	
		{
			printf("We have selected 3rd matrix\n");
			strcpy1(p,s2);
		}
}
if(pos_r==2&&pos_c==0)
{system("COLOR 5A");	
			strcpy1(s,p);
			up(s,pos_r,pos_c);
			strcpy1(s1,p);
			right(s1,pos_r,pos_c);
			prints(s,s1);
			printf("\n");
			u=k+h_x(s,g);
			r=k+h_x(s1,g);
			printf("%d + %d = %4d\t\t%d + %d = %4d\n\n",k,h_x(s,g),u,k,h_x(s1,g),r);
			if(u<=r){
			strcpy1(p,s);
			printf("We have selected 1st matrix\n");
			}
			else{
			printf("We have selected 2nd matrix\n");
			strcpy1(p,s1);
		}
}
if(pos_r==2&&pos_c==1)
{system("COLOR 8B");	
	strcpy1(s,p);
up(s,pos_r,pos_c);


strcpy1(s1,p);
left(s1,pos_r,pos_c);


strcpy1(s2,p);
right(s2,pos_r,pos_c);

print(s,s1,s2);
printf("\n");
 u=k+h_x(s,g);
 l=k+h_x(s1,g);
 r=k+h_x(s2,g);
printf("%d + %d = %4d\t\t%d + %d = %4d\t\t%d + %d = %4d\n\n",k,h_x(s,g),u,k,h_x(s1,g),l,k,h_x(s2,g),r);
	if(u<=l&&u<=r)
	{
	strcpy1(p,s);
	printf("We have selected  1st matrix\n");
	}
	else if(l<=u&&l<=r){
	strcpy1(p,s1);
	printf("We have selected  2nd matrix\n");
	}
	else 
	{
	strcpy1(p,s2);
	printf("We have selected  3rd matrix\n");
}
}
if(pos_r==2&&pos_c==2)
{system("COLOR 92");	
	strcpy1(s,p);
up(s,pos_r,pos_c);


strcpy1(s1,p);
left(s1,pos_r,pos_c);
prints(s,s1);
printf("\n");
u=k+h_x(s,g);
l=k+h_x(s1,g);
printf("%d + %d = %4d\t\t%d + %d = %4d\n\n",k,h_x(s,g),u,k,h_x(s1,g),l);
	if(l<=u){
	strcpy1(p,s1);
	printf("\nWe have selected  2nd matrix\n");
	}
	else{
	strcpy1(p,s);
	printf("\nwe have selected 1st matrix\n");
}
}	
}
else
{
printf("\t\t\t\tGOAL MATRIX\n");
	printf("\t\t\t\t--   \t      --\n");
	for(i=0;i<3;i++)
	{
		printf("\t\t\t\t");
		printf("|");
		for(j=0;j<3;j++)
		{
		printf("%4c",p[i][j]);	
		}
		printf("  |");
		printf("\n");
	}
		printf("\t\t\t\t--    \t      --\n");
	printf("\n\n");
	return 0;
}
printf("Level - %d\t\t\n\n",k);
k++;
if(k>=10)
{
	printf("We cannot reach goal state by sliding tiles using blank space\n");
	break;
}
}
	return 0;
}
