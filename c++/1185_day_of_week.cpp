/*
 * 1185. Day of the Week
 * Given a date, return the corresponding day of the week for that date.
 *
 * The input is given as three integers representing the day, month and year
 * respectively.
 *
 * Return the answer as one of the following values {"Sunday", "Monday",
 * "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}.
 *
 * Constraints:
 *
 * The given dates are valid dates between the years 1971 and 2100.
 */

#include "header.h"

class Solution {
public:
  string dayOfTheWeek(int day, int month, int year) {
      vector<string> res = { "Monday", "Tuesday", "Wednesday", "Thursday",
                             "Friday", "Saturday", "Sunday" };

      if (month == 1 || month == 2) {
          year--;
          month += 12;
      }

	  int mod = (day + 2 * month + 3 * (month + 1) / 5 + year
                 + year / 4 - year / 100 + year / 400) % 7;
      return res[mod];
  }
};
