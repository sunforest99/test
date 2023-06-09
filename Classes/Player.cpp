#include "stdafx.h"

Player::Player()
{
	_hp = 1;
}

void Player::InitObject()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	auto mainsprite = SpriteFrameCache::getInstance();
	mainsprite->addSpriteFramesWithFile("player.plist");

	_player = Sprite::createWithSpriteFrameName("pink_body.png");
	_player->setScale(D_BASE_SACLE);
	_player->setPosition(Vec2(visibleSize.width /2 , D_PLAYER_HEIGHT));

	// ---- ����
	_lwing = Sprite::createWithSpriteFrameName("pink_wing.png");
	_rwing = Sprite::createWithSpriteFrameName("pink_wing.png");
	
	_parent = _player->getContentSize();

	_lwing->setPosition(Vec2(_parent.width / 2.f - 40.f, _parent.height / 2.f));
	_rwing->setPosition(Vec2(_parent.width / 2.f + 40.f, _parent.height / 2.f));

	_rwing->setFlipX(true);

	auto rwingreduce = ScaleTo::create(0.5f,0.9f);
	auto rwingincrease = ScaleTo::create(0.5f, 1.1f);
	auto rseq = Sequence::create(rwingreduce, rwingincrease, nullptr);

	auto lwingreduce = ScaleTo::create(0.5f, 0.9f);
	auto lwingincrease = ScaleTo::create(0.5f, 1.1f);
	auto lseq = Sequence::create(lwingreduce, lwingincrease, nullptr);

	RepeatForever* ractionrepeat = RepeatForever::create(rseq);
	RepeatForever* lactionrepeat = RepeatForever::create(lseq);

	_rwing->runAction(ractionrepeat);
	_lwing->runAction(lactionrepeat);

	_player->addChild(_rwing, INGAME_ZORDER::E_WINGS);
	_player->addChild(_lwing, INGAME_ZORDER::E_WINGS);

	this->addChild(_player);
}

void Player::DamageInit()
{
	_damage = Sprite::create("damage.png");
	_damage->setPosition(_player->getPosition());
	this->addChild(_damage);
}

void Player::Update()
{
}
