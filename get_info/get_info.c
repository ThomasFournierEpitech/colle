/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

int	get_nb_words(FILE *stream)
{
	int nb = 0;
	ssize_t size;
	size_t n = 0;
	char *buff = NULL;

	size = getline(&buff, &n, stream);
	while (size != -1) {
		nb++;
		size = getline(&buff, &n, stream);
	}
	free(buff);
	return (nb);
}

char	**get_words(FILE *stream, int nb)
{
	char **tab = malloc(sizeof(*tab) * (nb + 1));
	int i = 0;
	ssize_t size;
	size_t n = 0;
	char *buff = NULL;

	size = getline(&buff, &n, stream);
	while (i < nb) {
		buff[size - 1] = '\0';
		tab[i] = malloc(sizeof(*tab) * size);
		tab[i] = strcpy(tab[i], buff);
		i++;
		size = getline(&buff, &n, stream);
	}
	tab[nb] = NULL;
	free(buff);
	return (tab);
}

void	free_tab(char ***tab)
{
	int i = 0;
	while ((*tab)[i] != NULL) {
		free((*tab)[i]);
		i++;
	}
	free(*tab);
}

char	*get_info(char *path)
{
	char *str = NULL;
	char **tab = NULL;
	FILE *stream = fopen(path, "r");
	int words = get_nb_words(stream);

	if (words == 0){
		fclose(stream);
		return (strdup(""));
	}
	fclose(stream);
	stream =fopen(path, "r");
	tab = get_words(stream, words);
	printf("words: %d\n", words);
	str = strdup(tab[rand() % words]);
	fclose(stream);
	printf("str: %s\n", str);
	free_tab(&tab);

	return (str);
}
