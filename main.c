#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <Windows.h>
// #include <time.h>


// programmation modulaire :
#include "functions.h"



dentaires_reservation clien_reservation[max_reser];
 



int main(){

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
           "        |     _________      |  \\_______/\n"
           "        |    |         |     |\n"
           "        |    |_________|     |\n"
           "        |____________________|\n"
           "\033[0m");

    do
    {

           

        show_menu();


        // show menu :
        printf("Enter your choice : ");
        int input = scanf("%d", &choice_main);


        while (input != 1 || choice_main > 7 || choice_main <= 0)
        {
            printf(COLOR_RED"wrong choice.!!\n"COLOR_BLUE);
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
            printf("Have a good day !!\n");
            exit(1);
            break;
        }


    } while (1);
    

    return 0;
}