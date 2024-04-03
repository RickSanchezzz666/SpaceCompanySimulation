#define CATCH_CONFIG_RUNNER
#include <catch2/catch_all.hpp>

#include <iostream>
#include <chrono>
#include <string>
#include <thread>

int main(int argc, char* argv[]) {

    std::cout << "Started running test cases..\n";

    auto startParsing = std::chrono::steady_clock::now();

    int result = Catch::Session().run(argc, argv);

    auto endParsing = std::chrono::steady_clock::now();

    auto parsingDurationS = std::chrono::duration_cast<std::chrono::seconds>(endParsing - startParsing);
    auto parsingDurationMl = std::chrono::duration_cast<std::chrono::milliseconds>(endParsing - startParsing);

    std::cout << "Tests done in " + std::to_string(parsingDurationS.count()) + "." + std::to_string(parsingDurationMl.count()) + " s.\n";

    return result;
}

//SCENARIO INSTANCE
// 
//SCENARIO("vector can be sized and resized") {
//    GIVEN("An empty vector") {
//        auto v = std::vector<std::string>{};
//
//        // Validate assumption of the GIVEN clause
//        THEN("The size and capacity start at 0") {
//            REQUIRE(v.size() == 0);
//            REQUIRE(v.capacity() == 0);
//        }
//
//        // Validate one use case for the GIVEN object
//        WHEN("push_back() is called") {
//            v.push_back("hullo");
//
//            THEN("The size changes") {
//                REQUIRE(v.size() == 1);
//                REQUIRE(v.capacity() >= 1);
//            }
//        }
//    }
//}