#include<stdio.h>

void orderbill(int adultNumber, int childNumber, int studentNumber,double totalPriceForAdult,double totalPriceForChildren,double totalPriceForStudent,double allPayment)
{
  double discount;
  //print the total cost for each group seperately
  printf("\n \t\t     \22**************************************\22    \n");
     printf(" \t\t   ******************  final BILL   ************      \n");
     printf(" \t\t\tadult/child/student\tcount\t\ttotal price\n");
     printf(" \t\t\tadults\t\t%d\t\t%5.2f\n",adultNumber,totalPriceForAdult);
     printf(" \t\t\tchildren\t%d\t\t%5.2f\n",childNumber,totalPriceForChildren);
     printf(" \t\t\t\tstudent\t%d\t\t\t%5.2f\n",studentNumber,totalPriceForStudent);
     printf(" \t\t\tTotal bill\t\t\t%5.2f\n",allPayment );


    // based on the total cost, discounts were given
     if(allPayment < 1000)
		 discount=((allPayment * 0.10));
     else if(allPayment>= 1000 && allPayment<2000)
          discount=((allPayment * 0.15));
     else if(allPayment>= 2000 && allPayment<3000)
          discount=((allPayment * 0.2));
     else if(allPayment>= 3000 && allPayment<4000)
          discount=((allPayment * 0.25));
	 else
		  discount= ((allPayment * 0.3));

      // printing the total cost
          printf(" \t\t\tTotal bill after discount\t%5.2f\n",allPayment-discount);
}