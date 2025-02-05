/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves-k <ealves-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:29:19 by ealves-k          #+#    #+#             */
/*   Updated: 2025/01/27 17:29:19 by ealves-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"
#include <fcntl.h>

char	**my_split(char *s, char c)
{
	int		wc;
	int		sz;
	int		wsz;
	char	**arr;

	wc = 0;
	sz = 0;
	wsz = 0;
	while (s && *s && *s++ && ++sz)
		wc += (*(s - 1) != c && (*s == c || !*s));
	arr = malloc((wc + 1) * sizeof(char *));
	while (wc-- && arr)
	{
		while (sz-- && (*--s == c || (*s != c && ++wsz && *(s - 1) != c)))
			arr[wc + !*(s + 1)] = NULL;
		arr[wc] = malloc((++wsz) * sizeof(char));
		if (!arr[wc])
			while (arr[++wc])
				free(arr[wc]);
		if (!arr[wc])
			return (free(arr), NULL);
		while (wsz && wsz--)
			arr[wc][wsz] = (!(s[wsz] == c) * s[wsz]);
	}
	return (arr);
}
char **my_split_no_norminete_edition(char *s, char c)
{
	int wc = 0, sz = 0, wsz = 0;
	while (s && *s && *s++ && ++sz)
		wc += (*(s - 1) != c && (*s == c || !*s));
	char **arr = malloc((wc + 1) * sizeof(char *));
	arr[wc] = NULL;
	while (wc--)
	{
		while (sz-- && (*--s == c || (*s != c && ++wsz && *(s - 1) != c)));
		arr[wc] = malloc((wsz + 1) * sizeof(char));
		while (wsz && wsz--)
			arr[wc][wsz] = (!(s[wsz] == c) * s[wsz]);
	}
	return(arr);
}

char **my_split_no_norminete_malloc_protection_edition(char *s, char c)
{
	int wc = 0, sz = 0, wsz = 0;
	while (s && *s && *s++ && ++sz)
		wc += (*(s - 1) != c && (*s == c || !*s));
	char **arr = malloc((wc + 1) * sizeof(char *));
	arr[wc] = NULL;
	while (wc-- && arr)
	{
		while (sz-- && (*--s == c || (*s != c && ++wsz && *(s - 1) != c)));
		arr[wc] = malloc((wsz + 1) * sizeof(char));
		if (!arr[wc])
		{
			while (arr[++wc])
				free(arr[wc]);
			return (free(arr), NULL);
		}
		while (wsz && wsz--)
			arr[wc][wsz] = (!(s[wsz] == c) * s[wsz]);
	}
	return (arr);
}

char **my_split_war_crimes_edition(char *s, char c)
{
	int wc = 0, sz = 0, wsz = 0;
	while (s && *s && *s++ && ++sz)
		wc += (*(s - 1) != c && (*s == c || !*s));
	char **arr = malloc((wc + 1) * sizeof(char *));
	arr[wc] = NULL;
	while (wc--)
	{
		while (sz-- && (*--s == c || (*s != c && ++wsz && *(s - 1) != c)));
		s[wsz] = '\0';
		arr[wc + (wsz -= wsz)] = s;
	}
	return(arr);
}
char	**my_split_complete_edition(char *s, char c)
{
	int		wc;
	int		sz;
	int		wsz;
	char	**arr;

	wc = 0;
	sz = 0;
	wsz = 0;
	while (s && *s && *s++ && ++sz)
		wc += (*(s - 1) != c && (*s == c || !*s));
	arr = malloc((wc + 1) * sizeof(char *));
        if (arr)
            arr[wc] = NULL;
	while (wc && wc-- && arr)
	{
		while (sz-- && (*--s == c || (*s != c && ++wsz && *(s - 1) != c)))
			sz += 0;
		arr[wc] = malloc((++wsz) * sizeof(char));
		if (!arr[wc])
			while (arr[++wc])
				free(arr[wc]);
		if (!arr[wc])
			return (free(arr), NULL);
		while (arr[wc] && wsz && wsz--)
			arr[wc][wsz] = (!(s[wsz] == c) * s[wsz]);
	}
	return (arr);
}

char	**my_split_complete_edition2(char const *s, char c)
{
	int		wc;
	int		sz;
	int		wsz;
	char	**arr;

	wc = 0;
	sz = 0;
	wsz = 0;
	while (s && *s && *s++ && ++sz)
		wc += (*(s - 1) != c && (*s == c || !*s));
	arr = malloc((wc + 1) * sizeof(char *));
	while (wc && wc-- && arr)
	{
		while (sz-- && (*--s == c || (*s != c && ++wsz && *(s - 1) != c)))
			arr[wc + (!(s + 1) && *s) + (!(s + 2) && *(s + 1)) * 2] = NULL;
		arr[wc] = malloc((++wsz) * sizeof(char));
		if (!arr[wc])
			while (arr[++wc])
				free(arr[wc]);
		if (!arr[wc])
			return (free(arr), NULL);
		while (wsz && wsz--)
			arr[wc][wsz] = (!(s[wsz] == c) * s[wsz]);
	}
	return (arr);
}
char	**my_split_complete_edition3(char *s, char c)
{
	int		wc;
	int		sz;
	int		wsz;
	char	**arr;

	wc = 0;
	sz = 0;
	wsz = 0;
	while (s && *s && *s++ && ++sz)
		wc += (*(s - 1) != c && (*s == c || !*s));
	arr = malloc((++wc) * sizeof(char *));
	while (wc && wc-- && arr)
	{
		while (sz-- && *s-- && (*s == c || (*s != c && ++wsz && *(s - 1) != c)))
			arr[wc] = NULL;
        if (*(s + 1) || (*(s + 2) && *s != c))
		    arr[wc] = malloc((++wsz) * sizeof(char));
        //printf("*%d, %d, %d", wsz, wc, sz);
//		if (!arr[wc] && ((*(s + 1) && *s) || !*s))
//			while (arr[++wc])
//				free(arr[wc]);
//		if (!arr[wc] && ((*(s + 1) && *s) || !*s))
//			return (free(arr), NULL);
        //printf("*%s %d\n", arr[wc], wsz);
		while (wsz && wsz--)
			arr[wc][wsz] = (!(s[wsz] == c) * s[wsz]);
	}
	return (arr);
}

int main()
{
    char **arr = my_split_complete_edition2("\0aa\0bbb", '\0');
    while(*arr)
    {
        printf("%s\n", *arr);
        arr++;
    }
    printf("%s\n", *arr);
}

// int main()
// {
//     char s[] = "b a n a n a    com   nescal    f";
//     char **arr = my_split_war_crimes_edition(s, ' ');
//     while(*arr)
//     {
//         printf("%s\n", *arr);
//         arr++;
//     }
//     printf("%s\n", *arr);
// }