#include "../Bjarne/std_lib_facilities.h";
#include <iostream>


double calculate(double n1, double n2, char oper)
{
	int operation = (int)oper; // The operation we will be doing.
	double result = 0.0;

	switch ((int)oper)
	{
	case 42: // *
		result = n1 * n2;
		break;
	case 43: // +
		result = n1 + n2;
		break;
	case 45: // -
		result = n1 - n2;
		break;
	case 47: // /
		result = n1 / n2;
		break;
	}

	return result;
}

/// <summary>
/// Calculator that accepts either word or typical digit input.
/// "eight eight +" and "8 8 +" are both legal.
/// </summary>
int main()
{
	double n1 = 0.0;
	double n2 = 0.0;
	char oper;
	double result = 0.0;

	vector<string> digits = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten" };

	cout << "Please enter two decimal values and an operator (+ - / *)" << endl;

	for (string input, input2; cin >> input >> input2 >> oper;)
	{
		bool inputWasResolved = false;
		bool input2WasResolved = false;

		// First we check if either # is in word format. (If it is, we make sure we do not try to convert the string to a double (Shown Below)
		for (int i = 0; i < digits.size(); i++)
		{
			if (input == digits[i])
			{
				n1 = (double)i;
				inputWasResolved = true;
			}
			
			// If statements must be separate because they both could be equal to digits[i]. ("eight eight +")

			if (input2 == digits[i])
			{
				n2 = (double)i;
				input2WasResolved = true;
			}
		}

		// Now we check if either # is in int format.
		if (!inputWasResolved)
		{
			n1 = stod(input);
		}

		if (!input2WasResolved)
		{
			n2 = stod(input2);
		}

		// Calculate our result now that we have both digits.
		result = calculate(n1, n2, oper);
		
		// Just for safety
		cin.clear();
		
		// Print Result
		cout << n1 << " " << oper << " " << n2 << " = " << result << endl;

		// Prompt for next go around
		cout << "Please enter two decimal values and an operator (+ - / *) \n| CTRL + Z to exit |" << endl;
	}
	return 0;
}