#include "Simulation.h"

int main(int argc, char ** argv){

    if(argc < 2){
        cout << "Invalid usage, please provide an input file" << endl;
        exit(-1);
    }

    string fileName = argv[1];

    Simulation *mySim = new Simulation();
    mySim->run(fileName);

    return 0;
}
