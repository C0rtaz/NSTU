#include "people.h"

people::people() 
    : FIO(""), age(0), doc(Birth_sertificate), gender(Male), 
      docSeries(0), docNumber(0), placeOfBirth(""), dateOfBirth{1, 1, 2000}, hadPassportBefore(false) {}




people::people(std::string fio, int age, people* mot, people* fat, Document d, Gender g, int docSer, int docNum, std::string place, date birth)
    : FIO(fio), age(age), gender(g), docSeries(docSer), docNumber(docNum), 
      placeOfBirth(place), dateOfBirth(birth),  
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

bool people::checkCycle(people* target, int step) const{
    if(step >= MAX_CHECK_DEPTH){
        return false;
    }


    for (const people* child : childrens) {

        if (child == target) {
            return true; // Цикл обнаружен!
        }

        if (child->checkCycle(target, step + 1)) {
            return true; 
        }
    }

    return false;
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
        throw std::domain_error("Нельзя указать свидетельство о рождении, так как человек уже имел паспорт!");
    }
    if (d == Passport && age < 14) {
        throw std::domain_error("Паспорт выдается только с 14 лет.");
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
        throw std::invalid_argument("Нельзя быть матерью самому себе");
    }
    if (mot->getGender() != Female) {
        throw std::invalid_argument("Матерью может быть только женщина");
    }
    mother = mot;
    mother->addChild(this);
}

people* people::getFather() const { return father; }
void people::setFather(people* fat) {
   if (fat == nullptr) {
        father = nullptr;
        return;
    }
    if (fat == this) {
        throw std::invalid_argument("Нельзя быть отцом самому себе");
    }
    if (fat->getGender() != Male) {
        throw std::invalid_argument("Отцом может быть только мужчина");
    }
    father = fat;
    father->addChild(this);
}




void people::addChild(people* child)
{
    if(child == this){
        throw std::invalid_argument("Человек не может быть родителем самого себя.");
    }
    if(child->age >= this->age - 18){
        throw std::invalid_argument("Ребёнок должен быть младше своих родителей.");
    }

    if(std::find(childrens.begin(), childrens.end(), child) != childrens.end()){
        throw std::invalid_argument("Ребёнок уже был добавлен.");
    }

    if (child->checkCycle(this, 1)) {
        throw std::runtime_error("Обнаружена циклическая зависимость.");
    }

    childrens.push_back(child);
}

const std::vector<people*>& people::getChildrens() { return childrens; }


// int people::getChildrenCounter() const { return childrenCounter; }
// void people::setChildrenCounter(int count) {
//     if (count < 0) {
//         std::cout << "Ошибка: Количество детей не может быть отрицательным!\n";
//         return;
//     }
//     childrenCounter = count;
// }