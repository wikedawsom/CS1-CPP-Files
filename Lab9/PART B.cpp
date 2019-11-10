//
//  main.cpp
//  Lab 9
//
//  Created by Courtney Jo Young and CHRISTIAN HARRIS on 11/1/18.
/
//

#include <iostream>
#include <vector>
using namespace std;


class node {
public:
    double resistance;
    double voltage_drop;
    double power_across;
    
};

double power(double current, double voltage)
{
    return current * voltage;
}
double calcCurrent(vector <node> N, double voltage)
{
    double total_resistance = 0;
    for (int i = 0; i < N.size(); i++)
    {
        total_resistance += N.at(i).resistance;
    }
    return total_resistance * voltage;
}

void fillNodes(vector <node> &N)
{
    
    int i = 0;
    double input = 0;
    while(true){
        cout << "Enter individual resitance (-1 to stop): ";
        cin >> input;
        if (input == -1)
            break;
        node N1;
        N.push_back(N1);
        N.at(i).resistance = input;
        i++;
    }
}
void calcVoltageDrop(vector <node> &N, int current)
{
    for (int i = 0; i < N.size(); i++)
    {
        N.at(i).voltage_drop = N.at(i).resistance * current;
    }
}
void calcPowerDissipated(vector <node> &N, int current)
{
    for (int i = 0; i < N.size(); i++)
    {
        N.at(i).power_across = N.at(i).voltage_drop * current;
    }

}
void display(vector <node> N, double totalVolt, double totalCurr)
{
    double totalPower = power(totalCurr, totalVolt);
    cout << "Total Voltage: " << totalVolt << " V" << endl;
    cout << "Total Current: " << totalCurr << " Amp" << endl;
    cout << "Total Power: " << totalPower << " Watt" << endl;
    for (int i = 0; i < N.size(); i++)
    {
        cout << "Resistance of node " << i << " :" << N.at(i).resistance << " Ohm\n";
        cout << "Voltage drop of node " << i << " :" << N.at(i).voltage_drop << " V\n";
        cout << "Power consumption of node " << i << " :" << N.at(i).power_across << " Watt\n";


    }
}

int main() {
    vector <node> N;
    double in_voltage;
    cout << "Enter Voltage: ";
    cin >> in_voltage;
    fillNodes(N);
    
    double total_current =calcCurrent(N, in_voltage);
    calcVoltageDrop(N, total_current);
    calcPowerDissipated(N, total_current);
    
    display(N, in_voltage, total_current);
    
}
