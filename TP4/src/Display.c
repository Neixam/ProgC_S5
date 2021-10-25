/**
 *  Auteur       : Bourennane Amine
 *  Creation     : 10-11-2020
 *  Modification : 21-11-2020
**/
#include "Display.h"
#include <MLV/MLV_all.h>

/**
 *  Display a new window Alchemist with size at 1080x720
**/
void        display_window(void)
{
    MLV_create_window("Alchemist", "PdP", 1080, 720);
}

/**
 *  Close the window
**/
void        close_win(void)
{
    MLV_free_window();
}

/**
 *  Display the score in `score` on t_window `win`
**/
void        display_score(int score, t_window win)
{
    MLV_draw_adapted_text_box((win.width / 3) * 2, win.height / 3,
        "Votre score actuel est %d !", 1, MLV_COLOR_BLACK, MLV_COLOR_WHITE,
        MLV_COLOR_BLACK, MLV_TEXT_LEFT, score); 
}

/**
 *  Return the color at `level`
**/
MLV_Color   assignment_color(int level)
{
    MLV_Color    assignment[11] = { MLV_COLOR_BLACK, MLV_COLOR_GREEN,
                    MLV_COLOR_ORANGE, MLV_COLOR_YELLOW, MLV_COLOR_RED,
                    MLV_COLOR_PINK, MLV_COLOR_PURPLE, MLV_COLOR_BLUE,
                    MLV_COLOR_LIGHTBLUE, MLV_COLOR_GREY, MLV_COLOR_WHITE };
    return (assignment[level]);
}

/**
 *  Display a filled circle with center pos (`x`, `y`) and radius `rad` with the
 *  color `color`
**/
void        display_circle(int x, int y, int rad, MLV_Color color)
{
    MLV_draw_filled_circle(x, y, rad, color);
}

/**
 *  Display the screen for losers, display also the score of the game in `b`
**/
void        display_lose_screen(t_board b)
{
    t_window    win;
    int         w;
    int         h;

    MLV_get_size_of_text("YOU LOSE !!\nyour score is %d, congrate.\nPress esacape for quit", &w, &h, b.score);
    MLV_clear_window(MLV_COLOR_BLACK);
    MLV_get_window_size(&win.width, &win.height);
    MLV_draw_adapted_text_box((win.width - w / 2) / 2, win.height / 2,
        "YOU LOSE !!\nyour score is %d, congrate.\nPress esacape for quit",
        1, MLV_COLOR_BLACK, MLV_COLOR_RED, MLV_COLOR_BLACK, MLV_TEXT_CENTER,
        b.score);
    MLV_update_window();
}

/**
 *  Display all of sort of ball can appear in t_window `win` with radius at 
 *  `rad`
**/
void        display_item(t_window win, int rad)
{
    int     i;
    int     x;
    int     y;

    for (i = 10, x = rad + 20, y = win.height / 10 ; i > 0; i--, y += rad * 2 + 10)
    {
        display_circle(x, y, rad,
            assignment_color(i));
    }
}

/**
 *  Display the new balls in board `b` with a radius `rad` from start (`x`, `y`)
**/
void        display_balls(t_board b, int rad, int x, int y)
{
    display_circle(x + (rad * 2) * b.loc.vertical, y, rad,
        assignment_color(b.loc.left_level));
    display_circle(x + (rad * 2) * (b.loc.vertical + (b.loc.alignment == 0)),
        y - (rad * 2) * b.loc.alignment, rad, assignment_color(b.loc.right_level));
}

/**
 *  Display the board in t_board `b` with a proportionnal size of width and
 *  height in fields of t_window `win` with the width of board `end_x` and the
 *  height of board `end_y`
**/
void        display_board(t_board b, t_window win, int end_x, int end_y)
{
    int         x;
    int         y;

    MLV_draw_rectangle(win.width / 3, win.height / 3 - 5,
        end_x, end_y, MLV_COLOR_WHITE);
    for (y = 0; y < Y; y++)
    {
        for (x = 0; x < X; x++)
            display_circle((win.width / 3) + 1 + ((end_x / X) / 2) + (end_x / X) * x,
                (win.height / 3) + 1 + ((end_x / X) / 2) + (end_x / X) * y,
                (end_x / X) / 2,
                assignment_color(b.box[y][x]));
    }
}

/**
 *  Display the instant game in t_board `b`
**/
void        display_game(t_board b)
{
    t_window    win;
    int         end_x;
    int         end_y;

    MLV_get_window_size(&win.width, &win.height);
    end_x = ((win.width / 3) * 0.9) - 1;
    end_y = ((win.height / 3) * 2) * 0.9;
    MLV_clear_window(MLV_COLOR_BLACK);
    display_score(b.score, win);
    display_item(win, (end_x / X) / 2);
    display_board(b, win, end_x, end_y);
    display_balls(b, (end_x / X) / 2, win.width / 3 + (end_x / X) / 2,
        win.height / 3 - ((end_x / X) + 20));
    MLV_update_window();
}
