#include "ComplexConcept.h"
#include <iostream>
#include <type_traits>

// Реализация шаблонной функции. Для демонстрации размещаем здесь
template <ComplexConcept T>
void process(const T& obj) {
    long hash_value = obj.hash();
    std::string str_value = obj.toString();
    
    std::cout << "Processing object: " << str_value << std::endl;
    std::cout << "Hash value: " << hash_value << std::endl;
    std::cout << "Type has virtual destructor: " 
              << (std::has_virtual_destructor<T>::value ? "Yes" : "No") << std::endl;
}

// Тестовая функция для проверки пригодности типа к использованию с концептом
template <typename T>
void testType(const T& obj, const std::string& typeName) {
    std::cout << "\n========= Testing type: " << typeName << " =========\n";
    
    // Проверяем наличие метода hash()
    std::cout << "Has hash() method: ";
    try {
        long hash_value = obj.hash();
        std::cout << "Yes, returns: " << hash_value << std::endl;
    } catch (...) {
        std::cout << "No or exception thrown" << std::endl;
    }
    
    // Проверяем наличие метода toString()
    std::cout << "Has toString() method: ";
    try {
        std::string str_value = obj.toString();
        std::cout << "Yes, returns: \"" << str_value << "\"" << std::endl;
    } catch (...) {
        std::cout << "No or exception thrown" << std::endl;
    }
    
    // Проверяем отсутствие виртуального деструктора
    std::cout << "Has virtual destructor: " 
              << (std::has_virtual_destructor<T>::value ? "Yes (не соответствует требованиям)" : "No (соответствует требованиям)") 
              << std::endl;
              
    // Проверяем соответствие концепту ComplexConcept
    std::cout << "Matches ComplexConcept: " 
              << (ComplexConcept<T> ? "Yes" : "No") 
              << std::endl;
}

int main() {
    std::cout << "======= Demonstration of ComplexConcept =======\n";
    
    // Тестируем ValidType
    ValidType valid;
    testType(valid, "ValidType");
    
    // Тестируем InvalidType
    InvalidType invalid;
    testType(invalid, "InvalidType");
    
    // Демонстрируем работу функции process с ValidType
    std::cout << "\n======= Using process() with ValidType =======\n";
    process(valid);     // OK
    
    return 0;
}