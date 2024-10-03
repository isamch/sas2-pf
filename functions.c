#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <time.h>




// programmation modulaire :
#include "functions.h"

int count_reservation = 0;


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



// repet loop function :===============================================
void for_add() 
{
    int loop_choose;
    printf("How many reservations do you want to add? : ");
    scanf("%d", &loop_choose);

    for (int i = 0; i < loop_choose; i++)
    {
        add_reservation();
    }
}


// add reservation :
void add_reservation()
{


    // random id : ____________________________
    char id_reservation[max_reser][max_id];

    
    sprintf(id_reservation[count_reservation+1], "RES%d", count_reservation+1);
    

    strcpy(clien_reservation[count_reservation].id_clien, id_reservation[count_reservation+1]);
    
    printf("\nYour ID : %s\n", clien_reservation[count_reservation].id_clien);


    
    printf("\n--------------------------\n");
    printf("Enter reservation : \'%d\'", count_reservation + 1);
    printf("\n--------------------------\n");
    // add info :
    getchar();
    printf("enter your first name : ");
    scanf("%[^\n]", clien_reservation[count_reservation].first_name);

    printf("\n-----------\n");
    printf("%s\n", clien_reservation[count_reservation].first_name);

    getchar();
    printf("enter your last name : ");
    scanf("%[^\n]", clien_reservation[count_reservation].last_name);
    
    getchar();
    printf("enter your phone number : ");
    scanf("%[^\n]", clien_reservation[count_reservation].phone_number);

    getchar();
    printf("enter your age : ");
    scanf("%d", &clien_reservation[count_reservation].age);

    
    // statut :
    int choice_status;
    printf("\n-----------------\n");
    printf("choose status : \n");
    printf("1. valid.    |  2. postponed.\n");
    printf("3. canceled. |  4. processed.\n");
    printf("------\n");
    do
    {
        printf("enter : ");
        scanf("%d", &choice_status);
    } while (choice_status > 4 || choice_status < 1);
    
    switch (choice_status)
    {
    case 1:
        strcpy(clien_reservation[count_reservation].status, "valid");
        break;
    case 2:
        strcpy(clien_reservation[count_reservation].status, "postponed");
        break;
    case 3:
        strcpy(clien_reservation[count_reservation].status, "canceled");
        break;
    case 4:
        strcpy(clien_reservation[count_reservation].status, "processed");
        break;
    }

    
    // add date :
    printf("Enter the reservation date.\n");
    do
    {   
        getchar();
        printf("Day : ");
        scanf("%d", &clien_reservation[count_reservation].date_reservation.day);
    } while ( clien_reservation[count_reservation].date_reservation.day > 30 || clien_reservation[count_reservation].date_reservation.day <= 0 );
    
    do
    {       
        getchar();
        printf("Month : ");
        scanf("%d", &clien_reservation[count_reservation].date_reservation.month);
    } while ( clien_reservation[count_reservation].date_reservation.month > 12 || clien_reservation[count_reservation].date_reservation.month <= 0 );

    do
    {
        getchar();
        printf("Year : ");
        scanf("%d", &clien_reservation[count_reservation].date_reservation.year);
    } while ( clien_reservation[count_reservation].date_reservation.year > 2025 || clien_reservation[count_reservation].date_reservation.year <= 2023 );


    count_reservation++;
    printf("\ncount = %d", count_reservation);

}


