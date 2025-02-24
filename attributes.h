#include <commctrl.h>


/*

SWCCGDM.DAT Format

SWCCGDMDATA3.00<NULL>VVVVV<NULL>RRRRR<NULL>
Attributes\0Name\0Lore\0Game_Text\0

VVVVV = version (changes that affect sort)
RRRRR = revision (changes that don't affect sort)

Attributes (15 bytes)

Byte	Use
0		Destiny

1		Type
2		Subtype
		L	= location
		LP	= system
		LT	= site
		LM	= mobile system
		LV	= mobile site
		LS  = sector

		C	= character
		CR	= rebel
		CI	= imperial
		CA	= alien
		CD	= droid

		R	= creature

		V	= vehicle
		VT	= transport
		VC	= creature
		VS	= shuttle
		VB  = combat vehicle

		S	= starship
		SC	= capital
		SF	= starfighter
		SS	= squadron

		I	= interrupt
		IL	= lost
		IU	= used
		IB	= used or lost
		IS  = starting

		E	= effect
		EE	= normal
		EU	= utinni
		EI	= immediate

		W	= weapon
		WD	= death star
		WC	= character
		WA	= automated
		WS	= starship

		D	= device

		N	= event

3		Deploy/Interior or Exterior site(I or E)
4		Forfeit
5		Power/Ferocity/Rebel Force
6		Ability/Armor/Maneuver/Defense/Imperial Force
7		Pilot(Y/N)/Hyperdrive/Landspeed/Parsec
8		Warrior(Y/N)/Perm. Pilot(Y/N)
9		Rarity		R  U  C   N F
10		Subrarity	12 12 123 A ''
11		Set **** (see below ****
12		Side l or d (light or dark)
13		Astromech(Y/N)
14		extra icon

extra icon

	I	Imperial
	R	Rebel
	S	Scomp Link
	D	Dejarik
	1-6	Destiny
	W	Warrior
	A	Astromech (non-ships)

    N	Interior
	X	Exterior
	D	Dejarik


Set codes are as defined by Chris Gregg's spoilers:

	p	Premiere
	i	Premiere 2-Player
	E	ESB 2-Player
	u	Unlimited
	a	A New Hope
	r	Rebel Leader
	j	Jedi Pack
	h	Hoth
	d	Dagobah
	c	Cloud City
	J	Jabba's Palace
	s	Special Edition
	1	First Anthology
	2	Second Anthology
	S	Official Sealed Deck

*/

#define ATT_DESTINY	  0

#define ATT_TYPE	  1

#define ATT_SUBTYPE   2	

#define	ATT_DEPLOY	  3
#define ATT_EXTINT	  3

#define ATT_FORFEIT	  4

#define ATT_POWER	  5
#define ATT_RFORCE	  5

#define ATT_ABILITY	  6
#define ATT_DEFENSE	  6
#define ATT_IFORCE	  6

#define ATT_PILOT	  7
#define ATT_SPEED	  7
#define	ATT_PARSEC	  7

#define ATT_WARRIOR	  8
#define ATT_PPILOT	  8

#define	ATT_RARITY	  9

#define ATT_SUBRARITY 10

#define	ATT_SET		  11

#define ATT_SIDE	  12

#define ATT_ASTRO	  13

#define ATT_ICON	  14

#define ATT_DESTINY2  15

#define ATT_LIMITED   16

#define ATT_MAX       17

#define IGEN_HANDLE		0

#define IGEN_NONE		0

#define IDST_HANDLE		1

#define IDST_BLANK		0
#define IDST_0			1
#define IDST_1			2
#define IDST_2			3
#define IDST_3			4
#define IDST_4			5
#define IDST_5			6
#define IDST_6			7
#define IDST_7			8
#define IDST_PI			9
#define IDST_X			10

#define ITYP_HANDLE		2

