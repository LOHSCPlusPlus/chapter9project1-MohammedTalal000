#include <iostream>
#include <string.h>
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
// Validates if user input is a double
double validDouble(double num) {
  while (!cin) {
    cin.clear();
    cin.ignore(1000,'\n');
    cout << "Invalid Data!" << endl;
    cout << "Enter again: ";
    cin >> num;
  }
  return num;
}
// Validates if user input is a int
int validInt(int num) {
  while (!cin) {
    cin.clear();
    cin.ignore(1000,'\n');
    cout << "Invalid Data!" << endl;
    cout << "Enter again: ";
    cin >> num;
  }
  return num;
}
// Checks is there is space then asks user for info of the car.
void addCar(CarType listCar[]) {
  for(int index = 0; index < 500; index++) {
    if(listCar[index].ValidEntry == false) {
      cout << "Enter the car's name: ";
      cin.ignore();
      cin.getline(listCar[index].Car_Name, 100);
      cout << endl << "Enter the MPG: ";
      cin >> listCar[index].MPG;
      listCar[index].MPG = validDouble(listCar[index].MPG);
      cout << endl << "Enter Cylinders: ";
      cin >> listCar[index].Cylinders;
      listCar[index].Cylinders = validInt(listCar[index].Cylinders);
      cout << endl << "Enter the Displacement: ";
      cin >> listCar[index].Displacement;
      listCar[index].Displacement = validDouble(listCar[index].Displacement);
      cout << endl << "Enter the Horsepower: ";
      cin >> listCar[index].Horsepower;
      listCar[index].Horsepower = validDouble(listCar[index].Horsepower);
      cout << endl << "Enter the Weight: ";
      cin >> listCar[index].Weight;
      listCar[index].Weight = validDouble(listCar[index].Weight);
      cout << endl << "Enter the Acceleration: ";
      cin >> listCar[index].Acceleration;
      listCar[index].Acceleration = validDouble(listCar[index].Acceleration);
      cout << endl << "Enter the Model: ";
      cin >> listCar[index].Model;
      listCar[index].Model = validInt(listCar[index].Model);
      cout << endl << "Enter the Origin: ";
      cin.ignore();
      cin.getline(listCar[index].Origin, 100);
      listCar[index].ValidEntry = true;
      break; 
    }
  }
}

// asks user for index to remove and does so.
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

// asks user for origin to search by and does so
void printCarsbyOrigin(int num, CarType listCar[500]){
  char selecOrigin[100];
  for (int index = 0; index < 100; index++) {
    selecOrigin[index] = '\0';
  }
  cout << "Please enter the specific Origin: ";
  cin.ignore();
  cin.getline(selecOrigin, 100);
  cout << endl;

  for(int counter = 0; counter < num; counter++) {
    if (listCar[counter].ValidEntry == true) {
      if (strcmp(listCar[counter].Origin,selecOrigin) == 0) {
        cout << "Index " << counter << ": ";
        cout << listCar[counter].Car_Name << ";" << listCar[counter].MPG << ";" << listCar[counter].Cylinders << ";" << listCar[counter].Displacement << ";" << listCar[counter].Horsepower << ";" << listCar[counter].Weight << ";" << listCar[counter].Acceleration << ";" << listCar[counter].Model << ";" << listCar[counter].Origin << endl;
      }
    }
    else {
      cout << endl;
    }
  }
}


// displays all the cars in the list.
void printCars(int num, CarType listCar[500]) {
  for(int counter = 0; counter < num; counter++) {
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

// fills the array witht he info of the cars.
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

// loops throught the different elements of the array to fill in the info
int readCarData(CarType listCar[500]){
  ifstream carFile("cars.txt");
  int numCars = 0;
  while(carFile.peek() != EOF && numCars < 499) {
      listCar[numCars] = readCar(carFile);
      numCars++;
  }
  return numCars;
}
// diplays menu for user to choose from
void displayMenu(CarType listCar[], int num){
  int option = 0;
  while (option != 5) {
    cout << endl << "1: Display the car list" << endl;
    cout << "2: Remove a car from the list" << endl;
    cout << "3: Add a car to the list" << endl;
    cout << "4: Display cars by origin" << endl;
    cout << "5: Quit" << endl;
    cout << "Enter an option: ";
    cin >> option;
    option = validInt(option);
  
    if(option == 1) {
      printCars(num, listCar);
    }
    else if (option == 2) {
      removeCar(listCar);
    }
    else if (option == 3) {
     addCar(listCar);
    }
    else if (option == 4) {
      printCarsbyOrigin(num, listCar);
    }
    else if (option == 5) {
      break;
    }
    else {
      cout << "Invalid option!!" << endl;
    }
  }
}
// calls displayMenu and starts the whole program.
int main(){
  CarType listCar[500];
  int num = readCarData(listCar);
  displayMenu(listCar, num);


}