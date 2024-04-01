#include <stdio.h>
#include "calendar.h"

Month months[MONTHS_IN_YEAR] = {
  {" ", 0},
  {"\n\n\nJanuary", 31},
  {"\n\n\nFebruary", 28}, /* Adjust for leap year */
  {"\n\n\nMarch", 31},
  {"\n\n\nApril", 30},
  {"\n\n\nMay", 31},
  {"\n\n\nJune", 30},
  {"\n\n\nJuly", 31},
  {"\n\n\nAugust", 31},
  {"\n\n\nSeptember", 30},
  {"\n\n\nOctober", 31},
  {"\n\n\nNovember", 30},
  {"\n\n\nDecember", 31}
};

int is_leap_year(int year) {
  if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
    months[2].days = 29;
    return TRUE;
  }
  else {
    months[2].days = 28;
    return FALSE;
  }
}

/* Calculate the day of the week for January 1st*/
int get_year_start_day(int year) {
  int start_day, d1, d2, d3;
  d1 = (year - 1) / 4;
  d2 = (year - 1) / 100;
  d3 = (year - 1) / 400;
  start_day = (year + d1 - d2 + d3) %7;
  return start_day;
}

void print_calendar(int year, int start_day)
{
  int day;
  for (int month = 1; month <= 12; month++) {
    printf("%s", months[month].name);
    printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n" );


    /* correct first date position */
    int days = months[month].days;
    for (day = 1; day <= 1 + start_day * 5; day++) {
      printf(" ");
    }

    /* Print all dates in one month */
    for (day = 1; day <= days; day++) {
      printf("%2d", day);

      /* Start on next line if day falls after Sat */
      if ((day + start_day) % 7 > 0)
         printf("   " );
      else
        printf("\n " );
    }
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
  is_leap_year(year);
  print_calendar(year, start_day);
  printf("\n");
}
