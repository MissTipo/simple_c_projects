#include <stdio.h>
#include "calendar.h"

Month months[MONTHS_IN_YEAR] = {
  {" ", 0},
  {"January", 31},
  {"February", 28}, /* Adjust for leap year */
  {"March", 31},
  {"April", 30},
  {"May", 31},
  {"June", 30},
  {"July", 31},
  {"August", 31},
  {"September", 30},
  {"October", 31},
  {"November", 30},
  {"December", 31}
};

int is_leap_year(int year) {
  return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

/* Calculate the day of the week for January 1st*/
int get_year_start_day(int year) {
  int start_day = year + (year / 4) - (year / 100) + (year / 400);
  return start_day % 7;
}

void print_calendar(int year, int start_day) {
  for (int month = 1; month <= 12; month++) {
    printf("\n\n\n%s", months[month].name);

    /* Make adjustment for leap year */
    int days = months[month].days + (is_leap_year(year) && month == 2);

    /* Print the leading spaces */
    for (int day = 1; day <= start_day; day++) {
      printf("    ");
    }

    /* Print all dates in a month */
    for (int day = 1; day <= days; day++) {
      printf("%2d   ", day);
      if ((day + start_day) % 7 == 0) {
        printf("\n");
      }
    }
    printf("\n");

    /* Update start day for the next month */
    start_day = (start_day + days) % 7;
  }
}

int enter_year(void) {
  int year;

  printf("Please enter a year (example: 2022) : ");
  scanf("%d", &year);
  return year;
}

int main(void) {
  int year, start_day;
  year = enter_year();
  start_day = get_year_start_day(year);
  print_calendar(year, start_day);

  return 0;
}
