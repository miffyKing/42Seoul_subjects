/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chobyounghwa <chobyounghwa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:44:11 by bcho              #+#    #+#             */
/*   Updated: 2023/04/25 19:03:32 by chobyounghw      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook()
{
  index = 0;
  count = 0;
}

PhoneBook::~PhoneBook() {}

void PhoneBook::check_eof()
{
  if (std::cin.eof())
  {
    std::cout << "EOF FOUND - EXIT\n";
    exit(1);
  }
}

std::string print_max_string(std::string str)
{
  if (str.length() > MAX_COL_WIDTH)
  {
    std::string sub_str = str.substr(0, 9) + ".";
    return sub_str;
  }
  else
    return str;
}

int string_to_int(std::string search_str)
{
  int temp;

  temp = 0;
  for (unsigned long i = 0; i <= search_str.size() - 1; i++)
  {
    if (search_str[i] < '0' || search_str[i] > '9')
      return (-1);
    else
      temp = temp * 10 + search_str[i] - '0';
  }
  return (temp);
}

int PhoneBook:: add_contact() {
  std::string first_name_;
  std::string last_name_;
  std::string nick_name_;
  std::string phone_number_;
  std::string darkest_secret_;

  std::cout<<"input first name:  ";
  std::getline(std::cin, first_name_);
  check_eof();

  std::cout<<"input last name:  ";
  std::getline(std::cin, last_name_);
  check_eof();

  std::cout<<"input nick name:  ";
  std::getline(std::cin, nick_name_);
  check_eof();

  std::cout<<"input phone number:  ";
  std::getline(std::cin, phone_number_);
  check_eof();

  std::cout<<"input darkest secret:  ";
  std::getline(std::cin, darkest_secret_);
  check_eof();

  if (!first_name_[0] || !last_name_[0] || !nick_name_[0] || !phone_number_[0] || !darkest_secret_[0])
  {
    std::cout << "Error: Invalid value found... Please try valid data\n";
    return (-1);
  }
  Contact newContact(first_name_, last_name_, nick_name_, phone_number_, darkest_secret_);
  contacts[index] = newContact;
  if (index + 1 == MAX_CONTACT_NUM)
  {
    count += 1;
    index = 0 ;
  }
  else
  {
    count+=1;
    index+=1;
  }
  return index;
}


void PhoneBook:: search_contact() {
  if (count == 0)
  {
    std::cout<<" NO CONTACT\n";
    return;
  }
  int idx;

  std::cout<<  std::setw(10) << "index" << "|"
            << std::setw(10) << "first_name" << "|"
            << std::setw(10) << "last_name" << "|"
            << std::setw(10) << "nick_name" << std::endl;
  for (int i = 0; i < MAX_CONTACT_NUM && !contacts[i].get_first_name().empty(); i++)
  {
    std::cout << std::setw(10) << i << "|"
              << std::setw(10) << print_max_string(contacts[i].get_first_name()) << "|"
              << std::setw(10) << print_max_string(contacts[i].get_last_name()) << "|"
              << std::setw(10) << print_max_string(contacts[i].get_nick_name()) << std::endl;
  }

  std::string search_str;
  int search_num;
  while(1)
  {
    std::cout << "INPUT INDEX  YOU WANT TO SEARCH: ";
		std::getline(std::cin, search_str);
    if (std::cin.eof())           //이거 모르겠고
    check_eof();
    search_num = string_to_int(search_str);
    if (search_num == -1)
    {
			std::cout << "INPUT INDEX NOT VALID\n";
			continue;
    }
    if (search_num > MAX_CONTACT_NUM)
    {
      std::cout << "INPUT INDEX NOT VALID\n";
      continue;
    }
    idx = search_num;
    break;
  }
  get_contact(idx);
  return ;
}

void PhoneBook::get_contact(int index)
{
  if (index < 0 || index >= MAX_CONTACT_NUM || contacts[index].get_first_name().empty())
  {
    std::cout << "Error: Invalid index number." << std::endl;
    return ;
  }
  std::cout << "first_name : " << contacts[index].get_first_name() << std::endl
            << "last_name : " << contacts[index].get_last_name() << std::endl
            << "nick_name : " << contacts[index].get_nick_name() << std::endl
            << "phone_number : " << contacts[index].get_phone_number() << std::endl
            << "darkest_secret : " << contacts[index].get_darkest_secret() << std::endl;

}