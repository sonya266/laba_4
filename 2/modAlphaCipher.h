/**
 * @file modAlphaCipher.h
 * @author Дьякова С.М.
 * @version 1.0
 * @brief Описание класса modAlphaCipher
 * @date 03.12.2024
 * @copyright ИБСТ ПГУ
 */
 
#pragma once
#include <string>
#include <stdexcept>
#include <codecvt>

/** @brief Шифрование методом табличной маршрутной перестановки
 * @details Ключ устанавливается в конструкторе.
 * Для зашифровывания и расшифровывания предназначены методы encrypt и decrypt.
 * @warning Реализация только для русского языка
 */
/**
 * @class modAlphaCipher
 * @brief Класс, реализующий табличный шифр.
 * Класс реализует шифр табличной маршрутной перестановки.
 *
 */
class AlphaCipher
{
private:
    int key; ///< Ключ для шифрования

public:
    AlphaCipher() = delete; ///< Запрет конструктора по умолчанию

    /**
     * @brief Конструктор класса AlphaCipher.
     *
     * Инициализирует объект шифрования с заданным ключом.
     *
     * @param key_str Строка, представляющая ключ шифрования.
     * @throws cipher_error Исключение, если ключ недействителен.
     */
    AlphaCipher(const std::wstring& key_str);

    /**
     * @brief Шифрует открытый текст.
     *
     * Зашифровывает переданный текст с использованием установленного ключа.
     *
     * @param text Открытый текст для шифрования.
     * @return Зашифрованный текст.
     * @throws cipher_error Исключение, если длина ключа превышает половину длины текста.
     */
    std::wstring encrypt(const std::wstring& text);

    /**
     * @brief Расшифровывает зашифрованный текст.
     *
     * Дешифрует переданный зашифрованный текст с использованием установленного ключа.
     *
     * @param encrypted_text Зашифрованный текст для расшифровки.
     * @return Открытый текст.
     */
    std::wstring decrypt(const std::wstring& encrypted_text);

    /**
     * @brief Проверяет и возвращает действительный ключ шифрования.
     *
     * Проверяет, что ключ состоит только из цифр и больше нуля.
     *
     * @param key_str Строка, представляющая ключ шифрования.
     * @return Проверенный ключ.
     * @throws cipher_error Исключение, если ключ недействителен или пуст.
     */
    int getValidKey(const std::wstring& key_str);

    /**
     * @brief Проверяет и возвращает действительный открытый текст для шифрования.
     *
     * Удаляет недопустимые символы и преобразует текст в верхний регистр.
     *
     * @param s Открытый текст для проверки.
     * @return Проверенный открытый текст.
     * @throws cipher_error Исключение, если открытый текст пуст или содержит недопустимые символы.
     */
    std::wstring getValidOpenText(const std::wstring & s);

    /**
     * @brief Проверяет и возвращает действительный зашифрованный текст для расшифровки.
     *
     * Удаляет недопустимые символы и проверяет на наличие звёздочек.
     *
     * @param s Зашифрованный текст для проверки.
     * @return Проверенный зашифрованный текст.
     * @throws cipher_error Исключение, если зашифрованный текст пуст или содержит недопустимые символы.
     */
    std::wstring getValidCipherText(const std::wstring & s);
};

/**
 * @brief Исключение для ошибок шифрования.
 *
 * Наследуется от std::invalid_argument и используется для обработки ошибок, связанных с шифрованием.
 */
class cipher_error : public std::invalid_argument
{
public:
    /**
     * @brief Конструктор исключения cipher_error с сообщением об ошибке.
     *
     * @param what_arg Сообщение об ошибке в виде строки.
     */
    explicit cipher_error(const std::string& what_arg);

    /**
     * @brief Конструктор исключения cipher_error с сообщением об ошибке.
     *
     * @param what_arg Сообщение об ошибке в виде C-строки.
     */
    explicit cipher_error(const char* what_arg);
};
