#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <Windows.h>
// #include <time.h>

// programmation modulaire :
#include "functions.h"

int count_reservation = 0;

// wait for enter :
void wit_for_entr()
{
    printf(COLOR_YELLOW"\nPress enter to continue ..."COLOR_BLUE);
    getchar();
    getchar();
}

// Affichage Menu:
void show_menu()
{
    printf(COLOR_GREEN "\n============= MENU ===============\n");
    printf(COLOR_BLUE "  > 1. Add a booking.\n");
    printf("  > 2. Modify or delete a booking.\n");
    printf("  > 3. View booking details.\n");
    printf("  > 4. Sort bookings.\n");
    printf("  > 5. Search reservations.\n");
    printf("  > 6. Statistics.\n");
    printf("  > 7. Exit.\n");
    printf(COLOR_GREEN "\n===================================\n" COLOR_BLUE);
}

// repet loop function :===============================================
void for_add()
{

    if (count_reservation >= max_reser)
    {
        printf(COLOR_RED"reservations plein.\n"COLOR_BLUE);
        return;
    }
    else
    {

        int loop_choose;
        printf("How many reservations do you want to add? ");
        printf(COLOR_RED "(Entrez 0 pour retour):  " COLOR_BLUE);

        scanf("%d", &loop_choose);
        if (loop_choose == 0)
        {
            return;
        }

        if (loop_choose + count_reservation >= max_reser)
        {
            printf("You can't add all this reservation. Available only \'%d\' reservation.\n", max_reser - count_reservation);
        }
        else
        {
            for (int i = 0; i < loop_choose; i++)
            {
                printf(COLOR_GREEN"\n------------------------------\n");
                printf(COLOR_BLUE"Enter reservation : \'%d\'", count_reservation + 1);
                printf(COLOR_GREEN"\n-----------------\n"COLOR_BLUE);

                add_reservation();
            }
        }
    }
}

// add reservation :
void add_reservation()
{

    // random id : ____________________________
    char id_reservation[max_reser][max_id];
    sprintf(id_reservation[count_reservation + 1], "RES%02d", count_reservation + 1);

    strcpy(clien_reservation[count_reservation].id_clien, id_reservation[count_reservation + 1]);
    printf("\nYour ID : %s\n", clien_reservation[count_reservation].id_clien);

    // add info :
    getchar();
    printf("enter your first name   : ");
    scanf("%[^\n]", clien_reservation[count_reservation].first_name);

    getchar();
    printf("enter your last name    : ");
    scanf("%[^\n]", clien_reservation[count_reservation].last_name);

    getchar();
    printf("enter your phone number : ");
    scanf("%[^\n]", clien_reservation[count_reservation].phone_number);

    getchar();
    printf("enter your age          : ");
    scanf("%d", &clien_reservation[count_reservation].age);

    // statut :
    int choice_status;
    printf(COLOR_GREEN"\n-----------------\n");
    printf(COLOR_BLUE"choose status : \n");
    printf("1. valid.    |  2. postponed.\n");
    printf("3. canceled. |  4. processed.\n");
    printf(COLOR_GREEN"--------\n"COLOR_BLUE);
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
        printf("Day   : ");
        scanf("%d", &clien_reservation[count_reservation].date_reservation.day);
    } while (clien_reservation[count_reservation].date_reservation.day > 30 || clien_reservation[count_reservation].date_reservation.day <= 0);

    do
    {
        getchar();
        printf("Month : ");
        scanf("%d", &clien_reservation[count_reservation].date_reservation.month);
    } while (clien_reservation[count_reservation].date_reservation.month > 12 || clien_reservation[count_reservation].date_reservation.month <= 0);

    do
    {
        getchar();
        printf("Year  : ");
        scanf("%d", &clien_reservation[count_reservation].date_reservation.year);
    } while (clien_reservation[count_reservation].date_reservation.year > 2025 || clien_reservation[count_reservation].date_reservation.year <= 2023);

    count_reservation++;
    printf(COLOR_GREEN"successfully done!!\n"COLOR_GREEN);

}