// 2. Modifier ou supprimer une réservation : ===============================================
void modify_delet(){

    int choice_2;
    // menu 2 modify and delet :
    printf(COLOR_RED "\n============= Edit & Delet ===============\n");
    printf(COLOR_GREEN "  > 1. Edit.\n");
    printf("  > 2. Delet.\n" );
    printf("  > 3. Exit.\n" COLOR_RESET);
    printf("\n---------------\n");
    printf("enter you choice : ");
    scanf("%d", &choice_2);

    while (choice_2 < 1 || choice_2 >3)
    {
        printf("choice not found.!!");
        scanf("%d", &choice_2);
    }
    
    // edit choice:
    if (choice_2 == 1)
    {
        char searching_id[6];
        // searching : 
        getchar();
        printf("searching by ID about : ");
        scanf("%[^\n]", searching_id);
        int found = 0;
        int i;
        for ( i = 0; i < count_reservation; i++)
        {
            if ( strcmp( searching_id, clien_reservation[i].id_clien ) == 0 )
            {
                found = 1;
                break;
            }   
        }

        if (found != 1)
        {
            printf("reservation not found.\n");
            return;
        }else{
            
            // edit choice :
            int choice_menu_2_1;
            printf("\n-------------------\n");
            printf("want to edit : \n");
            printf(" > 0. All.\n");
            printf(" > 1. first name.\n");
            printf(" > 2. last name.\n");
            printf(" > 3. phone number.\n");
            printf(" > 4. age.\n");
            printf(" > 5. statue.\n");
            printf(" > 6. date.\n");
            printf(" > 7. return.\n");
            printf("\n-----\n");

            do
            {
                printf("enter : ");
                scanf("%d", &choice_menu_2_1);                
            } while ( choice_menu_2_1 > 7 || choice_menu_2_1 < 0 );


            printf("\n----------------------\n");
            switch (choice_menu_2_1)
            {
            case 0:
                printf("enter new : \n");

                getchar();
                printf("first name :");
                scanf("%[^\n]", clien_reservation[i].first_name);

                getchar();
                printf("last name :");
                scanf("%[^\n]", clien_reservation[i].last_name);
                
                getchar();
                printf("phone number :");
                scanf("%[^\n]", clien_reservation[i].phone_number);

                getchar();
                printf("age :");
                scanf("%[^\n]", &clien_reservation[i].age);

                // statut :
                int choice_status;
                printf("\n------------------\n");
                printf("choose new status : \n");
                printf("1. valid.    |  2. postponed.\n");
                printf("3. canceled. |  4. processed.\n");
                printf("------\n");
                do
                {
                    printf("enter : ");
                    scanf("%d", &choice_status);
                } while (choice_status > 4 || choice_status < 1);

                switch (choice_status)
                {
                case 1:
                    strcpy(clien_reservation[count_reservation].status, "valid");
                    break;
                case 2:
                    strcpy(clien_reservation[count_reservation].status, "postponed");
                    break;
                case 3:
                    strcpy(clien_reservation[count_reservation].status, "canceled");
                    break;
                case 4:
                    strcpy(clien_reservation[count_reservation].status, "processed");
                    break;
                }

                // new date :
                printf("enter new date ; \n");
                do
                {   
                    getchar();
                    printf("Day : ");
                    scanf("%d", &clien_reservation[i].date_reservation.day);
                } while ( clien_reservation[i].date_reservation.day > 30 || clien_reservation[i].date_reservation.day <= 0 );
                
                do
                {       
                    getchar();
                    printf("Month : ");
                    scanf("%d", &clien_reservation[i].date_reservation.month);
                } while ( clien_reservation[i].date_reservation.month > 12 || clien_reservation[i].date_reservation.month <= 0 );

                do
                {
                    getchar();
                    printf("Year : ");
                    scanf("%d", &clien_reservation[i].date_reservation.year);
                } while ( clien_reservation[i].date_reservation.year > 2025 || clien_reservation[i].date_reservation.year <= 2023 );
                
                break;
            case 1:
                getchar();
                printf("first name :");
                scanf("%[^\n]", clien_reservation[i].first_name);
                break;
            case 2:
                getchar();
                printf("last name :");
                scanf("%[^\n]", clien_reservation[i].last_name);
                break;
            case 3:
                getchar();
                printf("phone number :");
                scanf("%[^\n]", clien_reservation[i].phone_number);
                break;
            case 4:
                getchar();
                printf("age :");
                scanf("%[^\n]", &clien_reservation[i].age);
                break;
            case 5:
                // statut :
                printf("\n------------------\n");
                printf("choose new status : \n");
                printf("1. valid.    |  2. postponed.\n");
                printf("3. canceled. |  4. processed.\n");
                printf("------\n");
                do
                {
                    printf("enter : ");
                    scanf("%d", &choice_status);
                } while (choice_status > 4 || choice_status < 1);
                
                switch (choice_status)
                {
                case 1:
                    strcpy(clien_reservation[count_reservation].status, "valid");
                    break;
                case 2:
                    strcpy(clien_reservation[count_reservation].status, "postponed");
                    break;
                case 3:
                    strcpy(clien_reservation[count_reservation].status, "canceled");
                    break;
                case 4:
                    strcpy(clien_reservation[count_reservation].status, "processed");
                    break;
                }

                break;
            case 6:
                // new date :
                printf("enter new date ; \n");
                do
                {   
                    getchar();
                    printf("Day : ");
                    scanf("%d", &clien_reservation[i].date_reservation.day);
                } while ( clien_reservation[i].date_reservation.day > 30 || clien_reservation[i].date_reservation.day <= 0 );
                
                do
                {       
                    getchar();
                    printf("Month : ");
                    scanf("%d", &clien_reservation[i].date_reservation.month);
                } while ( clien_reservation[i].date_reservation.month > 12 || clien_reservation[i].date_reservation.month <= 0 );

                do
                {
                    getchar();
                    printf("Year : ");
                    scanf("%d", &clien_reservation[i].date_reservation.year);
                } while ( clien_reservation[i].date_reservation.year > 2025 || clien_reservation[i].date_reservation.year <= 2023 );
                break;
            case 7:
                return;
                break;
            }
        }
    }else if (choice_2 == 2)
    {
        // delet:
        char searching_id[6];
        // searching : 
        getchar();
        printf("searching by ID about : ");
        scanf("%[^\n]", searching_id);
        int found = 0;
        int i;
        for ( i = 0; i < count_reservation; i++)
        {
            if ( strcmp( searching_id, clien_reservation[i].id_clien ) == 0 )
            {
                found = 1;
                break;
            }   
        }

        if(found != 1){
            printf("reservation not found.\n");
            return;
        }else{
            
            for ( i = i; i < count_reservation - 1; i++)
            {
                clien_reservation[i] = clien_reservation[i+1];
            }
            count_reservation--;
        }

    }else if (choice_2 == 3)
    {
        return;
    }
    
}



