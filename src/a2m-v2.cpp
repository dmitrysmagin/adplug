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

#include "a2m-v2.h"
#include "debug.h"

/*** public methods *************************************/

CPlayer *Ca2mv2Player::factory(Copl *newopl)
{
    return new Ca2mv2Player(newopl);
}

Ca2mv2Player::Ca2mv2Player(Copl *newopl) : CPlayer(newopl)
{
}

Ca2mv2Player::~Ca2mv2Player()
{
}

bool Ca2mv2Player::update()
{   
}

void Ca2mv2Player::rewind(int subsong)
{
}

float Ca2mv2Player::getrefresh()
{
    return 50.0;
}

bool Ca2mv2Player::load(const std::string &filename, const CFileProvider &fp)
{
    binistream *f = fp.open(filename);
    if (!f)
        return false;

    if (!fp.extension(filename, ".a2m") && !fp.extension(filename, ".a2t")) {
        fp.close(f);
        return false;
    }

    // Read the whole file
    unsigned long size = fp.filesize(f);
    char *tune = (char *)calloc(1, size);
    f->readString(tune, size);
    fp.close(f);

    if (!strncmp(tune, "_A2module_", 10)) {
        //a2m_import(tune);
    } else if (!strncmp(tune, "_A2tiny_module_", 15)) {
        //a2t_import(tune);
    }

    free(tune);

    rewind(0);
    return true;
}
