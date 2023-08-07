/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 23:42:39 by marvin            #+#    #+#             */
/*   Updated: 2023/05/05 11:05:00 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "libft.h"

void	free_cont(void *content)
{
	if (ft_strncmp(content, "", 1))
		content = "empty";
	else
		content = "ooo";
	//if (content)
	//	free(content);
}

int	main(void)
{
	printf("\n\n\n\n---------Libc functions---------\n\n");
	//isalnum
	printf("isalnum :\n");
	printf("%d == %d\n", isalnum('a'), ft_isalnum('a'));
	printf("%d == %d\n", isalnum('1'), ft_isalnum('1'));
	printf("\n");

	//isalpha
	printf("isalpha :\n");
	printf("%d == %d\n", isalpha('a'), ft_isalpha('a'));
	printf("%d == %d\n", isalpha('1'), ft_isalpha('1'));
	printf("\n");

	//isascii
	printf("isascii :\n");
	printf("%d == %d\n", isascii(255), ft_isascii(255));
	printf("%d == %d\n", isascii(0), ft_isascii(0));
	printf("%d == %d\n", isascii(123), ft_isascii(123));
	printf("%d == %d\n", isascii(1234), ft_isascii(1234));
	printf("\n");

	//isdigit
	printf("isdigit :\n");
	printf("%d == %d\n", isdigit(127), ft_isdigit(127));
	printf("%d == %d\n", isdigit('1'), ft_isdigit('1'));
	printf("%d == %d\n", isdigit('e'), ft_isdigit('e'));
	printf("%d == %d\n", isdigit(21), ft_isdigit(21));
	printf("\n");

	//isprint
	printf("isprint :\n");
	printf("%d == %d\n", isprint(127), ft_isprint(127));
	printf("%d == %d\n", isprint(360), ft_isprint(360));
	printf("%d == %d\n", isprint('1'), ft_isprint('1'));
	printf("%d == %d\n", isprint('e'), ft_isprint('e'));
	printf("%d == %d\n", isprint(21), ft_isprint(21));
	printf("\n");

	//strlen
	printf("strlen :\n");
	printf("%lu == %lu\n", strlen("hohoho"), ft_strlen("hohoho"));
	printf("%lu == %lu\n", strlen(""), ft_strlen(""));
	//both seg fault printf("%lu\n", strlen(0x0), ft_strlen(0x0));
	printf("\n");

	//memset
	printf("memset :\n");
	int		array1[] = {54, 85, 20, 63, 21};
	int		array2[] = {54, 85, 20, 63, 21};
	size_t	size = sizeof(int) * 5;
	int		length;
	void	*ptr = ft_memset(array1, 0, size);
	void	*ptr2 = memset(array2, 0, size);
	//printf("size = %lu\n", size);
	for( length=0; length<5; length++)
		printf("%d ", array1[length]);
	printf("== ");
	for( length=0; length<5; length++)
		printf("%d ", array2[length]);
	if (ptr && ptr2)
		printf( "\n\n" );

	//bzero
	int array3 [] = {54, 85, 20, 63, 21};
	int array4 [] = {54, 85, 20, 63, 21};
	printf( "bzero :\n" );
	ft_bzero(array3, size);
	bzero(array4, size);
	for( length=0; length<5; length++)
		printf("%d ", array3[length]);
	printf("== ");
	for( length=0; length<5; length++)
		printf("%d ", array4[length]);
	printf("\n\n");

	//memcpy
	printf( "memcpy :\n" );
	int	array[] = { 54, 85, 20, 63, 21 };
	int	*copy;
	int	*copy2;
	copy = (int *) malloc(sizeof(int) * 5);
	copy2 = (int *) malloc(sizeof(int) * 5);
	memcpy(copy, array, size);
	for(length=0; length<5; length++)
		printf("%d ", copy[length]);
	ft_memcpy(copy2, array, size);
	printf("== ");
	for(length=0; length<5; length++)
		printf("%d ", copy2[length]);
	printf( "\n\n" );
	free(copy);
	free(copy2);

	//memmove

	//strlcpy
	printf("strlcpy :\n");
	//char *dst1 = malloc(sizeof(char) * 6);
	char *dst2 = malloc(sizeof(char) * 6);
	//strlcpy(dst1, "ouioui", 6);
	ft_strlcpy(dst2, "ouioui", 6);
	printf("%s == %s\n\n", dst2, dst2);
	free(dst2);

	//strlcat
	printf("\nstrlcat\n");
	char *str3 = "the cake is a lie !\0I'm hidden lol\r\n";
	char buff2[0xF00] = "there is no stars in the sky";
	size_t max = strlen("the cake is a lie !\0I'm hidden lol\r\n") + 4;
	size_t r2 = ft_strlcat(buff2, str3, max);

	printf("res1 = %lu\n", r2);
	char s2[4] = "";
	r2 = ft_strlcat(s2, "thx to ntoniolo for this test !", 4);
	printf("res2 = %lu\n", r2);


	//toupper
	printf("toupper :\n");
	printf("%c == %c\n", toupper('z'), ft_toupper('z'));
	printf("%c == %c\n", toupper('Z'), ft_toupper('Z'));
	printf("%c == %c\n", toupper('('), ft_toupper('('));
	printf("%c == %c\n\n", toupper(0), ft_toupper(0));

	//tolower
	printf("tolower :\n");
	printf("%c == %c\n", tolower('z'), ft_tolower('z'));
	printf("%c == %c\n", tolower('['), ft_tolower('['));
	printf("%c == %c\n", tolower(127), ft_tolower(127));
	printf("%c == %c\n\n", tolower('Z'), ft_tolower('Z'));

	//strchr
	printf("strchr :\n");
	printf("%s == %s\n\n", strchr("yzazo", 'z'), ft_strchr("yzazo", 'z'));

	//strrch
	printf("strrchr :\n");
	printf("%s == %s\n\n", strrchr("yzazo", 'z'), ft_strrchr("yzazo", 'z'));

	//strncmp
	printf("strncmp :\n");
	printf("%d == %d\n\n", strncmp("ouioui", "ouiouj", 5), ft_strncmp("ouioui", "ouiouj", 5));

	//memcmp
	printf("memcmp :\n%d == %d\n", memcmp("hohoha", "hohoha", 6), ft_memcmp("hohoha", "hohoha", 6));
	printf("%d == %d\n", memcmp("hohoha", "hohohi", 6), ft_memcmp("hohoha", "hohohi", 6));
	printf("%d == %d\n", memcmp("hohohi", "hohoha", 6), ft_memcmp("hohohi", "hohoha", 6));

	//strnstr
	//printf("\nstrnstr :\n%s == %s\n", strnstr("je suis cache", "cache", 13), ft_strnstr("je suis cache", "cache", 13));
	//printf("%s == %s\n", strnstr("je suis cache", "cache", 12), ft_strnstr("je suis cache", "cache", 12));

	//atoi
	printf("\natoi:\n");
	printf("%d == %d\n", atoi("+1234567"), ft_atoi("+1234567"));
	printf("%d == %d\n", atoi("12345a67"), ft_atoi("12345a67"));
	printf("%d == %d\n", atoi("a1234567"), ft_atoi("a1234567"));
	printf("%d == %d\n", atoi("\t\t1234567"), ft_atoi("\t\t1234567"));
	printf("%d == %d\n", atoi("-2147483648"), ft_atoi("-2147483648"));
	printf("%d == %d\n", atoi("--+1234567"), ft_atoi("--+1234567"));
	


	printf("\n\n---------Additionnal functions---------\n\n");
	//substr
	char *substr1 = ft_substr("BONJOUR LES HARICOTS !", 8, 14);
	printf("substr:\nres : %s\n", substr1);
	free(substr1);

	//strjoin
	printf("\nstrjoin:\n");
	char	*strjoin = ft_strjoin("hihihi", "hohoho");
	printf("res  = %s\n", strjoin);
	free(strjoin);
	//strtrim
	printf("\nstrtrim:\n");
	char *ret = ft_strtrim("  \t \t \n   \n\n\n\t", " \n\t");

	if (!strcmp(ret, ""))
		printf("strtrim is good \n");
	free(ret);

	//itoa
	printf("\nitoa:\n");
	char *itoa = ft_itoa(2147483647);
	printf("2147483647 = %s\n", itoa);
	free(itoa);
	itoa = ft_itoa(-2147483648);
	printf("-2147483648 = %s\n", itoa);
	free(itoa);
	itoa = ft_itoa(479830);
	printf("479830 = %s\n", itoa);
	free(itoa);
	itoa = ft_itoa(1083648);
	printf("1083648 = %s\n", itoa);
	free(itoa);
	itoa = ft_itoa(-0);
	printf("0 = %s\n", itoa);
	free(itoa);

	//split
	

	//putnbr_fd
	
	printf("\nputnbr:\n");
	ft_putnbr_fd(-10923840, 1);
	printf("\n");


	//calloc
	
	printf("\ncalloc:\n");
	int *callc = 0x0;

	callc = (int *) ft_calloc(3, sizeof(int));
	printf("%d %d %d\n%lu\n", callc[0], callc[1], callc[2], sizeof(int));
	callc[0] = 1;
	callc[1] = 2;
	callc[2] = 3;
	printf("%d %d %d\n", callc[0], callc[1], callc[2]);
	free(callc);

	// strdup
	printf("\nstrdup\n");
	char *str;
	char *tmp = "I malloc so I am.";

	str = ft_strdup(tmp);
	if (!strcmp(str, tmp))
		printf("strdup is yes\n");
	free(str);

	printf("\n\n---------Bonus Part---------\n\n");
	//lstnew, lstadd_front, lstsize, lstdelone
	t_list *front = ft_lstnew("hihi");
	front->next = ft_lstnew("hahaha");
	ft_lstadd_front(&front, ft_lstnew("hohoho"));
	printf("size = %d\n", ft_lstsize(front));
	
	t_list *current_cell = front;
	while (current_cell)
	{
		printf(" %s --", (char *) current_cell->content);
		current_cell = current_cell->next;
	}
	printf("\nfront = %s", (char *) front->content);
	printf("\nlast = %s\n", (char *) ft_lstlast(front)->content);
	ft_lstdelone(front->next->next, free_cont);
	front->next->next = 0;
	current_cell = front;
	while (current_cell)
	{
		printf(" %s --", (char *) current_cell->content);
		current_cell = current_cell->next;
	}
	ft_lstclear(&front, &free_cont);
	printf("\nfirst = %p\n", front);
}
