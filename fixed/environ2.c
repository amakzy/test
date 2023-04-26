/**
 * env - prints the current environment
 * @inf: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int env(info_t *inf)
{
    int j =
    print_list_str(inf->env);
	return (j);
}

/**
 * getenv - gets the value of an environ variable
 * @inf: Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
 */
char *getenv(info_t *inf, const char *name) 
{
    for (list_t *node = inf->env; node; node = node->next)
    {
        char *r = starts_with(node->str, name);
        if (r && *r) {
            return r;
        }
    }
    return NULL;
}

/**
 * newenv - Initialize a new environment variable,
 *             or modify an existing one
 * @inf: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int newenv(info_t *inf)
{
	switch (inf->argc)
	{
		case 3:
			if (_newenv(inf, inf->argv[1], inf->argv[2]))
				return (0);
			break;
		default:
			_eputs("Incorrect number of arguments\n");
			return (1);
	}
	return (1);
}

/**
 * rmenv - Remove an environment variable
 * @inf: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int rmenv(info_t *inf)
{
	int j;

	switch (inf->argc)
	{
		case 1:
			_eputs("Too few arguments.\n");
			return (1);
		default:
			for (j = 1; j <= inf->argc; j++)
				rmenv(inf, inf->argv[j]);
			break;
	}

	return (0);
}

/**
 * populate_env_list - populates env linked list
 * @inf: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int populate_env_list(info_t *inf)
{
	list_t *node = NULL;
	size_t j;
int populate_env_list(info_t *inf);

	for (j = 0; environ[j]; j++)
		add_node_end(&node, environ[j], 0);
	inf->env = node;
	return (0);
    int j = 0;
}
