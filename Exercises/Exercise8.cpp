//Треба да дефинирате класи за работа со професори и асистенти и алокација на предавања и аудиториски вежби.
//За таа цел дефинирајте класа Teacher која содржи податочни членки: id (долг цел број), fullName (стринг).
//Дополнително додадете виртуелни функции членки print и calculateClassAllocations.
//Напишете класа ClassAllocation која содржи податочни членки: numberOfLectures и numberOfExercises (реални броеви). Додадете и виртуелна print функција.
//Крајно, дефинирајте класи Professor и Assistant кои се изведени од класите Teacher и ClassAllocation.
//Следните правила ги условуваат професорите:
//Не смее да се дозволи да се креира објект Professor ако бројот на предавања не е позитивен.
//Во овој случај да се фрли исклучок InvalidProfessorAllocationException со порака Professor doesn't have lectures.;
//функцијата calculateClassAllocations го пресметува бројот на часови така што се множи бројот на предавања со 2 и се додава бројот на вежби;
//функцијата print треба да ги повика соодветните print функции од базните класи. Печатењето е во следниот формат:
//Professor:
//<fullName> <id>
//Lectures: <numberOfLectures>; Exercises: <numberOfExercises>
//Следните правила ги условуваат асистентите:
//Не смее да се дозволи да се креира објект Assistant ако бројот на вежби не е позитивен.
//Во овој случај да се фрли исклучок InvalidAssistantAllocationException со порака Assistant doesn't have exercises.;
//Не смее да се дозволи да се креира објект Assistant ако бројот на предавања е позитивен.
//Во овој случај да се фрли исклучок InvalidAssistantAllocationException со порака Assistant shouldn't have lectures.;
//функцијата calculateClassAllocations го пресметува бројот на часови така што се множи бројот на вежби со 2;
//функцијата print треба да ги повика соодветните print функции од базните класи. Печатењето е во следниот формат:
//Assistant:
//<fullName> <id>
//Lectures: <numberOfLectures>; Exercises: <numberOfExercises>
//Да се дефинира глобална функција Teacher* mostAllocatedTeacher(Teacher** teachers, int n) која го враќа професорот/асистентот со најголем број на часови.
//Од тастатура се внесува прво бројот на професори, а потоа потребните информации за сите професори. Аналогно се внесуваат податоците и за асистентите.
//Потребно е да направите промена во main функцијата за да се справите со фрлените исклучоци од објектите од тип Assistant.
//You need to define classes for working with professors and assistants and allocation of lectures and practical exercises.
//For this purpose, define a class Teacher which contains data members: id (long integer), fullName (string).
//        Additionally, add virtual member functions print and calculateClassAllocations.
//Write a class ClassAllocation which contains data members: numberOfLectures and numberOfExercises (floating point numbers). Also, add a virtual print function.
//Finally, define classes Professor and Assistant which are derived from the classes Teacher and ClassAllocation.
//The following rules apply to professors:
//It is not allowed to create a Professor object if the number of lectures is not positive. In this case,
//throw an exception InvalidProfessorAllocationException with the message Professor doesn't have lectures.;
//The function calculateClassAllocations calculates the number of classes by multiplying the number of lectures by 2 and adding the number of exercises;
//The function print should call the appropriate print functions from the base classes. The printing format is as follows:
//Professor:
//<fullName> <id>
//Lectures: <numberOfLectures>; Exercises: <numberOfExercises>
//The following rules apply to assistants:
//It is not allowed to create an Assistant object if the number of exercises is not positive. In this case,
//throw an exception InvalidAssistantAllocationException with the message Assistant doesn't have exercises.;
//It is not allowed to create an Assistant object if the number of lectures is positive. In this case, throw an
//exception InvalidAssistantAllocationException with the message Assistant shouldn't have lectures.;
//The function calculateClassAllocations calculates the number of classes by multiplying the number of exercises by 2;
//The function print should call the appropriate print functions from the base classes. The printing format is as follows:
//Assistant:
//<fullName> <id>
//Lectures: <numberOfLectures>; Exercises: <numberOfExercises>
//Define a global function Teacher* mostAllocatedTeacher(Teacher** teachers, int n) which returns the professor/assistant with the highest number of classes.
//The number of professors is first entered from the keyboard, followed by the required information for all professors. Similarly, data for assistants is entered.
//You need to make a change in the main function to handle the exceptions thrown by the objects of type Assistant.



#include <iostream>
#include <cstring>
using namespace std;

