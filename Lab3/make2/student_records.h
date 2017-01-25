
// ICSP End Term Exam
// Problem 3 - Max points 15


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SID 13
#define MAX_NAME 64
#define MAX_EMAILID 32
#define MAX_DOB 11
#define MAX_DOMAIN_SUFFIX 16
#define MAX_STATE 32
#define MAX_CATEGORY 5

const char domain_suffix[MAX_DOMAIN_SUFFIX] = "@iiitkota.ac.in";

typedef struct date
{
  unsigned short day;	// DD
  unsigned short month;	// MM
  unsigned int year;	// YYYY
} DATE;

// Student record
typedef struct student
{
  char sid[MAX_SID];		// e.g. 2016KUCP1001
  char name[MAX_NAME];
  char emailid[MAX_EMAILID];	// e.g. 2016KUCP1001@iiitkota.ac.in
  char gender;			// M = Male / F = Female
  char dob[MAX_DOB];		// DD-MM-YYYY e.g. 01-01-2001

  //DATE date_enrolled;		// DD-MM-YYYY e.g. 28-07-2016

  enum student_status
  {
    ss_Active,			// UG student is active for 4 years
    ss_Passed_Out,
    ss_Inactive
  } status;

  // student's state of domicile
  char state[MAX_STATE];

  // student's admission category: SC/ST/PH/OBC/Open
  char category[MAX_CATEGORY];

  // student's family income group: 
  // IG_LT1 -> SC/ST/PH
  // IG_LT1 -> family income below 1 lac
  // IG_LT5 -> family income above 1 lac and below 5 lac
  // IG_GT5 -> family income above 5 lac
  enum income_group
  {
    ig_SC,
    ig_ST,
    ig_PH,
    ig_IG_LT1,
    ig_IG_LT5,
    ig_IG_GT5
  } family_income_group;


} STUDENT;

