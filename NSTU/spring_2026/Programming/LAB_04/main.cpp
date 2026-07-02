#include <iostream>
#include "people.h"

int main(){
    try {
        // 1. Создаем корректную цепочку родственников
        // Дата рождения в формате: {день, месяц, год}
        people grandFa("Иванов Иван Петрович", 70, nullptr, nullptr, Passport, Male, 1111, 111111, "Москва", {10, 5, 1956});
        people father("Иванов Алексей Иванович", 45, nullptr, &grandFa, Passport, Male, 2222, 222222, "Москва", {15, 8, 1981});
        people son("Иванов Никита Алексеевич", 20, nullptr, &father, Passport, Male, 3333, 333333, "СПб", {20, 12, 2006});

        std::cout << " Успешно создано базовое древо: Дедушка -> Отец -> Сын.\n";
        std::cout << "Количество детей у Дедушки: " << grandFa.getChildrens().size() << " (ожидается 1)\n";
        std::cout << "Количество детей у Отца: " << father.getChildrens().size() << " (ожидается 1)\n";

        std::cout << "\n--- ТЕСТ 1: Попытка добавить ребенка, который старше родителя ---\n";
        try {
            // Сын (20 лет) пытается усыновить Дедушку (70 лет)
            son.addChild(&grandFa);
        } catch (const std::invalid_argument& e) {
            std::cout << " Перехвачено ожидаемое исключение (Возраст): " << e.what() << "\n";
        }

        std::cout << "\n--- ТЕСТ 2: Попытка стать родителем самому себе ---\n";
        try {
            father.addChild(&father);
        } catch (const std::invalid_argument& e) {
            std::cout << " Перехвачено ожидаемое исключение (Само-родство): " << e.what() << "\n";
        }

        std::cout << "\n--- ТЕСТ 3: Нарушение правил по полу родителей ---\n";
        try {
            // Пытаемся установить Дедушку в качестве Матери
            son.setMother(&grandFa);
        } catch (const std::invalid_argument& e) {
            std::cout << " Перехвачено ожидаемое исключение (Пол матери): " << e.what() << "\n";
        }

        std::cout << "\n--- ТЕСТ 4: Нарушение правил выдачи документов ---\n";
        try {
            people baby("Иванов Малыш", 5, nullptr, nullptr, Birth_sertificate, Male, 0, 0, "Новгород", {1, 1, 2021});
            // Пытаемся установить 5-летнему ребенку Паспорт
            baby.setDocType(Passport); 
        } catch (const std::domain_error& e) {
            std::cout << " Перехвачено ожидаемое исключение (Паспорт < 14 лет): " << e.what() << "\n";
        }

        std::cout << "\n--- ТЕСТ 5: Проверка защиты от дублирования ---\n";
        try {
            std::cout << "Текущее кол-во детей у Отца: " << father.getChildrens().size() << "\n";
            father.addChild(&son); // Пробуем добавить Сына еще раз
            std::cout << "Кол-во детей у Отца после повторного добавления: " << father.getChildrens().size() << " (должно остаться 1)\n";
        } catch (const std::exception& e) {
            std::cout << " Ошибка: дублирование вызвало падение вместо игнорирования: " << e.what() << "\n";
        }
        std::cout << "\n--- ТЕСТ 6: Обнаружение циклической зависимости (Петли) ---\n";
        try {
            // Пытаемся зациклить древо через публичный метод addChild.
            // Мы просим Дедушку добавить самого себя или Отца добавить Дедушку.
            // Вызов addChild сам внутри себя запустит приватный checkCycle!
            father.addChild(&grandFa); 
            
        } catch (const std::runtime_error& e) {
            std::cout << " Перехвачено ожидаемое исключение (Цикл через addChild): " << e.what() << "\n";
        } catch (const std::invalid_argument& e) {
            std::cout << " На этом этапе сработал контроль возраста (тоже защита): " << e.what() << "\n";
        }

    } catch (const std::exception& e) {
        std::cerr << "Критическая непредвиденная ошибка в основном потоке: " << e.what() << std::endl;
    }

    std::cout << "\n=== ТЕСТИРОВАНИЕ ЗАВЕРШЕНО ===\n";
    

    return 0;
}