#include <stdio.h>

int main() {
	FILE*scr = fopen("01 It's A Long Way To The Top (If You Wanna Rock 'N' Roll).mp3", "rb");
	FILE*des = fopen("howboutthis.mp3", "wb");
	char buf[20];
	int readCnt;

	if (scr == NULL || des == NULL) {
		puts("파일오픈 실패!");
		return -1;
	}

	while (1)
	{
		readCnt = fread((void*)buf, 1, sizeof(buf), scr);   //scr의 바이너리를 1곱하기 buf크기(20)만큼 복사 해서 buf에 저장
		fwrite((void*)buf, 1, sizeof(buf), des);    //buf를 buf의 size 곱하기 1만큼 des에 저장

		if (readCnt < sizeof(buf)) { //마지막 남은 바이트 읽어들이기 꼭 필요 (20만큼 못 읽었을 때. 만약 121인데 20만큼 6번 읽고)
			if (feof(scr) != 0) {		//파일 끝인 경우 0아닌 값 반환	    	남은 데이터가 1번일 때
				fwrite((void*)buf, 1, readCnt, des);   //남은 만큼(readCnt 크기만큼) 쓰기
				puts("파일복사 완료");
				break;
			}
			else
				puts("파일복사 실패");

			break;
		}
		
	}	

	fclose(scr);
	fclose(des);
	return 0;
}