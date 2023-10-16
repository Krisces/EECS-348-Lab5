#include <stdio.h>


// Function to read sales data from file
void readSalesData(FILE *file, double sales[], int n) {
   for (int i = 0; i < n; i++) {
       fscanf(file, "%lf", &sales[i]);
   }
}


// Function to find minimum sales and corresponding month
void findMinSales(double sales[], char *months[], int n, double *minSales, char **minMonth) {
   *minSales = sales[0];
   *minMonth = months[0];


   for (int i = 1; i < n; i++) {
       if (sales[i] < *minSales) {
           *minSales = sales[i];
           *minMonth = months[i];
       }
   }
}


// Function to find maximum sales and corresponding month
void findMaxSales(double sales[], char *months[], int n, double *maxSales, char **maxMonth) {
   *maxSales = sales[0];
   *maxMonth = months[0];


   for (int i = 1; i < n; i++) {
       if (sales[i] > *maxSales) {
           *maxSales = sales[i];
           *maxMonth = months[i];
       }
   }
}


// Function to calculate average
double calculateAverage(double sales[], int n) {
   double sum = 0;
   for (int i = 0; i < n; i++) {
       sum += sales[i];
   }
   return sum / n;
}


// Function to calculate moving averages
void calculateMovingAverages(double sales[], int n, double averages[]) {
   for (int i = 0; i <= n - 6; i++) {
       double sum = 0;
       for (int j = i; j < i + 6; j++) {
           sum += sales[j];
       }
       averages[i] = sum / 6;
   }
}


// Function to sort sales data in descending order
void sortSalesData(double sales[], char *months[], int n) {
   for (int i = 0; i < n - 1; i++) {
       for (int j = 0; j < n - i - 1; j++) {
           if (sales[j] < sales[j+1]) {
               double tempSales = sales[j];
               sales[j] = sales[j+1];
               sales[j+1] = tempSales;


               char *tempMonth = months[j];
               months[j] = months[j+1];
               months[j+1] = tempMonth;
           }
       }
   }
}


int main() {
   FILE *file = fopen("sales_input.txt", "r");


   if (file == NULL) {
       printf("Error opening file.\n");
       return 1;
   }


   char *months[12] = {"January", "February", "March", "April", "May", "June",
                       "July", "August", "September", "October", "November", "December"};
   double sales[12];
   readSalesData(file, sales, 12);
   fclose(file);


   // Sales report
   printf("Monthly sales report for 2022:\n");
   printf("Month\tSales\n");
   for (int i = 0; i < 12; i++) {
       printf("%s\t$%.2lf\n", months[i], sales[i]);
   }


   // Minimum sales
   double minSales;
   char *minMonth;
   findMinSales(sales, months, 12, &minSales, &minMonth);


   // Maximum sales
   double maxSales;
   char *maxMonth;
   findMaxSales(sales, months, 12, &maxSales, &maxMonth);


   // Average sales
   double avgSales = calculateAverage(sales, 12);


   printf("\nSales summary:\n");
   printf("Minimum sales: $%.2lf (%s)\n", minSales, minMonth);
   printf("Maximum sales: $%.2lf (%s)\n", maxSales, maxMonth);
   printf("Average sales: $%.2lf\n", avgSales);


   // Moving averages
   double movingAverages[7];
   calculateMovingAverages(sales, 12, movingAverages);


   printf("\nSix-Month Moving Average Report:\n");
   for (int i = 0; i < 7; i++) {
       printf("%s - %s\t$%.2lf\n", months[i], months[i+5], movingAverages[i]);
   }


   // Sort sales data in descending order
   sortSalesData(sales, months, 12);


   // Sales Report (Highest to Lowest)
   printf("\nSales Report (Highest to Lowest):\n");
   printf("Month\tSales\n");
   for (int i = 0; i < 12; i++) {
       printf("%s\t$%.2lf\n", months[i], sales[i]);
   }


   return 0;
}
