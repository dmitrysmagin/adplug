/*
 * Adplug - Replayer for many OPL2/OPL3 audio file formats.
 * Copyright (C) 1999 - 2008 Simon Peter, <dn.tlp@gmx.net>, et al.
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#ifndef H_ADPLUG_A2MPLAYER
#define H_ADPLUG_A2MPLAYER

#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

#include "player.h"

class Ca2mv2Player : public CPlayer
{
public:
    static CPlayer *factory(Copl *newopl);

    Ca2mv2Player(Copl *newopl);
    ~Ca2mv2Player();

    bool load(const std::string &filename, const CFileProvider &fp);
    bool update();
    void rewind(int subsong);
    float getrefresh();

    std::string gettype() { return std::string("Adlib Tracker 2"); };

private:
};

#endif
