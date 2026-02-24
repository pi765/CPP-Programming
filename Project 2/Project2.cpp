// file name: Project2.cpp
// Name: William Nguyen

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

//Calculate total damage of all enemies
float matrix_power(int botsPower[], int botsCount, float bossPower) 
{
    float sum = 0;
    for (int i =0; i < botsCount; i++) { //loop to add up bot powers
        sum += botsPower[i];
    }
    sum += bossPower; //add boss power
    return sum;
}

//Missile power needed per individual bot and boss
template  <typename T>
T single_missile_power(T a)
{
    T power;
    if (a <= 10){
        power = a * 2; //missile power = bot power times 2
    }
    else{
        power = a * 5; //missile power = bot power times 5
    }
    return power;
}

//update defenseMatrix
void load_dva(float& defenseMatrix, float matrixPowerRequired)
{
    if (defenseMatrix < matrixPowerRequired) { //if defense matrix is lower than required, update defense matrix to the required
        defenseMatrix = matrixPowerRequired;
    }
}

//update microMissiles
void load_dva(int& microMissiles, float missilePowerRequired)
{
    if (missilePowerRequired > microMissiles * 80) { //if missile power required is greater than number of micro missiles times 80
        microMissiles = ceil(missilePowerRequired / 80); //number of micro missiles is equal to missile power required divided by 80 (rounded to nearest integer)
    }
}

int main() {
    //Open file
    ifstream combatFile("combat.txt");
    //Check file open
    if (!combatFile.is_open()){
        cout << "File fail to open." << endl;
        return 0;
    }

    //Read the number of bots
    int botsCount;
    combatFile >> botsCount;
    //Create an array to hold the botsPower
    int botsPower[botsCount];
    for (int i=0; i < botsCount; i++) { //loop to read and store integers into botsPower array
        combatFile >> botsPower[botsCount];
        botsPower[i] = botsPower[botsCount];
    }

    //Read Boss Power
    float bossPower;
    combatFile >> bossPower;

    //Read loaded micro missiles
    int microMissiles;
    combatFile >> microMissiles;

    //Read loaded power of defence matrix
    float defenseMatrix;
    combatFile >> defenseMatrix;

    //Close "combat.txt"
    combatFile.close();

    //Calculate missile power required
    float missilePowerRequired = 0;
    for (int i = 0; i < botsCount; i++) { //loop to sum missile power required from bots
        missilePowerRequired += single_missile_power(botsPower[i]);
    }
    missilePowerRequired += single_missile_power(bossPower); //add missile power required from boss

    //Calculate and load defense matrix
    float matrixPowerRequired = matrix_power(botsPower, botsCount, bossPower);
    load_dva(defenseMatrix, matrixPowerRequired);

    //load micro missiles
    load_dva(microMissiles, missilePowerRequired);


    //open File
    ofstream reportFile;
    reportFile.open("report.txt");
    //Check file open
    if (!reportFile.is_open()){
        cout << "Report file failed to open." << endl;
        return 0;
    }
    //Write summary report into "report.txt"
    reportFile << "D.Va's Combat Report\n";
    reportFile << "Combat with " << botsCount << " enemy bots and one enemy boss with power " << bossPower << ".\n";
    reportFile << "Loaded mech with " << microMissiles << " micro missiles and the defense matrix with power " << defenseMatrix << ".\n";
    reportFile << "Ready for combat!";
    //close "report.txt"
    reportFile.close();

    return 0;
}