// 2. Modifier ou supprimer une réservation : ===============================================
void modify_delet()
{

    if (count_reservation == 0)
    {
        printf(COLOR_YELLOW"reservations empty.\n"COLOR_BLUE);
        return;
    }


    int choice_2;
    // menu 2 modify and delet :
    printf(COLOR_GREEN "\n============= Edit & Delet ===============\n");
    printf(COLOR_BLUE "  > 1. Edit.\n");
    printf(COLOR_RED "  > 2. Delet.\n" COLOR_YELLOW);
    printf("  > 3. return.\n");
    printf(COLOR_GREEN "\n---------------\n" COLOR_BLUE);
    printf("enter you choice : ");
    scanf("%d", &choice_2);

    while (choice_2 < 1 || choice_2 > 3)
    {
        printf(COLOR_RED"choice not found.!!"COLOR_BLUE);
        printf("enter you choice again : ");
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
        for (i = 0; i < count_reservation; i++)
        {
            if (strcmp(searching_id, clien_reservation[i].id_clien) == 0)
            {
                found = 1;
                break;
            }
        }

        if (found != 1)
        {
            printf(COLOR_RED"reservation not found.\n"COLOR_BLUE);
            return;
        }
        else
        {

            // edit choice :
            int choice_menu_2_1;
            printf(COLOR_GREEN "\n-------------------\n" COLOR_BLUE);
            printf("want to edit : \n");
            printf(" > 0. All.\n");
            printf(" > 1. first name.\n");
            printf(" > 2. last name.\n");
            printf(" > 3. phone number.\n");
            printf(" > 4. age.\n");
            printf(" > 5. statue.\n");
            printf(" > 6. date.\n");
            printf(COLOR_YELLOW " > 7. return.\n");
            printf(COLOR_GREEN "\n-----\n" COLOR_BLUE);

            do
            {
                printf("enter : ");
                scanf("%d", &choice_menu_2_1);
            } while (choice_menu_2_1 > 7 || choice_menu_2_1 < 0);

            printf(COLOR_GREEN"\n----------------------\n"COLOR_BLUE);
            switch (choice_menu_2_1)
            {
            case 0:
                printf("enter new : \n");

                getchar();
                printf(" > first name  :");
                scanf("%[^\n]", clien_reservation[i].first_name);

                getchar();
                printf(" > last name   :");
                scanf("%[^\n]", clien_reservation[i].last_name);

                getchar();
                printf(" > phone number:");
                scanf("%[^\n]", clien_reservation[i].phone_number);

                getchar();
                printf(" > age         :");
                scanf("%d", &clien_reservation[i].age);

                // statut :
                int choice_status;
                printf(COLOR_GREEN"\n------------------\n");
                printf(COLOR_BLUE"choose new status : \n");
                printf("1. valid.    |  2. postponed.\n");
                printf("3. canceled. |  4. processed.\n");
                printf(COLOR_GREEN"--------\n"COLOR_BLUE);
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
                    printf("Day   : ");
                    scanf("%d", &clien_reservation[i].date_reservation.day);
                } while (clien_reservation[i].date_reservation.day > 30 || clien_reservation[i].date_reservation.day <= 0);

                do
                {
                    getchar();
                    printf("Month : ");
                    scanf("%d", &clien_reservation[i].date_reservation.month);
                } while (clien_reservation[i].date_reservation.month > 12 || clien_reservation[i].date_reservation.month <= 0);

                do
                {
                    getchar();
                    printf("Year  : ");
                    scanf("%d", &clien_reservation[i].date_reservation.year);
                } while (clien_reservation[i].date_reservation.year > 2025 || clien_reservation[i].date_reservation.year <= 2023);

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
                scanf("%d", &clien_reservation[i].age);
                break;
            case 5:
                // statut :
                printf(COLOR_GREEN"\n------------------\n");
                printf(COLOR_BLUE"choose new status : \n");
                printf("1. valid.    |  2. postponed.\n");
                printf("3. canceled. |  4. processed.\n");
                printf(COLOR_GREEN"-------\n"COLOR_BLUE);
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
                    printf("Day   : ");
                    scanf("%d", &clien_reservation[i].date_reservation.day);
                } while (clien_reservation[i].date_reservation.day > 30 || clien_reservation[i].date_reservation.day <= 0);

                do
                {
                    getchar();
                    printf("Month : ");
                    scanf("%d", &clien_reservation[i].date_reservation.month);
                } while (clien_reservation[i].date_reservation.month > 12 || clien_reservation[i].date_reservation.month <= 0);

                do
                {
                    getchar();
                    printf("Year  : ");
                    scanf("%d", &clien_reservation[i].date_reservation.year);
                } while (clien_reservation[i].date_reservation.year > 2025 || clien_reservation[i].date_reservation.year <= 2023);
                break;
            case 7:
                return;
                break;
            }

            printf(COLOR_GREEN"successfully done!!\n"COLOR_GREEN);
        }
    }
    else if (choice_2 == 2)
    {
        // delet:
        char searching_id[6];
        // searching :
        getchar();
        printf("searching by ID about : ");
        scanf("%[^\n]", searching_id);
        int found = 0;
        int i;
        for (i = 0; i < count_reservation; i++)
        {
            if (strcmp(searching_id, clien_reservation[i].id_clien) == 0)
            {
                found = 1;
                break;
            }
        }

        if (found != 1)
        {
            printf(COLOR_RED"reservation not found.\n"COLOR_BLUE);
            return;
        }
        else
        {

            for (i = i; i < count_reservation - 1; i++)
            {
                clien_reservation[i] = clien_reservation[i + 1];
            }
            count_reservation--;
        }
        printf(COLOR_GREEN"successfully done!!\n"COLOR_GREEN);

    }
    else if (choice_2 == 3)
    {
        return;
    }
}

