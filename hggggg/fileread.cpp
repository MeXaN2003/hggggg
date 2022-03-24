#include "fileread.h"
#include "geometryshapes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define kCircleArraySize 6
#define kTriangleArraySize 6

JJJJstruct FileRead(FILE* input_file)
{
	JJJJstruct input_struct;
	int o = 0;
	float input_poz_circle[kCircleArraySize] = { 0 };
	float input_poz_triangle[kTriangleArraySize] = { 0 };
	char input_k = 0;
	char input_line[127] = { 0 };
	while (input_k != '\n') {
		input_k = fgetc(input_file);
		if (input_k == -1) {
			break;
		}
		input_line[o] = input_k;
		o++;
	}
	if (input_line[0] == 't') {
		for (long unsigned int i = 0, d = 0; i <= strlen(input_line); i++) {
			if (StrNumber(input_line[i])) {
				if (input_line[i + 1] == '.') {
					input_poz_triangle[d] = (input_line[i] - 0x30)
						+ (0.1 * (input_line[i + 2] - 0x30));
					if (input_line[i - 1] == '-') {
						input_poz_triangle[d] *= -1.0;
					}
					i += 2;
				}
				else {
					input_poz_triangle[d] = (input_line[i] - 0x30);
					if (input_line[i - 1] == '-') {
						input_poz_triangle[d] *= -1.0;
					}
				}
				d++;
			}
		}
		for (int i = 0; i < kCircleArraySize; i++) {
			input_struct.input_array[i] = input_poz_triangle[i];
		}
		input_struct.choose_function = 1;
	}
	if (input_line[0] == 'c') {
		for (long unsigned int i = 0, d = 0; i <= strlen(input_line); i++) {
			if (StrNumber(input_line[i])) {
				if (input_line[i + 1] == '.') {
					input_poz_circle[d] = (input_line[i] - 0x30)
						+ (0.1 * (input_line[i + 2] - 0x30));
					if (input_line[i - 1] == '-') {
						input_poz_circle[d] *= -1.0;
					}
					i += 2;
				}
				else {
					input_poz_circle[d] = (input_line[i] - 0x30);
					if (input_line[i - 1] == '-') {
						input_poz_circle[d] *= -1.0;
					}
				}
				d++;
			}
		}
		for (int i = 0; i < kCircleArraySize; i++) {
				input_struct.input_array[i] = input_poz_triangle[i];
		}
		input_struct.choose_function = 2;
	}
	for (int k = 0; k < kCircleArraySize; k++) {
		input_poz_circle[k] = 0;
	}
	for (int k = 0; k < kTriangleArraySize; k++) {
		input_poz_triangle[k] = 0;
	}
	o = 0;
	return input_struct;
}

int StrNumber(char input_symbol)
{
	if ((input_symbol - 0x30) >= 0 && (input_symbol - 0x30) <= 9) {
		return 1;
	}
	else
		return 0;
}

