#ifndef LIGHTTPATERNS_H
#define LIGHTTPATERNS_H

// Array of lightpatterns to be accessed.
// Call like that: (*lightPatterns[i])();
void (*lightPatterns[99])();

// Lightpatterns
void pattern0();
void pattern1();
void pattern2();
void pattern3();
void pattern4();
void pattern5();

#endif
