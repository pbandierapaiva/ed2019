#include <stdio.h>

#define MAX_TABLE 1000000

long int hash(const char * str) {
	int hash = 401;
	int c;

	while (*str != '\0') {
		hash = ((hash << 4) + (int)(*str)) % MAX_TABLE;
		str++;
	}

	return hash % MAX_TABLE;
}

int main() {

	char inp[200];

	while(1) {
		scanf("%s", inp);
        	printf("%ld\n",hash(inp));
	}
}

