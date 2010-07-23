//____________________________________________________________________
// File: WCS.cpp
//____________________________________________________________________
//
// Author: Shaun ASHBY <Shaun.Ashby@gmail.com>
// Update: 2010-07-20 11:04:47+0200
// Revision: $Id$
//
// Copyright: 2010 (C) Shaun ASHBY
//
//--------------------------------------------------------------------
#include "WCS.h"

WCS::WCS(std::string & basedir, std::string & instrument)
	: m_basedir(basedir), m_instrument(instrument), m_projections(new std::vector<Projection*>())
{}

WCS::~WCS() {
	delete m_projections;
}

std::string & WCS::basedir() const {
	return m_basedir;
}

std::string & WCS::instrument() const {
	return m_instrument;
}

std::vector<Projection *> *WCS::projections() const {
	return m_projections;
}
