#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
int maindisplay();
int studentrecord();
int examdepartment();
int librarysystem();
int instudentrecord(int);
int inexamdepartment(int);
int inlibrarysystem(int);
struct stusr
{
	int roll;
	char name[20];
	char add[20];
	char gen[5];
	char gn[20];
}studentsr[100];
int main()
{
	system ("CLS");
	int c1,c11,c12,c13;
	c1=maindisplay();
	switch(c1)
	{
		case 1:
			c11=studentrecord();
			instudentrecord(c11);
			break;
		case 2:
			c12=examdepartment();
			inexamdepartment(c12);
			break;
		case 3:
			c13=librarysystem();
			inlibrarysystem(c13);
			break;
		default:
			main();
			break;
	} 
}
int maindisplay()
{
	int n=0;
	system ("CLS");
	printf("COLLEGE MANAGEMENT SYSTEM\n");
	printf("1\tSTUDENT RECORD\n");
	printf("2\tEXAM DEPERTMENT\n");
	printf("3\tLIBRARY\n");
	printf("Choose the available options:");
	scanf("\t%d",&n);
	if(n==1||n==2||n==3)
	{
		return n;
	}
	maindisplay();
	
}
int studentrecord()
{
	int n=0;
	system ("CLS");
	printf("COLLEGE MANAGEMENT SYSTEM\n");
	printf("1\tADD RECORD\n");
	printf("2\tSEARCH RECORD\n");
	printf("3\tEDIT RECORD\n");
	printf("4\tDELETE RECORD\n");
	printf("5\tRETURN BACK\n");
	printf("Choose the available options:");
	scanf("\t%d",&n);
	if(n==1||n==2||n==3||n==4||n==5)
		return n;
	else
		studentrecord();
}
int examdepartment()
{
	int n=0;
	system ("CLS");
	printf("COLLEGE MANAGEMENT SYSTEM\n");
	printf("1\tPREPARE RESULT\n");
	printf("2\tVIEW RESULT\n");
	printf("3\tSEARCH RESULT\n");
	printf("4\tEDIT RESULT\n");
	printf("5\tDELETE RESULT\n");
	printf("6\tRETURN BACK\n");
	printf("Choose the available options:");
	scanf("\t%d",&n);
	if(n==1||n==2||n==3||n==4||n==5||n==6)
		return n;
	else
		examdepartment();
}
int librarysystem()
{
	int n=0;
	system ("CLS");
	printf("COLLEGE MANAGEMENT SYSTEM\n");
	printf("1\tADD BOOK NAME\n");
	printf("2\tSEARCH BOOK\n");
	printf("3\tRETURN BOOK\n");
	printf("4\tRETURN BACK\n");
	printf("Choose the available options:");
	scanf("\t%d",&n);
	if(n==1||n==2||n==3||n==4)
		return n;
	else
		librarysystem();
}
int instudentrecord(int c11)
{
	char con='y';
	int n=0,ser,i;
	switch(c11)
	{
		case 1:

			while (con=='y'||con=='Y')
			{
				FILE *fp;
				fp=fopen("D:\\cproject\\studentrecord.text","a");
				if(fp==NULL)
				{
					printf("File cannot be opened");
					exit(0);
				}					
				printf("\nenter your roll no:\n");
				scanf("%d",&studentsr[n].roll);
				fflush(stdin);
				printf("enter your name:\n");
				scanf("%s",&studentsr[n].name);
				printf("enter your address:\n");					
				scanf("%s",&studentsr[n].add);
				printf("enter your 'm' for male and 'f'for female :\n");					
				scanf("%s",&studentsr[n].gen);
				printf("enter your gurdain name:\n");
				scanf("%s",&studentsr[n].gn);
				fprintf(fp, "%d\t%s\t%s\t%s\t%s\n",studentsr[n].roll, studentsr[n].name,  studentsr[n].add,studentsr[n].gen, studentsr[n].gn);
				fclose(fp);
				printf("\ndo you want to continue??:");
				scanf("%s",&con);
				n=n+1;
				//fp=fopen("D:\\cproject\\studentrecord.text","r");
			};
			studentrecord();
			break;
		case 2:
			while(con=='y'||con=='Y')
			{
				printf("enter the roll no you want to search:\n");
				scanf("%d",&ser);
				FILE *fp;
				fp=fopen("D:\\cproject\\studentrecord.text","r");
				if(fp==NULL)
				{
					printf("File cannot be opened");
					exit(0);
				}
				for(i=0;i<10;i++)
				{
					fscanf(fp,"%d%s%s%s%s",&studentsr[i].roll,&studentsr[i].name,&studentsr[i].add,&studentsr[i].gen,&studentsr[i].gn);
					fflush(stdin);
					if(studentsr[i].roll==ser)
					{
						printf("hfh");
						printf("%d\t%s\t%s\t%s\t%s\n",studentsr[i].roll,studentsr[i].name,studentsr[i].add,studentsr[i].gen,studentsr[i].gn);
						break;
					}
				}
				fclose(fp);
				printf("\ndo you want to continue??:");
				scanf("%s",&con);
			}
			break;
		case 3:
			printf("edit record");
			break;
		case 4:
			printf("delete record");
			break;
		case 5:
			main();
			break;
		default:
			studentrecord();
			break;
			
	}
}
int inexamdepartment(int c12)
{
	switch(c12)
	{
		case 1:
			printf("prepare result");
			break;
		case 2:
			printf("view result");
			break;
		case 3:
			printf("search result");
			break;
		case 4:
			printf("edit result");
			break;
		case 5:
			printf("delete result");
			break;
		case 6:
			main();
			break;
		default:
			examdepartment();
			break;
	}
}
int inlibrarysystem(int c13)
{
	switch(c13)
	{
		case 1:
			printf("add book name");
			break;
		case 2:
			printf("search book");
			break;
		case 3:
			printf("return book");
			break;
		case 4:
			main();
			break;
		default:
			librarysystem();
			break;
	}
}


