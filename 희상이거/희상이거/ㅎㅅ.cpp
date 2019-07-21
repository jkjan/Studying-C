#include <iostream>

using namespace std;

class Student {
private:
	char name[10];
	char gender;
	char address[10];
	char major[20];
	float grade;
	int height;
	int weight;
public:
	void input_student(FILE *fp, Student *p1, int length);
	void output_student(Student *p1, int length);
	Student* memory(int length);
};

Student* Student::memory(int length) {
	Student *p1 = new Student[length];
	return p1;
}

void Student::input_student(FILE *fp, Student *p1, int length) {
	int i;
	for (i = 0; i < length; i++) {
		fscanf(fp, "%s %c %s %s %f %d %d", (p1 + i)->name, &(p1 + i)->gender, (p1 + i)->address, (p1 + i)->major, &(p1 + i)->grade, &(p1 + i)->height, &(p1 + i)->weight);
	}
}

void Student::output_student(Student *p1, int length) {
	int i;
	for (i = 0; i < length; i++) {
		printf("%s %c %s %s %.2f %d %d\n", (p1 + i)->name, (p1 + i)->gender, (p1 + i)->address, (p1 + i)->major, (p1 + i)->grade, (p1 + i)->height, (p1 + i)->weight);
	}
}

int main()
{
	FILE *fp = fopen("list.txt", "r+t");
	 char c;
	int length = 0;
	while ((c = fgetc(fp)) != EOF) {
	   if (c == '\n')
		  length++;
	}
	length += 1; 
	rewind(fp);

	Student std;
	Student *list = std.memory(length);
	std.input_student(fp, list, length);
	std.output_student(list, length);

	fclose(fp);
}