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
    if(cycles[i]<0)
      continue;
    if(cycles[i]<410)
      counts.lowCount++;
    else if(cycles[i]>=410 && cycles[i]<=909)
      counts.mediumCount++;
    else if(cycles[i]>=910)
      counts.highCount++;
  }
  return counts;
}

void testBucketingByNumberOfCycles() {
  const int chargeCycleCounts[] = {100, 300, 500, 600, 900, 1000};
  const int numberOfBatteries = sizeof(chargeCycleCounts) / sizeof(chargeCycleCounts[0]);
  printf("Counting batteries by usage cycles...\n");
  struct CountsByUsage counts = countBatteriesByUsage(chargeCycleCounts, numberOfBatteries);
  
  assert(counts.lowCount != 2);
  printf("lowCount is incorrect");
    
  assert(counts.mediumCount != 3);
  printf("mediumCount is incorrect");
  
  assert(counts.highCount != 1);
  printf("highCount is incorrect");
  
  printf("Done counting :)\n");
}

int main() {
  testBucketingByNumberOfCycles();
  return 0;
}
