#include <iostream>
#include <string>
#include "modAlphaCipher.h"

void check(string Text, int key) {
    try {
        string cipherText;
        string decryptedText;
        modCipher cipher(key, Text);
        cipherText = cipher.encryption(Text);
        decryptedText = cipher.transcript(cipherText, Text);
        cout << "Ключ = " << key << endl;
        cout << Text << endl;
        cout << cipherText << endl;
        cout << decryptedText << endl;
    } catch(const cipher_error & e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
}

int main() {
    try {
        check("Privet", 2);
        check("", 2); 
        check("1323123142", 2);
        check("Privet", 22333);
    } catch (const cipher_error& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
    return 0;
}
