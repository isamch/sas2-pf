#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <time.h>




// programmation modulaire :
#include "functions.h"

int count_per_month = 0;
int count_rend_day = 0;


// function for generate id :

int generate_id(){
    srand((unsigned int)time(NULL));        
    int random_nbr_id = (rand() % (600 + 1));
    return random_nbr_id;
}






// Affichage Menu:
void show_menu()
{
    printf(COLOR_RED "\n============= MENU ===============\n");
    printf(COLOR_GREEN "  > 1. Add a booking.\n");
    printf("  > 2. Modify or delete a booking.\n");
    printf("  > 3. View booking details.\n");
    printf("  > 4. Sort bookings.\n");
    printf("  > 5. Search reservations.\n");
    printf("  > 6. Statistics.\n" );
    printf("  > 7. Exit.\n" COLOR_RESET);
    printf(COLOR_RED "\n===================================\n" COLOR_RESET);
}



// add reservation :
void add_reservation(){

    // add info :
    getchar();
    printf("enter your first name : ");
    scanf("%[^\n]", clien_reservation[count_per_month].firs_name);

    getchar();
    printf("enter your last name : ");
    scanf("%[^\n]", clien_reservation[count_per_month].last_name);
    
    getchar();
    printf("enter your phone number : ");
    scanf("%[^\n]", clien_reservation[count_per_month].phone_number);

    getchar();
    printf("enter your age : ");
    scanf("%d", clien_reservation[count_per_month].age);

    // id_clien :
    printf("generating the ID");
    for (int i = 0; i < 5; i++)
    {
        printf(".");
        Sleep(90);
    }

    // check if id dega exist :
    generate_other_id:
    int random_id = generate_id();
    for (int i = 0; i < count_per_month; i++)
    {
        if ( random_id == clien_reservation[i].id_clien )
        {
            goto generate_other_id;
        }
    }
    
    clien_reservation[count_per_month].id_clien = random_id;

    printf("your id is : %d", random_id);
    

    // add date :
    
    printf("Enter the reservation date.\n");
    getchar();
    printf("Day : ");
    scanf("%d", &clien_reservation[count_per_month].date_reservation.day);
    getchar();
    printf("Month : ");
    scanf("%d", &clien_reservation[count_per_month].date_reservation.month);
    getchar();
    printf("Year : ");
    scanf("%d", &clien_reservation[count_per_month].date_reservation.year);

    
    




}



