// 3. Afficher les détails d'une réservation : ===============================================
void affichage_res(){

    printf(COLOR_RED "\n============================== Reservations List ================================\n");

    printf(COLOR_RED "\n+----------+------------+------------+----------------+-------+----------+-------------+\n");
    printf(COLOR_GREEN "| ID       | f-name     | l-name     | phone number   | age   | status   | date        |");
    printf(COLOR_RED "\n+----------+------------+------------+----------------+-------+----------+-------------+\n");

    for (int i = 0; i < count_reservation; i++)
    {
        
        printf(COLOR_GREEN "| %-9s| %-11s| %-11s| %-15s| %-6d| %-9s| %02d-%02d-%04d  |\n",
        // printf(COLOR_GREEN " id : %s \n name : %s \n last name : %s \n phone number : %s \n age : %d\n status : %s\n",
        clien_reservation[i].id_clien,
        clien_reservation[i].first_name,
        clien_reservation[i].last_name,
        clien_reservation[i].phone_number,
        clien_reservation[i].age,
        clien_reservation[i].status,
        clien_reservation[i].date_reservation.day,
        clien_reservation[i].date_reservation.month,
        clien_reservation[i].date_reservation.year
        );

        
    }

    printf(COLOR_RED "\n+----------+------------+------------+----------------+-------+----------+-------------+\n");


    // for (int i = 0; i < count_reservation; i++)
    // {
    //     printf("\n--------- reservation %d ---------\n", i+1);
    //     printf("ID             : %s\n", clien_reservation[i].id_clien);
    //     printf("first name     : %s\n", clien_reservation[i].first_name);
    //     printf("last name      : %s\n", clien_reservation[i].last_name);
    //     printf("phone number   : %s\n", clien_reservation[i].phone_number);
    //     printf("age            : %d\n", clien_reservation[i].age);
    //     printf("status         : %s\n", clien_reservation[i].status);
    //     printf("date           : %02d-%02d-%04d \n\n", clien_reservation[i].date_reservation.day,
    //         clien_reservation[i].date_reservation.month, clien_reservation[i].date_reservation.year);


    // }
    
}




