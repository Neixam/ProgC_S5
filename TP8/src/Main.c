/* Auteur       : Bourennane Amine
*  Creation     : 04-01-2021
*  Modification : 04-01-2021   */
#include "Plugins.h"
#include "Parsing.h"

int     main(int ac, char **av)
{
    if (!create_plugin_tab())
        return (1);
    dc(av[0]);
    free_plugins();
    return (0);
}
