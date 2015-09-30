/****************************************************************************
Copyright 2015 Ricardo Quesada

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
****************************************************************************/

#include "palette.h"


static const QColor Palettes[][16] = {
    {
        // Colors from here: http://www.blitzbasic.com/Community/posts.php?topic=52312
        {0x00, 0x00, 0x00},
        {0xFF, 0xFF, 0xFF},
        {0x74, 0x43, 0x35},
        {0x7C, 0xAC, 0xBA},
        {0x7B, 0x48, 0x90},
        {0x64, 0x97, 0x4F},
        {0x40, 0x32, 0x85},
        {0xBF, 0xCD, 0x7A},
        {0x7B, 0x5B, 0x2F},
        {0x4f, 0x45, 0x00},
        {0xa3, 0x72, 0x65},
        {0x50, 0x50, 0x50},
        {0x78, 0x78, 0x78},
        {0xa4, 0xd7, 0x8e},
        {0x78, 0x6a, 0xbd},
        {0x9f, 0x9f, 0x9f},
    },
    {
        // Pepto: Colors from here: http://www.pepto.de/projects/colorvic/
        {0x00, 0x00, 0x00},
        {0xFF, 0xFF, 0xFF},
        {0x68, 0x37, 0x2B},
        {0x70, 0xA4, 0xB2},
        {0x6F, 0x3D, 0x86},
        {0x58, 0x8D, 0x43},
        {0x35, 0x28, 0x79},
        {0xB8, 0xC7, 0x6F},
        {0x6F, 0x4F, 0x25},
        {0x43, 0x39, 0x00},
        {0x9A, 0x67, 0x59},
        {0x44, 0x44, 0x44},
        {0x6C, 0x6C, 0x6C},
        {0x9A, 0xD2, 0x84},
        {0x6C, 0x5E, 0xB5},
        {0x95, 0x95, 0x95},
    },
    {
        // Pepto to grayscale using: r * 0.299 + g * 0.587 + b * 0.114
        {0x00, 0x00, 0x00},
        {0xff, 0xff, 0xff},
        {0x44, 0x44, 0x44},
        {0x96, 0x96, 0x96},
        {0x54, 0x54, 0x54},
        {0x74, 0x74, 0x74},
        {0x35, 0x35, 0x35},
        {0xb8, 0xb8, 0xb8},
        {0x53, 0x53, 0x53},
        {0x35, 0x35, 0x35},
        {0x74, 0x74, 0x74},
        {0x44, 0x44, 0x44},
        {0x6b, 0x6b, 0x6b},
        {0xb8, 0xb8, 0xb8},
        {0x6c, 0x6c, 0x6c},
        {0x94, 0x94, 0x94},
    }
};

int Palette::_paletteIndex = 1;

const QColor* Palette::getPalette()
{
    return Palettes[_paletteIndex];
}

void Palette::setActivePaletteIndex(int index)
{
    _paletteIndex = index;
}

int Palette::getActivePaletteIndex()
{
    return _paletteIndex;
}
