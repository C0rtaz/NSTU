#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>

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
    std::string placeOfBirth;
    date dateOfBirth;
    bool hadPassportBefore;
    std::vector<people*> childrens;
    bool checkCycle(people* target, int step) const;

public:
    static const int MAX_CHECK_DEPTH = 5;
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

    const std::vector<people*>& getChildrens();
    // void setChildrenCounter(int count);

    void addChild(people* child);
};



