#include <iostream>
#include <string>
#include <ncurses.h>
using namespace std;


int finish()
{
    clear();
    system("clear");
    
    string choice[] = {"{Yes}","{No}"};
    int pick;
    int highlight = 0;
     
    Choice:
      
    int height, width, start_y, start_x;
    height = 25;
    width = 50;
    start_y = start_x = 1;

    
    initscr();
    WINDOW * cred = newwin(height, width, start_y, start_x);
    
    mvwprintw(cred, 2, 9, "Thanks For Playing The Game!!!!");
    mvwprintw(cred, 4, 10, "");
    mvwprintw(cred, 5, 20, "Credits:");
    mvwprintw(cred, 8, 18, "*KHAN Qais* ");
    mvwprintw(cred, 9, 18, "*LAWAL Paul* ");
    mvwprintw(cred, 10, 12, "*ASAVKINAS Aleksandras* ");
    mvwprintw(cred, 11, 18, "*MAREK Peter* ");
    mvwprintw(cred, 12, 11, "*CHOUDHURY Mohammed Zahed* ");
    mvwprintw(cred, 13, 10, "*PATEL Harshkumar Chandrakant* ");
    mvwprintw(cred, 14, 1, " ");
    mvwprintw(cred, 17, 1, "Would you like to go back?: ");
    box(cred, 0, 0);
    refresh();
    wrefresh(cred);
    keypad(cred, true);
    
    
    
    
     
     
     wrefresh(cred);
    
    while(true)
    {
        for(int i = 0; i < 2; i++)
        {
                if(i == highlight)
                    wattron(cred, A_REVERSE);
                mvwprintw(cred, i+19, 1, choice[i].c_str());
                wattroff(cred, A_REVERSE);
        }
        pick = wgetch(cred);
        
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
