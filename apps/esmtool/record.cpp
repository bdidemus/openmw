#include "record.hpp"

#include <iostream>
#include <boost/format.hpp>

void printAIPackage(ESM::AIPackage p)
{
  if (p.mType == ESM::AI_Wander)
  {
      std::cout << "  AIType Wander:" << std::endl;
      std::cout << "    Distance: " << p.mWander.mDistance << std::endl;
      std::cout << "    Duration: " << p.mWander.mDuration << std::endl;
      std::cout << "    Time of Day: " << (int)p.mWander.mTimeOfDay << std::endl;
      if (p.mWander.mUnk != 1)
	  std::cout <<  "    Unknown: " << (int)p.mWander.mUnk << std::endl;

      std::cout << "    Idle: ";
      for (int i = 0; i != 8; i++)
	  std::cout << (int)p.mWander.mIdle[i] << " ";
      std::cout << std::endl;
  }
  else if (p.mType == ESM::AI_Travel)
  {
      std::cout << "  AIType Travel:" << std::endl;
      std::cout << "    Travel Coordinates: (" << p.mTravel.mX << ","
	   << p.mTravel.mY << "," << p.mTravel.mZ << ")" << std::endl;
      std::cout << "    Travel Unknown: " << (int)p.mTravel.mUnk << std::endl;
  }
  else if (p.mType == ESM::AI_Follow || p.mType == ESM::AI_Escort)
  {
      if (p.mType == ESM::AI_Follow) std::cout << "  AIType Follow:" << std::endl;
      else std::cout << "  AIType Escort:" << std::endl;

      std::cout << "    Follow Coordinates: (" << p.mTarget.mX << ","
	   << p.mTarget.mY << "," << p.mTarget.mZ << ")" << std::endl;
      std::cout << "    Duration: " << p.mTarget.mDuration << std::endl;
      std::cout << "    Target ID: " << p.mTarget.mId.toString() << std::endl;
      std::cout << "    Unknown: " << (int)p.mTarget.mUnk << std::endl;
  }
  else if (p.mType == ESM::AI_Activate)
  {
      std::cout << "  AIType Activate:" << std::endl;
      std::cout << "    Name: " << p.mActivate.mName.toString() << std::endl;
      std::cout << "    Activate Unknown: " << (int)p.mActivate.mUnk << std::endl;
  }
  else {
      std::cout << "    BadPackage: " << boost::format("0x%08x") % p.mType << std::endl;
  }

  if (p.mCellName != "")
      std::cout << "    Cell Name: " << p.mCellName << std::endl;
}

