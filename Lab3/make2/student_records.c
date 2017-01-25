
// ICSP End Term Exam
// Problem 3 - Max points 15

#include "student_records.h"

int main()
{
  printf("\n\tIIIT Kota student records: entry\n");

  int n = 0;
  unsigned int i = 0;
  char enter;

  printf("\nHow many student records are there? ");
  scanf("%d", &n);

  // Check input for student record count
  if (n <= 0)
  {
    printf("\nInvalid number!\n");
    return -1;
  }

  // Declare n array of pointers to structure student
  STUDENT *s[n];

  for (i = 0; i < n; i++)
  {
    // Allocate memory to individual structures
    s[i] = (STUDENT *) malloc(sizeof(STUDENT));

    // Check for memory allocation errors
    if (NULL == s[i])
    {
      printf("\nMemory allocation error!\n");
      return -2;
    }
  }

  enter = getchar();

  // Read student record details
  for (i = 0; i < n; i++)
  {
    printf("\nDetails of student[%d]\n", i+1);

    printf("\nEnter student id: ");
    scanf("%[^\n]s", s[i]->sid);
    enter = getchar();

    printf("\nEnter student's name: ");
    scanf("%[^\n]s", s[i]->name);
    enter = getchar();

    // Create email id from student id and domain_suffix
    strncat(s[i]->emailid, s[i]->sid, strlen(s[i]->sid));
    strncat(s[i]->emailid, domain_suffix, strlen(domain_suffix));

    printf("\nEnter student's gender [M/F]: ");
    scanf(" %c", &s[i]->gender);
    enter = getchar();

    // [3 points] Q. Use DATE structure for DOB and read day, month, year separately
    printf("\nEnter student's DOB: ");
    scanf("%[^\n]s", s[i]->dob);
    enter = getchar();

    // [3 points] Q. Compute status from enrollment date, 
    // get enrollment day, month, year from user
    s[i]->status = ss_Active;

    // [3 points] Q. Ask user about admission category and populate category

    // [3 points] Q. Ask user about income group and populate family_income_group


  } // student record entry ends here

  printf("\n\tIIIT Kota student records: display\n");

  for (i = 0; i < n; i++)
  {
    printf("\nDetails of student[%d]\n", i+1);

    printf("\tstudent id: %s\n", s[i]->sid);
    printf("\tstudent's name: %s\n", s[i]->name);
    printf("\tstudent's email id: %s\n", s[i]->emailid);
    printf("\tstudent's gender: %c\n", s[i]->gender);
    printf("\tstudent's DOB: %s\n", s[i]->dob);

    switch (s[i]->status)
    {
      case ss_Active:
        printf("\tstudent status: Active \n");
        break;

      case ss_Passed_Out:
        printf("\tstudent status: Active \n");
        break;

      case ss_Inactive:
        printf("\tstudent status: Active \n");
        break;

      default:
        printf("Invalid status!\n");
    }

    // [3 points] Q. print other details for student 


  } // student record display ends here

  // Free memory
  for (i = 0; i < n; i++)
  {
    free(s[i]);
    s[i] = NULL;
  }

  // [Bonus - Max 2 points] Q. What are the shortcomings of this implementations?
  // What can be better way to implement this?

  return 0;
}