#define ITYP_SYSTEM		0
#define ITYP_INTSITE	1
#define ITYP_EXTSITE	2
#define ITYP_MOBILE		3
#define ITYP_DEJARIK	4
#define ITYP_REBEL		5
#define ITYP_IMP		6
#define ITYP_DROID		7
#define ITYP_ALIEN		8
#define ITYP_CRITTER	9
#define ITYP_VEHICLE	10
#define ITYP_SHIP		11
#define ITYP_EFFECT		12
#define ITYP_WEAPON		13
#define ITYP_DEVICE		14
#define ITYP_EVENT		15
#define ITYP_OBJECTIVE	16
#define ITYP_JEDITEST	17
#define ITYP_JEDIMAST	18
#define ITYP_STARTING	19
#define ITYP_SECTOR		20
#define ITYP_INT		21

#define IICO_HANDLE		3

#define IICO_PILOT		0
#define IICO_ASTRO		1
#define IICO_WARRIOR	2
#define IICO_SCOMP		3
#define IICO_SPY		4
#define IICO_LEADER		5
#define IICO_BOUNTY		6
#define IICO_ENCLOSED	7
#define IICO_PERMWEAPON	8
#define IICO_INDEPENDANT 9
#define IICO_UORL		10
#define IICO_UTINNI		11
#define IICO_IMMED		12
#define IICO_LOST		13
#define IICO_MOBEFFECT	14

#define IRAR_HANDLE		4

#define IRAR_R1			0
#define IRAR_R2			1
#define IRAR_R			2
#define IRAR_U1			3
#define IRAR_U2			4
#define IRAR_U			5
#define IRAR_C1			6
#define IRAR_C2			7
#define IRAR_C3			8
#define IRAR_C			9
#define IRAR_NA			10
#define IRAR_F			11

#define ISET_HANDLE		5

#define ISET_PLTD		0
#define ISET_PULTD		1
#define ISET_2P			2
#define ISET_ANH		3
#define ISET_ANHUL		4
#define ISET_RL			5
#define ISET_HOTH		6
#define ISET_HOTHUL		7
#define ISET_DAGOBAH	8
#define ISET_DAGOBAHUL	9
#define ISET_BESPIN		10
#define ISET_BESPINUL	11
#define ISET_JABBA		12
#define ISET_JABBAUL	13
#define ISET_ENDOR		14
#define ISET_ENDORUL	15
#define ISET_DEATHSTAR	16
#define ISET_DEATHSTARUL 17
#define ISET_SE			18
#define ISET_ANTHOLOGY	19
#define ISET_EPP		20
#define ISET_JEDIPACK	21
#define ISET_OTSD		22

#define IFRC_HANDLE		6

#define IFRC_NONE		0
#define IFRC_R1			1
#define IFRC_R2			2
#define IFRC_R3			3
#define IFRC_I1			4
#define IFRC_I2			5
#define IFRC_I3			6

#define IDEP_HANDLE		7

enum {
	IDEP_0,
	IDEP_1,
	IDEP_2,
	IDEP_3,
	IDEP_4,
	IDEP_5,
	IDEP_6,
	IDEP_7,
	IDEP_8,
	IDEP_9,
	IDEP_X,
	IDEP_15
};

#define IFIT_HANDLE	8

enum {
	IFIT_0,
	IFIT_1,
	IFIT_2,
	IFIT_3,
	IFIT_4,
	IFIT_5,
	IFIT_6,
	IFIT_7,
	IFIT_8,
	IFIT_9,
	IFIT_X,
	IFIT_15,
};

#define IBAK_HANDLE 9

#define IBAK_LS		1
#define IBAK_DS		0

