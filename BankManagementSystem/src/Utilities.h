#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

bool FileExists(const std::string& filepath);
bool CreateFile(const std::string& username, const std::string& password);

void PromptUsernamePassword(std::string& username, std::string& password);
bool ValidateLogin(const std::string& username, std::string& password);

void PrintDetails(const std::string& username);

bool Deposit(const std::string& username, double amount);
bool Withdraw(const std::string& username, double amount);

void ContinueMessage(const std::string& message);