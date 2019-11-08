#include <iostream>
#include <random>
#include <armadillo>
#include <crossprodmat.h>

int main() {
  const int groups [] = {0,1,2,2,2,3,4,4,5,6}, ngroups=7, nvaringroup [] = {1,1,3,1,2,1,1}, p=10;
  int *current_sel, *singlevar_sel, i, p_i, varcount, groupcount, singlevarcount=0, nsinglevars=0;

  for (groupcount=0; groupcount<ngroups; groupcount++) {
    p_i = nvaringroup[groupcount];
    if (p_i==1) nsinglevars++;
  }
  singlevar_sel = new int [nsinglevars];
  for (varcount=0, groupcount=0; varcount < p; varcount++, groupcount++) {
    p_i = nvaringroup[groupcount];
    if (p_i==1) {
      singlevar_sel[singlevarcount] = varcount;
      singlevarcount++;
    } else {
      current_sel = new int [p_i];
      for (i=0;i<p_i;i++) {
        current_sel[i]=varcount+i;
        std::cout << current_sel[i] << ", ";
      }
      std::cout << std::endl;
      varcount = varcount + p_i - 1;
    }
  }

  for (i=0;i<nsinglevars;i++) {
    std::cout << singlevar_sel[i] << ", ";
  }
  std::cout << std::endl;
  return 0;
}
