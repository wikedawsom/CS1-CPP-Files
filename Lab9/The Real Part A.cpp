//
//  main.cpp
//  Lab 9
//
//  Created by Courtney Jo Young on 11/1/18.
//  Copyright © 2018 Courtney Jo Young. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


class node {
public:
    double resistance;
    double voltage_across;
    double power_across;
    
};
double power(double current, double voltage)
{
    return current * voltage;
}
double calcCurrent(double resistance, double voltage)
{
    return resistance * voltage;
}
void display(int current, node N1)
{
    
    cout << "The power dissipation is: " << N1.voltage_across << endl;
    cout << "The Current is: " << current << endl;;
    
    cout << "The voltage is: " << N1.voltage_across << endl;
    cout << "The wattage is: " << N1.power_across << endl;

}

int main() {
    node N1;
    double in_voltage;
    
    cout << "Enter Voltage: ";
    cin >> in_voltage;
    
    cout << "Resistor: ";
    cin >> N1.resistance;
    
    double current = calcCurrent(N1.resistance, in_voltage);
    N1.power_across = power(current, in_voltage);
    N1.voltage_across = current * N1.resistance; //
    
    display(current, N1);
}
