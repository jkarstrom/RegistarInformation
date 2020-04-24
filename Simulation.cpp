//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 4: Registar

#include "Simulation.h"

Simulation::Simulation(){
    clockTick = 0;
    studentIn = -1;

    totalStudents = 0;
    meanWait = 0;
    medianWait = 0;
    longestWait = 0;
    longWaits = 0;

    totalWindows;
    meanIdle = 0;
    longestIdle = 0;
    longIdle = 0;
    myRegistar = new Registar();
}

Simulation::~Simulation(){

}

void Simulation::run(string fileName){
    FileIO *fileReader = new FileIO();
    fileReader->openFile(fileName);

    // get number of open windows;
    totalWindows;
    if(totalWindows <= 0){
        cout << "There must be at least one open window during operating hours." << endl;
        exit(1);
    }

    for(int i = 0; i < totalWindows; ++i){
        myRegistar->openWindow();
    }

    // while file is still open
    while(true){
        // get time for student inflow
        studentIn;
        if(studentIn < clockTick){
            cout << "Students can only come at a present or future time." << endl;
            exit(1);
        }
        else if(studentIn > clockTick){
            break;
        }

        // get number of students here
        int studentCount;

        // make students;
        for(int i = 0; i < studentCount; ++i){
            // get student window time
            int studentWindow;
            if(studentWindow <= 0){
                cout << "Students have to have a valid service time" << endl;
                exit(1);
            }

            Student *newStudent = new Student(studentWindow);
            myRegistar->addStudent(newStudent);
        }

        // look for open windows and move students in line
        while(myRegistar->checkWindows()){
            if(myRegistar->checkLine()){
                int firstWait = myRegistar->studentStats();
                updateStudentStats(firstWait);
                int newIdle = myRegistar->moveStudent();
                updateWindowStats(newIdle);
            }
            else
                break;
        }

        // increase wait and idle times of other students and other windows
        myRegistar->increaseTimes();
        clockTick++;
    }

    printStats();

}

void Simulation::updateStudentStats(int waitTime){
    float totalWait = meanWait*totalStudents;
    totalWait += waitTime;
    totalStudents++;
    meanWait = totalWait/totalStudents;

    // update median wait

    if(waitTime > longestWait){
        longestWait = waitTime;
    }

    if(waitTime > 10){
        longWaits++;
    }
}

void Simulation::updateWindowStats(int idleTime){
    float totalIdle = meanIdle*totalWindows;
    totalIdle += idleTime;
    meanIdle = totalIdle/totalWindows;

    if(idleTime > longestIdle){
        longestIdle = idleTime;
    }

    if(idleTime > 5){
        longIdle++;
    }
}

void Simulation::printStats(){
    cout << "Mean wait time: " << meanWait << endl;
    cout << "Median wait time: " << medianWait << endl;
    cout << "Longest wait time: " << longestWait << endl;
    cout << "Number of students waiting over 10 min: " << longWaits << endl;
    cout << "Mean window idle time: " << meanIdle << endl;
    cout << "Longest window idle time: " << longestIdle << endl;
    cout << "Number of windows idle for over 5 min: " << longIdle << endl;
}
