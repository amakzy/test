#include "shell.h"

/**
 * display_history - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @inf: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
int display_history(info_t *inf)
{
    print_list(inf->history);
    return (0);
}

/**
 * unset_alias - unsets an alias by removing it from the list
 * @inf: parameter structure
 * @str: string alias
 *
 * Return: 0 else 1
 */
int unset_alias(info_t *inf, char *str)
{
    char *r;
    int ret;
    r = _strchr(str, '=');
    if (!r)
        return (1);
    *r = 0;
    ret = remove_value_from_list(&(inf->alias),
        get_node_index(inf->alias, node_starts_with(inf->alias, str, -1)));
    *r = '=';
    return (ret);
}

/**
 * set_alias - sets an alias to a string
 * @inf: parameter struct
 * @str: the string alias
 *
 * Return: 0 on success, 1 on error
 */
int set_alias(info_t *inf, char *str) 
{
    char *r = _strchr(str, '=');
    if (!r) {
        return 1;
    }
    int i = 0;
    r++;
    if (!*r) {
        return unset_alias(inf, str);
    }
    unset_alias(inf, str);
    return add_node_end(&(inf->alias), str, 0) == NULL;
}

/**
 * print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: 0 on success, 1 on error
 */
int print_alias(list_t *node) 
{
    if (!node) {
        return 1;
    }
    char *r = _strchr(node->str, '=');
    for (char *alias = node->str; alias <= r; alias++) {
        _putchar(*alias);
    }
    _putchar('\'');
    _puts(r + 1);
    _puts("'\n");
    return 0;
}

/**
 * alias_command - handles the alias command, mimicking the alias builtin (man alias)
 * @inf: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
int alias_command(info_t *inf)
{
    int i = 0;
    char *r = NULL;
    list_t *node = NULL;
    char *argv = inf->argv[1];

    switch (inf->argc)
    {
    case 1:
        node = inf->alias;
        while (node)
        {
            print_alias(node);
            node = node->next;
        }
        return (0);
    default:
        for (i = 1; inf->argv[i]; i++)
        {
            argv = inf->argv[i];
            r = _strchr(argv, '=');
            if (r)
            {
                set_alias(inf, argv);
            }
            else
            {
                node = node_starts_with(inf->alias, argv, '=');
                print_alias(node);
            }
        }
        return (0);
    }
}
