/**
 *  Auteur       : Bourennane Amine
 *  Creation     : 04-01-2021
 *  Modification : 11-01-2021
**/
#define _DEFAULT_SOURCE
#define LEN_PATH 64
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dlfcn.h>
#include "Plugins.h"
#include "Stack.h"

static t_tab_plug   plug;

/**
 *  Free plugins tab
**/
void    free_plugins(void)
{
    int     i;

    for (i = 0; i < plug.size; i++)
        if (plug.plugins[i].handle)
            dlclose(plug.plugins[i].handle);
    free(plug.plugins);
}


/**
 *  Close the handle of tab in the index `index` and print the string KO\n
**/
void    recover_error(int index)
{
    printf("KO\n");
    dlclose(plug.plugins[index].handle);
    plug.plugins[index].handle = NULL;
}

/**
 *  Do the correct operation associated to the `symbol` and return 1 if have not
 *  a symbol occurence in table of plugins return 0
**/
int     apply_operation(char symbol)
{
    int     *args;
    int     i;
    int     term;

    for (i = 0; i < plug.size; i++)
    {
        if (plug.plugins[i].symbol == symbol)
        {
            if (stack_size() < plug.plugins[i].arity)
            {
                fprintf(stderr, "stack is empty\n");
                return (1);
            }
            if (!(args = (int*) malloc(sizeof(int) * plug.plugins[i].arity)))
                return (0);
            for (term = plug.plugins[i].arity - 1; term >= 0; term--)
                args[term] = stack_pop();
            stack_push(plug.plugins[i].eval(args));
            free(args);
            return (1);
        }
    }
    return (0);
}

/**
 *  Function which return 1 if the adress of struct dirent `file` have the field
 *  d_name finish by the suffix .so else return 0;
**/
int     filter(const struct dirent *file)
{
    return (strcmp(&file->d_name[strlen(file->d_name) - 3], ".so") == 0);
}

/**
 *  Create the plugin tab in use of in the program and return 1, 0 if allocation
 *  failed
**/
int     create_plugin_tab(void)
{
    struct dirent   **files;
    char            path[LEN_PATH] = "plugins/libs/";
    int             nb;
    int             i;

    printf("Auto-loading of plugins...\n");
    if ((nb = scandir("plugins/libs/", &files, filter, alphasort)) == -1)
        return (0);
    printf("found %d potential plugins :\n", nb);
    if (!(plug.plugins = (t_plug*) malloc(sizeof(t_plug) * nb)))
        return (0);
    for (i = 0; i < nb; i++)
    {
        strcpy(&path[13], files[i]->d_name);
        printf("- %s ... loading ", files[i]->d_name);
        free(files[i]);
        if (!(plug.plugins[i].handle = dlopen(path, RTLD_LAZY)))
        {
            printf("KO\n");
            continue;
        }
        plug.plugins[i].eval = (eval) dlsym(plug.plugins[i].handle, "eval");
        if (dlerror())
        {
            recover_error(i);
            continue;
        }
        plug.plugins[i].arity = ((int (*)()) dlsym(plug.plugins[i].handle, "arity"))();
        if (dlerror())
        {
            recover_error(i);
            continue;
        }
        plug.plugins[i].symbol = ((char (*)()) dlsym(plug.plugins[i].handle, "symbol"))();
        if (dlerror())
        {
            recover_error(i);
            continue;
        }
        printf("OK\n");
    }
    plug.size = i;
    free(files);
    return (1);
}
