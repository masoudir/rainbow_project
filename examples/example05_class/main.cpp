#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>



class SudentProgress {
private:
    std::string name;
    int age;
    int class_level;
    int progress;

public:

    // int progress;

    explicit SudentProgress(std::string name, int age, int level) : name(name), age(age), class_level(level), progress(0) {
        
        // Get the current time point
        auto now = std::chrono::system_clock::now();

        // Convert the time point to a time_t object (seconds since epoch)
        std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

        // Print the current time
        std::cout << "new student with name of " << name << " has been created at this time:" << std::ctime(&currentTime) << std::endl;
    }

    ~SudentProgress() {
        // Get the current time point
        auto now = std::chrono::system_clock::now();

        // Convert the time point to a time_t object (seconds since epoch)
        std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
        std::cout << "student with name of " << name << " has been killed at this time" << std::ctime(&currentTime) << std::endl;
    }

    void increase_progress() {
        ++progress;
    }

    int get_progress() {
        return progress;
    }

};


// SudentProgress::get_progress


int main() {

    SudentProgress student1("ali", 11, 5);

    {
        SudentProgress student2("naghi", 10, 5);
    }


    SudentProgress student2("taghi", 10, 5);

    // student1.progress = 10;

    std::cout << "student1 progress=" << student1.get_progress() << std::endl;
    std::cout << "student2 progress=" << student2.get_progress() << std::endl;

    student1.increase_progress();

    std::cout << "student1 progress=" << student1.get_progress() << std::endl;
    std::cout << "student2 progress=" << student2.get_progress() << std::endl;

    


}