#include "node.h"

BOOL IsLower_GM(int id1, int id2) {
	int gn1, gn2, mn1, mn2;

	gn1 = id1 % 10000;
	gn2 = id2 % 10000;
	mn1 = (id1 / 10000) % 1000;
	mn2 = (id2 / 10000) % 1000;

	if (gn1 < gn2) return TRUE;
	else if (gn1 > gn2) return FALSE;
	else if (mn1 < mn2) return TRUE;
	else return FALSE;
}
