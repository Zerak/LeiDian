#include "GameOver.h"
#include "GameEvents.h"

CCScene* CGameOver::scene()
{
	CCScene * scene = NULL;
	while (true)
	{
		// 'scene' is an autorelease object
		scene = CCScene::create();
		CC_BREAK_IF(! scene);

		// 'layer' is an autorelease object
		CGameOver *layer = CGameOver::create();
		CC_BREAK_IF(! layer);

		// add layer as a child to scene
		scene->addChild(layer);

		break;
	}

	// return the scene
	return scene;
}

bool CGameOver::init()
{
	bool bRet = false;

	while (true)
	{
		CCSize size = CCDirector::sharedDirector()->getWinSize();

		//	背景	
		CCSprite *pBackGround = CCSprite::create("Image/GameOver.png");
		CC_BREAK_IF(! pBackGround);
		pBackGround->setPosition(ccp(size.width/2, size.height/2));
		this->addChild(pBackGround, 0);

		// 设置返回按钮
		CCMenuItemImage *pBack = CCMenuItemImage::create();       
		pBack->setCallback( CC_CALLBACK_1( CGameOver::back, this) );
		pBack->setNormalSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("CloseNormal.png"));  
		pBack->setSelectedSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("CloseSelected.png"));
		pBack->setPosition(ccp(size.width - 39, 21));

		// 添加菜单
		CCMenu *pMenu = CCMenu::create(pBack, NULL);
		pMenu->setPosition(ccp(0, 0));
		this->addChild(pMenu, 6);

		bRet = true;

		break;
	}

	return bRet;
}

void CGameOver::back(CCObject* pSender)
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Music/Title.mp3", true);
	CGameEvents::startFlipInterface(GAME_MENU);
}