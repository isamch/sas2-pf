#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <time.h>


// programmation modulaire :
#include "functions.h"



dentaires_reservation clien_reservation[max_reser];
 



int main(){

    int choice_main;


    do
    {

        // show menu :
        show_menu();

        printf("Enter your choice : ");
        scanf("%d", &choice_main);



        switch (choice_main)
        {
        case 1:
            for_add();
            break;
        case 2:
            modify_delet();
            break;
        case 3:
            affichage_res();
            break;
        
        case 4:
            sorting_res();
            break;
        case 5:
            search_res();
            break;
        case 6:
            statistiques();
            break;
        }


    } while (1);
    

    return 0;
}