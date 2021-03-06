// ========= Copyright Open Fortress Developers, CC-BY-NC-SA ============
// Purpose: COFTeam slots into the g_Teams vector,
//      keeps track of a CBasePlayer *m_hLeader,
//      and reports some player-related events to COFGameRules
// Author(s): Nopey
//
#pragma once
#include "utlvector.h"
#include "team.h"

class COFTeam: public CTeam {
public:
    DECLARE_CLASS(COFTeam, CTeam);
    DECLARE_SERVERCLASS();

    COFTeam();
    virtual ~COFTeam();

	virtual void AddPlayer( CBasePlayer *pPlayer ) override;
	virtual void RemovePlayer( CBasePlayer *pPlayer ) override;

private:
	CNetworkVar( int, m_nFlagCaptures );
	CNetworkVar( unsigned int, m_iRole );

public:
	CUtlVector< CBaseEntity* > m_aObjects; // When buildings are implemented, change this to CBaseObject
};

COFTeam *GetGlobalOFTeam( int iIndex );
