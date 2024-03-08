#pragma once

#include <iostream>
#include <thread>
#include <atomic>


class Thread {
private:
	std::atomic<bool> __isRunning;
	std::thread __thread;
public:
	template <class Function, class... Args>
	Thread(Function &&func, Args &&...args) : __isRunning(false) {
		if (!__isRunning) {
			__isRunning = true;
			__thread = std::thread(
				std::forward<Function>(func),
				std::forward<Args>(args)...);
			std::cout << "Thread started...\n";
		}
	};

	~Thread() {
		if (__isRunning) {
			__isRunning = false;
			__thread.join();
			std::cout << "Thread stopped...\n";
		}
	}
};