#include <stdio.h>

typedef enum syllable {
	Do=1, Re=2, Mi=3, Fa=4, So=5, La=6, Ti=7   //������ ���
} Syllable;

void Sound(Syllable sy) {
	switch (sy) {
	case Do:
		puts("��"); return;
	case Re:
		puts("��"); return;
	case Mi:
		puts("��"); return;
	case Fa:
		puts("��"); return;
	case So:
		puts("��"); return;
	case La:
		puts("��"); return;
	case Ti:
		puts("��"); return;
	}
}

int main() {
	Syllable tone;
	for (tone = Do; tone <= Ti; tone += 1)
		Sound(tone);

	printf("%g", sizeof(int));
	return 0;
}