#include <stdio.h>
#include <conio.h>
#include <string.h>
struct person
{
     char first_name[20];
     char last_name[20];
     int age;
     char dept[20];
     float bas_sal;
     char doj[20];
     char address[100];
     char city[20];
     int telno[10];
         
};
struct person obj;
FILE *fp;
void appendData()
{ 
fp=fopen("Employee.txt","a");
printf("*****Add Record**** \n");
printf("Enter first Name : ");
scanf("%s",obj.first_name);
fprintf(fp,"%20s",obj.first_name);
printf("Enter last Name : ");
scanf("%s",obj.last_name);
fprintf(fp,"%20s",obj.last_name);
printf("Enter age \n");
scanf("%d",&obj.age);
fprintf(fp,"%d",obj.age);
printf("Enter basic salary \n");
scanf("%f",&obj.bas_sal);
fprintf(fp,"%f",obj.bas_sal);
printf("Enter department \n");
scanf("%s",&obj.dept);
fprintf(fp,"%s",obj.dept);
printf("Enter date of joining \n");
scanf("%s",&obj.doj);
fprintf(fp,"%s",obj.doj);
printf("Enter address  \n");
scanf("%s",&obj.address);
fprintf(fp,"%s",obj.address);
printf("Enter city \n");
scanf("%s",&obj.city);
fprintf(fp,"%s",obj.city);
printf("Enter Telephone No. : ");
scanf("%d",&obj.telno);
fprintf(fp,"%7d",obj.telno);
fclose(fp);
}
void showAllData()
{          
//char ch;
      printf("*****Display All Records*****\n");
      printf("\n\n\t\tRecords :\n");
      printf("\n\t\t=====\t\t\t===============\n\n");
      fp=fopen("Employee.txt","r");
//next:
while(!feof(fp))
{
//fscanf(fp,"%20s %20s %d %f %s %s %s %s %7d",obj.first_name,obj.last_name,&obj.age,&obj.bas_sal,obj.dept,obj.doj,obj.address,obj.city,&obj.telno);
//printf("%20s %20s %d %f %s %s %s %s %7d",obj.first_name,obj.last_name,obj.age,obj.bas_sal,obj.dept,obj.doj,obj.address,obj.city,obj.telno);           
fscanf(fp,"%20s",obj.first_name);
printf("\n First name %20s",obj.first_name);
fscanf(fp,"%20s",obj.last_name);
printf("\n Last name %20s",obj.last_name);
fscanf(fp,"%d",&obj.age);
printf("\n Age %d",obj.age);
fscanf(fp,"%f",&obj.bas_sal);
printf("\n Basic Salary:%f",obj.bas_sal);
fscanf(fp,"%s",obj.dept);
printf("%s",obj.dept);
fscanf(fp,"%s",obj.doj);
printf("\n Date of joining %s",obj.doj);
fscanf(fp,"%s",obj.address);
printf("\n address %s",obj.address);
fscanf(fp,"%s",obj.city);
printf("\n city %s",obj.city);
fscanf(fp,"%7d",&obj.telno);
printf(" %7d",obj.telno); 
//the below part (within comment lines) also dont work. do suggest an alternative
/*printf("Do u wish to see next record??\n");
ch=getchar();
if(ch=='Y'||ch=='y')
{
goto next;
}         
else goto ending; 
ending: */
}

fclose(fp);
      getch();
}
void findData()
{
      char name[20];
      int totrec=0;
      fp=fopen("Employee.txt","r");
      printf("*****Display Specific Records*****\n");
      printf("\nEnter Name : ");
      gets(name);
      fp=fopen("Employee.txt","r");
      while(!feof(fp))
      {
      fscanf(fp,"%20s",obj.first_name);
      fscanf(fp,"%20s",obj.last_name);
      fscanf(fp,"%d",&obj.age);
      fscanf(fp,"%f",&obj.bas_sal);
      fscanf(fp,"%20s",obj.dept);
      fscanf(fp,"%s",obj.doj);
      fscanf(fp,"%s",obj.address);
      fscanf(fp,"%s",obj.city);
      fscanf(fp,"%7ld",&obj.telno);
      //This if statement for searching only works when the first name is entered
if((strcmpi(obj.first_name,name)==0)||(strcmpi(name,obj.last_name)==0)||(strcmpi(name,obj.dept)==0))
{
printf("\n First name %20s",obj.first_name);
printf("\n Last name %20s",obj.last_name);
printf("\n Age %d",obj.age);
printf("\n Basic Salary:%f",obj.bas_sal);
printf("%s",obj.dept);
printf("\n Date of joining %s",obj.doj);
printf("\n address %s",obj.address);
printf("\n city %s",obj.city);
printf("\n Phone number %7d",obj.telno);
totrec++;
}
}
      if(totrec==0)
         printf("\n\n\nNo Data Found");
      else
         printf("\n\n===Total %d Record found===",totrec);
      fclose(fp);
      getch();
}
/* Im kind of stuck here.
void edit()
{
 char name[100];
 printf("Enter the employee name or surname\n");
 gets(name);
 fp=fopen("Employee.txt","r");
while(!feof(fp))
{
      fscanf(fp,"%20s",obj.first_name);
      fscanf(fp,"%20s",obj.last_name);
      if((strcmpi(name,obj.first_name)==0)||(strcmpi(name,obj.last_name)==0)
      {
      printf("The employee record found. Re-enter his detail\n");
      
      }
}
 
 }
*/
int main()
{
      char choice;
      while(1)
      {
    printf("*****TELEPHONE DIRECTORY*****\n\n");
    printf("1) ADD Record\n");
    printf("2) Display all records\n");
    printf("3) Find Record\n");
   // printf("4) exit\n");
    printf("Enter your choice : ");
    fflush(stdin);
    choice = getche();
    switch(choice)
    {
         case'1' : //call append record
            appendData();
            break;
         case'2' :
                   //Read all record
            showAllData(); 
            break;
         case'3' :
                 //call find record
             findData();                                  
            break;
        // case'4' : exit(1); 
         default : printf(" Invalid entry\n");
                   break;
           }
    }
}
