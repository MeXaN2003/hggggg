#include "fileread.h"
#include <stdio.h>

int main()
{
	FILE *input_file;
	input_file = fopen("input.txt", "r");
	if (!input_file) {
		return;
	}
	while (!feof(input_file)) {
		JJJJstruct kekis = FileRead(input_file);
		printf("%d\n", kekis.choose_function);
	}
	fclose(input_file);
    return 0;
}