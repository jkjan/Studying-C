#ifndef namecard
#define namecard
#define name_len 30
#define phone_len 30

typedef struct __namecard {
	char name[name_len];
	char phone[phone_len];
} card;

card*make(char*name, char*phone);

void show(card*pcard);

int comp(card *pcard, char*name);

void change(card*pcard, char*phone);



#endif
#pragma once
