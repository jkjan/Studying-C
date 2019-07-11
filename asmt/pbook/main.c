#include "pb.h"

extern int cnt;
extern int ccnt;

int main() {
	int com = 0;
	node* root = NULL;
	pbook* info;
	FILE* fp = fopen("phonebook.txt", "r");
	
	char circle[30]; //to read info when insert and load
	char name[7];
	char number[12];
	char command[7];
	int i;

	if (fp != NULL) {                                              //if the file exists
		while ((fscanf(fp, "%s %s %s\n", circle, name, number)) != EOF) {    //read the file till the end
			info = setInfo(circle, name, number);
			root = load(root, info);
		};
		fclose(fp);
	}
	puts("\n ┏================================================================┓");
	puts(" | Hello, I'm Jarvis. Your personal phone book management program.|");  // user interface
	puts(" | How may I help you, sir?                                       |");
	puts(" |                                                                |");
	puts(" | 1. Insert a number                                             |");
	puts(" | 2. Find a person                                               |");
	puts(" | 3. Delete information                                          |");
	puts(" | 4. Print all information                                       |");
	puts(" | 5. Print a circle's information                                |");
	puts(" | 6. Data reset                                                  |");
	puts(" | 7. Exit                                                        |");
	puts(" |                                                                |");
	puts(" ┗================================================================┛\n");

	while (1) {
		scanf("%d", &com);  //input command
		if (com == 1) {    //insert
			puts("\nPlease input the person's circle, name, and the number please.");
			scanf(" %s %s %s", circle, name, number);
			__fpurge(stdin);
			
			info = setInfo(circle, name, number);      //get those in
			root = addtree(root, info);                //and add it to a tree
			printf("\n%s's information is now on the list, sir.", name);
			puts("\n");
		}

		else if (com == 2) {   //search
			if (cnt != 0) {
				puts("\nWho do you want to find?");
				scanf(" %s", command);                       //target
				node* searched = search(root, command);     
				if (searched == NULL)                       //if theres no such person
					puts("\nSorry, I couldn't find the person.");
				else {
					printf("\n");
					infoprint(searched->info);
				}
			}
			else
				puts("\nNo data here.");
			printf("\n");
		}

		else if (com == 3) {                  //remove
			if (cnt != 0) {
				puts("\nWho do you want to delete?");
				scanf(" %s", command);
	
				if (strcmp(command, root->info->name) == 0 && cnt == 1) {      //if there's just one data
					root = NULL;                                               //init
					cnt = 0;
					printf("\nThe last data deleted, no more data storaged, sir.\n\n");
				}
	
				else if (search(root, command) != NULL) {   //if found
					eliminate(root, command);                  //delete
					cnt--;
					printf("\n%s deleted, sir.\n\n", command);
				}

				else
					puts("\nThere is no such person.\n");   //if not
			}
			else
				puts("\nNo data here.\n");
		}

		else if (com == 4) {   //print
			if (cnt != 0) {
				puts("\nData printed.\n");
				treeprint(root);
				printf("\nCurrently %d data storaged.", cnt);
			}
			else   //if theres no data
				printf("\nNo data here.");
			puts("\n");
		}

		else if (com == 5) { //people whos in the club
			if (cnt != 0) {
				puts("\nWhich circle's members do you want to see?");
				scanf(" %s", command);
				printf("\n");
				int c = circleprint(root, command);
				printf("\n%d circle member(s) searched.", c); 
				ccnt = 0;
			}
			else   //if theres no data
				printf("\nNo data here.");		
			
			puts("\n");
		}

		else if (com == 6) {
			puts("\nAre you sure? (YES, or press any key)");
			scanf(" %s", command);
			printf("\n");
			if (strcmp(command, "YES")==0) {
				for (i = 4; i >= 1; i--) {
					printf("For real? (%d) ", i);
					scanf("%s", command);
					if (strcmp(command, "YES") != 0) {
						puts("\nReset Cancelled.\n");
						break;
					}
				}
				if (i == 0) {
					puts("\nData reset\n");
					cnt = 0;
					root = NULL;
				}
			}
			else
				puts("\nReset Cancelled.\n");
			
		}

		else if (com == 7) {  //exit
			puts("\nAlright, have a good day sir.");
			export(root);
			return 0;
		}
		puts("==================================================================\n");
		printf("What else may I do for you?  ");  //being polite
	}
}
