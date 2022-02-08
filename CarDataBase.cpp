#include <iostream>
#include <fstream>
using namespace std;


struct CarType {
  enum {MAX_CHAR_LEN=100};
  char Car_Name[MAX_CHAR_LEN];
  double MPG;
  int Cylinders;
  double Displacement;
  double Horsepower;
  double Weight;
  double Acceleration;
  int Model;
  char Origin;
  bool ValidEntry;
  CarType();

};

CarType::CarType() {
  Car_Name = {'\0'};
  MPG = 0;
  Cylinders = 0;
  Displacement = 0;
  Horsepower = 0;
  Weight = 0;
  Acceleration = 0;
  Model = 0;
  Origin = ' ';
  ValidEntry = false;
}


// void printCars(int num, listCar[]) {

//   for(int counter = 0; counter < num; counter++) {

//   }

// }


CarType readCar(ifstream &inFile){
    CarType car; 
    inFile.get(car.Car_Name, ';');
    inFile.ignore(100,';');
    inFile >> car.MPG;
    inFile.ignore(100,';');
    inFile >> car.Cylinders;
    inFile.ignore(100,';');
    inFile >> car.Displacement;
    inFile.ignore(100,';');
    inFile >> car.Horsepower;
    inFile.ignore(100,';');
    inFile >> car.Weight;
    inFile.ignore(100,';');
    inFile >> car.Acceleration;
    inFile.ignore(100,';');
    inFile >> car.Model;
    inFile.ignore(100,';');
    inFile >> car.Origin;
    inFile.ignore(100,';');
    car.ValidEntry = true;
    // If we reached the end of the file while reading, then the entry is not valid
    car.ValidEntry = !inFile.eof();
    return car;
}


int readCarData(CarType listCar[500]){
  ifstream carFile("cars.txt");
  int numCars = 0;
  while(carFile.peek() != EOF && numCars < 500) {
      listCar[numCars] = readCar(carFile);
      numCars++;
  }
  return numCars;
}



int main(){
  CarType listCar[500];
  int num = readCarData(listCar[500]);
  // displayMenu();


}