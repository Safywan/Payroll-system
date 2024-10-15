#ifndef SUPERANNUATION_H
#define SUPERANNUATION_H

#include <string>

#include "Adjustment.h"

class SuperAnnuation : public Adjustment {
 private:
  std::string provider;  // Super provider name

 public:
  SuperAnnuation(float rate, const std::string &provider);

  float calculateAdjustment(
      float income);  // Calculate superannuation adjustment
  float calculateCompanyContribution(
      float income);  // Company’s contribution based on income
  std::string getProvider() const;
};

#endif
