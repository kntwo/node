//����������������
semaphore mutex = 1, empty = n, apple = 0, orange = 0

dad() {

	while (1) {
		P(empty);
		P(mutex);
		V(mutex);
		����һ��ˮ��
		if (����ƻ��)
			V(apple)
			else
				V(orange)

			}
}

daughter{

	while (1) {
		P(apple);
		P(mutex);
		��һ��ƻ��
		V(mutex);
		V(empty);
	}
}

son{

	while (1) {
		P(orange);
		P(mutex);
		��һ������
		V(mutex);
		V(empty);
	}
}