// 4. Tri des réservations : ===============================================
void sorting_res(){

    int choice_menu_4;
    // menu 4 :
    printf("\n========== sorting menu =========\n");
    printf("Sorting by : \n");
    printf(" > 1. first name.\n");
    printf(" > 2. status.\n");
    printf(" >> 3. return.\n");
    printf("enter : ");
    getchar();
    scanf("%d", &choice_menu_4);

    dentaires_reservation temp;

    if ( choice_menu_4 == 1 )
    {
        // name sort :

        for (int i = 0; i < count_reservation - 1; i++)
        {
            for (int j = 0; j < count_reservation - 1; j++)
            {
                if (strcmp(clien_reservation[j].first_name, clien_reservation[j + 1].first_name) > 0)
                {
                    temp = clien_reservation[j];
                    clien_reservation[j] = clien_reservation[j + 1];
                    clien_reservation[j + 1] = temp;
                }
            }
        }
        
        void affichage_res();

    }else if ( choice_menu_4 == 2)
    {
        // staus sort :

        for (int i = 0; i < count_reservation - 1; i++)
        {
            for (int j = 0; j < count_reservation - 1; j++)
            {
                if (strcmp(clien_reservation[j].status, clien_reservation[j + 1].status) > 0)
                {
                    temp = clien_reservation[j];
                    clien_reservation[j] = clien_reservation[j + 1];
                    clien_reservation[j + 1] = temp;
                }
            }
        }

        void affichage_res();

    }else if ( choice_menu_4 == 3)
    {
        return;
    }
    
}


// 5. Recherche des réservations :===============================================
void search_res(){

    // menu 5 :
    int choice_meni_5;
    printf("\n======= searching menu ==========\n");
    printf("searching by :\n");
    printf(" > 1. ID.\n");
    printf(" > 2. first name.\n");
    printf(" > 3. date.\n");
    printf(" >> 4. return.\n");
    getchar();
    printf("enter : ");
    scanf("%d", &choice_meni_5);

    if (choice_meni_5 == 1)
    {
        // search by id:
        char search_by_id[max_id];
        int found = 0;
        int i;
        for ( i = 0; i < count_reservation; i++)
        {
            if (strcmp( search_by_id, clien_reservation[i].id_clien ) == 0)
            {
                found = 1;
                break;
            }
        }
        
        if (found == 1)
        {

                printf(COLOR_RED "\n============================== Reservations List ================================\n");
                printf(COLOR_RED "\n+----------+------------+------------+----------------+-------+----------+-------------+\n");
                printf(COLOR_GREEN "| ID       | f-name     | l-name     | phone number   | age   | status   | date        |");
                printf(COLOR_RED "\n+----------+------------+------------+----------------+-------+----------+-------------+\n");

                printf(COLOR_GREEN "| %-9s| %-11s| %-11s| %-15s| %-6d| %-9s| %02d-%02d-%04d  |\n",
                clien_reservation[i].id_clien,
                clien_reservation[i].first_name,
                clien_reservation[i].last_name,
                clien_reservation[i].phone_number,
                clien_reservation[i].age,
                clien_reservation[i].status,
                clien_reservation[i].date_reservation.day,
                clien_reservation[i].date_reservation.month,
                clien_reservation[i].date_reservation.year
                );

                printf(COLOR_RED "\n+----------+------------+------------+----------------+-------+----------+-------------+\n");
                      


        }else{
            printf("ID Not Found.\n");
            return;
        }
        

    }else if (choice_meni_5 == 2)
    {
        // search by  first name:
        char search_by_f_name[max_id];
        int found = 0;
        int i;
        for ( i = 0; i < count_reservation; i++)
        {
            if (strcasecmp( search_by_f_name, clien_reservation[i].first_name ) == 0)
            {
                found = 1;
                break;
            }
        }
        
        if (found == 1)
        {

                printf(COLOR_RED "\n============================== Reservations List ================================\n");
                printf(COLOR_RED "\n+----------+------------+------------+----------------+-------+----------+-------------+\n");
                printf(COLOR_GREEN "| ID       | f-name     | l-name     | phone number   | age   | status   | date        |");
                printf(COLOR_RED "\n+----------+------------+------------+----------------+-------+----------+-------------+\n");

                printf(COLOR_GREEN "| %-9s| %-11s| %-11s| %-15s| %-6d| %-9s| %02d-%02d-%04d  |\n",
                clien_reservation[i].id_clien,
                clien_reservation[i].first_name,
                clien_reservation[i].last_name,
                clien_reservation[i].phone_number,
                clien_reservation[i].age,
                clien_reservation[i].status,
                clien_reservation[i].date_reservation.day,
                clien_reservation[i].date_reservation.month,
                clien_reservation[i].date_reservation.year
                );

                printf(COLOR_RED "\n+----------+------------+------------+----------------+-------+----------+-------------+\n");
                      


        }else{
            printf("ID Not Found.\n");
            return;
        }



    }else if (choice_meni_5 == 3)
    {
        printf("Feature not available.\n");
    }else if (choice_meni_5 == 4)
    {
        return;
    }
    
}



