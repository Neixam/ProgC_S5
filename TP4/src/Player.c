/**
 *  Auteur       : Bourennane Amine
 *  Creation     : 21-11-2020
 *  Modification : 21-11-2020
**/
#include <MLV/MLV_all.h>

/**
 *  Return 1 if the button in `kb` is valid in the program else return 0
**/
int     is_button_valid(MLV_Keyboard_button kb)
{
    return (kb == MLV_KEYBOARD_UP || kb == MLV_KEYBOARD_DOWN ||
        kb == MLV_KEYBOARD_RIGHT || kb == MLV_KEYBOARD_LEFT ||
        kb == MLV_KEYBOARD_ESCAPE);
}

/**
 *  Return a value between 0 and 4 include reliant of key press user
**/
int     wait_user(void)
{
    MLV_Keyboard_button press;

    do
    {
        MLV_wait_keyboard(&press, NULL, NULL);
    }while (!is_button_valid(press));
    switch (press)
    {
        case MLV_KEYBOARD_UP : return (0);
        case MLV_KEYBOARD_DOWN : return (1);
        case MLV_KEYBOARD_RIGHT : return (2);
        case MLV_KEYBOARD_LEFT : return (3);
        default : return (4);
    }
}
