/* ************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheirm <lscheirm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 21:53:55 by lscheirm          #+#    #+#             */
/*   Updated: 2026/03/11 01:16:00 by lscheirm         ###   ########.fr       */
/*                                                                            */
/* ************************** */

#include "libft.h"
#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define CYAN "\033[0;36m"
#define RESET "\033[0m"
#define BOLD "\033[1m"

static int	g_ok = 0;
static int	g_ko = 0;

static void	check(const char *label, int result)
{
	if (result)
	{
		printf("  " GREEN "[OK]" RESET " %s\n", label);
		g_ok++;
	}
	else
	{
		printf("  " RED "[KO]" RESET " %s\n", label);
		g_ko++;
	}
}

static void	section(const char *name)
{
	printf(BOLD CYAN "\n╔══════════════════════════════╗\n" RESET);
	printf(BOLD CYAN "║  %-28s║\n" RESET, name);
	printf(BOLD CYAN "╚══════════════════════════════╝\n" RESET);
}

static int	sign(int n)
{
	if (n < 0)
		return (-1);
	if (n > 0)
		return (1);
	return (0);
}

int	main(void)
{
	char	dst_ft[200];
	char	dst_real[200];
	char	overlap_ft[200];
	char	overlap_real[200];
	char	*ptr;
	char	*ptr2;
	int		*iptr;
	size_t	ret_ft;
	size_t	ret_real;
	int		i;
	int		ko_in_loop;
		const char *big = "hello world";
		const char *big2 = "hello";
		const char *big3 = "";
			const char *multi = "aaabaaa";

	memset(dst_ft, 0, sizeof(dst_ft));
	memset(dst_real, 0, sizeof(dst_real));
	memset(overlap_ft, 0, sizeof(overlap_ft));
	memset(overlap_real, 0, sizeof(overlap_real));
	/* ================================================================ */
	section("ft_isalpha");
	/* ================================================================ */
	ko_in_loop = 0;
	i = 0;
	while (i < 128)
	{
		if (!!ft_isalpha(i) != !!isalpha(i))
		{
			printf("  " RED "[KO]" RESET " isalpha(%d = '%c')\n", i, (i >= 32
					&& i < 127) ? i : '?');
			ko_in_loop = 1;
			g_ko++;
		}
		i++;
	}
	if (!ko_in_loop)
	{
		printf("  " GREEN "[OK]" RESET " isalpha : tous les ASCII 0-127\n");
		g_ok++;
	}
	/* ================================================================ */
	section("ft_isdigit");
	/* ================================================================ */
	ko_in_loop = 0;
	i = 0;
	while (i < 128)
	{
		if (!!ft_isdigit(i) != !!isdigit(i))
		{
			printf("  " RED "[KO]" RESET " isdigit(%d = '%c')\n", i, (i >= 32
					&& i < 127) ? i : '?');
			ko_in_loop = 1;
			g_ko++;
		}
		i++;
	}
	if (!ko_in_loop)
	{
		printf("  " GREEN "[OK]" RESET " isdigit : tous les ASCII 0-127\n");
		g_ok++;
	}
	/* ================================================================ */
	section("ft_isalnum");
	/* ================================================================ */
	ko_in_loop = 0;
	i = 0;
	while (i < 128)
	{
		if (!!ft_isalnum(i) != !!isalnum(i))
		{
			printf("  " RED "[KO]" RESET " isalnum(%d = '%c')\n", i, (i >= 32
					&& i < 127) ? i : '?');
			ko_in_loop = 1;
			g_ko++;
		}
		i++;
	}
	if (!ko_in_loop)
	{
		printf("  " GREEN "[OK]" RESET " isalnum : tous les ASCII 0-127\n");
		g_ok++;
	}
	/* ================================================================ */
	section("ft_isascii");
	/* ================================================================ */
	ko_in_loop = 0;
	i = -10;
	while (i < 300)
	{
		if (!!ft_isascii(i) != !!isascii(i))
		{
			printf("  " RED "[KO]" RESET " isascii(%d)\n", i);
			ko_in_loop = 1;
			g_ko++;
		}
		i++;
	}
	if (!ko_in_loop)
	{
		printf("  " GREEN "[OK]" RESET " isascii : valeurs -10 a 300\n");
		g_ok++;
	}
	/* ================================================================ */
	section("ft_isprint");
	/* ================================================================ */
	ko_in_loop = 0;
	i = 0;
	while (i < 128)
	{
		if (!!ft_isprint(i) != !!isprint(i))
		{
			printf("  " RED "[KO]" RESET " isprint(%d)\n", i);
			ko_in_loop = 1;
			g_ko++;
		}
		i++;
	}
	if (!ko_in_loop)
	{
		printf("  " GREEN "[OK]" RESET " isprint : tous les ASCII 0-127\n");
		g_ok++;
	}
	/* ================================================================ */
	section("ft_toupper");
	/* ================================================================ */
	ko_in_loop = 0;
	i = 0;
	while (i < 128)
	{
		if (ft_toupper(i) != toupper(i))
		{
			printf("  " RED "[KO]" RESET " toupper(%d = '%c')\n", i, (i >= 32
					&& i < 127) ? i : '?');
			ko_in_loop = 1;
			g_ko++;
		}
		i++;
	}
	if (!ko_in_loop)
	{
		printf("  " GREEN "[OK]" RESET " toupper : tous les ASCII 0-127\n");
		g_ok++;
	}
	/* ================================================================ */
	section("ft_tolower");
	/* ================================================================ */
	ko_in_loop = 0;
	i = 0;
	while (i < 128)
	{
		if (ft_tolower(i) != tolower(i))
		{
			printf("  " RED "[KO]" RESET " tolower(%d = '%c')\n", i, (i >= 32
					&& i < 127) ? i : '?');
			ko_in_loop = 1;
			g_ko++;
		}
		i++;
	}
	if (!ko_in_loop)
	{
		printf("  " GREEN "[OK]" RESET " tolower : tous les ASCII 0-127\n");
		g_ok++;
	}
	/* ================================================================ */
	section("ft_atoi");
	/* ================================================================ */
	check("\"42\"", ft_atoi("42") == atoi("42"));
	check("\"0\"", ft_atoi("0") == atoi("0"));
	check("\"-1\"", ft_atoi("-1") == atoi("-1"));
	check("\"+42\"", ft_atoi("+42") == atoi("+42"));
	check("\"  42\" espaces", ft_atoi("  42") == atoi("  42"));
	check("\"\\t\\n42\" whitespace", ft_atoi("\t\n42") == atoi("\t\n42"));
	check("\"\\v\\f42\" whitespace", ft_atoi("\v\f42") == atoi("\v\f42"));
	check("\"  -42\"", ft_atoi("  -42") == atoi("  -42"));
	check("\"42abc\" stop non-digit", ft_atoi("42abc") == atoi("42abc"));
	check("\"abc\" -> 0", ft_atoi("abc") == atoi("abc"));
	check("\"\" -> 0", ft_atoi("") == atoi(""));
	check("\"   \" -> 0", ft_atoi("   ") == atoi("   "));
	check("\"2147483647\" INT_MAX",
		ft_atoi("2147483647") == atoi("2147483647"));
	check("\"-2147483648\" INT_MIN",
		ft_atoi("-2147483648") == atoi("-2147483648"));
	check("\"  +0\"", ft_atoi("  +0") == atoi("  +0"));
	check("\"-0\"", ft_atoi("-0") == atoi("-0"));
	check("\"00042\" zeros en tete", ft_atoi("00042") == atoi("00042"));
	check("\"++42\" double signe", ft_atoi("++42") == atoi("++42"));
	check("\"--42\" double signe", ft_atoi("--42") == atoi("--42"));
	check("\"+-42\" double signe", ft_atoi("+-42") == atoi("+-42"));
	check("\" - 42\" espace apres signe", ft_atoi(" - 42") == atoi(" - 42"));
	check("\"42 \" trailing space", ft_atoi("42 ") == atoi("42 "));
	/* ================================================================ */
	section("ft_strlen");
	/* ================================================================ */
	check("\"\"", ft_strlen("") == strlen(""));
	check("\"a\"", ft_strlen("a") == strlen("a"));
	check("\"hello\"", ft_strlen("hello") == strlen("hello"));
	check("\"hello world\"", ft_strlen("hello world") == strlen("hello world"));
	check("\" \"", ft_strlen(" ") == strlen(" "));
	check("\"\\t\\n\"", ft_strlen("\t\n") == strlen("\t\n"));
	check("\"\\x01\\x02\\x03\"",
		ft_strlen("\x01\x02\x03") == strlen("\x01\x02\x03"));
	check("\"hello\\0world\" (stop)",
		ft_strlen("hello\0world") == strlen("hello\0world"));
	check("26 lettres",
		ft_strlen("abcdefghijklmnopqrstuvwxyz") == strlen("abcdefghijklmnopqrstuvwxyz"));
	/* ================================================================ */
	section("ft_bzero");
	/* ================================================================ */
	memset(dst_ft, 'a', 20);
	memset(dst_real, 'a', 20);
	ft_bzero(dst_ft, 10);
	bzero(dst_real, 10);
	check("10 octets == bzero", memcmp(dst_ft, dst_real, 20) == 0);
	memset(dst_ft, 'z', 20);
	memset(dst_real, 'z', 20);
	ft_bzero(dst_ft, 0);
	bzero(dst_real, 0);
	check("n=0 == bzero", memcmp(dst_ft, dst_real, 20) == 0);
	memset(dst_ft, 'z', 20);
	memset(dst_real, 'z', 20);
	ft_bzero(dst_ft, 1);
	bzero(dst_real, 1);
	check("n=1 == bzero", memcmp(dst_ft, dst_real, 20) == 0);
	memset(dst_ft, 'a', 200);
	memset(dst_real, 'a', 200);
	ft_bzero(dst_ft, 200);
	bzero(dst_real, 200);
	check("n=200 buffer entier == bzero", memcmp(dst_ft, dst_real, 200) == 0);
	memset(dst_ft, 'a', 20);
	memset(dst_real, 'a', 20);
	ft_bzero(dst_ft + 5, 10);
	bzero(dst_real + 5, 10);
	check("bzero avec offset == bzero", memcmp(dst_ft, dst_real, 20) == 0);
	/* ================================================================ */
	section("ft_memset");
	/* ================================================================ */
	memset(dst_ft, 0, 200);
	memset(dst_real, 0, 200);
	check("'a' n=5 == memset", memcmp(ft_memset(dst_ft, 'a', 5),
			memset(dst_real, 'a', 5), 5) == 0);
	memset(dst_ft, 0, 200);
	memset(dst_real, 0, 200);
	check("0 n=10 == memset", memcmp(ft_memset(dst_ft, 0, 10), memset(dst_real,
				0, 10), 10) == 0);
	memset(dst_ft, 0, 200);
	memset(dst_real, 0, 200);
	check("255 n=3 == memset", memcmp(ft_memset(dst_ft, 255, 3),
			memset(dst_real, 255, 3), 3) == 0);
	memset(dst_ft, 0, 200);
	memset(dst_real, 0, 200);
	check("-1 (255) n=200 == memset", memcmp(ft_memset(dst_ft, -1, 200),
			memset(dst_real, -1, 200), 200) == 0);
	dst_ft[0] = 'a';
	ft_memset(dst_ft, 'z', 0);
	check("n=0 ne touche rien", dst_ft[0] == 'a');
	check("retourne dst", ft_memset(dst_ft, 0, 5) == dst_ft);
	memset(dst_ft, 'x', 200);
	memset(dst_real, 'x', 200);
	check("sur buffer non-zero == memset", memcmp(ft_memset(dst_ft, 'y', 150),
			memset(dst_real, 'y', 150), 200) == 0);
	/* ================================================================ */
	section("ft_memcpy");
	/* ================================================================ */
	memset(dst_ft, 0, 200);
	memset(dst_real, 0, 200);
	check("\"hello\" == memcpy", memcmp(ft_memcpy(dst_ft, "hello", 6),
			memcpy(dst_real, "hello", 6), 6) == 0);
	memset(dst_ft, 0, 200);
	memset(dst_real, 0, 200);
	check("n=1 == memcpy", memcmp(ft_memcpy(dst_ft, "abc", 1), memcpy(dst_real,
				"abc", 1), 1) == 0);
	memset(dst_ft, 0, 200);
	memset(dst_real, 0, 200);
	check("octets nuls == memcpy", memcmp(ft_memcpy(dst_ft, "\x00\x01\x02\x03",
				4), memcpy(dst_real, "\x00\x01\x02\x03", 4), 4) == 0);
	memset(dst_ft, 0, 200);
	memset(dst_real, 0, 200);
	check("avec \\0 integre == memcpy", memcmp(ft_memcpy(dst_ft, "hel\0lo", 6),
			memcpy(dst_real, "hel\0lo", 6), 6) == 0);
	check("retourne dst", ft_memcpy(dst_ft, "test", 5) == dst_ft);
	ft_memcpy(dst_ft, "hello", 6);
	memcpy(dst_real, "hello", 6);
	ft_memcpy(dst_ft, "world", 0);
	memcpy(dst_real, "world", 0);
	check("n=0 ne touche rien", strcmp(dst_ft, dst_real) == 0);
	/* ================================================================ */
	section("ft_memmove");
	/* ================================================================ */
	memset(dst_ft, 0, 200);
	memset(dst_real, 0, 200);
	check("basique == memmove", memcmp(ft_memmove(dst_ft, "hello", 6),
			memmove(dst_real, "hello", 6), 6) == 0);
	strcpy(overlap_ft, "Hello, World!");
	strcpy(overlap_real, "Hello, World!");
	ft_memmove(overlap_ft + 2, overlap_ft, 6);
	memmove(overlap_real + 2, overlap_real, 6);
	check("overlap dest>src == memmove", memcmp(overlap_ft, overlap_real,
			13) == 0);
	strcpy(overlap_ft, "Hello, World!");
	strcpy(overlap_real, "Hello, World!");
	ft_memmove(overlap_ft, overlap_ft + 2, 6);
	memmove(overlap_real, overlap_real + 2, 6);
	check("overlap dest<src == memmove", memcmp(overlap_ft, overlap_real,
			13) == 0);
	strcpy(overlap_ft, "Hello, World!");
	strcpy(overlap_real, "Hello, World!");
	ft_memmove(overlap_ft + 1, overlap_ft, 12);
	memmove(overlap_real + 1, overlap_real, 12);
	check("overlap +1 dest>src == memmove", memcmp(overlap_ft, overlap_real,
			13) == 0);
	strcpy(overlap_ft, "Hello, World!");
	strcpy(overlap_real, "Hello, World!");
	ft_memmove(overlap_ft, overlap_ft + 1, 12);
	memmove(overlap_real, overlap_real + 1, 12);
	check("overlap +1 dest<src == memmove", memcmp(overlap_ft, overlap_real,
			13) == 0);
	memset(dst_ft, 0, 200);
	memset(dst_real, 0, 200);
	check("n=0 == memmove", memcmp(ft_memmove(dst_ft, "abc", 0),
			memmove(dst_real, "abc", 0), 3) == 0);
	check("retourne dst", ft_memmove(dst_ft, "test", 5) == dst_ft);
	/* ================================================================ */
	section("ft_memchr");
	/* ================================================================ */
	check("'l' n=5 == memchr", ft_memchr("hello", 'l', 5) == memchr("hello",
			'l', 5));
	check("'h' debut == memchr", ft_memchr("hello", 'h', 5) == memchr("hello",
			'h', 5));
	check("'o' fin == memchr", ft_memchr("hello", 'o', 5) == memchr("hello",
			'o', 5));
	check("'z' absent == memchr", ft_memchr("hello", 'z', 5) == memchr("hello",
			'z', 5));
	check("n=0 == memchr", ft_memchr("hello", 'h', 0) == memchr("hello", 'h',
			0));
	check("'\\0' n=6 == memchr", ft_memchr("hello", '\0', 6) == memchr("hello",
			'\0', 6));
	check("hors limite n=2 == memchr", ft_memchr("hello", 'l',
			2) == memchr("hello", 'l', 2));
	check("\\xff == memchr", ft_memchr("\xff\x01\x02", '\xff',
			3) == memchr("\xff\x01\x02", '\xff', 3));
	check("c + 256 (trunc) == memchr", ft_memchr("abc", 'a' + 256,
			3) == memchr("abc", 'a' + 256, 3));
	check("c = -1 (== 255) == memchr", ft_memchr("\xff", -1,
			1) == memchr("\xff", -1, 1));
	check("long buffer == memchr",
		ft_memchr("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", 'b',
			51) == memchr("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab",
			'b', 51));
	/* ================================================================ */
	section("ft_memcmp");
	/* ================================================================ */
	check("\"abc\" == \"abc\" n=3", sign(ft_memcmp("abc", "abc",
				3)) == sign(memcmp("abc", "abc", 3)));
	check("\"abc\" < \"abd\" n=3", sign(ft_memcmp("abc", "abd",
				3)) == sign(memcmp("abc", "abd", 3)));
	check("\"abd\" > \"abc\" n=3", sign(ft_memcmp("abd", "abc",
				3)) == sign(memcmp("abd", "abc", 3)));
	check("n=0 -> 0", sign(ft_memcmp("abc", "xyz", 0)) == sign(memcmp("abc",
				"xyz", 0)));
	check("\"abc\" == \"abx\" n=2", sign(ft_memcmp("abc", "abx",
				2)) == sign(memcmp("abc", "abx", 2)));
	check("\\xff > \\x01 unsigned", sign(ft_memcmp("\xff", "\x01",
				1)) == sign(memcmp("\xff", "\x01", 1)));
	check("\\x01 < \\xff unsigned", sign(ft_memcmp("\x01", "\xff",
				1)) == sign(memcmp("\x01", "\xff", 1)));
	check("n=10 identiques", sign(ft_memcmp("0123456789", "0123456789",
				10)) == sign(memcmp("0123456789", "0123456789", 10)));
	check("\"ab\\0c\" vs \"ab\\0d\" n=4", sign(ft_memcmp("ab\0c", "ab\0d",
				4)) == sign(memcmp("ab\0c", "ab\0d", 4)));
	check("\\x80 > \\x7f unsigned", sign(ft_memcmp("\x80\x81", "\x7f\x82",
				2)) == sign(memcmp("\x80\x81", "\x7f\x82", 2)));
	/* ================================================================ */
	section("ft_strchr");
	/* ================================================================ */
	check("'l' -> \"llo\" == strchr", ft_strchr("hello", 'l') == strchr("hello",
			'l'));
	check("'h' debut == strchr", ft_strchr("hello", 'h') == strchr("hello",
			'h'));
	check("'o' fin == strchr", ft_strchr("hello", 'o') == strchr("hello", 'o'));
	check("'z' absent == strchr", ft_strchr("hello", 'z') == strchr("hello",
			'z'));
	check("'\\0' == strchr", ft_strchr("hello", '\0') == strchr("hello", '\0'));
	check("string vide + '\\0' == strchr", ft_strchr("", '\0') == strchr("",
			'\0'));
	check("string vide + 'a' == strchr", ft_strchr("", 'a') == strchr("", 'a'));
	check("double occurrence == strchr", ft_strchr("abcabc",
			'b') == strchr("abcabc", 'b'));
	check("c = -1 == strchr", ft_strchr("\xff", -1) == strchr("\xff", -1));
	/* ================================================================ */
	section("ft_strrchr");
	/* ================================================================ */
	check("dernier 'l' == strrchr", ft_strrchr("hello", 'l') == strrchr("hello",
			'l'));
	check("'h' debut == strrchr", ft_strrchr("hello", 'h') == strrchr("hello",
			'h'));
	check("'o' fin == strrchr", ft_strrchr("hello", 'o') == strrchr("hello",
			'o'));
	check("'z' absent == strrchr", ft_strrchr("hello", 'z') == strrchr("hello",
			'z'));
	check("'\\0' == strrchr", ft_strrchr("hello", '\0') == strrchr("hello",
			'\0'));
	check("string vide + '\\0' == strrchr", ft_strrchr("", '\0') == strrchr("",
			'\0'));
	check("double occurrence == strrchr", ft_strrchr("abcabc",
			'b') == strrchr("abcabc", 'b'));
	check("c = -1 == strrchr", ft_strrchr("\xff\xff", -1) == strrchr("\xff\xff",
			-1));
	/* ================================================================ */
	section("ft_strncmp");
	/* ================================================================ */
	check("\"abc\" == \"abc\" n=3", sign(ft_strncmp("abc", "abc",
				3)) == sign(strncmp("abc", "abc", 3)));
	check("\"abc\" < \"abd\" n=3", sign(ft_strncmp("abc", "abd",
				3)) == sign(strncmp("abc", "abd", 3)));
	check("\"abd\" > \"abc\" n=3", sign(ft_strncmp("abd", "abc",
				3)) == sign(strncmp("abd", "abc", 3)));
	check("n=0 -> 0", sign(ft_strncmp("abc", "xyz", 0)) == sign(strncmp("abc",
				"xyz", 0)));
	check("\"abc\" == \"abx\" n=2", sign(ft_strncmp("abc", "abx",
				2)) == sign(strncmp("abc", "abx", 2)));
	check("\"abc\" > \"ab\" n=3", sign(ft_strncmp("abc", "ab",
				3)) == sign(strncmp("abc", "ab", 3)));
	check("\"ab\" < \"abc\" n=3", sign(ft_strncmp("ab", "abc",
				3)) == sign(strncmp("ab", "abc", 3)));
	check("\"\" vs \"\" n=0", sign(ft_strncmp("", "", 0)) == sign(strncmp("",
				"", 0)));
	check("\"\" < \"a\" n=1", sign(ft_strncmp("", "a", 1)) == sign(strncmp("",
				"a", 1)));
	check("\\x80 > \\x01 unsigned", sign(ft_strncmp("\x80", "\x01",
				1)) == sign(strncmp("\x80", "\x01", 1)));
	check("\"ab\\0c\" vs \"ab\\0d\" n=4", sign(ft_strncmp("ab\0c", "ab\0d",
				4)) == sign(strncmp("ab\0c", "ab\0d", 4)));
	check("\\xff > \\x7f unsigned", sign(ft_strncmp("\xff", "\x7f",
				1)) == sign(strncmp("\xff", "\x7f", 1)));
	/* ================================================================ */
	section("ft_strlcpy");
	/* ================================================================ */
	memset(dst_ft, 0, 200);
	memset(dst_real, 0, 200);
	ret_ft = ft_strlcpy(dst_ft, "hello", 100);
	ret_real = strlcpy(dst_real, "hello", 100);
	check("\"hello\" size=100 retourne", ret_ft == ret_real);
	check("\"hello\" size=100 contenu", strcmp(dst_ft, dst_real) == 0);
	memset(dst_ft, 0, 200);
	memset(dst_real, 0, 200);
	ret_ft = ft_strlcpy(dst_ft, "hello", 3);
	ret_real = strlcpy(dst_real, "hello", 3);
	check("\"hello\" size=3 retourne", ret_ft == ret_real);
	check("\"hello\" size=3 contenu", strcmp(dst_ft, dst_real) == 0);
	memset(dst_ft, 0, 200);
	memset(dst_real, 0, 200);
	ret_ft = ft_strlcpy(dst_ft, "hello", 1);
	ret_real = strlcpy(dst_real, "hello", 1);
	check("\"hello\" size=1 retourne", ret_ft == ret_real);
	check("\"hello\" size=1 -> \"\"", strcmp(dst_ft, dst_real) == 0);
	memset(dst_ft, 'x', 200);
	memset(dst_real, 'x', 200);
	ret_ft = ft_strlcpy(dst_ft, "hello", 0);
	ret_real = strlcpy(dst_real, "hello", 0);
	check("\"hello\" size=0 retourne", ret_ft == ret_real);
	check("\"hello\" size=0 inchange", dst_ft[0] == 'x');
	memset(dst_ft, 0, 200);
	memset(dst_real, 0, 200);
	ret_ft = ft_strlcpy(dst_ft, "", 100);
	ret_real = strlcpy(dst_real, "", 100);
	check("\"\" size=100 retourne", ret_ft == ret_real);
	check("\"\" size=100 contenu", strcmp(dst_ft, dst_real) == 0);
	memset(dst_ft, 0, 200);
	memset(dst_real, 0, 200);
	ret_ft = ft_strlcpy(dst_ft, "hello world", 6);
	ret_real = strlcpy(dst_real, "hello world", 6);
	check("\"hello world\" size=6 retourne", ret_ft == ret_real);
	check("\"hello world\" size=6 contenu", strcmp(dst_ft, dst_real) == 0);
	/* ================================================================ */
	section("ft_strlcat");
	/* ================================================================ */
	strlcpy(dst_ft, "hello", 200);
	strlcpy(dst_real, "hello", 200);
	ret_ft = ft_strlcat(dst_ft, " world", 200);
	ret_real = strlcat(dst_real, " world", 200);
	check("cat basique retourne", ret_ft == ret_real);
	check("cat basique contenu", strcmp(dst_ft, dst_real) == 0);
	strlcpy(dst_ft, "hello", 200);
	strlcpy(dst_real, "hello", 200);
	ret_ft = ft_strlcat(dst_ft, " world", 8);
	ret_real = strlcat(dst_real, " world", 8);
	check("cat size=8 retourne", ret_ft == ret_real);
	check("cat size=8 contenu", strcmp(dst_ft, dst_real) == 0);
	strlcpy(dst_ft, "hello", 200);
	strlcpy(dst_real, "hello", 200);
	ret_ft = ft_strlcat(dst_ft, "", 200);
	ret_real = strlcat(dst_real, "", 200);
	check("cat src vide retourne", ret_ft == ret_real);
	check("cat src vide contenu", strcmp(dst_ft, dst_real) == 0);
	strlcpy(dst_ft, "hello", 200);
	strlcpy(dst_real, "hello", 200);
	ret_ft = ft_strlcat(dst_ft, " world", 5);
	ret_real = strlcat(dst_real, " world", 5);
	check("cat size<=len_dst retourne", ret_ft == ret_real);
	check("cat size<=len_dst inchange", strcmp(dst_ft, "hello") == 0);
	strlcpy(dst_ft, "", 200);
	strlcpy(dst_real, "", 200);
	ret_ft = ft_strlcat(dst_ft, "hello", 200);
	ret_real = strlcat(dst_real, "hello", 200);
	check("cat dst vide retourne", ret_ft == ret_real);
	check("cat dst vide contenu", strcmp(dst_ft, dst_real) == 0);
	strlcpy(dst_ft, "hello", 200);
	strlcpy(dst_real, "hello", 200);
	ret_ft = ft_strlcat(dst_ft, " world", 6);
	ret_real = strlcat(dst_real, " world", 6);
	check("cat size=len_dst+1 retourne", ret_ft == ret_real);
	check("cat size=len_dst+1 contenu", strcmp(dst_ft, dst_real) == 0);
	strlcpy(dst_ft, "hello", 200);
	strlcpy(dst_real, "hello", 200);
	ret_ft = ft_strlcat(dst_ft, " world", 0);
	ret_real = strlcat(dst_real, " world", 0);
	check("cat size=0 retourne", ret_ft == ret_real);
	check("cat size=0 contenu inchange", strcmp(dst_ft, "hello") == 0);
	/* ================================================================ */
	section("ft_strnstr");
	/* ================================================================ */
	{
		check("\"world\" n=11", ft_strnstr(big, "world", 11) == big + 6);
		check("\"xyz\" absent n=11 -> NULL", ft_strnstr(big, "xyz",
				11) == NULL);
		check("\"world\" hors limite n=8 -> NULL", ft_strnstr(big, "world",
				8) == NULL);
		check("little vide -> retourne big", ft_strnstr(big2, "", 5) == big2);
		check("little == big exact", ft_strnstr(big2, "hello", 5) == big2);
		check("n=0 little vide -> retourne big", ft_strnstr(big2, "",
				0) == big2);
		check("n=0 little non vide -> NULL", ft_strnstr(big2, "hello",
				0) == NULL);
		check("trouve en debut", ft_strnstr(big, "hello", 11) == big);
		check("trouve en milieu", ft_strnstr(big, "lo wo", 11) == big + 3);
		check("big vide little vide n=0", ft_strnstr(big3, "", 0) == big3);
		check("big vide little non vide -> NULL", ft_strnstr(big3, "hello",
				5) == NULL);
		check("little plus grand que n -> NULL", ft_strnstr("hi", "hello",
				2) == NULL);
		check("n large > taille big", ft_strnstr(big2, "ell", 100) == big2 + 1);
		{
			check("multi occurrences -> premiere", ft_strnstr(multi, "aab",
					7) == multi + 1);
		}
	}
	/* ================================================================ */
	section("ft_calloc");
	/* ================================================================ */
	ptr = ft_calloc(5, sizeof(char));
	ptr2 = calloc(5, sizeof(char));
	check("5 chars tous a 0 == calloc", ptr && ptr2 && memcmp(ptr, ptr2,
			5) == 0);
	free(ptr);
	free(ptr2);
	iptr = ft_calloc(3, sizeof(int));
	check("3 ints tous a 0", iptr && iptr[0] == 0 && iptr[1] == 0
		&& iptr[2] == 0);
	free(iptr);
	ptr = ft_calloc(10, sizeof(char));
	check("10 chars tous a 0", ptr && ptr[0] == 0 && ptr[5] == 0
		&& ptr[9] == 0);
	free(ptr);
	ptr = ft_calloc(1, 1);
	check("1x1 a 0", ptr && ptr[0] == 0);
	free(ptr);
	/* calloc(0, x) et calloc(x, 0) : comportement defini mais NULL ou ptr */
	ptr = ft_calloc(0, sizeof(char));
	check("nmemb=0 ne crash pas", 1);
	if (ptr)
		free(ptr);
	ptr = ft_calloc(1, 0);
	check("size=0 ne crash pas", 1);
	if (ptr)
		free(ptr);
	/* large alloc */
	ptr = ft_calloc(1000, sizeof(char));
	check("1000 chars large alloc tous a 0", ptr && ptr[0] == 0 && ptr[500] == 0
		&& ptr[999] == 0);
	if (ptr)
		free(ptr);
	/* overflow : (size_t)-1 * 1 -> malloc doit echouer -> NULL */
	ptr = ft_calloc((size_t)-1 / 2, 3);
	check("overflow -> NULL attendu", ptr == NULL);
	if (ptr)
		free(ptr);
	/* ================================================================ */
	section("ft_strdup");
	/* ================================================================ */
	ptr = ft_strdup("hello");
	ptr2 = strdup("hello");
	check("\"hello\" == strdup", ptr && ptr2 && strcmp(ptr, ptr2) == 0);
	free(ptr);
	free(ptr2);
	ptr = ft_strdup("");
	ptr2 = strdup("");
	check("\"\" == strdup", ptr && ptr2 && strcmp(ptr, ptr2) == 0);
	free(ptr);
	free(ptr2);
	ptr = ft_strdup("a");
	ptr2 = strdup("a");
	check("\"a\" == strdup", ptr && ptr2 && strcmp(ptr, ptr2) == 0);
	free(ptr);
	free(ptr2);
	ptr = ft_strdup("hello world 42!");
	ptr2 = strdup("hello world 42!");
	check("\"hello world 42!\" == strdup", ptr && ptr2 && strcmp(ptr,
			ptr2) == 0);
	free(ptr);
	free(ptr2);
	ptr = ft_strdup("\x01\x02\x03");
	ptr2 = strdup("\x01\x02\x03");
	check("non-printable chars == strdup", ptr && ptr2 && memcmp(ptr, ptr2,
			3) == 0);
	free(ptr);
	free(ptr2);
	/* copie independante */
	strlcpy(dst_ft, "hello world", 100);
	ptr = ft_strdup(dst_ft);
	dst_ft[0] = 'X';
	check("copie independante", ptr && strcmp(ptr, "hello world") == 0);
	free(ptr);
	/* stop au premier \0 */
	ptr = ft_strdup("hello\0hidden");
	ptr2 = strdup("hello\0hidden");
	check("stop au premier \\0", ptr && ptr2 && strcmp(ptr, ptr2) == 0);
	free(ptr);
	free(ptr2);
	/* long string */
	ptr = ft_strdup("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
					"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	ptr2 = strdup("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
					"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	check("128 chars == strdup", ptr && ptr2 && strcmp(ptr, ptr2) == 0);
	free(ptr);
	free(ptr2);
	/* ================================================================ */
	printf(BOLD CYAN "\n╔══════════════════════════════╗\n" RESET);
	printf(BOLD CYAN "║  RESULTATS FINAUX            ║\n" RESET);
	printf(BOLD CYAN "╚══════════════════════════════╝\n" RESET);
	printf("  " GREEN "OK : %d" RESET "\n", g_ok);
	printf("  " RED "KO : %d" RESET "\n", g_ko);
	printf("  Total : %d\n\n", g_ok + g_ko);
	return (0);
}
