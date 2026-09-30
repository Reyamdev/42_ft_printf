#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

static void	print_result(int real, int mine)
{
	printf("\nprintf return:    %d\n", real);
	printf("ft_printf return: %d\n", mine);
	if (real == mine)
		printf("RETURN: OK\n\n");
	else
		printf("RETURN: FAIL\n\n");
}

int	main(void)
{
	int		real;
	int		mine;
	int		n;
	char	*null_str;

	n = 42;
	null_str = NULL;

	printf("========== BASIC MIXED TEST ==========\n");

	real = printf(
			"char=[%c] str=[%s] ptr=[%p] d=[%d] i=[%i] "
			"u=[%u] x=[%x] X=[%X] percent=[%%]\n",
			'A', "Hello 42", (void *)&n, -42, 42,
			42U, 255U, 255U);

	mine = ft_printf(
			"char=[%c] str=[%s] ptr=[%p] d=[%d] i=[%i] "
			"u=[%u] x=[%x] X=[%X] percent=[%%]\n",
			'A', "Hello 42", (void *)&n, -42, 42,
			42U, 255U, 255U);

	print_result(real, mine);

	printf("========== INTEGER LIMITS ==========\n");

	real = printf(
			"INT_MIN=[%d] INT_MAX=[%d] UINT_MAX=[%u] "
			"HEX=[%x] HEX_UP=[%X]\n",
			INT_MIN, INT_MAX, UINT_MAX, UINT_MAX, UINT_MAX);

	mine = ft_printf(
			"INT_MIN=[%d] INT_MAX=[%d] UINT_MAX=[%u] "
			"HEX=[%x] HEX_UP=[%X]\n",
			INT_MIN, INT_MAX, UINT_MAX, UINT_MAX, UINT_MAX);

	print_result(real, mine);

	printf("========== ZERO TEST ==========\n");

	real = printf(
			"d=[%d] i=[%i] u=[%u] x=[%x] X=[%X]\n",
			0, 0, 0U, 0U, 0U);

	mine = ft_printf(
			"d=[%d] i=[%i] u=[%u] x=[%x] X=[%X]\n",
			0, 0, 0U, 0U, 0U);

	print_result(real, mine);

	printf("========== STRING TEST ==========\n");

	real = printf("empty=[%s] normal=[%s]\n", "", "Unga bunga");
	mine = ft_printf("empty=[%s] normal=[%s]\n", "", "Unga bunga");

	print_result(real, mine);

	printf("========== NULL STRING ==========\n");

	real = printf("null=[%s]\n", null_str);
	mine = ft_printf("null=[%s]\n", null_str);

	print_result(real, mine);

	printf("========== POINTER TEST ==========\n");

	real = printf("ptr=[%p]\n", (void *)&n);
	mine = ft_printf("ptr=[%p]\n", (void *)&n);

	print_result(real, mine);

	printf("========== NULL POINTER ==========\n");

	real = printf("ptr=[%p]\n", NULL);
	mine = ft_printf("ptr=[%p]\n", NULL);

	print_result(real, mine);

	printf("========== PERCENT TEST ==========\n");

	real = printf("%% %% %% %% %%\n");
	mine = ft_printf("%% %% %% %% %%\n");

	print_result(real, mine);

	printf("========== CHAR TEST ==========\n");

	real = printf("[%c][%c][%c]\n", 'A', '0', 'Z');
	mine = ft_printf("[%c][%c][%c]\n", 'A', '0', 'Z');

	print_result(real, mine);

	return (0);
}
