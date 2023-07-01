#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	unsigned long long int num, head, median;
	char *num_buf = NULL, *stop;
	size_t n = 0;

	FILE *fp = fopen(argv[1],  "r");

	while (getline(&num_buf, &n, fp) != -1)
	{
		num = strtoull(num_buf, &stop, 10);
		head = num % 2 == 0? 2 : 3;
		median = num / 2 + 1;

		for (; head < median; head += 2)
			if (num % head == 0)
			{
				printf("%llu=%llu*%llu\n", num, num / head, head);
				break;
			}
	}
	fclose(fp);
	return (0);
}
