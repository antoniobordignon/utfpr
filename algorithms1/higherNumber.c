#include <stdio.h>

int main() {
	int a, b, c, d, e;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	if(e < a) {
		e = a;
	}
	if(e < b) {
		e = b;
	}
	if(e < c) {
		e = c;
	}
	if(e < d) {
		e = d;
	}
	printf("%d", e);
}
