#ifndef CALENDAR_H
#define CALENDAR_H

#define TRUE   1
#define FALSE  0

#define MONTHS_IN_YEAR 13  // Includes an element for leap year adjustment

typedef struct {
  char name[20];
  int days;
} Month;

int is_leap_year(int year);
int get_year_start_day(int year);
void print_calendar(int year, int daycode);
int enter_year(void);

#endif //CALENDAR_H
