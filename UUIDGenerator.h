#pragma once

#include<iostream>
#include <chrono>
#include <random>
#include <string>

class UUIDGenerator
{

public:
	static int generate_uuid() {
	
		auto now = std::chrono::system_clock::now();
		auto epoch = now.time_since_epoch();
		auto seconds = std::chrono::duration_cast<std::chrono::seconds>(epoch);
		auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(epoch - seconds);

		
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(0, 9);
		int random_number = dis(gen);

		int uuid_hash = std::hash<int>{}(seconds.count() + microseconds.count() + random_number);

		return uuid_hash;
	}
};
