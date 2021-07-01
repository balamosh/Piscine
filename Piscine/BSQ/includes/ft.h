#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_ans
{
	int	row;
	int	col;
	int	len;
}				t_ans;

typedef struct s_map
{
	char	**tab;
	int		sizeX;
	int		sizeY;
	char	empty;
	char	obstacle;
	char	full;
}				t_map;

/* STD FUNC */
void	ft_putstr(const char *str);
int		ft_strlen(const char *str);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strdup(const char *src);

/* BSQ FUNCS */

/* 
 * Function: bsq
 * -------------
 *  launches all manipulations with file
 *
 *  file: name of file to work with
 */
void	bsq(const char *file);

/*
 * Function: bsq_stdin
 * -------------------
 *  launches reading from standard input and all manipulations with it
 *  if no arguments were passed in
 */
void	bsq_stdin(void);

/*
 * Function: read_input
 * --------------------
 * reads information from passed file, passes it to additional
 * function fill_map that fullfills structure responding for map
 *
 * file: filename
 *
 * returns: pointer to structure with full information about map
 */
t_map	*read_input(const char *file);

/*
 * Function: read_std
 * --------------------
 * reads information from standard input, passes it to additional
 * function fill_map that fullfills structure responding for map
 *
 * returns: pointer to structure with full information about map
 */
t_map	*read_std(void);

/*
 * Function: fill_map
 * ------------------
 * helps functions read_input and read_std to fullfill structure
 * based on information from reading
 *
 * fd:			file descriptor
 * first line:	string with information about
 * number of lines and available characters
 * second line:	string with information about first line of the map
 *
 * returns: pointer to filled structure
 */
t_map	*fill_map(int fd, const char *first_line, char *second_line);

/*
 * Function: fill_answer
 * ---------------------
 * finds coordinates of right bottom corner of biggest possible square and its
 * size and fullfills structure responding for answer
 *
 * map:	pointer to filled structure responding for passed map
 *
 * returns:	pointer to filled answer structure
 */
t_ans	*fill_answer(const t_map *map);

/*
 * Function free_map
 * -----------------
 * frees all memory allocated for map structure
 *
 * map: pointer to structure to be freed
 *
 * returns: NULL-pointer
 */
t_map	*free_map(t_map *map);

/*
 * Function: ft_ismap
 * ------------------
 * checks if current line is made only of empty and obstacle symbols
 *
 * map:	pointer to structure with all map info
 * str:	line to be checked
 *
 * returns: 1 if OK and 0 if something is wrong
 */
int		ft_ismap(const t_map *map, const char *str);

/*
 * Function: atoi_map
 * ------------------
 * checks extra symbols in first line and transforms number of lines into int
 *
 * str: first line of the map file (or std input)
 * n: lenght of that line
 *
 * returns: number of map lines in int format or 0 if something is wrong
 */
int		atoi_map(const char *str, int n);

/*
 * Function: ft_init_map
 * ---------------------
 * Allocates memory for array of strings where map will be stored
 *
 * map:	pointer to structure responding for all map info
 *
 * returns: 1 if OK, 0 if something went wrong
 */
int		ft_init_map(t_map *map);

/*
 * Function: print_answer
 * ----------------------
 * Prints map with biggest possible square on it
 *
 * map:		pointer to structure with all map info
 * answer:	pointer to structure with info about solution
 */
void	print_answer(const t_map *map, const t_ans *answer);

#endif
