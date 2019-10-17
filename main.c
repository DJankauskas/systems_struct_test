#include "user.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

//note: assuming ASCII!
//FIXME: use the standard library
char to_upper(char c)
{
  return c - 32;
}

char to_lower(char c)
{
  return c + 32;
}

int main()
{
  char first_names[6][10] = { "Dylan", "Veronica", "Eric", "Virginia", "Lewis", "Miley" };
  char consonants[6] = { 'd', 's', 'z', 't', 'h', 'l' };
  char vowels[5] = { 'a', 'e', 'i', 'o', 'u' };

  srand(time(0));

  //set up random first and last names
  char* first_name = first_names[rand() % 6];
  char last_name[4];
  last_name[0] = to_upper(consonants[rand() % 6]);
  last_name[1] = vowels[rand() % 5];
  last_name[2] = consonants[rand() % 6];
  last_name[3] = '\0';

  //create sample stuy email using names
  //future improvement: use sprintf

  char email[20];
  email[0] = to_lower(first_name[0]);
  email[1] = to_lower(last_name[0]);
  strcpy(email + 2, last_name + 1);
  strcpy(email + 1 + strlen(last_name), "00@stuy.edu");

  //a security id in the system is between 0 and 2
  int security_level = rand() % 3;

  //using designated initializers, which are a cool feature
  struct user user0 = { .first_name = first_name, .last_name = last_name, .email = email, .security_level = security_level };

  printf("The following semi-randomized struct represents a small subset of a user's representation on stuyspec.com: ");
  print_user(user0);

  printf("\nLet's make the user an admin. Admins have security level 2.\n");
  make_admin(&user0);
  printf("There we go: ");
  print_user(user0);
  printf("\n");

  return 0;
}
