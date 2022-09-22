#include <stdio.h>
#include <assert.h>

struct CountsByUsage {
  int lowCount;
  int mediumCount;
  int highCount;
};

struct CountsByUsage countBatteriesByUsage(const int* cycles, int nBatteries) {
  struct CountsByUsage counts = {0, 0, 0};
  for(int i=0; i<nBatteries; i++)
  {
    if(cycles[i]<0) //number of times battery charged cannot be a negative number
      continue;
    if(cycles[i]<410) //batteries charged less than 410 times is classified as low
      counts.lowCount++;
    else if(cycles[i]>=410 && cycles[i]<=909) //batteries charged between 410 to 909 times is classified as medium
      counts.mediumCount++;
    else if(cycles[i]>=910) ////batteries charged equal to or more than 910 times is classified as high
      counts.highCount++;
  }
  return counts;
}

void testBucketingByNumberOfCycles() {
  const int chargeCycleCounts[] = {100, 300, 500, 600, 900, 1000};
  const int numberOfBatteries = sizeof(chargeCycleCounts) / sizeof(chargeCycleCounts[0]);
  printf("Counting batteries by usage cycles...\n");
  struct CountsByUsage counts = countBatteriesByUsage(chargeCycleCounts, numberOfBatteries);  
  assert(counts.lowCount == 2);
  assert(counts.mediumCount == 3);
  assert(counts.highCount == 1);
  
  //Test Case1
  /*
  const int chargeCycleCounts[] = {410, 909, 0, 910};
  const int numberOfBatteries = sizeof(chargeCycleCounts) / sizeof(chargeCycleCounts[0]);
  printf("Counting batteries by usage cycles...\n");
  struct CountsByUsage counts = countBatteriesByUsage(chargeCycleCounts, numberOfBatteries);  
  assert(counts.lowCount == 1);
  assert(counts.mediumCount == 2);
  assert(counts.highCount == 1);
  */
  
  //Test Case2
  /*
  const int chargeCycleCounts[] = {300, 409, 410, 600, 700, 800, 909, 910, 1100, 1200};
  const int numberOfBatteries = sizeof(chargeCycleCounts) / sizeof(chargeCycleCounts[0]);
  printf("Counting batteries by usage cycles...\n");
  struct CountsByUsage counts = countBatteriesByUsage(chargeCycleCounts, numberOfBatteries);  
  assert(counts.lowCount == 2);
  assert(counts.mediumCount == 5);
  assert(counts.highCount == 3);
  */
  
  printf("Done counting :)\n");
}

int main() {
  testBucketingByNumberOfCycles();
  return 0;
}
