/**
 *  Auteur       : Bourennane Amine
 *  Creation     : 04-01-2021
 *  Modification : 11-01-2021
**/
#ifndef __PLUGINS__
#define __PLUGINS__

typedef int (*eval)(int *args);

typedef struct  s_plug
{
    void    *handle;
    eval    eval;
    int     arity;
    char    symbol;
}               t_plug;

typedef struct  s_tab_plug
{
    int     size;
    t_plug  *plugins;
}               t_tab_plug;

/**
 *  Create the plugin tab in use of in the program and return 1, 0 if allocation
 *  failed
**/
int     create_plugin_tab(void);

/**
 *  Free plugins tab
**/
void    free_plugins(void);

/**
 *  Do the correct operation associated to the `symbol` and return 1 if have not
 *  a symbol occurence in table of plugins return 0
**/
int     apply_operation(char symb);

#endif