class Teacher {
protected:
    double id;
    char fullname[100];
public:
    Teacher(double id = 0, const char *fullname = "") {
        this->id = id;
        strcpy(this->fullname, fullname);
    }
    virtual void print() {
        cout << fullname << " " << id << endl;
    };
    virtual double calculateClassAllocations() = 0;
    friend Teacher* mostAllocatedTeacher(Teacher** teachers, int n);
};

class ClassAllocation {
protected:
    double exercisenumber;
    double lecturesnumber;
public:
    ClassAllocation(double lecturesnumber = 0, double exercisenumber = 0) {
        this->exercisenumber = exercisenumber;
        this->lecturesnumber = lecturesnumber;
    }
    virtual void print() {
        cout << "Lectures: " << lecturesnumber << "; Exercises: " << exercisenumber << endl;
    }
    friend Teacher* mostAllocatedTeacher(Teacher** teachers, int n);
};

class InvalidProfessorAllocationException {
public:
    void print() {
        cout << "Professor doesn't have lectures." << endl;
    }
};

class Professor : public Teacher, public ClassAllocation {
public:
    Professor(double id = 0, const char *fullname = "", double lecturesnumber = 0, double exercisenumber = 0)
            : Teacher(id, fullname), ClassAllocation(lecturesnumber, exercisenumber) {
        if (lecturesnumber < 1) {
            throw InvalidProfessorAllocationException();
        }
    }
    double calculateClassAllocations() {
        return (lecturesnumber * 2) + exercisenumber;
    }
    void print() {
        cout<<"Professor: "<<endl;
        Teacher::print();
        ClassAllocation::print();
    }
};

class InvalidAssistantAllocationException {
private:
    string mesage;
    string message2;
public:
    explicit InvalidAssistantAllocationException(const string &mesage, const string &message2=""){
        this->mesage=mesage;
        this->message2=message2;
    }

    void print() {
        cout << mesage << endl;
        cout<<message2<<endl;
    }
};

class Assistant : public Teacher, public ClassAllocation {
public:
    Assistant(double id = 0, const char *fullname = "", double exercisenumber = 0, double lecturesnumber = 0)
            : Teacher(id, fullname), ClassAllocation(lecturesnumber, exercisenumber) {
        if (lecturesnumber > 0) {
            throw InvalidAssistantAllocationException("Assistant shouldn't have lectures.","Assistant doesn't have exercises.");
        }
    }
    double calculateClassAllocations() {
        return exercisenumber * 2;
    }
    void print() {
        cout<<"Assistant: "<<endl;

        Teacher::print();
        ClassAllocation::print();
    }
};

Teacher* mostAllocatedTeacher(Teacher** teachers, int n) {
    Teacher* maxTeacher = teachers[0];
    for (int i = 1; i < n; ++i) {
        if (teachers[i]->calculateClassAllocations() > maxTeacher->calculateClassAllocations()) {
            maxTeacher = teachers[i];
        }
    }
    return maxTeacher;
}

int main() {
    int numberOfProfessors;
    cin >> numberOfProfessors;
    Teacher** teachers = new Teacher*[50];

    long id;
    string fullName;
    float numberOfLectures, numberOfExercises;

    for (int i = 0; i < numberOfProfessors; ++i) {
        cin >> id;
        cin.ignore();
        getline(cin, fullName);
        cin >> numberOfLectures >> numberOfExercises;

        try {
            teachers[i] = new Professor(id, fullName.c_str(), numberOfLectures, numberOfExercises);
        }
        catch (InvalidProfessorAllocationException& exception) {
            --i;
            --numberOfProfessors;
            exception.print();
        }
    }

    int numberOfAssistants;
    cin >> numberOfAssistants;

    for (int i = numberOfProfessors; i < numberOfProfessors + numberOfAssistants; ++i) {
        cin >> id;
        cin.ignore();
        getline(cin, fullName);
        cin >> numberOfLectures >> numberOfExercises;

        try {
            teachers[i] = new Assistant(id, fullName.c_str(), numberOfExercises, numberOfLectures);
        }
        catch (InvalidAssistantAllocationException& exception) {
            --i;
            --numberOfAssistants;
            exception.print();
        }
    }

    mostAllocatedTeacher(teachers, numberOfProfessors + numberOfAssistants)->print();

    for (int i = 0; i < numberOfProfessors + numberOfAssistants; ++i) {
        delete teachers[i];
    }
    delete[] teachers;

    return 0;
}