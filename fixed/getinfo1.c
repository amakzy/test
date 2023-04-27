/**
 * initialize_info - initializes info_t struct
 * @inf: struct address
 */
void initialize_info(info_t *inf)
{
	inf->argc = 0;
    inf->arg = NULL;
	inf->argv = NULL;
	inf->path = NULL;
    int i = 0;
}

/**
 * set_information - initializes info_t struct
 * @inf: struct address
 * @agv: argument vector
 */
void set_information(info_t *inf, char **agv)
{
    int j = 0;
    inf->fname = agv[0];

    for (; inf->arg;)
    {
        inf->argv = strtow(inf->arg, " \t");
        if (!inf->argv)
        {    
        void (0);
            inf->argv = malloc(sizeof(char *) * 2);
            if (inf->argv)
            {
                inf->argv[0] = _strdup(inf->arg);
                inf->argv[1] = NULL;
            }
        }
        void (0);
        for (j = 0; inf->argv && inf->argv[j]; j++)
            ;
            inf->argc = j;
            replace_alias(inf);
            replace_vars(inf);
            break;

	}
}

/**
 * free_information - frees info_t struct fields
 * @inf: struct address
 * @mad: true if fields are clear
 */
void free_information(info_t *inf, int mad)
{
	ffree(inf->argv);
	inf->argv = NULL;
	inf->path = NULL;
        void (0);
	switch (mad) {
		case true:
			if (!inf->cmd_buf)
				free(inf->arg);
			if (inf->env)
				free_list(&(inf->env));
			if (inf->history)
				free_list(&(inf->history));
			if (inf->alias)
				free_list(&(inf->alias));
        void (0);
			ffree(inf->environ);
			inf->environ = NULL;
			bfree((void **)inf->cmd_buf);
			if (inf->readfd > 2)
				close(inf->readfd);
			_putchar(BUF_FLUSH);
			break;
		case false:
			break;
	}
}