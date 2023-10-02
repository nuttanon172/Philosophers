#include <stdio.h>

# define RED		"\x1b[31m"
# define GREEN	"\x1b[32m"
# define YELLOW	"\x1b[33m"
# define BLUE	"\x1b[34m"

int main()
{
	printf("%sdied\n", RED);
	printf("%seat\n", GREEN);
	printf("%sthink\n", YELLOW);
	printf("%ssleep\n", BLUE);
	size_t a = -1;
	printf("-1 = %zu\n", a);
	printf("-1 = %zu\n", a + 1);
}
