#include "people.h"

people::people() 
    : FIO(""), age(0), doc(Birth_sertificate), gender(Male), 
      docSeries(0), docNumber(0), childrenCounter(0), 
      placeOfBirth(""), dateOfBirth{1, 1, 2000}, hadPassportBefore(false) {}




people::people(std::string fio, int age, people* mot, people* fat, Document d, Gender g, int docSer, int docNum, std::string place, date birth)
    : FIO(fio), age(age), gender(g), docSeries(docSer), docNumber(docNum), 
      placeOfBirth(place), dateOfBirth(birth), childrenCounter(0), 
      mother(nullptr), father(nullptr) 
{

    hadPassportBefore = (d == Passport);

    if (d == Passport && age < 14) {
        std::cout << "Предупреждение [" << FIO << "]: Паспорт нельзя выдать лицу младше 14 лет. Установлено Свидетельство о рождении.\n";
        this->doc = Birth_sertificate;
    } else {
        this->doc = d;
    }

    setMother(mot);
    setFather(fat);
}

// ФИО
std::string people::getFIO() const { return FIO; }
void people::setFIO(const std::string& fio) { FIO = fio; }

// Пол (только возврат)
Gender people::getGender() const { return gender; }

// Серия и номер документа
int people::getDocSeries() const { return docSeries; }
int people::getDocNumber() const { return docNumber; }
void people::setDocDetails(int series, int number) {
    docSeries = series;
    docNumber = number;
}


Document people::getDocType() const { return doc; }
void people::setDocType(Document d) {
    if (d == Birth_sertificate && hadPassportBefore) {
        std::cout << "Ошибка [" << FIO << "]: Нельзя указать свидетельство о рождении, так как человек уже имел паспорт!\n";
        return;
    }
    if (d == Passport && age < 14) {
        std::cout << "Ошибка [" << FIO << "]: Паспорт выдается только с 14 лет (текущий возраст: " << age << ").\n";
        return;
    }

    doc = d;
    if (d == Passport) {
        hadPassportBefore = true;
    }
}


std::string people::getPlaceOfBirth() const { return placeOfBirth; }
date people::getDateOfBirth() const { return dateOfBirth; }
int people::getAge() const { return age; }


people* people::getMother() const { return mother; }
void people::setMother(people* mot) {
    if (mot == nullptr) {
        mother = nullptr;
        return;
    }
    if (mot == this) {
        std::cout << "Ошибка [" << FIO << "]: Нельзя быть матерью самому себе!\n";
        return;
    }
    if (mot->getGender() != Female) {
        std::cout << "Ошибка [" << FIO << "]: Матерью может быть только женщина!\n";
        return;
    }
    mother = mot;
}

people* people::getFather() const { return father; }
void people::setFather(people* fat) {
    if (fat == nullptr) {
        father = nullptr;
        return;
    }
    if (fat == this) {
        std::cout << "Ошибка [" << FIO << "]: Нельзя быть отцом самому себе!\n";
        return;
    }
    if (fat->getGender() != Male) {
        std::cout << "Ошибка [" << FIO << "]: Отцом может быть только мужчина!\n";
        return;
    }
    father = fat;
}

int people::getChildrenCounter() const { return childrenCounter; }
void people::setChildrenCounter(int count) {
    if (count < 0) {
        std::cout << "Ошибка: Количество детей не может быть отрицательным!\n";
        return;
    }
    childrenCounter = count;
}