#include <iostream>
#include <string>
#include <ncurses.h>
using namespace std;


int credits()
{
    clear();
    system("clear");
    
    string choice[] = {"{Yes}","{No}"};
    int pick;
    int highlight = 0;
     
    Choice:
      
    int height, width, start_y, start_x;
    height = 20;
    width = 30;
    start_y = start_x = 1;

    
    initscr();
    WINDOW * cred = newwin(height, width, start_y, start_x);//CREATING NEW WINDOW FOR NCURSES
    
    mvwprintw(cred, 1, 1, "Credits:");
    mvwprintw(cred, 3, 1, "*KHAN Qais* ");
    mvwprintw(cred, 4, 1, "*LAWAL Paul* ");
    mvwprintw(cred, 5, 1, "*ASAVKINAS Aleksandras* ");
    mvwprintw(cred, 6, 1, "*MAREK Peter* ");
    mvwprintw(cred, 7, 1, "*CHOUDHURY Mohammed Zahed* ");
    mvwprintw(cred, 8, 1, "*PATEL Harshkumar Chandrakant* ");
    mvwprintw(cred, 9, 1, " ");
    mvwprintw(cred, 13, 1, "Would you like to go back?: ");
    box(cred, 0, 0);//CREATING BORDER AROUND THE WINDOW
    refresh();
    wrefresh(cred);
    keypad(cred, true);//ENABLES THE ARROW KEYS TO BE USED
    
    
    
    
     
     
     wrefresh(cred);
    //HIGHLITS THE CHOICE OF THE USER//
    while(true)
    {
        for(int i = 0; i < 2; i++)
        {
                if(i == highlight)
                    wattron(cred, A_REVERSE);
                mvwprintw(cred, i+15, 1, choice[i].c_str());
                wattroff(cred, A_REVERSE);
        }
        pick = wgetch(cred);
        
        //ARROW KEY COMMANDS//
        switch(pick)
        {
            case KEY_UP:
                highlight--;
                if(highlight == -1)
                    highlight = 0;
                break;
            case KEY_DOWN:
                highlight++;
                if(highlight == 2)
                    highlight = 1;
                break;
            default:
                break;      
        }
        if(pick == 10)
            break;
        
    }
    
    if(choice[highlight] == "{Yes}")
    {
        endwin();
        clear();
        system("g++ --std=c++11 NCMenu.cpp -o NCMenu -lncurses -lsqlite3 && ./NCMenu");
    }
    else
    {
        endwin();
        system("clear");
        clear();
        return 0;
    }
   
    
     
  endwin();
}
