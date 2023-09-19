#include "Define.h"
#include "GossipDef.h"
#include "Player.h"
#include "ScriptedGossip.h"
#include "ScriptMgr.h"

#include "Language.h"

#define CONST_ARENA_RENAME 500
#define CONST_ARENA_CUSTOMIZE 500
#define CONST_ARENA_CHANGE_FACTION 1000
#define CONST_ARENA_CHANGE_RACE 1000

#define EMOTE_NO_VIP "Ты не VIP..."
#define EMOTE_COMBAT "Ты в бою!"
#define MSG_CHANGE_FACTION_COMPLETE "Успешно, сделайте релог!!" 
#define MSG_CHANGE_RACE_COMPLETE "Успешно, сделайте релог!!"
#define MSG_MAX_SKILL "Все умения - максимум!"
#define MSG_RIDING_COMPLETE "Ваша верховая езда - максимум!"
#define MSG_RESET_COOLDOWN "Ваши кулдауны обновлены!"
#define MSG_CHARACTER_SAVE_TO_DB "Игрок сохранен!"
#define ITEM_COMPARE_ENTRY 20558
#define ITEM_COMPARE_COUNT 1
#define notvip "У вас нет V.I.P доступа,купите V.I.P ранг,потом возвращайтесь ко мне."
#define yesvip "Добро пожаловать,вы являетесь V.I.P пользователем."
#define skillsmaxed "Ваши навыки были повышены до максимума."
#define votewhisper "Время, чтобы голосовать"
#define donationhelp "В любой момент вы можете сделать пожертвование,не забывайте об этом:)"
#define normalhelp "Если вам нужна помощь,спрашивайте"
#define ingamehelp "Если вам нужна помощь,обратитесь к Гейм Мастеру"
#define nosickness "На вас нет маски смерти."
#define nopet "У вас нет петомца"

class npc_premium_master2 : public CreatureScript
{
public:
    npc_premium_master2() : CreatureScript("npc_premium_master2") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
     
     if (!player->GetSession()->IsPremium2())
     
