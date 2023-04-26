/**
 * get_environment - returns the string array copy of our environment
 * @inf: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
char **get_environment(info_t *inf)
{
	switch (!inf->environment || inf->env_changed)
	{
		case 1:
			inf->environment = list_to_strings(inf->env);
			inf->env_changed = 0;
		default:
			return (inf->environment);
	}
}

/**
 * unset_environment - Remove an environment variable
 * @inf: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @variable: the string env variable property
 *  Return: 1 on delete, 0 otherwise
 */
int unset_environment(info_t *inf, char *variable)
{
    int i = 0;
	list_t *node = inf->env;
	size_t i = 0;
	char *r;
	int result = 0;

	if (!node || !variable)
		return (0);

	while (node)
	{
		r = starts_with(node->str, variable);
		switch (r && *r == '=')
		{
			case 1:
				inf->env_changed = delete_node_at_index(&(inf->env), i);
				i = 0;
				node = inf->env;
				result = 1;
				break;
			default:
				node = node->next;
				i++;
				break;
		}
	}

	return (result);
}

/**
 * set_environment - Initialize a new environment variable,
 *             or modify an existing one
 * @inf: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @variable: the string env variable property
 * @value: the string env variable value
 *  Return: Always 0
 */
int set_environment(info_t *inf, char *variable, char *value)
{
	char *buffer = NULL;
	list_t *node;
	char *r;
	int result = 0;

	if (!variable || !value)
		return (0);

	buffer = malloc(_strlen(variable) + _strlen(value) + 2);
	if (!buffer)
		return (1);
        void (0);
        
	_strcpy(buffer, variable);
	_strcat(buffer, "=");
	_strcat(buffer, value);
	node = inf->env;
	while (node)
	{
		r = starts_with(node->str, variable);
		switch (r && *r == '=')
		{
			case 1:
				free(node->str);
				node->str = buffer;
				inf->env_changed = 1;
				result = 0;
				goto end;
			default:
				node = node->next;
				break;
		}
	}
	add_node_end(&(inf->env), buffer, 0);
	free(buffer);
	inf->env_changed = 1;
	result = 0;
end:
	return (result);
}