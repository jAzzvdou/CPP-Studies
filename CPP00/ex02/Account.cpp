#include <iostream>
#include <ctime>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) //| Construtor
{
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;

	this->_amount = initial_deposit;
	Account::_totalAmount += initial_deposit;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account() //| Destrutor
{
	Account::_nbAccounts--;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
}

void Account::_displayTimestamp( void )
{
	time_t now = time(0);
	tm *ltm = localtime(&now);

	std::cout << "[" << 1900 + ltm->tm_year;
	std::cout << (ltm->tm_mon + 1 < 10 ? "0" : "") << 1 + ltm->tm_mon;
	std::cout << (ltm->tm_mday < 10 ? "0" : "") << ltm->tm_mday << "_";
	std::cout << (ltm->tm_hour < 10 ? "0" : "") << ltm->tm_hour;
	std::cout << (ltm->tm_min < 10 ? "0" : "") << ltm->tm_min;
	std::cout << (ltm->tm_sec < 10 ? "0" : "") << ltm->tm_sec << "] ";
}

int Account::getNbAccounts( void ) {return (Account::_nbAccounts);}

int Account::getTotalAmount( void ) {return (Account::_totalAmount);}

int Account::getNbDeposits( void ) {return (Account::_totalNbDeposits);}

int Account::getNbWithdrawals( void ) {return (Account::_totalNbWithdrawals);}

void Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "Accounts:" << Account::getNbAccounts() << ";";
	std::cout << "Total:" << Account::getTotalAmount() << ";";
	std::cout << "Deposits:" << Account::getNbDeposits() << ";";
	std::cout << "Withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();

	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "deposit:" << deposit << ";";

	this->_nbDeposits++;
	Account::_totalNbDeposits++;

	this->_amount += deposit;
	Account::_totalAmount += deposit;

	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();

	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "withdrawal:";
	if (withdrawal > this->_amount)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	this->_nbWithdrawals++;
	Account::_totalNbWithdrawals++;

	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;

	std::cout << withdrawal << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

int Account::checkAmount( void ) const
{
	return (this->_amount);
}

void Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}
