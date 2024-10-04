#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <Windows.h>
// #include <time.h>

// programmation modulaire :
#include "functions.h"

dentaires_reservation clien_reservation[max_reser];

int main()
{
    
    char id_r[10][6] = { "RES01", "RES02", "RES03", "RES04", "RES05"};
    char fr_name[10][max_char] = { "isam", "ayman", "said", "kaoutar", "hassan" };
    char ls_name[10][max_char] = { "chajia", "sadouk", "jebran", "amali", "semlali" };
    char ph_nbr[10][max_char] = { "0642932731", "0624769894", "0624587527", "062455223", "0624542521",  };
    int age_r[10] = { 16, 22, 12, 45, 21 };
    int day_r[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int month_r[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    for (int i = 0; i < 5; i++)
    {
        // reservation 1:
        strcpy(clien_reservation[i].id_clien, id_r[i]);
        strcpy(clien_reservation[i].first_name, fr_name[i]);
        strcpy(clien_reservation[i].last_name, ls_name[i]);
        strcpy(clien_reservation[i].phone_number, ph_nbr[i]);
        clien_reservation[i].age = age_r[i];
        strcpy(clien_reservation[i].status, "valid");
        clien_reservation[i].date_reservation.day = day_r[i];
        clien_reservation[i].date_reservation.month = month_r[i];
        clien_reservation[i].date_reservation.year = 2024;
    
    }
    
    


    int choice_main;



    // logo :
    printf("\033[1;34m"
           "            _____________\n"
           "           /             \\\n"
           "          /   Dental      \\\n"
           "         /     Clinic      \\\n"
           "        |___________________|\n"
           "        |  ____       ____  |\n"
           "        | |    |     |    | |\n"
           "        | | () |     | () | |   _______\n"
           "        | |____|     |____| |  /       \\\n"
           "        |                   | |  SMILE  |\n"
           "        |     _________     |  \\_______/\n"
           "        |    |         |    |\n"
           "        |    |_________|    |\n"
           "        |___________________|\n"
           "\033[0m");

    do
    {

        show_menu();

        // show menu :
        printf("Enter your choice : ");
        int input = scanf("%d", &choice_main);

        while (input != 1 || choice_main > 7 || choice_main <= 0)
        {
            printf(COLOR_RED "wrong choice.!!\n" COLOR_BLUE);
            getchar();
            printf("Enter your choice : ");
            input = scanf("%d", &choice_main);
            getchar();
        }

        switch (choice_main)
        {
        case 1:
            for_add();
            wit_for_entr();
            system("cls");
            break;
        case 2:
            modify_delet();
            wit_for_entr();
            system("cls");
            break;
        case 3:
            affichage_res();
            wit_for_entr();
            system("cls");
            break;

        case 4:
            sorting_res();
            wit_for_entr();
            system("cls");
            break;
        case 5:
            search_res();
            wit_for_entr();
            system("cls");
            break;
        case 6:
            statistiques();
            wit_for_entr();
            system("cls");
            break;
        case 7:
            system("cls");
            printf("\nHave a good day !!\n");
            printf(COLOR_YELLOW"Have a good day !!\n");
            printf(COLOR_RED"Have a good day !!\n"COLOR_RESET);

            // logo :
            printf("\033[1;34m"
                "            _____________\n"
                "           /             \\\n"
                "          /   Dental      \\\n"
                "         /     Clinic      \\\n"
                "        |___________________|\n"
                "        |  ____       ____  |\n"
                "        | |    |     |    | |\n"
                "        | | () |     | () | |   _______\n"
                "        | |____|     |____| |  /       \\\n"
                "        |                   | |  BY!!!  |\n"
                "        |     _________     |  \\_______/\n"
                "        |    |         |    |\n"
                "        |    |_________|    |\n"
                "        |___________________|\n"
                "\033[0m");
            exit(1);
            break;
        }

    } while (1);

    return 0;
}
