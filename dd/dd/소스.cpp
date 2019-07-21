#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Student{
private:
   char name[10];
   char sex;
   char area[10];
   char major[20];
   float grade;
   int height;
   int weight;
public:
   int line (FILE *file);
   Student* alloc(int n);
   void scan (FILE*fp,int i,Student*data);
   void print (Student*data,int n);

};

int Student :: line (FILE *file) {
   int i=0;
   int  j;
   while((j=fgetc(file))!=EOF)
    {
       if (j=='\n')
          i++;
    }
    return i+=1;
}

Student * Student :: alloc(int n) {
   Student *data=new Student[n];
    return data;
}

void Student :: scan(FILE*fp,int i,Student*data){
   int k;
   for(k=0;k<i;k++){
      fscanf(fp,"%s %c %s %s %f %d %d",data[k].name,&data[k].sex,data[k].area,data[k].major,&data[k].grade,&data[k].height,&data[k].weight);
    }
}

void Student :: print (Student *data, int n){
   int k;
   for(k=0;k<n;k++){
      printf("%s %c %s %s %g %d %d\n",data[k].name,data[k].sex,data[k].area,data[k].major,data[k].grade,data[k].height,data[k].weight);
    }
}


int main(){
    int len;
   FILE*fp=fopen("list.txt","rt");
   if (fp==NULL)
   {
      printf("파일 오픈 실패!");
      return -1;
   }
   Student std;
   Student *data;
   len=std.line(fp);

   data=std.alloc(len);
   rewind(fp);

   std.scan(fp,len,data);
   std.print(data,len);

   free(data);
   fclose(fp);
   return 0;
}