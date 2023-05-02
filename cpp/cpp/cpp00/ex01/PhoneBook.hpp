#include <iostream>
#include <string>
#include <cstdio>
#include <stdlib.h>
#include "Contact.hpp"

#define MAX_CONTACT_NUM 8
#define MAX_COL_WIDTH 10

class PhoneBook
{
    private:
        Contact contacts[MAX_CONTACT_NUM];
        int index;
        int count;
    
    public:
        PhoneBook();
        ~PhoneBook();
        
        int add_contact();
        void search_contact();
        void get_contact(int index);
        void check_eof(void);

};