#include <gmp.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	mpz_t num, head, median, rem;
	mpz_init(num);
	mpz_init(head);
	mpz_init(median);
	mpz_init(rem);
	char *num_buf = NULL, *stop;
	size_t n = 0;

	FILE *fp = fopen(argv[1], "r");

	while (getline(&num_buf, &n, fp) != -1)
	{
		mpz_set_str(num, num_buf, 10);
		mpz_div_ui(median, num, 2);
		mpz_add_ui(median, median, 1);
		if (mpz_mod_ui(head, num, 2) == 0)
			mpz_set_ui(head, 2);
		else
			mpz_set_ui(head, 3);

		for (; mpz_cmp(head, median) < 0; mpz_add_ui(head, head, 2))
		{
			mpz_mod(rem, num, head);
			if (mpz_cmp_ui(rem, 0) == 0)
			{
				mpz_div(rem, num, head);
				gmp_printf("%Zd=%Zd*%Zd\n", num, rem, head);
				break;
			}
		}
	}
	fclose(fp);
	mpz_clear(num);
	mpz_clear(median);
	mpz_clear(head);
	mpz_clear(rem);
	return (0);
}
