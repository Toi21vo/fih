#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fish.h"
#include "fihtypes.h"

static struct {
	char **typeNames;
	int typeAmnt;
} state;

void printRarity(Rarity r) {
	switch ((int)r) {
		case 0:
			printf("F\n");
			break;
		case 1:
			printf("E\n");
			break;
		case 2:
			printf("D\n");
			break;
		case 3:
			printf("C\n");
			break;
		case 4:
			printf("B\n");
			break;
		case 5:
			printf("A\n");
			break;
		case 6:
			printf("S\n");
			break;
		case 7:
			printf("SS\n");
			break;
		case 8:
			printf("SSS\n");
			break;
		default:
			printf("NO RARITY");
			break;
	}
}


int main() {
	srand(time(NULL));

	state.typeNames = loadFishNames(&state.typeAmnt);

	/*for (int i = 0; i < state.typeAmnt; i++) {
		printf("NAMES [%i]: %s\n", i, state.typeNames[i]);
	}*/

	Fish fish = createFish();

	printf("FIHS NAME: %s!\n", fish.name);

	printRarity(fish.rarity);

	printf("FISH SIZE: %fcm\n", fish.size);

	printf("FIHS VALUE: %i\n", fish.value);
}
