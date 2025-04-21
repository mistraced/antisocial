ARCHS = arm64
DEBUG = 0
FINALPACKAGE = 1
FOR_RELEASE = 1

include $(THEOS)/makefiles/common.mk

TWEAK_NAME = antisocial

$(TWEAK_NAME)_FRAMEWORKS = UIKit Foundation Security QuartzCore CoreGraphics CoreText AVFoundation Accelerate GLKit SystemConfiguration GameController

$(TWEAK_NAME)_CCFLAGS = -I./antisocial -I./antisocial/thirdparty/imgui -std=c++17 -fno-rtti -fno-exceptions -DNDEBUG
$(TWEAK_NAME)_CFLAGS = -I./antisocial -I./antisocial/thirdparty/imgui -fobjc-arc -Wno-deprecated-declarations -Wno-unused-variable -Wno-unused-value

$(TWEAK_NAME)_FILES = $(shell find . -type f \( -iname "*.cpp" -o -iname "*.m" -o -iname "*.c" -o -iname "*.mm" \))

include $(THEOS_MAKE_PATH)/tweak.mk