// 3. Afficher les détails d'une réservation : ===============================================
void affichage_res()
{

    if (count_reservation == 0)
    {
        printf(COLOR_YELLOW"reservations empty.\n"COLOR_BLUE);
        return;
    }


    printf(COLOR_GREEN "\n============================== Reservations List ================================\n");
    printf(COLOR_GREEN "\n+--------------------------------------------------------------------------------------+\n");
    printf(COLOR_BLUE"       ToTal : %d", count_reservation);
    printf(COLOR_GREEN "\n+----------+------------+------------+----------------+-------+----------+-------------+\n");
    printf(COLOR_BLUE "| ID       | f-name     | l-name     | phone number   | age   | status   | date        |");
    printf(COLOR_GREEN "\n+----------+------------+------------+----------------+-------+----------+-------------+\n");

    for (int i = 0; i < count_reservation; i++)
    {

        printf(COLOR_BLUE "| %-9s| %-11s| %-11s| %-15s| %-6d| %-9s| %02d-%02d-%04d  |\n",
               // printf(COLOR_BLUE " id : %s \n name : %s \n last name : %s \n phone number : %s \n age : %d\n status : %s\n",
               clien_reservation[i].id_clien,
               clien_reservation[i].first_name,
               clien_reservation[i].last_name,
               clien_reservation[i].phone_number,
               clien_reservation[i].age,
               clien_reservation[i].status,
               clien_reservation[i].date_reservation.day,
               clien_reservation[i].date_reservation.month,
               clien_reservation[i].date_reservation.year);
    }

    printf(COLOR_GREEN "+----------+------------+------------+----------------+-------+----------+-------------+\n"COLOR_BLUE);
}

// 4. Tri des réservations : ===============================================
void sorting_res()
{

    if (count_reservation == 0)
    {
        printf(COLOR_YELLOW"reservations empty.\n"COLOR_BLUE);
        return;
    }


    int choice_menu_4;
    // menu 4 :
    printf(COLOR_GREEN "\n========== sorting menu =========\n" COLOR_BLUE);
    printf("Sorting by : \n");
    printf(" > 1. first name.\n");
    printf(" > 2. status.\n");
    printf(" > 3. Date.\n");
    printf(COLOR_YELLOW " >> 4. return.\n" COLOR_BLUE);
    printf("enter : ");
    getchar();
    scanf("%d", &choice_menu_4);

    dentaires_reservation temp;

    if (choice_menu_4 == 1)
    {
        // name sort :
        printf(COLOR_GREEN"sorting by name : ------------\n"COLOR_BLUE);
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

        // affichage afte tri by name:
        affichage_res();
    }
    else if (choice_menu_4 == 2)
    {
        // staus sort :
        printf(COLOR_GREEN"sorting by status : ------------\n"COLOR_BLUE);
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
        // affichage afte tri by status:
        affichage_res();
    }else if ( choice_menu_4 == 3 )
    {
        
        printf(COLOR_GREEN"sorting by date : ------------\n"COLOR_BLUE);
        for (int i = 0; i < count_reservation - 1; i++)
        {
            
            for (int j = 0; j < count_reservation - 1; j++)
            {
            
                if (clien_reservation[j].date_reservation.year == clien_reservation[j+1].date_reservation.year)
                {

                    if (clien_reservation[j].date_reservation.month == clien_reservation[j+1].date_reservation.month)
                    {
                        if (clien_reservation[j].date_reservation.day > clien_reservation[j+1].date_reservation.day)
                        {
                            temp = clien_reservation[j];
                            clien_reservation[j] = clien_reservation[j + 1];
                            clien_reservation[j + 1] = temp;
                        }
                        
                    }else if (clien_reservation[j].date_reservation.month > clien_reservation[j+1].date_reservation.month)
                    {
                        temp = clien_reservation[j];
                        clien_reservation[j] = clien_reservation[j + 1];
                        clien_reservation[j + 1] = temp;  
                    }
            
                    
                }else if (clien_reservation[j].date_reservation.year > clien_reservation[j+1].date_reservation.year)
                {
                    temp = clien_reservation[j];
                    clien_reservation[j] = clien_reservation[j + 1];
                    clien_reservation[j + 1] = temp;

                }

            }
        
        }

        // affichage afte tri by date:
        affichage_res();

    }
    



    else if (choice_menu_4 == 4)
    {
        return;
    }
}

