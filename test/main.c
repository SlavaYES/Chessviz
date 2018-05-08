#define CTEST_MAIN

#include "conios.h"
#include "board_read.h"
#include "board_print_plain.h"
#include "board.h"
#include <ctest.h>

//CORRECT

int  n=9, m=9+1;

CTEST (W_Peshka, Correct_p_forward)
{
    char xod[6], a[n][m];
    xod[0]='P';
    xod[1]='e';
    xod[2]='7';
    xod[3]='-';
    xod[4]='e';
    xod[5]='6';
    for (int i=0; i<n; i++) {
	for (int j=0; j<m; j++) {
	    a[i][j]=' ';
	}
    }
    a[4][7]='P';
    a[4][6]=' ';
    int result=check(a, xod, 1);
    int expected=0;
    ASSERT_EQUAL(expected, result);
}

CTEST (B_Peshka, Correct_p_forward)
{
    char xod[6], a[n][m];
    xod[0]='P';
    xod[1]='e';
    xod[2]='2';
    xod[3]='-';
    xod[4]='e';
    xod[5]='4';
    for (int i=0; i<n; i++) {
	for (int j=0; j<m; j++) {
	    a[i][j]=' ';
	}
    }
    a[4][2]='p';
    a[4][3]=' ';
    int result=check(a, xod, 0);
    int expected=0;
    ASSERT_EQUAL(expected, result);
}

CTEST (W_Peshka, Correct_p_hack)
{
    char xod[6], a[n][m];
    xod[0]='P';
    xod[1]='e';
    xod[2]='7';
    xod[3]='x';
    xod[4]='f';
    xod[5]='6';
    for (int i=0; i<n; i++) {
	for (int j=0; j<m; j++) {
	    a[i][j]=' ';
	}
    }
    a[4][7]='P';
    a[5][6]='p';
    int result=check(a, xod, 1);
    int expected=0;
    ASSERT_EQUAL(expected, result);
}

CTEST (B_Peshka, Correct_p_hack)
{
    char xod[6], a[n][m];
    xod[0]='P';
    xod[1]='e';
    xod[2]='2';
    xod[3]='x';
    xod[4]='f';
    xod[5]='4';
    for (int i=0; i<n; i++) {
	for (int j=0; j<m; j++) {
	    a[i][j]=' ';
	}
    }
    a[4][2]='p';
    a[5][3]='P';
    int result=check(a, xod, 0);
    int expected=0;
    ASSERT_EQUAL(expected, result);
}

CTEST (W_Rook, Correct_Rook_h)
{
    char xod[6], a[n][m];
    xod[0]='R';
    xod[1]='a';
    xod[2]='8';
    xod[3]='x';
    xod[4]='a';
    xod[5]='3';
    for (int i=0; i<n; i++) {
	for (int j=0; j<m; j++) {
	    a[i][j]=' ';
	}
    }
    a[1][8]='R';
    a[1][3]='n';
    int result=check(a, xod, 1);
    int expected=0;
    ASSERT_EQUAL(expected, result);
}

CTEST (B_Rook, Correct_Rook_f)
{
    char xod[6], a[n][m];
    xod[0]='R';
    xod[1]='a';
    xod[2]='1';
    xod[3]='-';
    xod[4]='a';
    xod[5]='3';
    for (int i=0; i<n; i++) {
	for (int j=0; j<m; j++) {
	    a[i][j]=' ';
	}
    }
    a[1][1]='R';
    a[1][3]=' ';
    int result=check(a, xod, 0);
    int expected=0;
    ASSERT_EQUAL(expected, result);
}


CTEST (W_Horse, Correct_Knight_h)
{
    char xod[6], a[n][m];
    xod[0]='N';
    xod[1]='b';
    xod[2]='8';
    xod[3]='x';
    xod[4]='a';
    xod[5]='6';
    for (int i=0; i<n; i++) {
	for (int j=0; j<m; j++) {
	    a[i][j]=' ';
	}
    }
    a[2][8]='N';
    a[1][6]='r';
    int result=check(a, xod, 1);
    int expected=0;
    ASSERT_EQUAL(expected, result);
}