#define ICO_NONE	MAKELONG(IGEN_HANDLE,IGEN_NONE) //0
#define ICO_BLANK	MAKELONG(IDST_HANDLE,IDST_BLANK) //1
//all +1 from here...
#define ICO_DEST0	MAKELONG(IDST_HANDLE,IDST_0) //1
#define ICO_DEST1   MAKELONG(IDST_HANDLE,IDST_1) //2
#define ICO_DEST2	MAKELONG(IDST_HANDLE,IDST_2) //3
#define ICO_DEST3	MAKELONG(IDST_HANDLE,IDST_3) //4
#define ICO_DEST4	MAKELONG(IDST_HANDLE,IDST_4) //5
#define ICO_DEST5	MAKELONG(IDST_HANDLE,IDST_5) //6
#define ICO_DEST6	MAKELONG(IDST_HANDLE,IDST_6) //7
#define ICO_DEST7   MAKELONG(IDST_HANDLE,IDST_7) //8
#define ICO_SYSTEM	MAKELONG(ITYP_HANDLE,ITYP_SYSTEM) //9
#define ICO_INTSITE	MAKELONG(ITYP_HANDLE,ITYP_INTSITE) //10
#define ICO_EXTSITE	MAKELONG(ITYP_HANDLE,ITYP_EXTSITE) //11
#define ICO_MOBILE	MAKELONG(ITYP_HANDLE,ITYP_MOBILE) //12
#define ICO_DEJARIK	MAKELONG(ITYP_HANDLE,ITYP_DEJARIK) //13
#define ICO_REBEL	MAKELONG(ITYP_HANDLE,ITYP_REBEL) //14
#define ICO_IMP		MAKELONG(ITYP_HANDLE,ITYP_IMP) //15
#define ICO_DROID	MAKELONG(ITYP_HANDLE,ITYP_DROID) //16
#define ICO_ALIEN	MAKELONG(ITYP_HANDLE,ITYP_ALIEN) //17
#define ICO_CRITTER	MAKELONG(ITYP_HANDLE,ITYP_CRITTER) //18
#define ICO_VEHICLE	MAKELONG(ITYP_HANDLE,ITYP_VEHICLE) //19
#define ICO_SHIP	MAKELONG(ITYP_HANDLE,ITYP_SHIP) //20
#define ICO_INT		MAKELONG(ITYP_HANDLE,ITYP_INT) //21
#define ICO_UORL	MAKELONG(IICO_HANDLE,IICO_UORL) //22
#define ICO_EFFECT	MAKELONG(ITYP_HANDLE,ITYP_EFFECT) //23
#define ICO_UTINNI	MAKELONG(IICO_HANDLE,IICO_UTINNI) //24
#define ICO_IMMED	MAKELONG(IICO_HANDLE,IICO_IMMED) //25
#define ICO_RFORCE0	MAKELONG(IFRC_HANDLE,IFRC_NONE) //26
#define ICO_RFORCE1	MAKELONG(IFRC_HANDLE,IFRC_R1) //27
#define ICO_RFORCE2	MAKELONG(IFRC_HANDLE,IFRC_R2) //28
#define ICO_RFORCE3	MAKELONG(IFRC_HANDLE,IFRC_R3) //29
#define ICO_IFORCE0	MAKELONG(IFRC_HANDLE,IFRC_NONE) //30
#define ICO_IFORCE1	MAKELONG(IFRC_HANDLE,IFRC_I1) //31
#define ICO_IFORCE2	MAKELONG(IFRC_HANDLE,IFRC_I2) //32
#define ICO_IFORCE3	MAKELONG(IFRC_HANDLE,IFRC_I3) //33
#define ICO_WEAPON	MAKELONG(ITYP_HANDLE,ITYP_WEAPON) //34
#define ICO_DEVICE	MAKELONG(ITYP_HANDLE,ITYP_DEVICE) //35
#define ICO_PILOT	MAKELONG(IICO_HANDLE,IICO_PILOT) //36
#define ICO_ASTRO	MAKELONG(IICO_HANDLE,IICO_ASTRO) //37
#define ICO_WARRIOR	MAKELONG(IICO_HANDLE,IICO_WARRIOR) //38
#define ICO_R1		MAKELONG(IRAR_HANDLE,IRAR_R1) //39
#define ICO_R2		MAKELONG(IRAR_HANDLE,IRAR_R2) //40
#define ICO_U1		MAKELONG(IRAR_HANDLE,IRAR_U1) //41
#define ICO_U2		MAKELONG(IRAR_HANDLE,IRAR_U2) //42
#define ICO_C1		MAKELONG(IRAR_HANDLE,IRAR_C1) //43
#define ICO_C2		MAKELONG(IRAR_HANDLE,IRAR_C2) //44
#define ICO_C3		MAKELONG(IRAR_HANDLE,IRAR_C3) //45
#define ICO_NA		MAKELONG(IRAR_HANDLE,IRAR_NA) //46
#define ICO_SCOMP	MAKELONG(IICO_HANDLE,IICO_SCOMP) //47
#define ICO_LTD		MAKELONG(ISET_HANDLE,ISET_PLTD) //48
#define ICO_ULTD	MAKELONG(ISET_HANDLE,ISET_PULTD) //49
#define ICO_2P		MAKELONG(ISET_HANDLE,ISET_2P) //50
#define ICO_ANH		MAKELONG(ISET_HANDLE,ISET_ANH) //51
#define ICO_RL		MAKELONG(ISET_HANDLE,ISET_RL) //52
#define ICO_EVENT	MAKELONG(ITYP_HANDLE,ITYP_EVENT) //53
#define ICO_LOST	MAKELONG(IICO_HANDLE,IICO_LOST) //54
#define ICO_HOTH	MAKELONG(ISET_HANDLE,ISET_HOTH) //55
#define ICO_DESTPI	MAKELONG(IDST_HANDLE,IDST_PI) //56
#define ICO_DESTX   MAKELONG(ISET_HANDLE,IDST_X) //57
#define ICO_DEPLOY0 MAKELONG(IDEP_HANDLE,IDEP_0) //58
#define ICO_DEPLOY1 MAKELONG(IDEP_HANDLE,IDEP_1) //59
#define ICO_DEPLOY2 MAKELONG(IDEP_HANDLE,IDEP_2) //60
#define ICO_DEPLOY3 MAKELONG(IDEP_HANDLE,IDEP_3) //61
#define ICO_DEPLOY4 MAKELONG(IDEP_HANDLE,IDEP_4) //62
#define ICO_DEPLOY5 MAKELONG(IDEP_HANDLE,IDEP_5) //63
#define ICO_DEPLOY6 MAKELONG(IDEP_HANDLE,IDEP_6) //64
#define ICO_DEPLOY7 MAKELONG(IDEP_HANDLE,IDEP_7) //65
#define ICO_DEPLOY8 MAKELONG(IDEP_HANDLE,IDEP_8) //66
#define ICO_DEPLOY9 MAKELONG(IDEP_HANDLE,IDEP_9) //67
#define ICO_DEPLOYX MAKELONG(IDEP_HANDLE,IDEP_X) //68
#define ICO_FORFEIT0 MAKELONG(IFIT_HANDLE,IFIT_0) //69
#define ICO_FORFEITHALF MAKELONG(IFIT_HANDLE,IFIT_HALF)
#define ICO_FORFEIT1 MAKELONG(IFIT_HANDLE,IFIT_1) //70
#define ICO_FORFEIT2 MAKELONG(IFIT_HANDLE,IFIT_2) //71
#define ICO_FORFEIT3 MAKELONG(IFIT_HANDLE,IFIT_3) //72
#define ICO_FORFEIT4 MAKELONG(IFIT_HANDLE,IFIT_4) //73
#define ICO_FORFEIT5 MAKELONG(IFIT_HANDLE,IFIT_5) //74
#define ICO_FORFEIT6 MAKELONG(IFIT_HANDLE,IFIT_6) //75
#define ICO_FORFEIT7 MAKELONG(IFIT_HANDLE,IFIT_7) //76
#define ICO_FORFEIT8 MAKELONG(IFIT_HANDLE,IFIT_8) //77
#define ICO_FORFEIT9 MAKELONG(IFIT_HANDLE,IFIT_9) //78
#define ICO_FORFEIT15 MAKELONG(IFIT_HANDLE,IFIT_15)
#define ICO_FORFEITX MAKELONG(IFIT_HANDLE,IFIT_X) //79
#define ICO_R0       MAKELONG(IRAR_HANDLE,IRAR_R) //80
#define ICO_U0       MAKELONG(IRAR_HANDLE,IRAR_U) //81
#define ICO_C0       MAKELONG(IRAR_HANDLE,IRAR_C) //82
#define ICO_DAGOBAH  MAKELONG(ISET_HANDLE,ISET_DAGOBAH) //83
#define ICO_BESPIN   MAKELONG(ISET_HANDLE,ISET_BESPIN) //84
#define ICO_JABBA    MAKELONG(ISET_HANDLE,ISET_JABBA) //85
#define ICO_JEDITEST MAKELONG(ITYP_HANDLE,ITYP_JEDITEST) //86
#define ICO_JEDIMAST MAKELONG(ITYP_HANDLE,ITYP_JEDIMAST) //87
#define ICO_STARTING MAKELONG(ITYP_HANDLE,ITYP_STARTING) //88
#define ICO_INDEPENDENT MAKELONG(IICO_HANDLE,IICO_INDEPENDANT) //89
#define ICO_SECTOR   MAKELONG(ITYP_HANDLE,ITYP_SECTOR) //90
#define ICO_MOBEFFECT MAKELONG(IICO_HANDLE,IICO_MOBEFFECT) //91
#define ICO_SPY      MAKELONG(IICO_HANDLE,IICO_SPY) //92
#define ICO_LEADER   MAKELONG(IICO_HANDLE,IICO_LEADER) //93
#define ICO_BOUNTY   MAKELONG(IICO_HANDLE,IICO_BOUNTY) //94
#define ICO_DEPLOY15 MAKELONG(IDEP_HANDLE,IDEP_15) //95
#define ICO_FORFEIT15 MAKELONG(IFIT_HANDLE,IFIT_15) //96
#define ICO_ENCLOSED MAKELONG(IICO_HANDLE,IICO_ENCLOSED) //97
#define ICO_LSBACK MAKELONG(IBAK_HANDLE,IBAK_LS) //98
#define ICO_DSBACK MAKELONG(IBAK_HANDLE,IBAK_DS) //99

