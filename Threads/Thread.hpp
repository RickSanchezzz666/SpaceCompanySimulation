#pragma once

#include <iostream>
#include <thread>
#include <atomic>


class Thread {
private:
	std::thread __thread;
public:
	std::atomic<bool> isRunning;

	Thread() : isRunning(false) {};

	template <class Function, class... Args>
	void createThread(Function &&func, Args &&...args) {
		if (!isRunning) {
			isRunning = true;
			__thread = std::thread(
				std::forward<Function>(func),
				std::forward<Args>(args)...);
			std::cout << "Thread started...\n";
		}
	};

	~Thread() {
		if (isRunning) {
			isRunning = false;
			__thread.join();
			std::cout << "Thread stopped...\n";
		}
	}
};