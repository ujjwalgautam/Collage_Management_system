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
struct sr
	{
		char name[20];
		int roll;
		char add[20];
		char gen[20];
		char gn[20];
		char pass[10];
	}student[100];
struct ex
{
	char name[20];
	int roll,iit,c,math,phy,dl;
}stuex[100];
struct li
{
	char fn[10],ln[10],b1[20];
	int lc,m,d;
}stuli[100];
int main()
{
	FILE *fp;
	FILE *fp1;
	fp=fopen("D:\\cproject\\data.text","a");
	if(fp==NULL)
	{
		printf("File cannot be opened");
		exit(0);
	}
	else{
		printf("hgfhgf");
	}
	fclose(fp);
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
	printf("3\tVIEW ALL RECORD\n");
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
	printf("3\tDELETE RESULT\n");
	printf("4\tRETURN BACK\n");
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
	printf("2\tRETURN BOOK\n");
	printf("3\tRETURN BACK\n");
	printf("Choose the available options:");
	scanf("\t%d",&n);
	if(n==1||n==2||n==3||n==4)
		return n;
	else
		librarysystem();
}
int instudentrecord(int c11)
{
	int rn,ns,i,d,z,ser,pc;
	char con='y',c,p1[10]={"a"},p2[10]={"b"},pass[]="admin",pass1[10];
	switch(c11)
	{
		case 1:
			pc=0;
			printf("Enter password to add record:\n");
			while(1)
			{
				pc=pc+1;							
				scanf("%s",&pass1);
				if(strcmp(pass,pass1)==0)
					break;
				if(pc>3)
				{
					printf("\a\a\a");
					main();
				}
				if(pc>0)
				{
					printf("\a");
					printf("Re-enter password\n");
					
				}
				
			}
			while (con=='y'||con=='Y')
			{
					FILE *fp;
					char p1[10]={"a"},p2[10]={"b"};
					fp=fopen("D:\\cproject\\data.text","a");
					if(fp==NULL)
					{
						printf("File cannot be opened");
						exit(0);
					}					
					printf("Enter your roll no:\n");
					scanf("%d",&student[rn].roll);
					printf("Enter your name:\n");
					scanf("%s",&student[rn].name);
					fflush(stdin);
					printf("Enter your address:\n");					
					scanf("%s",&student[rn].add);
					printf("Enter 'm' for male and 'f'for female :\n");					
					scanf("%s",&student[rn].gen);
					printf("Enter your guardain name:\n");
					scanf("%s",&student[rn].gn);
					fflush(stdin);
					while(strcmp(p1,p2)!=0)
					{
						printf("Enter your password:\n");
						scanf("%s",&p1);
						printf("Re-enter your password:\n");
						scanf("%s",&p2);
					}
					strcpy(student[rn].pass,p1);
					fprintf(fp, "%d\t%s\t%s\t%s\t%s\t%s\n",student[rn].roll, student[rn].name,  student[rn].add,student[rn].gen, student[rn].gn,student[rn].pass);
					fclose(fp);
					printf("\nDo you want to continue??:");
					scanf("%s",&con);
					if(con=='y'||con=='Y')
					rn=rn+1;
			}
			c11=studentrecord();
			instudentrecord(c11);
			break;
		case 2:
			while (con=='y'||con=='Y')
			{
					FILE *fp;
					int out=0;
					fp=fopen("D:\\cproject\\data.text","r");
					if(fp==NULL)
					{
						printf("File cannot be opened");
						exit(0);
					}
					printf("Enter the roll no you want to search:\n");
					scanf("%d",&ser);
					for(i=0;i<100;i++)
				{
					fscanf(fp, "%d\t%s\t%s\t%s\t%s\t%s\n",&student[i].roll,& student[i].name,&student[i].add,&student[i].gen,&student[i].gn,&student[i].pass);
					fflush(stdin);
					if(student[i].roll==ser)
					{
					printf("Enter your password:\n");
					int t=0;
						while(t!=100)
						{
							pc=pc+1;							
							scanf("%s",&pass1);
							if(strcmp(student[i].pass,pass1)==0)
							{
								t=100;
								break;
							}

								
							if(pc>3)
							{
								printf("\a\a\a");
								main();
							}
							if(pc>0)
							{
								printf("\a");
								printf("Re-enter password\n");
								
							}
							
						}
				}
					if(student[i].roll==ser)
					{
						printf("Roll no\t\tName\t\tAddress\t\tGender\t\tGuardain name\n");
						printf("%d\t\t%s\t\t%s\t\t%s\t\t%s\n",student[i].roll, student[i].name,  student[i].add,student[i].gen, student[i].gn);
						out=out+1;
						break;
					}
					if(student[i].roll==0)
					{
						printf("Record not found");
						break;
					}
					
				}				
					fclose(fp);
					printf("\nDo you want to continue??:");
					scanf("%s",&con);
			}
			c11=studentrecord();
			instudentrecord(c11);
			break;
		case 3:
			pc=0;
			printf("Enter password:\n");
			while(1)
			{
				pc=pc+1;							
				scanf("%s",&pass1);
				if(strcmp(pass,pass1)==0)
					break;
				if(pc>3)
				{
					printf("\a\a\a");
					main();
				}
				if(pc>0)
				{
					printf("\a");
					printf("Re-enter password\n");
					
				}
				
			}
			while (con=='y'||con=='Y')
			{
					FILE *fp;
					fp=fopen("D:\\cproject\\data.text","r");
					if(fp==NULL)
					{
						printf("File cannot be opened");
						exit(0);
					}
					printf("Roll no\t\tName\t\tAddress\t\tGender\t\tGuardain name\n");
					for(i=0;i<100;i++)
				{
					fscanf(fp, "%d%s%s%s%s%s",&student[i].roll,& student[i].name,&student[i].add,&student[i].gen,&student[i].gn,&student[i].pass);
					if(student[i].roll==0)
					{
						break;
					}
				}
					for(i=0;i<100;i++)
				{

					printf("%d\t\t%s\t\t%s\t\t%s\t\t%s\n",student[i].roll, student[i].name,  student[i].add,student[i].gen, student[i].gn);
					
					if(student[i+1].roll==0||student[i+1].roll==student[i].roll)
					{
						printf("\nEnd of record\n");
						break;
					}
				}				
					fclose(fp);
					printf("\nDo you want to continue??:");
					scanf("%s",&con);
			}
			c11=studentrecord();
			instudentrecord(c11);
			break;
		case 4:
			while (con=='y'||con=='Y')
			{
					FILE *fp;
					fp=fopen("D:\\cproject\\data.text","r");
					if(fp==NULL)
					{
						printf("File cannot be opened");
						exit(0);
					}
					
					
					printf("Enter the rol no you want to delete:");
					scanf("%d",&ser);
					for(i=0;i<100;i++)
				{
					fscanf(fp, "%d\t%s\t%s\t%s\t%s\t%s\n",&student[i].roll,& student[i].name,&student[i].add,&student[i].gen,&student[i].gn,&student[i].pass);
					if(student[i].roll==0)
					{
						break;
					}
				}
				fclose(fp);
				fp=fopen("D:\\cproject\\data.text","w");
				if(fp==NULL)
					{
						printf("File cannot be opened");
						exit(0);
					}
					for(i=0;i<100;i++)
				{
					if(student[i].roll==ser)
					{
						printf("Enter your password:\n");
					int t=0;
						while(t!=100)
						{
							pc=pc+1;							
							scanf("%s",&pass1);
							if(strcmp(student[i].pass,pass1)==0)
							{
								t=100;
								break;
							}								
							if(pc>3)
							{
								printf("\a\a\a");
								main();
							}
							if(pc>0)
							{
								printf("\a");
								printf("Re-enter password\n");								
							}
							
						}
						break;
					}									
				}	
					for(i=0;i<100;i++)
				{
					if(student[i].roll==ser)
						continue;					
					fprintf(fp,"%d\t%s\t%s\t%s\t%s\t%s\n",student[i].roll, student[i].name,  student[i].add,student[i].gen, student[i].gn,student[i].pass);					
					if(student[i+1].roll==0)
					{
						break;
					}
				}
				printf("Record deleted");				
					fclose(fp);
					printf("\nDo you want to continue??:");
					scanf("%s",&con);
			}
			c11=studentrecord();
			instudentrecord(c11);
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
	int ser,i,rn=0,pc;
	char con='y',pass[]="admin",pass1[10];
	pc=0;
			
			
			while(1)
			{
				if(c12==4)
				break;
				if(pc==0)
				printf("enter password:\n");
				if(c12==4)
				break;
				pc=pc+1;							
				scanf("%s",&pass1);
				if(strcmp(pass,pass1)==0)
					break;
				if(pc>3)
				{
					printf("\a\a\a");
					main();
				}
				if(pc>0)
				{
					printf("\a");
					printf("reenter password\n");
					
				}
				
			}
	switch(c12)
	{
		case 1:
			while (con=='y'||con=='Y')
			{
										
					printf("enter your roll no:\n");
					scanf("%d",&stuex[rn].roll);
					printf("enter your name:\n");
					scanf("%s",&stuex[rn].name);
					fflush(stdin);
					printf("enter your marks in IIT:\n");					
					scanf("%d",&stuex[rn].iit);
					printf("enter your marks in DL :\n");					
					scanf("%d",&stuex[rn].dl);
					printf("enter your marks in MATH:\n");
					scanf("%d",&stuex[rn].math);
					printf("enter your marks in PHYSICS:\n");
					scanf("%d",&stuex[rn].phy);
					printf("enter your marks in CP:\n");
					scanf("%d",&stuex[rn].c);
					fflush(stdin);
					FILE *fpe;
					fpe=fopen("D:\\cproject\\result.text","a");
					if(fpe==NULL)
					{
						printf("File cannot be opened");
						exit(0);
					}
					fprintf(fpe, "%d\t%s\t%d\t%d\t%d\t%d\t%d\n",stuex[rn].roll,stuex[rn].name,stuex[rn].iit,stuex[rn].dl,stuex[rn].math,stuex[rn].phy,stuex[rn].c);
					fclose(fpe);
					printf("\ndo you want to continue??:");
					scanf("%s",&con);
					if(con=='y'||con=='Y')
					rn=rn+1;
			}
			c12=examdepartment();
			inexamdepartment(c12);
			break;
		case 2:
			while (con=='y'||con=='Y')
			{
					FILE *fpe;
					fpe=fopen("D:\\cproject\\result.text","r");
					if(fpe==NULL)
					{
						printf("File cannot be opened");
						exit(0);
					}
					for(i=0;i<100;i++)
					{
					fscanf(fpe, "%d\t%s\t%d\t%d\t%d\t%d\t%d\n",&stuex[i].roll,&stuex[i].name,&stuex[i].iit,&stuex[i].dl,&stuex[i].math,&stuex[i].phy,&stuex[i].c);	
					if(stuex[i].roll==0)
					{
						break;
					}
					}
					printf("roll no\t\tname\t\tIIT\tDL\tMATH\tPHY\tC\ttotal\tpercent\t\tgrade\n");
					for(i=0;i<100;i++)
					{
					printf("%d\t\t%s\t\t%d\t%d\t%d\t%d\t%d\t",stuex[i].roll,stuex[i].name,stuex[i].iit,stuex[i].dl,stuex[i].math,stuex[i].phy,stuex[i].c);	
					int total=stuex[i].iit+stuex[i].dl+stuex[i].math+stuex[i].phy+stuex[i].c;
					float percent;
					percent=total/5;
					printf("%d\t%.2f\t\t",total,percent);
					if(percent>=80)
						printf("A\n");
					else if(percent>=70)
						printf("B\n");
					else if(percent>=60)
						printf("C\n");
					else if(percent>=50)
						printf("D\n");
					else if(percent>=40)
						printf("E\n");
					else 
						printf("f\n");
						
					if(stuex[i+1].roll==0||stuex[i].roll==stuex[i+1].roll)
					{
						printf("End of file:\n");
						break;
					}
					}
					fclose(fpe);
					printf("\ndo you want to continue??:");
					scanf("%s",&con);
					if(con=='y'||con=='Y')
					rn=rn+1;
			}
			c12=examdepartment();
			inexamdepartment(c12);
			break;
		case 3:
			while (con=='y'||con=='Y')
			{
					FILE *fpe;
					fpe=fopen("D:\\cproject\\result.text","r");
					if(fpe==NULL)
					{
						printf("File cannot be opened");
						exit(0);
					}
					printf("Enter the roll no you want to delete:");
					scanf("%d",&ser);
					for(i=0;i<100;i++)
					{
					fscanf(fpe, "%d\t%s\t%d\t%d\t%d\t%d\t%d\n",&stuex[i].roll,&stuex[i].name,&stuex[i].iit,&stuex[i].dl,&stuex[i].math,&stuex[i].phy,&stuex[i].c);	
					if(stuex[i].roll==0)
					{
						break;
					}
					}
					fclose(fpe);
					fpe=fopen("D:\\cproject\\result.text","w");
					if(fpe==NULL)
					{
						printf("File cannot be opened");
						exit(0);
					}
					for(i=0;i<100;i++)
					{
					if(stuex[i].roll==ser)
					continue;
					fprintf(fpe, "%d\t%s\t%d\t%d\t%d\t%d\t%d\n",stuex[i].roll,stuex[i].name,stuex[i].iit,stuex[i].dl,stuex[i].math,stuex[i].phy,stuex[i].c);	
					if(stuex[i+1].roll==0||stuex[i].roll==stuex[i+1].roll)
					{
						break;
					}
					}
					printf("\nRecord deleted:");
					fclose(fpe);
					printf("\ndo you want to continue??:");
					scanf("%s",&con);
					if(con=='y'||con=='Y')
					rn=rn+1;
			}
			c12=examdepartment();
			inexamdepartment(c12);
			break;
		case 4:
			main();
			break;
			
		default:
			examdepartment();
			break;
	}
}
int inlibrarysystem(int c13)
{
	char con='y',pass[]="admin",pass1[10];
	int rn,i,lc,m,d,pc;
	pc=0;
			while(1)
			{
				if(c13==3)
				break;
				if(pc==0)
				printf("enter password:\n");
				if(c13==3)
				break;
				pc=pc+1;							
				scanf("%s",&pass1);
				if(strcmp(pass,pass1)==0)
					break;
				if(pc>3)
				{
					printf("\a\a\a");
					main();
				}
				if(pc>0)
				{
					printf("\a");
					printf("reenter password\n");
					
				}
				
			}
	switch(c13)
	{
		case 1:
			while (con=='y'||con=='Y')
			{
					FILE *fpl;
					fpl=fopen("D:\\cproject\\library.text","a");
					if(fpl==NULL)
					{
						printf("File cannot be opened");
						exit(0);
					}					
					printf("Enter library no of student:\n");
					scanf("%d",&stuli[rn].lc);
					printf("enter students first name:\n");
					scanf("%s",&stuli[rn].fn);
					fflush(stdin);
					printf("enter students last name name:\n");
					scanf("%s",&stuli[rn].ln);
					fflush(stdin);
					printf("enter book name:\n");				
					scanf("%s",&stuli[rn].b1);
					fflush(stdin);
					printf("enter month of book taken:\n");
					scanf("%d",&stuli[rn].m);
					printf("enter day of book taken:\n");
					scanf("%d",&stuli[rn].d);
					fprintf(fpl, "%d\t%s\t%s\t%s\t%d\t%d\n",stuli[rn].lc,stuli[rn].fn,stuli[rn].ln,stuli[rn].b1,stuli[rn].m,stuli[rn].d);
					fclose(fpl);
					printf("\ndo you want to continue??:");
					scanf("%s",&con);
					if(con=='y'||con=='Y')
				rn=rn+1;
			}
			c13=librarysystem();
			inlibrarysystem(c13);
			break;
		case 2:
			while (con=='y'||con=='Y')
			{
					FILE *fpl;
					fpl=fopen("D:\\cproject\\library.text","r");
					if(fpl==NULL)
					{
						printf("File cannot be opened");
						exit(0);
					}					
					for(rn=0;rn<100;rn++)
					{
						fscanf(fpl, "%d\t%s\t%s\t%s\t%d\t%d\n",&stuli[rn].lc,&stuli[rn].fn,&stuli[rn].ln,&stuli[rn].b1,&stuli[rn].m,&stuli[rn].d);
						if(stuli[rn].lc==0)
					{
						break;
					}	
					}
					fclose(fpl);
					printf("Enter library code no of student:\n");
					scanf("%d",&lc);
					int tm,td,tf;
					fpl=fopen("D:\\cproject\\library.text","w");
					if(fpl==NULL)
					{
						printf("File cannot be opened");
						exit(0);
					}
					for(rn=0;rn<100;rn++)
					{
						if(stuli[rn].lc==lc)
						{
							printf("\nlc\tname\t\t\tbook\t\tmonth\tday\n");
							printf("%d\t%s %s\t\t\t%s\t\t%d\t%d\n",stuli[rn].lc,stuli[rn].fn,stuli[rn].ln,stuli[rn].b1,stuli[rn].m,stuli[rn].d);
							printf("Enter submission month:\n");
							scanf("%d",&m);
							printf("Enter submission day:\n");
							scanf("%d",&d);	
							tm=m-stuli[rn].m;
							td=d-stuli[rn].d;
							td=td+tm*30;
							if(td>45)
								tf=100;
							else if(td>30)
								tf=50;
							else if(td>15)
								tf=30;
								else
								tf=0;
								printf("\ntotal fine:%d",tf);
								break;
							
						}	
					}
					for(rn=0;rn<100;rn++)
					{	
						if(stuli[rn].lc==lc||stuli[rn].lc==stuli[rn+1].lc)
							continue;
						fprintf(fpl, "%d\t%s\t%s\t%s\t%d\t%d\n",stuli[rn].lc,stuli[rn].fn,stuli[rn].ln,stuli[rn].b1,stuli[rn].m,stuli[rn].d);
						if(stuli[rn+1].lc==0)
						{
							break;
						}
						
					}
					fclose(fpl);
					printf("\ndo you want to continue??:");
					scanf("%s",&con);
					if(con=='y'||con=='Y')
					rn=rn+1;
			}
			c13=librarysystem();
			inlibrarysystem(c13);
			break;
		case 3:
			main();
			break;
		default:
			librarysystem();
			break;
	}
}




