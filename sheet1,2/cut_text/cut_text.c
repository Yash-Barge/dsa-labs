#include <stdio.h>

int main(void){
	FILE *f_test1 = fopen("test1.txt", "r");
	FILE *f_test2 = fopen("test2.txt", "a");

	if (f_test1 == NULL) {
		printf("test1.txt does not exist! Exiting...");
		return 1;
	}

	while (1) {
		char buffer[1024];
		if (fgets(buffer, 1024, f_test1) == NULL) break;
		fprintf(f_test2, "%s", buffer);
	}

	fclose(f_test1);
	fclose(f_test2);

	FILE *temp = fopen("test1.txt", "w");
	fclose(temp);

	return 0;
}
