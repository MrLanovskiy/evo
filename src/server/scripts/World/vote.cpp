#include "Define.h"
#include "GossipDef.h"
#include "Item.h"
#include "Player.h"
#include "ScriptedGossip.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "Configuration/Config.h"

class premium_account1 : public PlayerScript
{
public:
    premium_account1() : PlayerScript("premium_account1") { }
void OnLogin(Player* player) 
    {
if (player->GetSession()->IsPremium1())
{
player->learnSpell(80869);
player->GetSession()->SendNotification("|cffff6060[Система Голосования]:|r Благодарим Вас за то, что вы голосуете за наш сервер на MMOTOP и хотим подарить вам Premium баф|r!");
}
else{
player->removeSpell(80869, SPEC_MASK_ALL, false);
} 
   }


};


void AddSC_premium_account1()
{
    new premium_account1();
}