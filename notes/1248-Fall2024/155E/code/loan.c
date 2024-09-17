/**
 * CSCE 155E - Fall 2024
 *
 * Computes a loan amortization table
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/**
 * Returns the given amount rounded to the nearest cent
 * (rounded to the nearest hundredth)
 */
double roundToCents(double amount);

/**
 * Computes the monthly payment of a loan with the given
 * inputs.  See <a href="https://en.wikipedia.org/wiki/Amortization_calculator">here</a>
 */
double getMonthlyPayment(double principle, double annualRate, int years);

int main(int argc, char **argv) {

  double annualRate = 0.05;
  double monthlyRate = annualRate / 12;
  double principle = 10000.0;
  double balance = principle;
  int years = 5;
  int months = years * 12;

  double monthlyPayment = getMonthlyPayment(principle, annualRate, years);
  //TODO: round to the nearest cent...
  monthlyPayment = roundToCents(monthlyPayment);

  printf("Monthly Payment: $%.2f\n", monthlyPayment);

  for(int i=1; i<months; i++) {
    double monthlyInterest = roundToCents(monthlyRate * balance);
    double monthlyPrinciple = roundToCents(monthlyPayment - monthlyInterest);
    double newBalance = balance - monthlyPrinciple;
    printf("%d $%.2f   $%.2f  $%.2f $%.2f   $\n", i, balance, monthlyInterest, monthlyPrinciple, newBalance);
    balance = balance - monthlyPrinciple;
  }
  //TODO: change this to handle the last month separately

  return 0;
}

double roundToCents(double amount) {
  return round(amount * 100.0) / 100.0;
}

double getMonthlyPayment(double principle, double annualRate, int years) {
  double monthlyRate = annualRate / 12;
  int months = years * 12;
  double monthlyPayment = (monthlyRate * principle) / (1 - pow(1 + monthlyRate, -months) );
  return monthlyPayment;
}
