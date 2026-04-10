// src/MathUtils.cpp
#include "../include/MathUtils.h"
#include <random>
#include <string>

// --- MODULAR EXPONENTIATION ---
BigInt MathUtils::modExp(BigInt base, BigInt exp, BigInt mod) {
    BigInt result = 1;
    base = base % mod;

    while (exp > 0) {
        // If exp is odd, multiply base with result
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        // Bitwise shift right by 1 (divide by 2)
        exp = exp / 2; 
        base = (base * base) % mod;
    }
    return result;
}

// --- RANDOM BIGINT GENERATION ---
BigInt MathUtils::generateRandomBigInt(int bitLength) {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> zerotoNine(0, 9);
    std::uniform_int_distribution<> onetoNine(1, 9);

    // Approximate decimal digits needed for the given bit length
    int length = (bitLength * 3) / 10; 
    
    // Build a giant number as a string first to avoid standard C++ limits
    std::string numStr = ""; 
    for(int i=0;i<=length;i++){
        if(i==0){
            int firstRoll = onetoNine(generator);
            numStr = numStr + std::to_string(firstRoll);//To avoid zeros in the beginning
        }
        else{
            int roll = zerotoNine(generator);
            numStr = numStr + std::to_string(roll);
        }
    }
    return BigInt(numStr);
}

// --- MILLER-RABIN PRIMALITY TEST ---
bool MathUtils::isPrime(BigInt n, int k) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0) return false;

    // Find d such that n-1 = 2^r * d
    BigInt oddpart = n - 1;
    while (oddpart % 2 == 0) {
        oddpart /= 2;
    }

    // Run the test k times
    for (int i = 0; i < k; ++i) {
        // Generate a random base 'a' in range [2, n-2]
        BigInt a = 2 + (generateRandomBigInt(32) % (n - 3));
        BigInt x = modExp(a, oddpart, n);

        if (x == 1 || x == n - 1) continue;

        bool passed = false;
        BigInt tempD = oddpart;
        while (tempD != n - 1) {
            x = (x * x) % n;
            tempD *= 2;

            if (x == 1) return false;
            if (x == n - 1) {
                passed = true;
                break;
            }
        }
        if (!passed) return false;
    }
    return true;
}

// --- PRIME GENERATION ---
BigInt MathUtils::generatePrime(int bitLength) {
    BigInt candidate;
    bool PrimeFound = false;
    while (PrimeFound == false) {
        candidate = generateRandomBigInt(bitLength);
        // Make sure it's odd
        if (candidate % 2 == 0) {
            candidate += 1;
        } 
        
        if (isPrime(candidate)==true) {
            PrimeFound = true;
        }
        return candidate;
    }
}