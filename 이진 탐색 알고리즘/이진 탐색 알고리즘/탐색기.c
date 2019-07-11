int binsch(int *test, int len, int target, int first, int last) {
	int mid;

	mid = (first + last) / 2;
	if (*(test + mid) == target)
		return mid;

	else if (*(test + mid) < target)
		first = mid + 1;       //first = mid라 하면 반복 오류 난다. mid가 아니라는 것이 확정 났으니 mid를 제외시킨다
	else
		last = mid - 1;
	
	if (first <= last)
		binsch(test, len, target, first, last);      //재귀함수를 이용. 아니면 함수의 인자에서 first와 last 값을 없애고 함수 안에서 각각
	else                                             //0과 len-1로 초기화 해준 다음 while (first <= last) 를 해주면 된다. 
		return -1;
}

