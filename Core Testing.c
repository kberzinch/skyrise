#define NoLCD
#define NoInit
#define NoProgrammingSkills
#define HasGyro
#include "core\v3\core.h"

void ResetDriveEncoders() {
#if defined(_DEBUG)
    writeDebugStreamLine("Drive encoders reset");
#endif
}