namespace EsmTool {

RecordBase *
RecordBase::create(ESM::NAME type)
{
    RecordBase *record = 0;

    switch (type.val) {
    case ESM::REC_ACTI:
    {
        record = new EsmTool::Record<ESM::Activator>;
        break;
    }
    case ESM::REC_ALCH:
    {
        record = new EsmTool::Record<ESM::Potion>;
        break;
    }
    case ESM::REC_APPA:
    {
        record = new EsmTool::Record<ESM::Apparatus>;
        break;
    }
    case ESM::REC_ARMO:
    {
        record = new EsmTool::Record<ESM::Armor>;
        break;
    }
    case ESM::REC_BODY:
    {
        record = new EsmTool::Record<ESM::BodyPart>;
        break;
    }
    case ESM::REC_BOOK:
    {
        record = new EsmTool::Record<ESM::Book>;
        break;
    }
    case ESM::REC_BSGN:
    {
        record = new EsmTool::Record<ESM::BirthSign>;
        break;
    }
    case ESM::REC_CELL:
    {
        record = new EsmTool::Record<ESM::Cell>;
        break;
    }
    case ESM::REC_CLAS:
    {
        record = new EsmTool::Record<ESM::Class>;
        break;
    }
    case ESM::REC_CLOT:
    {
        record = new EsmTool::Record<ESM::Clothing>;
        break;
    }
    case ESM::REC_CONT:
    {
        record = new EsmTool::Record<ESM::Container>;
        break;
    }
    case ESM::REC_CREA:
    {
        record = new EsmTool::Record<ESM::Creature>;
        break;
    }
    case ESM::REC_DIAL:
    {
        record = new EsmTool::Record<ESM::Dialogue>;
        break;
    }
    case ESM::REC_DOOR:
    {
        record = new EsmTool::Record<ESM::Door>;
        break;
    }
    case ESM::REC_ENCH:
    {
        record = new EsmTool::Record<ESM::Enchantment>;
        break;
    }
    case ESM::REC_FACT:
    {
        record = new EsmTool::Record<ESM::Faction>;
        break;
    }
    case ESM::REC_GLOB:
    {
        record = new EsmTool::Record<ESM::Global>;
        break;
    }
    case ESM::REC_GMST:
    {
        record = new EsmTool::Record<ESM::GameSetting>;
        break;
    }
    case ESM::REC_INFO:
    {
        record = new EsmTool::Record<ESM::DialInfo>;
        break;
    }
    case ESM::REC_INGR:
    {
        record = new EsmTool::Record<ESM::Ingredient>;
        break;
    }
    case ESM::REC_LAND:
    {
        record = new EsmTool::Record<ESM::Land>;
        break;
    }
    case ESM::REC_LEVI:
    {
        record = new EsmTool::Record<ESM::ItemLevList>;
        break;
    }
    case ESM::REC_LEVC:
    {
        record = new EsmTool::Record<ESM::CreatureLevList>;
        break;
    }
    case ESM::REC_LIGH:
    {
        record = new EsmTool::Record<ESM::Light>;
        break;
    }
    case ESM::REC_LOCK:
    {
        record = new EsmTool::Record<ESM::Tool>;
        break;
    }
    case ESM::REC_LTEX:
    {
        record = new EsmTool::Record<ESM::LandTexture>;
        break;
    }
    case ESM::REC_MISC:
    {
        record = new EsmTool::Record<ESM::Miscellaneous>;
        break;
    }
    case ESM::REC_MGEF:
    {
        record = new EsmTool::Record<ESM::MagicEffect>;
        break;
    }
    case ESM::REC_NPC_:
    {
        record = new EsmTool::Record<ESM::NPC>;
        break;
    }
    case ESM::REC_PGRD:
    {
        record = new EsmTool::Record<ESM::Pathgrid>;
        break;
    }
    case ESM::REC_PROB:
    {
        record = new EsmTool::Record<ESM::Probe>;
        break;
    }
    case ESM::REC_RACE:
    {
        record = new EsmTool::Record<ESM::Race>;
        break;
    }
    case ESM::REC_REGN:
    {
        record = new EsmTool::Record<ESM::Region>;
        break;
    }
    case ESM::REC_REPA:
    {
        record = new EsmTool::Record<ESM::Repair>;
        break;
    }
    case ESM::REC_SCPT:
    {
        record = new EsmTool::Record<ESM::Script>;
        break;
    }
    case ESM::REC_SKIL:
    {
        record = new EsmTool::Record<ESM::Skill>;
        break;
    }
    case ESM::REC_SNDG:
    {
        record = new EsmTool::Record<ESM::SoundGenerator>;
        break;
    }
    case ESM::REC_SOUN:
    {
        record = new EsmTool::Record<ESM::Sound>;
        break;
    }
    case ESM::REC_SPEL:
    {
        record = new EsmTool::Record<ESM::Spell>;
        break;
    }
    case ESM::REC_STAT:
    {
        record = new EsmTool::Record<ESM::Static>;
        break;
    }
    case ESM::REC_WEAP:
    {
        record = new EsmTool::Record<ESM::Weapon>;
        break;
    }
    case ESM::REC_SSCR:
    {
        record = new EsmTool::Record<ESM::StartScript>;
        break;
    }
    default:
        record = 0;
    }
    if (record) {
        record->mType = type;
    }
    return record;
}

template<>
void Record<ESM::Activator>::print()
{
    std::cout << "  Name: " << mData.mName << std::endl;
    std::cout << "  Model: " << mData.mModel << std::endl;
    std::cout << "  Script: " << mData.mScript << std::endl;
}

template<>
void Record<ESM::Potion>::print()
{
    std::cout << "  Name: " << mData.mName << std::endl;
    std::cout << "  Model: " << mData.mModel << std::endl;
    std::cout << "  Icon: " << mData.mIcon << std::endl;
    if (mData.mScript != "")
	std::cout << "  Script: " << mData.mScript << std::endl;
    std::cout << "  Weight: " << mData.mData.mWeight << std::endl;
    std::cout << "  Value: " << mData.mData.mValue << std::endl;
    std::cout << "  AutoCalc: " << mData.mData.mAutoCalc << std::endl;
    // mEffects missing
}

template<>
void Record<ESM::Armor>::print()
{
    std::cout << "  Name: " << mData.mName << std::endl;
    std::cout << "  Model: " << mData.mModel << std::endl;
    std::cout << "  Icon: " << mData.mIcon << std::endl;
    if (mData.mScript != "")
	std::cout << "  Script: " << mData.mScript << std::endl;
    if (mData.mEnchant != "")
	std::cout << "  Enchantment: " << mData.mEnchant << std::endl;
    std::cout << "  Type: " << mData.mData.mType << std::endl;
    std::cout << "  Weight: " << mData.mData.mWeight << std::endl;
    std::cout << "  Value: " << mData.mData.mValue << std::endl;
    std::cout << "  Health: " << mData.mData.mHealth << std::endl;
    std::cout << "  Armor: " << mData.mData.mArmor << std::endl; 
    std::cout << "  Enchantment Points: " << mData.mData.mEnchant << std::endl;
    // mParts missing
}

template<>
void Record<ESM::Apparatus>::print()
{
    std::cout << "  Name: " << mData.mName << std::endl;
    std::cout << "  Model: " << mData.mModel << std::endl;
    std::cout << "  Icon: " << mData.mIcon << std::endl;
    std::cout << "  Script: " << mData.mScript << std::endl;
    std::cout << "  Type: " << mData.mData.mType << std::endl;
    std::cout << "  Weight: " << mData.mData.mWeight << std::endl;
    std::cout << "  Value: " << mData.mData.mValue << std::endl;
    std::cout << "  Quality: " << mData.mData.mQuality << std::endl;
}

template<>
void Record<ESM::BodyPart>::print()
{
    std::cout << "  Name: " << mData.mName << std::endl;
    std::cout << "  Model: " << mData.mModel << std::endl;
    std::cout << "  Type: " << (int)mData.mData.mType << std::endl;
    std::cout << "  Flags: " << (int)mData.mData.mFlags << std::endl;
    std::cout << "  Part: " << (int)mData.mData.mPart << std::endl;
    std::cout << "  Vampire: " << (int)mData.mData.mVampire << std::endl;
}

template<>
void Record<ESM::Book>::print()
{
    std::cout << "  Name: " << mData.mName << std::endl;
    std::cout << "  Model: " << mData.mModel << std::endl;
    std::cout << "  Icon: " << mData.mIcon << std::endl;
    if (mData.mScript != "")
	std::cout << "  Script: " << mData.mScript << std::endl;
    if (mData.mEnchant != "")
	std::cout << "  Enchantment: " << mData.mEnchant << std::endl;
    std::cout << "  Weight: " << mData.mData.mWeight << std::endl;
    std::cout << "  Value: " << mData.mData.mValue << std::endl;
    std::cout << "  IsScroll: " << mData.mData.mIsScroll << std::endl;
    std::cout << "  SkillID: " << mData.mData.mSkillID << std::endl;
    std::cout << "  Enchantment Points: " << mData.mData.mEnchant << std::endl;
    // mText missing
}

template<>
void Record<ESM::BirthSign>::print()
{
    std::cout << "  Name: " << mData.mName << std::endl;
    std::cout << "  Texture: " << mData.mTexture << std::endl;
    std::cout << "  Description: " << mData.mDescription << std::endl;
    std::vector<std::string>::iterator pit;
    for (pit = mData.mPowers.mList.begin(); pit != mData.mPowers.mList.end(); pit++)
	std::cout << "  Power: " << *pit << std::endl;	  
}

template<>
void Record<ESM::Cell>::print()
{
    // None of the cells have names...
    if (mData.mName != "")
	std::cout << "  Name: " << mData.mName << std::endl;
    if (mData.mRegion != "")
	std::cout << "  Region: " << mData.mRegion << std::endl;
    std::cout << "  Flags: " << (int)mData.mData.mFlags << std::endl;
    
    std::cout << "  Coordinates: " << " (" << mData.getGridX() << ","
	      << mData.getGridY() << ")" << std::endl;
    
    if (mData.mData.mFlags & ESM::Cell::Interior && 
	!(mData.mData.mFlags & ESM::Cell::QuasiEx)) 
    {
	std::cout << "  Ambient Light Color: " << mData.mAmbi.mAmbient << std::endl;
	std::cout << "  Sunlight Color: " << mData.mAmbi.mSunlight << std::endl;
	std::cout << "  Fog Color: " << mData.mAmbi.mFog << std::endl;
	std::cout << "  Fog Density: " << mData.mAmbi.mFogDensity << std::endl;
	std::cout << "  Water Level: " << mData.mWater << std::endl;
    }
    else 
	std::cout << "  Map Color: " << boost::format("0x%08X") % mData.mMapColor << std::endl;
    std::cout << "  Water Level Int: " << mData.mWaterInt << std::endl;
    std::cout << "  NAM0: " << mData.mNAM0 << std::endl;

}

template<>
void Record<ESM::Class>::print()
{
    std::cout << "  Name: " << mData.mName << std::endl;
    std::cout << "  Description: " << mData.mDescription << std::endl;
    std::cout << "  Playable: " << mData.mData.mIsPlayable << std::endl;
    std::cout << "  AutoCalc: " << mData.mData.mCalc << std::endl;
    std::cout << "  Attribute1: " << mData.mData.mAttribute[0] << std::endl;
    std::cout << "  Attribute2: " << mData.mData.mAttribute[1] << std::endl;
    std::cout << "  Specialization: " << mData.mData.mSpecialization << std::endl;
    for (int i = 0; i != 5; i++)
	std::cout << "  Major Skill: " << mData.mData.mSkills[i][0] << std::endl;
    for (int i = 0; i != 5; i++)
	std::cout << "  Minor Skill: " << mData.mData.mSkills[i][1] << std::endl;
}

template<>
void Record<ESM::Clothing>::print()
{
    std::cout << "  Name: " << mData.mName << std::endl;
    std::cout << "  Model: " << mData.mModel << std::endl;
    std::cout << "  Icon: " << mData.mIcon << std::endl;
    if (mData.mScript != "")
	std::cout << "  Script: " << mData.mScript << std::endl;
    if (mData.mEnchant != "")
	std::cout << "  Enchantment: " << mData.mEnchant << std::endl;
    std::cout << "  Type: " << mData.mData.mType << std::endl;
    std::cout << "  Weight: " << mData.mData.mWeight << std::endl;
    std::cout << "  Value: " << mData.mData.mValue << std::endl;
    // mEnchant also in CTDTstruct?
}

template<>
void Record<ESM::Container>::print()
{
    std::cout << "  Name: " << mData.mName << std::endl;
    std::cout << "  Model: " << mData.mModel << std::endl;
    if (mData.mScript != "")
	std::cout << "  Script: " << mData.mScript << std::endl;
    std::cout << "  Flags: " << mData.mFlags << std::endl;
    std::cout << "  Weight: " << mData.mWeight << std::endl;
    // mInventory missing
}

template<>
void Record<ESM::Creature>::print()
{
    std::cout << "  Name: " << mData.mName << std::endl;
    std::cout << "  Model: " << mData.mModel << std::endl;
    std::cout << "  Script: " << mData.mScript << std::endl;
    std::cout << "  Flags: " << mData.mFlags << std::endl;
    std::cout << "  Original: " << mData.mOriginal << std::endl;
    std::cout << "  Scale: " << mData.mScale << std::endl;

    std::cout << "  Type: " << mData.mData.mType << std::endl;
    std::cout << "  Level: " << mData.mData.mLevel << std::endl;

    std::cout << "  Attributes:" << std::endl;
    std::cout << "    Strength: " << mData.mData.mStrength << std::endl;
    std::cout << "    Intelligence: " << mData.mData.mIntelligence << std::endl;
    std::cout << "    Willpower: " << mData.mData.mWillpower << std::endl;
    std::cout << "    Agility: " << mData.mData.mAgility << std::endl;
    std::cout << "    Speed: " << mData.mData.mSpeed << std::endl;
    std::cout << "    Endurance: " << mData.mData.mEndurance << std::endl;
    std::cout << "    Personality: " << mData.mData.mPersonality << std::endl;
    std::cout << "    Luck: " << mData.mData.mLuck << std::endl;

    std::cout << "  Health: " << mData.mData.mHealth << std::endl;
    std::cout << "  Magicka: " << mData.mData.mMana << std::endl;
    std::cout << "  Fatigue: " << mData.mData.mFatigue << std::endl;
    std::cout << "  Soul: " << mData.mData.mSoul << std::endl;
    std::cout << "  Combat: " << mData.mData.mCombat << std::endl;
    std::cout << "  Magic: " << mData.mData.mMagic << std::endl;
    std::cout << "  Stealth: " << mData.mData.mStealth << std::endl;
    std::cout << "  Attack1: " << mData.mData.mAttack[0] 
	      << "-" <<  mData.mData.mAttack[1] << std::endl;
    std::cout << "  Attack2: " << mData.mData.mAttack[2] 
	      << "-" <<  mData.mData.mAttack[3] << std::endl;
    std::cout << "  Attack3: " << mData.mData.mAttack[4] 
	      << "-" <<  mData.mData.mAttack[5] << std::endl;
    std::cout << "  Gold: " << mData.mData.mGold << std::endl;

    std::vector<ESM::ContItem>::iterator cit;
    for (cit = mData.mInventory.mList.begin(); cit != mData.mInventory.mList.end(); cit++)
	std::cout << "  Inventory: Count: " << boost::format("%4d") % cit->mCount 
		  << " Item: " << cit->mItem.toString() << std::endl;

    std::vector<std::string>::iterator sit;
    for (sit = mData.mSpells.mList.begin(); sit != mData.mSpells.mList.end(); sit++)
	std::cout << "  Spell: " << *sit << std::endl;

    std::cout << "  Artifical Intelligence: " << mData.mHasAI << std::endl;
    std::cout << "    AI Hello:" << (int)mData.mAiData.mHello << std::endl;
    std::cout << "    AI Fight:" << (int)mData.mAiData.mFight << std::endl;
    std::cout << "    AI Flee:" << (int)mData.mAiData.mFlee << std::endl;
    std::cout << "    AI Alarm:" << (int)mData.mAiData.mAlarm << std::endl;
    std::cout << "    AI U1:" << (int)mData.mAiData.mU1 << std::endl;
    std::cout << "    AI U2:" << (int)mData.mAiData.mU2 << std::endl;
    std::cout << "    AI U3:" << (int)mData.mAiData.mU3 << std::endl;
    std::cout << "    AI U4:" << (int)mData.mAiData.mU4 << std::endl;
    std::cout << "    AI Services:" << boost::format("0x%08X") % mData.mAiData.mServices << std::endl;

    std::vector<ESM::AIPackage>::iterator pit;
    for (pit = mData.mAiPackage.mList.begin(); pit != mData.mAiPackage.mList.end(); pit++)
	printAIPackage(*pit);
}

template<>
void Record<ESM::Dialogue>::print()
{
    std::cout << "  Type: " << (int)mData.mType << std::endl;
    // mInfo missing
}

template<>
void Record<ESM::Door>::print()
{
    std::cout << "  Name: " << mData.mName << std::endl;
    std::cout << "  Model: " << mData.mModel << std::endl;
    std::cout << "  Script: " << mData.mScript << std::endl;
    std::cout << "  OpenSound: " << mData.mOpenSound << std::endl;
    std::cout << "  CloseSound: " << mData.mCloseSound << std::endl;
}

template<>
void Record<ESM::Enchantment>::print()
{
    std::cout << "  Type: " << mData.mData.mType << std::endl;
    std::cout << "  Cost: " << mData.mData.mCost << std::endl;
    std::cout << "  Charge: " << mData.mData.mCharge << std::endl;
    std::cout << "  AutoCalc: " << mData.mData.mAutocalc << std::endl;
    // mEffects missing
}

template<>
void Record<ESM::Faction>::print()
{
    std::cout << "  Name: " << mData.mName << std::endl;
    std::cout << "  Hidden: " << mData.mData.mIsHidden << std::endl;
    if (mData.mData.mUnknown != -1)
	std::cout << "  Unknown: " << mData.mData.mUnknown << std::endl;
    std::cout << "  Attribute1: " << mData.mData.mAttribute1 << std::endl;
    std::cout << "  Attribute2: " << mData.mData.mAttribute2 << std::endl;
    for (int i = 0; i != 6; i++)
	if (mData.mData.mSkillID[i] != -1)
	    std::cout << "  Skill: " << mData.mData.mSkillID[i] << std::endl;
    for (int i = 0; i != 10; i++)
	if (mData.mRanks[i] != "")
	{
	    std::cout << "  Rank: " << mData.mRanks[i] << std::endl;
	    std::cout << "    Attribute1 Requirement: " 
		      << mData.mData.mRankData[i].mAttribute1 << std::endl;
	    std::cout << "    Attribute2 Requirement: " 
		      << mData.mData.mRankData[i].mAttribute2 << std::endl;
	    std::cout << "    One Skill at Level: "
		      << mData.mData.mRankData[i].mSkill1 << std::endl;
	    std::cout << "    Two Skills at Level: " 
		      << mData.mData.mRankData[i].mSkill2 << std::endl;
	    std::cout << "    Faction Reaction: " 
		      << mData.mData.mRankData[i].mFactReaction << std::endl;
	}
    std::vector<ESM::Faction::Reaction>::iterator rit;
    for (rit = mData.mReactions.begin(); rit != mData.mReactions.end(); rit++)
	std::cout << "  Reaction: " << rit->mReaction << " = " << rit->mFaction << std::endl;
}

template<>
void Record<ESM::Global>::print()
{
    // nothing to print (well, nothing that's correct anyway)
    std::cout << "  Type: " << mData.mType << std::endl;
    std::cout << "  Value: " << mData.mValue << std::endl;
}

template<>
void Record<ESM::GameSetting>::print()
{
    std::cout << "  Value: ";
    switch (mData.mType) {
    case ESM::VT_String:
        std::cout << "'" << mData.mStr << "' (std::string)";
        break;

    case ESM::VT_Float:
        std::cout << mData.mF << " (float)";
        break;

    case ESM::VT_Int:
        std::cout << mData.mI << " (int)";
        break;

    default:
        std::cout << "unknown type";
    }
    std::cout << "\n  Dirty: " << mData.mDirty << std::endl;
}

template<>
void Record<ESM::DialInfo>::print()
{
    std::cout << "  Id: " << mData.mId << std::endl;
    std::cout << "  Text: " << mData.mResponse << std::endl;
    // Lots missing, more coming
}

template<>
void Record<ESM::Ingredient>::print()
{
    std::cout << "  Name: " << mData.mName << std::endl;
    std::cout << "  Model: " << mData.mModel << std::endl;
    std::cout << "  Icon: " << mData.mIcon << std::endl;
    if (mData.mScript != "")
	std::cout << "  Script: " << mData.mScript << std::endl;
    std::cout << "  Weight: " << mData.mData.mWeight << std::endl;
    std::cout << "  Value: " << mData.mData.mValue << std::endl;
    for (int i = 0; i !=4; i++)
    {
	// A value of -1 means no effect
	if (mData.mData.mEffectID[i] == -1) continue;
	std::cout << "  Effect: " << mData.mData.mEffectID[i] << std::endl;
	std::cout << "  Skill: " << mData.mData.mSkills[i] << std::endl;
	std::cout << "  Attribute: " << mData.mData.mAttributes[i] << std::endl;
    }
}

template<>
void Record<ESM::Land>::print()
{
    std::cout << "  Coordinates: (" << mData.mX << "," << mData.mY << ")" << std::endl;
    // Lots missing, more coming
}

template<>
void Record<ESM::CreatureLevList>::print()
{
    std::cout << "  Chance for None: " << (int)mData.mChanceNone << std::endl;
    std::cout << "  Flags: " << mData.mFlags << std::endl;
    std::cout << "  Number of items: " << mData.mList.size() << std::endl;
    std::vector<ESM::LeveledListBase::LevelItem>::iterator iit;
    for (iit = mData.mList.begin(); iit != mData.mList.end(); iit++)
	std::cout << "  Creature: Level: " << iit->mLevel 
		  << " Creature: " << iit->mId << std::endl;
}

template<>
void Record<ESM::ItemLevList>::print()
{
    std::cout << "  Chance for None: " << (int)mData.mChanceNone << std::endl;
    std::cout << "  Flags: " << mData.mFlags << std::endl;
    std::cout << "  Number of items: " << mData.mList.size() << std::endl;
    std::vector<ESM::LeveledListBase::LevelItem>::iterator iit;
    for (iit = mData.mList.begin(); iit != mData.mList.end(); iit++)
	std::cout << "  Inventory: Count: " << iit->mLevel
		  << " Item: " << iit->mId << std::endl;
}

template<>
void Record<ESM::Light>::print()
{
    if (mData.mName != "")
	std::cout << "  Name: " << mData.mName << std::endl;
    if (mData.mModel != "")
	std::cout << "  Model: " << mData.mModel << std::endl;
    if (mData.mIcon != "")
	std::cout << "  Icon: " << mData.mIcon << std::endl;
    if (mData.mScript != "")
	std::cout << "  Script: " << mData.mScript << std::endl;
    std::cout << "  Flags: " << mData.mData.mFlags << std::endl;
    std::cout << "  Weight: " << mData.mData.mWeight << std::endl;
    std::cout << "  Value: " << mData.mData.mValue << std::endl;
    std::cout << "  Sound: " << mData.mSound << std::endl;
    std::cout << "  Duration: " << mData.mData.mTime << std::endl;
    std::cout << "  Radius: " << mData.mData.mRadius << std::endl;
    std::cout << "  Color: " << mData.mData.mColor << std::endl;
}

template<>
void Record<ESM::Tool>::print()
{
    std::cout << "  Name: " << mData.mName << std::endl;
    std::cout << "  Model: " << mData.mModel << std::endl;
    std::cout << "  Icon: " << mData.mIcon << std::endl;
    if (mData.mScript != "")
	std::cout << "  Script: " << mData.mScript << std::endl;
    std::cout << "  Type: " << mData.mType << std::endl;
    std::cout << "  Weight: " << mData.mData.mWeight << std::endl;
    std::cout << "  Value: " << mData.mData.mValue << std::endl;
    std::cout << "  Quality: " << mData.mData.mQuality << std::endl;
    std::cout << "  Uses: " << mData.mData.mUses << std::endl;
}

template<>
void Record<ESM::Probe>::print()
{
    std::cout << "  Name: " << mData.mName << std::endl;
    std::cout << "  Model: " << mData.mModel << std::endl;
    std::cout << "  Icon: " << mData.mIcon << std::endl;
    if (mData.mScript != "")
	std::cout << "  Script: " << mData.mScript << std::endl;
    std::cout << "  Type: " << mData.mType << std::endl;
    std::cout << "  Weight: " << mData.mData.mWeight << std::endl;
    std::cout << "  Value: " << mData.mData.mValue << std::endl;
    std::cout << "  Quality: " << mData.mData.mQuality << std::endl;
    std::cout << "  Uses: " << mData.mData.mUses << std::endl;
}

template<>
void Record<ESM::Repair>::print()
{
    std::cout << "  Name: " << mData.mName << std::endl;
    std::cout << "  Model: " << mData.mModel << std::endl;
    std::cout << "  Icon: " << mData.mIcon << std::endl;
    if (mData.mScript != "")
	std::cout << "  Script: " << mData.mScript << std::endl;
    std::cout << "  Type: " << mData.mType << std::endl;
    std::cout << "  Weight: " << mData.mData.mWeight << std::endl;
    std::cout << "  Value: " << mData.mData.mValue << std::endl;
    std::cout << "  Quality: " << mData.mData.mQuality << std::endl;
    std::cout << "  Uses: " << mData.mData.mUses << std::endl;
}

template<>
void Record<ESM::LandTexture>::print()
{
    std::cout << "  Id: " << mData.mId << std::endl;
    std::cout << "  Index: " << mData.mIndex << std::endl;
    std::cout << "  Texture: " << mData.mTexture << std::endl;
}

template<>
void Record<ESM::MagicEffect>::print()
{
    std::cout << "  Index: " << mData.mIndex << std::endl;
    std::cout << "  Description: " << mData.mDescription << std::endl;
    std::cout << "  Icon: " << mData.mIcon << std::endl;
    std::cout << "  Flags: " << mData.mData.mFlags << std::endl;
    std::cout << "  Particle Texture: " << mData.mParticle << std::endl;
    if (mData.mCasting != "")
	std::cout << "  Casting Static: " << mData.mCasting << std::endl;
    if (mData.mCastSound != "")
	std::cout << "  Casting Sound: " << mData.mCastSound << std::endl;
    if (mData.mBolt != "")
	std::cout << "  Bolt Static: " << mData.mBolt << std::endl;
    if (mData.mBoltSound != "")
	std::cout << "  Bolt Sound: " << mData.mBoltSound << std::endl;
    if (mData.mHit != "")
	std::cout << "  Hit Static: " << mData.mHit << std::endl;
    if (mData.mHitSound != "")
	std::cout << "  Hit Sound: " << mData.mHitSound << std::endl;
    if (mData.mArea != "")
	std::cout << "  Area Static: " << mData.mArea << std::endl;
    if (mData.mAreaSound != "")
	std::cout << "  Area Sound: " << mData.mAreaSound << std::endl;
    std::cout << "  School: " << mData.mData.mSchool << std::endl;
    std::cout << "  Base Cost: " << mData.mData.mBaseCost << std::endl;
    std::cout << "  Speed: " << mData.mData.mSpeed << std::endl;
    std::cout << "  Size: " << mData.mData.mSize << std::endl;
    std::cout << "  Size Cap: " << mData.mData.mSizeCap << std::endl;
    std::cout << "  RGB Color: " << "("
	      << mData.mData.mRed << ","
	      << mData.mData.mGreen << ","
	      << mData.mData.mGreen << ")" << std::endl;
}

template<>
void Record<ESM::Miscellaneous>::print()
{
    std::cout << "  Name: " << mData.mName << std::endl;
    std::cout << "  Model: " << mData.mModel << std::endl;
    std::cout << "  Icon: " << mData.mIcon << std::endl;
    if (mData.mScript != "")
	std::cout << "  Script: " << mData.mScript << std::endl;
    std::cout << "  Weight: " << mData.mData.mWeight << std::endl;
    std::cout << "  Value: " << mData.mData.mValue << std::endl;
    std::cout << "  Is Key: " << mData.mData.mIsKey << std::endl;
}

template<>
void Record<ESM::NPC>::print()
{
    std::cout << "  Name: " << mData.mName << std::endl;
    std::cout << "  Animation: " << mData.mModel << std::endl;
    std::cout << "  Hair Model: " << mData.mHair << std::endl;
    std::cout << "  Head Model: " << mData.mHead << std::endl;
    std::cout << "  Race: " << mData.mRace << std::endl;
    std::cout << "  Class: " << mData.mClass << std::endl;
    if (mData.mScript != "")
	std::cout << "  Script: " << mData.mScript << std::endl;
    if (mData.mFaction != "")
	std::cout << "  Faction: " << mData.mFaction << std::endl;
    std::cout << "  Flags: " << mData.mFlags << std::endl;

    // Seriously?
    if (mData.mNpdt52.mGold == -10)
    {
	std::cout << "  Level: " << mData.mNpdt12.mLevel << std::endl;
	std::cout << "  Reputation: " << (int)mData.mNpdt12.mReputation << std::endl;
	std::cout << "  Disposition: " << (int)mData.mNpdt12.mDisposition << std::endl;
	std::cout << "  Faction: " << (int)mData.mNpdt52.mFactionID << std::endl;
	std::cout << "  Rank: " << (int)mData.mNpdt12.mRank << std::endl;
	std::cout << "  Unknown1: " 
		  << (unsigned int)((unsigned char)mData.mNpdt12.mUnknown1) << std::endl;
	std::cout << "  Unknown2: " 
		  << (unsigned int)((unsigned char)mData.mNpdt12.mUnknown2) << std::endl;
	std::cout << "  Unknown3: " 
		  << (unsigned int)((unsigned char)mData.mNpdt12.mUnknown3) << std::endl;
	std::cout << "  Gold: " << (int)mData.mNpdt12.mGold << std::endl;
    }
    else {
	std::cout << "  Level: " << mData.mNpdt52.mLevel << std::endl;
	std::cout << "  Reputation: " << (int)mData.mNpdt52.mReputation << std::endl;
	std::cout << "  Disposition: " << (int)mData.mNpdt52.mDisposition << std::endl;
	std::cout << "  Rank: " << (int)mData.mNpdt52.mRank << std::endl;

	std::cout << "  Attributes:" << std::endl;
	std::cout << "    Strength: " << (int)mData.mNpdt52.mStrength << std::endl;
	std::cout << "    Intelligence: " << (int)mData.mNpdt52.mIntelligence << std::endl;
	std::cout << "    Willpower: " << (int)mData.mNpdt52.mWillpower << std::endl;
	std::cout << "    Agility: " << (int)mData.mNpdt52.mAgility << std::endl;
	std::cout << "    Speed: " << (int)mData.mNpdt52.mSpeed << std::endl;
	std::cout << "    Endurance: " << (int)mData.mNpdt52.mEndurance << std::endl;
	std::cout << "    Personality: " << (int)mData.mNpdt52.mPersonality << std::endl;
	std::cout << "    Luck: " << (int)mData.mNpdt52.mLuck << std::endl;

	std::cout << "  Skills:" << std::endl;
	for (int i = 0; i != 27; i++)
	    std::cout << "    " << i << " = " 
		      << (int)((unsigned char)mData.mNpdt52.mSkills[i]) << std::endl;	
	
	std::cout << "  Health: " << mData.mNpdt52.mHealth << std::endl;
	std::cout << "  Magicka: " << mData.mNpdt52.mMana << std::endl;
	std::cout << "  Fatigue: " << mData.mNpdt52.mFatigue << std::endl;
	std::cout << "  Unknown: " << (int)mData.mNpdt52.mUnknown << std::endl;
	std::cout << "  Gold: " << mData.mNpdt52.mGold << std::endl;
    }

    std::vector<ESM::ContItem>::iterator cit;
    for (cit = mData.mInventory.mList.begin(); cit != mData.mInventory.mList.end(); cit++)
	std::cout << "  Inventory: Count: " << boost::format("%4d") % cit->mCount 
		  << " Item: " << cit->mItem.toString() << std::endl;
    
    std::vector<std::string>::iterator sit;
    for (sit = mData.mSpells.mList.begin(); sit != mData.mSpells.mList.end(); sit++)
	std::cout << "  Spell: " << *sit << std::endl;

    std::vector<ESM::NPC::Dest>::iterator dit;
    for (dit = mData.mTransport.begin(); dit != mData.mTransport.end(); dit++)
    {
	std::cout << "  Destination Position: " 
		  << boost::format("%12.3f") % dit->mPos.pos[0] << ","
		  << boost::format("%12.3f") % dit->mPos.pos[1] << ","
		  << boost::format("%12.3f") % dit->mPos.pos[2] << ")" << std::endl;
	std::cout << "  Destination Rotation: " 
		  << boost::format("%9.6f") % dit->mPos.rot[0] << ","
		  << boost::format("%9.6f") % dit->mPos.rot[1] << ","
		  << boost::format("%9.6f") % dit->mPos.rot[2] << ")" << std::endl;		
	if (dit->mCellName != "")
	    std::cout << "  Destination Cell: " << dit->mCellName << std::endl;
    }
    
    std::cout << "  Artifical Intelligence: " << mData.mHasAI << std::endl;
    std::cout << "    AI Hello:" << (int)mData.mAiData.mHello << std::endl;
    std::cout << "    AI Fight:" << (int)mData.mAiData.mFight << std::endl;
    std::cout << "    AI Flee:" << (int)mData.mAiData.mFlee << std::endl;
    std::cout << "    AI Alarm:" << (int)mData.mAiData.mAlarm << std::endl;
    std::cout << "    AI U1:" << (int)mData.mAiData.mU1 << std::endl;
    std::cout << "    AI U2:" << (int)mData.mAiData.mU2 << std::endl;
    std::cout << "    AI U3:" << (int)mData.mAiData.mU3 << std::endl;
    std::cout << "    AI U4:" << (int)mData.mAiData.mU4 << std::endl;
    std::cout << "    AI Services:" << boost::format("0x%08X") % mData.mAiData.mServices << std::endl;

    std::vector<ESM::AIPackage>::iterator pit;
    for (pit = mData.mAiPackage.mList.begin(); pit != mData.mAiPackage.mList.end(); pit++)
	printAIPackage(*pit);
}

template<>
void Record<ESM::Pathgrid>::print()
{
    std::cout << "  Cell: " << mData.mCell << std::endl;
    std::cout << "  Coordinates: (" << mData.mData.mX << "," << mData.mData.mY << ")" << std::endl;
    std::cout << "  Unknown S1: " << mData.mData.mS1 << std::endl;
    if ((unsigned int)mData.mData.mS2 != mData.mPoints.size())
	std::cout << "  Reported Point Count: " << mData.mData.mS2 << std::endl;
    std::cout << "  Point Count: " << mData.mPoints.size() << std::endl;
    std::cout << "  Edge Count: " << mData.mEdges.size() << std::endl;

    int i = 0;
    ESM::Pathgrid::PointList::iterator pit;
    for (pit = mData.mPoints.begin(); pit != mData.mPoints.end(); pit++)
    {
	std::cout << "  Point[" << i << "]:" << std::endl;
	std::cout << "    Coordinates: (" << pit->mX << "," 
	     << pit->mY << "," << pit->mZ << ")" << std::endl;
	std::cout << "    Auto-Generated: " << (int)pit->mAutogenerated << std::endl;
	std::cout << "    Connections: " << (int)pit->mConnectionNum << std::endl;
	std::cout << "    Unknown: " << pit->mUnknown << std::endl;
	i++;
    }
    i = 0;
    ESM::Pathgrid::EdgeList::iterator eit;
    for (eit = mData.mEdges.begin(); eit != mData.mEdges.end(); eit++)
    {
	std::cout << "  Edge[" << i << "]: " << eit->mV0 << " -> " << eit->mV1 << std::endl;
	if (eit->mV0 >= mData.mData.mS2 || eit->mV1 >= mData.mData.mS2)
	    std::cout << "  BAD POINT IN EDGE!" << std::endl;
	i++;
    }
}

template<>
void Record<ESM::Race>::print()
{
    std::cout << "  Name: " << mData.mName << std::endl;
    std::cout << "  Description: " << mData.mDescription << std::endl;
    std::cout << "  Flags: " << mData.mData.mFlags << std::endl;

    std::cout << "  Male:" << std::endl;
    std::cout << "    Strength: "
	      << mData.mData.mStrength.mMale << std::endl;
    std::cout << "    Intelligence: "
	      << mData.mData.mIntelligence.mMale << std::endl;
    std::cout << "    Willpower: "
	      << mData.mData.mWillpower.mMale << std::endl;
    std::cout << "    Agility: "
	      << mData.mData.mAgility.mMale << std::endl;
    std::cout << "    Speed: "
	      << mData.mData.mSpeed.mMale << std::endl;
    std::cout << "    Endurance: "
	      << mData.mData.mEndurance.mMale << std::endl;
    std::cout << "    Personality: "
	      << mData.mData.mPersonality.mMale << std::endl;
    std::cout << "    Luck: "
	      << mData.mData.mLuck.mMale << std::endl;
    std::cout << "    Height: "
	      << mData.mData.mHeight.mMale << std::endl;
    std::cout << "    Weight: "
	      << mData.mData.mWeight.mMale << std::endl;

    std::cout << "  Female:" << std::endl;
    std::cout << "    Strength: "
	      << mData.mData.mStrength.mFemale << std::endl;
    std::cout << "    Intelligence: "
	      << mData.mData.mIntelligence.mFemale << std::endl;
    std::cout << "    Willpower: "
	      << mData.mData.mWillpower.mFemale << std::endl;
    std::cout << "    Agility: "
	      << mData.mData.mAgility.mFemale << std::endl;
    std::cout << "    Speed: "
	      << mData.mData.mSpeed.mFemale << std::endl;
    std::cout << "    Endurance: "
	      << mData.mData.mEndurance.mFemale << std::endl;
    std::cout << "    Personality: "
	      << mData.mData.mPersonality.mFemale << std::endl;
    std::cout << "    Luck: "
	      << mData.mData.mLuck.mFemale << std::endl;
    std::cout << "    Height: "
	      << mData.mData.mHeight.mFemale << std::endl;
    std::cout << "    Weight: "
	      << mData.mData.mWeight.mFemale << std::endl;

    for (int i = 0; i != 7; i++)
	// Not all races have 7 skills.
	if (mData.mData.mBonus[i].mSkill != -1)
	    std::cout << "  Skill: " << mData.mData.mBonus[i].mSkill
		      << " = " << mData.mData.mBonus[i].mBonus << std::endl;

    std::vector<std::string>::iterator sit;
    for (sit = mData.mPowers.mList.begin(); sit != mData.mPowers.mList.end(); sit++)
	std::cout << "  Power: " << *sit << std::endl;
}

template<>
void Record<ESM::Region>::print()
{
    std::cout << "  Name: " << mData.mName << std::endl;

    std::cout << "  Weather:" << std::endl;
    std::cout << "    Clear: " << (int)mData.mData.mClear << std::endl;
    std::cout << "    Cloudy: " << (int)mData.mData.mCloudy << std::endl;
    std::cout << "    Foggy: " << (int)mData.mData.mFoggy << std::endl;
    std::cout << "    Overcast: " << (int)mData.mData.mOvercast << std::endl;
    std::cout << "    Rain: " << (int)mData.mData.mOvercast << std::endl;
    std::cout << "    Thunder: " << (int)mData.mData.mThunder << std::endl;
    std::cout << "    Ash: " << (int)mData.mData.mAsh << std::endl;
    std::cout << "    Blight: " << (int)mData.mData.mBlight << std::endl;
    std::cout << "    UnknownA: " << (int)mData.mData.mA << std::endl;
    std::cout << "    UnknownB: " << (int)mData.mData.mB << std::endl;
    std::cout << "  Map Color: " << mData.mMapColor << std::endl;
    if (mData.mSleepList != "")
	std::cout << "  Sleep List: " << mData.mSleepList << std::endl;
    std::vector<ESM::Region::SoundRef>::iterator sit;
    for (sit = mData.mSoundList.begin(); sit != mData.mSoundList.end(); sit++)
	std::cout << "  Sound: " << (int)sit->mChance << " = " << sit->mSound.toString() << std::endl;
}

template<>
void Record<ESM::Script>::print()
{
    std::cout << "  Name: " << mData.mData.mName.toString() << std::endl;

    std::cout << "  Num Shorts: " << mData.mData.mNumShorts << std::endl;
    std::cout << "  Num Longs: " << mData.mData.mNumLongs << std::endl;
    std::cout << "  Num Floats: " << mData.mData.mNumFloats << std::endl;
    std::cout << "  Script Data Size: " << mData.mData.mScriptDataSize << std::endl;
    std::cout << "  Table Size: " << mData.mData.mStringTableSize << std::endl;

    std::cout << "  Script: [skipped]" << std::endl;
    // Skip until multi-line field is controllable by a command line option.
    //std::cout << "-------------------------------------------" << std::endl;
    //std::cout << s->scriptText << std::endl;
    //std::cout << "-------------------------------------------" << std::endl;
    std::vector<std::string>::iterator vit;
    for (vit = mData.mVarNames.begin(); vit != mData.mVarNames.end(); vit++)
	std::cout << "  Variable: " << *vit << std::endl;

    std::cout << "  ByteCode: ";
    std::vector<char>::iterator cit;
    for (cit = mData.mScriptData.begin(); cit != mData.mScriptData.end(); cit++)
	std::cout << boost::format("%02X") % (int)(*cit);
    std::cout << std::endl;
}

template<>
void Record<ESM::Skill>::print()
{
    std::cout << "  ID: " << mData.mIndex << std::endl;

    const char *spec = 0;
    int specId = mData.mData.mSpecialization;
    if (specId == 0) {
        spec = "Combat";
    } else if (specId == 1) {
        spec = "Magic";
    } else {
        spec = "Stealth";
    }
    std::cout << "  Type: " << spec << std::endl;
}

template<>
void Record<ESM::SoundGenerator>::print()
{
    std::cout << "  Creature: " << mData.mCreature << std::endl;
    std::cout << "  Sound: " << mData.mSound << std::endl;
    std::cout << "  Type: " << mData.mType << std::endl;
}

template<>
void Record<ESM::Sound>::print()
{
    std::cout << "  Sound: " << mData.mSound << std::endl;
    std::cout << "  Volume: " << (int)mData.mData.mVolume << std::endl;
    if (mData.mData.mMinRange != 0 && mData.mData.mMaxRange != 0)
	std::cout << "  Range: " << (int)mData.mData.mMinRange << " - " 
		  << (int)mData.mData.mMaxRange << std::endl;
}

template<>
void Record<ESM::Spell>::print()
{
    std::cout << "  Name: " << mData.mName << std::endl;
    std::cout << "  Type: " << mData.mData.mType << std::endl;
    std::cout << "  Flags: " << mData.mData.mFlags << std::endl;
    std::cout << "  Cost: " << mData.mData.mCost << std::endl;
    // mEffect missing
}

template<>
void Record<ESM::StartScript>::print()
{
    std::cout << "Start Script: " << mData.mScript << std::endl;
    std::cout << "Start Data: " << mData.mData << std::endl;
}

template<>
void Record<ESM::Static>::print()
{
    std::cout << "  Model: " << mData.mModel << std::endl;
}

template<>
void Record<ESM::Weapon>::print()
{
    // No names on VFX bolts
    if (mData.mName != "")
	std::cout << "  Name: " << mData.mName << std::endl;
    std::cout << "  Model: " << mData.mModel << std::endl;
    // No icons on VFX bolts or magic bolts
    if (mData.mIcon != "")
	std::cout << "  Icon: " << mData.mIcon << std::endl;
    if (mData.mScript != "")
	std::cout << "  Script: " << mData.mScript << std::endl;
    if (mData.mEnchant != "")
	std::cout << "  Enchantment: " << mData.mEnchant << std::endl;    
    std::cout << "  Type: " << mData.mData.mType << std::endl;
    std::cout << "  Flags: " << mData.mData.mFlags << std::endl;
    std::cout << "  Weight: " << mData.mData.mWeight << std::endl;
    std::cout << "  Value: " << mData.mData.mValue << std::endl;
    std::cout << "  Health: " << mData.mData.mHealth << std::endl;
    std::cout << "  Speed: " << mData.mData.mSpeed << std::endl;
    std::cout << "  Reach: " << mData.mData.mReach << std::endl;
    std::cout << "  Enchantment Points: " << mData.mData.mEnchant << std::endl;
    if (mData.mData.mChop[0] != 0 && mData.mData.mChop[1] != 0)
	std::cout << "  Chop: " << (int)mData.mData.mChop[0] << "-" 
		  << (int)mData.mData.mChop[1] << std::endl;
    if (mData.mData.mSlash[0] != 0 && mData.mData.mSlash[1] != 0)
	std::cout << "  Slash: " << (int)mData.mData.mSlash[0] << "-"
		  << (int)mData.mData.mSlash[1] << std::endl;
    if (mData.mData.mThrust[0] != 0 && mData.mData.mThrust[1] != 0)
	std::cout << "  Thrust: " << (int)mData.mData.mThrust[0] << "-" 
		  << (int)mData.mData.mThrust[1] << std::endl;
}

template<>
void Record<ESM::CellRef>::print()
{
    std::cout << "    Refnum: " << mData.mRefnum << std::endl;
    std::cout << "    ID: '" << mData.mRefID << "'\n";
    std::cout << "    Owner: '" << mData.mOwner << "'\n";
    std::cout << "    INTV: " << mData.mIntv << "   NAM9: " << mData.mIntv << std::endl;
}

} // end namespace