CTEST (B_Horse, Correct_Knight_f)
{
    char xod[6], a[n][m];
    xod[0]='N';
    xod[1]='b';
    xod[2]='1';
    xod[3]='-';
    xod[4]='a';
    xod[5]='3';
    for (int i=0; i<n; i++) {
	for (int j=0; j<m; j++) {
	    a[i][j]=' ';
	}
    }
    a[2][1]='n';
    a[1][3]=' ';
    int result=check(a, xod, 0);
    int expected=0;
    ASSERT_EQUAL(expected, result);
}

CTEST (B_Bishop, Correct_Bishop_f)
{
    char xod[6], a[n][m];
    xod[0]='B';
    xod[1]='c';
    xod[2]='1';
    xod[3]='x';
    xod[4]='a';
    xod[5]='3';
    for (int i=0; i<n; i++) {
	for (int j=0; j<m; j++) {
	    a[i][j]=' ';
	}
    }
    a[3][1]='b';
    a[1][3]='Q';
    int result=check(a, xod, 0);
    int expected=0;
    ASSERT_EQUAL(expected, result);
}

CTEST (W_Bishop, Correct_Bishop_h)
{
    char xod[6], a[n][m];
    xod[0]='B';
    xod[1]='c';
    xod[2]='8';
    xod[3]='-';
    xod[4]='a';
    xod[5]='6';
    for (int i=0; i<n; i++) {
	for (int j=0; j<m; j++) {
	    a[i][j]=' ';
	}
    }
    a[3][8]='B';
    a[1][6]=' ';
    int result=check(a, xod, 1);
    int expected=0;
    ASSERT_EQUAL(expected, result);
}

CTEST (W_Queen, Correct_Queen_h)
{
    char xod[6], a[n][m];
    xod[0]='Q';
    xod[1]='d';
    xod[2]='8';
    xod[3]='x';
    xod[4]='d';
    xod[5]='2';
    for (int i=0; i<n; i++) {
	for (int j=0; j<m; j++) {
	    a[i][j]=' ';
	}
    }
    a[4][8]='Q';
    a[4][2]='p';
    int result=check(a, xod, 1);
    int expected=0;
    ASSERT_EQUAL(expected, result);
}

CTEST (B_Queen, Correct_Queen_f)
{
    char xod[6], a[n][m];
    xod[0]='Q';
    xod[1]='d';
    xod[2]='1';
    xod[3]='-';
    xod[4]='d';
    xod[5]='2';
    for (int i=0; i<n; i++) {
	for (int j=0; j<m; j++) {
	    a[i][j]=' ';
	}
    }
    a[4][1]='q';
    a[4][2]=' ';
    int result=check(a, xod, 0);
    int expected=0;
    ASSERT_EQUAL(expected, result);
}

CTEST (B_King, Correct_King_f)
{
    char xod[6], a[n][m];
    xod[0]='K';
    xod[1]='e';
    xod[2]='1';
    xod[3]='-';
    xod[4]='e';
    xod[5]='2';
    for (int i=0; i<n; i++) {
	for (int j=0; j<m; j++) {
	    a[i][j]=' ';
	}
    }
    a[5][1]='k';
    a[5][2]=' ';
    int result=check(a, xod, 0);
    int expected=0;
    ASSERT_EQUAL(expected, result);
}

CTEST (W_King, Correct_King_h)
{
    char xod[6], a[n][m];
    xod[0]='K';
    xod[1]='e';
    xod[2]='8';
    xod[3]='x';
    xod[4]='d';
    xod[5]='7';
    for (int i=0; i<n; i++) {
	for (int j=0; j<m; j++) {
	    a[i][j]=' ';
	}
    }
    a[4][8]='K';
    a[4][7]='n';
    int result=check(a, xod, 1);
    int expected=0;
    ASSERT_EQUAL(expected, result);
}

