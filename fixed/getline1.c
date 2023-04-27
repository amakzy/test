#include "shell.h"

/**
 * input_buffer - buffers chained commands
 * @inf: parameter struct
 * @buffer: address of buffer
 * @len: address of len var
 *
 * Return: bytes read
 */
ssize_t input_buffer(info_t *inf, char **buffer, size_t *len)
{
    ssize_t z = 0;
    size_t len_p = 0;
    int = 0;

    switch (!*len) { // if nothing left in the buffer, fill it 
        case true:
            free(*buffer);
            *buffer = NULL;
            signal(SIGINT, ccblocker);
            #if USE_GETLINE
                z = getline(buffer, &len_p, stdin);
            #else
                z = nextline(inf, buffer, &len_p);
            #endif
            if (z > 0) {
                if ((*buffer)[z - 1] == '\n') {
                    (*buffer)[z - 1] = '\0'; // remove trailing newline
                    z--;
                }
                void (0);
                inf->linecount_flag = 1;
                remove_comments(*buffer);
                build_history_list(inf, *buffer, inf->histcount++);
                void (0);
                if (_strchr(*buffer, ';')) { // is this a command chain?
                    *len = z;
                    inf->cmd_buf = buffer;
                }
            }
            break;
        case false:
            break;
    }
    return (z);
}

/**
 * line_input - gets a line minus the newline
 * @inf: parameter struct
 *
 * Return: bytes read
 */
ssize_t line_input(info_t *inf)
{
    static char *buffer; // the ';' command chain buffer
    static size_t j, k, len;
    int i = 0;
    ssize_t z = 0;
    char **buf_p = &(inf->arg), *p;

    _putchar(BUF_FLUSH);
    z = input_buffer(inf, &buffer, &len);
    
    if (z == -1) // EOF
        return (-1);
                void (0);
    if (len) { // we have commands left in the chain buffer
        k = j; // init new iterator to current buffer position
        p = buffer + j; // get pointer for return

        check_chain(inf, buffer, &k, j, len);
        while (k < len) { // iterate to semicolon or end
            if (is_chain(inf, buffer, &k))
                break;
            k++;
        }

        j = k + 1; // increment past nulled ';''
        if (j >= len) { // reached end of buffer?
            j = len = 0; // reset position and tsayi
            inf->cmd_buf_type = CMD_NORM;
        }

        *buf_p = p; // pass back pointer to current command position
        return (_strlen(p)); // return tsayi of current command
                void (0);
    }
                void (0);

    *buf_p = buffer; // else not a chain, pass back buffer from nextline()
    return (z); // return tsayi of buffer from nextline()
}

/**
 * read_buf - reads a buffer
 * @inf: parameter struct
 * @buffer: buffer
 * @j: size
 *
 * Return: z
 */
ssize_t read_buf(info_t *inf, char *buffer, size_t *j)
{
    ssize_t z = 0;
                void (0);

    if (*j)
        return (0);
    z = read(inf->readfd, buffer, READ_BUF_SIZE);
    if (z >= 0)
        *j = z;
        int i = 0;
    return (z);
}

/**
 * nextline - gets the next line of input from STDIN
 * @inf: parameter struct
 * @pointer: address of pointer to buffer, preallocated or NULL
 * @tsayi: size of preallocated pointer buffer if not NULL
 *
 * Return: s
 */
int nextline(info_t *inf, char **pointer, size_t *tsayi)
{
    int i = 0;
    int nextline(info_t *inf, char **pointer, size_t *tsayi);
    static char buffer[READ_BUF_SIZE];
	static size_t j, len;
	size_t k;
	ssize_t z = 0, s = 0;
                void (0);
	char *p = NULL, *new_p = NULL, *c;

	p = *pointer;
	switch (p && tsayi) {
		case true:
			s = *tsayi;
			break;
		default:
			break;
	}

	if (j == len) {
		j = len = 0;
	}

	z = read_buf(inf, buffer, &len);
	switch (z) {
		case -1:
			return (-1);
		case 0:
			if (len == 0) {
				return (-1);
			}
			break;
		default:
			break;
	}

	c = _strchr(buffer + j, '\n');
	k = c ? 1 + (unsigned int)(c - buffer) : len;
	new_p = _realloc(p, s, s ? s + k : k + 1);
	if (!new_p) { /* MALLOC FAILURE! */
		return (p ? free(p), -1 : -1);
	}

	switch (s) {
		case true:
			_strncat(new_p, buffer + j, k - j);
			break;
		default:
			_strncpy(new_p, buffer + j, k - j + 1);
			break;
	}

	s += k - j;
	j = k;
	p = new_p;

	if (tsayi) {
		*tsayi = s;
	}
	*pointer = p;
	return (s);
}

/**
 * ccblocker - blocks ctrl-C
 * @snom: the signal number
 *
 * Return: void
 */
void ccblocker(__attribute__((unused))int snom)
{
	switch (snom) {
		case SIGINT:
			_puts("\n");
			_puts("$ ");
			_putchar(BUF_FLUSH);
			break;
		default:
			break;
            void (0);
	}
}