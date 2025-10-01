#ifndef FIHTYPES_H
#define FIHTYPES_H

#include "fish.h"
#include <math.h>

enum fishType {
	PERCH,
	PIKE,
	TROUT,
	BASS,
};

#define TYPE_AMOUNT 4

void randomizeFish(Fish *f, float min, int range) {

	int random = randInt(100000);
	if      (random <  1)     { f->rarity = (Rarity)SSS; } // 1  
	else if (random < 11)     { f->rarity = (Rarity)SS;  } // 10 
	else if (random < 111)    { f->rarity = (Rarity)S;   } // 100 
	else if (random < 1111)   { f->rarity = (Rarity)A;   } // 1000 
	else if (random < 6111)   { f->rarity = (Rarity)B;   } // 5000
	else if (random < 16111)  { f->rarity = (Rarity)C;   } // 10000
	else if (random < 46111)  { f->rarity = (Rarity)D;   } // 30000
	else if (random < 76111)  { f->rarity = (Rarity)E;   } // 30000 
	else if (random >= 76111) { f->rarity = (Rarity)F;   } // REST

	// -- CALCULATE WEIGHT --

	range = 35 + range * f->rarity;
	f->size = (float)randInt(range) / 100 + min;
}

void calculateValue(Fish *f) {
	float r = exp((double)f->rarity);
	f->value = (int)(r * 100.0f + f->size * 500.0f + 5.0f);
}

Fish createFish() {
	int t = randInt(TYPE_AMOUNT);
	Fish f;
	switch (t) {
		case 0:
			f.name = "Perch";
			randomizeFish(&f, 2.0f, 427);
			break;
		case 1:
			f.name = "Pike";
			randomizeFish(&f, 5.0f, 732);
			break;
		case 2:
			f.name = "Trout";
			randomizeFish(&f, 4.8f, 700);
			break;
		case 3:
			f.name = "Bass";
			randomizeFish(&f, 3.6f, 886);
		default:
		break;
	}

	calculateValue(&f);

	return f;
}

#endif
