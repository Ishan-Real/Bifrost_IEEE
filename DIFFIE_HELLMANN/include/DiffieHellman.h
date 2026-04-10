// include/DiffieHellman.h
#pragma once //Includes the file only once during compilation
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
    //Generates private and public keys
    void generateKeys();
    //Returns public key to be sent to other party
    BigInt PublicKey() const;
    //Computes shared secret using other party's public key and their own private key
    void computeSharedSecret(BigInt otherPublicKey);
    //Returns computed shared key
    BigInt getSharedSecret() const;
};