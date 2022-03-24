#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class Account
{
private:
	std::string m_Username;
	std::string m_Password;
	std::string m_Filepath;
public:
	static Account* CreateAccount(const std::string& username, const std::string& password)
	{
		// We need to check if the username is taken
		// We will attempt to open the file.
		std::string filepath = "database\\" + username + ".txt";
		std::ifstream file(filepath);

		if (!file)
			return new Account(username, password, filepath);
		else
			return nullptr;
	}

	std::string GetUsername()
	{
		return m_Username;
	}

	std::string GetPassword()
	{
		return m_Password;
	}

	std::string GetFilepath()
	{
		return m_Filepath;
	}
private:
	Account(const std::string& username, const std::string& password, const std::string& filepath)
		: m_Username(username), m_Password(password), m_Filepath(filepath)
	{
		CreateFile();
	}

	void CreateFile()
	{
		std::ofstream file;
		file.open(m_Filepath);
		file << m_Username << '\n' << m_Password << '\n' << 0;
		file.close();
	}
};

void Menu()
{
	std::cout << "1. Open an account\n";
	std::cout << "2. Login\n";
	std::cout << "3. Deposit\n";
	std::cout << "4. Withdraw\n";
	std::cout << "5. Exit\n";
}

int main()
{
	int choice = 0;
	// We store them in a vector to delete them at the end of our program.
	std::vector<Account*> accounts;
	do
	{
		std::cout << '\n';
		Menu();
		std::cout << "Select from the menu -> ";
		std::cin >> choice;

		switch (choice)
		{
		case 1:
		{
			std::string username;
			std::cout << "Enter a username -> ";
			std::cin >> username;

			std::string password;
			std::cout << "Enter a password -> ";
			std::cin >> password;

			Account* account = Account::CreateAccount(username, password);
			if (account == nullptr)
				std::cout << "Username taken!\n";
			else
				accounts.push_back(account);
			break;
		}
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		default:
			break;
		}
	} while (choice != 5);

	accounts.clear();
	return 0;
}