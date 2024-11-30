#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>


struct Employee
{
	int code;

	int salary , bonus , deduct;

	char name[50];

	int netSalary;

};

struct Employee **employees;


/***************** Functions proto tupes ******************/

void New(void);

void Display(void);

void Exit(void);

void homeScreen(void);

void take_str_Input(char string[50]);

void readEmployee(int *count,int  numofEmployees);

void displayEmployee();

void arrow_up(int *flag);

void arrow_down(int *flag);

void enter_key(int *flag, int *count,int numofEmployees);



/********************* Main functiobn **********************/


int main(){

	char ch; int flag=1, count=0 , numofEmployees=0, i=0;



	   flushall();

	   clrscr();

	   gotoxy(28,11);

	   printf("Enter number of Employees: ");

	   scanf("%d",&numofEmployees);

	  // while(( ch = getchar()) != '\n' && ch != EOF);

	   employees = (struct Employee **)malloc(numofEmployees * sizeof(struct Employee *));
		  for( i = 0; i < numofEmployees; i++) {
			  employees[i] = (struct Employee *)malloc(sizeof(struct Employee));
		  }

	   if(employees == NULL){

		printf("Memory allocation is failed");
		return 1;
	   }


	  clrscr();

	   New();


	  while(1){
		ch = getch();
		if(ch==NULL){
			ch = getch();
			if((int)ch == 72){
				arrow_up(&flag);
			}else if((int)ch == 80){
				arrow_down(&flag);
			}

		}else{
			 enter_key(&flag,&count,numofEmployees);

		 }
	  }
	  for(i=0; i<numofEmployees; i++){

		 free(employees[i]);
	  }
	  free(employees);

	  return 0;


}

/*************** Functions implementation *****************/

void New(){

	  clrscr();

	  gotoxy(27,11);
	  printf("=========Menu=========\n\n");

	  gotoxy(32,12);
	  printf("\033[1;31m 1.New \033[0m\n");

	  gotoxy(32,13);
	  printf(" 2.Display\n");

	  gotoxy(32,14);
	  printf(" 3.Exist\n");


}

void Display(){

	 clrscr();

	 gotoxy(27,11);
	 printf("=========Menu=========\n\n");

	 gotoxy(32,12);
	 printf(" 1.New \n");

	 gotoxy(32,13);
	 printf("\033[1;31m 2.Display \033[0m\n");

	 gotoxy(32,14);
	 printf(" 3.Exist\n");

}

void Exit(){

	clrscr();

	gotoxy(27,11);
	printf("=========Menu=========\n\n");

	gotoxy(32,12);
	printf(" 1.New \n");

	gotoxy(32,13);
	printf(" 2.Display\n");

	gotoxy(32,14);
	printf("\033[1;31m 3.Exit \033[0m\n");
}

void homeScreen(){
	   gotoxy(1,1);
	   printf("\033[1;31m For Menu :press Enter \033[0m\n");

}

void take_str_input(char string[50]){

	char ch;

	int i=0 , j=0;

	for(j=0; j<50 ; j++){
		 string[j] = '\0';
	}

	while(1){
		ch = getch();

		if((int)ch==13){

			string[i] = '\0';
			break;

		}else if (i<49){

			string[i]=ch;
			printf("%c",ch);

			i++;
		}
	 }
}

void readEmployee(int *count ,int  numofEmployees){

  // struct Employee emp;
   int j=0; char ch;

   clrscr();

  /* for(j=0; j<50 ; j++){
		 employees[*count].name[j] = '\0';
   } */


   if(*count<numofEmployees){

		gotoxy(27,10);
		printf("Enter Employee name: ");


	  //	take_str_input(employees[*count].name);
	  scanf(" %[^\n]" , employees[*count]->name);

	  while(( ch = getchar()) != '\n' && ch != EOF);


		printf("\n");

		gotoxy(27,11);
		printf("Enter Employee code(1:5): ");
		scanf("%d", &employees[*count]->code);

		while(( ch = getchar()) != '\n' && ch != EOF);

		printf("\n");

		gotoxy(27,12);
		printf("Enter Employee salary: ");
		scanf("%d", &employees[*count]->salary);

		while(( ch = getchar()) != '\n' && ch != EOF);

		if(employees[*count]->salary <0){
			employees[*count]->salary *= -1;
		}

		printf("\n");

		gotoxy(27,13);
		printf("Enter Employee bonus: ");
		scanf("%d", &employees[*count]->bonus);

		while(( ch = getchar()) != '\n' && ch != EOF);

		if(employees[*count]->bonus <0){
			employees[*count]->bonus *= -1;
		}

		printf("\n");

		gotoxy(27,14);
		printf("Enter Employee deduct: ");
		scanf("%d", &employees[*count]->deduct);

		while(( ch = getchar()) != '\n' && ch != EOF);

		if(employees[*count]->deduct <0){
			employees[*count]->deduct *= -1;
		}

	   //	employees[*count]=emp;

		printf("\n\n");

		*count = *count+1;

		gotoxy(27,15);
		printf("Employee entered successfully!\n");

   }else{
		gotoxy(28,11);
		printf("The Buffer of Employees is full!");
	}
	  homeScreen();
	  getch();

}

void displayEmployee(int count){

  int index = 0;
  char c;

  homeScreen();

  if(count>0)
  {

	while(1){

	  gotoxy(23,10);
	  printf("==========Employee Data==========\n\n");

	  gotoxy(27,11);
	  printf("Employee Name: %s\n\n",employees[index]->name);

	  gotoxy(27,12);
	  printf("Employee code: %d\n\n",employees[index]->code);

	  employees[index]->netSalary =(employees[index]->salary + employees[index]->bonus)-employees[index]->deduct;

	  gotoxy(27,13);
	  printf("Employee net salary: %d\n",employees[index]->netSalary);

	  gotoxy(1,25);
	  printf("<<-");

	  gotoxy(77,25);
	  printf("->>");


	  c = getch();

	  if(c == NULL){

		c = getch();

		if(c==77 && index< count-1){ //right arrow code =77

			index++;

		}else if(c == 75 && index > 0){ //left arrow code = 75

			 index--;
		}
	  }else if((int) c ==13){ //return to the main menue
		break;
	  }
	}

  }else{
	clrscr();
	gotoxy(28,11);
	printf("There are no Employees yet!\n");
	homeScreen();
	getch();
  }

}

void arrow_up(int *flag){


	  clrscr();

	  switch(*flag){

		case(1):

			New();

			*flag=1;
			break;

		case(2):

			New();

			*flag=1;
			break;;

		case(3):

			Display();

			*flag=2;
			break;

		}

}

void arrow_down(int *flag){


	  clrscr();

	  switch(*flag){
		case(1):
			Display();

			*flag=2;
			break;

		case(2):

			Exit();

			*flag=3;
			break;

		case(3):

			Exit();

			*flag=3;
			break;

		}

}

void enter_key(int *flag, int *count, int numofEmployees){//code = 13
		int i=0;

	  clrscr();

	  switch(*flag){

		case(1):

			//  *count = *count + 1;

			  readEmployee(count , numofEmployees);


			  *flag = 1;
			  New();

			 break;

		case(2):

			 displayEmployee(*count);

			 *flag = 1;
			 New();

			 break;

		case(3):
			for(i = 0; i < numofEmployees; i++) {
				free(employees[i]);
			} 
			free(employees);

			exit(0);
			break;
		}
}