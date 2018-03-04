/**
 * @file aes_implementation_test.cc
 * @date 28/02/2018
 *
 * @breif This file will contain test methods to verify the functionality of my implementaiton of the AES Algorithm
 *
 * @version 0.01
 * @author Jacob Powell
 *
 */

#include "aes_implementation.h"

#include <iostream>
#include <iomanip>


void outputHexArray(uint8_t array[]);

void test_aes_128(){
    AESImplementation aes(AES128);

    uint8_t key[] = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15,
                    0x88, 0x09, 0xcf, 0x4f, 0x3c};
    uint8_t plaintext[] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99,
                    0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff};
    uint8_t ciphertext[16];

    aes.encrypt(plaintext, ciphertext, key);

    //outputHexArray(ciphertext);
    std::cout << "END" << std::endl;

}

void outputHexArray(uint8_t array[]){
    for(int i = 0; i < 16; i++){
        std::cout << std::hex << std::setfill('0') << std::setw(2) << unsigned(array[i]);
    }
    std::cout << std::endl;
}

int main(){
    test_aes_128();
}