LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/UnitSprite.cpp \
                   ../../Classes/RoleSprite.cpp \
                   ../../Classes/PlayerSprite.cpp \
                   ../../Classes/MoveTrackArray.cpp \
                   ../../Classes/LoadLogo.cpp \
                   ../../Classes/ItemSprite.cpp \
                   ../../Classes/ItemManager.cpp \
                   ../../Classes/HelloWorldScene.cpp \
                   ../../Classes/GameOver.cpp \
                   ../../Classes/GameMessage.cpp \
                   ../../Classes/GameMenu.cpp \
                   ../../Classes/GameMap.cpp \
                   ../../Classes/GameManager.cpp \
                   ../../Classes/GameLevel.cpp \
                   ../../Classes/GameEvents.cpp \
                   ../../Classes/EnemySprite.cpp \
                   ../../Classes/EnemyManager.cpp \
                   ../../Classes/Effect.cpp \
                   ../../Classes/CCRadioMenu.cpp \
                   ../../Classes/BulletSprite.cpp \
                   ../../Classes/BulletManager.cpp \
                   ../../Classes/BossSprite.cpp \
                   ../../Classes/AppDelegate.cpp \

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocosdenshion_static
LOCAL_WHOLE_STATIC_LIBRARIES += box2d_static


include $(BUILD_SHARED_LIBRARY)

$(call import-module,2d)
$(call import-module,audio/android)
$(call import-module,Box2D)
