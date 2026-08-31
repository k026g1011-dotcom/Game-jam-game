#pragma once
namespace AnimationConfig
{
	inline constexpr int FrameCount = 4;
    inline constexpr int PlayerStandFrames[FrameCount] = {
          0,-1,-1,-1
    };
	//inline constexpr int PlayerWalkFrameCount = 4;
    inline constexpr int PlayerWalkFrames[FrameCount] = {
      0,1,2,3
    };
	//inline constexpr int PlayerPushFrameCount = 4;
    inline constexpr int PlayerPushFrames[FrameCount] = {
      4,5,6,7
    };
    inline constexpr int BlockIdleFrames[FrameCount] = {
   0,-1,-1,-1
    };
    inline constexpr int StarIdleFrames[FrameCount] = {
0,-1,-1,-1
    };
}