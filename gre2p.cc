#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <re2/re2.h>
#include <re2/stringpiece.h>
#include <limits.h>

using namespace std;
using namespace re2;