#define ICO_OBJECTIVE MAKELONG(ITYP_HANDLE,ITYP_OBJECTIVE) //100
#define ICO_FIXED MAKELONG(IRAR_HANDLE,IRAR_F) //101
#define ICO_PERMWEAPON MAKELONG(IICO_HANDLE,IICO_PERMWEAPON) //102
#define ICO_ANHUL MAKELONG(ISET_HANDLE,ISET_ANHUL) //103
#define ICO_HOTHUL MAKELONG(ISET_HANDLE,ISET_HOTHUL) //104
#define ICO_SE MAKELONG(ISET_HANDLE,ISET_SE) // 105
#define ICO_ANTHOLOGY MAKELONG(ISET_HANDLE,ISET_ANTHOLOGY) //106
#define ICO_EPP MAKELONG(ISET_HANDLE,ISET_EPP) //107
#define ICO_JEDIPACK MAKELONG(ISET_HANDLE,ISET_JEDIPACK) //108
#define ICO_OTSD MAKELONG(ISET_HANDLE,ISET_OTSD) //109
#define ICO_ENDOR MAKELONG(ISET_HANDLE,ISET_ENDOR) //110
#define ICO_ENDORUL MAKELONG(ISET_HANDLE,ISET_ENDORUL) //111
#define ICO_DEATHSTAR MAKELONG(ISET_HANDLE,ISET_DEATHSTAR) //112
#define ICO_DEATHSTARUL MAKELONG(ISET_HANDLE,ISET_DEATHSTARUL) //113

