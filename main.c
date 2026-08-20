#include <stdio.h>
#include <string.h>

int main()
{
int choice = 0;
char username[50], password[50];
char login_username[50], login_password[50];
FILE *file;

file = fopen("account.txt", "r");

if (file != NULL)
{
fscanf(file, "%49s", username);
fscanf(file, "%49s", password);
fclose(file);
}

while (choice != 3)
{
printf("\n=== Password Vault ===\n");
printf("1. Create account\n");
printf("2. Login\n");
printf("3. Exit\n");
printf("Choose: ");
scanf("%d", &choice);

if (choice == 1)
{
printf("Username: ");
scanf("%49s", username);
printf("Password: ");
scanf("%49s", password);

file = fopen("account.txt", "w");

if (file != NULL)
{
fprintf(file, "%s\n%s\n", username, password);
fclose(file);
printf("Account saved!\n");
}
else
{
printf("Could not save account.\n");
}
}

else if (choice == 2)
{
printf("Username: ");
scanf("%49s", login_username);
printf("Password: ");
scanf("%49s", login_password);

if (strcmp(username, login_username) == 0 &&
strcmp(password, login_password) == 0)
{
printf("Login successful!\n");
}
else
{
printf("Invalid username or password!\n");
}
}

else if (choice == 3)
{
printf("Goodbye!\n");
}

else
{
printf("Invalid choice!\n");
}
}

return 0;
}
