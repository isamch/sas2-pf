#ifndef FUNCTIONS_C
#define FUNCTIONS_C

// defind color :
// Define color constants
#define COLOR_RESET "\033[0m"
#define COLOR_RED "\033[31m"
#define COLOR_GREEN "\033[32m"
#define COLOR_BLUE "\033[34m"
#define COLOR_YELLOW "\033[33m"

// Define color default
#define COLOR_RESET "\033[0m"


// defin max:
#define max_reser_month 600
#define max_reser_per_day 10
#define max_char 50


// structur :
typedef struct 
{
    int day;
    int month;
    int year;

} date_reservation;

typedef struct 
{
    char firs_name[max_char];
    char last_name[max_char];
    char phone_number[max_char];
    int  age;
    char status[max_char];
    int id_clien;
    date_reservation date_reservation;

} dentaires_reservation;



extern dentaires_reservation clien_reservation[max_reser_month];



// functoin link :










#endif
