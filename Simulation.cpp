//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 4: Registar

#include "Simulation.h"

//default constructor
Simulation::Simulation(){
    clockTick = 0;
    studentIn = -1;

    totalStudents = 0;
    meanWait = 0;
    nStudent = 0;
    medianWait = 0;
    longestWait = 0;
    longWaits = 0;

    totalWindows = 0;
    meanIdle = 0;
    longestIdle = 0;
    longIdle = 0;
    myRegistar = new Registar();
}

//deconstructor
Simulation::~Simulation(){

}

void Simulation::run(string fileName){
    FileIO *fileReader = new FileIO();
    fileReader->openFile(fileName);

    // get number of open windows;
    totalWindows = fileReader->getNext();
    if(totalWindows <= 0){
        cout << "There must be at least one open window during operating hours." << endl;
        exit(1);
    }
    for(int i = 0; i < totalWindows; ++i){
        myRegistar->openWindow();
    }

    // get time for student inflow
    studentIn = fileReader->getNext();


    // while file is still open
    while(fileReader->moreLines()){

        if(studentIn == clockTick){
            // get number of students here
            int studentCount = fileReader->getNext();

            // make students;
            for(int i = 0; i < studentCount; ++i){
                // get student window time
                int studentWindow = fileReader->getNext();
                if(studentWindow <= 0){
                    cout << "Students have to have a valid service time" << endl;
                    exit(1);
                }

                Student newStudent = Student(studentWindow);
                totalStudents++;
                myRegistar->addStudent(newStudent);
            }
            if(fileReader->moreLines()){
                studentIn = fileReader->getNext();
            }
            else{
                // clear students still in line or still at window
                while(myRegistar->checkLine() || !myRegistar->allOpen()){
                    update();
                }
                int time = -1;
                while(time != 0){
                    time = myRegistar->clearWindows();
                    updateWindowStats(time);
                }
                break;
            }

            update();
            continue;
        }
        else if(studentIn < clockTick){
            cout << "Students can only come at a present or future time." << endl;
            exit(1);
        }
        else
            update();

    }

    printStats();

}

void Simulation::update(){

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

void Simulation::updateStudentStats(int waitTime){
    float totalWait = meanWait*totalStudents;
    totalWait += waitTime;
    meanWait = totalWait/totalStudents;

    // update median wait
    allWaits[nStudent++] = waitTime;
    int median = totalStudents/2;
    if(totalStudents%2 == 0){
        medianWait = (allWaits[--median] + allWaits[median])/2;
    }
    else{
        medianWait = (allWaits[median]);
    }

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
    cout << endl << "Mean wait time: " << meanWait << endl;
    cout << "Median wait time: " << medianWait << endl;
    cout << "Longest wait time: " << longestWait << endl;
    cout << "Number of students waiting over 10 min: " << longWaits << endl;
    cout << "Mean window idle time: " << meanIdle << endl;
    cout << "Longest window idle time: " << longestIdle << endl;
    cout << "Number of windows idle for over 5 min: " << longIdle << endl << endl;
}