/*
// these are indexes into the "icon" array aPics[].
#define ICO_NONE	0
#define ICO_BLANK	1
#define ICO_DEST0	2
#define ICO_DEST1   3
#define ICO_DEST2	4
#define ICO_DEST3	5
#define ICO_DEST4	6
#define ICO_DEST5	7
#define ICO_DEST6	8
#define ICO_DEST7   9
#define ICO_SYSTEM	10
#define ICO_INTSITE	11
#define ICO_EXTSITE	12
#define ICO_MOBILE	13
#define ICO_DEJARIK	14
#define ICO_REBEL	15
#define ICO_IMP		16
#define ICO_DROID	17
#define ICO_ALIEN	18
#define ICO_CRITTER	19
#define ICO_VEHICLE	20
#define ICO_SHIP	21
#define ICO_INT		22
#define ICO_UORL	23
#define ICO_EFFECT	24
#define ICO_UTINNI	25
#define ICO_IMMED	26
#define ICO_RFORCE0	27
#define ICO_RFORCE1	28
#define ICO_RFORCE2	29
#define ICO_RFORCE3	30
#define ICO_IFORCE0	31
#define ICO_IFORCE1	32
#define ICO_IFORCE2	33
#define ICO_IFORCE3	34
#define ICO_WEAPON	35
#define ICO_DEVICE	36
#define ICO_PILOT	37
#define ICO_ASTRO	38
#define ICO_WARRIOR	39
#define ICO_R1		40
#define ICO_R2		41
#define ICO_U1		42
#define ICO_U2		43
#define ICO_C1		44
#define ICO_C2		45
#define ICO_C3		46
#define ICO_NA		47
#define ICO_SCOMP	48
#define ICO_LTD		49
#define ICO_ULTD	50
#define ICO_2P		51
#define ICO_ANH		52
#define ICO_RL		53
#define ICO_EVENT	54
#define ICO_LOST	55
#define ICO_HOTH	56
#define ICO_DESTPI	57
#define ICO_DESTX   58
#define ICO_DEPLOY0 59
#define ICO_DEPLOY1 60
#define ICO_DEPLOY2 61
#define ICO_DEPLOY3 62
#define ICO_DEPLOY4 63
#define ICO_DEPLOY5 64
#define ICO_DEPLOY6 65
#define ICO_DEPLOY7 66
#define ICO_DEPLOY8 67
#define ICO_DEPLOY9 68
#define ICO_DEPLOYX 69
#define ICO_FORFEIT0 70
#define ICO_FORFEIT1 71
#define ICO_FORFEIT2 72
#define ICO_FORFEIT3 73
#define ICO_FORFEIT4 74
#define ICO_FORFEIT5 75
#define ICO_FORFEIT6 76
#define ICO_FORFEIT7 77
#define ICO_FORFEIT8 78
#define ICO_FORFEIT9 79
#define ICO_FORFEITX 80
#define ICO_R0       81
#define ICO_U0       82
#define ICO_C0       83
#define ICO_DAGOBAH  84
#define ICO_BESPIN   85
#define ICO_JABBA    86
#define ICO_JEDITEST 87
#define ICO_JEDIMAST 88
#define ICO_STARTING 89
#define ICO_INDEPENDENT 90
#define ICO_SECTOR   91
#define ICO_MOBEFFECT 92
#define ICO_SPY      93
#define ICO_LEADER   94
#define ICO_BOUNTY   95
#define ICO_DEPLOY15 96
#define ICO_FORFEIT15 97
#define ICO_ENCLOSED 98
#define ICO_LSBACK 99
#define ICO_DSBACK 100

#define ICO_OBJECTIVE 101
#define ICO_FIXED 102
#define ICO_PERMWEAPON 103
#define ICO_ANHUL 104
#define ICO_HOTHUL 105
#define ICO_SE 106
#define ICO_ANTHOLOGY 107
#define ICO_EPP 108
#define ICO_JEDIPACK 109
#define ICO_OTSD 110
#define ICO_ENDOR 111
#define ICO_ENDORUL 112
#define ICO_DEATHSTAR 113
#define ICO_DEATHSTARUL 114

#define ICO_MAX 115


*/
#define CTYPE		0
#define CDEST		1
#define CDEST2		2
#define CRARITY		3
#define CSET		4
#define CEXTRA1		5
#define CEXTRA2		6
#define CEXTRA3		7

#define CMAX		8

#define RGB_BLUE		RGB(0,0,175)		// for ships and vehicles
#define RGB_RED			RGB(175,0,0)		// for effect and interrupts
#define RGB_GREEN		RGB(0,120,0)		// for weapons and devices
#define RGB_BLACK		RGB(0,0,0)			// for all characters
#define RGB_GREY		RGB(120,64,64) 		// for systems and sites
#define RGB_WHITE		RGB(255,255,255)
#define RGB_PURPLE		RGB(128,0,128)		// for epic events
#define RGB_DKGREY		RGB(96,96,96)		// for creatures
#define RGB_DKGREEN		RGB(16,80,16)		// for jedi tests

#define ILDrawBitmap(hdc,idx,x,y) \
	ImageList_Draw(hImageLists[LOWORD(idx)],HIWORD(idx),hdc,x,y,0)
