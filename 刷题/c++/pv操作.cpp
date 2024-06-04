//消费者生产者问题
semaphore mutex = 1, empty = n, apple = 0, orange = 0

dad() {

	while (1) {
		P(empty);
		P(mutex);
		V(mutex);
		放入一个水果
		if (放入苹果)
			V(apple)
			else
				V(orange)

			}
}

daughter{

	while (1) {
		P(apple);
		P(mutex);
		拿一个苹果
		V(mutex);
		V(empty);
	}
}

son{

	while (1) {
		P(orange);
		P(mutex);
		拿一个橘子
		V(mutex);
		V(empty);
	}
}