//INCORRECT

CTEST (W_Peshka, InCorrect_p_forward)
{
    char xod[6], a[n][m];
    xod[0]='P';
    xod[1]='e';
    xod[2]='7';
    xod[3]='-';
    xod[4]='e';
    xod[5]='6';
    for (int i=0; i<n; i++) {
	for (int j=0; j<m; j++) {
	    a[i][j]=' ';
	}
    }
    a[4][7]='P';
    a[4][6]='p';
    int result=check(a, xod, 1);
    int expected=0;
    ASSERT_EQUAL(expected, result);
}

CTEST (B_Peshka, InCorrect_p_forward)
{
    char xod[6], a[n][m];
    xod[0]='P';
    xod[1]='e';
    xod[2]='2';
    xod[3]='-';
    xod[4]='e';
    xod[5]='4';
    for (int i=0; i<n; i++) {
	for (int j=0; j<m; j++) {
	    a[i][j]=' ';
	}
    }
    a[4][2]='p';
    a[4][3]='P';
    int result=check(a, xod, 0);
    int expected=0;
    ASSERT_EQUAL(expected, result);
}

CTEST (W_Peshka, InCorrect_p_hack)
{
    char xod[6], a[n][m];
    xod[0]='P';
    xod[1]='e';
    xod[2]='7';
    xod[3]='x';
    xod[4]='f';
    xod[5]='6';
    for (int i=0; i<n; i++) {
	for (int j=0; j<m; j++) {
	    a[i][j]=' ';
	}
    }
    a[4][7]='P';
    a[5][6]=' ';
    int result=check(a, xod, 1);
    int expected=1;
    ASSERT_EQUAL(expected, result);
}

CTEST (B_Peshka, InCorrect_p_hack)
{
    char xod[6], a[n][m];
    xod[0]='P';
    xod[1]='e';
    xod[2]='2';
    xod[3]='x';
    xod[4]='f';
    xod[5]='4';
    for (int i=0; i<n; i++) {
	for (int j=0; j<m; j++) {
	    a[i][j]=' ';
	}
    }
    a[4][2]='p';
    a[5][3]=' ';
    int result=check(a, xod, 0);
    int expected=0;
    ASSERT_EQUAL(expected, result);
}

CTEST (W_Rook, InCorrect_Rook_h)
{
    char xod[6], a[n][m];
    xod[0]='R';
    xod[1]='a';
    xod[2]='8';
    xod[3]='x';
    xod[4]='a';
    xod[5]='3';
    for (int i=0; i<n; i++) {
	for (int j=0; j<m; j++) {
	    a[i][j]=' ';
	}
    }
    a[1][8]='R';
    a[1][3]=' ';
    int result=check(a, xod, 1);
    int expected=0;
    ASSERT_EQUAL(expected, result);
}

CTEST (B_Rook, InCorrect_Rook_f)
{
    char xod[6], a[n][m];
    xod[0]='R';
    xod[1]='a';
    xod[2]='1';
    xod[3]='-';
    xod[4]='a';
    xod[5]='3';
    for (int i=0; i<n; i++) {
	for (int j=0; j<m; j++) {
	    a[i][j]=' ';
	}
    }
    a[1][1]='R';
    a[1][3]='n';
    int result=check(a, xod, 0);
    int expected=1;
    ASSERT_EQUAL(expected, result);
}


CTEST (W_Horse, InCorrect_Knight_h)
{
    char xod[6], a[n][m];
    xod[0]='N';
    xod[1]='b';
    xod[2]='8';
    xod[3]='x';
    xod[4]='a';
    xod[5]='6';
    for (int i=0; i<n; i++) {
	for (int j=0; j<m; j++) {
	    a[i][j]=' ';
	}
    }
    a[2][8]='N';
    a[1][6]=' ';
    int result=check(a, xod, 1);
    int expected=0;
    ASSERT_EQUAL(expected, result);
}


