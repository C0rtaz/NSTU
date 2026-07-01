#include <iostream>
#include <string>

typedef enum gender{
    Male, Female
}Gender;

typedef enum docs{
    Passport, Birth_sertificate
}Document;

typedef struct dateOfBirth{
    int day, month, year;
}date;

class people
{
private:
    std::string FIO;
    int age;
    people* mother = nullptr;
    people* father = nullptr;
    Document doc;
    Gender gender;
    int docSeries, docNumber;
    int childrenCounter;
    std::string placeOfBirth;
    date dateOfBirth;
    bool hadPassportBefore;
public:
    people();
    people(std::string fio, int age, people* mot, people* fat, Document d, Gender g, int docSer, int docNum, std::string place, date birth);

    std::string getFIO() const;
    void setFIO(const std::string& fio);

    Gender getGender() const; 

    int getDocSeries() const;
    int getDocNumber() const;
    void setDocDetails(int series, int number); 

    Document getDocType() const;
    void setDocType(Document d);

    std::string getPlaceOfBirth() const; 
    date getDateOfBirth() const;         
    int getAge() const;                  

    people* getMother() const;
    void setMother(people* mot);

    people* getFather() const;
    void setFather(people* fat);

    int getChildrenCounter() const;
    void setChildrenCounter(int count);
};



// 10. Человек

// Необходимо разработать класс Человек для информационной системы МВД РФ, позволяющий хранить информацию о человеке,
// включая непосредственные родственные связи – родителей и детей человека.
// В качестве удостоверения личности используется паспорт для людей старше 14 лет и свидетельство о рождении для людей младше 14 лет.
// Если человек уже имел паспорт, свидетельство о рождении нельзя указать в качестве типа удостоверения личности.
// Нельзя быть родителем самого себя. В качестве матери может быть только женщина, отца – мужчина.
// Поля: ФИО, пол, серия и номер удостоверения личности, тип удостоверения личности (свидетельство о рождении, паспорт),
// место рождения, дата рождения, мать, отец, количество детей.
// Методы: конструктор со всеми полями, кроме количества детей;  возврат и установка ФИО, возврат пола, 
//возврат и установка серии и номера удостоверения личности, возврат и установка типа удостоверения личности, возврат места рождения, 
//возврат даты рождения, возврат возраста, возврат и установка матери, возврат и установка отца, установка и возврат количества детей.