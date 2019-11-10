//
//  main.cpp
//  Lab 9
//
//  Created by Courtney Jo Young AND Christian Harris
//
//

#include <iostream>
#include <vector>
using namespace std;


class node {
public:
    double resistance;
    double voltage_drop;
    double power_across;
    void changeResistance(double newRes)
    {
        resistance = newRes;
    }
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

void addone(vector <node> &N)
{
    double input = 0;
        cout << "Enter individual resitance: ";
        cin >> input;
        node N1;
        N.push_back(N1);
    N.at(N.size()-1).resistance = input;
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
    int index;
    vector <node> N;
    double in_voltage;
    cout << "Enter Voltage: ";
    cin >> in_voltage;
    
    
    double total_current =calcCurrent(N, in_voltage);
    calcVoltageDrop(N, total_current);
    calcPowerDissipated(N, total_current);
    
    bool K = true;
    
    while (K)
    {
        char input;
        cout << "Enter a to Add a single resistor" << endl;
        cout << "Enter c to change Input" << endl;
        cout << "Enter d to Delete Resistor" << endl;
        cout << "Enter e to Edit Resistor Value" << endl;
        cout << "Enter g to Add group of Resistors" << endl;
        cout << "Enter n to Display Network" << endl;
        cout << "Enter q to Quit" << endl;
        cin >> input;
        
        
        
        switch (input) {
            case 'a':
                addone(N);
                break;
            case 'c':
                cout << "Which do you want to change Voltage to? ";
                cin >> in_voltage;
                
    
                break;
                
            case 'd':
                cout << "Which node do you want to delete? ";
                cin >> index;
                N.erase(N.begin()+index);
                break;
                
            case 'e':
                int nodie;
                double newval;
                cout << "Which Node do you want to change? ";
                cin >> nodie;
                cout << "What do you want to change Node to? ";
                cin >> newval;
                N.at(nodie).changeResistance(newval);
                
                break;
            case 'g':
                fillNodes(N);
                break;
                
            case 'n':
                display(N, in_voltage, total_current);
                break;
            case 'q':
                K = false;
                break;
       
            default:
                break;
                
                
                
        }
        total_current =calcCurrent(N, in_voltage);
        calcVoltageDrop(N, total_current);
        calcPowerDissipated(N, total_current);
    }
    

}

