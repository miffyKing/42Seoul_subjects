/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcho <bcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:44:17 by bcho              #+#    #+#             */
/*   Updated: 2023/04/25 17:22:00 by bcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

Contact::Contact() {}

Contact::Contact(std::string FirstName,
                std::string LastName,
                std::string NickName,
                std::string PhoneNumber,
                std::string DarkestSecret)
                {
                    first_name_ = FirstName;
                    last_name_ = LastName;
                    nick_name_ = NickName;
                    phone_number_ = PhoneNumber;
                    darkest_secret_ = DarkestSecret;
                }

Contact::~Contact(){}
  
std::string Contact::get_first_name()
{
    return first_name_;
}

std::string Contact::get_last_name()
{
    return last_name_;
}

std::string Contact::get_nick_name()
{
    return nick_name_;
}

std::string Contact::get_phone_number()
{
    return phone_number_;
}

std::string Contact::get_darkest_secret()
{
    return darkest_secret_;
}
