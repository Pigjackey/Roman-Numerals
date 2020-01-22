#include<iostream>
#include<sstream>
#include<string>

using namespace std;

//The main class that will run the formula.
int main()
{
	//Set up the promp and take input from the user from cin.
	cout << "Please enter the roman numeral using the following characters (make sure that they are capital!): I, V, X, L, C, D, and M followed by {enter}" << endl;
	string input = "";
	cin >> input;


	//Do bounds checking and return error code for invalid input.
	for (int i = 0; i < input.length(); i++)
	{
		if (input.at(i) != 'I' &&
			input.at(i) != 'V' &&
			input.at(i) != 'X' &&
			input.at(i) != 'L' &&
			input.at(i) != 'C' &&
			input.at(i) != 'D' &&
			input.at(i) != 'M')
		{
			cout << "You entered inproper characters. Please try again" << endl;
			return 1;
		}
	}


	//Set up the variables for the parsing.
	stringstream in(input);
	int c;
	int total = 0;



	//Check each character and add the proper amount to the total. It also checks the next character to see if there is substitution involved.
	//Looking at the spec it seems like I should only look to see if the next character is the one exactly one rank above the current one so that's how it is implemented.
	//IE I only looks for V, C only looks for D, and so on.
	while ((c = in.get()) != -1)
	{
		if (c == 'I')
		{
			c = in.peek();
			if (c == 'V')
			{
				c = in.get();
				total += 4;
			}
			else
			{
				total += 1;
			}
		}
		else if (c == 'V')
		{
			c = in.peek();
			if (c == 'X')
			{
				c = in.get();
				total += 5;
			}
			else
			{
				total += 5;
			}
		}
		else if (c == 'X')
		{
			c = in.peek();
			if (c == 'L')
			{
				c = in.get();
				total += 40;
			}
			else
			{
				total += 10;
			}
		}
		else if (c == 'L')
		{
			c = in.peek();
			if (c == 'C')
			{
				c = in.get();
				total += 50;
			}
			else
			{
				total += 50;
			}
		}
		else if (c == 'C')
		{
			c = in.peek();
			if (c == 'D')
			{
				c = in.get();
				total += 400;
			}
			else
			{
				total += 100;
			}
		}
		else if (c == 'D')
		{
			c = in.peek();
			if (c == 'M')
			{
				c = in.get();
				total += 500;
			}
			else
			{
				total += 500;
			}
		}
		else if (c == 'M')
		{
			total += 1000;
		}
	}



	//Finishes by telling the user their number in decimal.
	cout << "This is the number " << total << " in decimal" << endl;
	system("pause");
}