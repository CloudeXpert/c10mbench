#include <stdio.h>

/***************************************************************************
 ***************************************************************************/
void
print_version()
{
    const char *cpu = "unknown";
    const char *compiler = "unknown";
    const char *compiler_version = "unknown";
    const char *os = "unknown";
    printf("\n");
    printf("c10mbench version %s ( %s )\n", 
           "1.0",
           "https://github.com/robertdavidgraham/c10mbench"
           );
    printf("Compiled on: %s %s\n", __DATE__, __TIME__);
    
#if defined(_MSC_VER)
#if defined(_M_AMD64) || defined(_M_X64)
    cpu = "x86";
#elif defined(_M_IX86)
    cpu = "x86";
#elif defined (_M_ARM_FP)
    cpu = "arm";
#endif
    
    {
        int msc_ver = _MSC_VER;
        
        compiler = "VisualStudio";
        
        if (msc_ver < 1500)
            compiler_version = "pre2008";
        else if (msc_ver == 1500)
            compiler_version = "2008";
        else if (msc_ver == 1600)
            compiler_version = "2010";
        else if (msc_ver == 1700)
            compiler_version = "2012";
        else if (msc_ver == 1800)
            compiler_version = "2013";
        else
            compiler_version = "post-2013";
    }
    
    
#elif defined(__GNUC__)
    compiler = "gcc";
    compiler_version = __VERSION__;
    
#if defined(i386) || defined(__i386) || defined(__i386__)
    cpu = "x86";
#endif
    
#if defined(__corei7) || defined(__corei7__)
    cpu = "x86-Corei7";
#endif
    
#endif
    
#if defined(WIN32)
    os = "Windows";
#elif defined(__linux__)
    os = "Linux";
#elif defined(__APPLE__)
    os = "Apple";
#elif defined(__MACH__)
    os = "MACH";
#elif defined(__FreeBSD__)
    os = "FreeBSD";
#elif defined(unix) || defined(__unix) || defined(__unix__)
    os = "Unix";
#endif
    
    printf("Compiler: %s %s\n", compiler, compiler_version);
    printf("OS: %s\n", os);
    printf("CPU: %s (%u bits)\n", cpu, (unsigned)(sizeof(void*))*8);
    
#if defined(GIT)
    printf("GIT version: %s\n", GIT);
#endif
}
