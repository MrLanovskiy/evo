#include "Define.h"
#include "GossipDef.h"
#include "Item.h"
#include "Player.h"
#include "ScriptedGossip.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "Configuration/Config.h"

class premium_account2 : public PlayerScript
{
public:
    premium_account2() : PlayerScript("premium_account2") { }
void OnLogin(Player* player) 
    {
if (player->GetSession()->IsPremium())
{

player->learnSpell(80865);
player->learnSpell(69541);
player->GetSession()->SendNotification("|cffff6060[VIP]:|r Благодарим за покупку VIP аккаунта. В знак благодарности вы получили VIP заклинание|r!");
}
else{

player->removeSpell(80865, SPEC_MASK_ALL, false); 
player->removeSpell(69541, SPEC_MASK_ALL, false);
} 
   }


};

class premium_account3 : public PlayerScript
{
public:
    premium_account3() : PlayerScript("premium_account3") { }
void OnLogin(Player* player) 
    {
if (player->GetSession()->IsPremium2())
{

player->learnSpell(80866);
player->learnSpell(36031);
player->GetSession()->SendNotification("|cffff6060[VIP]:|r Благодарим за покупку VIP аккаунта. В знак благодарности вы получили VIP заклинание|r!");
}
else{

player->removeSpell(80866, SPEC_MASK_ALL, false); 
player->removeSpell(36031, SPEC_MASK_ALL, false);
} 
   }


};

class premium_account4 : public PlayerScript
{
public:
    premium_account4() : PlayerScript("premium_account4") { }
void OnLogin(Player* player) 
    {
if (player->GetSession()->IsPremium3())
{

player->learnSpell(80867);
player->learnSpell(39181);
player->GetSession()->SendNotification("|cffff6060[VIP]:|r Благодарим за покупку VIP аккаунта. В знак благодарности вы получили VIP заклинание|r!");
}
else{

player->removeSpell(80867, SPEC_MASK_ALL, false); 
player->removeSpell(39181, SPEC_MASK_ALL, false);
} 
   }


};

class premium_account5 : public PlayerScript
{
public:
    premium_account5() : PlayerScript("premium_account5") { }
void OnLogin(Player* player) 
    {
if (player->GetSession()->IsPremium4())
{

player->learnSpell(80868);
player->learnSpell(46599);
player->GetSession()->SendNotification("|cffff6060[VIP]:|r Благодарим за покупку VIP аккаунта. В знак благодарности вы получили VIP заклинание|r!");
}
else{

player->removeSpell(80868, SPEC_MASK_ALL, false);
player->removeSpell(46599, SPEC_MASK_ALL, false);
} 
   }

};

void AddSC_premium_account2()
{
    new premium_account2();
	new premium_account3();
	new premium_account4();
	new premium_account5();
}