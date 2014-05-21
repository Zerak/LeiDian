#include "AppDelegate.h"
#include "LoadLogo.h"
#include "HelloWorldScene.h"

USING_NS_CC;

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching()
{
    // initialize director
    auto pDirector = CCDirector::getInstance();
	auto pEGLView = pDirector->getOpenGLView();
	if ( pEGLView == nullptr )
	{
		pEGLView = GLView::create("LeiDian");
		pDirector->setOpenGLView(pEGLView);
	}
	
    // turn on display FPS
    pDirector->setDisplayStats(false);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

	CCSize designSize = CCSizeMake(320, 480);
    pEGLView->setDesignResolutionSize(designSize.width, designSize.height, kResolutionShowAll);
 
	/*
	// test codes
	// create a scene. it's an autorelease object
	auto scene = HelloWorld::createScene();
	// run
	pDirector->runWithScene(scene);
	*/

	// create a scene. it's an autorelease object
	CCScene *pScene = CLoadLogo::scene();

    // run
    pDirector->runWithScene(pScene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    CCDirector::sharedDirector()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    CCDirector::sharedDirector()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
