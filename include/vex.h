#ifndef VEX_H
#define VEX_H
//default header below. DO NOT REMOVE!
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <string>//++
#include <iostream>//++
#include <sstream>//++
#include <cstring>//++
#include <cmath>//++

#include "v5.h"
#include "v5_vcs.h"

#include "robot-config.h"



#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)



#endif