#include "user.h"

void print_user(struct user us)
{
  printf("{ first_name: '%s'; last_name: '%s'; email: '%s'; security_level: %d; }", us.first_name, us.last_name, us.email, us.security_level);
}

void make_admin(struct user* us)
{
  us->security_level = 2;
}


