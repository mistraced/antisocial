THEOS_PACKAGE_SCHEME = rootless
ARCHS = arm64
DEBUG = 1
FINALPACKAGE = 1
FOR_RELEASE = 0

PACKAGE_TIMESTAMP=$(shell date +%s)
PACKAGE_VERSION="${PACKAGE_TIMESTAMP}"

include $(THEOS)/makefiles/common.mk

TWEAK_NAME = antisocial

$(TWEAK_NAME)_FRAMEWORKS = UIKit Foundation Security QuartzCore CoreGraphics CoreText AVFoundation Accelerate GLKit SystemConfiguration GameController

$(TWEAK_NAME)_CCFLAGS = -I./antisocial -I./antisocial/src/cpp -I./antisocial/thirdparty -I./antisocial/thirdparty/imgui -std=c++20 -fno-rtti -fno-exceptions -DNDEBUG -fvisibility=hidden -Wc++11-narrowing -Wno-narrowing -Wundefined-bool-conversion -Wreturn-stack-address -Wno-error=format-security -fvisibility=hidden -fpermissive -fexceptions -w -Wno-error=format-security -fvisibility=hidden -Werror -fpermissive -Wall -fexceptions -Wno-module-import-in-extern-c
$(TWEAK_NAME)_CFLAGS = -I./antisocial -I./antisocial/src/cpp -I./antisocial/thirdparty -I./antisocial/thirdparty/imgui -fobjc-arc -Wno-deprecated-declarations -Wno-unused-variable -Wno-unused-value -fvisibility=hidden -Wc++11-narrowing -Wno-narrowing -Wundefined-bool-conversion -Wreturn-stack-address -Wno-error=format-security -fvisibility=hidden -fpermissive -fexceptions -w -Wno-error=format-security -fvisibility=hidden -Werror -fpermissive -Wall -fexceptions -Wno-module-import-in-extern-c

$(TWEAK_NAME)_FILES = $(shell find . -type f \( -iname "*.cpp" -o -iname "*.m" -o -iname "*.c" -o -iname "*.mm" \))

$(TWEAK_NAME)_LDFLAGS += -L./antisocial/thirdparty/dobby/
$(TWEAK_NAME)_LDFLAGS += -lz -ldobby

include $(THEOS_MAKE_PATH)/tweak.mk