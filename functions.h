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
#define max_reser 100
#define max_char 50
#define max_id 6
#define max_per_day 10

// structur :
typedef struct
{
    int day;
    int month;
    int year;

} date_reservation;

typedef struct
{
    char id_clien[max_id];
    char first_name[max_char];
    char last_name[max_char];
    char phone_number[max_char];
    int age;
    char status[max_char];
    date_reservation date_reservation;

} dentaires_reservation;

// ------------------:
extern dentaires_reservation clien_reservation[max_reser];

extern int count_reservation;

// functoin link :

void show_menu();
void for_add();
void add_reservation();
void modify_delet();
void affichage_res();
void sorting_res();
void search_res();
void statistiques();
void wit_for_entr();

#endif