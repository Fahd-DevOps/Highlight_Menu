#include <stdio.h>
#include <stdlib.h>
#include <MyLibrary.h>
#define NormalPen 0X07
#define HighlightedPen 0X70
#define row 3
#define col 3

/// 4- Employee with Functions (try to divide Ass#2 into 2 functions):
///	Struct Employee AddNewEmployee();
///	void DisplayEmployee(struct Employee);


struct Employee
{
    int ID, Bonus, Deduction;
    int salary;
    char name[50];

};

struct Employee AddNewEmployee( )
{
    struct Employee Emp;
    printf("\n Enter Name of Employee  :");
    scanf("%s",&Emp.name);
    printf("\n Enter Employee ID : ");
    scanf("%d",&Emp.ID);
    printf("\n Enter Salary of Employee is :");
    scanf("%d",&Emp.salary);
    return Emp;
}
void DisplayEmployee(struct Employee Emp)
{
    if(Emp.ID != 0)
    {
        printf("\n Display the Employees Information   ");
        printf("\n Name of Employee  : %s \n",Emp.name);
        printf("\n Id: %d \n",Emp.ID);
        printf("\n Salary: %d \n",Emp.salary);

    }

}

int main()
{

///5- Employee with functions and Highlight Menu: Menu of Array_Of_Struct

/*(Menu will be like:)
		New
		Display
		Display All
		Delete
		Delete All
		Exit
*/


  int i, cur = 0, Flag = 0,counter=0,empNum;
  char menu[6][12] = {"New", "Display","Display All","Delete","Delete All", "Exit"};
  char ch;
  struct Employee Emply[50];
  struct Employee DeleteEmply={0};
    do
    {
        for(i=0; i<6; i++)
        {
            gotoxy(10, 5 + i*3);

            if(cur == i)
                textattr(HighlightedPen);
            else
                textattr(NormalPen);

            printf("%s", menu[i]);
        }

        ch = getch();

        switch(ch)
        {
        case 0:         ///Extended key
        case -32:
        case 224:

            ch = getch();

            switch(ch)
            {
                case 72: ///UP
                    cur--;
                    if(cur < 0)
                        cur=5;
                    break;
                case 80: ///Down Arrow
                    cur++;
                    if(cur > 5)
                        cur=0;
                    break;
            }

        break; ///break of Extended keys case
        case 13: ///Enter
            if(cur == 0)
            {
                clrscr();
                gotoxy(5, 7);
                printf("*********************************** Add New Employee **************************************");
                Emply[counter++] = AddNewEmployee();
                clrscr();
            }
            else if (cur == 1)
            {
                clrscr();
                gotoxy(5, 7);
                printf("*********************************** Display Employee **************************************");
                printf("\n Enter The Number : ");
                scanf("%d",&empNum);
                DisplayEmployee( Emply[empNum]);
                ch = getch();
                clrscr();

            }
            else if (cur == 2)
            {
                clrscr();
                gotoxy(5, 7);
                printf("*********************************** Display all Employees **************************************");
                for(i=0;i<counter;i++)
                {
                    DisplayEmployee( Emply[i]);
                }
                ch = getch();
                clrscr();
            }
              else if (cur == 3)
            {
                clrscr();
                gotoxy(5, 7);
                printf("*********************************** Delete Employee **************************************");
                printf("\n Enter The Number for this Employee : ");
                scanf("%d",&empNum);
                Emply[empNum] = DeleteEmply;
                ch = getch();
                clrscr();
            }
               else if (cur == 4)
            {
               clrscr();
                gotoxy(5, 7);
                printf("*********************************** Delete All Employee **************************************");
                for(i=0;i<counter;i++)
                {
                    Emply[i] = DeleteEmply;
                }
                printf("\n Deleted All Successfully");
                ch = getch();
                clrscr();
            }
              else if (cur == 5)
            {
                Flag = 1;
            }
        break;

        case 27: ///Esc
            Flag = 1;
        break;

        case 9: ///Tab
            cur++;
                if(cur > 5)
                    cur=0;
        break;
        }

    }while(Flag == 0);

    return 0;
}