     {
        ClearGossipMenuFor(player);
        creature->Whisper(EMOTE_NO_VIP, LANG_UNIVERSAL, player);
        return true;
     }
        player->PlayerTalkClass->ClearMenus();
        AddGossipItemFor(player, GOSSIP_ICON_DOT, "Сохранить", GOSSIP_SENDER_MAIN, 1213);
        //AddGossipItemFor(player, GOSSIP_ICON_DOT, "VIP Бафф", GOSSIP_SENDER_MAIN, 1216);
        AddGossipItemFor(player, GOSSIP_ICON_DOT, "Сбросить таланты", GOSSIP_SENDER_MAIN, 1207);
        AddGossipItemFor(player, GOSSIP_ICON_DOT, "Сброс маски смерти", GOSSIP_SENDER_MAIN, 1212);
       // AddGossipItemFor(player, GOSSIP_ICON_DOT, "Сброс дезертира", GOSSIP_SENDER_MAIN, 1204);
        //AddGossipItemFor(player, GOSSIP_ICON_DOT, "Починить всю экипировку", GOSSIP_SENDER_MAIN, 1211);
        //AddGossipItemFor(player,3, "Сброс КД инстов", GOSSIP_SENDER_MAIN, 1215);
        AddGossipItemFor(player, GOSSIP_ICON_DOT, "Реагенты", GOSSIP_SENDER_MAIN, 111);
		//AddGossipItemFor(player, GOSSIP_ICON_DOT, "Банк", GOSSIP_SENDER_MAIN, 112);
		AddGossipItemFor(player, GOSSIP_ICON_DOT, "Почта", GOSSIP_SENDER_MAIN, 113);
		//AddGossipItemFor(player,3, "Аукцион", GOSSIP_SENDER_MAIN, 114);
        //AddGossipItemFor(player,9, "Маунты ->", GOSSIP_SENDER_MAIN, 1208);
        //AddGossipItemFor(player, GOSSIP_ICON_DOT, "Морфы ->", GOSSIP_SENDER_MAIN, 1203);
        //AddGossipItemFor(player,0, "Баффы", GOSSIP_SENDER_MAIN, 1206);
        AddGossipItemFor(player,8, "Видео ->", GOSSIP_SENDER_MAIN, 1214);
        //AddGossipItemFor(player, GOSSIP_ICON_BATTLE, "[Меню телепортации]" , GOSSIP_SENDER_MAIN, 1);
        SendGossipMenuFor(player, 1, creature->GetGUID());
         return true;
	}

	bool OnGossipSelect(Player* player, Creature* creature, uint32 uiSender, uint32 action)
	{
            if (!player->getAttackers().empty())
            {
                creature->Whisper(EMOTE_COMBAT, LANG_UNIVERSAL, player);
                SendGossipMenuFor(player, 1, creature->GetGUID());
                return false;
            }

            player->PlayerTalkClass->ClearMenus();

          switch (action)
          {
            case 1207: // Reset talents
                player->resetTalents(true);
            player->SendTalentsInfoData(false);
			player->GetSession()->SendNotification("Вы успешно сбросили ваши таланты.");	
			player->PlayerTalkClass->SendCloseGossip();
            break;            case 1203: // Morphs
                //player->PlayerTalkClass->ClearMenus();
                //AddGossipItemFor(player, GOSSIP_ICON_DOT, "Король-Лич", GOSSIP_SENDER_MAIN, 499);
                //AddGossipItemFor(player, GOSSIP_ICON_DOT, "Принц Артас", GOSSIP_SENDER_MAIN, 500);
                //AddGossipItemFor(player, GOSSIP_ICON_DOT, "Сильвана Ветрокрылая", GOSSIP_SENDER_MAIN, 501);
                //AddGossipItemFor(player, GOSSIP_ICON_DOT, "Джайна Праудмур", GOSSIP_SENDER_MAIN, 502);
                //AddGossipItemFor(player, GOSSIP_ICON_DOT, "Тралл", GOSSIP_SENDER_MAIN, 503);
                //AddGossipItemFor(player, GOSSIP_ICON_DOT, "Вариан Ринн", GOSSIP_SENDER_MAIN, 504);
                //AddGossipItemFor(player, GOSSIP_ICON_DOT, "Железный ремонтник", GOSSIP_SENDER_MAIN, 506);
                //AddGossipItemFor(player, GOSSIP_ICON_DOT, "Друид", GOSSIP_SENDER_MAIN, 507);
                //AddGossipItemFor(player, GOSSIP_ICON_DOT, "Жрец", GOSSIP_SENDER_MAIN, 508);
                //AddGossipItemFor(player, GOSSIP_ICON_DOT, "Паладин", GOSSIP_SENDER_MAIN, 509);
                //AddGossipItemFor(player, GOSSIP_ICON_DOT, "Разбойник", GOSSIP_SENDER_MAIN, 510);
                //AddGossipItemFor(player, GOSSIP_ICON_DOT, "Рыцарь Смерти", GOSSIP_SENDER_MAIN, 511);
                //AddGossipItemFor(player, GOSSIP_ICON_DOT, "Чернокнижник", GOSSIP_SENDER_MAIN, 512);
                //AddGossipItemFor(player, GOSSIP_ICON_DOT, "Воин", GOSSIP_SENDER_MAIN, 513);
                //AddGossipItemFor(player, GOSSIP_ICON_DOT, "Маг", GOSSIP_SENDER_MAIN, 514);
                //AddGossipItemFor(player, GOSSIP_ICON_DOT, "Шаман", GOSSIP_SENDER_MAIN, 515);
                //AddGossipItemFor(player, GOSSIP_ICON_DOT, "Охотник", GOSSIP_SENDER_MAIN, 516);
                //AddGossipItemFor(player, GOSSIP_ICON_DOT, "Девушка дреней (White)", GOSSIP_SENDER_MAIN, 517);
                //AddGossipItemFor(player, GOSSIP_ICON_DOT, "Девушка дреней (Black)", GOSSIP_SENDER_MAIN, 518);
                //AddGossipItemFor(player,0, "Деморф", GOSSIP_SENDER_MAIN, 519);
                //SendGossipMenuFor(player, 1, creature->GetGUID());(DEFAULT_GOSSIP_MESSAGE,creature->GetGUID());
                break;
            case 499:
                SendGossipMenuFor(player, 1, creature->GetGUID()); // Starcraft Murlock
                player->SetDisplayId(24191);
                break;
            case 500:
                SendGossipMenuFor(player, 1, creature->GetGUID()); // Ambrose Boltspark
                player->SetDisplayId(24641);
                break;
            case 501:
                SendGossipMenuFor(player, 1, creature->GetGUID()); // Jonathan The Revelator
                player->SetDisplayId(28213);
                break;
            case 502:
                SendGossipMenuFor(player, 1, creature->GetGUID()); // Shattered Sun Magi
                player->SetDisplayId(30865);
                break;
            case 503:
                SendGossipMenuFor(player, 1, creature->GetGUID()); // Worgen
                player->SetDisplayId(4527);
                break;
            case 504:
                SendGossipMenuFor(player, 1, creature->GetGUID()); // Pandaren Monk
                player->SetDisplayId(28127);
                break;
            case 505:
                SendGossipMenuFor(player, 1, creature->GetGUID()); // Crok Scourgebane
                player->SetDisplayId(30911);
                break;
            case 506:
                SendGossipMenuFor(player, 1, creature->GetGUID()); // Iron Mender
                player->SetDisplayId(26239);
                break;
            case 507:
                SendGossipMenuFor(player, 1, creature->GetGUID()); // Druid
                player->SetDisplayId(30472);
                break;
            case 508:
                SendGossipMenuFor(player, 1, creature->GetGUID()); // Priest
                player->SetDisplayId(21419);
                break;
            case 509:
                SendGossipMenuFor(player, 1, creature->GetGUID()); // Paladin
                player->SetDisplayId(29774);
                break;
            case 510:
                SendGossipMenuFor(player, 1, creature->GetGUID()); // Rogue
                player->SetDisplayId(30485);
                break;
            case 511:
                SendGossipMenuFor(player, 1, creature->GetGUID()); // Death Knight
                player->SetDisplayId(27153);
                break;
            case 512:
                SendGossipMenuFor(player, 1, creature->GetGUID()); // Warlock
                player->SetDisplayId(30487);
                break;
            case 513:
                SendGossipMenuFor(player, 1, creature->GetGUID()); // Warrior
                player->SetDisplayId(30474);
                break;
            case 514:
                SendGossipMenuFor(player, 1, creature->GetGUID()); // Mage
                player->SetDisplayId(30477);
                break;
            case 515:
                SendGossipMenuFor(player, 1, creature->GetGUID()); // Shaman
                player->SetDisplayId(29768);
                break;
            case 516:
                SendGossipMenuFor(player, 1, creature->GetGUID()); // Hunter
                player->SetDisplayId(21379);
                break;
            case 517:
                SendGossipMenuFor(player, 1, creature->GetGUID()); // Coliseum Champion
                player->SetDisplayId(30634);
                break;
            case 518:
                SendGossipMenuFor(player, 1, creature->GetGUID()); // Coliseum Champion
                player->SetDisplayId(30771);
                break;
            case 519: // Demorph Player (remove all morphs)
                SendGossipMenuFor(player, 1, creature->GetGUID());
                player->DeMorph();
                break;
            case 1206: // Buffs
               SendGossipMenuFor(player, 1, creature->GetGUID());
		player->AddAura(48162, player);
		player->AddAura(48074, player);
		player->AddAura(48170, player);
		player->AddAura(43223, player);
		player->AddAura(48934, player);
		player->AddAura(48938, player);
		player->AddAura(25899, player);
		player->AddAura(36880, player);
		player->AddAura(43015, player);
		player->GetSession()->SendNotification("|cffff6060[Премиум мастер]:|r На вас наложены  |cFF76EE00V.I.P бафы|r!");
		break;
        case 1216: // Buffs
               SendGossipMenuFor(player, 1, creature->GetGUID());
		player->AddAura(150000, player);
player->GetSession()->SendNotification("|cffff6060[Премиум мастер]:|r На вас наложен  |cFF76EE00V.I.P баф|r!");
		break;

            case 4000: // Power Word Fortitude
                SendGossipMenuFor(player, 1, creature->GetGUID());
                player->CastSpell(player, 48162, true);
                break;
            case 4001: // Prayer of Spirit
                SendGossipMenuFor(player, 1, creature->GetGUID());
                player->CastSpell(player, 48074, true);
                break;
            case 4002: // Shadow Protection
                SendGossipMenuFor(player, 1, creature->GetGUID());
                player->CastSpell(player, 48170, true);
                break;
            case 4003: // Greater Blessing of Kings
                SendGossipMenuFor(player, 1, creature->GetGUID());
                player->CastSpell(player, 43223, true);
                break;
            case 4004: // Greater Bleesing of Might
                SendGossipMenuFor(player, 1, creature->GetGUID());
                player->CastSpell(player, 48934, true);
                break;
            case 4005: // Greater Blessing of Wisdom
                SendGossipMenuFor(player, 1, creature->GetGUID());
                player->CastSpell(player, 48938, true);
                break;
            case 4006: // Greater Blessing of Sanctuary
                SendGossipMenuFor(player, 1, creature->GetGUID());
                player->CastSpell(player, 25899, true);
                break;
            case 4007: // Arane Intellect
                SendGossipMenuFor(player, 1, creature->GetGUID());
                player->CastSpell(player, 36880, true);
                break;
            case 4008: // Dampen Magic
                SendGossipMenuFor(player, 1, creature->GetGUID());
                player->CastSpell(player, 43015, true);
                break;
            case 4009: // Amplify Magic
                SendGossipMenuFor(player, 1, creature->GetGUID());
                player->CastSpell(player, 43017, true);
                break;
            case 4010: // Gift of the Wild
                SendGossipMenuFor(player, 1, creature->GetGUID());
                player->CastSpell(player, 69381, true);
                break;
            case 4011: // Thorns
                SendGossipMenuFor(player, 1, creature->GetGUID());
                player->CastSpell(player, 467, true);
                break;
            case 4012: // Brilliance Intellect
                SendGossipMenuFor(player, 1, creature->GetGUID());
                player->CastSpell(player, 69994, true);
                break;
            case 1204: // Max Skills
               if(!player->HasAura(26013))
				{
					SendGossipMenuFor(player, 1, creature->GetGUID());
					player->GetSession()->SendNotification("|cffff6060[Премиум мастер]:|r С вас был снят дизертир!");
				}
				else
				{
					SendGossipMenuFor(player, 1, creature->GetGUID());
					player->RemoveAurasDueToSpell(26013);
				}
				break;
            case 1208: // Mounts Ground
                player->PlayerTalkClass->ClearMenus();
                AddGossipItemFor(player, GOSSIP_ICON_DOT, "Черный киражский резонирующий кристалл", GOSSIP_SENDER_MAIN, 100);
                AddGossipItemFor(player, GOSSIP_ICON_DOT, "Аманийский боевой медведь", GOSSIP_SENDER_MAIN, 101);
                AddGossipItemFor(player, GOSSIP_ICON_DOT, "Большой боевой медведь", GOSSIP_SENDER_MAIN, 102);
                AddGossipItemFor(player, GOSSIP_ICON_DOT, "Поводья коня смерти", GOSSIP_SENDER_MAIN, 103);
                AddGossipItemFor(player, GOSSIP_ICON_DOT, "Поводья огненного боевого коня", GOSSIP_SENDER_MAIN, 104);
                AddGossipItemFor(player, GOSSIP_ICON_DOT, "Стремительный пурпурный волк", GOSSIP_SENDER_MAIN, 105);
                AddGossipItemFor(player, GOSSIP_ICON_DOT, "Большой кодо Хмельного фестиваля", GOSSIP_SENDER_MAIN, 106);
                AddGossipItemFor(player, GOSSIP_ICON_DOT, "Верховой северный волк", GOSSIP_SENDER_MAIN, 107);
                AddGossipItemFor(player, GOSSIP_ICON_DOT, "Яйцо волшебного петуха", GOSSIP_SENDER_MAIN, 108);
                AddGossipItemFor(player, GOSSIP_ICON_DOT, "Поводья белого северного медведя", GOSSIP_SENDER_MAIN, 109);
                AddGossipItemFor(player, GOSSIP_ICON_DOT, "Поводья бурого северного медведя", GOSSIP_SENDER_MAIN, 110);
                AddGossipItemFor(player, GOSSIP_ICON_DOT, "Поводья багрового коня смерти", GOSSIP_SENDER_MAIN, 111);
                AddGossipItemFor(player, GOSSIP_ICON_DOT, "Поводья повелителя воронов", GOSSIP_SENDER_MAIN, 112);
                AddGossipItemFor(player, GOSSIP_ICON_DOT, "Поводья резвого призрачного тигра", GOSSIP_SENDER_MAIN, 113);
                AddGossipItemFor(player, GOSSIP_ICON_DOT, "Морская черепаха", GOSSIP_SENDER_MAIN, 114);
                AddGossipItemFor(player, GOSSIP_ICON_DOT, "Стремительный ящер Раззаши", GOSSIP_SENDER_MAIN, 115);
                AddGossipItemFor(player, GOSSIP_ICON_DOT, "Стремительный белый крылобег", GOSSIP_SENDER_MAIN, 116);
                AddGossipItemFor(player, GOSSIP_ICON_DOT, "Стремительная жевра", GOSSIP_SENDER_MAIN, 117);
                AddGossipItemFor(player, GOSSIP_ICON_DOT, "Стремительный зульский тигр", GOSSIP_SENDER_MAIN, 118);
                AddGossipItemFor(player, GOSSIP_ICON_DOT, "Поводья скакуна Всадника без головы", GOSSIP_SENDER_MAIN, 119);
                AddGossipItemFor(player, GOSSIP_ICON_DOT, "Белый шерстистый носорог", GOSSIP_SENDER_MAIN, 120);
                AddGossipItemFor(player, GOSSIP_ICON_DOT, "Киражские резонирующие кристаллы", GOSSIP_SENDER_MAIN, 121);
                SendGossipMenuFor(player, 1, creature->GetGUID());(DEFAULT_GOSSIP_MESSAGE,creature->GetGUID());
                break;
             case 100: // Black Qiraji Resonating Crystal
                SendGossipMenuFor(player, 1, creature->GetGUID());
                player->AddItem(21176, 1);
                break;
                case 101: // Amani War Bear
                SendGossipMenuFor(player, 1, creature->GetGUID());
                player->AddItem(33809, 1);
                break;
             case 102: // Big Battle Bear
                SendGossipMenuFor(player, 1, creature->GetGUID());
                player->AddItem(38576, 1);
                break;
             case 103: // Deathcharger's Reins
                SendGossipMenuFor(player, 1, creature->GetGUID());
                player->AddItem(13335, 1);
                break;
             case 104: // Fiery Warhorse's Reins
                SendGossipMenuFor(player, 1, creature->GetGUID());
                player->AddItem(30480, 1);
                break;
             case 105: // Swift Burgundy Wolf
                SendGossipMenuFor(player, 1, creature->GetGUID());
                player->CastSpell(player, 65646, true); // Cast Metod Because Item (Faction Flag)
                break;
             case 106: // Great Brewfest Kodo
                SendGossipMenuFor(player, 1, creature->GetGUID());
                player->AddItem(37828, 1);
                break;
             case 107: // Horn of the Frostwolf Howler
                SendGossipMenuFor(player, 1, creature->GetGUID());
                player->CastSpell(player, 23509, true); // Cast Metod Because Item (Faction Flag)
                break;
             case 108: // Magic Rooster Egg
                SendGossipMenuFor(player, 1, creature->GetGUID());
                player->AddItem(46778, 1);
                break;
             case 109: // Reins of the White Polar Bear
                SendGossipMenuFor(player, 1, creature->GetGUID());
                player->AddItem(43962, 1);
                break;
             case 110: // Reins of the Brown Polar Bear
                SendGossipMenuFor(player, 1, creature->GetGUID());
                player->AddItem(43963, 1);
                break;
             case 111: // Trans
                player->GetSession()->SendListInventory(creature->GetGUID(), 3323);
                break;
             case 112: // Банк
                SendGossipMenuFor(player, 1, creature->GetGUID());
				player->GetSession()->SendShowBank(player->GetGUID());
				break;
             case 113: // Почта
                SendGossipMenuFor(player, 1, creature->GetGUID());
				player->GetSession()->SendShowMailBox(player->GetGUID());
				break;
             case 114: // аук

             case 115: // Swift Razzashi Raptor
                SendGossipMenuFor(player, 1, creature->GetGUID());
                player->AddItem(19872, 1);
                break;
             case 116: // Swift White Hawkstrider
                SendGossipMenuFor(player, 1, creature->GetGUID());
                player->AddItem(35513, 1);
                break;
             case 117: // Swift Zhevra
                SendGossipMenuFor(player, 1, creature->GetGUID());
                player->AddItem(37719, 1);
                break;
                                       case 1211: // Riding Skills
                   player->DurabilityRepairAll(false, 0.0f, true);
               player->GetSession()->SendNotification("|cffff6060[Премиум мастер]:|r Я починил всю вашу  экипировку!");
               SendGossipMenuFor(player, 1, creature->GetGUID());
               break;

// ### Teleport Coordinates ###
// # Main Cities #

case 118: // Orgrimmar
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(1, 1629.36f, -4373.39f, 31.2564f, 3.54839f);
    break;
case 119: // Thunderbluff
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(1, -1277.37f, 124.804f, 131.287f, 5.22274f);
    break;
case 120: // Silvermoon
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(530, 9487.69f, -7279.2f, 14.2866f, 6.16478f);
    break;
case 121: // Undercity
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(0, 1584.07f, 241.987f, -52.1534f, 0.049647f);
    break;
case 122: // Stormwind
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(0, -8833.38f, 628.628f, 94.0066f, 1.06535f);
    break;
case 123: // Ironforge
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(0, -4918.88f, -940.406f, 501.564f, 5.42347f);
    break;
case 124: // Exodar
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(530, -3965.7f, -11653.6f, -138.844f, 0.852154f);
    break;
case 125: // Darnassus
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(1, 9949.56f, 2284.21f, 1341.4f, 1.59587f);
    break;

// # Neutral Cities #

case 126: // Dalaran
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(571, 5804.15f, 624.771f, 647.767f, 1.64f);
    break;
case 127: // Shattrath
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(530, -1838.16f, 5301.79f, -12.428f, 5.9517f);
    break;
case 128: // Booty Bay
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(0, -14297.2f, 530.993f, 8.77916f, 3.98863f);
    break;
case 129: // Gadgetzan
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(1, -7177.15f, -3785.34f, 8.36981f, 6.10237f);
    break;

// # Arenas #

case 130: // Gurubashi Arena
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(0, -13277.4f, 127.372f, 26.1418f, 1.11878f);
    break;
case 131: // Circle of Blood
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(530, 2839.44f, 5930.17f, 11.1002f, 3.16284f);
    break;
case 132: // The Ring of Trials
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(530, -1999.94f, 6581.71f, 11.32f, 2.36528f);
    break;

// # Dungeons #

case 133: // Dungeons 1-60 - Ragefire Chasm
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(1, 1811.78f, -4410.5f, -18.4704f, 5.20165f);
    break;
case 134: // Dungeons 1-60 - The Deadmines
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(0, -11208.7f, 1673.52f, 24.6361f, 1.51067f);
    break;
case 135: // Dungeons 1-60 - Wailing Caverns
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(1, -805.049f, -2032.03f, 95.8796f, 6.18912f);
    break;
case 136: // Dungeons 1-60 - Shadowfang Keep
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(0, -234.675f, 1561.63f, 76.8921f, 1.24031f);
    break;
case 137: // Dungeons 1-60 - Blackfathom Deeps
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(1, 4249.99f, 740.102f, -25.671f, 1.34062f);
    break;
case 138: // Dungeons 1-60 - Stormwind Stockade
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(0, -8773.32f, 839.031f, 91.6376f, 0.648292f);
    break;
case 139: // Dungeons 1-60 - Gnomergan
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(0, -5163.54f, 925.423f, 257.181f, 1.57423f);
    break;
case 140: // Dungeons 1-60 - Scarlet Monastery
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(0, 2842.533691f, -690.716248f, 139.331131f, 5.166503f);
    break;
case 141: // Dungeons 1-60 - Razorfen Kraul
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(1, -4470.28f, -1677.77f, 81.3925f, 1.16302f);
    break;
case 142: // Dungeons 1-60 - Maraudon
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(1, -1419.13f, 2908.14f, 137.464f, 1.57366f);
    break;
case 143: // Dungeons 1-60 - Uldaman
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(0, -6071.37f, -2955.16f, 209.782f, 0.015708f);
    break;
case 144: // Dungeons 1-60 - Razorfen Downs
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(1, -4657.3f, -2519.35f, 81.0529f, 4.54808f);
    break;
case 145: // Dungeons 1-60 - Zul Farrack
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(1, -6801.19f, -2893.02f, 9.00388f, 0.158639f);
    break;
case 146: // Dungeons 1-60 - Sunken Temple
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(0, -10177.9f, -3994.9f, -111.239f, 6.01885f);
    break;
case 147: // Dungeons 1-60 - Dire Maul
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(1, -3521.29f, 1085.2f, 161.097f, 4.7281f);
    break;
case 148: // Dungeons 1-60 - Blackrock Depths
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(0, -7179.34f, -921.212f, 165.821f, 5.09599f);
    break;
case 149: // Dungeons 1-60 - Blackrock Spire
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(0, -7527.05f, -1226.77f, 285.732f, 5.29626f);
    break;
case 150: // Dungeons 1-60 - Scholomance
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(0, 1269.64f, -2556.21f, 93.6088f, 0.620623f);
    break;
case 151: // Dungeons 1-60 - Stratholme
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(0, 3352.92f, -3379.03f, 144.782f, 6.25978f);
    break;
case 152: // Dungeons 60-70 - Hellfire Citadel
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(530, -390.863f, 3130.64f, 4.51327f, 0.218692f);
    break;
case 153: // Dungeons 60-70 - Coilfang Reservoir
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(530, 735.066f, 6883.45f, -66.2913f, 5.89172f);
    break;
case 154: // Dungeons 60-70 - Auchindoun
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(530, -3324.49f, 4943.45f, -101.239f, 4.63901f);
    break;
case 155: // Dungeons 60-70 - Tempest Keep
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(530, 3099.36f, 1518.73f, 190.3f, 4.72592f);
    break;
case 156: // Dungeons 60-70 - Caverns of Time
// Dungeons 60-70 - Culting of Stratholme
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(1, -8204.88f, -4495.25f, 9.0091f, 4.72574f);
    break;
case 157: // Dungeons 60-70 - Magisters' Terrace
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(530, 12884.6f, -7317.69f, 65.5023f, 4.799f);
    break;
case 158: // Dungeons 70-80 - Utgarde Keep
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(571, 1219.72f, -4865.28f, 41.2479f, 0.313228f);
    break;
case 159: // Dungeons 70-80 - The Nexus
// Dungeons 70-80 - The Oculus
// Dungeons 70-80 - The Eye of Eternity
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(571, 3781.81f, 6953.65f, 104.82f, 0.467432f);
    break;
case 160: // Dungeons 70-80 - Azjol-Nerub
// Dungeons 70-80 - Ahn'Kahet: The Old Kingdom
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(571, 3707.86f, 2150.23f, 36.76f, 3.22f);
    break;
case 161: // Dungeons 70-80 - Drak'Tharon Keep
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(571, 4774.6f, -2032.92f, 229.15f, 1.59f);
    break;
case 162: // Dungeons 70-80 - The Violet Hold
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(571, 5696.73f, 507.4f, 652.97f, 4.03f);
    break;
case 163: // Dungeons 70-80 - Gundrak
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(571, 6898.72f, -4584.94f, 451.12f, 2.34455f);
    break;
case 164: // Dungeons 70-80 - Halls of Stone
// Dungeons 70-80 - Halls of Lightning
// Dungeons 70-80 - Uldar
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(571, 9049.37f, -1282.35f, 1060.19f, 5.8395f);
    break;
case 165: // Dungeons 70-80 - Utgarde Pinnacle
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(571, 1259.33f, -4852.02f, 215.763f, 3.48293f);
    break;
case 166: // Dungeons 70-80 - Trial of Champion
// Dungeons 70-80 - Trial of Crusader
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(571, 8515.89f, 629.25f, 547.396f, 1.5747f);
    break;
case 167: // Dungeons 70-80 - Pit of Saron
// Dungeons 70-80 - Forge of Souls
// Dungeons 70-80 - Halls of Reflection
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(571, 5638.26f, 2053.01f, 798.046f, 4.59295f);
    break;

// # Raids #

case 168: // Level 60 Raids - Zul'Gurub
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(0, -11916.7f, -1215.72f, 92.289f, 4.72454f);
    break;
case 169: // Level 60 Raids - Molten Core
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(230, 1126.64f, -459.94f, -102.535f, 3.46095f);
    break;
case 170: // Level 60 Raids - Blackwing Lair
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(229, 164.789f, -475.305f, 116.842f, 0.022714f);
    break;
case 171: // Level 60 Raids - Ahn'Qiraj Ruins
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(1, -8409.82f, 1499.06f, 27.7179f, 2.51868f);
    break;
case 172: // Level 60 Raids - Ahn'Qiraj Temple
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(1, -8240.09f, 1991.32f, 129.072f, 0.941603f);
    break;
case 173: // Level 70 Raids - Karazhan
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(0, -11118.9f, -2010.33f, 47.0819f, 0.649895f);
    break;
case 174: // Level 70 Raids - Gruul's Lair
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(530, 3530.06f, 5104.08f, 3.50861f, 5.51117f);
    break;
case 175: // Level 70 Raids - Magtheridon's Lair
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(530, -312.7f, 3087.26f, -116.52f, 5.19026f);
    break;
case 176: // Level 70 Raids - Zul'Aman
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(530, 6851.78f, -7972.57f, 179.242f, 4.64691f);
    break;
case 177: // Level 70 Raids - Serpentshrine Cavern
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(530, 820.025f, 6864.93f, -66.7556f, 6.28127f);
    break;
case 178: // Level 70 Raids - Tempest Keep: The Eye
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(530, 3088.49f, 1381.57f, 184.863f, 4.61973f);
    break;
case 179: // Level 70 Raids - Hyjal
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(1, -8177.89f, -4181.23f, -167.552f, 0.913338f);
    break;
case 180: // Level 70 Raids - Black Temple
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(530, -3649.92f, 317.469f, 35.2827f, 2.94285f);
    break;
case 181: // Level 70 Raids - Sunwell Plateau
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(530, 12574.1f, -6774.81f, 15.0904f, 3.13788f);
    break;
case 182: // Level 80 Raids - Naxxarams
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(571, 3668.72f, -1262.46f, 243.622f, 4.785f);
    break;
case 183: // Level 80 Raids - Obsidian Sanctum
// Level 80 Raids - Ruby Sanctum
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(571, 3479.66f, 264.625f, -120.144f, 0.097f);
    break;
case 184: // Level 80 Raids - Vault of Archavon
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(571, 5453.72f, 2840.79f, 421.28f, 0.0f);
    break;
case 185: // Level 80 Raids - Icecrown Citadel
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(571, 5873.82f, 2110.98f, 636.011f, 3.5523f);
    break;
case 186: // Level 80 Raids - Onyxia's Liar
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(1, -4708.27f, -3727.64f, 54.5589f, 3.72786f);
    break;

// # Zones #

case 187: // Zones - Eastern Kingdoms - Eversong Woods
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(530, 9079.92f, -7193.23f, 55.6013f, 5.94597f);
    break;
case 188: // Zones - Eastern Kingdoms - Tirisfal Glades
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(0, 2036.02f, 161.331f, 33.8674f, 0.143896f);
    break;
case 189: // Zones - Eastern Kingdoms - Dun Morogh
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(0, -5451.55f, -656.992f, 392.675f, 0.66789f);
    break;
case 190: // Zones - Eastern Kingdoms - Elwynn Forest
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(0, -9617.06f, -288.949f, 57.3053f, 4.72687f);
    break;
case 191: // Zones - Eastern Kingdoms - Ghostlands
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(530, 7360.86f, -6803.3f, 44.2942f, 5.83679f);
    break;
case 192: // Zones - Eastern Kingdoms - Silverpine Forest
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(0, 878.74f, 1359.33f, 50.355f, 5.89929f);
    break;
case 193: // Zones - Eastern Kingdoms - Westfall
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(0, -10235.2f, 1222.47f, 43.6252f, 6.2427f);
    break;
case 194: // Zones - Eastern Kingdoms - Loch Modan
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(0, -5202.94f, -2855.18f, 336.822f, 0.37651f);
    break;
case 195: // Zones - Eastern Kingdoms - Redridge Mountains
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(0, -9551.81f, -2204.73f, 93.473f, 5.47141f);
    break;
case 196: // Zones - Eastern Kingdoms - Duskwood
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(0, -10898.3f, -364.784f, 39.2681f, 3.04614f);
    break;
case 197: // Zones - Eastern Kingdoms - Wetlands
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(0, -3242.81f, -2469.04f, 15.9226f, 6.03924f);
    break;
case 198: // Zones - Eastern Kingdoms - Hillsbrad Foothills
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(0, -436.657f, -581.254f, 53.5944f, 1.25917f);
    break;
case 199: // Zones - Eastern Kingdoms - Alterac Mountains
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(0, 370.763f, -491.355f, 175.361f, 5.37858f);
    break;
case 200: // Zones - Eastern Kingdoms - Arathi Highlands
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(0, -1508.51f, -2732.06f, 32.4986f, 3.35708f);
    break;
case 201: // Zones - Eastern Kingdoms - Strangelthorn Vale
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(0, -12644.3f, -377.411f, 18.299746f, 6.09978f);
    break;
case 202: // Zones - Eastern Kingdoms - Swamp of Sorrows
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(0, -10345.4f, -2773.42f, 21.99f, 5.08426f);
    break;
case 203: // Zones - Eastern Kingdoms - Badlands
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(0, -6779.2f, -3423.64f, 241.667f, 0.647481f);
    break;
case 204: // Zones - Eastern Kingdoms - The Hinterlands
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(0, 119.387f, -3190.37f, 117.331f, 2.34064f);
    break;
case 205: // Zones - Eastern Kingdoms - Searing Gorge
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(0, -7012.47f, -1065.13f, 241.786f, 5.63162f);
    break;
case 206: // Zones - Eastern Kingdoms - Blasted Lands
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(0, -11182.5f, -3016.67f, 7.42235f, 4.0004f);
    break;
case 207: // Zones - Eastern Kingdoms - Burning Steppes
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(0, -8118.54f, -1633.83f, 132.996f, 0.089067f);
    break;
case 208: // Zones - Eastern Kingdoms - Western Plaguelands
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(0, 1728.65f, -1602.25f, 63.429f, 1.6558f);
    break;
case 209: // Zones - Eastern Kingdoms - Eastern Plaguelands
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(0, 2300.97f, -4613.36f, 73.6231f, 0.367722f);
    break;
case 210: // Zones - Eastern Kingdoms - Deadwind Pass
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(0, -10438.8f, -1932.75f, 104.617f, 4.77402f);
    break;
case 211: // Zones - Kalimdor - Teldrassil
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(1, 10111.3f, 1557.73f, 1324.33f, 4.04239f);
    break;
case 212: // Zones - Kalimdor - Azuremyst Isle
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(530, -4216.87f, -12336.9f, 4.34247f, 6.02008f);
    break;
case 213: // Zones - Kalimdor - Durotar
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(1, 1007.78f, -4446.22f, 11.2022f, 0.20797f);
    break;
case 214: // Zones - Kalimdor - Mulgore
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(1, -2192.62f, -736.317f, -13.3274f, 0.487569f);
    break;
case 215: // Zones - Kalimdor - Bloodmyst Isle
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(530, -1993.62f, -11475.8f, 63.9657f, 5.29437f);
    break;
case 216: // Zones - Kalimdor - Darkshore
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(1, 5756.25f, 298.505f, 20.6049f, 5.96504f);
    break;
case 217: // Zones - Kalimdor - The Barrens
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(1, 884.54f, -3548.45f, 91.8532f, 2.95957f);
    break;
case 218: // Zones - Kalimdor - Stonetalon Mountains
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(1, 1570.92f, 1031.52f, 137.959f, 3.33006f);
    break;
case 219: // Zones - Kalimdor - Ashenvale
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(1, 1928.34f, -2165.95f, 93.7896f, 0.205731f);
    break;
case 220: // Zones - Kalimdor - Thousand Needles
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(1, -4969.02f, -1726.89f, -62.1269f, 3.7933f);
    break;
case 221: // Zones - Kalimdor - Desolace
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(1, -606.395f, 2211.75f, 92.9818f, 0.809746f);
    break;
case 222: // Zones - Kalimdor - Dustwallow Marsh
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(1, -4043.65f, -2991.32f, 36.3984f, 3.37443f);
    break;
case 223: // Zones - Kalimdor - Tanaris
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(1, -7931.2f, -3414.28f, 80.7365f, 0.66522f);
    break;
case 224: // Zones - Kalimdor - Feralas
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(1, -4841.19f, 1309.44f, 81.3937f, 1.48501f);
    break;
case 225: // Zones - Kalimdor - Azshara
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(1, 3341.36f, -4603.79f, 92.5027f, 5.28142f);
    break;
case 226: // Zones - Kalimdor - Felwood
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(1, 4102.25f, -1006.79f, 272.717f, 0.790048f);
    break;
case 227: // Zones - Kalimdor - Un'Goro Crater
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(1, -7943.22f, -2119.09f, -218.343f, 6.0727f);
    break;
case 228: // Zones - Kalimdor - Silithus
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(1, -7426.87f, 1005.31f, 1.13359f, 2.96086f);
    break;
case 229: // Zones - Kalimdor - Winterspring
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(1, 6759.18f, -4419.63f, 763.214f, 4.43476f);
    break;
case 230: // Zones - Kalimdor - Moonglade
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(1, 7654.3f, -2232.87f, 462.107f, 5.96786f);
    break;
case 231: // Zones - Outlands - Hellfire Peninsula
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(530, -211.237f, 4278.54f, 86.5678f, 4.59776f);
    break;
case 232: // Zones - Outlands - Zangarmarsh
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(530, -54.8621f, 5813.44f, 20.9764f, 0.081722f);
    break;
case 233: // Zones - Outlands - Terokkar Forest
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(530, -2000.47f, 4451.54f, 8.37917f, 4.40447f);
    break;
case 234: // Zones - Outlands - Nagrand
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(530, -1145.95f, 8182.35f, 3.60249f, 6.13478f);
    break;
case 235: // Zones - Outlands - Blade's Edge Mountains
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(530, 3037.67f, 5962.86f, 130.774f, 1.27253f);
    break;
case 236: // Zones - Outlands - Shadowmoon Valley
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(530, -3179.6f, 2716.43f, 68.6444f, 4.16414f);
    break;
case 237: // Zones - Outlands - Netherstorm
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(530, 3830.23f, 3426.5f, 88.6145f, 5.16677f);
    break;
case 238: // Zones - Northrend - Borean Tundra
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(571, 3256.57f, 5278.23f, 40.8046f, 0.246367f);
    break;
case 239: // Zones - Northrend - Howling Fjord
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(571, 1902.15f, -4883.91f, 171.363f, 3.11537f);
    break;
case 240: // Zones - Northrend - Dragonblight
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(571, 4103.36f, 264.478f, 50.5019f, 3.09349f);
    break;
case 241: // Zones - Northrend - Grizzly Hills
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(571, 4391.73f, -3587.92f, 238.531f, 3.57526f);
    break;
case 242: // Zones - Northrend - Zul'Drak
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(571, 5560.23f, -3211.66f, 371.709f, 5.55055f);
    break;
case 243: // Zones - Northrend - Sholazar Basin
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(571, 5323, 4942, -133.5f, 2.17f);
    break;
case 244: // Zones - Northrend - Crystalsong Forest
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(571, 5659.35f, 359.053f, 158.214f, 3.69933f);
    break;
case 245: // Zones - Northrend - The Storm Peaks
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(571, 7527.14f, -1260.89f, 919.049f, 2.0696f);
    break;
case 246: // Zones - Northrend - Icecrown
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(571, 7253.64f, 1644.78f, 433.68f, 4.83412f);
    break;
case 247: // Zones - Northrend - Wintergrasp
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(571, 4760.7f, 2143.7f, 423, 1.13f);
    break;


// # Malls #

case 248: // Horde Mall
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(571, 4126.39f, -4356.95f, 275.57f, 4.30905f);
    break;
case 249: // Alliance Mall
    SendGossipMenuFor(player, 1, creature->GetGUID());
    player->TeleportTo(571, 4126.39f, -4356.95f, 275.57f, 4.30905f);
    break;

case 1: // Меню телепортации
if (player->GetTeamId() == TEAM_HORDE)
    //AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "[Старт зона орды]" , GOSSIP_SENDER_MAIN, 248);
//else
//AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "[Старт зона альянса]" , GOSSIP_SENDER_MAIN, 249);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "[Столицы]" , GOSSIP_SENDER_MAIN, 5);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "[Нейтральные зоны]" , GOSSIP_SENDER_MAIN, 6);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "[Зоны]" , GOSSIP_SENDER_MAIN, 2);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "[Подземелья]" , GOSSIP_SENDER_MAIN, 3);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "[Рейды]" , GOSSIP_SENDER_MAIN, 4);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "[Арены]" , GOSSIP_SENDER_MAIN, 22);

    AddGossipItemFor(player,GOSSIP_ICON_DOT, "[Основное меню]" , GOSSIP_SENDER_MAIN, 0);
    SendGossipMenuFor(player, 1, creature->GetGUID());(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
    break;
case 2: // Zones
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "[Восточные королевства]" , GOSSIP_SENDER_MAIN, 7);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "[Калимдор]" , GOSSIP_SENDER_MAIN, 10);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "[Запределье]" , GOSSIP_SENDER_MAIN, 12);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "[Нордскол]" , GOSSIP_SENDER_MAIN, 13);

    AddGossipItemFor(player,GOSSIP_ICON_DOT, "[Назад]" , GOSSIP_SENDER_MAIN, 1);
    AddGossipItemFor(player,GOSSIP_ICON_DOT, "[Основное меню]" , GOSSIP_SENDER_MAIN, 0);
    SendGossipMenuFor(player, 1, creature->GetGUID());(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
    break;
case 3: // Dungeons
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "[Подземелья (1-60)]" , GOSSIP_SENDER_MAIN, 14);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "[Подземелья (60-70)]" , GOSSIP_SENDER_MAIN, 16);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "[Подземелья (70-80)]" , GOSSIP_SENDER_MAIN, 17);

    AddGossipItemFor(player,GOSSIP_ICON_DOT, "[Назад]" , GOSSIP_SENDER_MAIN, 1);
    AddGossipItemFor(player,GOSSIP_ICON_DOT, "[Основное меню]" , GOSSIP_SENDER_MAIN, 0);
    SendGossipMenuFor(player, 1, creature->GetGUID());(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
    break;
case 4: // Raids
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "[Рейдовые подземелья на 60-й уровень]" , GOSSIP_SENDER_MAIN, 19);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "[Рейдовые подземелья на 70-й уровень]" , GOSSIP_SENDER_MAIN, 20);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "[Рейдовые подземелья на 80-й уровень]" , GOSSIP_SENDER_MAIN, 21);

    AddGossipItemFor(player,GOSSIP_ICON_DOT, "[Назад]" , GOSSIP_SENDER_MAIN, 1);
    AddGossipItemFor(player,GOSSIP_ICON_DOT, "[Основное меню]" , GOSSIP_SENDER_MAIN, 0);
    SendGossipMenuFor(player, 1, creature->GetGUID());(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
    break;
case 5: // Home Cities
if (player->GetTeamId() == TEAM_HORDE)
{
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Оргриммар" , GOSSIP_SENDER_MAIN, 118);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Громовой Утес" , GOSSIP_SENDER_MAIN, 119);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Сильвермун" , GOSSIP_SENDER_MAIN, 120);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Подгород" , GOSSIP_SENDER_MAIN, 121);
}else{
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Штормград" , GOSSIP_SENDER_MAIN, 122);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Стальгорн" , GOSSIP_SENDER_MAIN, 123);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Екзодар" , GOSSIP_SENDER_MAIN, 124);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Дарнасус" , GOSSIP_SENDER_MAIN, 125);
}
    AddGossipItemFor(player,GOSSIP_ICON_DOT, "[Назад]" , GOSSIP_SENDER_MAIN, 1);
    AddGossipItemFor(player,GOSSIP_ICON_DOT, "[Основное меню]" , GOSSIP_SENDER_MAIN, 0);
    SendGossipMenuFor(player, 1, creature->GetGUID());(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
    break;
case 6: // Neutral Cities
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Даларан" , GOSSIP_SENDER_MAIN, 126);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Шатрат" , GOSSIP_SENDER_MAIN, 127);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Бути бей" , GOSSIP_SENDER_MAIN, 128);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Прибамбасск" , GOSSIP_SENDER_MAIN, 129);

    AddGossipItemFor(player,GOSSIP_ICON_DOT, "[Назад]" , GOSSIP_SENDER_MAIN, 1);
    AddGossipItemFor(player,GOSSIP_ICON_DOT, "[Основное меню]" , GOSSIP_SENDER_MAIN, 0);
    SendGossipMenuFor(player, 1, creature->GetGUID());(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
    break;
case 7: // Zones - Eastern Kingdoms Page 1
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Леса Вечной Песни (1-10)" , GOSSIP_SENDER_MAIN, 187);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Тирисфальские леса (1-10)" , GOSSIP_SENDER_MAIN, 188);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Дун Морог (1-10)" , GOSSIP_SENDER_MAIN, 189);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Элвиннский лес (1-10)" , GOSSIP_SENDER_MAIN, 190);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Призрачное нагорье (10-20)" , GOSSIP_SENDER_MAIN, 191);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Серебряный бор (10-20)" , GOSSIP_SENDER_MAIN, 192);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Западный Край (10-20)" , GOSSIP_SENDER_MAIN, 193);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Лок Модан (10-20)" , GOSSIP_SENDER_MAIN, 194);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Красногорье (15-25)" , GOSSIP_SENDER_MAIN, 195);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Сумеречный лес (18-30)" , GOSSIP_SENDER_MAIN, 196);

    AddGossipItemFor(player,GOSSIP_ICON_DOT, "[Вперед]" , GOSSIP_SENDER_MAIN, 8);
    AddGossipItemFor(player,GOSSIP_ICON_DOT, "[Назад]" , GOSSIP_SENDER_MAIN, 2);
    AddGossipItemFor(player,GOSSIP_ICON_DOT, "[Основное меню]" , GOSSIP_SENDER_MAIN, 0);
    SendGossipMenuFor(player, 1, creature->GetGUID());(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
    break;
case 8: // Zones - Eastern Kingdoms Page 2
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Водно-болотные угодья (20-30)" , GOSSIP_SENDER_MAIN, 197);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Предгорья Хилсбрада (20-30)" , GOSSIP_SENDER_MAIN, 198);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Альтеракские горы (30-40)" , GOSSIP_SENDER_MAIN, 199);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Нагорье Арати (30-40)" , GOSSIP_SENDER_MAIN, 200);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Тернистая долина (30-45)" , GOSSIP_SENDER_MAIN, 201);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Болото Печали (35-45)" , GOSSIP_SENDER_MAIN, 202);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Бесплодные земли (35-45)" , GOSSIP_SENDER_MAIN, 203);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Внутренние земли (40-50)" , GOSSIP_SENDER_MAIN, 204);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Тлеющее ущелье (43-50)" , GOSSIP_SENDER_MAIN, 205);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Проклятые земли (45-55)" , GOSSIP_SENDER_MAIN, 206);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Пылающие степи (50-58)" , GOSSIP_SENDER_MAIN, 207);

    AddGossipItemFor(player,GOSSIP_ICON_DOT, "[Вперед]" , GOSSIP_SENDER_MAIN, 9);
    AddGossipItemFor(player,GOSSIP_ICON_DOT, "[Назад]" , GOSSIP_SENDER_MAIN, 7);
    AddGossipItemFor(player,GOSSIP_ICON_DOT, "[Основное меню]" , GOSSIP_SENDER_MAIN, 0);
    SendGossipMenuFor(player, 1, creature->GetGUID());(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
    break;
case 9: // Zones - Eastern Kingdoms Page 3
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Западные Чумные земли (51-58)" , GOSSIP_SENDER_MAIN, 208);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Восточные Чумные земли (53-60)" , GOSSIP_SENDER_MAIN, 209);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Перевал Мертвого Ветра (55-60)" , GOSSIP_SENDER_MAIN, 210);

    AddGossipItemFor(player,GOSSIP_ICON_DOT, "[Назад]" , GOSSIP_SENDER_MAIN, 8);
    AddGossipItemFor(player,GOSSIP_ICON_DOT, "[Основное меню]" , GOSSIP_SENDER_MAIN, 0);
    SendGossipMenuFor(player, 1, creature->GetGUID());(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
    break;
case 10: // Zones - Kalimdor Page 1
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Телдрассил (1-10)" , GOSSIP_SENDER_MAIN, 211);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Остров Лазурной Дымки (1-10)" , GOSSIP_SENDER_MAIN, 212);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Дуротар (1-10)" , GOSSIP_SENDER_MAIN, 213);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Мулгор (1-10)" , GOSSIP_SENDER_MAIN, 214);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Остров Кровавой Дымки (10-20)" , GOSSIP_SENDER_MAIN, 215);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Темные берега (10-20)" , GOSSIP_SENDER_MAIN, 216);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Степи (10-25)" , GOSSIP_SENDER_MAIN, 217);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Когтистые горы (15-27)" , GOSSIP_SENDER_MAIN, 218);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Ясеневый лес (18-30)" , GOSSIP_SENDER_MAIN, 219);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Тысяча Игл (25-35)" , GOSSIP_SENDER_MAIN, 220);

    AddGossipItemFor(player,GOSSIP_ICON_DOT, "[Вперед]" , GOSSIP_SENDER_MAIN, 11);
    AddGossipItemFor(player,GOSSIP_ICON_DOT, "[Назад]" , GOSSIP_SENDER_MAIN, 2);
    AddGossipItemFor(player,GOSSIP_ICON_DOT, "[Основное меню]" , GOSSIP_SENDER_MAIN, 0);
    SendGossipMenuFor(player, 1, creature->GetGUID());(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
    break;
case 11: // Zones - Kalimdor Page 2
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Пустоши (30-40)" , GOSSIP_SENDER_MAIN, 221);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Пылевые топи (35-45)" , GOSSIP_SENDER_MAIN, 222);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Танарис (40-50)" , GOSSIP_SENDER_MAIN, 223);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Фералас (40-50)" , GOSSIP_SENDER_MAIN, 224);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Азшара (45-55)" , GOSSIP_SENDER_MAIN, 225);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Оскверненный лес (48-55)" , GOSSIP_SENDER_MAIN, 226);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Кратер Ун'Горо (45-55)" , GOSSIP_SENDER_MAIN, 227);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Силитус (55-60)" , GOSSIP_SENDER_MAIN, 228);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Зимние ключи (55-60)" , GOSSIP_SENDER_MAIN, 229);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Лунная поляна (1-80)" , GOSSIP_SENDER_MAIN, 230);

    AddGossipItemFor(player,GOSSIP_ICON_DOT, "[Назад]" , GOSSIP_SENDER_MAIN, 10);
    AddGossipItemFor(player,GOSSIP_ICON_DOT, "[Основное меню]" , GOSSIP_SENDER_MAIN, 0);
    SendGossipMenuFor(player, 1, creature->GetGUID());(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
    break;
case 12: // Zones - Outlands
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Полуостров Адского Пламени (58-63)" , GOSSIP_SENDER_MAIN, 231);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Зангартопь (60-64)" , GOSSIP_SENDER_MAIN, 232);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Лес Тероккар (62-65)" , GOSSIP_SENDER_MAIN, 233);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Награнд (64-67)" , GOSSIP_SENDER_MAIN, 234);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Острогорье (65-68)" , GOSSIP_SENDER_MAIN, 235);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Долина Призрачной Луны (67-70)" , GOSSIP_SENDER_MAIN, 236);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Пустоверть (67-70)" , GOSSIP_SENDER_MAIN, 237);

    AddGossipItemFor(player,GOSSIP_ICON_DOT, "[Назад]" , GOSSIP_SENDER_MAIN, 2);
    AddGossipItemFor(player,GOSSIP_ICON_DOT, "[Основное меню]" , GOSSIP_SENDER_MAIN, 0);
    SendGossipMenuFor(player, 1, creature->GetGUID());(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
    break;
case 13: // Zones - Northrend
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Борейская тундра (68-72)" , GOSSIP_SENDER_MAIN, 238);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Ревущий фьорд (68-72)" , GOSSIP_SENDER_MAIN, 239);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Драконий погост (71-74)" , GOSSIP_SENDER_MAIN, 240);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Седые холмы (73-75)" , GOSSIP_SENDER_MAIN, 241);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Зул'Драк (74-77)" , GOSSIP_SENDER_MAIN, 242);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Низина шолозар (76-78)" , GOSSIP_SENDER_MAIN, 243);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Лес Хрустальной песни (77-80)" , GOSSIP_SENDER_MAIN, 244);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Грозовая Гряда (77-80)" , GOSSIP_SENDER_MAIN, 245);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Ледяная Корона (77-80)" , GOSSIP_SENDER_MAIN, 246);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Ледяные оковы (ПвП)" , GOSSIP_SENDER_MAIN, 247);

    AddGossipItemFor(player,GOSSIP_ICON_DOT, "[Назад]" , GOSSIP_SENDER_MAIN, 2);
    AddGossipItemFor(player,GOSSIP_ICON_DOT, "[Основное меню]" , GOSSIP_SENDER_MAIN, 0);
    SendGossipMenuFor(player, 1, creature->GetGUID());(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
    break;
case 14: // Dungeons 1-60 Page 1
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Огненная пропасть (15-21)" , GOSSIP_SENDER_MAIN, 133);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Мертвые копи (15-21)" , GOSSIP_SENDER_MAIN, 134);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Пещеры Стенаний (15-25)" , GOSSIP_SENDER_MAIN, 135);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Логово темного клыка (16-26)" , GOSSIP_SENDER_MAIN, 136);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Пещеры черной горы (20-30)" , GOSSIP_SENDER_MAIN, 137);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Тюрьма штормграда (20-30)" , GOSSIP_SENDER_MAIN, 138);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Гномеран (24-34)" , GOSSIP_SENDER_MAIN, 139);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Монастырь Алого ордена (26-42)" , GOSSIP_SENDER_MAIN, 140);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Лабиринты Иглошкурых (30-40)" , GOSSIP_SENDER_MAIN, 141);

    AddGossipItemFor(player,GOSSIP_ICON_DOT, "[Вперед]" , GOSSIP_SENDER_MAIN, 15);
    AddGossipItemFor(player,GOSSIP_ICON_DOT, "[Назад]" , GOSSIP_SENDER_MAIN, 3);
    AddGossipItemFor(player,GOSSIP_ICON_DOT, "[Основное меню]" , GOSSIP_SENDER_MAIN, 0);
    SendGossipMenuFor(player, 1, creature->GetGUID());(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
    break;
case 15: // Dungeons 1-60 Page 2
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Марадон (30-46)" , GOSSIP_SENDER_MAIN, 142);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Ульдаман (35-45)" , GOSSIP_SENDER_MAIN, 143);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Курганы Иглошкурых (35-43)" , GOSSIP_SENDER_MAIN, 144);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Зульфарак (40-48)" , GOSSIP_SENDER_MAIN, 145);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Затонувший храм (45-55)" , GOSSIP_SENDER_MAIN, 146);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Забытый Город (50-60)" , GOSSIP_SENDER_MAIN, 147);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Глубины Черной горы (50-60)" , GOSSIP_SENDER_MAIN, 148);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Черная гора (50-60)" , GOSSIP_SENDER_MAIN, 149);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Некроситет (50-60)" , GOSSIP_SENDER_MAIN, 150);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Стратхольм (50-60)" , GOSSIP_SENDER_MAIN, 151);

    AddGossipItemFor(player,GOSSIP_ICON_DOT, "[Назад]" , GOSSIP_SENDER_MAIN, 14);
    AddGossipItemFor(player,GOSSIP_ICON_DOT, "[Основное меню]" , GOSSIP_SENDER_MAIN, 0);
    SendGossipMenuFor(player, 1, creature->GetGUID());(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
    break;
case 16: // Dungeons 60-70
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Цытадель адского пламени (60-68)" , GOSSIP_SENDER_MAIN, 152);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Резервуар Кривого Клыка (60-69)" , GOSSIP_SENDER_MAIN, 153);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Аукхидон (60-70)" , GOSSIP_SENDER_MAIN, 154);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Крепость бурь (60-70)" , GOSSIP_SENDER_MAIN, 155);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Пещеры Времени (60-70)" , GOSSIP_SENDER_MAIN, 156);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Терраса Магистров (68-72)" , GOSSIP_SENDER_MAIN, 157);

    AddGossipItemFor(player,GOSSIP_ICON_DOT, "[Назад]" , GOSSIP_SENDER_MAIN, 3);
    AddGossipItemFor(player,GOSSIP_ICON_DOT, "[Основное меню]" , GOSSIP_SENDER_MAIN, 0);
    SendGossipMenuFor(player, 1, creature->GetGUID());(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
    break;
case 17: // Dungeons 70-80 Page 1
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Крепость Утгард (70-72)" , GOSSIP_SENDER_MAIN, 158);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Нексус (71-73)" , GOSSIP_SENDER_MAIN, 159);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Азжол - Неруб (72-74)" , GOSSIP_SENDER_MAIN, 160);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Ан'кахете :Старое Королевство (73-75)" , GOSSIP_SENDER_MAIN, 160);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Драк'Тарон (74-76)" , GOSSIP_SENDER_MAIN, 161);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Аметистовая крепость (75-77)" , GOSSIP_SENDER_MAIN, 162);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Гундрак (76-78)" , GOSSIP_SENDER_MAIN, 163);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Чертоги Камня (77-79)" , GOSSIP_SENDER_MAIN, 164);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Чертоги Молний (80)" , GOSSIP_SENDER_MAIN, 164);

    AddGossipItemFor(player,GOSSIP_ICON_DOT, "[Вперед]" , GOSSIP_SENDER_MAIN, 18);
    AddGossipItemFor(player,GOSSIP_ICON_DOT, "[Назад]" , GOSSIP_SENDER_MAIN, 3);
    AddGossipItemFor(player,GOSSIP_ICON_DOT, "[Основное меню]" , GOSSIP_SENDER_MAIN, 0);
    SendGossipMenuFor(player, 1, creature->GetGUID());(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
    break;
case 18: // Dungeons 70-80 Page 2
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Глаз (80)" , GOSSIP_SENDER_MAIN, 159);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Очищение Стратхольма (80)" , GOSSIP_SENDER_MAIN, 156);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Вершина Утгард (80)" , GOSSIP_SENDER_MAIN, 165);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Испытание чемпиона (80)" , GOSSIP_SENDER_MAIN, 166);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Яма Сарона (80)" , GOSSIP_SENDER_MAIN, 167);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Кузня Душ (80)" , GOSSIP_SENDER_MAIN, 167);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Залы Отражений (80)" , GOSSIP_SENDER_MAIN, 167);

    AddGossipItemFor(player,GOSSIP_ICON_DOT, "[Назад]" , GOSSIP_SENDER_MAIN, 17);
    AddGossipItemFor(player,GOSSIP_ICON_DOT, "[Основное меню]" , GOSSIP_SENDER_MAIN, 0);
    SendGossipMenuFor(player, 1, creature->GetGUID());(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
    break;
case 19: // Level 60 Raids
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Зул'Гуруб" , GOSSIP_SENDER_MAIN, 168);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Огненные Недра" , GOSSIP_SENDER_MAIN, 169);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Логово Крыла Тьмы" , GOSSIP_SENDER_MAIN, 170);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Ан'киражские Руины" , GOSSIP_SENDER_MAIN, 171);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Ан'киражский Храм" , GOSSIP_SENDER_MAIN, 172);

    AddGossipItemFor(player,GOSSIP_ICON_DOT, "[Назад]" , GOSSIP_SENDER_MAIN, 4);
    AddGossipItemFor(player,GOSSIP_ICON_DOT, "[Основное меню]" , GOSSIP_SENDER_MAIN, 0);
    SendGossipMenuFor(player, 1, creature->GetGUID());(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
    break;
case 20: // Level 70 Raids
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Каражан" , GOSSIP_SENDER_MAIN, 173);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Логово Груула" , GOSSIP_SENDER_MAIN, 174);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Логово Магтеридона" , GOSSIP_SENDER_MAIN, 175);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Зуляман" , GOSSIP_SENDER_MAIN, 176);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Змеиное святилище" , GOSSIP_SENDER_MAIN, 177);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Крепость бурь:глаз" , GOSSIP_SENDER_MAIN, 178);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Хиджал" , GOSSIP_SENDER_MAIN, 179);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Черный храм" , GOSSIP_SENDER_MAIN, 180);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Плато Солнечного Колодца" , GOSSIP_SENDER_MAIN, 181);

    AddGossipItemFor(player,GOSSIP_ICON_DOT, "[Назад]" , GOSSIP_SENDER_MAIN, 4);
    AddGossipItemFor(player,GOSSIP_ICON_DOT, "[Основное меню]" , GOSSIP_SENDER_MAIN, 0);
    SendGossipMenuFor(player, 1, creature->GetGUID());(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
    break;
case 21: // Level 80 Raids
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Наксармас" , GOSSIP_SENDER_MAIN, 182);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Обсидиановое святилище" , GOSSIP_SENDER_MAIN, 183);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Рубиновое святилище" , GOSSIP_SENDER_MAIN, 183);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Склеп Аркавона" , GOSSIP_SENDER_MAIN, 184);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Око Вечности" , GOSSIP_SENDER_MAIN, 159);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Ульдар" , GOSSIP_SENDER_MAIN, 164);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Цитадель Ледяной Короны" , GOSSIP_SENDER_MAIN, 185);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Испытание чемпиона" , GOSSIP_SENDER_MAIN, 166);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Логово Ониксии" , GOSSIP_SENDER_MAIN, 186);

    AddGossipItemFor(player,GOSSIP_ICON_DOT, "[Назад]" , GOSSIP_SENDER_MAIN, 4);
    AddGossipItemFor(player,GOSSIP_ICON_DOT, "[Основное меню]" , GOSSIP_SENDER_MAIN, 0);
    SendGossipMenuFor(player, 1, creature->GetGUID());(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
    break;
case 22: // Arenas
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Гурубаши арена" , GOSSIP_SENDER_MAIN, 130);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Круг крови" , GOSSIP_SENDER_MAIN, 131);
    AddGossipItemFor(player,GOSSIP_ICON_BATTLE, "Кольцо Испытаний" , GOSSIP_SENDER_MAIN, 132);

    AddGossipItemFor(player,GOSSIP_ICON_DOT, "[Назад]" , GOSSIP_SENDER_MAIN, 1);
    AddGossipItemFor(player,GOSSIP_ICON_DOT, "[Основное меню]" , GOSSIP_SENDER_MAIN, 0);
    SendGossipMenuFor(player, 1, creature->GetGUID());(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
    break;
             case 1212: // Reset Cooldown
                	if(!player->HasAura(15007))
				{
					SendGossipMenuFor(player, 1, creature->GetGUID());
					player->GetSession()->SendNotification("|cffff6060[Премиум мастер]:|r С вас была  снята маска смерти!");
				}
				else
				{
					SendGossipMenuFor(player, 1, creature->GetGUID());
					player->RemoveAurasDueToSpell(15007);
					player->SetHealth(player->GetMaxHealth()); //Restore Health
					player->SetPower(POWER_MANA, player->GetMaxPower(POWER_MANA)); // Restore Mana
				}
				break;
                       case 1215:
SendGossipMenuFor(player, 1, creature->GetGUID());

            for (uint8 i = 0; i < MAX_DIFFICULTY; ++i)
				{
						BoundInstancesMap const& m_boundInstances = sInstanceSaveMgr->PlayerGetBoundInstances(player->GetGUID(), Difficulty(i));
                 for (BoundInstancesMap::const_iterator itr = m_boundInstances.begin(); itr != m_boundInstances.end();)
                    {

                        sInstanceSaveMgr->PlayerUnbindInstance(player->GetGUID(), itr->first, Difficulty(i), true, player);
						player->GetSession()->SendNotification("|cfff4b25eVip шепчет:|r |cfffcedbbВаши инсты обновлены!|r");
                    itr = m_boundInstances.begin();
						}
				}
				player->GetSession()->SendNotification("|cffFFFF00Сброс КД \n |cffFFFFFFКД с инстов сброшены!");
				player->CastSpell(player, 59908);
				break;

             case 1213: // Save Character Online
                SendGossipMenuFor(player, 1, creature->GetGUID());
                player->SaveToDB(true, true);;
                creature->Whisper(MSG_CHARACTER_SAVE_TO_DB, LANG_UNIVERSAL, player);
                break;
             case 1214: // Movie Menu
                player->PlayerTalkClass->ClearMenus();
                AddGossipItemFor(player, GOSSIP_ICON_DOT, "World of Warcraft", GOSSIP_SENDER_MAIN, 250);
                AddGossipItemFor(player, GOSSIP_ICON_DOT, "The Wrath Gate", GOSSIP_SENDER_MAIN, 251);
                AddGossipItemFor(player, GOSSIP_ICON_DOT, "Fall of The Lich King", GOSSIP_SENDER_MAIN, 252);
                SendGossipMenuFor(player, 1, creature->GetGUID());(DEFAULT_GOSSIP_MESSAGE,creature->GetGUID());
                break;
             case 250: // Classic
                SendGossipMenuFor(player, 1, creature->GetGUID());
                player->SendMovieStart(2);
                break;
             case 251: // The Wrath Gate
                SendGossipMenuFor(player, 1, creature->GetGUID());
                player->SendMovieStart(14);
                break;
             case 252: // Fall of The Lich King
                SendGossipMenuFor(player, 1, creature->GetGUID());
                player->SendMovieStart(16);
                break;
           }
           return true;
        }
};

void AddSC_npc_premium_master2()
{
    new npc_premium_master2;
}