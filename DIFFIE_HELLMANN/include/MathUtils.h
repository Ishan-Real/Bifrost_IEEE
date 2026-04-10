// include/MathUtils.h
#pragma once
#include "BigInt.h"

class MathUtils {
public:
    // Calculates (base^exp) % mod quickly using Square-and-Multiply Algorithm
    static BigInt modExp(BigInt base, BigInt exp, BigInt mod);

    // Probabilistic primality test (Miller-Rabin)
    //n is the number to test, k is the number of rounds 
    static bool isPrime(BigInt n, int k = 10);

    // Generates a random BigInt of an approximate bit length
    static BigInt generateRandomBigInt(int bitLength);

    // Continuously generates random numbers until it finds a prime
    static BigInt generatePrime(int bitLength);
};