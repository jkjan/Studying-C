int binsch(int *test, int len, int target, int first, int last) {
	int mid;

	mid = (first + last) / 2;
	if (*(test + mid) == target)
		return mid;

	else if (*(test + mid) < target)
		first = mid + 1;       //first = mid�� �ϸ� �ݺ� ���� ����. mid�� �ƴ϶�� ���� Ȯ�� ������ mid�� ���ܽ�Ų��
	else
		last = mid - 1;
	
	if (first <= last)
		binsch(test, len, target, first, last);      //����Լ��� �̿�. �ƴϸ� �Լ��� ���ڿ��� first�� last ���� ���ְ� �Լ� �ȿ��� ����
	else                                             //0�� len-1�� �ʱ�ȭ ���� ���� while (first <= last) �� ���ָ� �ȴ�. 
		return -1;
}