// 6. Statistiques :===============================================
void statistiques(){

    int choice_menu_6;
    // menu _ 6 :
    printf("\n======== Statistics =========\n");
    printf(" > 1. average age of patients who have booked.\n");
    printf(" > 2. Show the number of patients by age group.\n");
    printf(" > 3. Generate statistics to know the total number of reservations by status.\n");
    printf(" >> 4. return.\n");
    getchar();
    printf("enter : ");
    scanf("%d", &choice_menu_6);

    if (choice_menu_6 == 1)
    {
        // average age :
        int average_age;
        int sum = 0;
        for (int i = 0; i < count_reservation; i++)
        {

            sum = sum + clien_reservation[i].age;
        }
        
        average_age = sum / count_reservation;

        printf("\n----------------\n");
        printf("The Average age is : %d", average_age);


    }else if ( choice_menu_6 == 2)
    {
        // Show the number of patients by age group:
        int age_0_18 = 0;
        int age_19_35 = 0;
        int age_36_ = 0;

        printf("\n----------------\n");

        for (int i = 0; i < count_reservation; i++)
        {
            if ( clien_reservation[i].age >= 0 && clien_reservation[i].age <=18 )
            {
                age_0_18++;   
            }else if ( clien_reservation[i].age >= 19 && clien_reservation[i].age <=35 )
            {
                age_19_35++;    
            }else if ( clien_reservation[i].age >= 36)
            {
                age_36_++;
            }
        }

        printf("\n number of patients by age group : \n");
        // resault :
        printf("Patients between (00 -- 18) : %d\n", age_0_18);
        printf("Patients between (19 -- 35) : %d\n", age_19_35);
        printf("Patients older than (36)    : %d\n", age_36_);

    }else if ( choice_menu_6 == 3)
    {

        // Generate statistics to know the total number of reservations by status :
        
        int number_valid     = 0;
        int number_postponed = 0;
        int number_canceled  = 0;
        int number_processed = 0;

    


        for (int i = 0; i < count_reservation; i++)
        {
            if ( strcmp(clien_reservation[i].status , "valid") == 0)
            {
                number_valid++;
            }else if ( strcmp(clien_reservation[i].status , "postponed") == 0)
            {
                number_postponed++;
            }else if ( strcmp(clien_reservation[i].status , "canceled") == 0)
            {
                number_canceled++;
            }else if ( strcmp(clien_reservation[i].status , "processed") == 0)
            {
                number_processed++;
            }
        }

        printf("\n------------------\n");
        printf("Number of bookings with status : \n");
        printf("Valid     : %d\n", number_valid);
        printf("postponed : %d\n", number_postponed);
        printf("canceled  : %d\n", number_canceled);
        printf("processed : %d\n", number_processed);


    }else if (choice_menu_6 == 4)
    {
        return;
    }
    
}






