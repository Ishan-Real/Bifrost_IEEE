// include/DiffieHellman.h
#pragma once
#include "BigInt.h"

class DiffieHellman {
private:
    BigInt p;            // Shared prime number
    BigInt g;            // Shared generator
    BigInt privateKey;   // Secret key (never shared)
    BigInt publicKey;    // Public key (sent over network)
    BigInt sharedSecret; // The final matching key

public:
    DiffieHellman(BigInt prime, BigInt generator);
    
    void generateKeys();
    BigInt getPublicKey() const;
    void computeSharedSecret(BigInt otherPublicKey);
    BigInt getSharedSecret() const;
};