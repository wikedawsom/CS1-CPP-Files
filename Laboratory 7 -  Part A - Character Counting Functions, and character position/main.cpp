

/*
Name: Christian Harris
Date: <fill me in>
Assignment: Lab7, Part A
Description: Array and Vector functions
*/


#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int find(int arr[], int len, int seek)
{
	for (int i = 0; i < len; ++i)
	{
		if (arr[i] == seek) 
			return i;
	}
	return -1;
}

bool itExists(int array[], int length, int value) 
{
	for (int i = 0; i < length; i++)
	{
		if (value == array[i])
			return true;
	}
	return false;
}

bool isSorted(int array[], int length) 
{
	for (int i = 0; i < length-1; i++)
	{
		if (array[i] > array[i + 1])
			return false;
	}
	return true;
}

void reverse(vector <int> &reverse_me) 
{
	vector<int> original = reverse_me;
	int reversal = reverse_me.size()-1;

	for (int i = 0; i < reverse_me.size(); i++)
	{
		reverse_me.at(i) = original.at(reversal);
		reversal--;
	}
}

float mean(const vector <float> values)
{
	if (values.size() == 0)
		return 0;
	float sum = 0;
	for (int i = 0; i < values.size(); i++)
		sum += values.at(i);
	return (sum / values.size());
}

float stddev(const vector <float> values)
{
	if (values.size() == 0)
		return 0;
	float avg = mean(values);
	vector<float> sqdeviations = values;
	for (int i = 0; i < values.size() - 1; i++)
	{
		sqdeviations.at(i) = pow(values.at(i) - avg, 2);
	}
	return sqrt(mean(sqdeviations));
}

vector<int> removeDups(vector<int> array) 
{
	if (array.size() == 0)
		return array;
	vector<int> noCopies = { array.at(0) };
	bool isCopy;

	for (int i = 1; i < array.size() - 1; i++)
	{
		isCopy = false;
		for (int dupCheck = 0; dupCheck < noCopies.size(); dupCheck++)
			if (noCopies.at(dupCheck) == array.at(i))
				isCopy = true;
		if (!isCopy)
		{
			//noCopies.resize(noCopies.size() + 1);
			noCopies.push_back(array.at(i));
		}
	}
	
	return noCopies;
}

// Strings - You need to a add the rest listed in the google doc
int countPunctChars(const string &countme)
{
	int counter = 0;
	for (int i = 0; i < countme.size(); i++)
	{
		if (ispunct(countme.at(i)))
			counter++;
	}
	return counter;
}

unsigned int countUpperCaseChars(const string &countme) 
{
	int counter = 0;
	for (int i = 0; i < countme.size(); i++)
	{
		if (isupper(countme.at(i)))
			counter++;
	}
	return counter;
}

unsigned int countLowerCaseChars(const string &countme)
{
	int counter = 0;
	for (int i = 0; i < countme.size(); i++)
	{
		if (islower(countme.at(i)))
			counter++;
	}
	return counter;
}

unsigned int positionOfMaxAsciiValue(const string &countme)
{
	int position = 0;
	if (countme.size() == 0)
		return -1;
	for (int i = 1; i < countme.size(); i++)
	{
		if (countme.at(i) > countme.at(i-1))
			position = i;
	}
	return position;
}

string convertToUpper(const string &to_be_converted) 
{
	string upperCase = to_be_converted;
	if (to_be_converted.size() == 0)
		return to_be_converted;
	for (int i = 0; i < upperCase.size(); i++)
	{
		upperCase.at(i) = toupper(upperCase.at(i));
	}
	return upperCase;
}

string convertToLower(const string &to_be_converted)
{
	string upperCase = to_be_converted;
	if (to_be_converted.size() == 0)
		return to_be_converted;
	for (int i = 0; i < upperCase.size(); i++)
	{
		upperCase.at(i) = tolower(upperCase.at(i));
	}
	return upperCase;
}

string removeSpaces(const string &remove_from_me) 
{
	string spaceless = remove_from_me;
	for (int i = remove_from_me.size() - 1; i >= 0; i--)
	{
		if (spaceless.at(i) == ' ')
			spaceless.erase(spaceless.begin()+i);
	}
	return spaceless;
}

vector <int> characterCounts(const string &countme) 
{
	vector<int> counts(26,0);
	for (int countsi = 0; countsi < 26; countsi++)
	{
		for (int i = 0; i < countme.size(); i++)
		{
			if (tolower(countme.at(i)) - 'a' == countsi)
				counts.at(countsi)++;
		}
	}
	return counts;
}

template<typename T>
string print(vector<T> vec);

template<typename T>
string print(T array[], int length);


