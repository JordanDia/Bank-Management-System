#include "Utilities.h"

bool FileExists(const std::string& filepath)
{
	std::ifstream file;
	file.open(filepath);
	if (file)
	{
		file.close();
		return true;
	}
	return false;
}

bool CreateFile(const std::string& username, const std::string& password)
{
	std::string filepath = "database\\" + username + ".txt";

	// check if file exists already
	if (FileExists(filepath)) return false;

	// create file with login info
	std::ofstream file;
	file.open(filepath);
	file << username << '\n' << password;
	file.close();

	// create file that holds the user's balance
	filepath = "database\\" + username + "_balance.txt";

	std::ofstream balance_file;
	balance_file.open(filepath);
	balance_file << 0.00;
	balance_file.close();
	return true;
}

void PromptUsernamePassword(std::string& username, std::string& password)
{
	std::cout << "Enter a username -> ";
	std::cin >> username;

	std::cout << "Enter a password -> ";
	std::cin >> password;

	std::cout << '\n';
}

bool ValidateLogin(const std::string& username, std::string& password)
{
	std::string filepath = "database\\" + username + ".txt";
	std::ifstream file;
	file.open(filepath);

	if (!file) return false;

	std::string current_line;
	int line_number = 0;
	while (std::getline(file, current_line))
	{
		line_number++;
		if (line_number == 1 && current_line != username) return false;
		if (line_number == 2 && current_line != password) return false;
	}
	return true;
}

void PrintDetails(const std::string& username)
{
	// open the login info file
	std::string filepath = "database\\" + username + ".txt";
	std::ifstream file;
	file.open(filepath);

	if (!file) return;

	// print the entire file
	std::string current_line;
	while (std::getline(file, current_line))
	{
		std::cout << current_line << std::endl;
	}
	file.close();

	// do the same for the balance file
	filepath = "database\\" + username + "_balance.txt";
	std::ifstream balance_file;
	balance_file.open(filepath);

	if (!balance_file) return;

	std::getline(balance_file, current_line);
	std::cout << current_line << std::endl;

	balance_file.close();
}

bool Deposit(const std::string& username, double amount)
{
	if (amount <= 0)
	{
		std::cout << "Invalid amount...\n";
		return false;
	}

	// get the balance file
	std::string filepath = "database\\" + username + "_balance.txt";
	std::ifstream read_balance_file;
	read_balance_file.open(filepath);

	// calculate the new balance amount
	std::string balance_string;
	std::getline(read_balance_file, balance_string);
	double balance = std::stod(balance_string);
	double new_balance = balance + amount;

	// close the read file
	read_balance_file.close();

	// open a write file to update the balance;
	std::ofstream new_balance_file;
	new_balance_file.open(filepath);
	new_balance_file << new_balance;
	new_balance_file.close();
	return true;
}

bool Withdraw(const std::string& username, double amount)
{
	if (amount <= 0)
	{
		std::cout << "Invalid amount...\n";
		return false;
	}

	// get the balance file
	std::string filepath = "database\\" + username + "_balance.txt";
	std::ifstream read_balance_file;
	read_balance_file.open(filepath);

	// calculate the new balance amount
	std::string balance_string;
	std::getline(read_balance_file, balance_string);
	double balance = std::stod(balance_string);
	double new_balance = balance - amount;

	// make sure new balance is not negative
	if (new_balance < 0)
	{
		std::cout << "New balance cannot be less than 0...\n";
		return false;
	}

	// close the read file
	read_balance_file.close();

	// open a write file to update the balance;
	std::ofstream new_balance_file;
	new_balance_file.open(filepath);
	new_balance_file << new_balance;
	new_balance_file.close();
	return true;
}

void ContinueMessage(const std::string& message)
{
	std::cout << message << std::endl;
	std::cin.ignore();
	std::cin.get();
}
