// main.cpp
#include <iostream>
#include "include/MathUtils.h"
#include "include/DiffieHellman.h"

int main() {
    std::cout << "--- Diffie-Hellman Key Exchange Simulation ---\n\n";

    // 1. Generate Public Parameters
    std::cout << "[System] Generating a 512-bit prime (this might take a few seconds)...\n";
    BigInt p = MathUtils::generatePrime(512); 
    BigInt g = 2; // 2 is a very common generator used in practice

    std::cout << "[System] Prime (p): " << p << "\n";
    std::cout << "[System] Generator (g): " << g << "\n\n";

    // 2. Initialize Alice and Bob with the public parameters
    DiffieHellman alice(p, g);
    DiffieHellman bob(p, g);

    // 3. Generate Keys
    std::cout << "Alice generating her private and public keys...\n";
    alice.generateKeys();
    std::cout << "Bob generating his private and public keys...\n\n";
    bob.generateKeys();

    // 4. Exchange Public Keys & Compute Shared Secret
    std::cout << "Swapping public keys over the 'network'...\n";
    alice.computeSharedSecret(bob.getPublicKey());
    bob.computeSharedSecret(alice.getPublicKey());

    // 5. Verify the math works
    std::cout << "\n--- Final Results ---\n";
    std::cout << "Alice's Shared Secret: \n" << alice.getSharedSecret() << "\n\n";
    std::cout << "Bob's Shared Secret: \n" << bob.getSharedSecret() << "\n\n";

    if (alice.getSharedSecret() == bob.getSharedSecret()) {
        std::cout << "SUCCESS! Both parties share the exact same secret key.\n";
    } else {
        std::cout << "ERROR! The keys do not match.\n";
    }

    return 0;
}