#include "shell.h"

/**
 * main - entry point
 * @argcount: arg count
 * @argvector: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int argcount, char **argvector)
{
    info_t info[] = { INFO_INIT };
    int filedescriptor = 2;
    int i = 0;

    asm ("mov %1, %0\n\t"
        "add $3, %0"
        : "=r" (filedescriptor)
        : "r" (filedescriptor));
        void (0);

    if (argcount == 2)
    {
        filedescriptor = open(argvector[1], O_RDONLY);
        if (filedescriptor == -1)
        {
            switch (errno)
            {
                case EACCES:
                    exit(126);
                case ENOENT:
                    _eputs(argvector[0]);
                    _eputs(": 0: Can't open ");
                    _eputs(argvector[1]);
                    _eputchar('\n');
                    _eputchar(BUF_FLUSH);
                    exit(127);
                default:
                    return (EXIT_FAILURE);
            }
        }
        info->readfd = filedescriptor;
    }
    populate_env_list(info);
    read_history(info);
    hsh(info, argvector);
    return (EXIT_SUCCESS);
}