// 5. Recherche des réservations :===============================================
void search_res()
{

    if (count_reservation == 0)
    {
        printf(COLOR_YELLOW"reservations empty.\n"COLOR_BLUE);
        return;
    }


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
        getchar();
        printf("\nEnter Id : ");
        scanf("%[^\n]", search_by_id);

        for (i = 0; i < count_reservation; i++)
        {
            if (strcmp(search_by_id, clien_reservation[i].id_clien) == 0)
            {
                found = 1;
                break;
            }
        }

        if (found == 1)
        {

            printf(COLOR_GREEN "\n=============================== search by id =================================\n");
            printf(COLOR_GREEN "\n+----------+------------+------------+----------------+-------+----------+-------------+\n");
            printf(COLOR_BLUE "| ID       | f-name     | l-name     | phone number   | age   | status   | date        |");
            printf(COLOR_GREEN "\n+----------+------------+------------+----------------+-------+----------+-------------+\n");

            printf(COLOR_BLUE "| %-9s| %-11s| %-11s| %-15s| %-6d| %-9s| %02d-%02d-%04d  |\n",
                   clien_reservation[i].id_clien,
                   clien_reservation[i].first_name,
                   clien_reservation[i].last_name,
                   clien_reservation[i].phone_number,
                   clien_reservation[i].age,
                   clien_reservation[i].status,
                   clien_reservation[i].date_reservation.day,
                   clien_reservation[i].date_reservation.month,
                   clien_reservation[i].date_reservation.year);

            printf(COLOR_GREEN "+----------+------------+------------+----------------+-------+----------+-------------+\n"COLOR_BLUE);
        }
        else
        {
            printf(COLOR_RED"ID Not Found.\n"COLOR_BLUE);
            return;
        }
    }
    else if (choice_meni_5 == 2)
    {
        // search by  first name:
        char search_by_f_name[max_char];
        int found = 0;
        int i;
        getchar();
        printf("\nEnter Id : ");
        scanf("%[^\n]", search_by_f_name);

        for (i = 0; i < count_reservation; i++)
        {
            if (strcasecmp(search_by_f_name, clien_reservation[i].first_name) == 0)
            {
                found = 1;
                break;
            }
        }

        if (found == 1)
        {

            printf(COLOR_GREEN "\n============================== search by name ================================\n");
            printf(COLOR_GREEN "\n+----------+------------+------------+----------------+-------+----------+-------------+\n");
            printf(COLOR_BLUE "| ID       | f-name     | l-name     | phone number   | age   | status   | date        |");
            printf(COLOR_GREEN "\n+----------+------------+------------+----------------+-------+----------+-------------+\n");

            printf(COLOR_BLUE "| %-9s| %-11s| %-11s| %-15s| %-6d| %-9s| %02d-%02d-%04d  |\n",
                   clien_reservation[i].id_clien,
                   clien_reservation[i].first_name,
                   clien_reservation[i].last_name,
                   clien_reservation[i].phone_number,
                   clien_reservation[i].age,
                   clien_reservation[i].status,
                   clien_reservation[i].date_reservation.day,
                   clien_reservation[i].date_reservation.month,
                   clien_reservation[i].date_reservation.year);

            printf(COLOR_GREEN "+----------+------------+------------+----------------+-------+----------+-------------+\n"COLOR_BLUE);
        }
        else
        {
            printf(COLOR_RED"Name Not Found.\n"COLOR_BLUE);
            return;
        }
    }
    else if (choice_meni_5 == 3)
    {
        // printf(COLOR_RED"Feature not available.\n"COLOR_BLUE);
        
        int search_year;
        int search_month;
        int search_day;
        printf(COLOR_GREEN"\n---------\n"COLOR_BLUE);
        printf("searching by date : \n");
        getchar();
        printf("Enter year : ");
        scanf("%d", &search_year);

        getchar();
        printf("Enter month : ");
        scanf("%d", &search_month);

        getchar();
        printf("Enter day : ");
        scanf("%d", &search_day);
        
        int i;
        int found = 0;
        for ( i = 0; i < count_reservation; i++)
        {
            if ( search_year == clien_reservation[i].date_reservation.year 
            && search_month == clien_reservation[i].date_reservation.month
            && search_day == clien_reservation[i].date_reservation.day 
            )
            {
                found = 1;
                break;
            }
        }

        if ( found == 1)
        {

            printf(COLOR_GREEN "\n============================== search by date ================================\n");
            printf(COLOR_GREEN "\n+----------+------------+------------+----------------+-------+----------+-------------+\n");
            printf(COLOR_BLUE "| ID       | f-name     | l-name     | phone number   | age   | status   | date        |");
            printf(COLOR_GREEN "\n+----------+------------+------------+----------------+-------+----------+-------------+\n");

            printf(COLOR_BLUE "| %-9s| %-11s| %-11s| %-15s| %-6d| %-9s| %02d-%02d-%04d  |\n",
                   clien_reservation[i].id_clien,
                   clien_reservation[i].first_name,
                   clien_reservation[i].last_name,
                   clien_reservation[i].phone_number,
                   clien_reservation[i].age,
                   clien_reservation[i].status,
                   clien_reservation[i].date_reservation.day,
                   clien_reservation[i].date_reservation.month,
                   clien_reservation[i].date_reservation.year);

            printf(COLOR_GREEN "+----------+------------+------------+----------------+-------+----------+-------------+\n"COLOR_BLUE);
            
        }else
        {
            printf(COLOR_RED"Date Not Found.\n"COLOR_BLUE);
            return;
        }



    }
    else if (choice_meni_5 == 4)
    {
        return;
    }
}

