#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

enum Rarity {
	F,   // REST
	E,   // 50%     2
	D,   // 30%     10 / 3
	C,   // 10%     10
	B,   // 5%      50
	A,   // 1%      100
	S,   // 0.1%    1000
	SS,  // 0.01%   10000
	SSS, // 0.001%  100000
};

typedef enum Rarity Rarity;

typedef struct Fish {
	Rarity rarity;
	float size;
	char *name;
	int value;
} Fish;

int randInt(int range) {
	return (rand() / (RAND_MAX / range));
}

char **loadFishNames(int *amnt) {
	char **names = NULL;
	int size = 0;

	FILE *fishFile;
	fishFile = fopen("fihlist.txt", "r");

	char *ident;
	char *data;
	int lineamnt = 0;

	if (fishFile != NULL) {
		while (fscanf(fishFile, "%*s %*s", ident, data) == 2) {
			printf("ident: %s, data: %s\n", ident, data);
			lineamnt += 1;
			if(ident[0] == 'n') {
				size++;
				names = (char**)malloc(sizeof(char*) * size);
				names[size - 1] = data;
			}
		}
	}

	/*printf("total lines: %i, %s\n", lineamnt, names[0]);

	*amnt = size;
	return names;*/
}
