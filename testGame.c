#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "Game.h"

#define DEFAULT_DISCIPLINES {STUDENT_BQN, STUDENT_MMONEY, STUDENT_MJ, \
                STUDENT_MMONEY, STUDENT_MJ, STUDENT_BPS, STUDENT_MTV, \
                STUDENT_MTV, STUDENT_BPS,STUDENT_MTV, STUDENT_BQN, \
                STUDENT_MJ, STUDENT_BQN, STUDENT_THD, STUDENT_MJ, \
                STUDENT_MMONEY, STUDENT_MTV, STUDENT_BQN, STUDENT_BPS}
#define DEFAULT_DICE {9,10,8,12,6,5,3,11,3,11,4,6,4,7,9,2,8,10,5}


int check(int didPass, const char *testDescription) {
    fprintf(stderr, testDescription);
    fprintf(stderr, "... ");
    if (!didPass) {
        fprintf(stderr, "failed!\n");
    } else {
        fprintf(stderr, "passed!\n");
    }
    return !didPass;
}



int main(int argc, char *argv[]) {

    int disciplines[] = DEFAULT_DISCIPLINES;
    int dice[] = DEFAULT_DICE;

    int numFailed = 0;
    
    Game g = newGame(disciplines, dice);


    // TODO: write your tests on the Game here, using asserts

    //checking stuff for first turn...
    numFailed += check(getTurnNumber(g) == -1, "Checking start turn number is -1");
    numFailed += check(getWhoseTurn(g) == NO_ONE, "Checking it is no ones turn");
    numFailed += check(getMostPublications(g) == NO_ONE, "Checking that no one has most publications");
    numFailed += check(getMostARCs(g) == NO_ONE, "Checking no one has most ARCs");

    // clean up: keep your memory beautiful
    disposeGame(g);

    
    assert(numFailed == 0);
    printf("All tests passed, you are Awesome!\n");
	return EXIT_SUCCESS;

    return EXIT_SUCCESS;
}
