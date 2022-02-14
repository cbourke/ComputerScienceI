#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main(int argc, char **argv) {

    if(argc != 4) {
        printf("Usage: principle years interestRate\n");
        exit(1);
    }

    double principle = atof(argv[1]);
    int years = atoi(argv[2]);
    double interestRate = atof(argv[3]);

    double monthlyInterestRate = (interestRate / 12);

    //TODO: validate the input

    double monthlyPayment = (monthlyInterestRate * principle) / ( 1 - pow(1 + monthlyInterestRate, -years*12) );
    monthlyPayment = round(monthlyPayment * 100.0) / 100.0;
    printf("Monthly payment = $%.2f\n", monthlyPayment);

    double balance = principle;

    printf("Month  Balance  Interest   New Balance\n");
    for(int i=1; i<=years * 12; i++) {
        double monthlyInterest = round(monthlyInterestRate * balance * 100.0) / 100.0;
        double monthlyPrinciple = monthlyPayment - monthlyInterest;
        double newBalance = balance - monthlyPrinciple;
        printf("%d  $%10.2f | $%10.2f | $%10.2f | $%10.2f \n", i, balance, monthlyInterest, monthlyPrinciple, newBalance);
        balance = newBalance;
    }

    return 0;
}