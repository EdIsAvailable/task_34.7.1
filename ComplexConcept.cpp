
#include "ComplexConcept.h"
#include <iostream>

// Реализация методов для ValidType
long ValidType::hash() const {
    return 42;
}

std::string ValidType::toString() const {
    return "ValidType";
}

// Реализация методов для InvalidType
long InvalidType::hash() const {
    return 42;
}

std::string InvalidType::toString() const {
    return "InvalidType";
}

// Реализация шаблонной функции process (так как это шаблон, реализация обычно в заголовочном файле)
// Но пример реализации для конкретного типа можно добавить здесь
void processValidType(const ValidType& obj) {
    // Используем переменные, чтобы избежать предупреждений
    long hash_value = obj.hash();
    std::string str_value = obj.toString();
    
    // Примерная обработка полученных значений (чтобы избежать предупреждений о неиспользуемых переменных)
    if (hash_value > 0) {
        std::cout << "Processing: " << str_value << " with hash: " << hash_value << std::endl;
    }
}