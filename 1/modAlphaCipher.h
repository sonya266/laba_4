/**
 * @file modAlphaCipher.h
 * @author Дьякова С.М.
 * @version 1.0
 * @brief Описание класса modAlphaCipher
 * @date 03.12.2024
 * @copyright ИБСТ ПГУ
 */

#pragma once

#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
#include <locale>
#include <codecvt>
#include <vector>
#include <map>
#include <locale.h>

using namespace std;

/** @brief Шифрование методом Гронсфельда
 * @details Ключ устанавливается в конструкторе.
 * Для зашифровывания и расшифровывания предназначены методы encrypt и decrypt.
 * @warning Реализация только для русского языка
 */
class modAlphaCipher
{
private:
    wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; ///< Алфавит по порядку
    map<char, int> alphaNum; ///< Ассоциативный массив "номер по символу"
    vector<int> key; ///< Ключ шифрования

    /**
     * @brief Преобразует строку в вектор целых чисел.
     *
     * @param s Строка для преобразования.
     * @return Вектор целых чисел, представляющий символы строки.
     */
    vector<int> convert(const string& s);

    /**
     * @brief Преобразует вектор целых чисел в строку.
     *
     * @param v Вектор целых чисел для преобразования.
     * @return Строка, представляющая символы вектора.
     */
    string convert(const vector<int>& v);

    /**
     * @brief Проверяет и возвращает действительный ключ шифрования.
     *
     * @param s Строка, представляющая ключ шифрования.
     * @return Проверенный ключ.
     * @throws cipher_error Исключение, если ключ недействителен или пуст.
     */
    string getValidKey(const string& s);

    /**
     * @brief Проверяет и возвращает действительный открытый текст для шифрования.
     *
     * @param s Открытый текст для проверки.
     * @return Проверенный открытый текст.
     * @throws cipher_error Исключение, если открытый текст пуст или содержит недопустимые символы.
     */
    string getValidOpenText(const string& s);

    /**
     * @brief Проверяет и возвращает действительный зашифрованный текст для расшифровки.
     *
     * @param s Зашифрованный текст для проверки.
     * @return Проверенный зашифрованный текст.
     * @throws cipher_error Исключение, если зашифрованный текст пуст или содержит недопустимые символы.
     */
    string getValidCipherText(const string& s);

public:
    /**
     * @brief Запрещает использование конструктора без параметров.
     */
    modAlphaCipher() = delete; ///< Запрет конструктора без параметров

    /**
     * @brief Конструктор для установки ключа шифрования.
     *
     * @param skey Строка, представляющая ключ шифрования.
     * @throws cipher_error Исключение, если ключ слишком слабый.
     */
    modAlphaCipher(const std::string& skey);

    /**
     * @brief Зашифровывает открытый текст.
     *
     * @param open_text Открытый текст для шифрования.
     * @return Зашифрованный текст.
     */
    std::string encrypt(const std::string& open_text);

    /**
     * @brief Расшифровывает зашифрованный текст.
     *
     * @param cipher_text Зашифрованный текст для расшифровки.
     * @return Открытый текст.
     */
    std::string decrypt(const std::string& cipher_text);
};

/**
 * @class cipher_error
 * @brief Исключение для обработки ошибок шифрования.
 *
 * Наследуется от std::invalid_argument и используется для сигнализации о проблемах с ключами или текстами.
 */
class cipher_error : public std::invalid_argument
{
public:
    /**
     * @brief Конструктор исключения с сообщением об ошибке.
     *
     * @param what_arg Сообщение об ошибке.
     */
    explicit cipher_error(const std::string& what_arg) :
        std::invalid_argument(what_arg) {}

    /**
     * @brief Конструктор исключения с сообщением об ошибке.
     *
     * @param what_arg Сообщение об ошибке в виде C-строки.
     */
    explicit cipher_error(const char* what_arg) :
        std::invalid_argument(what_arg) {}
};
