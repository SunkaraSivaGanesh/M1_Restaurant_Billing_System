#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"meals.h"
#include"order.h"
/*
  meals.h header files contains the function which prints the menu
  order.h header is responsible to print the final bill by giving the discount on the final amount
  orderMeals- calls seperate functions for each catergory and calls final bill function
  orderForadults - takes the order from adults and calculates the total cost including tax
  orderForChildren - takes the order from children and calculates the total cost including tax
  orderForStudent - takes the order from students and calculates the total cost including tax

*/

// creating some varibles which we use across the fucntions
double price[7] = {240.00 , 250.00 , 300.00 , 280.00 , 320.00 , 380.00 , 200.00 };

int studentNumber,adultNumber,childNumber;
// implicit declaration of the functions used in this project
void orderbill(int adultNumber, int childNumber, int studentNumber,double totalPriceForAdult,double totalPriceForChildren,double totalPriceForStudent,double allPayment);

void printMeals();
void orderMeals(int studentNumber, int adultNumber, int childNumber);
double orderForAdult(int adultNumber);
double orderForChildren(int childNumber);
double orderForStudent(int studentNumber);


int main()
{
    char response = 'y';  // intializing the response to yes


    printMeals(); // printing the menu available
    while(response == 'y'|| response == 'Y')
    {
            // taking the number of adults visited the restaurant
            printf("please enter number of adults  :");
            scanf("%d",&adultNumber);
            // taking the number of children arrived
            printf("please enter number of children:");
            scanf("%d",&childNumber);
            // taking the number of students came to restaurant
            printf("Please enter number of students :");
            scanf("%d",&studentNumber);

            // calling the function to take the order and print the bill
            orderMeals(studentNumber,adultNumber,childNumber);

            // to take another order we go with y, else enter n
            printf("\nwould you like to continue(y/n):");
            scanf("\n%c",&response);
    }
    printf("\n      ******************** THANK YOU FOR COMING  *************************\n");
    printf("\20**********************   PLEASE VISIT US NEXT TIME  **************************\20 \n");
    system("pause");
    return 0;
}

// function to take order and calculate bill
void orderMeals(int studentNumber,int adultNumber, int childNumber)
{
	double totalPriceForAdult, totalPriceForChildren, totalPriceForStudent;
	double allPayment,discount;
         printf("                      \t\t**** ORDER MENUE****\n");

        // calling the functions one by one and calculating the total price for each catergory
        totalPriceForAdult =  orderForAdult(adultNumber);
        //printf("\n Total bill for adults=%f",totalPriceForAdult);
        totalPriceForChildren = orderForChildren(childNumber);
        //printf("\n Total bill for Children=%f",totalPriceForChildren);
        totalPriceForStudent = orderForStudent (studentNumber);
        //printf("\n Total bill for Students=%f",totalPriceForStudent);
  // total cost for the group
		allPayment = totalPriceForAdult + totalPriceForChildren + totalPriceForStudent ;

      // calculate the bill with discount and print the bill using this function
     orderbill(adultNumber, childNumber, studentNumber, totalPriceForAdult, totalPriceForChildren, totalPriceForStudent, allPayment);

}

// function to take order from the adults
double orderForAdult(int adultNumber)
{
    int menuOption,i;
      char response = 'y';
      double totalPerPerson = 0.0,totalAllPerson = 0.0;
      double tax = 5.0;  // tax for adults
      int *amount;
      amount = (int*)malloc(sizeof(int));
      if(adultNumber <=0)
		   printf("\n ");
	  else
      printf("*\tadults:\n");
      for(i=0;i<adultNumber;i++)
     {
               printf("adult %d please enter your orders\n",i+1);
               while(response == 'y' || response == 'Y')
               {
                 // take the desired order
                    printf("please enter your option:");
                    scanf("%d",&menuOption);
                 // if not found display the message and take input again
                    if(menuOption<1 || menuOption>7)
                    {
                      printf("sorry we don`t have this order \nagain! ");
                      continue;
                    }
                 // quantity of order required
                    printf("please enter your amount of order:");
                    scanf("%d",amount);

                    // calculating the cost for one adult
                    totalPerPerson = totalPerPerson + (*amount * price[menuOption - 1] );

                    printf("\nWould you like to enter more orders(y/n):");
                    scanf("\n%c",&response);



               }
               printf("\n");
       // calculating thee total cost for adults(if more than one)
               totalAllPerson += totalAllPerson +  totalPerPerson;
               totalPerPerson = 0.0;
               response = 'y';
     }

     totalAllPerson= totalAllPerson + ((totalAllPerson * tax) / 100);
  // return the amount including the tax
     return totalAllPerson;
}

// taking order for children
double orderForChildren(int childNumber)
{
       int menuOption,i;
       int *amount;
       amount = (int*)malloc(sizeof(int));
      char response = 'y';
      double totalPerChild = 0.0,totalAllChildren = 0.0;
      double tax = 5.0,oneOrder;
       if(childNumber <=0)
		   printf("\n");
	   else
       printf("*\tChildren:\n");
       for(i=0;i<childNumber;i++)
     {
               printf("child %d please enter your orders\n",i+1);
               while(response == 'y' || response == 'Y')
               {
                              printf("please enter your option:");
                              scanf("%d",&menuOption);
							  if(menuOption<1 || menuOption>7)
							  {
								  printf("sorry we don`t have this order \nagain! ");
                                  continue;
							  }
                              printf("please enter your amount of order:");
                              scanf("%d",amount);

                              oneOrder = (price[menuOption - 1] * 60)/100 ;//this one order for a child with discount %60 of one order of adult
                              totalPerChild = totalPerChild + (*amount * oneOrder)  ;

							  printf("Would you like to enter more orders(y/n):");
                              scanf("\n%c",&response);


               }
               totalAllChildren += totalAllChildren +  totalPerChild;
               response = 'y';
               totalPerChild = 0.0;

               printf("\n");

     }

     return totalAllChildren + ((totalAllChildren * tax) / 100);
}
// taking order from student
double orderForStudent(int studentNumber)
{
     int menuOption,i;
     int *amount;
     amount = (int*)malloc(sizeof(int));
      char response = 'y';
      double totalPerPerson = 0.0,totalAllPerson = 0.0;
      double tax = 5.0, oneOrder;
      if(studentNumber <=0)
		   printf("\n ");
	  else
      printf("*\tStudents:\n");
      for(i=0;i<studentNumber;i++)
     {
               printf("student %d please enter your orders\n",i+1);
               while(response == 'y' || response == 'Y')
               {
                              printf("please enter your option:");
                              scanf("%d",&menuOption);
							  if(menuOption<1 || menuOption>7)
							  {
								  printf("sorry we don`t have this order \nagain! ");
								  continue;
							  }
                              printf("please enter your amount of order:");
                              scanf("%d",amount);

                              oneOrder = (price[menuOption - 1] * 90)/100 ;//this one order for a Student with discount %30 of one order of adult
                              totalPerPerson = totalPerPerson + (*amount * oneOrder)  ;


                              printf("\nWould you like to enter more orders(y/n):");
                              scanf("\n%c",&response);



               }
               printf("\n");
               totalAllPerson += totalAllPerson +  totalPerPerson;
               totalPerPerson = 0.0;
               response = 'y';
     }

     return totalAllPerson + ((totalAllPerson * tax) / 100);
}
