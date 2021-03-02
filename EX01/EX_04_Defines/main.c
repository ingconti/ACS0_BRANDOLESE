//
//  main.c
//  EX_04_Defines
//
//  Created by ing.conti on 01/03/21.
//

#include <stdio.h>


int main(int argc, const char * argv[]) {

    
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
   //define something for Windows (32-bit and 64-bit, this part is common)
   #ifdef _WIN64
      //define something for Windows (64-bit only)
   #else
      //define something for Windows (32-bit only)
   #endif
#elif __APPLE__
    printf("Hello, __APPLE__!\n");

    #if TARGET_IPHONE_SIMULATOR
         // iOS Simulator
    #elif TARGET_OS_IPHONE
        // iOS device
    #elif TARGET_OS_MAC
        // Other kinds of Mac OS
    #else
    #endif
#elif __linux__
    // linux
    printf("Hello, __linux__!\n");

#elif __unix__ // all unices not caught above
    // Unix

#elif defined(_POSIX_VERSION)
    // POSIX
#else
#endif

#ifdef DEBUG
//    printf("Hello, DEBUG!\n");

#endif

    return 0;
}
