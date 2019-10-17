#ifndef USER_HEADER
#define USER_HEADER

#include <stdio.h>

struct user
{
  char* first_name;
  char* last_name;
  char* email;

  int security_level;
};

void print_user(struct user us);

void make_admin(struct user* us);

#endif
