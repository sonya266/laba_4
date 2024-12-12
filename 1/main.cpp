#include "modAlphaCipher.h"

void check(const string& Text, const string& key)
{
    try {
        modAlphaCipher cipher(key);
        string cipherText = cipher.encrypt(Text);
        string decryptedText = cipher.decrypt(cipherText);
        // ... Вывод текста и ключа
        if(Text == decryptedText) {
            cout << "Ok\n";
        } else {
            cout << "Err\n";
        }
    } catch(const cipher_error& e) {
        cout << "Ошибка: " << e.what() << endl;
    }
}

int main()
{
    check("ПРИВЕТ", "ПРИВЕЕЕТ");
    check("ПРИВЕТ", "ПРИВ");
    check("ПРИВЕТ", "!ПРИВ!");
    check("ПРИВЕТ", "11032001");
    check("1234567890", "NO");
    check("ПРИВЕТ", "ПОКА");
    check("123456789", "ПРИВ");
    check("КАК ДЕЛА", "АБВГ");
}
