#include <iostream>

#include "Utilities.h"

void Menu()
{
	std::cout << "\n\t1. Open an account\n";
	std::cout << "\t2. Show account details\n";
	std::cout << "\t3. Deposit\n";
	std::cout << "\t4. Withdraw\n";
}

int main()
{
	int choice = -1;

	do
	{
		system("cls");
		Menu();
		std::cout << "\nSelect from the menu (0 to exit) -> ";
		std::cin >> choice;
		choice = (int)choice;
		std::cout << '\n';
		switch (choice)
		{
		case 1:
		{
			// Create account

			std::string username;
			std::string password;
			PromptUsernamePassword(username, password);

			bool success = CreateFile(username, password);
			if (!success)
				std::cout << "Username taken!\n";
			else
				std::cout << "Account created!\n";

			ContinueMessage("Press enter to continue...");
			break;
		}
		case 2:
		{
			// Show account details

			std::string username;
			std::string password;
			PromptUsernamePassword(username, password);
			bool success = ValidateLogin(username, password);
			
			if (success)
			{
				PrintDetails(username);
				ContinueMessage("Press enter to continue...");
			}
			else
			{
				ContinueMessage("Invalid credentials. Press enter to continue...");
			}
			
			break;
		}
		case 3:
		{
			// Deposit

			std::string username;
			std::string password;
			PromptUsernamePassword(username, password);
			bool success = ValidateLogin(username, password);

			if (success)
			{
				double amount;
				std::cout << "Deposit amount -> ";
				std::cin >> amount;
				std::cout << '\n';
				Deposit(username, amount);
				ContinueMessage("Press enter to continue...");
			}
			else
			{
				ContinueMessage("Invalid credentials. Press enter to continue...");
			}

			break;
		}
		case 4:
		{
			// Withdraw

			std::string username;
			std::string password;
			PromptUsernamePassword(username, password);
			bool success = ValidateLogin(username, password);

			if (success)
			{
				double amount;
				std::cout << "Withdraw amount -> ";
				std::cin >> amount;
				std::cout << '\n';
				Withdraw(username, amount);
				ContinueMessage("Press enter to continue...");
			}
			else
			{
				ContinueMessage("Invalid credentials. Press enter to continue...");
			}
			break;
		}
		default:
			break;
		}
	} while (choice != 0);

	return 0;
}