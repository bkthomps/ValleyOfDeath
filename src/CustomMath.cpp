/*
 * Math functionality which is not available from the standard library.
 */

#include "DragonFireSDK.h"
#include "CustomMath.h"

int round(double num) {
    return (int) ((num < 0) ? (num - 0.5) : (num + 0.5));
}
