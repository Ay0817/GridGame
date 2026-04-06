#pragma once

#include "Color.hpp"

namespace AyLib::Palette
{
	namespace Basic {
        inline constexpr Color Black    {   0,   0,   0, 255 };
        inline constexpr Color White    { 255, 255, 255, 255 };
        inline constexpr Color Gray     { 128, 128, 128, 255 };
        inline constexpr Color LightGray{ 192, 192, 192, 255 };
        inline constexpr Color DarkGray {  64,  64,  64, 255 };

        inline constexpr Color Red  { 255,   0,   0, 255 };
        inline constexpr Color Green{   0, 255,   0, 255 };
        inline constexpr Color Blue {   0,   0, 255, 255 };

        inline constexpr Color Yellow { 255, 255,   0, 255 };
        inline constexpr Color Cyan   {   0, 255, 255, 255 };
        inline constexpr Color Magenta{ 255,   0, 255, 255 };

        inline constexpr Color Orange  { 255, 165,   0, 255 };
        inline constexpr Color Pink    { 255, 192, 203, 255 };
        inline constexpr Color Purple  { 128,   0, 128, 255 };
        inline constexpr Color Brown   { 139,  69,  19, 255 };
        inline constexpr Color Lime    {  50, 205,  50, 255 };
        inline constexpr Color SkyBlue { 135, 206, 235, 255 };
        inline constexpr Color Navy    {   0,   0, 128, 255 };
        inline constexpr Color Gold    { 255, 215,   0, 255 };
	}

	namespace Vspo {
        inline constexpr Color Sumire { 176, 196, 222, 255 };
        inline constexpr Color Nazuna { 250, 190, 220, 255 };
        inline constexpr Color Toto   { 255, 243,  63, 255 };
        inline constexpr Color Uruha  {  65, 130, 250, 255 };
        inline constexpr Color Noa    { 255, 219, 254, 255 };
        inline constexpr Color Mimi   { 199, 178, 214, 255 };
        inline constexpr Color Sena   { 255, 255, 255, 255 };
        inline constexpr Color Hinano { 250, 150, 200, 255 };
        inline constexpr Color Lisa   { 209, 222, 121, 255 };
        inline constexpr Color Ren    { 190,  33,  82, 255 };
        inline constexpr Color Qpi    { 255, 210,  60, 255 };
        inline constexpr Color Beni   { 133, 202, 179, 255 };
        inline constexpr Color Ema    { 180, 241, 249, 255 };
        inline constexpr Color Runa   { 241, 173, 255, 255 };
        inline constexpr Color Tsuna  { 255,  54,  82, 255 };
        inline constexpr Color Ramune { 142, 206, 217, 255 };
        inline constexpr Color Meto   { 251, 160,  63, 255 };
        inline constexpr Color Akari  { 255, 153, 141, 255 };
        inline constexpr Color Kuromu { 144, 158, 200, 255 };
        inline constexpr Color Kokage {  81, 149, 225, 255 };
        inline constexpr Color Yuuhi  { 237, 120,  74, 255 };
        inline constexpr Color Hanabi { 234,  85,   6, 255 };
        inline constexpr Color Moka   { 236, 160, 170, 255 };
        inline constexpr Color Saine  {  88,  83,  94, 255 };
        inline constexpr Color Chise  { 190, 255, 119, 255 };
	}
}
