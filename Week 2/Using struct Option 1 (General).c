
#include <stdio.h>

typedef enum month{ jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec} month;
typedef struct date{ month m; int d;} date;
int max_days, i;

void printday(date* dt)
{

    switch(dt-> m)
    {
        case jan:
            printf("January %d", dt->d);
            max_days = 31;
            break;
        case feb:
            printf("February %d", dt->d);
            max_days = 28;
            break;
        case mar:
            printf("March %d", dt->d);
            max_days = 31;
            break;
        case apr:
            printf("April %d", dt->d);
            max_days = 30;
            break;
        case may:
            printf("May %d", dt->d);
            max_days = 31;
            break;
        case jun:
            printf("June %d", dt->d);
            max_days = 30;
            break;
        case jul:
            printf("July %d", dt->d);
            max_days = 31;
            break;
        case aug:
            printf("August %d", dt->d);
            max_days = 31;
            break;
        case sep:
            printf("September %d", dt->d);
            max_days = 30;
            break;
        case oct:
            printf("October %d", dt->d);
            max_days = 31;
            break;
        case nov:
            printf("November %d", dt->d);
            max_days = 30;
            break;
        case dec:
            printf("December %d", dt->d);
            max_days = 31;
            break;
    }
}
date* nextday(date* dt)
{
    if (dt->d==max_days) //For the case that we're in the last day of the month
    {
        dt->d = (dt->d + 1)%max_days;
        dt->m = (dt->m + 1)%12; //%12 for the case that we're in the last day of the year
    }
    else //If we're not in the end of the month, just increment the day
        dt->d = dt->d + 1;
    return dt;
}

int main()
{
    date date1 = {jan, 1};
    date date2 = {feb, 28};
    date date3 = {mar, 14};
    date date4 = {oct, 31};
    date date5 = {dec, 31};
    date dates[] = {date1, date2, date3, date4, date5};
    
    for (i=0; i<5; i++)
    {
        printf("Date is ");
        printday(&dates[i]);
        printf("\nNext day is ");
        nextday(&dates[i]);
        printday(&dates[i]);
        printf("\n\n");
    }

    return 0;
}
