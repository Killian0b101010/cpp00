#include "Account.hpp"

  Account::Account( int deposit)
  {
    displayTimestamp();
    std::cout
     << "index;" << index << ";" 
     << "amount:" << _amount << ";" 
     << "created" std::endl;

  } 
  Account::~Account(void)
  {
    displayTimestamp();
    std::cout
     << "index;" << index << ";" 
     << "amount:" << _amount << ";" 
     << "closed" << std::endl;
  } 

  Account::getTotalAmount(void) { return _totalAmount; } 

  Account::getNbAccounts(void) { return _nbAccounts; } 

  Account::getNbDeposits(void) { return _totalNbDeposits; } 

  Account::getNbWithdrawals(void) { return _totalNbWithdrawals; } 

  Account::displayAccountsInfos( void ) {
            displayTimestamp();
            std::cout 
            <<"accounts:" << getNbAccounts() 
            <<"total:" << getTotalAmount() 
            <<"deposits:" << getNbDeposits() 
            <<"withdrawals:" << getNbWithdrawals() << std::endl; }

  Account::displayTimestamp(void)
  {
    time_t timestamp;
    time(&timestamp);
    struct tm *timeInfos = localtime(&timestamp);
    timeInfos->tm_year+1900,timeInfos->tm_month,timeInfos->tm_mday,
    timeInfos->tm_hour,timeInfos->min,timeInfos->tm_sec;
  
    stdd::cout 
    <<"[" 
    << timeInfos->tm_year+1900 
    << timeInfos->tm_month 
    << timeInfos->tm_mday 
    << timeInfos->tm_hour 
    << timeInfos->min 
    << timeInfos->tm_sec;
    << "]" 
  }

  void	makeDeposit( int deposit )
  {
      _amount += deposit;
      _nbDeposits+=1;
      _totalAmount+=deposit;
      _totalNbDeposits+=1;
  }

	bool	makeWithdrawal( int withdrawal )
  {
    if( _amount < withdrawal)
     return(false);
    if( _amount >= withdrawal
    {
      _nbWithdrawals+=1; 
      _amount -= withdrawal;
      _totalAmount -=amount;
      _totalNbWithdrawals+=1;
      return(true);
    }
    return(false);
  }   

	int		checkAmount( void ) const
  {
    return(_amount);
  }
  
  void displayStatus(void)const
  {
    displayTimestamp();
    std::cout  
    << "index" << _accountIndex 
    << "amount" << _amount 
    << "deposits" << _nbDeposits
    << "withdrawal" << _nbWithdrawals 
    << std::endl;
  }
