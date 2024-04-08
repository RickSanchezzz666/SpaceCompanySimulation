#include <catch2/catch_all.hpp>

#define TEST_NAME "[Thread]"

#include <iostream>

#include "../TestRunner.hpp"

#include "../../../Threads/Thread.hpp"

TEST_CASE("Thread creation and destruction", TEST_NAME) {
	printStartTest(TEST_NAME);

	Thread* thread = new Thread();

	REQUIRE_FALSE(thread->isRunning.load());

	thread->createThread([]() {});

	REQUIRE(thread->isRunning.load());

	thread->~Thread();

	REQUIRE_FALSE(thread->isRunning.load());

	delete thread;
}

TEST_CASE("Thread creation twice", TEST_NAME) {
	printStartTest(TEST_NAME);

	Thread* thread = new Thread();

	std::thread::id initialThreadID;
	std::thread::id secondThreadID;

	thread->createThread([&initialThreadID]() {
		initialThreadID = std::this_thread::get_id();
	});

	thread->~Thread();

	thread->createThread([&secondThreadID]() {
		secondThreadID = std::this_thread::get_id();
	});

	thread->~Thread();

	REQUIRE_FALSE(initialThreadID == secondThreadID);

	delete thread;
}

void emptyFunction(int& arg) {
	arg = 8;
}

TEST_CASE("Thread creation with function", TEST_NAME) {
	printStartTest(TEST_NAME);

	Thread* thread = new Thread();

	int testNumber = 6;

	REQUIRE_FALSE(thread->isRunning.load());

	thread->createThread([&]() {
		emptyFunction(testNumber);
	});

	REQUIRE(thread->isRunning.load());

	thread->~Thread();

	REQUIRE_FALSE(thread->isRunning.load());

	REQUIRE(testNumber == 8);

	delete thread;
}

TEST_CASE("Immidiate Thread creation twice is not available", TEST_NAME) {
	printStartTest(TEST_NAME);

	Thread* thread = new Thread();

	REQUIRE_FALSE(thread->isRunning.load());

	thread->createThread([]() {});

	REQUIRE(thread->isRunning.load());

	thread->createThread([]() {});

	REQUIRE(thread->isRunning.load());

	thread->~Thread();

	REQUIRE_FALSE(thread->isRunning.load());

	delete thread;
}