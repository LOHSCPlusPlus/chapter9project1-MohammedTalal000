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
  char Origin[MAX_CHAR_LEN];
  bool ValidEntry;
  CarType();

};

CarType::CarType() {
  for (int index = 0; index < MAX_CHAR_LEN; index++) {
      Car_Name[index] = '\0';
  }
  MPG = 0;
  Cylinders = 0;
  Displacement = 0;
  Horsepower = 0;
  Weight = 0;
  Acceleration = 0;
  Model = 0;
  for (int index = 0; index < MAX_CHAR_LEN; index++) {
    Origin[index] = '\0';
  }
  ValidEntry = false;
}

void addCar(CarType listCar[]) {
  for(int index = 0; index < 499; index++) {
    if(listCar[index].ValidEntry == false) {
      cout << "Enter the car's name: ";
      cin.ignore();
      cin.getline(listCar[index].Car_Name, 100);
      cout << endl << "Enter the MPG: ";
      cin >> listCar[index].MPG;
      while (!cin) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid Data!" << endl;
        cout << "Enter again: ";
        cin >> listCar[index].MPG;
      }
      cout << endl << "Enter Cylinders: ";
      cin >> listCar[index].Cylinders;
      while (!cin) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid Data!" << endl;
        cout << "Enter again: ";
        cin >> listCar[index].Cylinders;
      }
      cout << endl << "Enter the Displacement: ";
      cin >> listCar[index].Displacement;
      while (!cin) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid Data!" << endl;
        cout << "Enter again: ";
        cin >> listCar[index].Displacement;
      }
      cout << endl << "Enter the Horsepower: ";
      cin >> listCar[index].Horsepower;
      while (!cin) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid Data!" << endl;
        cout << "Enter again: ";
        cin >> listCar[index].Horsepower;
      }
      cout << endl << "Enter the Weight: ";
      cin >> listCar[index].Weight;
      while (!cin) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid Data!" << endl;
        cout << "Enter again: ";
        cin >> listCar[index].Weight;
      }
      cout << endl << "Enter the Acceleration: ";
      cin >> listCar[index].Acceleration;
      while (!cin) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid Data!" << endl;
        cout << "Enter again: ";
        cin >> listCar[index].Acceleration;
      }
      cout << endl << "Enter the Model: ";
      cin >> listCar[index].Model;
      while (!cin) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid Data!" << endl;
        cout << "Enter again: ";
        cin >> listCar[index].Model;
      }
      cout << endl << "Enter the Origin: ";
      cin.ignore();
      cin.getline(listCar[index].Origin, 100);
      listCar[index].ValidEntry = true;
      break; 
    }
  }
}


void removeCar(CarType listCar[]) {
  int index = 0;
  cout << "Enter the index you want to remove: ";
  cin >> index;
  while (!cin || listCar[index].ValidEntry == false) {
    cin.clear();
    cin.ignore(1000,'\n');
    cout << "Invalid Data!" << endl;
    cout << "Enter the index you want to remove: ";
    cin >> index;
  }
  listCar[index].ValidEntry = false;
}


void printCarsbyOrigin(int numCar, CarType listCar[500]){

  char selecOrigin[100];
  for (int index = 0; index < 100; index++) {
    selecOrigin[index] = '\0';
  }
  cout << "Please enter the specific Origin: ";
  cin.ignore();
  cin.getline(selecOrigin, 100);

  for(int counter = 0; counter < numCar; counter++) {
    if (listCar[counter].ValidEntry == true) {
      if (listCar[counter].Origin == selecOrigin) {
      cout << "Index " << counter << ": ";
      cout << listCar[counter].Car_Name << ";" << listCar[counter].MPG << ";" << listCar[counter].Cylinders << ";" << listCar[counter].Displacement << ";" << listCar[counter].Horsepower << ";" << listCar[counter].Weight << ";" << listCar[counter].Acceleration << ";" << listCar[counter].Model << ";" << listCar[counter].Origin;
      }
      else {
        continue;
      }
    }
    else {
      cout << endl;
      continue;
    }
    cout << endl;
  }
}



void printCars(int num, CarType listCar[500]) {
  for(int counter = 0; counter < 5; counter++) {
    if (listCar[counter].ValidEntry == true) {
      cout << "Index " << counter << ": ";
      cout << listCar[counter].Car_Name << ";" << listCar[counter].MPG << ";" << listCar[counter].Cylinders << ";" << listCar[counter].Displacement << ";" << listCar[counter].Horsepower << ";" << listCar[counter].Weight << ";" << listCar[counter].Acceleration << ";" << listCar[counter].Model << ";" << listCar[counter].Origin;
    }
    else {
      cout << endl;
      continue;
    }
    cout << endl;
  }

}


CarType readCar(ifstream &inFile){
    CarType car; 
    inFile.get(car.Car_Name, CarType::MAX_CHAR_LEN, ';');
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
    inFile.get(car.Origin, ';');
    inFile.ignore(100,'\n');
    car.ValidEntry = true;

    car.ValidEntry = !inFile.eof();
    return car;
}


int readCarData(CarType listCar[500]){
  ifstream carFile("cars.txt");
  int numCars = 0;
  while(carFile.peek() != EOF && numCars < 499) {
      listCar[numCars] = readCar(carFile);
      numCars++;
  }
  return numCars;
}



int main(){
  CarType listCar[500];
  int num = readCarData(listCar);
  printCars(num,listCar);
  printCarsbyOrigin(num,listCar);
  // removeCar(listCar);
  // printCars(num,listCar);
  // removeCar(listCar);
  // printCars(num,listCar);
  // addCar(listCar);
  // printCars(num,listCar);
  // displayMenu();


}