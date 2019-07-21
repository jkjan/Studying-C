#include "d.h"

ada*ada::init() {
	ada*sex = new ada;
	sex->num = new int(100);
	sex->cnt = 0;
	sex->size = 100;
	return sex;
}

void ada::insert(ada*s, int a) {
	if (isfull(s))
		return;

	if (isempty(s))
		*(s->num) = a;

	int i, j;

	if (a <= *(s->num)) {
		for (i = s->cnt - 1; i >= 0; i--) {
			s->num[i + 1] = s->num[i];
		}
		*(s->num) = a;
	}

	else {
		for (i = 0; i < s->cnt; i++) {
			if (a <= *(s->num + i))
				break;
		}

		if (i < s->cnt) {
			for (j = s->cnt - 1; j >= i; j--) {
				s->num[j + 1] = s->num[j];
			}
			s->num[i] = a;
		}

		else
			s->num[s->cnt] = a;
	}

	s->cnt++;

	return;
}

int ada::search(ada*s, int a, int l, int r) {
	int m = (l + r) / 2;

	if (l > r)
		return -1;

	if (l == r)
		return m;

	else {
		if (s->num[m] > a)
			search(s, a, l, m - 1);

		else if (s->num[m] == a)
			return m;

		else
			search(s, a, m + 1, r);
	}
}

int ada::remove(ada*s, int a) {
	if (isempty(s))
		return 0;

	int i;

	int w = search(s, a, 0, s->cnt - 1);

	if (w == -1)
		return 0;

	for (i = w; i < s->cnt - 1; i++) {
		s->num[i] = s->num[i + 1];
	}

	s->cnt--;

	return w;
}

int ada::isfull(ada*s) {
	return s->cnt == s->size ? 1 : 0;
}

int ada::isempty(ada*s) {
	return s->cnt == 0 ? 1 : 0;
}

void ada::printall(ada*s) {
	if (isempty(s))
		return;

	for (int i = 0; i < s->cnt; i++)
		cout << s->num[i] << ' ';
	return;
}