CTEST (B_Horse, InCorrect_Knight_f)
{
    char xod[6], a[n][m];
    xod[0]='N';
    xod[1]='b';
    xod[2]='1';
    xod[3]='-';
    xod[4]='a';
    xod[5]='3';
    for (int i=0; i<n; i++) {
	for (int j=0; j<m; j++) {
	    a[i][j]=' ';
	}
    }
    a[2][1]='n';
    a[1][3]='K';
    int result=check(a, xod, 0);
    int expected=0;
    ASSERT_EQUAL(expected, result);
}

CTEST (B_Bishop, InCorrect_Bishop_f)
{
    char xod[6], a[n][m];
    xod[0]='B';
    xod[1]='c';
    xod[2]='1';
    xod[3]='x';
    xod[4]='a';
    xod[5]='3';
    for (int i=0; i<n; i++) {
	for (int j=0; j<m; j++) {
	    a[i][j]=' ';
	}
    }
    a[3][1]='b';
    a[1][3]='Q';
    int result=check(a, xod, 0);
    int expected=1;
    ASSERT_EQUAL(expected, result);
}

CTEST (W_Bishop, InCorrect_Bishop_h)
{
    char xod[6], a[n][m];
    xod[0]='B';
    xod[1]='c';
    xod[2]='8';
    xod[3]='-';
    xod[4]='a';
    xod[5]='6';
    for (int i=0; i<n; i++) {
	for (int j=0; j<m; j++) {
	    a[i][j]=' ';
	}
    }
    a[3][8]='B';
    a[1][6]='K';
    int result=check(a, xod, 1);
    int expected=0;
    ASSERT_EQUAL(expected, result);
}

CTEST (W_Queen, InCorrect_Queen_h)
{
    char xod[6], a[n][m];
    xod[0]='Q';
    xod[1]='d';
    xod[2]='8';
    xod[3]='x';
    xod[4]='d';
    xod[5]='2';
    for (int i=0; i<n; i++) {
	for (int j=0; j<m; j++) {
	    a[i][j]=' ';
	}
    }
    a[4][8]='Q';
    a[4][2]=' ';
    int result=check(a, xod, 1);
    int expected=0;
    ASSERT_EQUAL(expected, result);
}

CTEST (B_Queen, InCorrect_Queen_f)
{
    char xod[6], a[n][m];
    xod[0]='Q';
    xod[1]='d';
    xod[2]='1';
    xod[3]='-';
    xod[4]='d';
    xod[5]='2';
    for (int i=0; i<n; i++) {
	for (int j=0; j<m; j++) {
	    a[i][j]=' ';
	}
    }
    a[4][1]='q';
    a[4][2]='K';
    int result=check(a, xod, 0);
    int expected=1;
    ASSERT_EQUAL(expected, result);
}

CTEST (B_King, InCorrect_King_f)
{
    char xod[6], a[n][m];
    xod[0]='K';
    xod[1]='e';
    xod[2]='1';
    xod[3]='-';
    xod[4]='d';
    xod[5]='2';
    for (int i=0; i<n; i++) {
	for (int j=0; j<m; j++) {
	    a[i][j]=' ';
	}
    }
    a[4][1]='k';
    a[4][2]='K';
    int result=check(a, xod, 0);
    int expected=0;
    ASSERT_EQUAL(expected, result);
}

CTEST (W_King, InCorrect_King_h)
{
    char xod[6], a[n][m];
    xod[0]='K';
    xod[1]='e';
    xod[2]='8';
    xod[3]='-';
    xod[4]='d';
    xod[5]='7';
    for (int i=0; i<n; i++) {
	for (int j=0; j<m; j++) {
	    a[i][j]=' ';
	}
    }
    a[4][8]='K';
    a[4][7]=' ';
    int result=check(a, xod, 1);
    int expected=0;
    ASSERT_EQUAL(expected, result);
}

int main(int argc, const char** argv)
{
    int test_result = ctest_main(argc, argv);
    return test_result;
}