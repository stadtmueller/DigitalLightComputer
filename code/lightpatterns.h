#ifndef LIGHTTPATERNS_H
#define LIGHTTPATERNS_H

#ifndef LIGHTPORT
#define LIGHTPORT PORTA
#endif

#define PORTMAX 0b11111111

// Array of lightpatterns to be accessed.
// Call like that: (*lightPatterns[i])();
int (*lightPatterns[99])(void);

// Lightpatterns
int pattern0();
int pattern1();
int pattern2();
int pattern3();
int pattern4();
int pattern5();
int pattern6();
int pattern7();
int pattern8();
int pattern9();
int pattern10();
int pattern11();

#endif
