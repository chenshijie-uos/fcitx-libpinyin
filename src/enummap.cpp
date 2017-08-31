/***************************************************************************
 *   Copyright (C) 2011~2011 by CSSlayer                                   *
 *   wengxt@gmail.com                                                      *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.              *
 ***************************************************************************/

#include <assert.h>
#include <iostream>
#include "enummap.h"

PinyinAmbiguity2 FcitxLibPinyinTransAmbiguity(FCITX_AMBIGUITY ambiguity)
{
    switch(ambiguity) {
        case FCITX_AMB_CiChi:
            return PINYIN_AMB_C_CH;
        case FCITX_AMB_ZiZhi:
            return PINYIN_AMB_Z_ZH;
        case FCITX_AMB_SiShi:
            return PINYIN_AMB_S_SH;
        case FCITX_AMB_LeNe:
            return PINYIN_AMB_L_N;
        case FCITX_AMB_FoHe:
            return PINYIN_AMB_F_H;
        case FCITX_AMB_LeRi:
            return PINYIN_AMB_L_R;
        case FCITX_AMB_GeKe:
            return PINYIN_AMB_G_K;
        case FCITX_AMB_AnAng:
            return PINYIN_AMB_AN_ANG;
        case FCITX_AMB_EnEng:
            return PINYIN_AMB_EN_ENG;
        case FCITX_AMB_InIng:
            return PINYIN_AMB_IN_ING;
        default:
            return PINYIN_AMB_ALL;
    }
}

PinyinCorrection2 FcitxLibPinyinTransCorrection(FCITX_CORRECTION correction)
{
    switch(correction) {
        case FCITX_CR_V_U:
            return PINYIN_CORRECT_V_U;
        case FCITX_CR_GN_NG:
            return PINYIN_CORRECT_GN_NG;
        case FCITX_CR_MG_NG:
            return PINYIN_CORRECT_MG_NG;
        case FCITX_CR_IOU_IU:
            return PINYIN_CORRECT_IOU_IU;
        case FCITX_CR_UEI_UI:
            return PINYIN_CORRECT_UEI_UI;
        case FCITX_CR_UEN_UN:
            return PINYIN_CORRECT_UEN_UN;
        case FCITX_CR_UE_VE:
            return PINYIN_CORRECT_UE_VE;
        case FCITX_CR_ON_ONG:
            return PINYIN_CORRECT_ON_ONG;
        default:
            return PINYIN_CORRECT_ALL;
    }
}

DoublePinyinScheme FcitxLibPinyinTransShuangpinScheme(FCITX_SHUANGPIN_SCHEME scheme)
{
    switch(scheme) {
        case FCITX_SHUANG_PIN_ZRM:
            return DOUBLE_PINYIN_ZRM;
        case FCITX_SHUANG_PIN_MS:
            return DOUBLE_PINYIN_MS;
        case FCITX_SHUANG_PIN_ZIGUANG:
            return DOUBLE_PINYIN_ZIGUANG;
        case FCITX_SHUANG_PIN_ABC:
            return DOUBLE_PINYIN_ABC;
        case FCITX_SHUANG_PIN_PYJJ:
            return DOUBLE_PINYIN_PYJJ;
        case FCITX_SHUANG_PIN_XHE:
            return DOUBLE_PINYIN_XHE;
        default:
            return DOUBLE_PINYIN_ZRM;
    }
}

ZhuyinScheme FcitxLibPinyinTransZhuyinLayout(FCITX_ZHUYIN_LAYOUT layout)
{
    switch(layout) {
        case FCITX_ZHUYIN_STANDARD:
            return ZHUYIN_STANDARD;
        case FCITX_ZHUYIN_IBM:
            return ZHUYIN_IBM;
        case FCITX_ZHUYIN_GIN_YIEH:
            return ZHUYIN_GINYIEH;
        case FCITX_ZHUYIN_ET:
            return ZHUYIN_ETEN;
        default:
            return ZHUYIN_STANDARD;
    }
}

static const int dictMap[] =
{
    4,
    5,
    6,
    7,
    8,
    9,
    10,
    11,
    12,
    13,
    14,
    15,
};

int FcitxLibPinyinTransDictionary(FCITX_DICTIONARY dict)
{
    int sz = sizeof(dictMap) / sizeof(dictMap[0]);
    int sz2 = FCITX_DICT_LAST + 1;
    assert(sz == sz2);
    return dictMap[dict];
}

static const int dictMapZhuyin[] =
{
    4,
    5,
    6,
    7,
    8,
    9,
    10,
    11,
    12,
    13
};

int FcitxLibPinyinTransZhuyinDictionary(FCITX_ZHUYIN_DICTIONARY dict)
{
    int sz = sizeof(dictMapZhuyin) / sizeof(dictMapZhuyin[0]);
    int sz2 = FCITX_ZHUYIN_DICT_LAST + 1;
    assert(sz == sz2);
    return dictMapZhuyin[dict];
}

sort_option_t FcitxLibPinyinTransSortOption(FCITX_LIBPINYIN_SORT sort) {
    switch(sort) {
        case FLS_PhraseLengthAndFreq:
            return SORT_BY_PHRASE_LENGTH_AND_FREQUENCY;
        case FLS_PhraseLengthAndPinyinLengthAndFreq:
        default:
            return SORT_BY_PHRASE_LENGTH_AND_PINYIN_LENGTH_AND_FREQUENCY;
    }
}
