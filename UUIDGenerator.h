#pragma once

#include <iostream>
#include <chrono>
#include <cstdlib>
#include <string>

class UUIDGenerator
{
public:
    static int generate_uuid() {
        auto now = std::chrono::system_clock::now();
        auto epoch = now.time_since_epoch();

        uint64_t total_microseconds = epoch.count();

        // Use FNV-1a hash function
        const uint64_t FNV_offset_basis = 14695981039346656037ULL;
        const uint64_t FNV_prime = 1099511628211ULL;
        uint64_t hash = FNV_offset_basis;

        // Hash the total microseconds
        for (int i = 0; i < 8; ++i) {
            hash ^= (total_microseconds & 0xff);
            hash *= FNV_prime;
            total_microseconds >>= 8;
        }

        // Generate a random number using rand()
        int random_number = rand() % 10;

        // Hash the random number
        hash ^= random_number;
        hash *= FNV_prime;

        return static_cast<int>(hash);
    }
};
