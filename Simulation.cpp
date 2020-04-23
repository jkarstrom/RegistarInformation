//Joan Karstrom, Jennifer Nguyen
//ID: 2318286, 2320560
//karstrom@chapman.edu, jenguyen@chapman.edu
//CPSC: 350 - 2
//Assignment 4: Registar

Simulation::Simulation(){
    clockTick = 0;
    myRegistar = new Registar();
}

Simulation::~Simulation(){

}

void Simulation::run(string fileName){
    FileIO *fileReader = new FileIO();
    fileReader->openFile(fileName);
    
    // get number of open windows;
    int openWindows;

    for(int i = 0; i < openWindows; ++i){
        myRegistar->openWindow();
    }

    // get time for student inflow
    int studentIn;

    // get number of students here
    int studentCount;

    // make students;
    for(int i = 0; i < studentCount; ++i){
        // get student window
        int studentWindow;
        Student *newStudent = new Student(studentWindow);
        myRegistar->addStudent(newStudent);
    }


}
