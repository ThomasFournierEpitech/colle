/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

void	error_handling(int ac, char **av)
{
	FILE *stream = NULL;
	if (ac != 2) {
		printf("Not enought argument\n");
		exit(84);
	}
	stream = fopen(av[1], "r");
	if (stream == NULL) {
		fclose(stream);
		printf("Invalide fill\n");
		exit(84);
	}
	fclose(stream);
	if (ac > 3) {
		printf("Too much argument\n");
		exit(84);
	}
}

int	main(int ac, char **av)
{
	char *str = NULL;
	char *path = NULL;
	int life = 10;

	path =  av[1];
	if (ac == 3)
		life = atoi(av[2]);
	srandom(random() % time(NULL));
	str = get_info(path);
	//hangman(str, life);
	free(str);
	return (0);
}
