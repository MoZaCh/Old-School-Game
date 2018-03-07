#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ncurses.h>
#include <curses.h>
#include <panel.h>
#include <functional>
#include <string>
#include "Credits.cpp"
#include "Paths.cpp"


using namespace std;

int main(int argc, char ** argv)
{ 
    string choice[] = {"       Start New Game       ", "         Resume Game        ", "           Credits          ", "            Exit           ", };
    int pick;
    int highlight;
    
    cbreak();//command to stop the program proccess with CTRL+C
    clear();//clears the window

    /*COORDINATES OF THE FIRST MENU WINDOW*/
    int height, width, start_y, start_x;
    height = 10;
    width = 30;
    start_y = start_x = 1;
    
    
    initscr();//ncurses starts
    option:
    WINDOW * menu_win = newwin(height, width, start_y, start_x);//creating a new window
    refresh();//refreshes the window in a console so that changes would be seen

    
    
    box(menu_win, 0, 0);//creates a border around the window that was created
    refresh();
    wrefresh(menu_win);//refreshes only the menu window
    keypad(menu_win, true);//function lets us to use the arrow keys
    
    
    int y, x, yBeg, xBeg, yMax, xMax;
    getyx(menu_win, y, x);
    getbegyx(menu_win, yBeg, xBeg);//getting the beginning of a window
    getmaxyx(menu_win, yMax, xMax);//getting the size of a window
    
    
    mvwprintw(menu_win, 1, xMax/3, "D5 RPG Game");
    mvwprintw(menu_win, 2, 1, "----------------------------");
    
    
    
    title:
    
   
    /*CREATING A LOOP WHICH HIGLITS OUR CHOSEN CHOICE*/
    while(true)
    {
        for(int i = 0; i < 4; i++)
        {
            if(i == highlight)
                wattron(menu_win, A_REVERSE);
            mvwprintw(menu_win, i+3, 1, choice[i].c_str());
            wattroff(menu_win, A_REVERSE);
        }
       pick = wgetch(menu_win);
        
        switch(pick)
        {
            case KEY_UP:
                highlight--;
                if(highlight == -1)
                    highlight = 0;
                break;
            case KEY_DOWN:
                highlight++;
                if(highlight == 4)
                    highlight = 3;
                break;
        }
        if(pick == 10)
            break;
        
    }
    
    /*FUNCTIONALITY OF THE CHOICES*/
    if(choice[highlight] == "       Start New Game       ")
    {
            endwin(); //Leaves ncurse, goes back to normal format
            system("clear");
            choice[highlight] = '\0'; 
            path();
    }
    else if(choice[highlight] == "         Resume Game        ")
    {
        goto title;
    }
    else if(choice[highlight] == "           Credits          ")
    {

        credits();
    }
    else if(choice[highlight] == "            Exit           ")
    {
        endwin();
        clear();
        system("clear");
        return 0;
    }
      
    endwin();
  return 0;
}
