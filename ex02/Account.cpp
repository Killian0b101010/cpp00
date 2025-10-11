/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiteixei <kiteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 15:03:44 by kiteixei          #+#    #+#             */
/*   Updated: 2025/10/11 15:03:49 by kiteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

  int Account::_nbAccounts = 0;
  int Account::_totalAmount = 0;
  int Account::_totalNbDeposits = 0;
  int Account::_totalNbWithdrawals = 0;
  Account::Account(int initial_deposit)
  {
    _displayTimestamp();
    _accountIndex = getNbAccounts();
    _nbAccounts++;
    _amount = initial_deposit;
    _totalAmount+=_amount;

    std::cout
     << " index:" <<_accountIndex << ";" 
     << "amount:" << _amount << ";" 
     << "created" << std::endl; 
  }

  Account::~Account(void)
  {
    _displayTimestamp();
    _totalAmount-= _amount;
    _nbAccounts-=1;
    std::cout
     << " index:" <<_accountIndex<< ";" 
     << "amount:" << _amount << ";" 
     << "closed" << std::endl;
  } 

  int Account::getTotalAmount(void) { return _totalAmount; } 

  int Account::getNbAccounts(void) { return _nbAccounts; } 

  int Account::getNbDeposits(void) { return _totalNbDeposits; } 

  int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; } 

  void Account::displayAccountsInfos( void ) {
            _displayTimestamp();
            std::cout 
            <<" accounts:" << getNbAccounts() << ";" 
            <<"total:" << getTotalAmount() << ";"
            <<"deposits:" << getNbDeposits() << ";"
            <<"withdrawals:" << getNbWithdrawals() << std::endl; }

  void Account::_displayTimestamp(void)
  {
    time_t timestamp;
    time(&timestamp);
    struct tm *timeInfos = localtime(&timestamp);
    std::cout 
    <<"[" 
    << timeInfos->tm_year+1900 
    << timeInfos->tm_mon 
    << timeInfos->tm_mday 
    << timeInfos->tm_hour 
    << timeInfos->tm_min 
    << timeInfos->tm_sec
    << "]"; 
  }

  void	Account::makeDeposit( int deposit )
  {
    _displayTimestamp();
    std::cout 
    << " index" << ":" << _accountIndex << ";" 
    << "p_amount" << ":" << _amount << ";"
    << "deposits" << ":" << deposit << ";";
 
      _amount += deposit;
      _nbDeposits+=1;
      _totalAmount+=deposit;
      _totalNbDeposits+=1;
    std::cout
    << "amount" << ":" << _amount << ";"
    << "nb_deposit" << ":" << _nbDeposits
    << std::endl;
  }

	bool	Account::makeWithdrawal( int withdrawal )
  {
    _displayTimestamp();
    std::cout 
    << " index" << ":" << _accountIndex << ";"
    << "p_amout" << ":" << _amount << ":";
    if(_amount < withdrawal)
    {
      std::cout << "refused" << std::endl;
    }
    else
    {
      std::cout << "withdrawal" << ":" << withdrawal << ";";
      if( _amount >= withdrawal)
      {
        _nbWithdrawals+=1; 
        _amount = withdrawal;
        _totalAmount -=_amount;
        _totalNbWithdrawals+=1;
        std::cout
        << "amount" << ":" << _amount << ";"
        << "nb_withdrawals" << ":" << _nbWithdrawals
        << std::endl;
        return(true);
      }
    }
    return(false);
  }   

	int		Account::checkAmount( void ) const
  {
    return(_amount);
  }
  
  void  Account::displayStatus(void)const
  {
    _displayTimestamp();
    std::cout  
    << " index" << ":" << _accountIndex << ":" 
    << "amount" << ":" << _amount << ":"
    << "deposits" << ":" << _nbDeposits << ":"
    << "withdrawals" << ":"<< _nbWithdrawals << 
    std::endl;
  }