int main() {
	srand(time(0));

	cout << "find:" << endl;
	int x1[10] = { 1,2,3,5,5,6,7,8,9,0 };

	cout << "false/0 = " << find(x1, 10, 4) << endl;
	cout << "false/0 = " << find(x1, 10, 99) << endl;
	cout << "true/1 = " << find(x1, 10, 5) << endl;
	cout << "true/1 = " << find(x1, 10, 0) << endl;
	cout << "true/1 = " << find(x1, 10, 1) << endl;
	cout << "true/1 = " << find(x1, 10, 6) << endl;
	cout << endl;
	cout << endl;
	cout << "reverse:" << endl;
	vector <int> v1 = { 1,2,3,4,5 };
	reverse(v1);
	cout << "[5,4,3,2,1] = " << print(v1) << endl;
	reverse(v1);
	cout << "[1,2,3,4,5] = " << print(v1) << endl;
	vector <int> v2 = { 5 };
	cout << "[5] = " << print(v2) << endl;
	vector <int> v3 = { 1,2,4,5 };
	reverse(v3);
	cout << "[5,4,2,1] = " << print(v3) << endl;
	vector <int> v4(100);
	v4[0] = 4;
	v4[1] = 2;
	reverse(v4);
	cout << "0 = " << v4[0] << endl;
	cout << "2 = " << v4[98] << endl;
	cout << "4 = " << v4[99] << endl;

	cout << endl << "mean:" << endl;
	vector <float> f1 = { 1.2, 2.4, 3.4 };
	vector <float> f2 = { 5.6, 5.6, 5.6, 5.6, 5.6, 5.6 };
	cout << "2.33 = " << mean(f1) << endl;
	cout << "5.6 = " << mean(f2) << endl;

	cout << endl << "stddev:" << endl;
	cout << "0.899 = " << stddev(f1) << endl;
	cout << "0 = " << stddev(f2) << endl;

	cout << endl << "removedups:" << endl;
	vector<int> v5;
	v5.push_back(1);
	v5.push_back(2);
	v5.push_back(3);
	v5.push_back(3);
	v5.push_back(4);
	v5.push_back(5);
	v5.push_back(1);
	vector<int> v12 = removeDups(v5);
	cout << "[1,2,3,4,5] = " << print(v12) << endl;
	cout << "5 = " << v12.size() << endl;
	vector<int> v6;
	for (int i = 0; i < 100; i++) {
		v6.push_back(i % 17 + i % 7);
	}
	vector<int> v22 = removeDups(v6);
	cout << "22 = " << v22.size() << endl;

	cout << "\nString Functions: " << endl;
	string upper_test = "aaABCdeFG";
	cout << "countUpperCase" << endl;
	cout << "5 = " << countUpperCaseChars(upper_test) << endl;
	cout << "5 = " << countUpperCaseChars("AAAAA") << endl;
	cout << "0 = " << countUpperCaseChars("aaaaa") << endl;
	string no_upper_case = "aaaa";
	cout << "0 = " << countUpperCaseChars(no_upper_case) << endl;
	cout << "positionOfMaxAsciiValue:" << endl;
	string sendIt = "AbcDeF456JHsiacXXx";
	cout << "17 = " << positionOfMaxAsciiValue(sendIt) << endl;
	cout << "RemoveSpaces:" << endl;
	string test1 = "aa AB Cd e FG";
	string test2 = "aaAB Cd e FG ";
	string test3 = " rrAB Cd e FG";
	string test4 = " rrAB Cd e FG ";

	cout << "aaABCdeFG = " << removeSpaces(test1) << endl;
	cout << "aaABCdeFG = " << removeSpaces(test2) << endl;
	cout << "rrABCdeFG = " << removeSpaces(test3) << endl;
	cout << "rrABCdeFG = " << removeSpaces(test4) << endl;

	return 0;
}

// A sneaky way to allow 1 function to print any typed array, as long as
// the passed array element can be sent to <<.
// The stringstream allows us to 'print' information to a fake output
// stream, and then get the result as a string.  It's a simple way of
// getting a non-string/character into a string.
// Contense of this function will not be tested in this course!


template<typename T>
string print(vector<T> vect) {
	stringstream out;
	out << '[';
	for (int i = 0; i < vect.size(); i++) {
		out << vect[i];
		if (i != vect.size() - 1)out << ',';
	}
	out << ']';
	return out.str();
}


template<typename T>
string print(T array[], int length) {
	stringstream out;
	out << '[';
	for (int i = 0; i < length; i++) {
		out << array[i];
		if (i != length - 1)out << ',';
	}
	out << ']';
	return out.str();
}


