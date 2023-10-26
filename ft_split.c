/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleperei <aleperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:09:08 by aleperei          #+#    #+#             */
/*   Updated: 2023/05/03 13:09:56 by aleperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_ng(char const *s, char c)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			size++;
		}
		i++;
	}
	return (size);
}

static	char	*ft_sstr(char const *s, char c)
{
	char	*new;
	int		i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	new = malloc(sizeof(char) * (i + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

static char	**free_split(char **new, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(new[i]);
		i++;
	}
	free(new);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		i;
	int		j;

	new = malloc(sizeof(char *) * (ft_ng(s, c) + 1));
	if (!s || !new)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			new[j] = ft_sstr(&s[i], c);
			if (!new[j])
				return (free_split(new, j));
			j++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
		else
			i++;
	}
	new[j] = NULL;
	return (new);
}

/*nt main()
{
    char    *str= "                 ndfkjdj";

    printf("Split string: %s\n", *ft_split(str, ' '));
    return (0);
}*/