// 6. Statistiques :===============================================
void statistiques()
{

    if (count_reservation == 0)
    {
        printf(COLOR_YELLOW"reservations empty.\n"COLOR_BLUE);
        return;
    }

    int choice_menu_6;
    // menu _ 6 :
    printf(COLOR_GREEN "\n======== Statistics =========\n" COLOR_BLUE);
    printf(" > 1. average age of patients who have booked.\n");
    printf(" > 2. Show the number of patients by age group.\n");
    printf(" > 3. Generate statistics to know the total number of reservations by status.\n");
    printf(COLOR_YELLOW " >> 4. return.\n" COLOR_BLUE);
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

        printf(COLOR_GREEN "\n----------------\n" COLOR_BLUE);
        printf("The Average age is : %d", average_age);
    }
    else if (choice_menu_6 == 2)
    {
        // Show the number of patients by age group:
        int age_0_18 = 0;
        int age_19_35 = 0;
        int age_36_ = 0;

        printf(COLOR_GREEN "\n----------------\n" COLOR_BLUE);

        for (int i = 0; i < count_reservation; i++)
        {
            if (clien_reservation[i].age >= 0 && clien_reservation[i].age <= 18)
            {
                age_0_18++;
            }
            else if (clien_reservation[i].age >= 19 && clien_reservation[i].age <= 35)
            {
                age_19_35++;
            }
            else if (clien_reservation[i].age >= 36)
            {
                age_36_++;
            }
        }

        printf("\n number of patients by age group : \n");
        // resault :
        printf("Patients between (00 -- 18) : %d\n", age_0_18);
        printf("Patients between (19 -- 35) : %d\n", age_19_35);
        printf("Patients older than (36)    : %d\n", age_36_);
    }
    else if (choice_menu_6 == 3)
    {

        // Generate statistics to know the total number of reservations by status :

        int number_valid = 0;
        int number_postponed = 0;
        int number_canceled = 0;
        int number_processed = 0;

        for (int i = 0; i < count_reservation; i++)
        {
            if (strcmp(clien_reservation[i].status, "valid") == 0)
            {
                number_valid++;
            }
            else if (strcmp(clien_reservation[i].status, "postponed") == 0)
            {
                number_postponed++;
            }
            else if (strcmp(clien_reservation[i].status, "canceled") == 0)
            {
                number_canceled++;
            }
            else if (strcmp(clien_reservation[i].status, "processed") == 0)
            {
                number_processed++;
            }
        }

        printf(COLOR_GREEN "\n------------------\n" COLOR_BLUE);
        printf("Number of bookings with status : \n");


        printf(COLOR_GREEN"\n========== number of bookings with status ==========\n");
        printf(COLOR_GREEN"\n+-----------+------------+------------+------------+\n");
        printf(COLOR_BLUE"| Valid     | Postponed  | Canceled   | Processed  |");
        printf(COLOR_GREEN"\n+-----------+------------+------------+------------+\n");

        printf(COLOR_BLUE"| %-10d| %-11d| %-11d| %-11d|\n", number_valid, number_postponed, number_canceled, number_processed);
        printf(COLOR_GREEN"+-----------+------------+------------+------------+\n"COLOR_BLUE);

    }
    else if (choice_menu_6 == 4)
    {
        return;
    }
}
