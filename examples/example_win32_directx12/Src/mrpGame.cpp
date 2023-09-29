#include "mrpGame.h"
#include <stdlib.h>

namespace mrp {
    int roll() {
        return rand() % 20 + 1; 
    }
}
