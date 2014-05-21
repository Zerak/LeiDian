//
//  CCRadioMenu.cpp
//  SceneHello
//
//  Created by Orangef on 12-12-24.
//
//

#include "CCRadioMenu.h"
using namespace cocos2d;

CCRadioMenu* CCRadioMenu::create()
{
    return CCRadioMenu::create(NULL, NULL);
}

CCRadioMenu * CCRadioMenu::create(CCMenuItem* item, ...)
{
    va_list args;
    va_start(args,item);
    
    CCRadioMenu *pRet = CCRadioMenu::createWithItems(item, args);
    
    va_end(args);
    
    return pRet;
}

CCRadioMenu* CCRadioMenu::createWithItems(CCMenuItem* item, va_list args)
{
	Vector<MenuItem*> items;
	if( item )
	{
		items.pushBack(item);
		MenuItem *i = va_arg(args, MenuItem*);
		while(i)
		{
			items.pushBack(i);
			i = va_arg(args, MenuItem*);
		}
	}
    return CCRadioMenu::createWithArray( items );
}

CCRadioMenu* CCRadioMenu::createWithArray(const Vector<MenuItem*>& arrayOfItems)
{
    CCRadioMenu *pRet = new CCRadioMenu();
    if (pRet && pRet->initWithArray(arrayOfItems))
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    
    return pRet;
}

void CCRadioMenu::setSelectedItem_(CCMenuItem *item)
{
    _selectedItem = nullptr;
    _selectedItem = item;
}

bool CCRadioMenu::onTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    if (_state != kCCMenuStateWaiting) return false;
    CCMenuItem *curSelection = this->getItemForTouch(pTouch);
    if (curSelection)
	{
        curSelection->selected();
        _curHighlighted = curSelection;
        
        if (_curHighlighted)
		{
            if (_selectedItem && _selectedItem != curSelection)
			{
                _selectedItem->unselected();
            }
            _state = kCCMenuStateTrackingTouch;
            return true;
        }
    }
    return false;
}

void CCRadioMenu::onTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
    CCAssert(_state == kCCMenuStateTrackingTouch, "[Menu ccTouchEnded] -- invalid state");
    CCMenuItem *curSelection = this->getItemForTouch(pTouch);
    if (curSelection != _curHighlighted && curSelection != NULL)
	{
        _selectedItem->selected();
        _curHighlighted->unselected();
        _curHighlighted = NULL;
        _state = kCCMenuStateWaiting;
        return;
    }
    
    _selectedItem = _curHighlighted;
    _curHighlighted->activate();
    _curHighlighted = NULL;
    
    _state = kCCMenuStateWaiting;
}

void CCRadioMenu::onTouchCancelled(CCTouch *pTouch, CCEvent *pEvent)
{
    CCAssert(_state == kCCMenuStateTrackingTouch, "[Menu ccTouchCancelled] -- invalid state");
    _selectedItem->selected();
    _curHighlighted->unselected();
    _curHighlighted = NULL;
    
    _state = kCCMenuStateWaiting;
}

void CCRadioMenu::onTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
    CCAssert(_state == kCCMenuStateTrackingTouch, "[Menu ccTouchMoved] -- invalid state");
    CCMenuItem *curSelection = this->getItemForTouch(pTouch);
    if (curSelection != _curHighlighted && curSelection != NULL)
	{
        _curHighlighted->unselected();
        curSelection->selected();
        _curHighlighted = curSelection;
        return;
    }
}