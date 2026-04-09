// src/DiffieHellman.cpp
#include "../include/DiffieHellman.h"
#include "../include/MathUtils.h"

DiffieHellman::DiffieHellman(BigInt prime, BigInt generator) {
    p = prime;
    g = generator;
}

void DiffieHellman::generateKeys() {
    // Generate a private key (usually smaller than the prime for speed)
    privateKey = MathUtils::generateRandomBigInt(256); 
    
    // Calculate Public Key: (g^privateKey) mod p
    publicKey = MathUtils::modExp(g, privateKey, p);
}

BigInt DiffieHellman::getPublicKey() const {
    return publicKey;
}

void DiffieHellman::computeSharedSecret(BigInt otherPublicKey) {
    // Calculate Shared Secret: (otherPublicKey^privateKey) mod p
    sharedSecret = MathUtils::modExp(otherPublicKey, privateKey, p);
}

BigInt DiffieHellman::getSharedSecret() const {
    return sharedSecret;
}