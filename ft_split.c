/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:18:19 by samunyan          #+#    #+#             */
/*   Updated: 2022/04/04 17:18:28 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_tokens(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	if (!s[i])
		return (0);
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
			count++;
		while (s[i] != c && s[i + 1] != '\0')
			i++;
		i++;
	}
	return (count);
}

static size_t	get_token_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*ft_strndup(char const *s, size_t len)
{
	char	*res;
	size_t	i;

	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i] && i < len)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static void	*free_arr_until(char **arr, size_t i)
{
	while (i)
	{
		free(arr[i]);
		i--;
	}
	free(arr[i]);
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	n_tokens;
	size_t	i;
	size_t	len;

	n_tokens = count_tokens(s, c);
	arr = malloc(sizeof(arr) * (n_tokens + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < n_tokens)
	{
		while (*s && *s == c)
			s++;
		len = get_token_len(s, c);
		arr[i] = ft_strndup(s, len);
		if (!arr[i])
			return (free_arr_until(arr, i));
		s += len;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
