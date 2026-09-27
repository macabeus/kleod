#ifndef GUARD_ANIM_H
#define GUARD_ANIM_H

#include "global.h"

void SetEntityAnimationInfoState(s32 slot, u8 state);
void UpdateEntityAnimationInfoEntries(void);
void DrawLevelHud_Hearts(void);
s32 DrawLevelHud_DreamStones(void);
void DrawLevelHud_Lives(void);
void DrawVisionSelectHud_Lives(void);
void DrawLevelTimer(void);
void DrawVisionStart(void);
void DrawVisionEnd(void);

#endif // GUARD_ANIM_H